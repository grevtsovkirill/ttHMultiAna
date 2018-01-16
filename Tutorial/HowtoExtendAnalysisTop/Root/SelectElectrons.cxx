/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "HowtoExtendAnalysisTop/SelectElectrons.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODEgamma/ElectronContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"

SelectElectrons::SelectElectrons(std::string params,std::shared_ptr<top::TopConfig> config):
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
  m_electrons="SelectedElectrons";
  nelec2=0;
}

SelectElectrons::~SelectElectrons(){

}

bool SelectElectrons::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Event>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Event> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
  std::string elname = m_config->sgKeyElectrons();

  for (auto elItr : event.m_electrons) {
        if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
  nelec2++;
  }

  //m_asgHelper->getElectronContainer(elname);
  //tthevt->GetElectronContainer(elname);
  //const xAOD::ElectronContainer* Electrons = m_asgHelper->RetrieveElectrons(m_electrons);
 // tthevt->onelep_type=3;
std::cout<<"nelecafter= " <<nelec2<<std::endl;
  return true;

}

std::string SelectElectrons::name() const{
  return "SELECTELECTRONS";
}



