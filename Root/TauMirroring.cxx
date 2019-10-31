#include "ttHMultilepton/Tau.h"
#include "boost/format.hpp"

template<typename PTR> void CreateBranch(std::shared_ptr<top::TreeManager> tree, PTR addr, 
		    const char* basename, 
		    int index) {
  boost::format fmt1("%1%%2%");
  fmt1 % basename % index;
  tree->makeOutputVariable(*addr, fmt1.str().c_str());
}

void ttHML::Tau::BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index) {
  CreateBranch(tree, &pt,              "tau_pt_",               index);
  CreateBranch(tree, &eta,             "tau_eta_",              index);
  CreateBranch(tree, &phi,             "tau_phi_",              index);
  CreateBranch(tree, &charge,          "tau_charge_",           index);
  CreateBranch(tree, &e,               "tau_E_",                index);
  CreateBranch(tree, &RNNJetScore,     "tau_RNNJetScore_",      index);
  CreateBranch(tree, &JetRNNSigVeryLoose,  "tau_JetRNNSigVeryLoose_",   index);
  CreateBranch(tree, &JetRNNSigLoose,  "tau_JetRNNSigLoose_",   index);
  CreateBranch(tree, &JetRNNSigMedium, "tau_JetRNNSigMedium_",  index);
  CreateBranch(tree, &JetRNNSigTight,  "tau_JetRNNSigTight_",   index);
  CreateBranch(tree, &numTrack,        "tau_numTrack_",         index);
  CreateBranch(tree, &isHadronic,      "tau_isHadronic_",       index);
  CreateBranch(tree, &tagWeightBin,    "tau_tagWeightBin_",     index);
  CreateBranch(tree, &MV2c10,	       "tau_MV2c10_",		index);
  CreateBranch(tree, &DL1,	       "tau_DL1_",		index);
  CreateBranch(tree, &fromPV,          "tau_fromPV_",           index);
  CreateBranch(tree, &SFTight[0],      "tau_SFTight_",          index);
  CreateBranch(tree, &SFLoose[0],      "tau_SFLoose_",          index);

  CreateBranch(tree, &passEleOLR,      "tau_passEleOLR_",       index);
  CreateBranch(tree, &passEleBDT,      "tau_passEleBDT_",       index);
  CreateBranch(tree, &passMuonOLR,     "tau_passMuonOLR_",      index);
  CreateBranch(tree, &BDTEleScoreSigTrans, "tau_BDTEleScoreSigTrans_", index);
  CreateBranch(tree, &RNNJetScoreSigTrans, "tau_RNNJetScoreSigTrans_", index);

  CreateBranch(tree, &truthOrigin,     "tau_truthOrigin_",      index);
  CreateBranch(tree, &truthType,       "tau_truthType_",        index);
  CreateBranch(tree, &truthJetFlavour, "tau_truthJetFlavour_",  index);
  
  CreateBranch(tree, &truthPt,       "tau_truthPt_",        index);
  CreateBranch(tree, &truthPtVis,    "tau_truthPtVisible_", index);   
  CreateBranch(tree, &truthNumCharge,"tau_truthNumCharge_", index);


  //  CreateBranch(tree, &promptTauInput_TrackJetNTrack, "tau_promptTauInput_TrackJetNTrack_", index);
  CreateBranch(tree, &promptTauInput_JetF, "tau_promptTauInput_JetF_", index);
  CreateBranch(tree, &promptTauInput_DRlj, "tau_promptTauInput_DRlj_", index);
  CreateBranch(tree, &promptTauInput_LepJetPtFrac, "tau_promptTauInput_LepJetPtFrac_", index);
  CreateBranch(tree, &promptTauInput_SV1, "tau_promptTauInput_SV1_", index);
  CreateBranch(tree, &promptTauInput_MV2c10rnn, "tau_promptTauInput_MV2c10rnn_", index);
  CreateBranch(tree, &promptTauInput_ip2, "tau_promptTauInput_ip2_", index);
  CreateBranch(tree, &promptTauInput_ip3, "tau_promptTauInput_ip3_", index);
  CreateBranch(tree, &promptTauInput_rnnip, "tau_promptTauInput_rnnip_", index);
  CreateBranch(tree, &promptTauInput_MV2c10, "tau_promptTauInput_MV2c10_", index);

  CreateBranch(tree, &promptTauVeto, "tau_promptTauVeto_",      index);
  CreateBranch(tree, &promptTauIso,  "tau_promptTauIso_",		index);
}

