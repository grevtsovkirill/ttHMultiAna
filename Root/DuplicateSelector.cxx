#include "ttHMultilepton/DuplicateSelector.h"

#include "TopEvent/EventTools.h"

// Systematic include(s):
#include "PATInterfaces/SystematicSet.h"

DuplicateSelector::DuplicateSelector() : m_nominalHashValue(0) {
  CP::SystematicSet nominal; 
  m_nominalHashValue = nominal.hash();
}

bool DuplicateSelector::apply(const top::Event& event) const {
    
  if (event.m_hashValue != m_nominalHashValue || event.m_isLoose)
    return true;
  
  int runNumber = event.m_info->eventNumber();
  int eventNumber = event.m_info->runNumber();
  std::pair<int,int> runEvent = std::make_pair(runNumber,eventNumber);
  if( m_processedEvents.insert(runEvent).second == false ){
    // event is duplicate
    std::cout<<"Ignoring duplicate event: "<<eventNumber<<" run: "<<runNumber<<std::cout;
    return false;
  }
  
  
  return true;
}

std::string DuplicateSelector::name() const {
    return "DUPLICATEVETO";
}
