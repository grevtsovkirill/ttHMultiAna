#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/ReadBDTG.h"

#include "TROOT.h"
void
ttHMultileptonLooseEventSaver::Decorate(const top::Event& event) {

  // Retrieve track jet container from evtStore - needed due to baseline track jet overlap removal.
  const xAOD::JetContainer* tJets = 0;
  bool no_tjet = false;
  if(m_config->useTrackJets() == false) no_tjet = true;
  else top::check(evtStore()->retrieve(tJets, m_config->sgKeyTrackJets(event.m_hashValue)), "Failed to retrieve track jets");

  double vtx_z = m_pv->z();

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

    //variables for muon_ID BDT 

    //Default decorations
    muItr->auxdecor<float> ("jet_pt")           = -999;
    muItr->auxdecor<float> ("jet_eta")          = -999;
    muItr->auxdecor<float> ("jet_phi")          = -999;
    muItr->auxdecor<float> ("jet_dr")           = -999;
    muItr->auxdecor<int> ("jet_numTrk")         = -999;
    muItr->auxdecor<float> ("jet_sumPtTrk")     = -999;
    muItr->auxdecor<float> ("MV2c10_weight")    = -999;
    muItr->auxdecor<float>("jet_ptRel")         = -999;
    muItr->auxdecor<int> ("jet_tagWeightBin")       = -999;
    muItr->auxdecor<float>("muon_BDT")		= -999;


    xAOD::Jet* closestJet =0;
    float smallestDr = 1e5;
    for(auto jet: event.m_jets){
      float muJetDr = jet->p4().DeltaR(muItr->p4());
      if(smallestDr > muJetDr)
      {
         smallestDr = muJetDr;
         closestJet = (xAOD::Jet*)jet;
      }
    }
    if(smallestDr <=0.6 && closestJet)
    {
       muItr->auxdecor<float> ("jet_pt")  = closestJet->p4().Pt();
       muItr->auxdecor<float> ("jet_eta") = closestJet->p4().Eta();
       muItr->auxdecor<float> ("jet_phi") = closestJet->p4().Phi();
       muItr->auxdecor<float> ("jet_dr")  = smallestDr;
       auto numTrkVec = closestJet->getAttribute<std::vector<int>   >(xAOD::JetAttribute::NumTrkPt500);
       auto numJetTrk =  (numTrkVec.size() ? numTrkVec[m_pv->index()] : 0);
       muItr->auxdecor<int> ("jet_numTrk")      = numJetTrk;
       auto sumPtTrkVec  = closestJet->getAttribute<std::vector<float> >(xAOD::JetAttribute::SumPtTrkPt500);
       auto jetSumPtTrk =  (sumPtTrkVec.size() ? sumPtTrkVec[m_pv->index()] : 0.);
       muItr->auxdecor<float> ("jet_sumPtTrk")    = jetSumPtTrk;

       auto btagging = closestJet->btagging();
       double rv(0);
       muItr->auxdecor<float> ("MV2c10_weight") = btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0. ;
       muItr->auxdecor<int>("jet_tagWeightBin") = ( closestJet->isAvailable<int>("tagWeightBin")) ?closestJet->auxdataConst<int>("tagWeightBin") : -2;

       float theta= muItr->p4().Vect().Angle(closestJet->p4().Vect());
       muItr->auxdecor<float>("jet_ptRel") = TMath::Sin(theta) * muItr->pt();

       //MuonIDBDT Score
       std::vector<std::string> inputVarNames = { "jetMu_jetPt", "jetMu_jetNTrk", "jetMu_SumPtTrk", "jetMu_mv2c10_weight", "jetMu_deltaR", "jetMu_ptRel*1e-3", "jetMu_jetPt/jetMu_muPt", "jetMu_muonSigd0PV", "jetMu_muonZ0SinTheta"};
       ReadBDTG muonIdBDT(inputVarNames);
       std::vector<double> inputValues ={muItr->auxdataConst<float>("jet_pt"),muItr->auxdataConst<int>("jet_numTrk"),muItr->auxdataConst<float>("jet_sumPtTrk"),muItr->auxdataConst<float>("MV2c10_weight"),muItr->auxdataConst<float>("jet_ptRel")*1e-3,muItr->auxdataConst<float>("jet_pt")/muItr->pt(),muItr->auxdataConst<float>("d0sig"),muItr->auxdataConst<float>("delta_z0_sintheta")};

       muItr->auxdecor<float>("muon_BDT") = muonIdBDT.GetMvaValue(inputValues);

    }
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
	if( truthJet->isAvailable<int>("PartonTruthLabelID") ){
	  truthJetFlavour = truthJet->auxdata<int>("PartonTruthLabelID");
	}
      }
    }
    tauItr->auxdecor<int>("truthJetFlavour") = truthJetFlavour;
  }//end taus
  
}//end decorate
