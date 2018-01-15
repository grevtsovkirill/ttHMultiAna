/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef SelectMuons_H_
#define SelectMuons_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "HowtoExtendAnalysisTop/Event.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"
#include "xAODMuon/MuonContainer.h"
#include <unordered_map>

class SelectMuons:public top::EventSelectorBase {

 public:

  SelectMuons(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectMuons();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:
  bool m_doSFSystematics;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_muons;
  std::string m_params;


};

#endif
