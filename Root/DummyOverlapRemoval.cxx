// $Id$
#include "ttHMultilepton/DummyOverlapRemoval.h"
#include "TopEvent/EventTools.h"

#include <list>

  DummyOverlapRemoval::DummyOverlapRemoval() {
  }

  DummyOverlapRemoval::~DummyOverlapRemoval() {
  }

void DummyOverlapRemoval::overlapremoval(const xAOD::PhotonContainer* /* ph */,
					 const xAOD::ElectronContainer* el,
					 const xAOD::MuonContainer* mu,
					 const xAOD::TauJetContainer* tau,
					 const xAOD::JetContainer* jet,
					 const xAOD::JetContainer* ljet,
					 std::vector<unsigned int>& goodPhotons,
					 std::vector<unsigned int>& goodElectrons,
					 std::vector<unsigned int>& goodMuons,
					 std::vector<unsigned int>& goodTaus,
					 std::vector<unsigned int>& goodJets,
					 std::vector<unsigned int>& goodLargeRJets,
					 const bool isLoose )
  {
    std::string passTopCuts("passPreORSelection");
  
    // Work internally with std::list
    // What passed the pre-overlap removal selection?
    std::vector<unsigned int> IN_el,IN_mu,IN_jet,IN_ljet,IN_tau;
    std::list<unsigned int> l_el,l_mu,l_jet,l_ljet,l_tau;
    unsigned int index_el(0),index_mu(0),index_jet(0),index_ljet(0),index_tau(0);

    if (el) {
      for( auto x : *el ){
	if( x->auxdataConst< char >(passTopCuts) == 1 ){
	  IN_el.push_back(index_el);
	  l_el.push_back(index_el);
	}
	++index_el;
      }
    }

    if (mu) {
      for( auto x : *mu ){
	if( x->auxdataConst< char >(passTopCuts) == 1 ){
	  IN_mu.push_back(index_mu);
	  l_mu.push_back(index_mu);
	}
	++index_mu;
      }
    }

    if (jet) {
      for( auto x : *jet ){
	if( x->auxdataConst< char >(passTopCuts) == 1 ){
	  IN_jet.push_back(index_jet);
	  l_jet.push_back(index_jet);
	}
	++index_jet;
      }
    }

    if (ljet) {
      for( auto x : *ljet ){
	if( x->auxdataConst< char >(passTopCuts) == 1 ){
	  IN_ljet.push_back(index_ljet);
	  l_ljet.push_back(index_ljet);
	}
	++index_ljet;
      }
    }

    if (tau) {
      for( auto x : *tau ){
	if( x->auxdataConst< char >(passTopCuts) == 1 ){
	  IN_tau.push_back(index_tau);
	  l_tau.push_back(index_tau);
	}
	++index_tau;
      }
    }
    
    // Save what's left of the std::lists into the OUT vectors;
    goodElectrons.clear();
    goodMuons.clear();
    goodJets.clear();
    goodLargeRJets.clear();
    goodTaus.clear();

    for( auto i : l_el  ){goodElectrons.push_back(i); }
    for( auto i : l_mu  ){goodMuons.push_back(i); }
    for( auto i : l_jet ){goodJets.push_back(i);}
    for( auto i : l_ljet){goodLargeRJets.push_back(i);}
    for( auto i : l_tau ){goodTaus.push_back(i);}
  }

  void DummyOverlapRemoval::print(std::ostream& os) const {
    os << "DummyOverlapRemoval\n";
    os << "  (1) remove muon within dR < 0.4 of any jet\n";
    os << "  (2) remove single jet closest to an electron (within dR < 0.2)\n";
    os << "  (3) remove electron with dR < 0.4 of jet\n";
  }

