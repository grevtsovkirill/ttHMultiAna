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
  CreateBranch(tree, &PtID, "lep_PtID_", index);
  CreateBranch(tree, &PtIDuncorr, "lep_PtIDuncorr_", index);
  CreateBranch(tree, &PtME, "lep_PtME_", index);
  CreateBranch(tree, &PtMEuncorr, "lep_PtMEuncorr_", index);
  CreateBranch(tree, &ID, "lep_ID_", index);
  CreateBranch(tree, &Pt, "lep_Pt_", index);
  //CreateBranch(tree, &Px, "lep_Px_", index);
  //CreateBranch(tree, &Py, "lep_Py_", index);
  //CreateBranch(tree, &Pz, "lep_Pz_", index);
  CreateBranch(tree, &E, "lep_E_", index);
  CreateBranch(tree, &Eta, "lep_Eta_", index);
  CreateBranch(tree, &Phi, "lep_Phi_", index);
  CreateBranch(tree, &Etcone20Uncorr, "lep_Etcone20Uncorr_", index);
  CreateBranch(tree, &Etcone30Uncorr, "lep_Etcone30Uncorr_", index);
  CreateBranch(tree, &Etcone40Uncorr, "lep_Etcone40Uncorr_", index);
  CreateBranch(tree, &Etcone20, "lep_Etcone20_", index);
  CreateBranch(tree, &Etcone30, "lep_Etcone30_", index);
  CreateBranch(tree, &Etcone40, "lep_Etcone40_", index);
  CreateBranch(tree, &Ptcone20, "lep_Ptcone20_", index);
  CreateBranch(tree, &Ptcone30, "lep_Ptcone30_", index);
  CreateBranch(tree, &Ptcone40, "lep_Ptcone40_", index);
  CreateBranch(tree, &Nucone20, "lep_Nucone20_", index);
  CreateBranch(tree, &Nucone30, "lep_Nucone30_", index);
  CreateBranch(tree, &Nucone40, "lep_Nucone40_", index);
  CreateBranch(tree, &MI10_max40_ptsum, "lep_MI10_max40_ptsum_", index);
  CreateBranch(tree, &Eiso90Etcone20, "lep_Eiso90Etcone20_", index);
  CreateBranch(tree, &Eiso90ptcone30, "lep_Eiso90ptcone30_", index);
  CreateBranch(tree, &z0PV, "lep_z0PV_", index);
  CreateBranch(tree, &sigd0PV, "lep_sigd0PV_", index);
  CreateBranch(tree, &D0, "lep_D0_", index);
  CreateBranch(tree, &Z0SinTheta, "lep_Z0SinTheta_", index);
  //CreateBranch(tree, &Truth_parent_particle_ID, "lep_truth_parent_particle_id", index);
  //CreateBranch(tree, &Truth_particle_ID, "lep_truth_particle_id", index);
  

  //CreateBranch(tree, &MagD0, "lep_MagD0_", index);

//   tree->Branch("DRlep0jet",&DRlep0jet,"DRlep0jet/F");
//   tree->Branch("DRlep1jet",&DRlep1jet,"DRlep1jet/F");

 // CreateBranch(tree, &Sys ,"lep_Sys_", "std::vector<float>",index);
  
  CreateBranch(tree, &isVeryTightLH, "lep_isVeryTightLH_", index);
  CreateBranch(tree, &isTightLH, "lep_isTightLH_", index);
  CreateBranch(tree, &isMediumLH, "lep_isMediumLH_", index);
  CreateBranch(tree, &isLooseLH, "lep_isLooseLH_", index);
  CreateBranch(tree, &isVeryLooseLH, "lep_isVeryLooseLH_", index);
  CreateBranch(tree, &isCombined, "lep_isCombined_", index);
  CreateBranch(tree, &isTight, "lep_isTight_", index);
  CreateBranch(tree, &isMedium, "lep_isMedium_", index);
  CreateBranch(tree, &isLoose, "lep_isLoose_", index);
  CreateBranch(tree, &isHSG3Clear, "lep_isHSG3Clear_", index);
  CreateBranch(tree, &isHSG3IsoClear, "lep_isHSG3IsoClear_", index);
  CreateBranch(tree, &isolationLooseTrackOnly, "lep_isolationLooseTrackOnly_", index);
  CreateBranch(tree, &isolationLoose, "lep_isolationLoose_", index);
  CreateBranch(tree, &isolationTight, "lep_isolationTight_", index);
  CreateBranch(tree, &isolationGradient, "lep_isolationGradient_", index);
  CreateBranch(tree, &isolationGradientLoose, "lep_isolationGradientLoose_", index);
  CreateBranch(tree, &isTrigMatch, "lep_isTrigMatch_", index);
  CreateBranch(tree, &isFakable, "lep_isFakable_", index);
  CreateBranch(tree, &BLayer_hit, "lep_BLayer_hit_", index);
  CreateBranch(tree, &conv, "lep_conv_", index);
  CreateBranch(tree, &Author, "lep_Author_", index);
  CreateBranch(tree, &Index, "lep_Index_", index);

//  CreateBranch(tree, &TrigSFEventWeight, "lep_TrigSFEventWeight_", index);
  CreateBranch(tree, &SFRecoEventWeight, "lep_SFRecoEventWeight_", index);
  CreateBranch(tree, &SFIdEventWeight, "lep_SFIdEventWeight_", index);
  CreateBranch(tree, &SFIsoEventWeight, "lep_SFIsoEventWeight_", index);

//  CreateBranch(tree, &TrigSFError, "lep_TrigSFError_", index);
  CreateBranch(tree, &SFRecoError, "lep_SFRecoError_", index);
  CreateBranch(tree, &SFIsoError, "lep_SFErrorIso_", index);
  CreateBranch(tree, &SFIdError, "lep_SFIdError_", index);
}
