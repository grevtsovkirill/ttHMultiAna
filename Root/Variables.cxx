
#include "ttHMultilepton/Variables.h"
#include "boost/format.hpp"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "TopEvent/EventTools.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "xAODJet/JetContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTruth/xAODTruthHelpers.h"

using boost::format;

namespace ttHML{

Variables::Variables()
{

}

Variables::~Variables(){
}

void Variables::BootstrapTree(std::shared_ptr<top::TreeManager> tree, bool doSFSystematics){
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
  tree->makeOutputVariable(minOSSFMll, "minOSSFMll");
  tree->makeOutputVariable(minOSMll, "minOSMll");
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
  // tree->makeOutputVariable(selected_jets, "selected_jets");
  // tree->makeOutputVariable(selected_jets_T, "selected_jets_T");

  // scale factors
  //  tree->makeOutputVariable(lepSFIDLoose, "lepSFIDLoose");
  //  tree->makeOutputVariable(lepSFIDTight, "lepSFIDTight");
  //  tree->makeOutputVariable(lepSFTrigLoose, "lepSFTrigLoose");
  //  tree->makeOutputVariable(lepSFTrigTight, "lepSFTrigTight");

  //nominal weights
  tree->makeOutputVariable(lepSFTrigLoose[0], "lepSFTrigLoose");
  tree->makeOutputVariable(lepSFTrigTight[0], "lepSFTrigTight");
  tree->makeOutputVariable(lepSFTrigTightLoose[0], "lepSFTrigTightLoose");
  tree->makeOutputVariable(lepSFTrigLooseTight[0], "lepSFTrigLooseTight");
  tree->makeOutputVariable(lepEffTrigLoose[0], "lepEffTrigLoose");
  tree->makeOutputVariable(lepEffTrigTight[0], "lepEffTrigTight");
  tree->makeOutputVariable(lepEffTrigTightLoose[0], "lepEffTrigTightLoose");
  tree->makeOutputVariable(lepEffTrigLooseTight[0], "lepEffTrigLooseTight");
  tree->makeOutputVariable(lepDataEffTrigLoose[0], "lepDataEffTrigLoose");
  tree->makeOutputVariable(lepDataEffTrigTight[0], "lepDataEffTrigTight");
  tree->makeOutputVariable(lepDataEffTrigTightLoose[0], "lepDataEffTrigTightLoose");
  tree->makeOutputVariable(lepDataEffTrigLooseTight[0], "lepDataEffTrigLooseTight");
  tree->makeOutputVariable(lepSFObjLoose [top::topSFSyst::nominal], "lepSFObjLoose");
  tree->makeOutputVariable(lepSFObjTight [top::topSFSyst::nominal], "lepSFObjTight");
  tree->makeOutputVariable(tauSFTight    [top::topSFSyst::nominal], "tauSFTight");
  tree->makeOutputVariable(tauSFLoose    [top::topSFSyst::nominal], "tauSFLoose");

  //additional loop for trig SFs uncertainties with multiTrigger tool
/*  if(doSFSystematics) {
    int nTrig = -1;
    for (const auto systvar : ntupler->m_lep_trigger_sf_names) {
      ++nTrig;
      if( systvar.second == "nominal" ) continue; //nominal is done outside loop
      std::string thisname = "_" + systvar.second;
      tree->makeOutputVariable(lepSFTrigLoose[nTrig], "lepSFTrigLoose" + thisname);
      tree->makeOutputVariable(lepSFTrigTight[nTrig], "lepSFTrigTight" + thisname);
      tree->makeOutputVariable(lepSFTrigTightLoose[nTrig], "lepSFTrigTightLoose" + thisname);
      tree->makeOutputVariable(lepSFTrigLooseTight[nTrig], "lepSFTrigLooseTight" + thisname);
      tree->makeOutputVariable(lepEffTrigLoose[nTrig], "lepEffTrigLoose" + thisname);
      tree->makeOutputVariable(lepEffTrigTight[nTrig], "lepEffTrigTight" + thisname);
      tree->makeOutputVariable(lepEffTrigTightLoose[nTrig], "lepEffTrigTightLoose" + thisname);
      tree->makeOutputVariable(lepEffTrigLooseTight[nTrig], "lepEffTrigLooseTight" + thisname);
      tree->makeOutputVariable(lepDataEffTrigLoose[nTrig], "lepDataEffTrigLoose" + thisname);
      tree->makeOutputVariable(lepDataEffTrigTight[nTrig], "lepDataEffTrigTight" + thisname);
      tree->makeOutputVariable(lepDataEffTrigTightLoose[nTrig], "lepDataEffTrigTightLoose" + thisname);
      tree->makeOutputVariable(lepDataEffTrigLooseTight[nTrig], "lepDataEffTrigLooseTight" + thisname);
    }
  }
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
      // if (dotrig && onelep_type>0) { //done above
      //    tree->makeOutputVariable(lepSFTrigLoose[systvar.first], "lepSFTrigLoose" + thisname);
      //    tree->makeOutputVariable(lepSFTrigTight[systvar.first], "lepSFTrigTight" + thisname);
      // }
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
  }// endif doSFSystematics */
}

void Variables::AssignOutput(ttHML::Variables* m_ttHEvent, std::shared_ptr<ttHML::Variables> tthevt){

    m_ttHEvent->onelep_type = tthevt->onelep_type;
    m_ttHEvent->dilep_type = tthevt->dilep_type;
    m_ttHEvent->trilep_type = tthevt->trilep_type;
    m_ttHEvent->quadlep_type = tthevt->quadlep_type;
    m_ttHEvent->total_leptons = tthevt->total_leptons;
    m_ttHEvent->total_charge = tthevt->total_charge;
    m_ttHEvent->isQMisIDEvent = tthevt->isQMisIDEvent;
    m_ttHEvent->isFakeEvent = tthevt->isFakeEvent;
    m_ttHEvent->isLepFromPhEvent = tthevt->isLepFromPhEvent;

 /*   format XXmn("%1%%2%%3%"), XXmno("%1%%2%%3%%4%"), XXmnop("%1%%2%%3%%4%%5%");
    for (size_t idx1 = 0; idx1 < LEPTON_ARR_SIZE-1; ++idx1) {
      for (size_t idx2 = idx1+1; idx2 < LEPTON_ARR_SIZE; ++idx2) {
        XXmn % "Mll" % idx1 % idx2;
        m_ttHEvent->Mll[idx1][idx2-1] = tthevt->Mll[idx1][idx2-1];
        XXmn % "Ptll" % idx1 % idx2;
        m_ttHEvent->Ptll[idx1][idx2-1] = tthevt->Ptll[idx1][idx2-1];
        XXmn % "DRll" % idx1 % idx2;
        m_ttHEvent->DRll[idx1][idx2-1] = tthevt->DRll[idx1][idx2-1];
        XXmn % "matchDLTll" % idx1 % idx2;
        m_ttHEvent->matchDLTll[idx1][idx2-1] = tthevt->matchDLTll[idx1][idx2-1];
        for (size_t idx3 = idx2+1; idx3 < LEPTON_ARR_SIZE; ++idx3) {
          XXmno % "Mlll" % idx1 % idx2 % idx3;
		  m_ttHEvent->Mlll[idx1][idx2-1][idx3-2] = tthevt->Mlll[idx1][idx2-1][idx3-2];          
          for (size_t idx4 = idx3+1; idx4 < LEPTON_ARR_SIZE; ++idx4) {
            XXmnop % "Mllll" % idx1 % idx2 % idx3 % idx4;
			m_ttHEvent->Mllll[idx1][idx2-1][idx3-2][idx4-3] = tthevt->Mllll[idx1][idx2-1][idx3-2][idx4-3];            
          }
        }
      }
    }
    m_ttHEvent->best_Z_Mll = tthevt->best_Z_Mll;
    m_ttHEvent->best_Z_other_MtLepMet = tthevt->best_Z_other_MtLepMet;
    m_ttHEvent->best_Z_other_Mll = tthevt->best_Z_other_Mll;
    m_ttHEvent->minOSSFMll = tthevt->minOSSFMll;
    m_ttHEvent->minOSMll = tthevt->minOSMll;
    //m_ttHEvent->Ptll01 = tthevt->Ptll01;
    //m_ttHEvent->DRll01 = tthevt->DRll01;
    m_ttHEvent->nJets_OR_T = tthevt->nJets_OR_T;
    m_ttHEvent->nJets_OR = tthevt->nJets_OR;
    m_ttHEvent->nTruthJets = tthevt->nTruthJets;
    m_ttHEvent->nTruthJets_OR = tthevt->nTruthJets_OR;
    m_ttHEvent->nJets_OR_T_MV2c20_60 = tthevt->nJets_OR_T_MV2c20_60;
    m_ttHEvent->nJets_OR_T_MV2c20_70 = tthevt->nJets_OR_T_MV2c20_70;
    m_ttHEvent->nJets_OR_T_MV2c20_77 = tthevt->nJets_OR_T_MV2c20_77;
    m_ttHEvent->nJets_OR_T_MV2c20_85 = tthevt->nJets_OR_T_MV2c20_85;
    m_ttHEvent->nJets_OR_MV2c20_85 = tthevt->nJets_OR_MV2c20_85;
    m_ttHEvent->nJets_OR_MV2c20_60 = tthevt->nJets_OR_MV2c20_60;
    m_ttHEvent->nJets_OR_MV2c20_77 = tthevt->nJets_OR_MV2c20_77;
    m_ttHEvent->nJets_OR_MV2c20_70 = tthevt->nJets_OR_MV2c20_70;
    m_ttHEvent->nJets_OR_T_MV2c10_60 = tthevt->nJets_OR_T_MV2c10_60;
    m_ttHEvent->nJets_OR_T_MV2c10_70 = tthevt->nJets_OR_T_MV2c10_70;
    m_ttHEvent->nJets_OR_T_MV2c10_77 = tthevt->nJets_OR_T_MV2c10_77;
    m_ttHEvent->nJets_OR_T_MV2c10_85 = tthevt->nJets_OR_T_MV2c10_85;
    m_ttHEvent->nJets_OR_MV2c10_85 = tthevt->nJets_OR_MV2c10_85;
    m_ttHEvent->nJets_OR_MV2c10_60 = tthevt->nJets_OR_MV2c10_60;
    m_ttHEvent->nJets_OR_MV2c10_77 = tthevt->nJets_OR_MV2c10_77;
    m_ttHEvent->nJets_OR_MV2c10_70 = tthevt->nJets_OR_MV2c10_70;
    m_ttHEvent->nTaus_OR_Pt25 = tthevt->nTaus_OR_Pt25;
    m_ttHEvent->isBlinded = tthevt->isBlinded;
    m_ttHEvent->HT = tthevt->HT;
    m_ttHEvent->HT_lep = tthevt->HT_lep;
    m_ttHEvent->HT_jets = tthevt->HT_jets;
    m_ttHEvent->lead_jetPt = tthevt->lead_jetPt;
    m_ttHEvent->lead_jetEta = tthevt->lead_jetEta;
    m_ttHEvent->lead_jetPhi = tthevt->lead_jetPhi;
    m_ttHEvent->lead_jetE = tthevt->lead_jetE;
    m_ttHEvent->sublead_jetPt = tthevt->sublead_jetPt;
    m_ttHEvent->sublead_jetEta = tthevt->sublead_jetEta;
    m_ttHEvent->sublead_jetPhi = tthevt->sublead_jetPhi;
    m_ttHEvent->sublead_jetE = tthevt->sublead_jetE;
    //m_ttHEvent->selected_jets = tthevt->selected_jets;
    //m_ttHEvent->selected_jets_T = tthevt->selected_jets_T;

    //nominal weights
    m_ttHEvent->lepSFTrigLoose[0] = tthevt->lepSFTrigLoose[0];
    m_ttHEvent->lepSFTrigTight[0] = tthevt->lepSFTrigTight[0];
    m_ttHEvent->lepSFTrigTightLoose[0] = tthevt->lepSFTrigTightLoose[0];
    m_ttHEvent->lepSFTrigLooseTight[0] = tthevt->lepSFTrigLooseTight[0];
    m_ttHEvent->lepEffTrigLoose[0] = tthevt->lepEffTrigLoose[0];
    m_ttHEvent->lepEffTrigTight[0] = tthevt->lepEffTrigTight[0];
    m_ttHEvent->lepEffTrigTightLoose[0] = tthevt->lepEffTrigTightLoose[0];
    m_ttHEvent->lepEffTrigLooseTight[0] = tthevt->lepEffTrigLooseTight[0];
    m_ttHEvent->lepDataEffTrigLoose[0] = tthevt->lepDataEffTrigLoose[0];
    m_ttHEvent->lepDataEffTrigTight[0] = tthevt->lepDataEffTrigTight[0];
    m_ttHEvent->lepDataEffTrigTightLoose[0] = tthevt->lepDataEffTrigTightLoose[0];
    m_ttHEvent->lepDataEffTrigLooseTight[0] = tthevt->lepDataEffTrigLooseTight[0];
    m_ttHEvent->lepSFObjLoose [top::topSFSyst::nominal] = tthevt->lepSFObjLoose [top::topSFSyst::nominal];
    m_ttHEvent->lepSFObjTight [top::topSFSyst::nominal] = tthevt->lepSFObjTight [top::topSFSyst::nominal];
    m_ttHEvent->tauSFTight    [top::topSFSyst::nominal] = tthevt->tauSFTight    [top::topSFSyst::nominal];
    m_ttHEvent->tauSFLoose    [top::topSFSyst::nominal] = tthevt->tauSFLoose    [top::topSFSyst::nominal];*/



}

//void Variables::clear(){
//}

}

