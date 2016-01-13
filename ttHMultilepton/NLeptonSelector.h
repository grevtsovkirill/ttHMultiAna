#ifndef NLEPTONSELECTOR_H_
#define NLEPTONSELECTOR_H_

#include "TopEventSelectionTools/SignValueSelector.h"

/**
 * @brief To accept an event based on a check of electrons and muons.
 */
  class NLeptonSelector : public top::SignValueSelector {
public:
    /**
     * @brief Select events based on multiplicity, which should be an integer.
     */
    explicit NLeptonSelector(const std::string& params);

    /**
     * @brief The 'OR' of a check against electrons and muons.
     *
     * @return True to keep the event, false otherwise.
     */
    bool apply(const top::Event& event) const override;

    /*!
      * @brief The 'OR' of a check against electrons and muons.
     *
     * @return True to keep the event, false otherwise.
     */
    bool applyParticleLevel(const top::ParticleLevelEvent& event) const override;
};


#endif
