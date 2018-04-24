/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/SelectOR.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODEgamma/ElectronContainer.h"
#include "TopEvent/EventTools.h"
#include "TopEvent/Event.h"

//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"


template<typename T> int CountPassOR(ConstDataVector<DataVector<T> >& vec, bool doTauOR = false) {
  int rv = 0;
  for (const auto iItr : vec) {
    if (iItr->template auxdataConst<char>("ttHpassOVR") && (!doTauOR || iItr->template auxdataConst<char>("ttHpassTauOVR") ) ) {
      rv++;
    }
  }
  return rv;
}


SelectOR::SelectOR(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  m_config(config)
{
   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_OR_electrons="SelectedORElectrons";
  m_OR_muons="SelectedORMuons";
  m_OR_jets="SelectedORJets";
  m_OR_taus="SelectedORTaus";
  
}

SelectOR::~SelectOR(){

}

bool SelectOR::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
  //std::string elname = m_config->sgKeyOR();

  auto goodEl = tthevt->selected_electrons;
  auto goodMu = tthevt->selected_muons; 
  auto goodJet = tthevt->selected_jets; 
  auto goodTau = tthevt->selected_taus; 

  for (const auto elItr : *goodEl) {
    elItr->auxdecor<char>("ttHpassOVR") = 1;
  }
  for (const auto muItr : *goodMu) {
    muItr->auxdecor<char>("ttHpassOVR") = 1;
  }
  for (const auto jetItr : *goodJet) {
    jetItr->auxdecor<char>("ttHpassOVR") = 1;
    jetItr->auxdecor<char>("ttHpassTauOVR") = 1;
  }
  for (const auto tauItr : *goodTau) {
    tauItr->auxdecor<char>("ttHpassOVR") = 1;
  }

  //if an electron and muon candidate are within 0.1 of each other: remove the electron 
  for (const auto elItr : *goodEl) {
     auto p4 = elItr->p4();
    for (const auto muItr : *goodMu) {
     if (p4.DeltaR(muItr->p4()) < 0.1) {
  	elItr->auxdecor<char>("ttHpassOVR") = 0;
  	break;
      }
    }
  }
  event.m_ttreeIndex == 0 && m_eleCutflow->Fill(8, CountPassOR(*goodEl));

  //If two electron candidates within 0.1 of each other: remove the one with lower pt 
  for (size_t i1 = 0; i1 < goodEl->size(); ++i1) {
    auto elItr = goodEl->at(i1);
    if (! elItr->auxdataConst<char>("ttHpassOVR")) {
      continue;
    }
    auto p4 = elItr->p4();
    for (size_t i2 = i1+1; i2 < goodEl->size(); ++i2) {
    auto elItr2 = goodEl->at(i2);
      if (! elItr2->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
      if (p4.DeltaR(elItr2->p4()) < 0.1) {
  	if (elItr2->pt() < elItr->pt()) {
  	  elItr2->auxdecor<char>("ttHpassOVR") = 0;
  	} else {
  	  elItr->auxdecor<char>("ttHpassOVR") = 0;
  	}
      }
    }
  }
  // now done later
  event.m_ttreeIndex == 0 && m_eleCutflow->Fill(9, CountPassOR(*goodEl));

  //if an electron and a jet are within 0.3 of each other: remove the jet 
  for (const auto jetItr : *goodJet) {
    auto p4 = jetItr->p4();
    for (const auto elItr : *goodEl) {
    if (! elItr->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
     if (p4.DeltaR(elItr->p4()) < 0.3) {
  	jetItr->auxdecor<char>("ttHpassOVR") = 0;
  	break;
      }
    }
  }
  event.m_ttreeIndex == 0 && m_jetCutflow->Fill(7, CountPassOR(*goodJet));

  //if a muon and a jet are within 0.04+10[GeV]/pT(muon) of each other: remove the muon
  /*for (const auto jetItr : *goodJet) {
    if (! jetItr->auxdataConst<char>("ttHpassOVR")) {
      continue;
    }
    auto p4 = jetItr->p4();
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
     if (p4.DeltaR(muItr->p4()) < 0.04+10e3/muItr->pt()) {
  	muItr->auxdecor<char>("ttHpassOVR") = 0;
      }
    }
  }*/

  //if a muon and a jet are within (0.4, 0.04+10[GeV]/pT(muon)) of each other: remove the muon
  for (const auto jetItr : *goodJet) {
    if (! jetItr->auxdataConst<char>("ttHpassOVR")) {
      continue;
    }
    auto p4 = jetItr->p4();
    for (const auto muItr : *goodMu) {
      
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
      if ( p4.DeltaR(muItr->p4()) < std::min(0.4, 0.04+10e3/muItr->pt()) ) {
  	muItr->auxdecor<char>("ttHpassOVR") = 0;
      }
    }
  }

  // now done later
  event.m_ttreeIndex == 0 && m_muCutflow->Fill(7, CountPassOR(*goodMu));

  //if an electron and a tau are within 0.2 of each other: remove the tau
  for (const auto tauItr : *goodTau) {
    auto p4 = tauItr->p4();
    for (const auto elItr : *goodEl) {
     if (! elItr->auxdataConst<char>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(elItr->p4()) < 0.2) {
	tauItr->auxdecor<char>("ttHpassOVR") = 0;
	break;
      }
    }
    //if an muon and a tau are within 0.2 of each other: remove the tau 
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(muItr->p4()) < 0.2) {
	tauItr->auxdecor<char>("ttHpassOVR") = 0;
	break;
      }
    }
    //if a tau and a jet are within 0.3 of each other: remove the jet 
    if (tauItr->auxdataConst<char>("ttHpassOVR")) {
      for (const auto jetItr : *goodJet) {
    // don't need additional protection here...
	if (p4.DeltaR(jetItr->p4()) < 0.3) {
	  jetItr->auxdecor<char>("ttHpassTauOVR") = 0;
	}
      }
    }
  }
  event.m_ttreeIndex == 0 && m_tauCutflow->Fill(8, CountPassOR(*goodTau));
  event.m_ttreeIndex == 0 && m_jetCutflow->Fill(8, CountPassOR(*goodJet));
  
  for (const auto elItr : *goodEl) {
    if (elItr->auxdataConst<char>("ttHpassOVR")) {
     tthevt->selected_OR_electrons->push_back(elItr);
    }
  }
  for (const auto muItr : *goodMu) {
    if (muItr->auxdataConst<char>("ttHpassOVR")) {
//      auto newMu = new xAOD::Muon();
//      newMu->makePrivateStore(*muItr);
      tthevt->selected_OR_muons->push_back(muItr);
    }
  }
  for (const auto jetItr : *goodJet) {
    //jetItr->auxdecor<char>("ttHJetOVRStatus") = jetItr->auxdataConst<char>("ttHpassOVR") + 
jetItr->auxdataConst<char>("ttHpassTauOVR");
    if (jetItr->auxdataConst<char>("ttHpassOVR")) {
     tthevt->selected_OR_jets->push_back(jetItr);
    }
  }
  for (const auto tauItr : *goodTau) {
    if (tauItr->auxdataConst<char>("ttHpassOVR")) {
//      auto newTau = new xAOD::TauJet();
//      newTau->makePrivateStore(*tauItr);
     tthevt->selected_OR_taus->push_back(tauItr);
   }    
  }


  std::string m_OR_electrons1 = m_OR_electrons + "_"+ m_config->systematicName(event.m_hashValue) ;
  std::sort (tthevt->selected_OR_electrons->begin(), tthevt->selected_OR_electrons->end(), ttHMLAsgHelper::pt_sort());
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_OR_electrons, m_OR_electrons1),"Could not record Selected Electrons after overlap removal");


  std::string m_OR_muons1 = m_OR_muons + "_"+ m_config->systematicName(event.m_hashValue) ;
  std::sort (tthevt->selected_OR_muons->begin(), tthevt->selected_OR_muons->end(), ttHMLAsgHelper::pt_sort());
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_OR_muons, m_OR_muons1),"Could not record Selected Muons after overlap removal");

  std::string m_OR_jets1 = m_OR_jets + "_"+ m_config->systematicName(event.m_hashValue) ;
  std::sort (tthevt->selected_OR_jets->begin(), tthevt->selected_OR_jets->end(), ttHMLAsgHelper::pt_sort());
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_OR_jets, m_OR_jets1),"Could not record Selected Jets after overlap removal");

  std::string m_OR_taus1 = m_OR_taus + "_"+ m_config->systematicName(event.m_hashValue) ;
  std::sort (tthevt->selected_OR_taus->begin(), tthevt->selected_OR_taus->end(), ttHMLAsgHelper::pt_sort());
  top::check(m_asgHelper->evtStore()->record(tthevt->selected_OR_taus, m_OR_taus1),"Could not record Selected Taus after overlap removal");

  return true;

}

std::string SelectOR::name() const{
  return "SELECT_OR";
}

