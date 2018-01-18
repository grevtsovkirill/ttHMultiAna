/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef FillVariables_H_
#define FillVariables_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "HowtoExtendAnalysisTop/Event.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"

class FillVariables:public top::EventSelectorBase {

 public:

  FillVariables(std::string params, std::shared_ptr<top::TopConfig> config);
  ~FillVariables();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:
  bool m_doSFSystematics;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_elec;
  std::string m_params;
  std::string m_muon;
};

#endif

