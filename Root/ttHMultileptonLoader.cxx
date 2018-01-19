/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/ttHMultileptonLoader.h"

#include "ttHMultilepton/ttHMLCreateEvent.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/DecorateElectrons.h"
#include "ttHMultilepton/SelectJets.h"
#include "ttHMultilepton/SelectElectrons.h"
#include "ttHMultilepton/SelectTaus.h"
#include "ttHMultilepton/SelectMuons.h"
#include "ttHMultilepton/DecorateTaus.h"
#include "ttHMultilepton/DecorateMuons.h"

#include <iostream>
#include "TFile.h"


  top::EventSelectorBase* ttHMultileptonLoader::initTool(const std::string& /*name*/, const std::string& line, TFile* /*outputFile*/, std::shared_ptr<top::TopConfig> config,EL::Worker* /*wk*/)
  {
    //get the first bit of the string and store it in toolname
    std::istringstream iss(line);
    std::string toolname;
    getline(iss, toolname, ' ');

    //any parameters?
    std::string param;
    if (line.size() > toolname.size())
        param = line.substr(toolname.size() + 1);

    if (toolname == "EVEN")
        return new ttHMLCreateEvent(param, config);  
    if(toolname == "DECORATEEL")
        return new DecorateElectrons(param, config);
    if(toolname == "DECORATETAUS")
        return new DecorateTaus(param, config);
    if(toolname == "DECORATEMUONS")
        return new DecorateMuons(param, config);
    if(toolname == "SELECTJETS")
        return new SelectJets(param, config);
   if(toolname == "SELECTELECTRONS")
        return new SelectElectrons(param, config);
    if(toolname == "SELECTTAUS")
        return new SelectTaus(param, config);
    if(toolname == "SELECTMUONS")
        return new SelectMuons(param, config);
//    if(toolname == "FILLVARIABLES")
//        return new FillVariables(param, config);
    //else if (toolname.find("OTHER_TOOL") == 0)
    //  return OtherToolThatYouInvented()    
    
    return nullptr;      
  }
