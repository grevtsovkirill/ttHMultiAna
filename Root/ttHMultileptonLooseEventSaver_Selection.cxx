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
template<typename T> int CountPassOR(DataVector<T>& vec, bool doTauOR = false) {
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
   //   CopyMuon(*(Muons)[lidx], m_leptons[idx]);
    }
  }
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

  static SG::AuxElement::Accessor<float> promptLeptonIso_TagWeight("PromptLeptonIso_TagWeight");
  lep.promptLeptonIso_TagWeight = ( promptLeptonIso_TagWeight.isAvailable(el) ) ? promptLeptonIso_TagWeight(el) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_sv1_jf_ntrkv("PromptLeptonIso_sv1_jf_ntrkv");
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
  
  // trigger matching, electron pt > 25 GeV
  if (m_runYear == 2015) {
    lep.isTrigMatch = ( el.pt() > 25e3 && (
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e24_lhmedium_L1EM20VH", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e120_lhloose", (char) 0)));
  }
  else if (m_runYear == 2016) {
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
/*  for (const auto& systvar : m_lep_sf_names) {
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
  }*/
}
void
ttHMultileptonLooseEventSaver::CopyJets(const xAOD::JetContainer& goodJets) {
  // don't actually copy anything ATM, just give yields of jets & btags
  m_ttHEvent->nJets_OR = goodJets.size();
//  m_ttHEvent->nJets_OR_T = CountPassOR(*goodJets, true);
  m_ttHEvent->nTruthJets_OR = this->getNTruthJets(goodJets);


  m_ttHEvent->nJets_OR_MV2c20_85   = 0;
  m_ttHEvent->nJets_OR_MV2c20_70   = 0;
  m_ttHEvent->nJets_OR_MV2c20_77   = 0;
  m_ttHEvent->nJets_OR_MV2c20_60   = 0;
  m_ttHEvent->nJets_OR_T_MV2c20_85 = 0;
  m_ttHEvent->nJets_OR_T_MV2c20_70 = 0;
  m_ttHEvent->nJets_OR_T_MV2c20_77 = 0;
  m_ttHEvent->nJets_OR_T_MV2c20_60 = 0;
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
      if( btagging->MVx_discriminant("MV2c20", mv2c) ) {
	if (mv2c > 0.0206) {
	  m_ttHEvent->nJets_OR_MV2c20_85++;
	  if (mv2c > 0.4803) {
	    m_ttHEvent->nJets_OR_MV2c20_77++;
	    if (mv2c > 0.7110) {
	      m_ttHEvent->nJets_OR_MV2c20_70++;
	      if (mv2c > 0.8867) {
		m_ttHEvent->nJets_OR_MV2c20_60++;
	      }
	    }
	  }
	}
      }
      if( btagging->MVx_discriminant("MV2c10", mv2c) ) {
	if (mv2c > 0.1758) {
	  m_ttHEvent->nJets_OR_MV2c10_85++;
	  if (mv2c > 0.6459) {
	    m_ttHEvent->nJets_OR_MV2c10_77++;
	    if (mv2c > 0.8244) {
	      m_ttHEvent->nJets_OR_MV2c10_70++;
	      if (mv2c > 0.9349) {
		m_ttHEvent->nJets_OR_MV2c10_60++;
	      }
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
	if( btagging->MVx_discriminant("MV2c20", mv2c) ) {
	  if (mv2c > 0.0206) {
	    m_ttHEvent->nJets_OR_T_MV2c20_85++;
	    if (mv2c > 0.4803) {
	      m_ttHEvent->nJets_OR_T_MV2c20_77++;
	      if (mv2c > 0.7110) {
		m_ttHEvent->nJets_OR_T_MV2c20_70++;
		if (mv2c > 0.8867) {
		  m_ttHEvent->nJets_OR_T_MV2c20_60++;
		}
	      }
	    }
	  }
	}
	if( btagging->MVx_discriminant("MV2c10", mv2c) ) {
	  if (mv2c > 0.1758) {
	    m_ttHEvent->nJets_OR_T_MV2c10_85++;
	    if (mv2c > 0.6459) {
	      m_ttHEvent->nJets_OR_T_MV2c10_77++;
	      if (mv2c > 0.8244) {
		m_ttHEvent->nJets_OR_T_MV2c10_70++;
		if (mv2c > 0.9349) {
		  m_ttHEvent->nJets_OR_T_MV2c10_60++;
		}
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

/*  for( auto syst : m_tau_sf_names ) {
    auto ivar = syst.first;
    if( !m_doSFSystematics && ivar != 0 ) continue;
    // AnalysisTop tight/loose and our tight/loose are reversed
    MLTau.SFTight[ivar] = m_isMC ? m_sfRetriever->tauSF(xTau, ivar,  true) : 1.0;
    MLTau.SFLoose[ivar] = m_isMC ? m_sfRetriever->tauSF(xTau, ivar, false)               : 1.0;
  }*/
}

void
ttHMultileptonLooseEventSaver::CopyTaus(const xAOD::TauJetContainer& goodTaus) {
  memset(&m_taus, 0, sizeof(m_taus));
  int totalTaus = goodTaus.size();
  m_ttHEvent->nTaus_OR_Pt25 = totalTaus;

//  goodTaus.sort(top::descendingPtSorter);

  for(int i = 0; i < totalTaus && i < TAU_ARR_SIZE; ++i) {
    CopyTau( *(goodTaus.at(i)) , m_taus[i] );
  }
}
void
ttHMultileptonLooseEventSaver::CopyHT(const xAOD::ElectronContainer& goodEl, const xAOD::MuonContainer& goodMu, const xAOD::JetContainer& goodJets, const xAOD::TauJetContainer& goodTaus) {
  m_ttHEvent->HT = 0;
  m_ttHEvent->HT_lep = 0;
  m_ttHEvent->HT_jets = 0;

  for (const auto jetItr : goodJets) {
    m_ttHEvent->HT += jetItr->pt();
    m_ttHEvent->HT_jets += jetItr->pt();
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

