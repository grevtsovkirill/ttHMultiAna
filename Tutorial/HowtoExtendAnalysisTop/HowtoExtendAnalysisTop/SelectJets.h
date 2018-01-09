/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef SelectJets_H_
#define SelectJets_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "HowtoExtendAnalysisTop/Event.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"
#include "xAODJet/JetContainer.h"
#include <unordered_map>

class SelectJets:public top::EventSelectorBase {

 public:

  SelectJets(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectJets();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:

  std::shared_ptr<top::TopConfig> m_config;
 // std::string name;

  std::string m_params;


};

#endif
