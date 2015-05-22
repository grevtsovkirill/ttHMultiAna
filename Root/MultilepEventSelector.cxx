#include "ttHMultilepton/MultilepEventSelector.h"


bool MultilepEventSelector::apply(const top::Event& event) const {
  const xAOD::Electron* el1 = 0;
  const xAOD::Electron* el2 = 0;
  const xAOD::Muon* mu1 = 0;
  const xAOD::Muon* mu2 = 0;
  const xAOD::IParticle* lepton1 = 0;
  const xAOD::IParticle* lepton2 = 0;

  bool passed = false;
  for (const auto* const elPtr : event.m_electrons) {
    //std::cout << "Passes?" << elPtr->auxdataConst< unsigned int >("passPreORSelection") << std::endl;
    if (elPtr->auxdataConst< char >("passPreORSelection") != 0) {
      passed = true;
    }
  }
  return true;

  
}

//For the cutflow and terminal output
std::string MultilepEventSelector::name() const {
    return "TTHMULTILEP";
}

//}
