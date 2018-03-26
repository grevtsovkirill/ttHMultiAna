/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/DecorateTaus.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODTau/TauJetContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
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

DecorateTaus::DecorateTaus(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  iso_1( "iso_1" ),

  m_tauSelectionEleOLR("TauSelectionEleOLR"),
  m_tauSelectionEleBDT("TauSelectionEleBDT"),
  m_tauSelectionMuonOLR("TauSelectionMuonOLR"),
  m_config(config)
{
    top::check( iso_1.initialize(),"IsolationTool fails to initialize");
    char* const rc = getenv("WorkDir_DIR");

   top::check( m_tauSelectionEleOLR.setProperty("ConfigPath", std::string(rc)+"/data/ttHMultilepton/data/EleOLR_tau_selection.conf" ), "TauSelectionEleOLR:Failed to set ConfigPath");
  top::check( m_tauSelectionEleOLR.initialize(), "Failed to initialise TauSelectionTool for EleOLR" );

  top::check( m_tauSelectionEleBDT.setProperty("ConfigPath", std::string(rc)+"/data/ttHMultilepton/data/EleOLR_tau_selection.conf" ), "TauSelectionEleBDT:Failed to set ConfigPath");
  top::check( m_tauSelectionEleBDT.initialize(), "Failed to initialise TauSelectionTool for EleBDT" );

  top::check( m_tauSelectionMuonOLR.setProperty("ConfigPath", std::string(rc)+"/data/ttHMultilepton/data/EleOLR_tau_selection.conf" ), "TauSelectionMuonOLR:Failed to set ConfigPath");
  top::check( m_tauSelectionMuonOLR.initialize(), "Failed to initialise TauSelectionTool for MuonOLR" );

   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_pv=nullptr;
  ntaus=0;
}

DecorateTaus::~DecorateTaus(){

}

bool DecorateTaus::apply(const top::Event & event) const{

  //km_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
  m_vertices = event.m_primaryVertices;
  m_pvNumber = 0;
  m_puNumber = 0;

  for (const xAOD::Vertex* vtx : *m_vertices){
    if(vtx->vertexType() == xAOD::VxType::PriVtx) {
      m_pvNumber++;
      m_pv = vtx;
    }
    else if( vtx->vertexType() == xAOD::VxType::PileUp ) m_puNumber++;
  }
    
    for (auto tauItr : event.m_tauJets) {

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
    tauItr->auxdecor<int>("tagWeightBin") =-99;
    tauItr->auxdecor<char>("fromPV")=-99;
  }
  decoratetau(event);
//std::cout<<"ntaubefore= " <<ntaus<<std::endl;
  return true;

}

void DecorateTaus::decoratetau(const top::Event& event)const{
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
	}
      try {
        tau->auxdecor<char>("fromPV") =
          (tau->vertex() and m_pv) ? ( tau->vertex()->position() == m_pv->position() ) : -1;
      }
      catch(std::exception& e) {
        tau->auxdecor<char>("fromPV") = 1;
      }
    
  }



}

std::string DecorateTaus::name() const{
  return "DECORATETAUS";
}



