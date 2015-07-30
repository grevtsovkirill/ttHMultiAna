#include "ttHMultilepton/Lepton.h"
#include "boost/format.hpp"

template<typename PTR> void CreateBranch(std::shared_ptr<top::TreeManager> tree, PTR addr, 
		    const char* basename, 
		    const char* brtype, int index) {
boost::format fmt1("%1%%2%"), fmt2("%1%%2%/%3%");
  fmt1 % basename % index; fmt2 % basename % index % brtype;
  tree->makeOutputVariable(*addr, fmt1.str().c_str());
}

void ttHMultilepton::Lepton::BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index) {
  CreateBranch(tree, &PtID, "lep_PtID_", "F", index);
  CreateBranch(tree, &PtIDuncorr, "lep_PtIDuncorr_", "F", index);
  CreateBranch(tree, &PtME, "lep_PtME_", "F", index);
  CreateBranch(tree, &PtMEuncorr, "lep_PtMEuncorr_", "F", index);
  CreateBranch(tree, &ID, "lep_ID_", "F", index);
  CreateBranch(tree, &Pt, "lep_Pt_", "F", index);
  //CreateBranch(tree, &Px, "lep_Px_", "F", index);
  //CreateBranch(tree, &Py, "lep_Py_", "F", index);
  //CreateBranch(tree, &Pz, "lep_Pz_", "F", index);
  CreateBranch(tree, &E, "lep_E_", "F", index);
  CreateBranch(tree, &Eta, "lep_Eta_", "F", index);
  CreateBranch(tree, &Phi, "lep_Phi_", "F", index);
  CreateBranch(tree, &Etcone20Uncorr, "lep_Etcone20Uncorr_", "F", index);
  CreateBranch(tree, &Etcone30Uncorr, "lep_Etcone30Uncorr_", "F", index);
  CreateBranch(tree, &Etcone40Uncorr, "lep_Etcone40Uncorr_", "F", index);
  CreateBranch(tree, &Etcone20, "lep_Etcone20_", "F", index);
  CreateBranch(tree, &Etcone30, "lep_Etcone30_", "F", index);
  CreateBranch(tree, &Etcone40, "lep_Etcone40_", "F", index);
  CreateBranch(tree, &Ptcone20, "lep_Ptcone20_", "F", index);
  CreateBranch(tree, &Ptcone30, "lep_Ptcone30_", "F", index);
  CreateBranch(tree, &Ptcone40, "lep_Ptcone40_", "F", index);
  CreateBranch(tree, &Nucone20, "lep_Nucone20_", "I", index);
  CreateBranch(tree, &Nucone30, "lep_Nucone30_", "I", index);
  CreateBranch(tree, &Nucone40, "lep_Nucone40_", "I", index);
  CreateBranch(tree, &MI10_max40_ptsum, "lep_MI10_max40_ptsum_", "F", index);
  CreateBranch(tree, &Eiso90Etcone20, "lep_Eiso90Etcone20_", "F", index);
  CreateBranch(tree, &Eiso90ptcone30, "lep_Eiso90ptcone30_", "F", index);
  CreateBranch(tree, &z0PV, "lep_z0PV_", "F", index);
  CreateBranch(tree, &sigd0PV, "lep_sigd0PV_", "F", index);
  CreateBranch(tree, &D0, "lep_D0_", "F", index);
  CreateBranch(tree, &Z0SinTheta, "lep_Z0SinTheta_", "F", index);
  //CreateBranch(tree, &Truth_parent_particle_ID, "lep_truth_parent_particle_id", "I", index);
  //CreateBranch(tree, &Truth_particle_ID, "lep_truth_particle_id", "I", index);
  

  //CreateBranch(tree, &MagD0, "lep_MagD0_", "F", index);

//   tree->Branch("DRlep0jet",&DRlep0jet,"DRlep0jet/F");
//   tree->Branch("DRlep1jet",&DRlep1jet,"DRlep1jet/F");

 // CreateBranch(tree, &Sys ,"lep_Sys_", "std::vector<float>",index);
  
  CreateBranch(tree, &isVeryTightLH, "lep_isVeryTightLH_", "B", index);
  CreateBranch(tree, &isTightLH, "lep_isTightLH_", "B", index);
  CreateBranch(tree, &isMediumLH, "lep_isMediumLH_", "B", index);
  CreateBranch(tree, &isLooseLH, "lep_isLooseLH_", "B", index);
  CreateBranch(tree, &isVeryLooseLH, "lep_isVeryLooseLH_", "B", index);
  CreateBranch(tree, &isCombined, "lep_isCombined_", "B", index);
  CreateBranch(tree, &isTight, "lep_isTight_", "B", index);
  CreateBranch(tree, &isMedium, "lep_isMedium_", "B", index);
  CreateBranch(tree, &isLoose, "lep_isLoose_", "B", index);
  CreateBranch(tree, &isHSG3Clear, "lep_isHSG3Clear_", "B", index);
  CreateBranch(tree, &isHSG3IsoClear, "lep_isHSG3IsoClear_", "B", index);
  CreateBranch(tree, &isTrigMatch, "lep_isTrigMatch_", "B", index);
  CreateBranch(tree, &isFakable, "lep_isFakable_", "B", index);
  CreateBranch(tree, &BLayer_hit, "lep_BLayer_hit_", "B", index);
  CreateBranch(tree, &conv, "lep_conv_", "B", index);
  CreateBranch(tree, &Author, "lep_Author_", "I", index);
  CreateBranch(tree, &Index, "lep_Index_", "I", index);

//  CreateBranch(tree, &TrigSFEventWeight, "lep_TrigSFEventWeight_", "D", index);
  CreateBranch(tree, &SFRecoEventWeight, "lep_SFRecoEventWeight_", "D", index);
  CreateBranch(tree, &SFIdEventWeight, "lep_SFIdEventWeight_", "D", index);
  CreateBranch(tree, &SFIsoEventWeight, "lep_SFIsoEventWeight_", "D", index);

//  CreateBranch(tree, &TrigSFError, "lep_TrigSFError_", "D", index);
  CreateBranch(tree, &SFRecoError, "lep_SFRecoError_", "D", index);
  CreateBranch(tree, &SFIsoError, "lep_SFErrorIso_", "D", index);
  CreateBranch(tree, &SFIdError, "lep_SFIdError_", "D", index);
}
