/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "HowtoExtendAnalysisTop/SelectTaus.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODTau/TauJetContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"

SelectTaus::SelectTaus(std::string params,std::shared_ptr<top::TopConfig> config):
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
  m_taus="SelectedTaus";

}

SelectTaus::~SelectTaus(){

}

bool SelectTaus::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Event>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Event> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
  for (const auto tauItr : event.m_tauJets) {
    if (abs(tauItr->charge()) != 1) {
      continue;
    }
    if (!(tauItr->nTracks() == 1 || tauItr->nTracks() == 3)) {
      continue;
    }
    auto abseta = fabs(tauItr->eta());
    if (!(abseta < 1.37 || (1.52 < abseta && abseta < 2.5))) {
      continue;
    }
    if (!tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium)) {
      continue;
    }
    if (tauItr->pt() < 25e3) {
      continue;
    }
    if ( !( tauItr->auxdata<int>("passEleBDT") ) ) {
      continue;
    }
    tthevt->selected_taus->push_back(tauItr);
  }
  std::sort (tthevt->selected_taus->begin(), tthevt->selected_taus->end(), ttHMLAsgHelper::pt_sort());
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_taus,"Selected_taus"), "recording Selected_taus failed.");

 // std::string tauname = m_config->sgKeyTaus();
  //tthevt->GetTauContainer(tauname);
  //const xAOD::TauJetContainer* Taus = m_asgHelper->RetrieveTaus(m_taus);
 // tthevt->onelep_type=3;

  return true;

}

std::string SelectTaus::name() const{
  return "SELECTTAUS";
}



