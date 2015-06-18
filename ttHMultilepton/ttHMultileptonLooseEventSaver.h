#ifndef TTHMULTILEPTONLOOSEEVENTSAVER_H_
#define TTHMULTILEPTONLOOSEEVENTSAVER_H_

#include "TopAnalysis/EventSaverFlatNtuple.h"
#include "ttHMultilepton/TreeAssist.h"
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "xAODEgamma/EgammaxAODHelpers.h"
#include "xAODTracking/VertexContainer.h"
#include "TauAnalysisTools/TauTruthMatchingTool.h"

using namespace Trig;
using namespace TrigConf;
using namespace xAOD;
using namespace CP;

class ttHMultileptonLooseEventSaver : public top::EventSaverFlatNtuple {
 public:
  //Default - so root can load based on a name
  ttHMultileptonLooseEventSaver();
  
  //Default - so we can clean up
  ~ttHMultileptonLooseEventSaver();
  
  //Run once at the start of the job
  virtual void initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches);
  
  //Run for every event (in every systematic) that needs saving
  void saveEvent(const top::Event& event);

  // IGNORE
  virtual void saveParticleLevelEvent(const top::ParticleLevelEvent& plEvent);

  void finalize();
  
 private:
  ///The file where everything goes
  TFile* m_outputFile;

  xAODConfigTool configTool;
  TrigDecisionTool trigDecTool;
  MuonSelectionTool muonSelection;
  TauAnalysisTools::TauTruthMatchingTool tauTruthMatching;
  const VertexContainer* m_vertices;
  
  ///A simple way to write out branches, without having to worry about the type.
  std::vector<std::shared_ptr<top::TreeManager>> m_treeManagers;

  ///names of the passed / failed branches.
  std::vector<std::string> m_extraBranches;

  ///Decisions on if the event passed / failed a particular selection.
  std::vector<int> m_selectionDecisions;

  // Method for recording selection pass/fail branches in saveEvent()
  void recordSelectionDecision(const top::Event& event);

  //some event weights
  double m_mcWeight;
  double m_pileup_weight;

  //event info
  unsigned int m_eventNumber;
  unsigned int m_runNumber;
  unsigned int m_mcChannelNumber;
  float m_mu;
  float m_mu_ac;
  int m_pvNumber;
  int m_puNumber;

  //met
  float m_met_met;
  float m_met_phi;

  //trigger info
  //single e
  /*
  unsigned int HLT_e26_tight_iloose;
  unsigned int HLT_e26_lhtight_iloose;
  unsigned int HLT_e60_medium;
  unsigned int HLT_e60_lhmedium;
  unsigned int HLT_e24_tight_iloose;
  unsigned int HLT_e24_lhtight_iloose;

  unsigned int HLT_e24_tight_iloose_L1EM20VH;
  unsigned int HLT_e140_loose;
  unsigned int HLT_e24_lhtight_iloose_L1EM20VH;
  unsigned int HLT_e140_lhloose;

  //single mu
  unsigned int HLT_mu26_imedium;
  unsigned int HLT_mu50;
  unsigned int HLT_mu24_imedium;

  //dilepton
  //e-e
  unsigned int HLT_2e12_loose_L12EM10VH;
  unsigned int HLT_2e12_lhloose_L12EM10VH;

  //mu-mu
  unsigned int HLT_2mu14;
  unsigned int HLT_2mu10;

  //e-mu
  unsigned int HLT_e17_loose_mu14;
  unsigned int HLT_e17_lhloose_mu14;
  unsigned int HLT_e7_medium_mu24;
  unsigned int HLT_e7_lhmedium_mu24;

  //Associated pre-scales
  float HLT_e26_tight_iloose_PS;
  float HLT_e26_lhtight_iloose_PS;
  float HLT_e60_medium_PS;
  float HLT_e60_lhmedium_PS;
  float HLT_e24_tight_iloose_PS;
  float HLT_e24_lhtight_iloose_PS;
  float HLT_e24_tight_iloose_L1EM20VH_PS;
  float HLT_e140_loose_PS;
  float HLT_e24_lhtight_iloose_L1EM20VH_PS;
  float HLT_e140_lhloose_PS;
  float HLT_mu26_imedium_PS;
  float HLT_mu50_PS;
  float HLT_mu24_imedium_PS;
  float HLT_2e12_loose_L12EM10VH_PS;
  float HLT_2e12_lhloose_L12EM10VH_PS;
  float HLT_2mu14_PS;
  float HLT_2mu10_PS;
  float HLT_e17_loose_mu14_PS;
  float HLT_e17_lhloose_mu14_PS;
  float HLT_e7_medium_mu24_PS;
  float HLT_e7_lhmedium_mu24_PS;
  //end trigger
  */  
  //MC  
  std::vector<float> m_mc_m;
  std::vector<float> m_mc_pt;
  std::vector<float> m_mc_eta;
  std::vector<float> m_mc_phi;
  std::vector<float> m_mc_e;
  std::vector<int>   m_mc_pdgId;
  std::vector<int>   m_mc_status;
  std::vector<int>   m_mc_barcode;
  std::vector<int>   m_mc_parentPdgId;

  std::vector<float> m_PDFinfo_x1;
  std::vector<float> m_PDFinfo_x2;
  std::vector<int> m_PDFinfo_id1;
  std::vector<int> m_PDFinfo_id2;   
  std::vector<float> m_PDFinfo_scalePDF;
  std::vector<float> m_PDFinfo_pdf1;
  std::vector<float> m_PDFinfo_pdf2;

  #ifndef __CINT__ 
  std::vector<ScalarWrapperCollection> vec_scalar_wrappers;
  std::vector<VectorWrapperCollection> vec_electron_wrappers;
  std::vector<VectorWrapperCollection> vec_muon_wrappers;
  std::vector<VectorWrapperCollection> vec_jet_wrappers;
  std::vector<VectorWrapperCollection> vec_tau_wrappers;
  #endif

  ClassDef(ttHMultileptonLooseEventSaver, 0);
};

#endif
