
#include "HowtoExtendAnalysisTop/EvenEventNumberSelector.h"
#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>


#include "TopEvent/EventTools.h"


EvenEventNumberSelector::EvenEventNumberSelector(std::string params,std::shared_ptr<top::TopConfig> config):
  m_config(config)
 {
   m_params=params;
}

EvenEventNumberSelector::~EvenEventNumberSelector(){

}

bool EvenEventNumberSelector::apply(const top::Event & event) const{

  std::shared_ptr<ttHML::Event> tthevt;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
    tthevt = std::make_shared<ttHML::Event>();
    event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables") = tthevt;

    tthevt->m_info = std::make_shared<ttHML::EventData>();
    tthevt->m_info->eventNumber=event.m_info->eventNumber();
    if(m_config->isMC()){
      tthevt->m_info->mcChannelNumber=event.m_info->mcChannelNumber();
    }
    else{
      tthevt->m_info->mcChannelNumber=0;
    }
    tthevt->m_info->runNumber=event.m_info->runNumber();
    tthevt->m_info->isData= !m_config->isMC();

  }
  else{
    tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
  }

  /// nothing to be done for now here  
  /// will be cleaned in EventSaver

  return true;

}



bool EvenEventNumberSelector::applyParticleLevel(const top::ParticleLevelEvent & plEvent) const{

  std::shared_ptr<ttHML::Event> tthevt;

  if(!plEvent.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
    tthevt = std::make_shared<ttHML::Event>();
    plEvent.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables") = tthevt;

    tthevt->m_info = std::make_shared<ttHML::EventData>();
    tthevt->m_info->eventNumber=plEvent.m_info->eventNumber();
    tthevt->m_info->mcChannelNumber=plEvent.m_info->mcChannelNumber();
    tthevt->m_info->runNumber=plEvent.m_info->runNumber();
    tthevt->m_info->isData= !m_config->isMC();

  }
  else{
    tthevt = plEvent.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
  }

  /// nothing to be done for now here  
  /// will be cleaned in EventSaver

  return true;

}



std::string EvenEventNumberSelector::name() const{
  return "EVEN";
}


