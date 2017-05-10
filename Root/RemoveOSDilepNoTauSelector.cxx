#include "ttHMultilepton/RemoveOSDilepNoTauSelector.h"

bool RemoveOSDilepNoTauSelector::apply(const top::Event& event) const {

  if (event.m_tauJets.size())
    return true;

  if (event.m_electrons.size() + event.m_muons.size() != 2)
    return true;

  int total_charge = 0;
  for (auto electron : event.m_electrons) {
    total_charge += electron->charge();
  }
  for (auto muon : event.m_muons) {
    total_charge += muon->charge();
  }
  if (total_charge)
    return true;

  return false;

}

//For the cutflow and terminal output
std::string RemoveOSDilepNoTauSelector::name() const {
  return "REMOVEOSDILEPNOTAU";
}
