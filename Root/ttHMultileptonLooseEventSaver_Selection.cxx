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
      CopyElectron((Electrons)[lidx], m_leptons[idx]);
    } else {
   //   CopyMuon(*(Muons)[lidx], m_leptons[idx]);
    }
  }
}

void ttHMultileptonLooseEventSaver::
CopyElectron(xAOD::Electron& el, ttHML::Lepton& lep) {
lep.EtaBE2 = el.caloCluster()->etaBE(2);
/*  CopyIParticle(el, lep);
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
  }*/
}








