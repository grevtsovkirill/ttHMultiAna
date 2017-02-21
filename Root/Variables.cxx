#include "ttHMultilepton/Variables.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "boost/format.hpp"

using boost::format;

void ttHMultilepton::Variables::BootstrapTree(std::shared_ptr<top::TreeManager> tree, const ttHMultileptonLooseEventSaver* ntupler, bool doSFSystematics) {
  tree->makeOutputVariable(onelep_type,   "onelep_type");
  tree->makeOutputVariable(dilep_type,    "dilep_type");
  tree->makeOutputVariable(trilep_type,   "trilep_type");
  tree->makeOutputVariable(quadlep_type,  "quadlep_type");
  tree->makeOutputVariable(total_charge,  "total_charge");
  tree->makeOutputVariable(total_leptons, "total_leptons");
  tree->makeOutputVariable(isQMisIDEvent, "isQMisIDEvent");
  tree->makeOutputVariable(isFakeEvent,   "isFakeEvent");
  tree->makeOutputVariable(isLepFromPhEvent, "isLepFromPhEvent");

  //tree->makeOutputVariable(Mll01, "Mll01");
  format XXmn("%1%%2%%3%"), XXmno("%1%%2%%3%%4%"), XXmnop("%1%%2%%3%%4%%5%");
  for (size_t idx1 = 0; idx1 < LEPTON_ARR_SIZE-1; ++idx1) {
    for (size_t idx2 = idx1+1; idx2 < LEPTON_ARR_SIZE; ++idx2) {
      XXmn % "Mll" % idx1 % idx2;
      tree->makeOutputVariable(Mll[idx1][idx2-1], XXmn.str().c_str());
      XXmn % "Ptll" % idx1 % idx2;
      tree->makeOutputVariable(Ptll[idx1][idx2-1], XXmn.str().c_str());
      XXmn % "DRll" % idx1 % idx2;
      tree->makeOutputVariable(DRll[idx1][idx2-1], XXmn.str().c_str());
      XXmn % "matchDLTll" % idx1 % idx2;
      tree->makeOutputVariable(matchDLTll[idx1][idx2-1], XXmn.str().c_str());
      for (size_t idx3 = idx2+1; idx3 < LEPTON_ARR_SIZE; ++idx3) {
	XXmno % "Mlll" % idx1 % idx2 % idx3;
	tree->makeOutputVariable(Mlll[idx1][idx2-1][idx3-2], XXmno.str().c_str());
	for (size_t idx4 = idx3+1; idx4 < LEPTON_ARR_SIZE; ++idx4) {
	  XXmnop % "Mllll" % idx1 % idx2 % idx3 % idx4;
	  tree->makeOutputVariable(Mllll[idx1][idx2-1][idx3-2][idx4-3], XXmnop.str().c_str());
	}
      }
    }
  }
  tree->makeOutputVariable(best_Z_Mll, "best_Z_Mll");
  tree->makeOutputVariable(best_Z_other_MtLepMet, "best_Z_other_MtLepMet");
  tree->makeOutputVariable(best_Z_other_Mll, "best_Z_other_Mll");
  //tree->makeOutputVariable(Ptll01, "Ptll01");
  //tree->makeOutputVariable(DRll01, "DRll01");
  tree->makeOutputVariable(nJets_OR_T, "nJets_OR_T");
  tree->makeOutputVariable(nJets_OR, "nJets_OR");
  tree->makeOutputVariable(nTruthJets,"nTruthJets");
  tree->makeOutputVariable(nTruthJets_OR,"nTruthJets_OR");
  tree->makeOutputVariable(nJets_OR_T_MV2c20_60, "nJets_OR_T_MV2c20_60");
  tree->makeOutputVariable(nJets_OR_T_MV2c20_70, "nJets_OR_T_MV2c20_70");
  tree->makeOutputVariable(nJets_OR_T_MV2c20_77, "nJets_OR_T_MV2c20_77");
  tree->makeOutputVariable(nJets_OR_T_MV2c20_85, "nJets_OR_T_MV2c20_85");
  tree->makeOutputVariable(nJets_OR_MV2c20_85, "nJets_OR_MV2c20_85");
  tree->makeOutputVariable(nJets_OR_MV2c20_60, "nJets_OR_MV2c20_60");
  tree->makeOutputVariable(nJets_OR_MV2c20_77, "nJets_OR_MV2c20_77");
  tree->makeOutputVariable(nJets_OR_MV2c20_70, "nJets_OR_MV2c20_70");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_60, "nJets_OR_T_MV2c10_60");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_70, "nJets_OR_T_MV2c10_70");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_77, "nJets_OR_T_MV2c10_77");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_85, "nJets_OR_T_MV2c10_85");
  tree->makeOutputVariable(nJets_OR_MV2c10_85, "nJets_OR_MV2c10_85");
  tree->makeOutputVariable(nJets_OR_MV2c10_60, "nJets_OR_MV2c10_60");
  tree->makeOutputVariable(nJets_OR_MV2c10_77, "nJets_OR_MV2c10_77");
  tree->makeOutputVariable(nJets_OR_MV2c10_70, "nJets_OR_MV2c10_70");
  tree->makeOutputVariable(nTaus_OR_Pt25, "nTaus_OR_Pt25");
  tree->makeOutputVariable(isBlinded, "isBlinded");
  tree->makeOutputVariable(HT, "HT");
  tree->makeOutputVariable(HT_lep, "HT_lep");
  tree->makeOutputVariable(HT_jets, "HT_jets");
  tree->makeOutputVariable(lead_jetPt,  "lead_jetPt");
  tree->makeOutputVariable(lead_jetEta, "lead_jetEta");
  tree->makeOutputVariable(lead_jetPhi, "lead_jetPhi");
  tree->makeOutputVariable(lead_jetE,"lead_jetE");
  tree->makeOutputVariable(sublead_jetPt,  "sublead_jetPt");
  tree->makeOutputVariable(sublead_jetEta, "sublead_jetEta");
  tree->makeOutputVariable(sublead_jetPhi, "sublead_jetPhi");
  tree->makeOutputVariable(sublead_jetE,"sublead_jetE");
  tree->makeOutputVariable(selected_jets, "selected_jets");
  tree->makeOutputVariable(selected_jets_T, "selected_jets_T");
  // scale factors
  //  tree->makeOutputVariable(lepSFIDLoose, "lepSFIDLoose");
  //  tree->makeOutputVariable(lepSFIDTight, "lepSFIDTight");
  //  tree->makeOutputVariable(lepSFTrigLoose, "lepSFTrigLoose");
  //  tree->makeOutputVariable(lepSFTrigTight, "lepSFTrigTight");

  //nominal weights
  tree->makeOutputVariable(lepSFTrigLoose[top::topSFSyst::nominal], "lepSFTrigLoose");
  tree->makeOutputVariable(lepSFTrigTight[top::topSFSyst::nominal], "lepSFTrigTight");
  tree->makeOutputVariable(lepSFObjLoose [top::topSFSyst::nominal], "lepSFObjLoose");
  tree->makeOutputVariable(lepSFObjTight [top::topSFSyst::nominal], "lepSFObjTight");
  tree->makeOutputVariable(tauSFTight    [top::topSFSyst::nominal], "tauSFTight");
  tree->makeOutputVariable(tauSFLoose    [top::topSFSyst::nominal], "tauSFLoose");

  if(doSFSystematics) {
    for (const auto systvar : ntupler->m_lep_sf_names) {
      if( systvar.first == top::topSFSyst::nominal ) continue; //nominal is done outside loop
      std::string thisname = "_" + systvar.second;
      bool dotrig = false;
      bool doobj = false;

      if (
	  (top::topSFSyst::EL_SF_Trigger_UP <= systvar.first &&
	   systvar.first <= top::topSFSyst::EL_SF_Trigger_DOWN)
	  ||
	  (top::topSFSyst::MU_SF_Trigger_UP <= systvar.first &&
	   systvar.first <= top::topSFSyst::MU_SF_Trigger_SYST_DOWN)
	  ) {
	if (!(top::topSFSyst::MU_SF_Trigger_UP <= systvar.first &&
	      systvar.first <= top::topSFSyst::MU_SF_Trigger_DOWN)) {
	  dotrig = true;
	}
      } else {
	doobj = true;
      }
      if (dotrig) {
	tree->makeOutputVariable(lepSFTrigLoose[systvar.first], "lepSFTrigLoose" + thisname);
	tree->makeOutputVariable(lepSFTrigTight[systvar.first], "lepSFTrigTight" + thisname);
      }
      if (doobj) {
	tree->makeOutputVariable(lepSFObjLoose[systvar.first], "lepSFObjLoose" + thisname);
	tree->makeOutputVariable(lepSFObjTight[systvar.first], "lepSFObjTight" + thisname);
      }
    }
    for ( auto systvar : ntupler->m_tau_sf_names) {
      if( systvar.first == top::topSFSyst::nominal ) continue; //nominal is done outside loop
      std::string thisname = "_" + systvar.second;
      tree->makeOutputVariable(tauSFTight[systvar.first], "tauSFTight" + thisname);
      tree->makeOutputVariable(tauSFLoose[systvar.first], "tauSFLoose" + thisname);
    }

  }// endif doSFSystematics
}
