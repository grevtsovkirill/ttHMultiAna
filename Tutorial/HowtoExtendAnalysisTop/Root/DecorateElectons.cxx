/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "HowtoExtendAnalysisTop/DecorateElectrons.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODEgamma/ElectronContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"

DecorateElectrons::DecorateElectrons(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  iso_1( "iso_1" ),
  m_electronChargeIDLoose("ElectronChargeIDSelectorLoose"),
  m_electronChargeIDMedium("ElectronChargeIDSelectorMedium"),
  m_electronChargeIDTight("ElectronChargeIDSelectorTight"),
  m_config(config)
{
    top::check( iso_1.initialize(),"IsolationTool fails to initialize");
  top::check( m_electronChargeIDLoose.setProperty("TrainingFile", "ElectronPhotonSelectorTools/ChargeID/ECIDS_20161125for2017Moriond.root"), "ElectronChargeIDLoose: Failed to set training file." );
  top::check( m_electronChargeIDLoose.setProperty("OutputLevel", MSG::ERROR), "ElectronChargeIDLoose: Failed to set output level." );
  top::check( m_electronChargeIDLoose.initialize(), "ElectronChargeIDLoose: Failed to initialize." );
  top::check( m_electronChargeIDMedium.setProperty("TrainingFile", "ElectronPhotonSelectorTools/ChargeID/ECIDS_20161125for2017Moriond.root"), "ElectronChargeIDMedium: Failed to set training file." );
  top::check( m_electronChargeIDMedium.setProperty("OutputLevel", MSG::ERROR), "ElectronChargeIDMedium: Failed to set output level." );
  top::check( m_electronChargeIDMedium.initialize(), "ElectronChargeIDMedium: Failed to initialize." );
  top::check( m_electronChargeIDTight.setProperty("TrainingFile", "ElectronPhotonSelectorTools/ChargeID/ECIDS_20161125for2017Moriond.root"), "ElectronChargeIDTight: Failed to set training file." );
  top::check( m_electronChargeIDTight.setProperty("OutputLevel", MSG::ERROR), "ElectronChargeIDTight: Failed to set output level." );
  top::check( m_electronChargeIDTight.initialize(), "ElectronChargeIDTight: Failed to initialize." );

   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_pv=nullptr;
  nelec=0;
}

DecorateElectrons::~DecorateElectrons(){

}

bool DecorateElectrons::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Event>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Event> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
    for (auto elItr : event.m_electrons) {
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
  }




 /* m_vertices = event.m_primaryVertices;
  m_pvNumber = 0;
  m_puNumber = 0;

  for (const xAOD::Vertex* vtx : *m_vertices){
    if(vtx->vertexType() == xAOD::VxType::PriVtx) {
      m_pvNumber++;
      m_pv = vtx;
    }
    else if( vtx->vertexType() == xAOD::VxType::PileUp ) m_puNumber++;
  }*/

 // double vtx_z = m_pv->z();

 /* for (auto elItr : event.m_electrons) {
    if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
  nelec++;
  }*/
 /* for (auto elItr : event.m_electrons) {
    //delta z0
    float delta_z0 = elItr->trackParticle()->z0()
                   + elItr->trackParticle()->vz()
                   - vtx_z;
    elItr->auxdecor<float>("delta_z0") = delta_z0;
    elItr->auxdecor<float>("delta_z0_sintheta") = delta_z0*std::sin( elItr->trackParticle()->theta() );
        if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
  nelec++;
  }*/
std::cout<<"nelecbefore= " <<nelec<<std::endl;
  return true;

}

std::string DecorateElectrons::name() const{
  return "DECORATEEL";
}



