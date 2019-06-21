/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCore/AuxContainerBase.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "TH1F.h"

#include "ttHMultilepton/ttHMLAsgHelper.h"

template<typename T, typename U> T returnDecoIfAvailable(const U& obj, const std::string& deconame, T defaultval) {
  //return defaultval;
  T result = (obj.template isAvailable<T>(deconame) ? obj.template auxdataConst<T>(deconame) : defaultval);
  return result;
}
template<typename T> int CountPassOR(const DataVector<T>& vec, bool doTauOR = false) {
  int rv = 0;
  // Figure this out later ...
  //T::template Decorator<short> passovr("ttHpassOVR");
  //for (size_t idx = 0; idx < vec.size(); ++idx) {
  //if (passovr(vec, idx)) {
  for (const auto iItr : vec) {
    if (iItr->template auxdataConst<char>("ttHpassOVR") && (!doTauOR || iItr->template auxdataConst<char>("ttHpassTauOVR") ) ) {
      rv++;
    //std::cout<<"open it when we have OR"<<std::endl;
    }
  }
  return rv;
}

void CopyIParticle(const xAOD::IParticle& part, ttHML::Lepton& lep) {
  lep.Pt = part.pt();
  lep.E = part.e();
  lep.Eta = part.eta();
  lep.Phi = part.phi();
  lep.Index = part.index();
}

void CopyIso(const xAOD::IParticle& part, ttHML::Lepton& lep) {
  lep.isolationLooseTrackOnly = part.auxdataConst<short>("Iso_LooseTrackOnly");
  lep.isolationLoose = part.auxdataConst<short>("Iso_Loose");
  lep.isolationGradient = part.auxdataConst<short>("Iso_Gradient");
  lep.isolationGradientLoose = part.auxdataConst<short>("Iso_GradientLoose");
  lep.isolationFixedCutTightTrackOnly = part.auxdataConst<short>("Iso_FixedCutTightTrackOnly");
  lep.isolationFixedCutLoose = part.auxdataConst<short>("Iso_FixedCutLoose");

}

void CopyIParam(const xAOD::IParticle& part, ttHML::Lepton& lep) {
  lep.sigd0PV = part.auxdataConst<float>("d0sig");
  lep.Z0SinTheta = part.auxdataConst<float>("delta_z0_sintheta");
  lep.deltaz0 = part.auxdataConst<float>("delta_z0");
}

int ttHMultileptonLooseEventSaver::getNInnerPix(const xAOD::Electron& el) {
  uint8_t val8;
  int expInPix = el.trackParticleSummaryValue(val8, xAOD::expectInnermostPixelLayerHit)
    ? val8 : -999;
  int expNextInPix = el.trackParticleSummaryValue(val8, xAOD::expectNextToInnermostPixelLayerHit)
    ? val8 : -999;
  if (1 == expInPix) {
    return (el.trackParticleSummaryValue(val8, xAOD::numberOfInnermostPixelLayerHits)
	    ? val8 : -999);
  }
  else if (1 == expNextInPix) {
    return (el.trackParticleSummaryValue(val8, xAOD::numberOfNextToInnermostPixelLayerHits)
	    ? val8 : -999);
  }
  return -999;
}
int ttHMultileptonLooseEventSaver::getNInnerPix(const xAOD::Muon& mu) {
  uint8_t val8;
  const auto& link = mu.inDetTrackParticleLink();
  if (!link.isValid()) return -999;
  int expInPix = (*link)->summaryValue(val8, xAOD::expectInnermostPixelLayerHit) ? val8 : -999;
  int expNextInPix = (*link)->summaryValue(val8, xAOD::expectNextToInnermostPixelLayerHit) ? val8 : -999;
  if (1 == expInPix) {
    return ((*link)->summaryValue(val8, xAOD::numberOfInnermostPixelLayerHits) ? val8 : -999);
  }
  else if (1 == expNextInPix) {
    return ((*link)->summaryValue(val8, xAOD::numberOfNextToInnermostPixelLayerHits) ? val8 : -999);
  }
  return -999;

}

void ttHMultileptonLooseEventSaver::CopyLeptons(const xAOD::ElectronContainer& Electrons, const xAOD::MuonContainer& Muons){

  //const xAOD::ElectronContainer* Electrons = m_asgHelper->RetrieveElectrons(m_elec);
  //const xAOD::MuonContainer* Muons = m_asgHelper->RetrieveMuons(m_muon);
  memset(&m_leptons, 0, sizeof(m_leptons));
  const int totleptons = Electrons.size() + Muons.size();
  m_ttHEvent->total_leptons = totleptons;
  int keyval = 1 + Electrons.size();
  switch(totleptons) {
  case 1:
    m_ttHEvent->onelep_type = keyval;
    break;
  case 2:
    m_ttHEvent->dilep_type = keyval;
    break;
  case 3:
    m_ttHEvent->trilep_type = keyval;
    break;
  case 4:
    m_ttHEvent->quadlep_type = keyval;
    break;
  }

  for (const auto elItr : Electrons) { m_ttHEvent->total_charge += elItr->charge(); }
  for (const auto muItr : Muons) { m_ttHEvent->total_charge += muItr->charge(); }

  // Do a sorting for objects
  // (pt, idx, leptype)
  // 3l |q| = 1 has special sorting by Delta R from OS lepton
  typedef std::tuple<const TLorentzVector*, int, ttHML::LepType> sorttype_t;
  std::vector<sorttype_t> sorter;
  // Get p4 for OS in trilep case
  TLorentzVector p4OS;
  bool is_trilep_q1 = m_ttHEvent->trilep_type && abs(m_ttHEvent->total_charge) == 1;
  if (is_trilep_q1) {
    for (const auto elItr : Electrons) {
      if (elItr->charge() == -m_ttHEvent->total_charge) {
	p4OS = elItr->p4(); break;
      }
    }
    for (const auto muItr : Muons) {
      if (muItr->charge() == -m_ttHEvent->total_charge) {
	p4OS = muItr->p4(); break;
      }
    }
  }

  size_t idx = 0;
  for (const auto elItr : Electrons) {
    sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHML::ELECTRON));
  }
  idx = 0;
  for (const auto muItr : Muons) {
    sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHML::MUON));
  }
  if (is_trilep_q1) {
    // sort by increasing delta R from OS lepton (= OS first)
    std::sort(sorter.begin(), sorter.end(),
	      [p4OS](sorttype_t a, sorttype_t b) { return std::get<0>(a)->DeltaR(p4OS) < std::get<0>(b)->DeltaR(p4OS); });
  } else {
    // sort by decreasing pt
    std::sort(sorter.begin(), sorter.end(),
	      [](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
  }
std::vector<const TLorentzVector*> p4s;
  short capped_totleptons = std::min(totleptons, LEPTON_ARR_SIZE);
  for (short idx = 0; idx < capped_totleptons; ++idx) {
    const TLorentzVector* p4;
    int lidx;
    ttHML::LepType typ;
    std::tie(p4, lidx, typ) = sorter[idx];
    p4s.push_back(p4);
    if (typ == ttHML::ELECTRON) {
      CopyElectron(*((Electrons)[lidx]), m_leptons[idx]);
    } else {
      CopyMuon(*((Muons)[lidx]), m_leptons[idx]);
    }
  }
if (totleptons >= 2) {
    TLorentzVector p4_01 = (*p4s[0]+*p4s[1]);
    //m_ttHEvent->Mll01 = p4_01.M();
    //m_ttHEvent->Ptll01 = p4_01.Pt();
    //m_ttHEvent->DRll01 = p4s[0]->DeltaR(*p4s[1]);
    int zidx[2]{-1,-1};
    for (int idx1 = 0; idx1 < capped_totleptons-1; ++idx1) {
      for (int idx2 = idx1+1; idx2 < capped_totleptons; ++idx2) {
	TLorentzVector p4sum = *p4s[idx1] + *p4s[idx2];
	m_ttHEvent->Mll[idx1][idx2-1] = p4sum.M();
	m_ttHEvent->Ptll[idx1][idx2-1] = p4sum.Pt();
	m_ttHEvent->DRll[idx1][idx2-1] = p4s[idx1]->DeltaR(*p4s[idx2]);
        m_ttHEvent->matchDLTll[idx1][idx2-1] = ( (int)m_leptons[idx1].isTrigMatchDLT && (int)m_leptons[idx2].isTrigMatchDLT
          && std::max(m_leptons[idx1].Pt, m_leptons[idx2].Pt)
          > (abs(m_leptons[idx1].ID*m_leptons[idx2].ID)==169)*((m_runYear==2015)*19e3+(m_runYear==2016||m_runYear==2017)*23e3) );
	// min Mll variables
	if (m_leptons[idx1].ID * m_leptons[idx2].ID < 0) {
	  if (m_ttHEvent->minOSMll == 0 || 
	      m_ttHEvent->Mll[idx1][idx2-1] < m_ttHEvent->minOSMll) {
	    m_ttHEvent->minOSMll = m_ttHEvent->Mll[idx1][idx2-1];
	  }
	}
	if (m_leptons[idx1].ID == -m_leptons[idx2].ID) {
	  if (m_ttHEvent->best_Z_Mll == 0 ||
	      (fabs(m_ttHEvent->Mll[idx1][idx2-1]-91.1876e3) <
	       fabs(m_ttHEvent->best_Z_Mll-91.1876e3))) {
	    m_ttHEvent->best_Z_Mll=m_ttHEvent->Mll[idx1][idx2-1];
	    zidx[0] = idx1; zidx[1] = idx2;
	  }
	  // min Mll variables
	  if (m_ttHEvent->minOSSFMll == 0 || 
	      m_ttHEvent->Mll[idx1][idx2-1] < m_ttHEvent->minOSSFMll) {
	    m_ttHEvent->minOSSFMll = m_ttHEvent->Mll[idx1][idx2-1];
	  }
	}
	for (int idx3 = idx2+1; idx3 < capped_totleptons; ++idx3) {
	  TLorentzVector p4sum3 = p4sum + *p4s[idx3];
	  m_ttHEvent->Mlll[idx1][idx2-1][idx3-2] = p4sum3.M();
	  for (int idx4 = idx3+1; idx4 < capped_totleptons; ++idx4) {
	    TLorentzVector p4sum4 = p4sum3 + *p4s[idx4];
	    m_ttHEvent->Mllll[idx1][idx2-1][idx3-2][idx4-3] = p4sum4.M();
	  }
	}
      }
    }
    if (totleptons==3 && zidx[0] >= 0) {
      int oidx = 3 - zidx[0] - zidx[1];
      TLorentzVector p4met;
      p4met.SetPtEtaPhiM(m_met_met,0,m_met_phi,0);
      m_ttHEvent->best_Z_other_MtLepMet = (p4met + *p4s[oidx]).Mt();
    }
    if (totleptons==4 && zidx[0] >= 0) {
      std::vector<int> otherleps;
      for (int idx = 0; idx < 4; ++idx) {
	if (idx != zidx[0] && idx != zidx[1]) {
	  otherleps.push_back(idx);
	}
      }
      m_ttHEvent->best_Z_other_Mll = m_ttHEvent->Mll[otherleps[0]][otherleps[1]-1];
    }
  }

  // Flag event if there's at least one truth-QMisID/truth-fake/truth-From-Non-GEANT-Photon lepton
  //
  // By construction, "isLepFromPhEvent==1" is a subset of "isFakeEvent==1"
  //
  if ( m_isMC && totleptons >= 1 ) {

    m_ttHEvent->isQMisIDEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
      if ( m_leptons[idx].isQMisID == 1 ) {
    	m_ttHEvent->isQMisIDEvent = 1;
    	break;
      }
    }
    m_ttHEvent->isFakeEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
      if ( m_leptons[idx].isFakeLep == 1 ) {
    	m_ttHEvent->isFakeEvent = 1;
    	break;
      }
    }
    m_ttHEvent->isLepFromPhEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
	if ( m_leptons[idx].isConvPh == 1 || m_leptons[idx].isISR_FSR_Ph == 1 ) {
    	m_ttHEvent->isLepFromPhEvent = 1;
    	break;
      }
    }
  } else {
    m_ttHEvent->isQMisIDEvent    = -1; // default for data
    m_ttHEvent->isFakeEvent      = -1; // default for data
    m_ttHEvent->isLepFromPhEvent = -1; // default for data
  }

}

