/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/SelectMuons.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODMuon/MuonContainer.h"
#include "TopEvent/EventTools.h"
#include "TH1.h"

//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

SelectMuons::SelectMuons(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  muonSelection("MuonSelection"),
  m_config(config)
{
  top::check( muonSelection.setProperty( "MaxEta", (double)m_config->muonEtacut() ), "muonSelection tool could not set max eta");
  top::check( muonSelection.initialize(),"muonSelection tool fails to initialize");

   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_Muons="SelectedMuons";
}

SelectMuons::~SelectMuons(){

}

bool SelectMuons::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");

  for (const auto muItr : event.m_muons) {
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(1);
    auto abseta = fabs(muItr->eta());
    if (!(abseta < 2.5 && muonSelection.getQuality(*muItr) <= xAOD::Muon::Loose && muonSelection.passedIDCuts(*muItr))) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(2);
    if (muItr->pt() < 10e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(3);
    if (fabs(muItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(4);
    if (fabs(muItr->auxdataConst<float>("d0sig")) > 10) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(5);
    //old iso cut, maybe no longer necessary?
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(6);
    tthevt-> selected_muons->push_back(muItr);
  }
  std::sort (tthevt->selected_muons->begin(), tthevt->selected_muons->end(), ttHMLAsgHelper::pt_sort());

  std::string m_Muons1;
  m_Muons1 = m_Muons;
  if(m_config->systematicName(event.m_hashValue)!="nominal"){
    m_Muons1 = m_Muons + "_"+ m_config->systematicName(event.m_hashValue) ;
  }

  top::check(m_asgHelper->evtStore()->record(tthevt->selected_muons,m_Muons1), "recording Selected_muons failed.");

  //std::string elname = m_config->sgKeyMuons();
  //m_asgHelper->getMuonContainer(m_config->sgKeyMuons());
  //const xAOD::MuonContainer* Muons = m_asgHelper->RetrieveMuons(m_Muons);
 // tthevt->onelep_type=3;

  return true;

}

std::string SelectMuons::name() const{
  return "SELECTMUONS";
}



