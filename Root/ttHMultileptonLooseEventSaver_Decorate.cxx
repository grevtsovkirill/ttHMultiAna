#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"

void
ttHMultileptonLooseEventSaver::Decorate(const top::Event& event) {

  // Retrieve track jet container from evtStore - needed due to baseline track jet overlap removal.
  const xAOD::JetContainer* tJets = 0;
  bool no_tjet = false;
  if(m_config->useTrackJets() == false) no_tjet = true;
  else top::check(evtStore()->retrieve(tJets, m_config->sgKeyTrackJets(event.m_hashValue)), "Failed to retrieve track jets");

  double vtx_z = m_pvZ;
  
  for (auto elItr : event.m_electrons) {
    //delta z0
    float delta_z0 = elItr->trackParticle()->z0()
                   + elItr->trackParticle()->vz()
                   - vtx_z;
    elItr->auxdecor<float>("delta_z0") = delta_z0;
    elItr->auxdecor<float>("delta_z0_sintheta") = delta_z0*std::sin( elItr->trackParticle()->theta() );
    
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

    // Track jets
    if(!no_tjet) {
      xAOD::Jet* jet = 0;
      std::pair<double, const xAOD::Jet*> match(10.0, jet);
      for(auto tjItr : *tJets) {
	double dr = tjItr->p4().DeltaR(elItr->p4());
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
      if(match.second && match.first < 0.5 &&
	 match.second->isAvailable<std::vector<ElementLink<DataVector<xAOD::IParticle> > > >("constituentLinks")) {
	xAOD::JetConstituentVector parts = match.second->getConstituents();
	if(parts.size() <= 1) elItr->auxdecor<double>("jetFitterComb") = -10.0;
	else {
	  if(match.second->isAvailable<ElementLink<DataVector<xAOD::BTagging_v1> > >("btaggingLink")) {
	    const xAOD::BTagging *btag = match.second->btagging();
	    if(btag) {
	      elItr->auxdecor<double>("jetFitterComb") = btag->JetFitterCombNN_loglikelihoodratio();
	    }
	    else elItr->auxdecor<double>("jetFitterComb") = -10.0;
	  }
	  else elItr->auxdecor<double>("jetFitterComb") = -10.0;
	}
      }
      else elItr->auxdecor<double>("jetFitterComb") = -10.0;
    }
    else elItr->auxdecor<double>("jetFitterComb") = -10.0;
  
  }// end elecs

  for (auto muItr : event.m_muons) {
    //delta z0
    float delta_z0 = muItr->primaryTrackParticle()->z0() +
		     muItr->primaryTrackParticle()->vz() -
		     vtx_z;
    muItr->auxdecor<float>("delta_z0") = delta_z0;
    muItr->auxdecor<float>("delta_z0_sintheta") = delta_z0*std::sin( muItr->primaryTrackParticle()->theta() );

    
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
      if(match.second && match.first < 0.5 &&
	 match.second->isAvailable<std::vector<ElementLink<DataVector<xAOD::IParticle> > > >("constituentLinks")) {
	xAOD::JetConstituentVector parts = match.second->getConstituents();
	if(parts.size() <= 1) muItr->auxdecor<double>("jetFitterComb") = -10.0;
	else {
	  if(match.second->isAvailable<ElementLink<DataVector<xAOD::BTagging_v1> > >("btaggingLink")) {
	    const xAOD::BTagging *btag = match.second->btagging();
	    if(btag) {
	      muItr->auxdecor<double>("jetFitterComb") = btag->JetFitterCombNN_loglikelihoodratio();
	    }
	    else muItr->auxdecor<double>("jetFitterComb") = -10.0;
	  }
	  else muItr->auxdecor<double>("jetFitterComb") = -10.0;
	}
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

    //truth jet flavour
    int truthJetFlavour(-1);
    if(tauItr->isAvailable<ElementLink<xAOD::JetContainer> >("truthJetLink")) {
      auto truthJetLink = tauItr->auxdata<ElementLink<xAOD::JetContainer> >("truthJetLink");
      if(truthJetLink.isValid() ) {
	auto truthJet = *truthJetLink;
	if( truthJet->isAvailable<int>("HadronConeExclTruthLabelID") ){
	  truthJetFlavour = truthJet->auxdata<int>("HadronConeExclTruthLabelID");
	}
      }
    }
    tauItr->auxdecor<int>("truthJetFlavour") = truthJetFlavour;
  }//end taus
  
}//end decorate
