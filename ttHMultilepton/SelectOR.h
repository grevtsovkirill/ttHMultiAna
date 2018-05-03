/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef SelectOR_H_
#define SelectOR_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include <unordered_map>

class SelectOR:public top::EventSelectorBase {

 public:

  SelectOR(std::string params, std::shared_ptr<top::TopConfig> config);
  ~SelectOR();
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
  std::string m_OR_electrons;
  std::string m_OR_muons;
  std::string m_OR_jets;
  std::string m_OR_taus;
  std::string m_params;

  //void OverlapRemoval(DataVector<xAOD::Electron_v1>& goodEl, DataVector<xAOD::Muon_v1>& goodMu, DataVector<xAOD::Jet_v1>& goodJet, DataVector<xAOD::TauJet_v3>& goodTau, bool fillCutflow) const;
  
};

#endif

