#ifndef TTHMULTILEPTONLOOSEEVENTSAVER_H_
#define TTHMULTILEPTONLOOSEEVENTSAVER_H_


// Trigger
#include "TrigConfxAOD/xAODConfigTool.h"
#include "TrigDecisionTool/TrigDecisionTool.h"

// CP tools
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "JetSelectorTools/JetCleaningTool.h"
#include "PileupReweighting/PileupReweightingTool.h"
#include "AsgTools/ToolHandle.h"
#include "TauAnalysisTools/TauEfficiencyCorrectionsTool.h"

// xAOD
#include "xAODEgamma/EgammaxAODHelpers.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTruth/xAODTruthHelpers.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODJet/JetContainer.h"
#include "xAODTau/TauJetContainer.h"

//Isolation
#include "IsolationSelection/IsolationSelectionTool.h"

// Local and Top analysis
#include "TopAnalysis/EventSaverFlatNtuple.h"
#include "TopCorrections/ScaleFactorRetriever.h"
#include "ttHMultilepton/TreeAssist.h"
#include "ttHMultilepton/TruthSelector.h"
#include "ttHMultilepton/Lepton.h"
#include "ttHMultilepton/Variables.h"

//root
#include <TH1F.h>
#include <TString.h>

using namespace Trig;
using namespace TrigConf;
using namespace xAOD;
using namespace CP;
using namespace ttHMultilepton;
using TauAnalysisTools::TauEfficiencyCorrectionsTool;
using TauAnalysisTools::TauSelectionTool;

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

  void saveTruthEvent();

  // IGNORE
  void saveParticleLevelEvent(const top::ParticleLevelEvent& plEvent);

  void finalize();

  void Decorate(const top::Event& event);
  std::shared_ptr<xAOD::ElectronContainer> SelectElectrons(const top::Event& event);
  std::shared_ptr<xAOD::MuonContainer> SelectMuons(const top::Event& event);
  std::shared_ptr<xAOD::JetContainer> SelectJets(const top::Event& event);
  std::shared_ptr<xAOD::TauJetContainer> SelectTaus(const top::Event& event);
  void OverlapRemoval(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<JetContainer>& goodJet, std::shared_ptr<TauJetContainer>& goodTau, bool fillCutflow);
  void CopyLeptons(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu);
  void CopyJets(std::shared_ptr<xAOD::JetContainer>& goodJet);
  void CopyTaus(std::shared_ptr<xAOD::TauJetContainer>& goodTau);
  void CheckIsBlinded();
  
 private:
  ///The file where everything goes
  TFile* m_outputFile;

  TH1* m_eleCutflow;
  TH1* m_muCutflow;
  TH1* m_jetCutflow;
  TH1* m_tauCutflow;

  ///Scale factors
  std::unique_ptr<top::ScaleFactorRetriever> m_sfRetriever;

  xAODConfigTool                         configTool;
  TrigDecisionTool                       trigDecTool;
  MuonSelectionTool                      muonSelection;
  JetCleaningTool*                       cleaningTool;
  IsolationSelectionTool                 iso_1;
  ttH::TruthSelector                     truthSelector;
  //  ToolHandle<CP::IPileupReweightingTool>     m_purwtool;
  //ToolHandle<IPileupReweightingTool>     m_purwtool;
  PileupReweightingTool*                 m_purwtool;
  TauEfficiencyCorrectionsTool           m_tauEffTool;
  TauSelectionTool                       m_tauSelectionEleOLR;

  //for convenience of use with Wrap stuff
  const VertexContainer* m_vertices;
  const EventInfo*       m_eventInfo;
  
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
  double m_leptonTrigSF_weight;

  //event info
  unsigned int m_eventNumber;
  unsigned int m_runNumber;
  unsigned int m_mcChannelNumber;
  float m_mu;
  float m_mu_unc;
  float m_mu_ac;
  ULong64_t m_pu_hash;
  int m_pvNumber;
  int m_puNumber;
  //use with care, don't mix MC and data in same job
  bool m_isMC;

  //met
  float m_met_met;
  float m_met_phi;

  // leptons to save
  Lepton m_leptons[LEPTON_ARR_SIZE];
  ttHMultilepton::Variables* m_variables;

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
  TString m_higgsMode;
  std::vector<float> m_mc_m;
  std::vector<float> m_mc_pt;
  std::vector<float> m_mc_eta;
  std::vector<float> m_mc_phi;
  std::vector<float> m_mc_e;
  std::vector<int>   m_mc_pdgId;
  std::vector<int>   m_mc_status;
  std::vector<int>   m_mc_barcode;

  std::vector<std::vector<int> >  m_mc_parents;
  std::vector<std::vector<int> >  m_mc_children;

  std::vector<float> m_PDFinfo_x1;
  std::vector<float> m_PDFinfo_x2;
  std::vector<int> m_PDFinfo_id1;
  std::vector<int> m_PDFinfo_id2;   
  std::vector<float> m_PDFinfo_scalePDF;
  std::vector<float> m_PDFinfo_pdf1;
  std::vector<float> m_PDFinfo_pdf2;

  std::vector<float> m_trjet_pt;
  std::vector<float> m_trjet_eta;
  std::vector<float> m_trjet_phi;
  std::vector<float> m_trjet_e;


  TH1F * h_decayMode;

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
