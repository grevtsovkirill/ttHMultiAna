
/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef DecorateElectrons_H_
#define DecorateElectrons_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODTracking/VertexContainer.h"
#include <unordered_map>
#include "IsolationSelection/IsolationSelectionTool.h"
#include "ElectronPhotonSelectorTools/AsgElectronChargeIDSelectorTool.h"

class DecorateElectrons:public top::EventSelectorBase {

 public:

  DecorateElectrons(std::string params, std::shared_ptr<top::TopConfig> config);
  ~DecorateElectrons();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 

 private:
  AsgElectronChargeIDSelectorTool        m_electronChargeIDLoose;
  AsgElectronChargeIDSelectorTool        m_electronChargeIDMedium;
  AsgElectronChargeIDSelectorTool        m_electronChargeIDTight;
  CP::IsolationSelectionTool                 iso_1;
  void decorateel(const xAOD::ElectronContainer& orig);
  mutable const xAOD::VertexContainer* m_vertices;
  mutable const xAOD::Vertex* m_pv;
  mutable int m_pvNumber;
  mutable int m_puNumber;
  bool m_doSFSystematics;
  bool m_isRemote;
  mutable int nelec;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_electrons;
  std::string m_params;
  

};

#endif
