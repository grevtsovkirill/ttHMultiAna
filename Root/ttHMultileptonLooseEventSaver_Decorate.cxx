#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"

void
ttHMultileptonLooseEventSaver::Decorate(const top::Event& event) {

  for (auto elItr : event.m_electrons) {
    // Isolation
    auto isomap = iso_1.accept(*elItr);
    int idx = 0;
    for (auto wp : {"Iso_LooseTrackOnly", "Iso_Loose", "Iso_Gradient", "Iso_GradientLoose","Iso_FixedCutTightTrackOnly","Iso_FixedCutLoose","Iso_FixedCutTight"}) {
      elItr->auxdecor<short>(wp) = isomap.getCutResult(idx++);
    }

    auto WPs = {"LHLoose","LHMedium","LHTight"};
    for( auto wp : WPs ) {
      std::string ttHML_LH_decoration("pass");                        ttHML_LH_decoration += wp;
      std::string derivation_LH_decoration("DFCommonElectrons"); derivation_LH_decoration += wp;
      if(m_config->isPrimaryxAOD()) {
	//there will be only one LH wp when using xAOD
	//it seems the type of the decoration was changed at some point
	try {
	  elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<int> (m_config->electronIDDecoration());
	}
	catch(std::exception& e) {
	  elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<char>(m_config->electronIDDecoration());
	}
      }
      else { // not primary xAOD
	try {
	  elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<int> (derivation_LH_decoration);
	}
	catch(std::exception& e) {
	  elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<char>(derivation_LH_decoration);
	}
      }
    }
  
  }// end elecs

  // Retrieve track jet container from evtStore - needed due to baseline track jet overlap removal.
  const xAOD::JetContainer* tJets = 0;
  bool no_tjet = false;
  if(m_config->useTrackJets() == false) no_tjet = true;
  else top::check(evtStore()->retrieve(tJets, m_config->sgKeyTrackJets(event.m_hashValue)), "Failed to retrieve track jets");

  for (auto muItr : event.m_muons) {
    // Isolation
    auto isomap = iso_1.accept(*muItr);
    int idx = 0;
    for (auto wp : {"Iso_LooseTrackOnly", "Iso_Loose", "Iso_Gradient", "Iso_GradientLoose", "Iso_FixedCutTightTrackOnly","Iso_FixedCutLoose"}) {
      muItr->auxdecor<short>(wp) = isomap.getCutResult(idx++);
    }

    // Track jets
    if(!no_tjet) {
      xAOD::Jet* jet = 0;
      std::pair<double, const xAOD::Jet*> match(10.0, jet);
      for(auto tjItr : *tJets) { 
	double dr = tjItr->p4().DeltaR(muItr->p4());
	if(match.second) {
	  if(dr < match.first) {
	    match.first  = dr;
	    match.second = tjItr;
	  }
	}
	else {
	  match.first  = dr;
	  match.second = tjItr;    
	}
      }
      if(match.second && match.first < 0.5) {
	//std::vector<const xAOD::IParticle *> parts = match.second->getConstituents().asIParticleVector();
	//if(parts.size() <= 1) muItr->auxdecor<double>("jetFitterComb") = -10.0;
	const xAOD::BTagging *btag = match.second->btagging();
	if(btag) {
	  muItr->auxdecor<double>("jetFitterComb") = btag->JetFitterCombNN_loglikelihoodratio();
	}
	else muItr->auxdecor<double>("jetFitterComb") = -10.0;
      }
      else muItr->auxdecor<double>("jetFitterComb") = -10.0;
    }
    else muItr->auxdecor<double>("jetFitterComb") = -10.0;

  }//end muons

  top::check( m_tauSelectionEleOLR.initializeEvent(), "Failed to initializeEvent() for tauSelectionEleOLR");
  
  for( auto tauItr : event.m_tauJets) {
    //truth
    int isHadronic(0), tauTruthType(0), tauTruthOrigin(0);
    if(tauItr->isAvailable<char>("IsTruthMatched") && static_cast<int>(tauItr->auxdata<char>("IsTruthMatched")) == 1)
      {
	if(tauItr->isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
	  auto tauTruthLink = tauItr->auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
    	  if(tauTruthLink.isValid()) {
	    const xAOD::TruthParticle* truthTau = nullptr;
	    truthTau = *tauTruthLink;

	    if( truthTau->isAvailable<char>("IsHadronicTau") )
	      isHadronic =  static_cast<int>( truthTau->auxdata<char>("IsHadronicTau") );

	    if( truthTau->isAvailable<unsigned int>("classifierParticleOrigin") )
	      tauTruthOrigin = truthTau->auxdata<unsigned int>("classifierParticleOrigin");

	    if( truthTau->isAvailable<unsigned int>("classifierParticleType") )
	      tauTruthType = truthTau->auxdata<unsigned int>("classifierParticleType");
	  }
	}
      }
    tauItr->auxdecor<int>("IsHadronic")     = isHadronic;
    tauItr->auxdecor<int>("tauTruthType")   = tauTruthType;
    tauItr->auxdecor<int>("tauTruthOrigin") = tauTruthOrigin;

    //EleOLR
    int passEleOLR(0);
    if(m_tauSelectionEleOLR.accept(*tauItr)) passEleOLR = 1;
    tauItr->auxdecor<int>("passEleOLR") = passEleOLR;
  }//end taus
  
}//end decorate
