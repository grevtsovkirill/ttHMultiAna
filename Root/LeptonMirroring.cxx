#include "ttHMultilepton/Lepton.h"
#include "boost/format.hpp"

template<typename PTR> void CreateBranch(std::shared_ptr<top::TreeManager> tree, PTR addr,
		    const char* basename,
		    int index) {
  boost::format fmt1("%1%%2%");
  fmt1 % basename % index;
  tree->makeOutputVariable(*addr, fmt1.str().c_str());
}

void ttHML::Lepton::BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index) {
  CreateBranch(tree, &ID,    "lep_ID_", index);
  CreateBranch(tree, &Index, "lep_Index_", index);
  CreateBranch(tree, &Pt,    "lep_Pt_", index);
  //CreateBranch(tree, &Px, "lep_Px_", index);
  //CreateBranch(tree, &Py, "lep_Py_", index);
  //CreateBranch(tree, &Pz, "lep_Pz_", index);
  CreateBranch(tree, &E,      "lep_E_", index);
  CreateBranch(tree, &Eta,    "lep_Eta_", index);
  CreateBranch(tree, &Phi,    "lep_Phi_", index);
  CreateBranch(tree, &EtaBE2, "lep_EtaBE2_", index);
  // isolation variables
  CreateBranch(tree, &topoEtcone20, "lep_topoEtcone20_", index);
  CreateBranch(tree, &topoEtcone30, "lep_topoEtcone30_", index);
  CreateBranch(tree, &topoEtcone40, "lep_topoEtcone40_", index);
  CreateBranch(tree, &ptVarcone20,  "lep_ptVarcone20_", index);
  CreateBranch(tree, &ptVarcone30,  "lep_ptVarcone30_", index);
  CreateBranch(tree, &ptVarcone40,  "lep_ptVarcone40_", index);
  // impact parameters
  CreateBranch(tree, &sigd0PV,    "lep_sigd0PV_", index);
  CreateBranch(tree, &Z0SinTheta, "lep_Z0SinTheta_", index);
  CreateBranch(tree, &d0,         "lep_d0_", index);
  CreateBranch(tree, &z0,         "lep_z0_", index);
  CreateBranch(tree, &vz,         "lep_vz_", index);
  CreateBranch(tree, &deltaz0,    "lep_deltaz0_", index);
  // LH ID
  CreateBranch(tree, &isTightLH,  "lep_isTightLH_", index);
  CreateBranch(tree, &isMediumLH, "lep_isMediumLH_", index);
  CreateBranch(tree, &isLooseLH,  "lep_isLooseLH_", index);
  // ID
  CreateBranch(tree, &isTight,  "lep_isTight_", index);
  CreateBranch(tree, &isMedium, "lep_isMedium_", index);
  CreateBranch(tree, &isLoose,  "lep_isLoose_", index);
  // isolation WPs
  CreateBranch(tree, &isolationLooseTrackOnly,         "lep_isolationLooseTrackOnly_", index);
  CreateBranch(tree, &isolationLoose,                  "lep_isolationLoose_", index);
  CreateBranch(tree, &isolationGradient,               "lep_isolationGradient_", index);
  CreateBranch(tree, &isolationGradientLoose,          "lep_isolationGradientLoose_", index);
  CreateBranch(tree, &isolationFixedCutTight,          "lep_isolationFixedCutTight_", index);
  CreateBranch(tree, &isolationFixedCutTightTrackOnly, "lep_isolationFixedCutTightTrackOnly_", index);
  CreateBranch(tree, &isolationFixedCutLoose,          "lep_isolationFixedCutLoose_", index);
  // trigger matching
  CreateBranch(tree, &isTrigMatch, "lep_isTrigMatch_", index);
  CreateBranch(tree, &isTrigMatchDLT, "lep_isTrigMatchDLT_", index);
  // truth matching
  CreateBranch(tree, &isPrompt,    "lep_isPrompt_", index);
  // fake lepton (!prompt and NOT QFlip --> includes non prompt HF leptons, photon conversions, brems leptons which are not QMisID,...)
  CreateBranch(tree, &isFakeLep, "lep_isFakeLep_", index);
  CreateBranch(tree, &isQMisID, "lep_isQMisID_", index);
  CreateBranch(tree, &isConvPh, "lep_isConvPh_", index);
  CreateBranch(tree, &isExtConvPh, "lep_isExtConvPh_", index);
  CreateBranch(tree, &isIntConvPh, "lep_isIntConvPh_", index);
  CreateBranch(tree, &isISR_FSR_Ph, "lep_isISR_FSR_Ph_", index);
  CreateBranch(tree, &isBrems, "lep_isBrems_", index);
  CreateBranch(tree, &nTrackParticles, "lep_nTrackParticles_", index);
  CreateBranch(tree, &MeeCO, "lep_MeeCO_", index);
  CreateBranch(tree, &RadiusCO, "lep_RadiusCO_", index);
  CreateBranch(tree, &SeparationMinDCT, "lep_SeparationMinDCT_", index);

  CreateBranch(tree, &ClosestSiTracknIL,  "lep_ClosestSiTracknIL_", index);
  CreateBranch(tree, &ClosestSiTrackeIL,  "lep_ClosestSiTrackeIL_", index);
  CreateBranch(tree, &ClosestSiTracknNIL, "lep_ClosestSiTracknNIL_", index);
  CreateBranch(tree, &ClosestSiTrackeNIL, "lep_ClosestSiTrackeNIL_", index);

  CreateBranch(tree, &BestMatchTrackPt,   "lep_BestMatchTrackPt_", index);
  CreateBranch(tree, &BestMatchTrackEta,  "lep_BestMatchTrackEta_", index);
  CreateBranch(tree, &BestMatchTrackPhi,  "lep_BestMatchTrackPhi_", index);
  CreateBranch(tree, &BestMatchTrackD0,   "lep_BestMatchTrackD0_", index);
  CreateBranch(tree, &BestMatchTrackZ0,   "lep_BestMatchTrackZ0_", index);
  CreateBranch(tree, &BestMatchTrackQ,    "lep_BestMatchTrackQ_", index);

  CreateBranch(tree, &ClosestSiTrackPt,   "lep_ClosestSiTrackPt_", index);
  CreateBranch(tree, &ClosestSiTrackEta,  "lep_ClosestSiTrackEta_", index);
  CreateBranch(tree, &ClosestSiTrackPhi,  "lep_ClosestSiTrackPhi_", index);
  CreateBranch(tree, &ClosestSiTrackD0,   "lep_ClosestSiTrackD0_", index);
  CreateBranch(tree, &ClosestSiTrackZ0,   "lep_ClosestSiTrackZ0_", index);
  CreateBranch(tree, &ClosestSiTrackQ,    "lep_ClosestSiTrackQ_", index);


  CreateBranch(tree, &chargeIDBDTLoose, "lep_chargeIDBDTLoose_", index);
  CreateBranch(tree, &chargeIDBDTMedium, "lep_chargeIDBDTMedium_", index);
  CreateBranch(tree, &chargeIDBDTTight, "lep_chargeIDBDTTight_", index);
//  CreateBranch(tree, &promptLeptonIso_TagWeight, "lep_promptLeptonIso_TagWeight_", index);
//  CreateBranch(tree, &promptLeptonIso_sv1_jf_ntrkv, "lep_promptLeptonIso_sv1_jf_ntrkv_", index);
//  CreateBranch(tree, &promptLeptonIso_TrackJetNTrack, "lep_promptLeptonIso_TrackJetNTrack_", index);
//  CreateBranch(tree, &promptLeptonIso_ip2, "lep_promptLeptonIso_ip2_", index);
//  CreateBranch(tree, &promptLeptonIso_ip3, "lep_promptLeptonIso_ip3_", index);
//  CreateBranch(tree, &promptLeptonIso_DRlj, "lep_promptLeptonIso_DRlj_", index);
//  CreateBranch(tree, &promptLeptonIso_LepJetPtFrac, "lep_promptLeptonIso_LepJetPtFrac_", index);
//  CreateBranch(tree, &promptLepton_TagWeight, "lep_promptLepton_TagWeight_", index);
//  CreateBranch(tree, &promptLeptonNoIso_TagWeight, "lep_promptLeptonNoIso_TagWeight_", index);

  CreateBranch(tree, &promptLeptonInput_sv1_jf_ntrkv, "lep_promptLeptonInput_sv1_jf_ntrkv_", index);
  CreateBranch(tree, &promptLeptonInput_TrackJetNTrack, "lep_promptLeptonInput_TrackJetNTrack_", index);
  CreateBranch(tree, &promptLeptonInput_DL1mu, "lep_promptLeptonInput_DL1mu_", index);
  CreateBranch(tree, &promptLeptonInput_DRlj, "lep_promptLeptonInput_DRlj_", index);
  CreateBranch(tree, &promptLeptonInput_LepJetPtFrac, "lep_promptLeptonInput_LepJetPtFrac_", index);
  CreateBranch(tree, &promptLeptonInput_PtFrac, "lep_promptLeptonInput_PtFrac_", index);
  CreateBranch(tree, &promptLeptonInput_PtRel, "lep_promptLeptonInput_PtRel_", index);
  CreateBranch(tree, &promptLeptonInput_ip2, "lep_promptLeptonInput_ip2_", index);
  CreateBranch(tree, &promptLeptonInput_ip3, "lep_promptLeptonInput_ip3_", index);
  CreateBranch(tree, &promptLeptonInput_rnnip, "lep_promptLeptonInput_rnnip_", index);

  CreateBranch(tree, &promptLeptonIso_TagWeight, "lep_promptLeptonIso_TagWeight_", index);
  CreateBranch(tree, &promptLeptonVeto_TagWeight, "lep_promptLeptonVeto_TagWeight_", index);

  CreateBranch(tree, &mujet_jetPt,"lep_jet_Pt_",index);
  CreateBranch(tree, &mujet_jetNTrk,"lep_jet_nTrk_",index);
  CreateBranch(tree, &mujet_jetSumPtTrk,"lep_jet_sumPtTrk_",index);
  CreateBranch(tree, &mujet_mv2c10,"lep_jet_mv2c10_",index);
  CreateBranch(tree, &mujet_deltaR,"lep_jet_deltaR_",index);
  CreateBranch(tree, &mujet_ptRel,"lep_jet_ptRel_",index);
  CreateBranch(tree, &mujet_jetPtOverpt,"lep_jet_ptOverMuPt_",index);
  CreateBranch(tree, &mujet_BDT,"lep_jet_BDT_",index);

  CreateBranch(tree, &isTruthMatched,"lep_isTruthMatched_", index);
  CreateBranch(tree, &truthType,     "lep_truthType_", index);
  CreateBranch(tree, &truthOrigin,   "lep_truthOrigin_", index);
  CreateBranch(tree, &truthPdgId,    "lep_truthPdgId_", index);
  CreateBranch(tree, &truthStatus,   "lep_truthStatus_", index);
  CreateBranch(tree, &truthParentType,     "lep_truthParentType_", index);
  CreateBranch(tree, &truthParentOrigin,   "lep_truthParentOrigin_", index);
  CreateBranch(tree, &truthParentPdgId,    "lep_truthParentPdgId_", index);
  CreateBranch(tree, &truthParentStatus,   "lep_truthParentStatus_", index);
  CreateBranch(tree, &truthPt,       "lep_truthPt_", index);
  CreateBranch(tree, &truthEta,      "lep_truthEta_", index);
  CreateBranch(tree, &truthPhi,      "lep_truthPhi_", index);
  CreateBranch(tree, &truthM,        "lep_truthM_", index);
  CreateBranch(tree, &truthE,        "lep_truthE_", index);
  CreateBranch(tree, &truthRapidity, "lep_truthRapidity_", index);
  CreateBranch(tree, &ambiguityType, "lep_ambiguityType_", index);
  // SFs
  CreateBranch(tree, &SFIDLoose[0],   "lep_SFIDLoose_", index);
  CreateBranch(tree, &SFIDTight[0],   "lep_SFIDTight_", index);
  CreateBranch(tree, &SFTrigLoose[0], "lep_SFTrigLoose_", index);
  CreateBranch(tree, &SFTrigTight[0], "lep_SFTrigTight_", index);
  CreateBranch(tree, &EffTrigLoose[0], "lep_EffTrigLoose_", index);
  CreateBranch(tree, &EffTrigTight[0], "lep_EffTrigTight_", index);
  CreateBranch(tree, &SFIsoLoose[0],  "lep_SFIsoLoose_", index);
  CreateBranch(tree, &SFIsoTight[0],  "lep_SFIsoTight_", index);
  CreateBranch(tree, &SFReco[0],      "lep_SFReco_", index);
  CreateBranch(tree, &SFTTVA[0],      "lep_SFTTVA_", index);
  CreateBranch(tree, &SFObjLoose[0],  "lep_SFObjLoose_", index);
  CreateBranch(tree, &SFObjTight[0],  "lep_SFObjTight_", index);
  CreateBranch(tree, &nInnerPix, "lep_nInnerPix_", index);
  CreateBranch(tree, &firstEgMotherPdgId, "lep_firstEgMotherPdgId_", index);
  CreateBranch(tree, &firstEgMotherTruthType, "lep_firstEgMotherTruthType_", index);
  CreateBranch(tree, &firstEgMotherTruthOrigin, "lep_firstEgMotherTruthOrigin_", index);
}

