#ifndef TTHML_ELECTRONLIKELIHOODMC15_H_
#define TTHML_ELECTRONLIKELIHOODMC15_H_

#include "TopObjectSelectionTools/ElectronLikelihoodMC15.h"

namespace ttHMultilepton {

/**
 * @brief overrides only passTTVACuts
 */
  class ElectronLikelihoodMC15 : public top::ElectronLikelihoodMC15 {
public:

    ElectronLikelihoodMC15(const double ptcut,
			   const bool vetoCrack,
			   const std::string& operatingPoint,
			   const std::string& operatingPointLoose,
			   top::StandardIsolation* isolation);
    
    bool passTTVACuts(const xAOD::Electron& el) const override;

};

}

#endif
