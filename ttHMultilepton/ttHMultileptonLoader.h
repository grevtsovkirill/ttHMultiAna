/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef HOWTOEXTENDANALYSISTOP_HOWTOEXTENDANALYSISTOPLOADER_H
#define HOWTOEXTENDANALYSISTOP_HOWTOEXTENDANALYSISTOPLOADER_H

#include "TopEventSelectionTools/ToolLoaderBase.h"


  
  class ttHMultileptonLoader : public top::ToolLoaderBase {
    public:
      top::EventSelectorBase* initTool(const std::string& name, const std::string& line, TFile* outputFile, std::shared_ptr<top::TopConfig> config,EL::Worker* wk = nullptr);

      ClassDef(ttHMultileptonLoader, 0)      
  };

#endif
