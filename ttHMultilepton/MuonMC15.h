#ifndef TTHML_MUONMC15_H_
#define TTHML_MUONMC15_H_

#include "TopObjectSelectionTools/MuonMC15.h"

namespace ttHMultilepton {

/**
 * @brief overrides only passTTVACuts
 */
  class MuonMC15 : public top::MuonMC15 {
public:

    MuonMC15(const double ptcut, top::IsolationBase* isolation);
    
    bool passTTVACuts(const xAOD::Muon& mu) const override;

};

}

#endif
