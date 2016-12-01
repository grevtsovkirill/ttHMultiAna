#ifndef TTHMULTILEPTONLOOSEEVENTSAVER_H_
#define TTHMULTILEPTONLOOSEEVENTSAVER_H_

// Trigger
#include "TrigDecisionTool/TrigDecisionTool.h"

// CP tools
#include "AsgTools/ToolHandle.h"
#include "ElectronPhotonSelectorTools/AsgElectronChargeIDSelectorTool.h"
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "JetInterface/IJetSelector.h"
#include "PileupReweighting/PileupReweightingTool.h"
#include "TauAnalysisTools/TauSelectionTool.h"
#include "AssociationUtils/ToolBox.h"
#include "AssociationUtils/IOverlapRemovalTool.h"

// xAOD
#include "xAODEgamma/EgammaxAODHelpers.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTruth/xAODTruthHelpers.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODJet/JetContainer.h"
#include "xAODTau/TauJetContainer.h"

//Isolation
#include "IsolationSelection/IsolationSelectionTool.h"

//Sherpa 2.2 reweight
#include "PMGTools/PMGSherpa22VJetsWeightTool.h"

// Local and Top analysis
#include "TopAnalysis/EventSaverFlatNtuple.h"
#include "TopCorrections/ScaleFactorRetriever.h"
#include "TopDataPreparation/SampleXsection.h"
#include "ttHMultilepton/TreeAssist.h"
#include "ttHMultilepton/TruthSelector.h"
#include "ttHMultilepton/Lepton.h"
#include "ttHMultilepton/Tau.h"
#include "ttHMultilepton/Variables.h"
#include "ttHMultilepton/TruthMatchAlgo.h"
#include "ttHMultilepton/ClassifyHF.h"

//root
#include <TH1F.h>
#include <TString.h>

using namespace xAOD;
using namespace ttHMultilepton;
using CP::IsolationSelectionTool;
using CP::MuonSelectionTool;
using TauAnalysisTools::TauSelectionTool;

class ttHMultileptonLooseEventSaver : public top::EventSaverFlatNtuple {
 friend class ttHMultilepton::Variables;
 friend class ttHMultilepton::ClassifyHF;
 public:
  //Default - so root can load based on a name
  ttHMultileptonLooseEventSaver();

  //Default - so we can clean up
  ~ttHMultileptonLooseEventSaver();