float muonEff_Trigger(const xAOD::Muon& x,const std::string& id,const top::topSFSyst SFSyst)
{
  float sf(1.);
  if (x.isAvailable<float>("MU_EFF_Trigger_"+id)) {
    sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id);
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_STAT_UP) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_STAT_UP")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_STAT_UP");
    }
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_STAT_DOWN) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_STAT_DOWN")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_STAT_DOWN");
    }
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_SYST_UP) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_SYST_UP")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_SYST_UP");
    }
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_SYST_DOWN) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_SYST_DOWN")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_SYST_DOWN");
    }
  }
  return sf;
}

float electronEff_Trigger(const xAOD::Electron& x,const std::string& id,const top::topSFSyst SFSyst)
{
  float sf(1.);
  if (x.isAvailable<float>("EL_EFF_Trigger_"+id)) {
    sf = x.auxdataConst<float>("EL_EFF_Trigger_"+id);
  }

  if (SFSyst == top::topSFSyst::EL_SF_Trigger_UP) {
    if (x.isAvailable<float>("EL_EFF_Trigger_"+id+"_UP")) {
      sf = x.auxdataConst<float>("EL_EFF_Trigger_"+id+"_UP");
    }
  }

  if (SFSyst == top::topSFSyst::EL_SF_Trigger_DOWN) {
    if (x.isAvailable<float>("EL_EFF_Trigger_"+id+"_DOWN")) {
      sf = x.auxdataConst<float>("EL_EFF_Trigger_"+id+"_DOWN");
    }
  }

  return sf;
}

