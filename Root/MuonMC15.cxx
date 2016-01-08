#include "ttHMultilepton/MuonMC15.h"

namespace ttHMultilepton {

  MuonMC15::MuonMC15(const double ptcut, top::IsolationBase* isolation):
    top::MuonMC15(ptcut, isolation) {}
  
  bool MuonMC15::passTTVACuts(const xAOD::Muon& mu) const
  {
    return true;
  }
  
}
