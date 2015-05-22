#include "ttHMultilepton/MLLSFWinSelector.h"


//namespace top {
//If the event number divided by two has no remainder then return true.
bool MLLSFWinSelector::apply(const top::Event& event) const {
  const xAOD::Electron* el1 = 0;
  const xAOD::Electron* el2 = 0;
  const xAOD::Muon* mu1 = 0;
  const xAOD::Muon* mu2 = 0;
  const xAOD::IParticle* lepton1 = 0;
  const xAOD::IParticle* lepton2 = 0;
  
  if (event.m_electrons.size() == 2 && event.m_muons.size() == 1) {
    // lepton0 = event.m_electrons[0];
    // lepton1 = event.m_electrons[1];
    el1 = event.m_electrons[0];
    el2 = event.m_electrons[1];

    if (el1->charge() * el2->charge() > 0) 
      exit(1);
    else {
      lepton1 = el1;
      lepton2 = el2;
    }
  } 
  else if (event.m_muons.size() == 2 && event.m_electrons.size() == 1) {
    mu1 = event.m_muons[0];
    mu2 = event.m_muons[1];
    if (mu1->charge() * mu2->charge() > 0)
      exit(1);
    else {
      lepton1 = mu1;
      lepton2 = mu2;
    }
  }
  else if (event.m_electrons.size() == 3){
    for (unsigned int i=0; i < event.m_electrons.size(); ++i) {
      for (unsigned int j=i+1; j < event.m_electrons.size(); ++j) {
	el1 = event.m_electrons[i];
	el2 = event.m_electrons[j];
	if (el1->charge() * el2->charge() < 0) {
	  lepton1 = el1;
	  lepton2 = el2;
	}
      }
    }
  }
  else if (event.m_muons.size() == 3){
    for (unsigned int i=0; i < event.m_muons.size(); ++i) {
      for (unsigned int j=i+1; j < event.m_muons.size(); ++j) {
	mu1 = event.m_muons[i];
	mu2 = event.m_muons[j];
	if (mu1->charge() * mu2->charge() < 0) {
	  lepton1 = mu1;
	  lepton2 = mu2;
	}	
      }
    }
  }
  else {
    std::cout << "need two charged leptons of the same flavour and opposite sign!" << std::endl;
    exit(1);
  }
  
  const double mll = top::invariantMass(*lepton1, *lepton2);
  std::cout << "mll is : " << mll << std::endl;
  return std::abs(mll - 91000) < 10000;

}

//For the cutflow and terminal output
std::string MLLSFWinSelector::name() const {
    return "MLLSFWIN";
}

//}
