#include "HowtoExtendAnalysisTop/Tau.h"
#include "boost/format.hpp"

template<typename PTR> void CreateBranch(std::shared_ptr<top::TreeManager> tree, PTR addr, 
		    const char* basename, 
		    int index) {
  boost::format fmt1("%1%%2%");
  fmt1 % basename % index;
  tree->makeOutputVariable(*addr, fmt1.str().c_str());
}

void Event::Tau::BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index) {
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
  CreateBranch(tree, &tagWeightBin,    "tau_tagWeightBin_",     index);
  CreateBranch(tree, &fromPV,          "tau_fromPV_",           index);
  CreateBranch(tree, &SFTight[0],      "tau_SFTight_",          index);
  CreateBranch(tree, &SFLoose[0],      "tau_SFLoose_",          index);

  CreateBranch(tree, &passEleOLR,      "tau_passEleOLR_",       index);
  CreateBranch(tree, &passEleBDT,      "tau_passEleBDT_",       index);
  CreateBranch(tree, &passMuonOLR,     "tau_passMuonOLR_",      index);

  CreateBranch(tree, &truthOrigin,     "tau_truthOrigin_",      index);
  CreateBranch(tree, &truthType,       "tau_truthType_",        index);
  CreateBranch(tree, &truthJetFlavour, "tau_truthJetFlavour_",  index);
}

