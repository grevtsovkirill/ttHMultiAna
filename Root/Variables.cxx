#include "ttHMultilepton/Variables.h"
#include "boost/format.hpp"

using boost::format;

void ttHMultilepton::Variables::BootstrapTree(std::shared_ptr<top::TreeManager> tree) {
  tree->makeOutputVariable(onelep_type,   "onelep_type");
  tree->makeOutputVariable(dilep_type,    "dilep_type");
  tree->makeOutputVariable(trilep_type,   "trilep_type");
  tree->makeOutputVariable(quadlep_type,  "quadlep_type");
  tree->makeOutputVariable(total_charge,  "total_charge");
  tree->makeOutputVariable(total_leptons, "total_leptons");
  //tree->makeOutputVariable(Mll01, "Mll01");
  format XXmn("%1%%2%%3%");
  for (size_t idx1 = 0; idx1 < LEPTON_ARR_SIZE-1; ++idx1) {
    for (size_t idx2 = idx1+1; idx2 < LEPTON_ARR_SIZE; ++idx2) {
      XXmn % "Mll" % idx1 % idx2;
      tree->makeOutputVariable(Mll[idx1][idx2-1], XXmn.str().c_str());
      XXmn % "Ptll" % idx1 % idx2;
      tree->makeOutputVariable(Ptll[idx1][idx2-1], XXmn.str().c_str());
      XXmn % "DRll" % idx1 % idx2;
      tree->makeOutputVariable(DRll[idx1][idx2-1], XXmn.str().c_str());
    }
  }
  //tree->makeOutputVariable(Ptll01, "Ptll01");
  //tree->makeOutputVariable(DRll01, "DRll01");
  tree->makeOutputVariable(nJets_OR_T, "nJets_OR_T");
  tree->makeOutputVariable(nJets_OR_T_MV2c20_70, "nJets_OR_T_MV2c20_70");
  tree->makeOutputVariable(nJets_OR_T_MV2c20_77, "nJets_OR_T_MV2c20_77");
  tree->makeOutputVariable(nTaus_OR_Pt25, "nTaus_OR_Pt25");
  tree->makeOutputVariable(isBlinded, "isBlinded");
  tree->makeOutputVariable(HT, "HT");
  tree->makeOutputVariable(HT_lep, "HT_lep");
  tree->makeOutputVariable(HT_jets, "HT_jets");
  tree->makeOutputVariable(lead_jetPt,  "lead_jetPt");
  tree->makeOutputVariable(lead_jetEta, "lead_jetEta");
  tree->makeOutputVariable(lead_jetPhi, "lead_jetPhi");
  tree->makeOutputVariable(sublead_jetPt,  "sublead_jetPt");
  tree->makeOutputVariable(sublead_jetEta, "sublead_jetEta");
  tree->makeOutputVariable(sublead_jetPhi, "sublead_jetPhi");

}
