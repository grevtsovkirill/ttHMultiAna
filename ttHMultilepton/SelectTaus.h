/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef SelectTaus_H_
#define SelectTaus_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "xAODTau/TauJetContainer.h"
#include <unordered_map>

class SelectTaus:public top::EventSelectorBase {

 public:

  SelectTaus(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectTaus();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:
  bool m_doSFSystematics;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_taus;
  std::string m_params;


};

#endif
