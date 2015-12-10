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
  CreateBranch(tree, &ID, "lep_ID_", index);
  CreateBranch(tree, &Index, "lep_Index_", index);
  CreateBranch(tree, &Pt, "lep_Pt_", index);
  //CreateBranch(tree, &Px, "lep_Px_", index);
  //CreateBranch(tree, &Py, "lep_Py_", index);
  //CreateBranch(tree, &Pz, "lep_Pz_", index);
  CreateBranch(tree, &E, "lep_E_", index);
  CreateBranch(tree, &Eta, "lep_Eta_", index);
  CreateBranch(tree, &Phi, "lep_Phi_", index);
  // isolation variables
  CreateBranch(tree, &topoEtcone20, "lep_topoEtcone20_", index);
  CreateBranch(tree, &topoEtcone30, "lep_topoEtcone30_", index);
  CreateBranch(tree, &topoEtcone40, "lep_topoEtcone40_", index);
  CreateBranch(tree, &ptVarcone20, "lep_ptVarcone20_", index);
  CreateBranch(tree, &ptVarcone30, "lep_ptVarcone30_", index);
  CreateBranch(tree, &ptVarcone40, "lep_ptVarcone40_", index);
  // impact parameters
  CreateBranch(tree, &sigd0PV, "lep_sigd0PV_", index);
  CreateBranch(tree, &Z0SinTheta, "lep_Z0SinTheta_", index);
  // LH ID
  CreateBranch(tree, &isTightLH, "lep_isTightLH_", index);
  CreateBranch(tree, &isMediumLH, "lep_isMediumLH_", index);
  CreateBranch(tree, &isLooseLH, "lep_isLooseLH_", index);
  // ID
  CreateBranch(tree, &isTight, "lep_isTight_", index);
  CreateBranch(tree, &isMedium, "lep_isMedium_", index);
  CreateBranch(tree, &isLoose, "lep_isLoose_", index);
  // isolation WPs
  CreateBranch(tree, &isolationLooseTrackOnly, "lep_isolationLooseTrackOnly_", index);
  CreateBranch(tree, &isolationLoose, "lep_isolationLoose_", index);
  CreateBranch(tree, &isolationGradient, "lep_isolationGradient_", index);
  CreateBranch(tree, &isolationGradientLoose, "lep_isolationGradientLoose_", index);
  CreateBranch(tree, &isolationFixedCutTight, "lep_isolationFixedCutTight_", index);
  CreateBranch(tree, &isolationFixedCutTightTrackOnly, "lep_isolationFixedCutTightTrackOnly_", index);
  CreateBranch(tree, &isolationFixedCutLoose, "lep_isolationFixedCutLoose_", index);
  // trigger matching
  CreateBranch(tree, &isTrigMatch, "lep_isTrigMatch_", index);

  // SFs (not yet filled)
  //  CreateBranch(tree, &TrigSFEventWeight, "lep_TrigSFEventWeight_", index);
  CreateBranch(tree, &SFRecoEventWeight, "lep_SFRecoEventWeight_", index);
  CreateBranch(tree, &SFIdEventWeight, "lep_SFIdEventWeight_", index);
  CreateBranch(tree, &SFIsoEventWeight, "lep_SFIsoEventWeight_", index);
 
}
