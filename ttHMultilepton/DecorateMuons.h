/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef DecorateMuons_H_
#define DecorateMuons_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTracking/VertexContainer.h"
#include <unordered_map>
#include "IsolationSelection/IsolationSelectionTool.h"
#include "ElectronPhotonSelectorTools/AsgElectronChargeIDSelectorTool.h"

class DecorateMuons:public top::EventSelectorBase {

 public:

  DecorateMuons(std::string params, std::shared_ptr<top::TopConfig> config);
  ~DecorateMuons();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:

  CP::IsolationSelectionTool                 iso_1;
  void DecorateMu(const xAOD::MuonContainer& orig);
  mutable const xAOD::VertexContainer* m_vertices;
  mutable const xAOD::Vertex* m_pv;
  mutable int m_pvNumber;
  mutable int m_puNumber;
  bool m_doSFSystematics;
  bool m_isRemote;
  mutable int nmuon;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_muons;
  std::string m_params;


};

#endif

