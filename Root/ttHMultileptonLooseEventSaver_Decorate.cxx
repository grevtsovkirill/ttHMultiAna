#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/ReadBDTG.h"

#include "TROOT.h"


// looking for a match for T in a container of Us
template<class ObjectT, class ContainerU> std::pair<double, const typename ContainerU::base_value_type* > FindMinDR(const ObjectT &obj, const ContainerU &cont) 
{
  typedef typename ContainerU::base_value_type ObjectU;
  std::pair<double, const ObjectU* > match(0.0, nullptr );

  for(const ObjectU* ptr: cont) {
    const double dr = obj->p4().DeltaR(ptr->p4());
      
    if(match.second) {
      if(dr < match.first) {
	match.first  = dr;
	match.second = ptr;
      }
    }
    else {
      match.first  = dr;
      match.second = ptr;     
    }
  }
    
  return match;
}



void
ttHMultileptonLooseEventSaver::Decorate(const top::Event& event) {

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

    
    elItr->auxdecor<float>("chargeIDBDTLoose") = (float)m_electronChargeIDLoose.calculate(elItr);
    elItr->auxdecor<float>("chargeIDBDTMedium") = (float)m_electronChargeIDMedium.calculate(elItr);
    elItr->auxdecor<float>("chargeIDBDTTight") = (float)m_electronChargeIDTight.calculate(elItr);
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

    
    //variables for muon_ID BDT 

    //Default decorations
    muItr->auxdecor<float> ("jet_pt")           = -99;
    muItr->auxdecor<float> ("jet_eta")          = -99;
    muItr->auxdecor<float> ("jet_phi")          = -99;
    muItr->auxdecor<float> ("dRJet")            = -1.0; //name changed for promptLeptonIso calibration
    muItr->auxdecor<float> ("jet_numTrk")       = -99;
    muItr->auxdecor<float> ("jet_sumPtTrk")     = -99;
    muItr->auxdecor<float> ("MV2c10_weight")    = -99;
    muItr->auxdecor<float>("jet_ptRel")         = -99;
    muItr->auxdecor<float> ("jet_tagWeightBin") = -99;
    muItr->auxdecor<float>("muon_BDT")		= -99;
 
    xAOD::Jet* closestJet =0;
    float smallestDr = 1e5;
    for (const auto jetItr : event.m_jets) 
    {
        //if (!m_jetCleaningToolLooseBad->keep(*jetItr)) {
          //continue;
        //}
        if (jetItr->pt() < 25e3) {
          continue;
        }
        if (fabs(jetItr->eta()) > 2.5) {
          continue;
        }
        if (jetItr->pt() < 60e3
          && fabs(jetItr->getAttribute<float>("DetectorEta")) < 2.4
          && jetItr->auxdataConst<float>("AnalysisTop_JVT") < 0.59) {
          continue;
        }
        float muJetDr = jetItr->p4().DeltaR(muItr->p4());
        if(smallestDr > muJetDr)
        {
           smallestDr = muJetDr;
           closestJet = (xAOD::Jet*)jetItr;
        }
    }


    if(closestJet)
    {
       muItr->auxdecor<float> ("jet_pt")  = closestJet->p4().Pt();
       muItr->auxdecor<float> ("jet_eta") = closestJet->p4().Eta();
       muItr->auxdecor<float> ("jet_phi") = closestJet->p4().Phi();
       muItr->auxdecor<float> ("dRJet")  = smallestDr;
       auto numTrkVec = closestJet->getAttribute<std::vector<int>   >(xAOD::JetAttribute::NumTrkPt500);
       auto numJetTrk =  (numTrkVec.size() ? numTrkVec[m_pv->index()] : 0);
       muItr->auxdecor<float> ("jet_numTrk")      = numJetTrk;
       auto sumPtTrkVec  = closestJet->getAttribute<std::vector<float> >(xAOD::JetAttribute::SumPtTrkPt500);
       auto jetSumPtTrk =  (sumPtTrkVec.size() ? sumPtTrkVec[m_pv->index()] : 0.);
       muItr->auxdecor<float> ("jet_sumPtTrk")    = jetSumPtTrk;

       auto btagging = closestJet->btagging();
       double rv(0);
       muItr->auxdecor<float> ("MV2c10_weight") = btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0. ;
       muItr->auxdecor<float>("jet_tagWeightBin") = ( closestJet->isAvailable<int>("tagWeightBin")) ?closestJet->auxdataConst<int>("tagWeightBin") : -2;

       float theta= muItr->p4().Vect().Angle(closestJet->p4().Vect());
       muItr->auxdecor<float>("jet_ptRel") = TMath::Sin(theta) * muItr->pt();

       //MuonIDBDT Score
       std::vector<std::string> inputVarNames = {
	        "jetMu_jetPt",
		"jetMu_jetNTrk",
		"jetMu_SumPtTrk", 
		"mv2c10_70", 
		"jetMu_deltaR", 
		"jetMu_ptRel", 
		"jetMu_jetPt/jetMu_muPt", 
		"jetMu_muonSigd0PV", 
		"jetMu_muonZ0SinTheta" };

       ReadBDTG muonIdBDT(inputVarNames);

       std::vector<double> inputValues ={
	       muItr->auxdataConst<float>("jet_pt"),
	       muItr->auxdataConst<float>("jet_numTrk"),
	       muItr->auxdataConst<float>("jet_sumPtTrk"),
	       (muItr->auxdataConst<float>("MV2c10_weight")> 0.8244) ? 1.0 :0.0,
	       muItr->auxdataConst<float>("dRJet"), //jet_dr -> dRJet
	       smallestDr,muItr->auxdataConst<float>("jet_ptRel"),
	       muItr->auxdataConst<float>("jet_pt")/muItr->pt(),
	       muItr->auxdataConst<float>("d0sig"),
	       muItr->auxdataConst<float>("delta_z0_sintheta")};

       if (smallestDr <=0.4)
       {
           muItr->auxdecor<float>("muon_BDT") = muonIdBDT.GetMvaValue(inputValues);
       }

    }
  }//end muons
  
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

    //EleBDT
    int passEleBDT(0);
    if(m_tauSelectionEleBDT.accept(*tauItr)) passEleBDT = 1;
    tauItr->auxdecor<int>("passEleBDT") = passEleBDT;

    //MuonOLR
    int passMuonOLR(0);
    if(m_tauSelectionMuonOLR.accept(*tauItr)) passMuonOLR = 1;
    tauItr->auxdecor<int>("passMuonOLR") = passMuonOLR;
    
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


void
ttHMultileptonLooseEventSaver::DecorateTaus(const top::Event& event) {

  for( const xAOD::TauJet* tau : event.m_tauJets) {
    auto match = FindMinDR(tau, event.m_jets);
    if( match.second and match.first < 0.3 ) {
      const xAOD::Jet& jet = *match.second;
      
      auto btagging = jet.btagging(); double rv(-2);
      if(btagging) btagging->MVx_discriminant("MV2c10", rv);
      tau->auxdecor<float>("MV2c10") = rv;

      tau->auxdecor<int>("tagWeightBin") =
	jet.isAvailable<int>("tagWeightBin") ? jet.auxdataConst<int>("tagWeightBin") : -2;

      tau->auxdecor<char>("passJVT") =	
	jet.isAvailable<char>("passJVT") ? jet.auxdataConst<char>("passJVT") : -1;

      try {
        tau->auxdecor<char>("fromPV") =
          (tau->vertex() and m_pv) ? ( tau->vertex()->position() == m_pv->position() ) : -1;
      }
      catch(std::exception& e) {
        tau->auxdecor<char>("fromPV") = 1;
      }
    }
  }
}