  //Run once at the start of the job
  virtual void initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches);

  //Keep the asg::AsgTool happy
  virtual StatusCode initialize(){return StatusCode::SUCCESS;}

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
  // here we just remove the objects from the containers
  void OverlapRemoval_ContOnly(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<JetContainer>& goodJet, std::shared_ptr<TauJetContainer>& goodTau, bool fillCutflow);
  void CopyLeptons(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu);
  void CopyJets(std::shared_ptr<xAOD::JetContainer>& goodJet);
  void CopyTaus(std::shared_ptr<xAOD::TauJetContainer>& goodTau);
  void CheckIsBlinded();
  void CopyHT(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<xAOD::JetContainer>& goodJet, std::shared_ptr<xAOD::TauJetContainer>& goodTau);
  void MakeJetIndices(const std::shared_ptr<xAOD::JetContainer>& goodJets, const xAOD::JetContainer& allJets);
  std::string betterBtagNamedSyst (const std::string WP);

 private:
  ///The file where everything goes
  TFile* m_outputFile;

  //unique sys names for selected object containers
  std::string m_sysName;
  std::shared_ptr<top::TopConfig> m_config;
  bool m_doSystematics;
  bool m_doSFSystematics;

  TH1* m_eleCutflow;
  TH1* m_muCutflow;
  TH1* m_jetCutflow;
  TH1* m_tauCutflow;

  ///Scale factors
  std::unique_ptr<top::ScaleFactorRetriever> m_sfRetriever;

  ToolHandle<Trig::TrigDecisionTool>     m_trigDecTool;
  ToolHandle<CP::IPileupReweightingTool> m_purwtool;
  ToolHandle<IJetSelector>               m_jetCleaningToolLooseBad;
  AsgElectronChargeIDSelectorTool        m_electronChargeIDLoose;
  AsgElectronChargeIDSelectorTool        m_electronChargeIDMedium;
  AsgElectronChargeIDSelectorTool        m_electronChargeIDTight;
  MuonSelectionTool                      muonSelection;
  IsolationSelectionTool                 iso_1;
  ttH::TruthSelector                     truthSelector;
  TauSelectionTool                       m_tauSelectionEleOLR;
  // OR tools: 0 = e/mu only; 1 = nominal; 2 = all but tau;
  ORUtils::ToolBox                       m_ORtoolBox[3];
  asg::AnaToolHandle<ORUtils::IOverlapRemovalTool> m_overlapRemovalTool[3];

  //decorate all the things in all the sys
  SG::AuxElement::Decorator< char >* m_decor_ttHpassOVR;
  SG::AuxElement::Decorator< char >* m_decor_ttHpassTauOVR;

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
  void CopyMuon(    xAOD::Muon&,     ttHMultilepton::Lepton&);
  void CopyTau(     xAOD::TauJet&,   ttHMultilepton::Tau&);
  void doEventSFs();
  double relativeSF(double variation, double nominal);

  //some event weights
  double m_mcWeight;
  double m_pileup_weight;
  double m_pileup_weight_UP;
  double m_pileup_weight_DOWN;
  //btag SF weights
  double m_bTagSF_weight;
  double m_bTagSF77_weight;
  double m_bTagSF85_weight;
  double m_bTagSF60_weight;
  std::vector<float> m_weight_bTagSF_70_eigen_B_up;
  std::vector<float> m_weight_bTagSF_70_eigen_B_down;
  std::vector<float> m_weight_bTagSF_70_eigen_C_up;
  std::vector<float> m_weight_bTagSF_70_eigen_C_down;
  std::vector<float> m_weight_bTagSF_70_eigen_Light_up;
  std::vector<float> m_weight_bTagSF_70_eigen_Light_down;
  std::unordered_map<std::string, float> m_weight_bTagSF_70_eigen_Others_up;
  std::unordered_map<std::string, float> m_weight_bTagSF_70_eigen_Others_down;
  /* double m_weight_bTagSF_70_extrapolation_up; */
  /* double m_weight_bTagSF_70_extrapolation_down; */
  /* double m_weight_bTagSF_70_extrapolation_from_charm_up; */
  /* double m_weight_bTagSF_70_extrapolation_from_charm_down; */
  // JVT SF weights
  double m_JVT_weight;
  double m_JVT_weight_UP;
  double m_JVT_weight_DOWN;

  //event info
  unsigned long long m_eventNumber;
  uint32_t m_runNumber;
  unsigned int m_mcChannelNumber;
  float m_mu;
  float m_mu_unc;
  float m_mu_ac;
  ULong64_t m_pu_hash;
  int m_pvNumber;
  int m_puNumber;
  const xAOD::Vertex* m_pv;
  //use with care, don't mix MC and data in same job
  bool m_isMC;
  int m_runYear;
  SampleXsection m_sampleXsection;

  // Truth matching
  ttHMultilepton::TruthMatchAlgo* m_truthMatchAlgo;

  //ttbar HF classification
  int m_HF_Classification;

  //met
  float m_met_met;
  float m_met_phi;
  float m_met_sumet;
  float MET_softTrk_et;
  float MET_softTrk_phi;
  float MET_softClus_et;
  float MET_softClus_phi;

  // MET Truth
  float m_truthMET_px;
  float m_truthMET_py;
  float m_truthMET_phi;
  float m_truthMET_sumet;


  // leptons to save
  Lepton m_leptons[LEPTON_ARR_SIZE];
  Tau m_taus[TAU_ARR_SIZE];
  ttHMultilepton::Variables* m_variables;

  //ttHF classification
  ttHMultilepton::ClassifyHF* m_classifyttbarHF;

  //sherpa RW
  ToolHandle<PMGTools::PMGSherpa22VJetsWeightTool> m_sherpaRW;

  //MC
  int   m_higgsMode;
  const xAOD::TruthParticle* m_higgs;
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
  std::vector<int>   m_trjet_Wcount, m_trjet_Zcount, m_trjet_Hcount, m_trjet_Tcount;

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
    { top::topSFSyst::MU_SF_ID_STAT_LOWPT_UP, "MU_SF_ID_STAT_LOWPT_UP" },
    { top::topSFSyst::MU_SF_ID_STAT_LOWPT_DOWN, "MU_SF_ID_STAT_LOWPT_DOWN" },
    { top::topSFSyst::MU_SF_ID_SYST_LOWPT_UP, "MU_SF_ID_SYST_LOWPT_UP" },
    { top::topSFSyst::MU_SF_ID_SYST_LOWPT_DOWN, "MU_SF_ID_SYST_LOWPT_DOWN" },
  };
  // names tau SFs
  std::map<top::topSFSyst, std::string> m_tau_sf_names{
      { top::topSFSyst::nominal, "nominal" },
      { top::topSFSyst::TAU_SF_ELEOLR_TOTAL_UP,   "TAU_SF_ELEOLR_TOTAL_UP"  },
      { top::topSFSyst::TAU_SF_ELEOLR_TOTAL_DOWN, "TAU_SF_ELEOLR_TOTAL_DOWN"},
      { top::topSFSyst::TAU_SF_JETID_TOTAL_UP,	  "TAU_SF_JETID_TOTAL_UP"   },
      { top::topSFSyst::TAU_SF_JETID_TOTAL_DOWN,  "TAU_SF_JETID_TOTAL_DOWN" },
      { top::topSFSyst::TAU_SF_RECO_TOTAL_UP,	  "TAU_SF_RECO_TOTAL_UP"    },
      { top::topSFSyst::TAU_SF_RECO_TOTAL_DOWN,   "TAU_SF_RECO_TOTAL_DOWN"  },
	};

  TH1F * h_decayMode;

  #ifndef __CINT__
  std::vector<ScalarWrapperCollection> vec_scalar_wrappers;
  std::vector<VectorWrapperCollection> vec_electron_wrappers;
  std::vector<VectorWrapperCollection> vec_muon_wrappers;
  std::vector<VectorWrapperCollection> vec_jet_wrappers;
  std::vector<VectorWrapperCollection> vec_tau_wrappers;
  std::vector<VectorWrapperCollection> vec_vtx_wrappers;
  #endif

  ClassDef(ttHMultileptonLooseEventSaver, 0);
};



#endif
