/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "HowtoExtendAnalysisTop/CustomEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEventSelectionTools/TreeManager.h"
#include "HowtoExtendAnalysisTop/Event.h"

#include "TopConfiguration/TopConfig.h"

#include "TopConfiguration/ConfigurationSettings.h"
#include "TopConfiguration/SelectionConfigurationData.h"

#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <cmath>
#include <algorithm>

#include <TRandom3.h>


namespace top{
  ///-- Constrcutor --///
  CustomEventSaver::CustomEventSaver() :
    m_randomNumber(0.),
    m_someOtherVariable(0.)
  {
  }
  
  ///-- initialize - done once at the start of a job before the loop over events --///
  void CustomEventSaver::initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches)
  {
    ///-- Let the base class do all the hard work --///
    ///-- It will setup TTrees for each systematic with a standard set of variables --///
    top::EventSaverFlatNtuple::initialize(config, file, extraBranches);

	m_ttHEvent = new ttHML::Event();
    
    ///-- Loop over the systematic TTrees and add the custom variables --///
    for (auto systematicTree : treeManagers()) {
      systematicTree->makeOutputVariable(m_randomNumber, "randomNumber");
      systematicTree->makeOutputVariable(m_someOtherVariable,"someOtherVariable");
	  m_ttHEvent->BootstrapTree(systematicTree,false);
    }
  }
  
  ///-- saveEvent - run for every systematic and every event --///
  void CustomEventSaver::saveEvent(const top::Event& event) 
  {
  std::shared_ptr<ttHML::Event> tthevt;
  if(event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
    tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");
  }

    ///-- set our variables to zero --///
    m_randomNumber = 0.;
    m_someOtherVariable = 0.;
    
    ///-- Fill them - you should probably do something more complicated --///
    TRandom3 random( event.m_info->eventNumber() );
    m_randomNumber = random.Rndm();    
    m_someOtherVariable = 42;
 
    m_ttHEvent->AssignOutput(m_ttHEvent,tthevt);   
    ///-- Let the base class do all the hard work --///
    top::EventSaverFlatNtuple::saveEvent(event);
  }
  
}