void ttHMultileptonLooseEventSaver::
CopyElectron(const xAOD::Electron& el, ttHML::Lepton& lep) {
  lep.EtaBE2 = el.caloCluster()->etaBE(2);
  CopyIParticle(el, lep);
  CopyIso(el, lep);
  CopyIParam(el, lep);
  lep.ID = -11*el.charge();
  lep.isLooseLH  = el.auxdataConst<int>("passLHLoose");
  // passLHLoose is equivalent to LooseLH + BLayer cuts
  // the BLayer cuts are applied by AnalysisTop
  lep.isMediumLH = el.auxdataConst<int>("passLHMedium");
  lep.isTightLH  = el.auxdataConst<int>("passLHTight");
  lep.isolationFixedCutTight = el.auxdataConst<short>("Iso_FixedCutTight");

  lep.d0 = el.trackParticle()->d0();
  lep.z0 = el.trackParticle()->z0();
  lep.vz = el.trackParticle()->vz();

  // NTracks associated to the reco electron
  lep.nTrackParticles      = el.nTrackParticles();

  // Mtrktrk at Primary Vertex
  lep.Mtrktrk_atPV_CO      = el.auxdataConst<float>("mll_conv");

  // Mtrktrk at Conversion Vertex
  lep.Mtrktrk_atConvV_CO   = el.auxdataConst<float>("mll_conv_atConvV");

  // Conversion radius from tracks
  lep.RadiusCO             = el.auxdataConst<float>("radius_conv");
  lep.RadiusCOX            = el.auxdataConst<float>("radius_convX");
  lep.RadiusCOY            = el.auxdataConst<float>("radius_convY");

  // Distance between the two track curves
  lep.SeparationMinDCT     = el.auxdataConst<float>("separationMinDCT");

  // Pt, Eta, Phi, D0, Z0 from best matched non-GSF track to electron
  lep.BestMatchTrackPt     = el.auxdataConst<float>("bestmatchSiTrackPt");
  lep.BestMatchTrackEta    = el.auxdataConst<float>("bestmatchSiTrackEta");
  lep.BestMatchTrackPhi    = el.auxdataConst<float>("bestmatchSiTrackPhi");
  lep.BestMatchTrackD0     = el.auxdataConst<float>("bestmatchSiTrackD0");
  lep.BestMatchTrackZ0     = el.auxdataConst<float>("bestmatchSiTrackZ0");
  lep.BestMatchTrackQ      = el.auxdataConst<float>("bestmatchSiTrackQ");
  

  // Pt, Eta, Phi, D0, Z0 from closest non-GSF track to electron
  lep.ClosestSiTrackPt     = el.auxdataConst<float>("closestSiTrackPt");
  lep.ClosestSiTrackEta    = el.auxdataConst<float>("closestSiTrackEta");
  lep.ClosestSiTrackPhi    = el.auxdataConst<float>("closestSiTrackPhi");
  lep.ClosestSiTrackD0     = el.auxdataConst<float>("closestSiTrackD0");
  lep.ClosestSiTrackZ0     = el.auxdataConst<float>("closestSiTrackZ0");
  lep.ClosestSiTrackQ      = el.auxdataConst<float>("closestSiTrackQ");
  

  // nIL (observed Innermost layer hits), eIL (expected Innermost layer hits), nNIL (observed next to Innermost layer hits), eNIL (expected next to Innermost layer hits)
  lep.ClosestSiTracknIL    = el.auxdataConst<float>("closestSiTracknIL");
  lep.ClosestSiTrackeIL    = el.auxdataConst<float>("closestSiTrackeIL");
  lep.ClosestSiTracknNIL    = el.auxdataConst<float>("closestSiTracknNIL");
  lep.ClosestSiTrackeNIL    = el.auxdataConst<float>("closestSiTrackeNIL");


  // truth matching, fakes, QMisId
  int TruthType = -99;
  int TruthOrigin = -99;


  if(m_isMC) {
    static SG::AuxElement::Accessor<int> origel("truthOrigin");
    if (origel.isAvailable(el)) TruthOrigin = origel(el);

    static SG::AuxElement::Accessor<int> typeel("truthType");
    if (typeel.isAvailable(el)) TruthType = typeel(el);

    //truthType   = (int) xAOD::TruthHelpers::getParticleTruthType(el);
    //truthOrigin = (int) xAOD::TruthHelpers::getParticleTruthOrigin(el);
  }

  if (TruthType == 2 || TruthType == 6)
    lep.isPrompt = 1;
  else
    lep.isPrompt = 0;
  static SG::AuxElement::Accessor<unsigned char> AmbiguityType("ambiguityType");
  lep.ambiguityType = ( AmbiguityType.isAvailable(el) ) ?  AmbiguityType(el) : -99;

  static SG::AuxElement::Accessor<char> QMisID("isQMisID");
  lep.isQMisID = ( QMisID.isAvailable(el) ) ?  QMisID(el) : -1;

  static SG::AuxElement::Accessor<char> ConvPh("isConvPh");
  lep.isConvPh = ( ConvPh.isAvailable(el) ) ?  ConvPh(el) : -1;

  static SG::AuxElement::Accessor<char> ISR_FSR_Ph("isISR_FSR_Ph");
  lep.isISR_FSR_Ph = ( ISR_FSR_Ph.isAvailable(el) ) ?  ISR_FSR_Ph(el) : -1;

  static SG::AuxElement::Accessor<char> isBrems("isBrems");
  lep.isBrems = ( isBrems.isAvailable(el) ) ? isBrems(el) : -1;
  //std::cout << "Its Brems Elec and bkgMotherPdgId is " << bkgElMotherPdgID << " and type: " << bkgElType << " and origin: " << bkgElOrigin << std::endl;

  // Whatever is not a prompt or a QMisID, is a fake to us!
  lep.isFakeLep = ( !( lep.isPrompt == 1 ) && !( lep.isQMisID == 1 ) );

/*  static SG::AuxElement::Accessor<short> promptLeptonIso_sv1_jf_ntrkv("PromptLeptonIso_sv1_jf_ntrkv");
  lep.promptLeptonIso_sv1_jf_ntrkv = ( promptLeptonIso_sv1_jf_ntrkv.isAvailable(el) ) ? promptLeptonIso_sv1_jf_ntrkv(el) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_TrackJetNTrack("PromptLeptonIso_TrackJetNTrack");
  lep.promptLeptonIso_TrackJetNTrack = ( promptLeptonIso_TrackJetNTrack.isAvailable(el) ) ? promptLeptonIso_TrackJetNTrack(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip2("PromptLeptonIso_ip2");
  lep.promptLeptonIso_ip2 = ( promptLeptonIso_ip2.isAvailable(el) ) ? promptLeptonIso_ip2(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip3("PromptLeptonIso_ip3");
  lep.promptLeptonIso_ip3 = ( promptLeptonIso_ip3.isAvailable(el) ) ? promptLeptonIso_ip3(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_DRlj("PromptLeptonIso_DRlj");
  lep.promptLeptonIso_DRlj = ( promptLeptonIso_DRlj.isAvailable(el) ) ? promptLeptonIso_DRlj(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_LepJetPtFrac("PromptLeptonIso_LepJetPtFrac");
  lep.promptLeptonIso_LepJetPtFrac = ( promptLeptonIso_LepJetPtFrac.isAvailable(el) ) ? promptLeptonIso_LepJetPtFrac(el) : -99;

  static SG::AuxElement::Accessor<float> promptLepton_TagWeight("PromptLepton_TagWeight");
  lep.promptLepton_TagWeight = ( promptLepton_TagWeight.isAvailable(el) ) ? promptLepton_TagWeight(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonNoIso_TagWeight("PromptLeptonNoIso_TagWeight");
  lep.promptLeptonNoIso_TagWeight = ( promptLeptonNoIso_TagWeight.isAvailable(el) ) ? promptLeptonNoIso_TagWeight(el) : -99;
*/

  static SG::AuxElement::Accessor<short> promptLeptonInput_sv1_jf_ntrkv("PromptLeptonInput_sv1_jf_ntrkv");
  lep.promptLeptonInput_sv1_jf_ntrkv = ( promptLeptonInput_sv1_jf_ntrkv.isAvailable(el) ) ? promptLeptonInput_sv1_jf_ntrkv(el) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonInput_TrackJetNTrack("PromptLeptonInput_TrackJetNTrack");
  lep.promptLeptonInput_TrackJetNTrack = ( promptLeptonInput_TrackJetNTrack.isAvailable(el) ) ? promptLeptonInput_TrackJetNTrack(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_DL1mu("PromptLeptonInput_DL1mu");
  lep.promptLeptonInput_DL1mu = ( promptLeptonInput_DL1mu.isAvailable(el) ) ? promptLeptonInput_DL1mu(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_DRlj("PromptLeptonInput_DRlj");
  lep.promptLeptonInput_DRlj = ( promptLeptonInput_DRlj.isAvailable(el) ) ? promptLeptonInput_DRlj(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_LepJetPtFrac("PromptLeptonInput_LepJetPtFrac");
  lep.promptLeptonInput_LepJetPtFrac = ( promptLeptonInput_LepJetPtFrac.isAvailable(el) ) ? promptLeptonInput_LepJetPtFrac(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_PtFrac("PromptLeptonInput_PtFrac");
  lep.promptLeptonInput_PtFrac = ( promptLeptonInput_PtFrac.isAvailable(el) ) ? promptLeptonInput_PtFrac(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_PtRel("PromptLeptonInput_PtRel");
  lep.promptLeptonInput_PtRel = ( promptLeptonInput_PtRel.isAvailable(el) ) ? promptLeptonInput_PtRel(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_ip2("PromptLeptonInput_ip2");
  lep.promptLeptonInput_ip2 = ( promptLeptonInput_ip2.isAvailable(el) ) ? promptLeptonInput_ip2(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_ip3("PromptLeptonInput_ip3");
  lep.promptLeptonInput_ip3 = ( promptLeptonInput_ip3.isAvailable(el) ) ? promptLeptonInput_ip3(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_rnnip("PromptLeptonInput_rnnip");
  lep.promptLeptonInput_rnnip = ( promptLeptonInput_rnnip.isAvailable(el) ) ? promptLeptonInput_rnnip(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_TagWeight("PromptLeptonIso");
  lep.promptLeptonIso_TagWeight = ( promptLeptonIso_TagWeight.isAvailable(el) ) ? promptLeptonIso_TagWeight(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonVeto_TagWeight("PromptLeptonVeto");
  lep.promptLeptonVeto_TagWeight = ( promptLeptonVeto_TagWeight.isAvailable(el) ) ? promptLeptonVeto_TagWeight(el) : -99;



  static SG::AuxElement::Accessor<float> chargeIDBDTLoose("chargeIDBDTLoose");
  lep.chargeIDBDTLoose = ( chargeIDBDTLoose.isAvailable(el) ) ? chargeIDBDTLoose(el) : -99;

  static SG::AuxElement::Accessor<float> chargeIDBDTMedium("chargeIDBDTMedium");
  lep.chargeIDBDTMedium = ( chargeIDBDTMedium.isAvailable(el) ) ? chargeIDBDTMedium(el) : -99;

  static SG::AuxElement::Accessor<float> chargeIDBDTTight("chargeIDBDTTight");
  lep.chargeIDBDTTight = ( chargeIDBDTTight.isAvailable(el) ) ? chargeIDBDTTight(el) : -99;

  static SG::AuxElement::Accessor<char> isTruthMatched("isTruthMatched");
  lep.isTruthMatched = ( isTruthMatched.isAvailable(el) ) ? isTruthMatched(el) : -1;

  lep.truthOrigin = TruthOrigin;
  lep.truthType = TruthType;


  static SG::AuxElement::Accessor<int> truthPdgId("truthPdgId");
  lep.truthPdgId = ( truthPdgId.isAvailable(el) ) ? truthPdgId(el) : -1;

  static SG::AuxElement::Accessor<int> truthStatus("truthStatus");
  lep.truthStatus = ( truthStatus.isAvailable(el) ) ? truthStatus(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentType("ancestorTruthType");
  lep.truthParentType = ( truthParentType.isAvailable(el) ) ? truthParentType(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentOrigin("ancestorTruthOrigin");
  lep.truthParentOrigin = ( truthParentOrigin.isAvailable(el) ) ? truthParentOrigin(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentPdgId("ancestorTruthPdgId");
  lep.truthParentPdgId = ( truthParentPdgId.isAvailable(el) ) ? truthParentPdgId(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentStatus("ancestorTruthStatus");
  lep.truthParentStatus = ( truthParentStatus.isAvailable(el) ) ? truthParentStatus(el) : -1;

  static SG::AuxElement::Accessor<float> truthPt("truthPt");
  lep.truthPt = ( truthPt.isAvailable(el) ) ? truthPt(el) : -1;

  static SG::AuxElement::Accessor<float> truthEta("truthEta");
  lep.truthEta = ( truthEta.isAvailable(el) ) ? truthEta(el) : -1;

  static SG::AuxElement::Accessor<float> truthPhi("truthPhi");
  lep.truthPhi = ( truthPhi.isAvailable(el) ) ? truthPhi(el) : -1;

  static SG::AuxElement::Accessor<float> truthM("truthM");
  lep.truthM = ( truthM.isAvailable(el) ) ? truthM(el) : -1;

  static SG::AuxElement::Accessor<float> truthE("truthE");
  lep.truthE = ( truthE.isAvailable(el) ) ? truthE(el) : -1;

  static SG::AuxElement::Accessor<float> truthRapidity("truthRapidity");
  lep.truthRapidity = ( truthRapidity.isAvailable(el) ) ? truthRapidity(el) : -1;
  
  static SG::AuxElement::Accessor<int> firstEgMotherPdgId("firstEgMotherPdgId");
  lep.firstEgMotherPdgId = ( firstEgMotherPdgId.isAvailable(el) ) ? firstEgMotherPdgId(el) : -99;

  static SG::AuxElement::Accessor<int> firstEgMotherTruthType("firstEgMotherTruthType");
  lep.firstEgMotherTruthType = ( firstEgMotherTruthType.isAvailable(el) ) ? firstEgMotherTruthType(el) : -99;

  static SG::AuxElement::Accessor<int> firstEgMotherTruthOrigin("firstEgMotherTruthOrigin");
  lep.firstEgMotherTruthOrigin = ( firstEgMotherTruthOrigin.isAvailable(el) ) ? firstEgMotherTruthOrigin(el) : -99;

  // trigger matching, electron pt > 25 GeV
  if (m_runYear == 2015) {
    lep.isTrigMatch = ( el.pt() > 25e3 && (
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e24_lhmedium_L1EM20VH", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e120_lhloose", (char) 0)));
  }
  else if (m_runYear == 2016 || m_runYear == 2017 || m_runYear == 2018) {
    lep.isTrigMatch = ( el.pt() > 27e3 && (
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e26_lhtight_nod0_ivarloose", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium_nod0", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e140_lhloose_nod0", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  if (m_runYear == 2015) {
    lep.isTrigMatchDLT = ( (el.pt() > 13e3 && returnDecoIfAvailable(el, "TRIGMATCH_HLT_2e12_lhloose_L12EM10VH", (char) 0)) || 
			   (el.pt() > 18e3 && returnDecoIfAvailable(el, "TRIGMATCH_HLT_e17_lhloose_mu14"      , (char) 0)) );
  }
  else if (m_runYear == 2016) {
    lep.isTrigMatchDLT = ( el.pt() > 18e3 && (
                                              returnDecoIfAvailable(el, "TRIGMATCH_HLT_2e17_lhvloose_nod0"   , (char) 0) ||
                                              returnDecoIfAvailable(el, "TRIGMATCH_HLT_e17_lhloose_nod0_mu14", (char) 0)));
  }
  else if (m_runYear == 2017) {
    lep.isTrigMatchDLT = ( el.pt() > 18e3 && (
                                              returnDecoIfAvailable(el, "TRIGMATCH_HLT_2e24_lhvloose_nod0" , (char) 0) ||
											  returnDecoIfAvailable(el, "TRIGMATCH_HLT_e17_lhloose_nod0_mu14", (char) 0)));
  } else {
    lep.isTrigMatchDLT = 0;
  }


  // isolation variables
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone20); lep.ptVarcone20 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone30); lep.ptVarcone30 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone40); lep.ptVarcone40 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone20); lep.topoEtcone20 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone30); lep.topoEtcone30 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone40); lep.topoEtcone40 = iso;}

  lep.nInnerPix = getNInnerPix(el);

  // scale factors
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    if( !m_doSFSystematics && ivar != 0 ) continue; // break after doing nominal
    lep.SFIDLoose[ivar] = m_sfRetriever->electronSF_ID(el, ivar, false);
    lep.SFIDTight[ivar] = m_sfRetriever->electronSF_ID(el, ivar, true);
    lep.SFTrigLoose[ivar] = m_sfRetriever->electronSF_Trigger(el, ivar, false);
    lep.SFTrigTight[ivar] = m_sfRetriever->electronSF_Trigger(el, ivar, true);
    if (lep.SFTrigLoose[ivar] == 0) lep.SFTrigLoose[ivar] = 1;
    if (lep.SFTrigTight[ivar] == 0) lep.SFTrigTight[ivar] = 1;
    lep.SFIsoLoose[ivar] = m_sfRetriever->electronSF_Isol(el, ivar, false);
    lep.SFIsoTight[ivar] = m_sfRetriever->electronSF_Isol(el, ivar, true);
    lep.SFReco[ivar] = m_sfRetriever->electronSF_Reco(el, ivar);
    lep.SFTTVA[ivar] = 1;
    // I know the loose/tight swap looks weird, but it's intentional
    lep.EffTrigLoose[ivar] = electronEff_Trigger(el, m_config->electronID(), ivar);
    lep.EffTrigTight[ivar] = electronEff_Trigger(el, m_config->electronIDLoose(), ivar);
    // Everything except trigger
    lep.SFObjLoose[ivar] = lep.SFIDLoose[ivar]*lep.SFIsoLoose[ivar]*lep.SFReco[ivar];
    lep.SFObjTight[ivar] = lep.SFIDTight[ivar]*lep.SFIsoTight[ivar]*lep.SFReco[ivar];
  }
}
void
ttHMultileptonLooseEventSaver::CopyJets(const xAOD::JetContainer& goodJets) {
  // don't actually copy anything ATM, just give yields of jets & btags
  m_ttHEvent->nJets_OR = goodJets.size();
  m_ttHEvent->nJets_OR_T = CountPassOR(goodJets, true);
  m_ttHEvent->nTruthJets_OR = this->getNTruthJets(goodJets);


  m_ttHEvent->nJets_OR_MV2c10_85   = 0;
  m_ttHEvent->nJets_OR_MV2c10_70   = 0;
  m_ttHEvent->nJets_OR_MV2c10_77   = 0;
  m_ttHEvent->nJets_OR_MV2c10_60   = 0;
  m_ttHEvent->nJets_OR_T_MV2c10_85 = 0;
  m_ttHEvent->nJets_OR_T_MV2c10_70 = 0;
  m_ttHEvent->nJets_OR_T_MV2c10_77 = 0;
  m_ttHEvent->nJets_OR_T_MV2c10_60 = 0;

  m_ttHEvent->lead_jetPt = 0;
  m_ttHEvent->sublead_jetPt = 0;
  m_ttHEvent->lead_jetEta = 0;
  m_ttHEvent->sublead_jetEta = 0;
  m_ttHEvent->lead_jetPhi = 0;
  m_ttHEvent->sublead_jetPhi = 0;
  m_ttHEvent->lead_jetE = 0;
  m_ttHEvent->sublead_jetE =0;

  typedef std::tuple<const TLorentzVector*, int> sortvec_t;
  std::vector<sortvec_t> sorter_jets;
  size_t idx = 0;


  for (const auto jetItr : goodJets) {
    sorter_jets.push_back(std::make_tuple(&(jetItr->p4()), idx++));

    auto btagging = jetItr->btagging();
    if (btagging) {
      double mv2c;
      if( btagging->MVx_discriminant("MV2c10", mv2c) ) {
	if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_85")) {
	  m_ttHEvent->nJets_OR_MV2c10_85++;
	  if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_77")) {
	    m_ttHEvent->nJets_OR_MV2c10_77++;
	    if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_70")) {
	      m_ttHEvent->nJets_OR_MV2c10_70++;
	      if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_60")) {
		m_ttHEvent->nJets_OR_MV2c10_60++;
	      }
	    }
	  }
	}
      }
	if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_85")) {
	  m_ttHEvent->nJets_OR_DL1_85++;
	  if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_77")) {
	    m_ttHEvent->nJets_OR_DL1_77++;
	    if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_70")) {
	      m_ttHEvent->nJets_OR_DL1_70++;
	      if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_60")) {
		      m_ttHEvent->nJets_OR_DL1_60++;
	      }
	    }
	  }
	}
    }
  }

  //same thing for jet with tau OR
  for (const auto jetItr : goodJets) {
    if( jetItr->auxdataConst<char>("ttHpassTauOVR") ) {
    //std::cout<<"open it when we have OR_1"<<std::endl;
      auto btagging = jetItr->btagging();
      if (btagging) {
	double mv2c;
	if( btagging->MVx_discriminant("MV2c10", mv2c) ) {
	  if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_85")) {
	    m_ttHEvent->nJets_OR_T_MV2c10_85++;
	    if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_77")) {
	      m_ttHEvent->nJets_OR_T_MV2c10_77++;
	      if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_70")) {
		      m_ttHEvent->nJets_OR_T_MV2c10_70++;
		        if (jetItr->auxdataConst<char>("isbtagged_MV2c10_FixedCutBEff_60")) {
		          m_ttHEvent->nJets_OR_T_MV2c10_60++;
		}
	      }
	    }
	  }
	}
	if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_85")) {
	  m_ttHEvent->nJets_OR_T_DL1_85++;
	  if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_77")) {
	    m_ttHEvent->nJets_OR_T_DL1_77++;
	    if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_70")) {
	      m_ttHEvent->nJets_OR_T_DL1_70++;
	      if (jetItr->auxdataConst<char>("isbtagged_DL1_FixedCutBEff_60")) {
		      m_ttHEvent->nJets_OR_T_DL1_60++;
	      }
	    }
	  }
	}
      }
    }
  }

  std::sort(sorter_jets.begin(), sorter_jets.end(),
	      [](sortvec_t a, sortvec_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
                
  std::vector<const TLorentzVector*> p4s;
  const int totjets = goodJets.size();
  for (short idx1 = 0; idx1 < totjets; ++idx1) {
    const TLorentzVector* p4;
    int lidx;
    std::tie(p4, lidx) = sorter_jets[idx1];
    p4s.push_back(p4);
  }

  if (goodJets.size() > 0){
    m_ttHEvent->lead_jetPt  = p4s[0]->Pt();
    m_ttHEvent->lead_jetEta = p4s[0]->Eta();
    m_ttHEvent->lead_jetPhi = p4s[0]->Phi();
    m_ttHEvent->lead_jetE   = p4s[0]->E();
    }
  if (goodJets.size() > 1){
    m_ttHEvent->sublead_jetPt  = p4s[1]->Pt();
    m_ttHEvent->sublead_jetEta = p4s[1]->Eta();
    m_ttHEvent->sublead_jetPhi = p4s[1]->Phi();
    m_ttHEvent->sublead_jetE	= p4s[1]->E();
  }
  
  /*typedef std::tuple<double,  int> bWtSortvec_t;
  std::vector<bWtSortvec_t> bWtSorter;
  idx = 0;
  for (const auto jetItr : goodJets) {
    double mv2c(0);  
    jetItr->btagging()->MVx_discriminant("MV2c10", mv2c);
    bWtSorter.push_back(std::make_tuple(mv2c, idx++));
  }
  std::sort(bWtSorter.begin(), bWtSorter.end(),
	      [](bWtSortvec_t a, bWtSortvec_t b) { return std::get<0>(a)  > std::get<0>(b); });

   MakeJetIndices(*goodJets,event.m_jets);*/
}
void ttHMultileptonLooseEventSaver::CopyMuon(const xAOD::Muon& mu,     ttHML::Lepton& lep){
  CopyIParticle(mu, lep);
  CopyIso(mu, lep);
  CopyIParam(mu, lep);
  lep.ID = -13*mu.charge();
  lep.isLoose  = (char) ( muonSelection.getQuality(mu) <= xAOD::Muon::Loose  && muonSelection.passedIDCuts(mu) );
  lep.isMedium = (char) ( muonSelection.getQuality(mu) <= xAOD::Muon::Medium && muonSelection.passedIDCuts(mu) );
  lep.isTight  = (char) ( muonSelection.getQuality(mu) <= xAOD::Muon::Tight  && muonSelection.passedIDCuts(mu) );

  // lep.d0 = mu.trackParticle(xAOD::Muon::TrackParticleType::CombinedTrackParticle)->d0();
  // lep.z0 = mu.trackParticle(xAOD::Muon::TrackParticleType::CombinedTrackParticle)->z0();
  lep.d0 = mu.primaryTrackParticle()->d0();
  lep.z0 = mu.primaryTrackParticle()->z0();
  lep.vz = mu.primaryTrackParticle()->vz();


  static SG::AuxElement::Accessor<float> mujet_jetPt("jet_pt");
  lep.mujet_jetPt = (mujet_jetPt.isAvailable(mu)) ? mujet_jetPt(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_jetNTrk("jet_numTrk");
  lep.mujet_jetNTrk = (mujet_jetNTrk.isAvailable(mu)) ? mujet_jetNTrk(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_jetSumPtTrk("jet_sumPtTrk");
  lep.mujet_jetSumPtTrk = (mujet_jetSumPtTrk.isAvailable(mu)) ? mujet_jetSumPtTrk(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_mv2c10("MV2c10_weight");
  lep.mujet_mv2c10 = (mujet_mv2c10.isAvailable(mu)) ? mujet_mv2c10(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_deltaR("dRJet"); //changed for PromptLeptonIso calibration
  lep.mujet_deltaR = (mujet_deltaR.isAvailable(mu)) ? mujet_deltaR(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_ptRel("jet_ptRel");
  lep.mujet_ptRel = (mujet_ptRel.isAvailable(mu)) ? mujet_ptRel(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_jetPtOverpt("jet_pt");
  lep.mujet_jetPtOverpt = (mujet_jetPtOverpt.isAvailable(mu)) ? mujet_jetPtOverpt(mu)/mu.pt(): -99;

  static::SG::AuxElement::Accessor<float> mujet_BDT("muon_BDT");
  lep.mujet_BDT        = (mujet_BDT.isAvailable(mu)) ? mujet_BDT(mu): -99;



  // trigger matching
  if (m_runYear == 2015) {
    lep.isTrigMatch = (mu.pt() > 21e3 && (
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu20_iloose_L1MU15", (char) 0) ||
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else if (m_runYear == 2016 || m_runYear == 2017 || m_runYear == 2018) { // since period D4 on in 2016 data (high luminosity triggers)
    lep.isTrigMatch = (mu.pt() > 27e3 && (
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu26_ivarmedium", (char) 0) ||
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  if (m_runYear == 2015) {
    lep.isTrigMatchDLT = ( (mu.pt() > 9e3  && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu18_mu8noL1"    , (char) 0)) ||
			   (mu.pt() > 15e3 && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_e17_lhloose_mu14", (char) 0)) );
  }
  else if (m_runYear == 2016 || m_runYear == 2017) {
    lep.isTrigMatchDLT = ( (mu.pt() > 9e3  && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu22_mu8noL1"         , (char) 0)) ||
                           (mu.pt() > 15e3 && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_e17_lhloose_nod0_mu14", (char) 0)) );
  } else {
    lep.isTrigMatchDLT = 0;
  }

  /* //////// Different pT threshold for pre and post-ICHEP dataset
  else if (m_runYear == 2016 && m_runNumber < 302900) { // period A to D3 in 2016 data
    lep.isTrigMatch = (mu.pt() > 25e3 && (
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu24_ivarmedium", (char) 0) ||
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else if (m_runYear == 2016) { // since period D4 on in 2016 data (high luminosity triggers)
    lep.isTrigMatch = (mu.pt() > 27e3 && (
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu26_ivarmedium", (char) 0) ||
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  */

  // truth matching, fakes, QMisId
  int TruthType = -99;
  int TruthOrigin = -99;

  if(m_isMC) {
    static SG::AuxElement::Accessor<int> acc_mctt("truthType");
    const xAOD::TrackParticle* mutrack = mu.primaryTrackParticle();
    if (mutrack!=nullptr) {
      if (acc_mctt.isAvailable(*mutrack)) TruthType = acc_mctt(*mutrack);
    }

    static SG::AuxElement::Accessor<int> acc_mcto("truthOrigin");
    if (mutrack!=nullptr) {
      if (acc_mcto.isAvailable(*mutrack)) TruthOrigin = acc_mcto(*mutrack);
    }
  }

  // const xAOD::TruthParticle* matched_truth_muon=0;
  // if(mu.isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
  //   ElementLink<xAOD::TruthParticleContainer> link = mu.auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
  //   if(link.isValid()){
  //     matched_truth_muon = *link;
  //     truthOrigin = matched_truth_muon->auxdata<int>("truthOrigin");
  //   }
  // }

  // const xAOD::TrackParticle* idtp=0;
  // ElementLink<xAOD::TrackParticleContainer> idtpLink = mu.inDetTrackParticleLink();
  // if(idtpLink.isValid()){
  //   idtp = *idtpLink;
  //   if(m_isMC) truthType = idtp->auxdata<int>("truthType");
  // }

  if (TruthType == 2 || TruthType == 6)
    lep.isPrompt = 1;
  else
    lep.isPrompt = 0;

  static SG::AuxElement::Accessor<char> QMisID("isQMisID");
  lep.isQMisID = ( QMisID.isAvailable(mu) ) ?  QMisID(mu) : -1;

  static SG::AuxElement::Accessor<char> ConvPh("isConvPh");
  lep.isConvPh = ( ConvPh.isAvailable(mu) ) ?  ConvPh(mu) : -1;

  static SG::AuxElement::Accessor<char> ISR_FSR_Ph("isISR_FSR_Ph");
  lep.isISR_FSR_Ph = ( ISR_FSR_Ph.isAvailable(mu) ) ?  ISR_FSR_Ph(mu) : -1;

  static SG::AuxElement::Accessor<char> isBrems("isBrems");
  lep.isBrems = ( isBrems.isAvailable(mu) ) ? isBrems(mu) : -1;
  //std::cout << "Its Brems Elec and bkgMotherPdgId is " << bkgElMotherPdgID << " and type: " << bkgElType << " and origin: " << bkgElOrigin << std::endl;

//  static SG::AuxElement::Accessor<float> promptLeptonIso_TagWeight("PromptLeptonIso_TagWeight");
//  lep.promptLeptonIso_TagWeight = ( promptLeptonIso_TagWeight.isAvailable(mu) ) ? promptLeptonIso_TagWeight(mu) : -99;

/*  static SG::AuxElement::Accessor<short> promptLeptonIso_sv1_jf_ntrkv("PromptLeptonIso_sv1_jf_ntrkv");
  lep.promptLeptonIso_sv1_jf_ntrkv = ( promptLeptonIso_sv1_jf_ntrkv.isAvailable(mu) ) ? promptLeptonIso_sv1_jf_ntrkv(mu) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_TrackJetNTrack("PromptLeptonIso_TrackJetNTrack");
  lep.promptLeptonIso_TrackJetNTrack = ( promptLeptonIso_TrackJetNTrack.isAvailable(mu) ) ? promptLeptonIso_TrackJetNTrack(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip2("PromptLeptonIso_ip2");
  lep.promptLeptonIso_ip2 = ( promptLeptonIso_ip2.isAvailable(mu) ) ? promptLeptonIso_ip2(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip3("PromptLeptonIso_ip3");
  lep.promptLeptonIso_ip3 = ( promptLeptonIso_ip3.isAvailable(mu) ) ? promptLeptonIso_ip3(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_DRlj("PromptLeptonIso_DRlj");
  lep.promptLeptonIso_DRlj = ( promptLeptonIso_DRlj.isAvailable(mu) ) ? promptLeptonIso_DRlj(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_LepJetPtFrac("PromptLeptonIso_LepJetPtFrac");
  lep.promptLeptonIso_LepJetPtFrac = ( promptLeptonIso_LepJetPtFrac.isAvailable(mu) ) ? promptLeptonIso_LepJetPtFrac(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLepton_TagWeight("PromptLepton_TagWeight");
  lep.promptLepton_TagWeight = ( promptLepton_TagWeight.isAvailable(mu) ) ? promptLepton_TagWeight(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonNoIso_TagWeight("PromptLeptonNoIso_TagWeight");
  lep.promptLeptonNoIso_TagWeight = ( promptLeptonNoIso_TagWeight.isAvailable(mu) ) ? promptLeptonNoIso_TagWeight(mu) : -99;
*/
 
  static SG::AuxElement::Accessor<short> promptLeptonInput_sv1_jf_ntrkv("PromptLeptonInput_sv1_jf_ntrkv");
  lep.promptLeptonInput_sv1_jf_ntrkv = ( promptLeptonInput_sv1_jf_ntrkv.isAvailable(mu) ) ? promptLeptonInput_sv1_jf_ntrkv(mu) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonInput_TrackJetNTrack("PromptLeptonInput_TrackJetNTrack");
  lep.promptLeptonInput_TrackJetNTrack = ( promptLeptonInput_TrackJetNTrack.isAvailable(mu) ) ? promptLeptonInput_TrackJetNTrack(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_DL1mu("PromptLeptonInput_DL1mu");
  lep.promptLeptonInput_DL1mu = ( promptLeptonInput_DL1mu.isAvailable(mu) ) ? promptLeptonInput_DL1mu(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_DRlj("PromptLeptonInput_DRlj");
  lep.promptLeptonInput_DRlj = ( promptLeptonInput_DRlj.isAvailable(mu) ) ? promptLeptonInput_DRlj(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_LepJetPtFrac("PromptLeptonInput_LepJetPtFrac");
  lep.promptLeptonInput_LepJetPtFrac = ( promptLeptonInput_LepJetPtFrac.isAvailable(mu) ) ? promptLeptonInput_LepJetPtFrac(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_PtFrac("PromptLeptonInput_PtFrac");
  lep.promptLeptonInput_PtFrac = ( promptLeptonInput_PtFrac.isAvailable(mu) ) ? promptLeptonInput_PtFrac(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_PtRel("PromptLeptonInput_PtRel");
  lep.promptLeptonInput_PtRel = ( promptLeptonInput_PtRel.isAvailable(mu) ) ? promptLeptonInput_PtRel(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_ip2("PromptLeptonInput_ip2");
  lep.promptLeptonInput_ip2 = ( promptLeptonInput_ip2.isAvailable(mu) ) ? promptLeptonInput_ip2(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_ip3("PromptLeptonInput_ip3");
  lep.promptLeptonInput_ip3 = ( promptLeptonInput_ip3.isAvailable(mu) ) ? promptLeptonInput_ip3(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonInput_rnnip("PromptLeptonInput_rnnip");
  lep.promptLeptonInput_rnnip = ( promptLeptonInput_rnnip.isAvailable(mu) ) ? promptLeptonInput_rnnip(mu) : -99;

   static SG::AuxElement::Accessor<float> promptLeptonIso_TagWeight("PromptLeptonIso");
  lep.promptLeptonIso_TagWeight = ( promptLeptonIso_TagWeight.isAvailable(mu) ) ? promptLeptonIso_TagWeight(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonVeto_TagWeight("PromptLeptonVeto");
  lep.promptLeptonVeto_TagWeight = ( promptLeptonVeto_TagWeight.isAvailable(mu) ) ? promptLeptonVeto_TagWeight(mu) : -99;





  // Whatever is not a prompt or a QMisID, is a fake to us!
  lep.isFakeLep = ( !( lep.isPrompt == 1 ) && !( lep.isQMisID == 1 ) );

  static SG::AuxElement::Accessor<char> isTruthMatched("isTruthMatched");
  lep.isTruthMatched = ( isTruthMatched.isAvailable(mu) ) ? isTruthMatched(mu) : -1;

  lep.truthOrigin = TruthOrigin;
  lep.truthType = TruthType;

  static SG::AuxElement::Accessor<int> truthPdgId("truthPdgId");
  lep.truthPdgId = ( truthPdgId.isAvailable(mu) ) ? truthPdgId(mu) : -1;

  static SG::AuxElement::Accessor<int> truthStatus("truthStatus");
  lep.truthStatus = ( truthStatus.isAvailable(mu) ) ? truthStatus(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentType("ancestorTruthType");
  lep.truthParentType = ( truthParentType.isAvailable(mu) ) ? truthParentType(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentOrigin("ancestorTruthOrigin");
  lep.truthParentOrigin = ( truthParentOrigin.isAvailable(mu) ) ? truthParentOrigin(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentPdgId("ancestorTruthPdgId");
  lep.truthParentPdgId = ( truthParentPdgId.isAvailable(mu) ) ? truthParentPdgId(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentStatus("ancestorTruthStatus");
  lep.truthParentStatus = ( truthParentStatus.isAvailable(mu) ) ? truthParentStatus(mu) : -1;

  static SG::AuxElement::Accessor<float> truthPt("truthPt");
  lep.truthPt = ( truthPt.isAvailable(mu) ) ? truthPt(mu) : -1;

  static SG::AuxElement::Accessor<float> truthEta("truthEta");
  lep.truthEta = ( truthEta.isAvailable(mu) ) ? truthEta(mu) : -1;

  static SG::AuxElement::Accessor<float> truthPhi("truthPhi");
  lep.truthPhi = ( truthPhi.isAvailable(mu) ) ? truthPhi(mu) : -1;

  static SG::AuxElement::Accessor<float> truthM("truthM");
  lep.truthM = ( truthM.isAvailable(mu) ) ? truthM(mu) : -1;

  static SG::AuxElement::Accessor<float> truthE("truthE");
  lep.truthE = ( truthE.isAvailable(mu) ) ? truthE(mu) : -1;

  static SG::AuxElement::Accessor<float> truthRapidity("truthRapidity");
  lep.truthRapidity = ( truthRapidity.isAvailable(mu) ) ? truthRapidity(mu) : -1;

  // isolation variables
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone20); lep.ptVarcone20 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone30); lep.ptVarcone30 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone40); lep.ptVarcone40 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone20); lep.topoEtcone20 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone30); lep.topoEtcone30 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone40); lep.topoEtcone40 = iso;}

  lep.nInnerPix = getNInnerPix(mu);

  // scale factors
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    if( !m_doSFSystematics && ivar != 0 ) continue;
    // I know the loose/tight swap looks weird, but it's intentional
    lep.SFIDLoose[ivar] = m_sfRetriever->muonSF_ID(mu, ivar, false);
    lep.SFIDTight[ivar] = m_sfRetriever->muonSF_ID(mu, ivar, true);
    lep.SFTrigLoose[ivar] = m_sfRetriever->muonSF_Trigger(mu, ivar, false);
    lep.SFTrigTight[ivar] = m_sfRetriever->muonSF_Trigger(mu, ivar, true);
    lep.SFIsoLoose[ivar] = m_sfRetriever->muonSF_Isol(mu, ivar, false);
    lep.SFIsoTight[ivar] = m_sfRetriever->muonSF_Isol(mu, ivar, true);
    lep.SFTTVA[ivar] = m_isMC ? m_sfRetriever->muonSF_TTVA(mu, ivar) : 1.0;
    lep.SFReco[ivar] = 1;
    lep.EffTrigLoose[ivar] = muonEff_Trigger(mu, m_config->muonQuality(), ivar);
    lep.EffTrigTight[ivar] = muonEff_Trigger(mu, m_config->muonQualityLoose(), ivar);
  // Everything except trigger
    lep.SFObjLoose[ivar] = lep.SFIDLoose[ivar]*lep.SFIsoLoose[ivar]*lep.SFTTVA[ivar];
    lep.SFObjTight[ivar] = lep.SFIDTight[ivar]*lep.SFIsoTight[ivar]*lep.SFTTVA[ivar];
  }


}
void
ttHMultileptonLooseEventSaver::CopyTau(const xAOD::TauJet& xTau, ttHML::Tau& MLTau) {
  MLTau.pt              = xTau.pt();
  MLTau.eta             = xTau.eta();
  MLTau.phi             = xTau.phi();
  MLTau.charge          = xTau.charge();
  MLTau.e               = xTau.e();
  MLTau.BDTJetScore     = xTau.discriminant(xAOD::TauJetParameters::TauID::BDTJetScore);
  MLTau.JetBDTSigLoose  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigLoose);
  MLTau.JetBDTSigMedium = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium);
  MLTau.JetBDTSigTight  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigTight);
  MLTau.RNNJetScore     = xTau.discriminant(xAOD::TauJetParameters::TauID::RNNJetScore);
  MLTau.JetRNNSigVeryLoose  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigVeryLoose);
  MLTau.JetRNNSigLoose  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigLoose);
  MLTau.JetRNNSigMedium = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigMedium);
  MLTau.JetRNNSigTight  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigTight);
  MLTau.numTrack        = xTau.nTracks();
  MLTau.isHadronic      = xTau.auxdata<int>("IsHadronic");
  MLTau.tagWeightBin    = xTau.auxdata<int>("tagWeightBin");
  MLTau.fromPV          = xTau.auxdata<char>("fromPV");
  MLTau.passEleOLR      = xTau.auxdata<int>("passEleOLR");
  MLTau.passEleBDT      = xTau.auxdata<int>("passEleBDT");
  MLTau.passMuonOLR     = xTau.auxdata<int>("passMuonOLR");
  MLTau.truthOrigin     = xTau.auxdata<int>("tauTruthOrigin");
  MLTau.truthType       = xTau.auxdata<int>("tauTruthType");
  MLTau.truthJetFlavour = xTau.auxdata<int>("truthJetFlavour");
  

  static SG::AuxElement::Accessor<float> BDTEleScoreSigTrans("BDTEleScoreSigTrans");
  MLTau.BDTEleScoreSigTrans = ( BDTEleScoreSigTrans.isAvailable(xTau) ) ? BDTEleScoreSigTrans(xTau) : -2;

  static SG::AuxElement::Accessor<float> BDTJetScoreSigTrans("BDTJetScoreSigTrans");
  MLTau.BDTJetScoreSigTrans = ( BDTJetScoreSigTrans.isAvailable(xTau) ) ? BDTJetScoreSigTrans(xTau) : -2;

  static SG::AuxElement::Accessor<float> RNNJetScoreSigTrans("RNNJetScoreSigTrans");
  MLTau.RNNJetScoreSigTrans = ( RNNJetScoreSigTrans.isAvailable(xTau) ) ? RNNJetScoreSigTrans(xTau) : -2;

  static SG::AuxElement::Accessor<float> tau_mv2c10("MV2c10");
  MLTau.MV2c10 = ( tau_mv2c10.isAvailable(xTau) ) ? tau_mv2c10(xTau) : -2;

  static SG::AuxElement::Accessor<short> promptTauInput_TrackJetNTrack("PromptTauInput_TrackJetNTrack");
  MLTau.promptTauInput_TrackJetNTrack = ( promptTauInput_TrackJetNTrack.isAvailable(xTau) ) ? promptTauInput_TrackJetNTrack(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_DRlj("PromptTauInput_DRlj");
  MLTau.promptTauInput_DRlj = ( promptTauInput_DRlj.isAvailable(xTau) ) ? promptTauInput_DRlj(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_LepJetPtFrac("PromptTauInput_LepJetPtFrac");
  MLTau.promptTauInput_LepJetPtFrac = ( promptTauInput_LepJetPtFrac.isAvailable(xTau) ) ? promptTauInput_LepJetPtFrac(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_JetF("PromptTauInput_JetF");
  MLTau.promptTauInput_JetF = ( promptTauInput_JetF.isAvailable(xTau) ) ? promptTauInput_JetF(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_SV1("PromptTauInput_SV1");
  MLTau.promptTauInput_SV1 = ( promptTauInput_SV1.isAvailable(xTau) ) ? promptTauInput_SV1(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_MV2c10rnn("PromptTauInput_MV2c10rnn");
  MLTau.promptTauInput_MV2c10rnn = ( promptTauInput_MV2c10rnn.isAvailable(xTau) ) ? promptTauInput_MV2c10rnn(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_ip2("PromptTauInput_ip2");
  MLTau.promptTauInput_ip2 = ( promptTauInput_ip2.isAvailable(xTau) ) ? promptTauInput_ip2(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_ip3("PromptTauInput_ip3");
  MLTau.promptTauInput_ip3 = ( promptTauInput_ip3.isAvailable(xTau) ) ? promptTauInput_ip3(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_rnnip("PromptTauInput_rnnip");
  MLTau.promptTauInput_rnnip = ( promptTauInput_rnnip.isAvailable(xTau) ) ? promptTauInput_rnnip(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauInput_MV2c10("PromptTauInput_MV2c10");
  MLTau.promptTauInput_MV2c10 = ( promptTauInput_MV2c10.isAvailable(xTau) ) ? promptTauInput_MV2c10(xTau) : -99;


  static SG::AuxElement::Accessor<float> promptTauVeto("PromptTauVeto");
  MLTau.promptTauVeto = (promptTauVeto.isAvailable(xTau)) ? promptTauVeto(xTau) : -99;

  static SG::AuxElement::Accessor<float> promptTauIso("PromptTauIso");
  MLTau.promptTauIso = (promptTauIso.isAvailable(xTau)) ? promptTauIso(xTau) : -99;


  for( auto syst : m_tau_sf_names ) {
    auto ivar = syst.first;
    if( !m_doSFSystematics && ivar != 0 ) continue;
    // AnalysisTop tight/loose and our tight/loose are reversed
    MLTau.SFTight[ivar] = m_isMC ? m_sfRetriever->tauSF(xTau, ivar,  true) : 1.0;
    MLTau.SFLoose[ivar] = m_isMC ? m_sfRetriever->tauSF(xTau, ivar, false)               : 1.0;
  }
}

void
ttHMultileptonLooseEventSaver::CopyTaus(const xAOD::TauJetContainer& Taus) {
  memset(&m_taus, 0, sizeof(m_taus));
  int totalTaus = Taus.size();
  m_ttHEvent->nTaus_OR_Pt25 = totalTaus;

//  goodTaus.sort(top::descendingPtSorter);

  for(int i = 0; i < totalTaus && i < TAU_ARR_SIZE; ++i) {
    CopyTau( *(Taus.at(i)) , m_taus[i] );
  }
  for ( const auto tauItr : Taus) {
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigLoose)) 
      m_ttHEvent->nTaus_OR_Loose++;
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium)) 
      m_ttHEvent->nTaus_OR_Medium++;
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigTight)) 
      m_ttHEvent->nTaus_OR_Tight++;
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigVeryLoose)) 
      m_ttHEvent->nTaus_OR_RNN_VeryLoose++;
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigLoose)) 
      m_ttHEvent->nTaus_OR_RNN_Loose++;
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigMedium)) 
      m_ttHEvent->nTaus_OR_RNN_Medium++;
    if(tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigTight)) 
      m_ttHEvent->nTaus_OR_RNN_Tight++;
  }

}
void
ttHMultileptonLooseEventSaver::CopyHT(const xAOD::ElectronContainer& goodEl, const xAOD::MuonContainer& goodMu, const xAOD::JetContainer& goodJets, const xAOD::TauJetContainer& goodTaus) {
  m_ttHEvent->HT = 0;
  m_ttHEvent->HT_lep = 0;
  m_ttHEvent->HT_jets = 0;
  m_ttHEvent->Meff = 0;

  for (const auto jetItr : goodJets) {
    if( jetItr->auxdataConst<char>("ttHpassTauOVR") ) {
      m_ttHEvent->HT += jetItr->pt();
      m_ttHEvent->HT_jets += jetItr->pt();
    }
  }
  for (const auto elItr : goodEl) {
    m_ttHEvent->HT += elItr->pt();
    m_ttHEvent->HT_lep += elItr->pt();
  }
  for (const auto muItr : goodMu) {
    m_ttHEvent->HT += muItr->pt();
    m_ttHEvent->HT_lep += muItr->pt();
  }
  for (const auto tauItr : goodTaus) {
    m_ttHEvent->HT += tauItr->pt();
  }
  
  m_ttHEvent->Meff += m_ttHEvent->HT;
  m_ttHEvent->Meff += m_met_met;

}

void
ttHMultileptonLooseEventSaver::CopyHT_trig(const xAOD::JetContainer& goodJets) {
  m_ttHEvent->HT_alljets = 0;
  for (const auto jetItr : goodJets) {
    m_ttHEvent->HT_alljets += jetItr->pt();
  }
}


void
ttHMultileptonLooseEventSaver::CopyMass(const xAOD::ElectronContainer& goodEl, const xAOD::MuonContainer& goodMu, const xAOD::TauJetContainer& goodTaus) {
  m_ttHEvent->Mlt00 = 0;
  m_ttHEvent->Mlt01 = 0;
  m_ttHEvent->Mlt10 = 0;
  m_ttHEvent->Mlt11 = 0;
  m_ttHEvent->Mtt01 = 0;
  m_ttHEvent->MTlmet = 0;
  const int totleptons = goodEl.size() + goodMu.size();

  std::vector<const TLorentzVector*> tau_p4s;
  std::vector<const TLorentzVector*> lep_p4s;

  typedef std::tuple<const TLorentzVector*, int, ttHML::LepType> sorttype_t;
  std::vector<sorttype_t> sorter;
  size_t idx = 0;
  for (const auto elItr : goodEl) {
    sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHML::ELECTRON));
  }
  idx = 0;
  for (const auto muItr : goodMu) {
    sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHML::MUON));
  }
  std::sort(sorter.begin(), sorter.end(),
	    [](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
  for (short idx1 = 0; idx1<totleptons; ++idx1) {
    const TLorentzVector* p4;
    int lidx;
    ttHML::LepType typ;
    std::tie(p4, lidx, typ) = sorter[idx1];
    lep_p4s.push_back(p4);
  }
  if( totleptons>0 ){
    //    lmet = (p4met+*lep_p4s[0]);
    m_ttHEvent->MTlmet = (sqrt(2*m_met_met*lep_p4s[0]->Pt()*(1-cos(acos(cos(m_met_phi-lep_p4s[0]->Phi()))))));
  }

  idx=0;
  typedef std::tuple<const TLorentzVector*, int> sortvec_t;
  std::vector<sortvec_t> sorter_taus;
  for (const auto tauItr : goodTaus) {
    sorter_taus.push_back(std::make_tuple(&(tauItr->p4()), idx++));
  }
  std::sort(sorter_taus.begin(), sorter_taus.end(),
	    [](sortvec_t a, sortvec_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
  
  for (short idx1 = 0; idx1<goodTaus.size(); ++idx1)  {
    const TLorentzVector* p4;
    int lidx;
    std::tie(p4,lidx) = sorter_taus[idx1];
    tau_p4s.push_back(p4);
  }
  if( goodTaus.size() > 1 ) {
    TLorentzVector ditau;
    ditau = (*tau_p4s[0]+*tau_p4s[1]);
    m_ttHEvent->Mtt01 = ditau.M();
  }
  
  if(goodTaus.size()>0 && totleptons>0){
    TLorentzVector lephad00,lephad01,lephad10,lephad11;
    lephad00 = (*tau_p4s[0]+*lep_p4s[0]);
    m_ttHEvent->Mlt00 = lephad00.M();
    if(goodTaus.size()>1) {
      lephad01 = (*tau_p4s[1]+*lep_p4s[0]);
      m_ttHEvent->Mlt01 = lephad01.M();
    }
    if(totleptons>1) {
      lephad10 = (*tau_p4s[0]+*lep_p4s[1]);
      m_ttHEvent->Mlt10 = lephad10.M();
    }
    if(goodTaus.size()>1 && totleptons>1){
      lephad11 = (*tau_p4s[1]+*lep_p4s[1]);
      m_ttHEvent->Mlt11 = lephad11.M();
    }	
  }
}

void
ttHMultileptonLooseEventSaver::CheckIsBlinded() {
  bool isBlinded = false;
  if (m_ttHEvent->dilep_type) {
    if (abs(m_ttHEvent->total_charge) == 2
	&& m_ttHEvent->nJets_OR_T >= 4
	&& m_ttHEvent->nJets_OR_T_MV2c10_77 >= 1) {
      isBlinded = true;
    }
  } else if (m_ttHEvent->trilep_type) {
    // remember Mll01 = Mll[0][0] and Mll02 = Mll[0][1]
    if (abs(m_ttHEvent->total_charge) == 1
	&& ((m_ttHEvent->nJets_OR_T >=4
	     && m_ttHEvent->nJets_OR_T_MV2c10_77 >= 1)
	    || (m_ttHEvent->nJets_OR_T ==3
		&& m_ttHEvent->nJets_OR_T_MV2c10_77 >= 2))
	&& ! ((m_leptons[0].ID == - m_leptons[1].ID && fabs(m_ttHEvent->Mll[0][0] - 91.2e3) < 10e3)
	      || (m_leptons[0].ID == - m_leptons[2].ID && fabs(m_ttHEvent->Mll[0][1] - 91.2e3) < 10e3))
	) {
      isBlinded = true;
    }
  } else if (m_ttHEvent->quadlep_type) {
    if (m_ttHEvent->nJets_OR_T_MV2c10_77 >= 1
	&& m_ttHEvent->nJets_OR_T >= 2
	&& fabs(m_ttHEvent->best_Z_Mll - 91.2e3) > 10e3) {
      isBlinded = true;
    }
  }
  m_ttHEvent->isBlinded = isBlinded;
}


int ttHMultileptonLooseEventSaver::getNTruthJets(const xAOD::JetContainer jetColl)
{
  int nTruth = 0;
  for(auto jet: jetColl) 
  {
    if (jet->isAvailable<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink") && jet->auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink").isValid())
    {
      const xAOD::Jet* trthjet = *(jet->auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink"));
      if(trthjet->pt() >10000) nTruth++;
    }
  }
  return nTruth;
}

void
 ttHMultileptonLooseEventSaver::MakeJetIndices(const xAOD::JetContainer& goodJets,
					      const xAOD::JetContainer& allJets) {
  typedef std::tuple<double,  int> bWtSortvec_t;
  std::vector<bWtSortvec_t> OR_bWtSorter;
  std::vector<bWtSortvec_t> OR_T_bWtSorter;

  m_ttHEvent->selected_jetsOR.clear();
  m_ttHEvent->selected_jets_TOR.clear();

  m_ttHEvent->selected_jetsOR_mv2c10_Ordrd.clear();
  m_ttHEvent->selected_jets_TOR_mv2c10_Ordrd.clear();

  for (const auto jetItr : goodJets) 
  {
     double mv2c(0);  
     jetItr->btagging()->MVx_discriminant("MV2c10", mv2c);

     if (!jetItr->template auxdataConst<char>("ttHpassOVR")) continue;

     auto& goodp4 = jetItr->p4();
     bool found = false;
     for (size_t idx = 0; idx < allJets.size(); ++idx) {
        if (goodp4 == allJets[idx]->p4()) {
  	   found = true;
  	   OR_bWtSorter.push_back(std::make_tuple(mv2c, idx));
  	   m_ttHEvent->selected_jetsOR.push_back(idx);
  	   if (jetItr->template auxdataConst<char>("ttHpassTauOVR")) 
  	   {
  	     m_ttHEvent->selected_jets_TOR.push_back(idx);
  	     OR_T_bWtSorter.push_back(std::make_tuple(mv2c,idx));
  	   }
  	   break;
  	}
     }
     if (!found) {
       std::cerr << "Unable to find a jet match. Sad!" << std::endl;
     }
  }
  
  std::sort(OR_bWtSorter.begin(), OR_bWtSorter.end(), [](bWtSortvec_t a, bWtSortvec_t b) { return std::get<0>(a)  > std::get<0>(b); });
  std::sort(OR_T_bWtSorter.begin(), OR_T_bWtSorter.end(), [](bWtSortvec_t a, bWtSortvec_t b) { return std::get<0>(a)  > std::get<0>(b); });
  
  for(auto itr: OR_bWtSorter) { m_ttHEvent->selected_jetsOR_mv2c10_Ordrd.push_back( std::get<1>(itr));}
  for(auto itr: OR_T_bWtSorter) { m_ttHEvent->selected_jets_TOR_mv2c10_Ordrd.push_back( std::get<1>(itr));}
}

void
ttHMultileptonLooseEventSaver::doEventTrigSFs(const xAOD::ElectronContainer& Electrons, const xAOD::MuonContainer& Muons, const top::Event& event) {
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    m_ttHEvent->lepSFTrigLoose[ivar] = 1;
    m_ttHEvent->lepSFTrigTight[ivar] = 1;
  }
  double oneMinusTrigEffLoose[MAXSYST][2], oneMinusTrigEffTight[MAXSYST][2];
  for (int idx1 = 0; idx1 < MAXSYST; ++idx1) {
    for (int idx2 = 0; idx2 < 2; ++idx2) {
      oneMinusTrigEffLoose[idx1][idx2] = oneMinusTrigEffTight[idx1][idx2] = 1.;
    }
  }

  SG::AuxElement::Decorator<char> dec_tight("Signal"); // to tag electrons passing tight PID and PLI
  //SG::AuxElement::Decorator<char> dec_tightCFT("SignalCFT"); // to tag electrons passing tight PID and PLI+CFT
  SG::AuxElement::Decorator<char> dec_loose("Baseline"); // to tag electrons passing loose PID
 
  //std::cout << "doEventTrigSFs::Starting event loop" << std::endl;
  //int errors = 0;
  
  //const int totleptons = goodEl->size() + goodMu->size();
    
 // unsigned runNumber = 305291; // 2016 period G
  //event.m_info->auxdecor<unsigned int>("RandomRunNumber") = runNumber;
  unsigned runNumber=event.m_info->auxdecor<unsigned int>("RandomRunNumber");
  //std::cout<<"runnumber= " <<runNumber<<std::endl;
  std::vector<const xAOD::Electron*> myTriggeringElectrons;
  std::vector<const xAOD::Muon*> myTriggeringMuons;
  std::vector<const xAOD::IParticle*> myTriggeringLeptons;
  
  for(auto electron : Electrons)
    {
      //float pt = 0.001f*electron->pt(), eta = (electron->caloCluster()? fabs(electron->caloCluster()->etaBE(2)) : 10.f);
      //if(pt<10.f || eta>2.47) continue;
      //int type = electron->auxdata<int>("truthType"), origin = electron->auxdata<int>("truthOrigin");
      //if(type!=2 || !(origin==10 || (origin>=12 && origin<=22) || origin==43)) continue;
      myTriggeringElectrons.push_back(electron);
      myTriggeringLeptons.push_back(electron);
      //if(pt>18.f) ++nAbove18GeV;
    }
  
  float leadMuonPt = -1000.;
  for(auto muon : Muons)
    {
      float pt = 0.001f*muon->pt();
      //if(pt<10.f || eta>=2.5 || (muon->muonType()!=xAOD::Muon::Combined && muon->muonType()!=xAOD::Muon::myTriggeringMuonstandAlone)) continue;
      //int type = muon->primaryTrackParticle()->auxdata<int>("truthType"), origin = muon->primaryTrackParticle()->auxdata<int>("truthOrigin");
      //if(type!=6 || !(origin==10 || (origin>=12 && origin<=22) || origin==43)) continue;
      leadMuonPt = std::max(pt,leadMuonPt);
      myTriggeringMuons.push_back(muon);
      myTriggeringLeptons.push_back(muon);
    }

  //Calculate per-Event Trigger lepton SFs
  switch (m_ttHEvent->total_leptons) {
  case 2:
    {
      //if(nAbove18GeV<2) return;
      int nTrig = -1;
      for (const auto& systvar : m_lep_trigger_sf_names) {
	++nTrig;
	
	if (abs(m_ttHEvent->total_charge) == 0 && m_ttHEvent->nTaus_OR_Pt25>0){
	  for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0;  dec_loose(*e) = 1;}//TightTight SF 2LOS
	}
	else {
	  for(auto e : myTriggeringElectrons) {dec_tight(*e) = 1;  dec_loose(*e) = 0;}//TightTight SF 2LSS
	}
  
  	double sf_tt = 1.;
	//auto cc_tt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_tt);
	auto cc_tt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_tt);
	if(cc_tt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigTight[nTrig] = sf_tt;
	  }
	double dummy,eff_tt = 1.; //TightTight EFF
       	//auto cc_Ett = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy, eff_tt);
	auto cc_Ett = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy, eff_tt);
	if(cc_Ett==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigTight[nTrig] = eff_tt;
	    m_ttHEvent->lepDataEffTrigTight[nTrig] = dummy;
	  }
      
	for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0;  dec_loose(*e) = 1;} //LooseLoose SF
	double sf_ll = 1.;
	//auto cc_ll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_ll);
	auto cc_ll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_ll);
	if(cc_ll==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigLoose[nTrig] = sf_ll;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_2,eff_ll = 1.; //LooseLoose EFF
	//auto cc_Ell = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_2, eff_ll);
	auto cc_Ell = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy_2, eff_ll);
	if(cc_Ell==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigLoose[nTrig] = eff_ll;
	    m_ttHEvent->lepDataEffTrigLoose[nTrig] = dummy_2;
	  }
	
	float leadElectronPt = -1000.;
	int nCount=-1;
	for(auto e : myTriggeringElectrons) {
	  ++nCount;
	  float pt = 0.001f*e->pt();
	  leadElectronPt = std::max(pt,leadElectronPt);
	  //dec_tight(*e) = 0;
	  if (myTriggeringMuons.size()==0){
	    if (nCount==0) { dec_tight(*e) = 1; dec_loose(*e) = 0; }
	    else if (nCount==1) { dec_tight(*e) = 0; dec_loose(*e) = 1; }
	  }
	  else {
	    if (leadElectronPt > leadMuonPt) { dec_tight(*e) = 1; dec_loose(*e) = 0; }
	    else { dec_tight(*e) = 0; dec_loose(*e) = 1; }
	  }
	} //TightLoose SF
	double sf_tl = 1.;
	//auto cc_tl = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_tl);
	auto cc_tl = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_tl);
	if(cc_tl==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigTightLoose[nTrig] = sf_tl;
	   // std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_3,eff_tl = 1.; //TightLoose EFF
	auto cc_Etl = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy_3, eff_tl);
      	//auto cc_Etl = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_3, eff_tl);
	if(cc_Etl==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigTightLoose[nTrig] = eff_tl;
	    m_ttHEvent->lepDataEffTrigTightLoose[nTrig] = dummy_3;
	  }
	
	leadElectronPt = -1000.;
	nCount=-1;
	for(auto e : myTriggeringElectrons) {
	  ++nCount;
	  float pt = 0.001f*e->pt();
	  //std::cout << nCount << " electron pT " << pt << std::endl;
	  leadElectronPt = std::max(pt,leadElectronPt);
	  //dec_tight(*e) = 0;
	  if (myTriggeringMuons.size()==0){
	    if (nCount==0) { dec_tight(*e) = 0; dec_loose(*e) = 1; }
	    else if (nCount==1) { dec_tight(*e) = 1; dec_loose(*e) = 0; }
	  }
	  else {
	    if (leadElectronPt > leadMuonPt) { dec_tight(*e) = 0; dec_loose(*e) = 1; }
	    else { dec_tight(*e) = 1; dec_loose(*e) = 0; }
	  }
	} //LooseTight SF
	double sf_lt = 1.;
	auto cc_lt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_lt);
        //auto cc_lt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_lt);
	if(cc_lt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigLooseTight[nTrig] = sf_lt;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_4,eff_lt = 1.; //TightLoose EFF
	auto cc_Elt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy_4, eff_lt);
        //auto cc_Elt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_4, eff_lt);
	if(cc_Elt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigLooseTight[nTrig] = eff_lt;
	    m_ttHEvent->lepDataEffTrigLooseTight[nTrig] = dummy_4;
	    //std::cout << "2LSSLooseTight:TriggerEff is for sys " << systvar.second << " : " << eff_lt << std::endl;
	  }
	

      }
      
    }
    break;
  case 1:
    {
      for (int ilep = 0; ilep < m_ttHEvent->total_leptons; ++ilep) {
	for (const auto& systvar : m_lep_sf_names) {
	  auto ivar = systvar.first;
	  oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[ilep].EffTrigLoose[ivar]);
	  oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[ilep].EffTrigLoose[ivar]*m_leptons[ilep].SFTrigLoose[ivar]);
	  oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[ilep].EffTrigTight[ivar]);
	  oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[ilep].EffTrigTight[ivar]*m_leptons[ilep].SFTrigTight[ivar]);
	}
      }
      
      m_ttHEvent->lepSFTrigLoose[0] = oneMinusTrigEffLoose[0][0] != 1 ? (1-oneMinusTrigEffLoose[0][1])/(1-oneMinusTrigEffLoose[0][0]) : 1;
      m_ttHEvent->lepSFTrigTight[0] = oneMinusTrigEffTight[0][0] != 1 ? (1-oneMinusTrigEffTight[0][1])/(1-oneMinusTrigEffTight[0][0]) : 1;
      for (const auto& systvar : m_lep_sf_names) {
	auto ivar = systvar.first;
	//std::cout << "In systematic number " << ivar << " and systematic: " << systvar.second <<  std::endl;
	if (ivar == top::topSFSyst::nominal) continue;
	m_ttHEvent->lepSFTrigLoose[ivar] = oneMinusTrigEffLoose[ivar][0] != 1 ? (1-oneMinusTrigEffLoose[ivar][1])/(1-oneMinusTrigEffLoose[ivar][0])/m_ttHEvent->lepSFTrigLoose[0] : 1;
	m_ttHEvent->lepSFTrigTight[ivar] = oneMinusTrigEffTight[ivar][0] != 1 ? (1-oneMinusTrigEffTight[ivar][1])/(1-oneMinusTrigEffTight[ivar][0])/m_ttHEvent->lepSFTrigTight[0] : 1;
      }
    }
    break;
  case 3:
    {

      // Do a sorting for objects
      // (pt, idx, leptype)
      // 3l |q| = 1 has special sorting by Delta R from OS lepton
      typedef std::tuple<const TLorentzVector*, int, ttHML::LepType> sorttype_t;
      std::vector<sorttype_t> sorter;
      // Get p4 for OS in trilep case
      TLorentzVector p4OS;
      bool is_trilep_q1 = m_ttHEvent->trilep_type && abs(m_ttHEvent->total_charge) == 1;
      if (is_trilep_q1) {
	for (const auto elItr : myTriggeringElectrons) {
	  if (elItr->charge() == -m_ttHEvent->total_charge) {
	    p4OS = elItr->p4(); break;
	  }
	}
	for (const auto muItr : myTriggeringMuons) {
	  if (muItr->charge() == -m_ttHEvent->total_charge) {
	    p4OS = muItr->p4(); break;
	  }
	}
      }
      
      size_t idx = 0;
      for (const auto elItr : myTriggeringElectrons) {
	sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHML::ELECTRON));
      }
      idx = 0;
      for (const auto muItr : myTriggeringMuons) {
	sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHML::MUON));
      }
      if (is_trilep_q1) {
	// sort by increasing delta R from OS lepton (= OS first)
	std::sort(sorter.begin(), sorter.end(),
		  [p4OS](sorttype_t a, sorttype_t b) { return std::get<0>(a)->DeltaR(p4OS) < std::get<0>(b)->DeltaR(p4OS); });
      } else {
	// sort by decreasing pt
	std::sort(sorter.begin(), sorter.end(),
		  [](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
      }
      
      int nTrig = -1;
      for (const auto& systvar : m_lep_trigger_sf_names) {
	++nTrig;
	
	for(auto e : myTriggeringElectrons) {
	  //dec_tight(*e) = 0;
	  if (e->charge() == -m_ttHEvent->total_charge){ 
	    dec_loose(*e) = 1;
	    dec_tight(*e) = 0;
	  }
	  else {
	    dec_loose(*e) = 0;	  
	    dec_tight(*e) = 1;
	  }
	}//TightTight
	
	double sf_ltt = 1.;
	//auto cc_ltt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_ltt);
	auto cc_ltt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_ltt);
	if(cc_ltt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigTight[nTrig] = sf_ltt;
	    //std::cout << "3LTight:TriggerScaleFactor is: " << sf_ltt << std::endl;
	  }
	
	double dummy,eff_ltt = 1.; //TightTight EFF
	//auto cc_Eltt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy, eff_ltt);
	auto cc_Eltt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy, eff_ltt);
	if(cc_Eltt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigTight[nTrig] = eff_ltt;
	    m_ttHEvent->lepDataEffTrigTight[nTrig] = dummy;
	    //std::cout << "3LTightTight:TriggerEff is for sys " << systvar.second << " : " << eff_ltt << std::endl;
	  }
      
	for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_loose(*e) = 1;} //LooseLoose SF
	double sf_lll = 1.;
	//auto cc_lll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_lll);
	auto cc_lll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_lll);
	if(cc_lll==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigLoose[nTrig] = sf_lll;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_lll << std::endl;
	  }
	double dummy_2,eff_lll = 1.; //LooseLoose EFF
	//auto cc_Elll = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_2, eff_lll);
	auto cc_Elll = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy_2, eff_lll);
	if(cc_Elll==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigLoose[nTrig] = eff_lll;
	    m_ttHEvent->lepDataEffTrigLoose[nTrig] = dummy_2;
	    //std::cout << "3LLooseLoose:TriggerEff is for sys " << systvar.second << " : " << eff_lll << std::endl;
	  }
	
	short capped_totleptons = std::min(m_ttHEvent->total_leptons, LEPTON_ARR_SIZE);
	for (short idx = 0; idx < capped_totleptons; ++idx) {
	  const TLorentzVector* p4;
	  int lidx;
	  ttHML::LepType typ;
	  std::tie(p4, lidx, typ) = sorter[idx];
	  //dec_tight(*(myTriggeringElectrons)[lidx]) = 0;
	  if (typ == ttHML::ELECTRON){
	    if (idx==0) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==1) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tight(*(myTriggeringElectrons)[lidx]) = 1;}
	    else if (idx==2) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	  }
	} //TightLoose SF

	double sf_ltl = 1.;
	//auto cc_ltl = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_ltl);
	auto cc_ltl = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_ltl);
	if(cc_ltl==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigTightLoose[nTrig] = sf_ltl;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_3,eff_ltl = 1.; //TightLoose EFF
	//	auto cc_Eltl = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_3, eff_ltl);
	auto cc_Eltl = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy_3, eff_ltl);
	if(cc_Eltl==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigTightLoose[nTrig] = eff_ltl;
	    m_ttHEvent->lepDataEffTrigTightLoose[nTrig] = dummy_3;
	    //std::cout << "3LTightLoose:TriggerEff is for sys " << systvar.second << " : " << eff_ltl << std::endl;
	  }


	for (short idx = 0; idx < capped_totleptons; ++idx) {
	  const TLorentzVector* p4;
	  int lidx;
	  ttHML::LepType typ;
	  std::tie(p4, lidx, typ) = sorter[idx];
	  //dec_tight(*(myTriggeringElectrons)[lidx]) = 0;
	  if (typ == ttHML::ELECTRON){
	    if (idx==0) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==1) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==2) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tight(*(myTriggeringElectrons)[lidx]) = 1;}
	  }
	} //LooseTight SF

	double sf_llt = 1.;
	//auto cc_llt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_llt);
	auto cc_llt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_llt);
	if(cc_llt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigLooseTight[nTrig] = sf_llt;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_4,eff_llt = 1.; //TightLoose EFF
	//auto cc_Ellt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_4, eff_llt);
	auto cc_Ellt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringLeptons, dummy_4, eff_llt);
	if(cc_Ellt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepEffTrigLooseTight[nTrig] = eff_llt;
	    m_ttHEvent->lepDataEffTrigLooseTight[nTrig] = dummy_4;
	    //std::cout << "3LLooseTight:TriggerEff is for sys " << systvar.second << " : " << eff_llt << std::endl;
	  }
	
      }
    }
    /* // OLD trigger SF computation for SLT
	 for (const auto& systvar : m_lep_sf_names) {
	 auto ivar = systvar.first;
	 oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[0].EffTrigLoose[ivar]);
	 oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[0].EffTrigLoose[ivar]*m_leptons[0].SFTrigLoose[ivar]);
	 oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[0].EffTrigLoose[ivar]);
      oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[0].EffTrigLoose[ivar]*m_leptons[0].SFTrigLoose[ivar]);
    }
    for (int ilep = 1; ilep < m_ttHEvent->total_leptons; ++ilep) {
      for (const auto& systvar : m_lep_sf_names) {
	auto ivar = systvar.first;
	oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[ilep].EffTrigLoose[ivar]);
	oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[ilep].EffTrigLoose[ivar]*m_leptons[ilep].SFTrigLoose[ivar]);
	oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[ilep].EffTrigTight[ivar]);
	oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[ilep].EffTrigTight[ivar]*m_leptons[ilep].SFTrigTight[ivar]);
      }
    }
    m_ttHEvent->lepSFTrigLoose[0] = oneMinusTrigEffLoose[0][0] != 1 ? (1-oneMinusTrigEffLoose[0][1])/(1-oneMinusTrigEffLoose[0][0]) : 1;
    m_ttHEvent->lepSFTrigTight[0] = oneMinusTrigEffTight[0][0] != 1 ? (1-oneMinusTrigEffTight[0][1])/(1-oneMinusTrigEffTight[0][0]) : 1;
    //std::cout << "3L:TriggerScaleFactor is: " << m_ttHEvent->lepSFTrigTight[0] << std::endl;
    for (const auto& systvar : m_lep_sf_names) {
      auto ivar = systvar.first;
      if (ivar == top::topSFSyst::nominal) continue;
      m_ttHEvent->lepSFTrigLoose[ivar] = oneMinusTrigEffLoose[ivar][0] != 1 ? (1-oneMinusTrigEffLoose[ivar][1])/(1-oneMinusTrigEffLoose[ivar][0])/m_ttHEvent->lepSFTrigLoose[0] : 1;
      m_ttHEvent->lepSFTrigTight[ivar] = oneMinusTrigEffTight[ivar][0] != 1 ? (1-oneMinusTrigEffTight[ivar][1])/(1-oneMinusTrigEffTight[ivar][0])/m_ttHEvent->lepSFTrigTight[0] : 1;
    */
  
    break;
  case 4:
    {
      // Do a sorting for objects
      // (pt, idx, leptype)
      typedef std::tuple<const TLorentzVector*, int, ttHML::LepType> sorttype_t;
      std::vector<sorttype_t> sorter;
            
      size_t idx = 0;
      for (const auto elItr : myTriggeringElectrons) {
	sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHML::ELECTRON));
      }
      idx = 0;
      for (const auto muItr : myTriggeringMuons) {
	sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHML::MUON));
      }
      // sort by decreasing pt
      std::sort(sorter.begin(), sorter.end(),
		[](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
    
      
      int nTrig = -1;
      for (const auto& systvar : m_lep_trigger_sf_names) {
	++nTrig;

	short capped_totleptons = std::min(m_ttHEvent->total_leptons, LEPTON_ARR_SIZE);
	for (short idx = 0; idx < capped_totleptons; ++idx) {
	  const TLorentzVector* p4;
	  int lidx;
	  ttHML::LepType typ;
	  std::tie(p4, lidx, typ) = sorter[idx];
	  //dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 0;
	  if (typ == ttHML::ELECTRON){
	    if (idx==0) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==1) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==2) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tight(*(myTriggeringElectrons)[lidx]) = 1;}
	    else if (idx==3) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tight(*(myTriggeringElectrons)[lidx]) = 1;}
	  }
	}//TightTight

	double sf_tttt = 1.;
	//auto cc_tttt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_tttt);
	auto cc_tttt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_tttt);
	if(cc_tttt==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigTight[nTrig] = sf_tttt;
	    //std::cout << "4L:TriggerScaleFactor is: " << sf_tttt << std::endl;
	  }
	
	for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_loose(*e) = 1;} //LooseLoose
	double sf_llll = 1.;
	//auto cc_llll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_llll);
	auto cc_llll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringLeptons, sf_llll);
	if(cc_llll==CP::CorrectionCode::Ok)
	  {
	    m_ttHEvent->lepSFTrigLoose[nTrig] = sf_llll;
	    //std::cout << "4LLooseLoose:TriggerScaleFactor is: " << sf_llll << std::endl;
	  }	
      }
    }
    break;
  default:
    return;
  }
    
  //naaaaan
  for ( auto syst : m_lep_sf_names ) {
    auto ivar = syst.first;
      if( m_ttHEvent->lepSFTrigLoose[ivar] != m_ttHEvent->lepSFTrigLoose[ivar] ) {
	//std::cout<<"nanananana"<<std::endl;
	m_ttHEvent->lepSFTrigLoose[ivar] = 1;
      }
      if( m_ttHEvent->lepSFTrigTight[ivar] != m_ttHEvent->lepSFTrigTight[ivar] ) {
	//std::cout<<"nanananana"<<std::endl;
	m_ttHEvent->lepSFTrigTight[ivar] = 1;
      }
      
  }


}

