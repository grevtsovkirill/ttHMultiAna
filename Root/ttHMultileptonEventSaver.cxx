#include "ttHMultilepton/ttHMultileptonEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEventSelectionTools/TreeManager.h"

ttHMultileptonEventSaver::ttHMultileptonEventSaver() : m_HT(0), m_HThad(0), m_cent(0) {
}

ttHMultileptonEventSaver::~ttHMultileptonEventSaver(){}

void ttHMultileptonEventSaver::initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches) {

  EventSaverFlatNtuple::initialize(config, file, extraBranches);
  
  for (auto systematicTree : treeManagers()){
      systematicTree->makeOutputVariable(m_HT, "HT");
      systematicTree->makeOutputVariable(m_HThad, "HThad");
      systematicTree->makeOutputVariable(m_cent, "Cent");
    }
}

void ttHMultileptonEventSaver::saveEvent(const top::Event& event){
  
  float m_esum = 0;

  for(const auto* const elPtr : event.m_electrons)
    m_HT += elPtr->pt();
  for(const auto* const muPtr : event.m_muons)
    m_HT += muPtr->pt();
  for(const auto* const jPtr : event.m_jets){
    m_HT += jPtr->pt();
    m_HThad += jPtr->pt();
    m_esum += jPtr->e();
  }
  
  m_cent = m_HT/m_esum;
  
  EventSaverFlatNtuple::saveEvent(event);
}
