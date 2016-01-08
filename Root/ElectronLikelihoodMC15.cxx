#include "ttHMultilepton/ElectronLikelihoodMC15.h"

namespace ttHMultilepton {

  ElectronLikelihoodMC15::ElectronLikelihoodMC15(const bool isPrimaryxAOD,
						 const double ptcut,
						 const bool vetoCrack,
						 const std::string& operatingPoint,
						 const std::string& operatingPointLoose,
						 top::IsolationBase* isolation) :
    top::ElectronLikelihoodMC15(isPrimaryxAOD,
				ptcut,
				vetoCrack,
				operatingPoint,
				operatingPointLoose,
				isolation) {}
  
  bool ElectronLikelihoodMC15::passTTVACuts(const xAOD::Electron& el) const
  {
    return true;
  }
  
}
