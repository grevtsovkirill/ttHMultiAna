/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "HowtoExtendAnalysisTop/SelectJets.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODJet/JetContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"

SelectJets::SelectJets(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  m_config(config)
{
   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_jets="SelectedJets";

}

SelectJets::~SelectJets(){

}

bool SelectJets::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Event>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Event> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
  std::string jetname = m_config->sgKeyJets();
  const xAOD::JetContainer* Jets = m_asgHelper->RetrieveJets("AllJets");
  tthevt->onelep_type=3;

  ConstDataVector<xAOD::JetContainer> * selJets = new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
  for( const auto jetItr : *Jets){
	if(jetItr->pt() < 25e3){continue;}	
	if(fabs(jetItr->eta()) > 2.5){ continue;}
	if (jetItr->pt() < 60e3 && fabs(jetItr->getAttribute<float>("DetectorEta")) < 2.4) {continue;}
	if (jetItr->isAvailable<float>("AnalysisTop_JVT")) {if(jetItr->auxdataConst<float>("AnalysisTop_JVT") < 0.59) continue;}	
 	selJets->push_back(jetItr);
  }
  std::cout << "SkimmedJetSize: " << selJets->size() << std::endl;
  m_asgHelper->saveJetContainer( selJets,m_jets);  

  const xAOD::JetContainer* Test_Jets = m_asgHelper->RetrieveJets(m_jets);
 std::cout << "TestJets Size: " << Test_Jets->size() << std::endl;

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



