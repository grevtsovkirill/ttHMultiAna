#include "ttHMultilepton/Tau.h"
#include "boost/format.hpp"

template<typename PTR> void CreateBranch(std::shared_ptr<top::TreeManager> tree, PTR addr, 
		    const char* basename, 
		    int index) {
  boost::format fmt1("%1%%2%");
  fmt1 % basename % index;
  tree->makeOutputVariable(*addr, fmt1.str().c_str());
}

void ttHMultilepton::Tau::BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index) {
  CreateBranch(tree, &pt,              "tau_pt_",               index);
  CreateBranch(tree, &eta,             "tau_eta_",              index);
  CreateBranch(tree, &phi,             "tau_phi_",              index);
  CreateBranch(tree, &charge,          "tau_charge_",           index);
  CreateBranch(tree, &e,               "tau_E_",                index);
  CreateBranch(tree, &BDTJetScore,     "tau_BDTJetScore_",      index);
  CreateBranch(tree, &JetBDTSigLoose,  "tau_JetBDTSigLoose_",   index);
  CreateBranch(tree, &JetBDTSigMedium, "tau_JetBDTSigMedium_",  index);
  CreateBranch(tree, &JetBDTSigTight,  "tau_JetBDTSigTight_",   index);
  CreateBranch(tree, &numTrack,        "tau_numTrack_",         index);
  CreateBranch(tree, &isHadronic,      "tau_isHadronic_",       index);
  CreateBranch(tree, &SFTight[0],      "tau_SFTight_",          index);
  CreateBranch(tree, &SFLoose[0],      "tau_SFLoose_",          index);
}
