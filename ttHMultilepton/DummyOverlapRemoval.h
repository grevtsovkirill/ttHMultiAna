// $Id$
#ifndef DUMMYOVERLAPREMOVAL_H
#define DUMMYOVERLAPREMOVAL_H

// system include(s):
#include <memory>
#include <vector>

#include "TopObjectSelectionTools/OverlapRemovalBase.h"

  /**
   * @brief The "standard" overlap removal for the top group
   */
  class DummyOverlapRemoval : public top::OverlapRemovalBase {
  public:
    ///Doesn't do anything
    DummyOverlapRemoval();

    ///Doesn't do anything
    virtual ~DummyOverlapRemoval();

    /**
     * @brief Perform our "standard" overlap removal.
     *
     * This runs for every event.
     *
     * The overlap removal consists of:
     * - (1) remove muon within dR < 0.4 of any jet
     * - (2) remove single jet closest to an electron (within dR < 0.2)
     * - (3) remove electron with dR < 0.4 of jet
     *
     * @param el All the electrons (even bad ones).  Good ones are decorated
     * with passPreORSelection = 1.
     * @param mu All the muons in the event
     * @param jet All the jets in the event
     * @param ljet All the large-R jets in the event
     * @param OUT_el The indices of the electrons to keep (e.g. the 0th, 2nd)
     * @param OUT_mu The indices of the muons to keep
     * @param OUT_jet The indices of the jets to keep
     * @param OUT_ljet The indices of the large-R jets to keep
     */
    virtual void overlapremoval(const xAOD::PhotonContainer*   photon  ,
				const xAOD::ElectronContainer* el  ,
				const xAOD::MuonContainer*     mu  ,
				const xAOD::TauJetContainer*   tau ,
				const xAOD::JetContainer*      jet ,
				const xAOD::JetContainer*      ljet ,
				std::vector<unsigned int>& goodPhotons,
				std::vector<unsigned int>& goodElectrons,
				std::vector<unsigned int>& goodMuons,
				std::vector<unsigned int>& goodTaus,
				std::vector<unsigned int>& goodJets,
				std::vector<unsigned int>& goodLargeRJets,
				const bool isLooseEvent );

    ///Print something useful to the screen
    virtual void print(std::ostream&) const;
  };

#endif  
