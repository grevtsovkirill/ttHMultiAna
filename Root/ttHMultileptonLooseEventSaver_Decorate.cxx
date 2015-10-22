#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"

void
ttHMultileptonLooseEventSaver::Decorate(const top::Event& event) {
  for (auto elItr : event.m_electrons) {
    elItr->auxdecor<float>("d0significance") = xAOD::TrackingHelpers::d0significance( elItr->trackParticle(), m_eventInfo->beamPosSigmaX(), m_eventInfo->beamPosSigmaY(), m_eventInfo->beamPosSigmaXY() );

    float z0 = elItr->trackParticle()->z0(); 
    float vz = elItr->trackParticle()->vz(); 
    float z_pv = 0;  
    for (auto vtx : *m_vertices){ 
      if(vtx->vertexType() == xAOD::VxType::PriVtx) {
	z_pv = vtx->z(); 
	break; 
      }
    } 
    float z0corr = (z0 + vz - z_pv); 
    float theta = elItr->trackParticle()->theta(); 
    float sin_Th = sin(theta); 
    elItr->auxdecor<float>("z0sintheta") = (z0corr*sin_Th);
    // Isolation
    auto isomap = iso_1.accept(*elItr);
    int idx = 0;
    for (auto wp : {"Iso_LooseTrackOnly", "Iso_Loose", "Iso_Tight", "Iso_Gradient", "Iso_GradientLoose"}) {
      elItr->auxdecor<short>(wp) = isomap.getCutResult(idx++);
    }
  }
  
  for (auto muItr : event.m_muons) {
    muItr->auxdecor<float>("d0significance") = xAOD::TrackingHelpers::d0significance( muItr->primaryTrackParticle(), m_eventInfo->beamPosSigmaX(), m_eventInfo->beamPosSigmaY(), m_eventInfo->beamPosSigmaXY() );

    float z0 = muItr->primaryTrackParticle()->z0(); 
    float vz = muItr->primaryTrackParticle()->vz(); 
    float z_pv = 0;  
    for (auto vtx : *m_vertices){ 
      if(vtx->vertexType() == xAOD::VxType::PriVtx) {
	z_pv = vtx->z(); 
	break; 
      }
    } 
    float z0corr = (z0 + vz - z_pv); 
    float theta = muItr->primaryTrackParticle()->theta(); 
    float sin_Th = sin(theta); 
    muItr->auxdecor<float>("z0sintheta") = (z0corr*sin_Th);
    // Isolation
    auto isomap = iso_1.accept(*muItr);
    int idx = 0;
    for (auto wp : {"Iso_LooseTrackOnly", "Iso_Loose", "Iso_Tight", "Iso_Gradient", "Iso_GradientLoose"}) {
      muItr->auxdecor<short>(wp) = isomap.getCutResult(idx++);
    }
  }

  top::check( m_tauSelectionEleOLR.initializeEvent(), "Failed to initializeEvent() for tauSelectionEleOLR");

  for( auto tauItr : event.m_tauJets) {
    //SF
    // init the values
    tauItr->auxdecor<double>("TauScaleFactorReconstructionHadTau") = 1.;
    tauItr->auxdecor<double>("TauScaleFactorJetIDHadTau")          = 1.;
    tauItr->auxdecor<double>("TauScaleFactorEleOLRHadTau")         = 1.;
    if( top::isSimulation(event) ) {
      top::check( m_tauEffTool.applyEfficiencyScaleFactor(*tauItr), "Failed to apply SF to tau");
      double tauSF(0);
      top::check( m_tauEffTool.getEfficiencyScaleFactor(*tauItr,tauSF), "Failed to apply SF to tau");
      
      //std::cout<<tauSF<<std::endl;
      //std::cout<<tauItr->auxdecor<double>("TauScaleFactorReconstructionHadTau")<<std::endl;
      //std::cout<<tauItr->auxdecor<double>("TauScaleFactorJetIDHadTau")<<std::endl;
      //std::cout<<tauItr->auxdecor<double>("TauScaleFactorEleOLRHadTau")<<std::endl;
    }

    //truth
    int isHadronic(0), tauTruthType(0), tauTruthOrigin(0);
    if(tauItr->isAvailable<char>("IsTruthMatched") && static_cast<int>(tauItr->auxdata<char>("IsTruthMatched")) == 1)
      {
	if(tauItr->isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
	  auto tauTruthLink = tauItr->auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
    	  if(tauTruthLink.isValid()) {
	    const xAOD::TruthParticle* truthTau = nullptr;
	    truthTau = *tauTruthLink;
	    if( truthTau->isAvailable<char>("IsHadronicTau") ) isHadronic =  static_cast<int>( truthTau->auxdata<char>("IsHadronicTau") );
	    tauTruthOrigin = truthTau->auxdata<unsigned int>("classifierParticleOrigin");
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
  
}
