/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef SelectJets_H_
#define SelectJets_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODJet/JetContainer.h"
#include <unordered_map>
#include "JetSelectorTools/JetCleaningTool.h"
class SelectJets:public top::EventSelectorBase {

 public:

  SelectJets(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectJets();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:
  ToolHandle<IJetSelector>               m_jetCleaningToolLooseBad;
  bool m_doSFSystematics;
  bool m_isRemote;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_jets;
  std::string m_params;

};

#endif
