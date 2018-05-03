/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef SelectElectrons_H_
#define SelectElectrons_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include <unordered_map>

class SelectElectrons:public top::EventSelectorBase {

 public:

  SelectElectrons(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectElectrons();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:
  bool m_doSFSystematics;
  bool m_isRemote;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  mutable int nelec2;
  std::string m_electrons;
  std::string m_params;

};

#endif
