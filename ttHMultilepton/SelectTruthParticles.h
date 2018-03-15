/*
 *   Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
 *   */

#ifndef SelectTruthElectrons_H_
#define SelectTruthElectrons_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "ttHMultilepton/TruthSelector.h"
#include "ttHMultilepton/TruthMatchAlgo.h"
#include <unordered_map>

class SelectTruthParticles:public top::EventSelectorBase {

 public:
  SelectTruthParticles(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectTruthParticles();
  // void initialise(const top::Event& event) const;
     bool apply(const top::Event & event) const override;
       std::string name() const override;
         ttHMLAsgHelper* m_asgHelper;
          private:
            bool m_doSFSystematics;
              std::shared_ptr<top::TopConfig> m_config;
                mutable const top::Event* m_event;
                 // std::string name;
                   mutable int ntruthelec2;
                     std::string m_truthparticles;
                       std::string m_params;
mutable ttH::TruthSelector truthSelector;  
mutable ttHMultilepton::TruthMatchAlgo* m_truthMatchAlgo;  




                  };
  
                       #endif
                       
