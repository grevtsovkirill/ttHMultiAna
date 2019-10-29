/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/SelectJets.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODJet/JetContainer.h"
#include "TopEvent/EventTools.h"
#include "TH1.h"

//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

SelectJets::SelectJets(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
 // m_jetCleaningToolLooseBad("JetCleaningToolLooseBad"),
  m_config(config),
  m_isRemote(false)
{
  //top::check( m_jetCleaningToolLooseBad.retrieve() , "Failed to retrieve JetCleaningToolLooseBad" );
   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
     m_isRemote=true; 
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_jets="SelectedJets";
}

SelectJets::~SelectJets(){
  if(!m_isRemote)  delete m_asgHelper;
}

bool SelectJets::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");

  for (const auto jetItr : event.m_jets) {
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(1);
  //  if (!m_jetCleaningToolLooseBad->keep(*jetItr)) {
  //    continue;
  //  }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(2);
    if (jetItr->pt() < 25e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(3);
    if (fabs(jetItr->eta()) > 2.5) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(4);
    
    if( jetItr->auxdataConst<char>("passJVT")==0 ){ continue;}
    

    /*if (jetItr->pt() < 60e3  && fabs(jetItr->getAttribute<float>("DetectorEta")) < 2.4)
      continue;
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(5);
    if (jetItr->isAvailable<float>("AnalysisTop_JVT")) {
	  if(jetItr->auxdataConst<float>("AnalysisTop_JVT") < 0.59)
      continue;
    }*/
    

    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(6);
    tthevt->selected_jets->push_back(jetItr);
  }
  std::sort (tthevt->selected_jets->begin(), tthevt->selected_jets->end(), ttHMLAsgHelper::pt_sort());
  //std::string m_jets1;
  //m_jets1 = m_jets;
  //if(m_config->systematicName(event.m_hashValue)!="nominal"){
    //m_jets1 = m_jets + "_"+ m_config->systematicName(event.m_hashValue) ;
  //}
  std::string m_jets1 = m_jets + "_"+ m_config->systematicName(event.m_hashValue) ;
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_jets,m_jets1), "recording Selected_jets failed.");

  //std::string jetname = m_config->sgKeyJets();
  //std::string retjet="SelectedJets";
  //const xAOD::JetContainer* Jets = m_asgHelper->getJetContainer(jetname);
  //const xAOD::JetContainer* Jets = m_asgHelper->RetrieveJets(jetname);
  //m_asgHelper->getJetContainer(jetname);
  //tthevt->GetJetContainer(jetname);
  //const xAOD::JetContainer* Jets = m_asgHelper->RetrieveJets(m_jets);
  //tthevt->onelep_type=3;


/*
const xAOD::JetContainer *alljets = nullptr;
 top::check(evtStore()->retrieve (alljets, "Jets"));
auto selectedJets = std::make_unique<ConstDataVector<xAOD::JetContainer>> (SG::VIEW_ELEMENTS);
for (const auto jet : *alljets) {
    if (jet->pt() < 25e3) {
      continue;
    }
selectedJets.push_back(jet);
}
top::check(evtStore()->record( selectedJets.release(), "selectedJets"));
*/

  return true;

}

std::string SelectJets::name() const{
  return "SELECTJETS";
}



