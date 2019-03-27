
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

void Variables::BootstrapTree(std::shared_ptr<top::TreeManager> tree,const ttHMultileptonLooseEventSaver *ntupler, bool doSFSystematics){
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
  tree->makeOutputVariable(Mlt00, "Mlt00");
  tree->makeOutputVariable(Mlt01, "Mlt01");
  tree->makeOutputVariable(Mlt10, "Mlt10");
  tree->makeOutputVariable(Mlt11, "Mlt11");
  tree->makeOutputVariable(Mtt01, "Mtt01");
  tree->makeOutputVariable(MTlmet, "MTlmet");
  //tree->makeOutputVariable(Ptll01, "Ptll01");
  //tree->makeOutputVariable(DRll01, "DRll01");
  tree->makeOutputVariable(nJets_OR_T, "nJets_OR_T");
  tree->makeOutputVariable(nJets_OR, "nJets_OR");
  tree->makeOutputVariable(nTruthJets,"nTruthJets");
  tree->makeOutputVariable(nTruthJets_OR,"nTruthJets_OR");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_60, "nJets_OR_T_MV2c10_60");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_70, "nJets_OR_T_MV2c10_70");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_77, "nJets_OR_T_MV2c10_77");
  tree->makeOutputVariable(nJets_OR_T_MV2c10_85, "nJets_OR_T_MV2c10_85");
  tree->makeOutputVariable(nJets_OR_MV2c10_85, "nJets_OR_MV2c10_85");
  tree->makeOutputVariable(nJets_OR_MV2c10_60, "nJets_OR_MV2c10_60");
  tree->makeOutputVariable(nJets_OR_MV2c10_77, "nJets_OR_MV2c10_77");
  tree->makeOutputVariable(nJets_OR_MV2c10_70, "nJets_OR_MV2c10_70");
  tree->makeOutputVariable(nJets_OR_T_DL1_60, "nJets_OR_T_DL1_60");
  tree->makeOutputVariable(nJets_OR_T_DL1_70, "nJets_OR_T_DL1_70");
  tree->makeOutputVariable(nJets_OR_T_DL1_77, "nJets_OR_T_DL1_77");
  tree->makeOutputVariable(nJets_OR_T_DL1_85, "nJets_OR_T_DL1_85");
  tree->makeOutputVariable(nJets_OR_DL1_85, "nJets_OR_DL1_85");
  tree->makeOutputVariable(nJets_OR_DL1_60, "nJets_OR_DL1_60");
  tree->makeOutputVariable(nJets_OR_DL1_77, "nJets_OR_DL1_77");
  tree->makeOutputVariable(nJets_OR_DL1_70, "nJets_OR_DL1_70");
  tree->makeOutputVariable(nTaus_OR_Pt25, "nTaus_OR_Pt25");
  tree->makeOutputVariable(nTaus_OR_Loose, "nTaus_OR_Loose");
  tree->makeOutputVariable(nTaus_OR_Medium, "nTaus_OR_Medium");
  tree->makeOutputVariable(nTaus_OR_Tight, "nTaus_OR_Tight");
  tree->makeOutputVariable(isBlinded, "isBlinded");
  tree->makeOutputVariable(HT, "HT");
  tree->makeOutputVariable(HT_lep, "HT_lep");
  tree->makeOutputVariable(HT_jets, "HT_jets");
  tree->makeOutputVariable(HT_alljets, "HT_alljets");
  tree->makeOutputVariable(Meff,"Meff");
  tree->makeOutputVariable(lead_jetPt,  "lead_jetPt");
  tree->makeOutputVariable(lead_jetEta, "lead_jetEta");
  tree->makeOutputVariable(lead_jetPhi, "lead_jetPhi");
  tree->makeOutputVariable(lead_jetE,"lead_jetE");
  tree->makeOutputVariable(sublead_jetPt,  "sublead_jetPt");
  tree->makeOutputVariable(sublead_jetEta, "sublead_jetEta");
  tree->makeOutputVariable(sublead_jetPhi, "sublead_jetPhi");
  tree->makeOutputVariable(sublead_jetE,"sublead_jetE");
  tree->makeOutputVariable(selected_jetsOR, "selected_jets");
  tree->makeOutputVariable(selected_jets_TOR, "selected_jets_T");
  tree->makeOutputVariable(selected_jetsOR_mv2c10_Ordrd,"selected_jets_mv2c10_Ordrd");
  tree->makeOutputVariable(selected_jets_TOR_mv2c10_Ordrd,"selected_jets_T_mv2c10_Ordrd");

  // scale factors
  //  tree->makeOutputVariable(lepSFIDLoose, "lepSFIDLoose");
  //  tree->makeOutputVariable(lepSFIDTight, "lepSFIDTight");
  //  tree->makeOutputVariable(lepSFTrigLoose, "lepSFTrigLoose");
  //  tree->makeOutputVariable(lepSFTrigTight, "lepSFTrigTight");
  tree->makeOutputVariable(lepSFIDLoose, "lepSFIDLoose");
  tree->makeOutputVariable(lepSFIDTight, "lepSFIDTight");
  tree->makeOutputVariable(lepSFIsoLoose, "lepSFIsoLoose");
  tree->makeOutputVariable(lepSFIsoTight, "lepSFIsoTight");
  tree->makeOutputVariable(lepSFReco, "lepSFReco");
  tree->makeOutputVariable(lepSFTTVA, "lepSFTTVA");



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
  if(doSFSystematics) {
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
    for (const auto systvar :ntupler-> m_lep_sf_names) {
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
    for ( auto systvar : m_tau_sf_names) {
      if( systvar.first == top::topSFSyst::nominal ) continue; //nominal is done outside loop
      std::string thisname = "_" + systvar.second;
      tree->makeOutputVariable(tauSFTight[systvar.first], "tauSFTight" + thisname);
      tree->makeOutputVariable(tauSFLoose[systvar.first], "tauSFLoose" + thisname);
    }
  }// endif doSFSystematics 
}

  void Variables::clearReco(){
    selected_jets->clear();
    selected_electrons->clear();
    selected_muons->clear();
    selected_taus->clear();
    selected_OR_jets->clear();
    selected_OR_electrons->clear();
    selected_OR_muons->clear();
    selected_OR_taus->clear();
//    clearDecorations();
//    m_reco=false;
  }
void Variables::Clear() { memset(this, 0, sizeof(Variables)); }

}

