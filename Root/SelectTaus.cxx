/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/SelectTaus.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODTau/TauJetContainer.h"
#include "TopEvent/EventTools.h"
#include "TH1.h"

//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

SelectTaus::SelectTaus(std::string params,std::shared_ptr<top::TopConfig> config):
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
  m_taus="SelectedTaus";
  //m_evtSaver = new ttHMultileptonLooseEventSaver();
}

SelectTaus::~SelectTaus(){
  if(!m_isRemote)  delete m_asgHelper;    
}

bool SelectTaus::apply(const top::Event & event) const{
  
  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
  
  for (const auto tauItr : event.m_tauJets) {
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(1);
    if (abs(tauItr->charge()) != 1) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(2);
    if (!(tauItr->nTracks() == 1 || tauItr->nTracks() == 3)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(3);
    auto abseta = fabs(tauItr->eta());
    if (!(abseta < 1.37 || (1.52 < abseta && abseta < 2.5))) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(4);
    if (!tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetRNNSigLoose)) {
    //    if(!(tauItr->discriminant(xAOD::TauJetParameters::TauID::RNNJetScoreSigTrans)>0.005)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(5);
    if (tauItr->pt() < 25e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(6);
    if ( !( tauItr->auxdata<int>("passEleBDT") ) ) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(7);
    tthevt->selected_taus->push_back(tauItr);
  }
  
  std::sort (tthevt->selected_taus->begin(), tthevt->selected_taus->end(), ttHMLAsgHelper::pt_sort());

  std::string m_taus1;
  m_taus1 = m_taus;
  if(m_config->systematicName(event.m_hashValue)!="nominal"){
    m_taus1 = m_taus + "_"+ m_config->systematicName(event.m_hashValue) ;
  }
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_taus,m_taus1), "recording Selected_taus failed.");

 // std::string tauname = m_config->sgKeyTaus();
  //tthevt->GetTauContainer(tauname);
  //const xAOD::TauJetContainer* Taus = m_asgHelper->RetrieveTaus(m_taus);
 // tthevt->onelep_type=3;

  return true;

}

std::string SelectTaus::name() const{
  return "SELECTTAUS";
}



