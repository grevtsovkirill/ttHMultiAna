/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef DecorateTaus_H_
#define DecorateTaus_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "HowtoExtendAnalysisTop/Event.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODTracking/VertexContainer.h"
#include <unordered_map>
#include "IsolationSelection/IsolationSelectionTool.h"
#include "TauAnalysisTools/TauSelectionTool.h"

class DecorateTaus:public top::EventSelectorBase {

 public:

  DecorateTaus(std::string params, std::shared_ptr<top::TopConfig> config);
  ~DecorateTaus();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  std::string name() const override;
  ttHMLAsgHelper* m_asgHelper;
 private:
  TauAnalysisTools::TauSelectionTool                       m_tauSelectionEleOLR;
  TauAnalysisTools::TauSelectionTool                       m_tauSelectionEleBDT;
  TauAnalysisTools::TauSelectionTool                       m_tauSelectionMuonOLR;
  void decoratetau(const top::Event & event)const;
  CP::IsolationSelectionTool                 iso_1;
  mutable const xAOD::VertexContainer* m_vertices;
  mutable const xAOD::Vertex* m_pv;
  mutable int m_pvNumber;
  mutable int m_puNumber;
  bool m_doSFSystematics;
  mutable int ntaus;
  std::shared_ptr<top::TopConfig> m_config;
  mutable const top::Event* m_event;
 // std::string name;
  std::string m_taus;
  std::string m_params;


};

#endif

