/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/SelectTruthParticles.h"
#include "TopEventSelectionTools/TreeManager.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "TopEvent/EventTools.h"
#include "TopEventSelectionTools/TreeManager.h"

//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

SelectTruthParticles::SelectTruthParticles(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  m_config(config)
{
/*   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }*/
  m_params=params;
  m_truthMatchAlgo  = new ttHMultilepton::TruthMatchAlgo();
  m_truthMatchAlgo->msg().setLevel( MSG::INFO ); 

}

SelectTruthParticles::~SelectTruthParticles(){
  delete  m_truthMatchAlgo;
}

bool SelectTruthParticles::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Event>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

// m_truthMatchAlgo  = new ttHMultilepton::TruthMatchAlgo();
//std::cout<<"test"<<std::endl;
// m_truthMatchAlgo->msg().setLevel( MSG::INFO );  
  if ( top::isSimulation(event) ) {
    top::check( m_truthMatchAlgo->executeTruthMatching(event), "Failed to execute executeTruthMatching(). Aborting");
  }
const std::vector<ttH::TruthPart> selected_truths =truthSelector.SelectTruth(event.m_truth);
event.m_info->auxdecor<std::vector<ttH::TruthPart> >("ttHMLEventVariablesT") = selected_truths;
  return true;

}

std::string SelectTruthParticles::name() const{
  return "SELECTTRUTHPARTICLES";
}


