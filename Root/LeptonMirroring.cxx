#include "ttHMultilepton/Lepton.h"
#include "boost/format.hpp"

template<typename PTR> void CreateBranch(std::shared_ptr<top::TreeManager> tree, PTR addr,
		    const char* basename,
		    int index) {
  boost::format fmt1("%1%%2%");
  fmt1 % basename % index;
  tree->makeOutputVariable(*addr, fmt1.str().c_str());
}

void ttHMultilepton::Lepton::BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index) {
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
  CreateBranch(tree, &ptcone20,  "lep_ptcone20_", index);
  CreateBranch(tree, &ptcone30,  "lep_ptcone30_", index);
  CreateBranch(tree, &ptcone40,  "lep_ptcone40_", index);
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
  // truth matching
  CreateBranch(tree, &isPrompt,    "lep_isPrompt_", index);
  // fake lepton (!prompt and NOT QFlip --> includes non prompt HF leptons, photon conversions, brems leptons which are not QMisID,...)
  CreateBranch(tree, &isFakeLep, "lep_isFakeLep_", index);
  CreateBranch(tree, &isQMisID, "lep_isQMisID_", index);
  CreateBranch(tree, &isConvPh, "lep_isConvPh_", index);
  CreateBranch(tree, &isISR_FSR_Ph, "lep_isISR_FSR_Ph_", index);
  CreateBranch(tree, &isBrems, "lep_isBrems_", index);

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

  // specific observables for electron
  CreateBranch(tree, &wstot,    "lep_wstot_", index);
  CreateBranch(tree, &Reta,     "lep_Reta_", index);
  CreateBranch(tree, &Rphi,     "lep_Rphi_", index);
  CreateBranch(tree, &Rhad1,    "lep_Rhad1_", index);
  CreateBranch(tree, &Rhad,     "lep_Rhad_", index);
  CreateBranch(tree, &ws3,      "lep_ws3_", index);
  CreateBranch(tree, &w2,       "lep_w2_", index);
  CreateBranch(tree, &f1,       "lep_f1_", index);
  CreateBranch(tree, &Eratio,   "lep_Eratio_", index);
  CreateBranch(tree, &f3,       "lep_f3_", index);
  CreateBranch(tree, &deltaEta, "lep_deltaEta_", index);
  CreateBranch(tree, &deltaPhiRescaled2, "lep_deltaPhiRescaled2_", index);
  CreateBranch(tree, &QoverP,   "lep_QoverP_", index);
  CreateBranch(tree, &EoverP,   "lep_EoverP_", index);

  // specific observables for muon
  CreateBranch(tree, &momBalSignif,    "lep_momBalSignif_", index);
  CreateBranch(tree, &scatCurvSignif,  "lep_scatCurvSignif_", index);
  CreateBranch(tree, &scatNeighSignif, "lep_scatNeighSignif_", index);
  //CreateBranch(tree, &qOverP,          "lep_qOverP_", index);
  CreateBranch(tree, &rho,             "lep_rho_", index);
  CreateBranch(tree, &qOverPsigma,     "lep_qOverPsigma_", index);
  CreateBranch(tree, &qOverPsignif,    "lep_qOverPsignif_", index);
  CreateBranch(tree, &reducedChi2,     "lep_reducedChi2_", index);
  CreateBranch(tree, &numPrecLayers,   "lep_numPrecLayers_", index);
 
}
