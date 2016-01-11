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
#include "TopCorrections/ScaleFactorCalculator.h"
#include "ttHMultilepton/TreeAssist.h"
#include "ttHMultilepton/TruthSelector.h"
#include "ttHMultilepton/Lepton.h"
#include "ttHMultilepton/Tau.h"
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
 friend class ttHMultilepton::Variables;
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
  void CopyHT(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<xAOD::JetContainer>& goodJet, std::shared_ptr<xAOD::TauJetContainer>& goodTau);
  
 private:
  ///The file where everything goes
  TFile* m_outputFile;

  //unique sys names for selected object containers
  std::string m_sysName;
  std::shared_ptr<top::TopConfig> m_config;
  bool m_doSystematics;
  
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

  // utility functions
  void CopyElectron(xAOD::Electron&, ttHMultilepton::Lepton&);
  void CopyMuon(xAOD::Muon&, ttHMultilepton::Lepton&, CP::MuonSelectionTool&);
  void doEventSFs();
  
  //some event weights
  double m_mcWeight;
  double m_pileup_weight;
  double m_pileup_weight_UP;
  double m_pileup_weight_DOWN;
  double m_leptonTrigSF_weight;
  //btag SF weights
  double m_bTagSF_weight;
  std::vector<float> m_weight_bTagSF_77_eigen_B_up;
  std::vector<float> m_weight_bTagSF_77_eigen_B_down;
  std::vector<float> m_weight_bTagSF_77_eigen_C_up;
  std::vector<float> m_weight_bTagSF_77_eigen_C_down;
  std::vector<float> m_weight_bTagSF_77_eigen_Light_up;
  std::vector<float> m_weight_bTagSF_77_eigen_Light_down;
  double m_weight_bTagSF_77_extrapolation_up;
  double m_weight_bTagSF_77_extrapolation_down;
  double m_weight_bTagSF_77_extrapolation_from_charm_up;
  double m_weight_bTagSF_77_extrapolation_from_charm_down;
  //tau SF weights
  double m_weight_tauSF;
  double m_weight_tauSF_ELEOLR_UP;
  double m_weight_tauSF_ELEOLR_DOWN;
  double m_weight_tauSF_JETID_UP;
  double m_weight_tauSF_JETID_DOWN;
  double m_weight_tauSF_RECO_UP;
  double m_weight_tauSF_RECO_DOWN;

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
  Tau m_taus[TAU_ARR_SIZE];
  ttHMultilepton::Variables* m_variables;
 
  //MC  
  int m_higgsMode;
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

  // for names of lepton SFs
  std::map<top::topSFSyst, std::string> m_lep_sf_names{
    { top::topSFSyst::nominal, "nominal" },
    { top::topSFSyst::EL_SF_Trigger_UP, "EL_SF_Trigger_UP" },
    { top::topSFSyst::EL_SF_Trigger_DOWN, "EL_SF_Trigger_DOWN" },
    { top::topSFSyst::EL_SF_Reco_UP, "EL_SF_Reco_UP" },
    { top::topSFSyst::EL_SF_Reco_DOWN, "EL_SF_Reco_DOWN" },
    { top::topSFSyst::EL_SF_ID_UP, "EL_SF_ID_UP" },
    { top::topSFSyst::EL_SF_ID_DOWN, "EL_SF_ID_DOWN" },
    { top::topSFSyst::EL_SF_Isol_UP, "EL_SF_Isol_UP" },
    { top::topSFSyst::EL_SF_Isol_DOWN, "EL_SF_Isol_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_UP, "MU_SF_Trigger_UP" },
    { top::topSFSyst::MU_SF_Trigger_DOWN, "MU_SF_Trigger_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_STAT_UP, "MU_SF_Trigger_STAT_UP" },
    { top::topSFSyst::MU_SF_Trigger_STAT_DOWN, "MU_SF_Trigger_STAT_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_SYST_UP, "MU_SF_Trigger_SYST_UP" },
    { top::topSFSyst::MU_SF_Trigger_SYST_DOWN, "MU_SF_Trigger_SYST_DOWN" },
    { top::topSFSyst::MU_SF_ID_STAT_UP, "MU_SF_ID_STAT_UP" },
    { top::topSFSyst::MU_SF_ID_STAT_DOWN, "MU_SF_ID_STAT_DOWN" },
    { top::topSFSyst::MU_SF_ID_SYST_UP, "MU_SF_ID_SYST_UP" },
    { top::topSFSyst::MU_SF_ID_SYST_DOWN, "MU_SF_ID_SYST_DOWN" },
    { top::topSFSyst::MU_SF_Isol_STAT_UP, "MU_SF_Isol_STAT_UP" },
    { top::topSFSyst::MU_SF_Isol_STAT_DOWN, "MU_SF_Isol_STAT_DOWN" },
    { top::topSFSyst::MU_SF_Isol_SYST_UP, "MU_SF_Isol_SYST_UP" },
    { top::topSFSyst::MU_SF_Isol_SYST_DOWN, "MU_SF_Isol_SYST_DOWN" },
    { top::topSFSyst::MU_SF_TTVA_STAT_UP, "MU_SF_TTVA_STAT_UP" },
    { top::topSFSyst::MU_SF_TTVA_STAT_DOWN, "MU_SF_TTVA_STAT_DOWN" },
    { top::topSFSyst::MU_SF_TTVA_SYST_UP, "MU_SF_TTVA_SYST_UP" },
    { top::topSFSyst::MU_SF_TTVA_SYST_DOWN, "MU_SF_TTVA_SYST_DOWN" },
  };

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
