#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
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
  }
}
