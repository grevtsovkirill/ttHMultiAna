/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/SelectElectrons.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODEgamma/ElectronContainer.h"
#include "TopEvent/EventTools.h"
#include "TH1.h"

//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

SelectElectrons::SelectElectrons(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  m_config(config),
  m_isRemote(false)
{
   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
     m_isRemote=true;
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
  if(!m_isRemote)  delete m_asgHelper;  
}

bool SelectElectrons::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
  std::string elname = m_config->sgKeyElectrons();

  /*for (auto elItr : event.m_electrons) {
        if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
  nelec2++;
  }*/
 // xAOD::ElectronContainer* goodElectrons = new xAOD::ElectronContainer();
 // xAOD::AuxContainerBase* goodElectronsAux = new xAOD::AuxContainerBase();
 // goodElectrons->SG::setStore(goodElectronsAux);

  for (const auto elItr : event.m_electrons) {
    // Fill only for nominal tree
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(1);
    if (elItr->pt() < 10e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(2);
    auto abseta = fabs(elItr->caloCluster()->etaBE(2));
    if (!(abseta < 1.37 || (1.52 < abseta && abseta < 2.47))) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(3);
    if (!elItr->auxdataConst<int>("passLHLoose")) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(4);
    if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(5);
    if (fabs(elItr->auxdataConst<float>("d0sig")) > 10) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(6);
    if(!elItr->auxdecor<short>("Iso_FCLoose")){
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(7);
    tthevt->selected_electrons->push_back(elItr);
  }

  std::sort (tthevt->selected_electrons->begin(), tthevt->selected_electrons->end(), ttHMLAsgHelper::pt_sort());
 // m_asgHelper->RecordElectrons(tthevt->selected_electrons,m_electrons);
  //top::check(m_asgHelper->evtStore()->record(tthevt->selected_electrons,"Selected_Electrons"), "recording Selected_Electrons failed.");
  std::string m_electrons1;
  m_electrons1 = m_electrons;
  if(m_config->systematicName(event.m_hashValue)!="nominal"){
    m_electrons1 = m_electrons + "_"+ m_config->systematicName(event.m_hashValue) ;
  }

  top::check(m_asgHelper->evtStore()->record(tthevt->selected_electrons,m_electrons1), "recording Selected_Electrons failed.");

  return true;

}

std::string SelectElectrons::name() const{
  return "SELECTELECTRONS";
}



