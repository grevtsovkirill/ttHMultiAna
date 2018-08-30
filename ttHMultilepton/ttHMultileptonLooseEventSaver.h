/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef ttHMultilepton_ttHMultileptonLooseEventSaver_H
#define ttHMultilepton_ttHMultileptonLooseEventSaver_H

#include "TopAnalysis/EventSaverFlatNtuple.h"
#include "ttHMultilepton/Variables.h"
#include "TopAnalysis/EventSaverFlatNtuple.h"
#include "TopCorrections/ScaleFactorRetriever.h"
#include "TopDataPreparation/SampleXsection.h"
#include "TrigDecisionTool/TrigDecisionTool.h"
#include "PMGTools/PMGSherpa22VJetsWeightTool.h"
#include "PileupReweighting/PileupReweightingTool.h"
#include "MuonSelectorTools/MuonSelectionTool.h"
#include "JetInterface/IJetSelector.h"

#include "AssociationUtils/IOverlapRemovalTool.h"

#include "AssociationUtils/ToolBox.h"
//TriggerTools///
#include "ElectronEfficiencyCorrection/IAsgElectronEfficiencyCorrectionTool.h"
#include "MuonEfficiencyCorrections/MuonTriggerScaleFactors.h"
//#include "TriggerAnalysisInterfaces/ITrigGlobalEfficiencyCorrectionTool.h"
#include "TriggerAnalysisInterfaces/ITrigGlobalEfficiencyCorrectionTool.h"
#include "TrigGlobalEfficiencyCorrection/TrigGlobalEfficiencyCorrectionTool.h"
#include "MuonAnalysisInterfaces/IMuonTriggerScaleFactors.h"
#include "PATCore/PATCoreEnums.h"
//////
//#include "ttHMultilepton/TreeAssist.h"
#include "ttHMultilepton/TruthSelector.h"
#include "ttHMultilepton/Lepton.h"
#include "ttHMultilepton/Tau.h"
#include "ttHMultilepton/TreeAssist.h"
#include <TH1F.h>
#include <TString.h>
#include <random>
#include <algorithm>



using namespace ttHML;
using namespace xAOD;
//using CP::IsolationSelectionTool;
using CP::MuonSelectionTool;
//using TauAnalysisTools::TauSelectionTool;

extern TH1I* m_eleCutflow;
extern TH1I* m_muCutflow;
extern TH1I* m_jetCutflow;
extern TH1I* m_tauCutflow;

  class ttHMultileptonLooseEventSaver : public top::EventSaverFlatNtuple {
    public:
      ///-- Default constrcutor with no arguments - needed for ROOT --///
      ttHMultileptonLooseEventSaver();
      ///-- Destructor does nothing --///
      ~ttHMultileptonLooseEventSaver();
      
      ///-- initialize function for top::EventSaverFlatNtuple --///
      ///-- We will be setting up out custom variables here --///
      virtual void initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches) override;
      
      ///-- Keep the asg::AsgTool happy --///
      virtual StatusCode initialize() override {return StatusCode::SUCCESS;}      
      
      void finalize();
      ///-- saveEvent function for top::EventSaverFlatNtuple --///
      ///-- We will be setting our custom variables on a per-event basis --///
      virtual void saveEvent(const top::Event& event) override;
      void CopyLeptons(const xAOD::ElectronContainer& Electrons, const xAOD::MuonContainer& Muons);
      void CopyJets(const xAOD::JetContainer& Jets);
      void MakeJetIndices(const xAOD::JetContainer& goodJets,const xAOD::JetContainer& allJets);
      void CopyTaus(const xAOD::TauJetContainer& Taus);
      void CheckIsBlinded();
      void CopyHT(const xAOD::ElectronContainer& goodEl, const xAOD::MuonContainer& goodMu, const xAOD::JetContainer& goodJets, const xAOD::TauJetContainer& goodTaus);
      void MakeJetIndices(const std::shared_ptr<xAOD::JetContainer>& goodJets, const xAOD::JetContainer& allJets);
      int getNTruthJets(const xAOD::JetContainer jetColl);
      int getNInnerPix(const xAOD::Electron& el);
      int getNInnerPix(const xAOD::Muon& mu);
      template <class T> T getattr_truthJet(const xAOD::Jet &jet, std::string  attr) {
	      T attr_value = -99;
	      if (jet.isAvailable<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink")
			      && jet.auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink").isValid()) {
		      const xAOD::Jet* trthjet = *jet.auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink");
		      if(trthjet->pt() >10000) attr_value = trthjet->auxdataConst<T>(attr.c_str()); //10 GeV cut recommended for finding hard-scattering jet
	      }
	      return attr_value;
      }


      //extern TH1I* m_eleCutflow;// = new TH1I("m_eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
      //extern TH1I* m_muCutflow;// = new TH1I("m_muCutflow", "Muon cutflow", 10, 0.5, 10.5);
      //extern TH1I* m_jetCutflow;// = new TH1I("m_jetCutflow", "Jet cutflow", 10, 0.5, 10.5);
      //extern TH1I* m_tauCutflow;//  = new TH1I("m_tauCutflow", "Tau cutflow", 10, 0.5, 10.5);

      //std::shared_ptr<TH1I*> m_eleCutflow; // = new std::shared_ptr<TH1I*>("m_eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
      //std::shared_ptr<TH1I*> m_muCutflow; // = new TH1I("m_eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
      //std::shared_ptr<TH1I*> m_jetCutflow; // = new TH1I("m_eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
      //std::shared_ptr<TH1I*> m_tauCutflow; // = new TH1I("m_eleCutflow", "Electron cutflow", 10, 0.5, 10.5);

    //private:
      ///-- Some additional custom variables for the output --///
  ///The file where everything goes
      TFile* m_outputFile;

  //unique sys names for selected object containers
      std::string m_sysName;
      std::shared_ptr<top::TopConfig> m_config;
      bool m_doSystematics;
      bool m_doSFSystematics;

      //TH1* m_eleCutflow;
      //TH1* m_muCutflow;
      //TH1* m_jetCutflow;
      //TH1* m_tauCutflow;

  ///Scale factors
//      std::unique_ptr<top::ScaleFactorRetriever> m_sfRetriever;
	top::ScaleFactorRetriever* m_sfRetriever;


      ToolHandle<Trig::TrigDecisionTool>     m_trigDecTool;
      ToolHandle<CP::IPileupReweightingTool> m_purwtool;
      ToolHandle<IJetSelector>               m_jetCleaningToolLooseBad;
//  AsgElectronChargeIDSelectorTool        m_electronChargeIDLoose;
//  AsgElectronChargeIDSelectorTool        m_electronChargeIDMedium;
//  AsgElectronChargeIDSelectorTool        m_electronChargeIDTight;
      MuonSelectionTool                      muonSelection;
//  IsolationSelectionTool                 iso_1;
  ttH::TruthSelector                     truthSelector;
//  TauSelectionTool                       m_tauSelectionEleOLR;
//  TauSelectionTool                       m_tauSelectionEleBDT;
//  TauSelectionTool                       m_tauSelectionMuonOLR;
  // OR tools: 0 = e/mu only; 1 = nominal; 2 = all but tau;
      ORUtils::ToolBox                       m_ORtoolBox[3];
      asg::AnaToolHandle<ORUtils::IOverlapRemovalTool> m_overlapRemovalTool[3];
  
  //Trigger Scale Factors -- NEW -- 
  // --> Electrons
      ToolHandleArray<IAsgElectronEfficiencyCorrectionTool>                    m_electronEffToolsHandles;
      ToolHandleArray<IAsgElectronEfficiencyCorrectionTool>                    m_electronSFToolsHandles;
      std::vector<asg::AnaToolHandle<IAsgElectronEfficiencyCorrectionTool> >   m_electronToolsFactory; 
 // --> Muons
      ToolHandleArray<CP::IMuonTriggerScaleFactors>                            m_muonToolsHandles;
      std::vector<asg::AnaToolHandle<CP::IMuonTriggerScaleFactors> >           m_muonToolsFactory;
  //--> The Tool
    //asg::AnaToolHandle<ITrigGlobalEfficiencyCorrectionTool>                  m_trigGlobEffCorr;
    //TrigGlobalEfficiencyCorrectionTool*                  m_trigGlobEffCorr;
      std::vector<TrigGlobalEfficiencyCorrectionTool*>                 m_trigGlobEffCorr;

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
    // static function that prevents the unwanted creation of branches in any eventsaver using the tree manager
      static int getBranchStatus(top::TreeManager const *, std::string const & variableName);

  // utility functions
  void CopyElectron(const xAOD::Electron&, ttHML::Lepton&);
  void CopyMuon(const xAOD::Muon&,     ttHML::Lepton&);
  void CopyTau( const xAOD::TauJet&,   ttHML::Tau&);
  void doEventTrigSFs(const xAOD::ElectronContainer& Electrons, const xAOD::MuonContainer& Muons, const top::Event& event);
/*  void doEventTrigSFs(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, const top::Event& event);
  void doEventSFs_Helper(int ilep, bool tightIsLoose = false);
  void doEventSFs();*/
  double relativeSF(double variation, double nominal);
  std::string betterBtagNamedSyst (const std::string WP);
  void setBtagSFs_ForDL1(const top::Event& event);
  void setBtagSFs(const top::Event& event);

  //some event weights
  double m_mcWeight;
  std::vector<float> m_lhe3weights;
  double m_pileup_weight;
  double m_pileup_weight_UP;
  double m_pileup_weight_DOWN;
  //btag SF weights
  std::string m_bTagSF_default;
  double m_bTagSF_weight;
  double m_bTagSF60_weight;
  double m_bTagSF70_weight;
  double m_bTagSF77_weight;
  double m_bTagSF85_weight;
  double m_bTagSFContinuous_weight;
  std::vector<float> m_weight_bTagSF_eigen_B_up;
  std::vector<float> m_weight_bTagSF_eigen_B_down;
  std::vector<float> m_weight_bTagSF_eigen_C_up;
  std::vector<float> m_weight_bTagSF_eigen_C_down;
  std::vector<float> m_weight_bTagSF_eigen_Light_up;
  std::vector<float> m_weight_bTagSF_eigen_Light_down;
  std::unordered_map<std::string, float> m_weight_bTagSF_eigen_Others_up;
  std::unordered_map<std::string, float> m_weight_bTagSF_eigen_Others_down;
  std::string m_bTagSF_DL1;
  double m_bTagSF_weight_DL1;
  double m_bTagSF60_weight_DL1;
  double m_bTagSF70_weight_DL1;
  double m_bTagSF77_weight_DL1;
  double m_bTagSF85_weight_DL1;
  double m_bTagSFContinuous_weight_DL1;
  std::vector<float> m_weight_bTagSF_eigen_B_up_DL1;
  std::vector<float> m_weight_bTagSF_eigen_B_down_DL1;
  std::vector<float> m_weight_bTagSF_eigen_C_up_DL1;
  std::vector<float> m_weight_bTagSF_eigen_C_down_DL1;
  std::vector<float> m_weight_bTagSF_eigen_Light_up_DL1;
  std::vector<float> m_weight_bTagSF_eigen_Light_down_DL1;
  std::unordered_map<std::string, float> m_weight_bTagSF_eigen_Others_up_DL1;
  std::unordered_map<std::string, float> m_weight_bTagSF_eigen_Others_down_DL1;
  // JVT SF weights
  double m_JVT_weight;
  double m_JVT_weight_UP;
  double m_JVT_weight_DOWN;

  //event info
  unsigned long long m_eventNumber;
  uint32_t m_runNumber;
  unsigned int m_mcChannelNumber;
  char m_isAFII;
  float m_mu;
  float m_mu_unc;
  float m_mu_ac;
  ULong64_t m_pu_hash;
  int m_pvNumber;
  int m_puNumber;
  float m_vertex_density;
  float m_beam_posz;
  float m_beam_sigmaz;
  const xAOD::Vertex* m_pv;
  //use with care, don't mix MC and data in same job
  bool m_isMC;
  int m_runYear;
  SampleXsection m_sampleXsection;

  // Truth matching
  //ttHMultilepton::TruthMatchAlgo* m_truthMatchAlgo;

  // Truth Matrix element photon
  char m_hasMEphoton;
  char m_hasMEphoton_DRgt02_nonhad;
  /* char m_MEphoton_OLtty_keepEvent; */
  /* char m_MEphoton_OLtty_cat1; */
  /* char m_MEphoton_OLtty_cat2; */
  /* char m_MEphoton_OLtty_cat3; */
  /* char m_MEphoton_OLtty_cat4; */
  float m_MEphoton_e;
  float m_MEphoton_pt;
  float m_MEphoton_eta;
  float m_MEphoton_phi;
  int m_MEphoton_mother_pdgId;  
  float m_MEphoton_mother_pt;
  float m_MEphoton_mother_e;
  float m_MEphoton_mother_eta;
  float m_MEphoton_mother_phi;

  // ttbar HF, DLF, MLF classification
  int m_HF_Classification;
  int m_HF_ClassificationTop;
  int m_DLF_Classification;
  //int m_MLF_Classification;

  // met
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
 // ttHMultilepton::Variables* m_variables;

  // ttbar HF classification
 // ttHMultilepton::ClassifyHF* m_classifyttbarHF;

  //sherpa RW
  ToolHandle<PMGTools::PMGSherpa22VJetsWeightTool> m_sherpaRW;

  //MC
  int   m_higgsMode;
  const xAOD::TruthParticle* m_higgs;
  const xAOD::TruthParticle* m_top;
  const xAOD::TruthParticle* m_antitop;
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

  std::vector<float> m_PDFinfo_X1;
  std::vector<float> m_PDFinfo_X2;
  std::vector<int> m_PDFinfo_PDGID1;
  std::vector<int> m_PDFinfo_PDGID2;
  std::vector<float> m_PDFinfo_Q;
  std::vector<float> m_PDFinfo_XF1;
  std::vector<float> m_PDFinfo_XF2;
/*
  std::vector<float> m_trjet_pt;
  std::vector<float> m_trjet_eta;
  std::vector<float> m_trjet_phi;
  std::vector<float> m_trjet_e;
  std::vector<int>   m_trjet_Wcount, m_trjet_Zcount, m_trjet_Hcount, m_trjet_Tcount;
*/
  CP::SystematicSet dummy_nom;
  CP::SystematicSet dummy_elup;
  CP::SystematicSet dummy_eldo;
  CP::SystematicSet dummy_muup;
  CP::SystematicSet dummy_mudo;
  CP::SystematicSet dummy_musysup;
  CP::SystematicSet dummy_musysdo;
  CP::SystematicSet dummy_eleffup;
  CP::SystematicSet dummy_eleffdo;

      float m_randomNumber;
      float m_someOtherVariable;

      ttHML::Variables* m_ttHEvent;


      // for names of lepton trigger SFs for multi-trigger tool
      //std::map<CP::SystematicSet, std::string> m_lep_trigger_sf_names{ 
      std::vector< std::pair<CP::SystematicSet, std::string> >  m_lep_trigger_sf_names{
    	{ dummy_nom, "nominal" },
    	{ dummy_elup, "EL_SF_Trigger_UP" },
   		{ dummy_eldo, "EL_SF_Trigger_DOWN" },
	    { dummy_muup, "MU_SF_Trigger_STAT_UP" },
	    { dummy_mudo, "MU_SF_Trigger_STAT_DOWN" },
		{ dummy_musysup, "MU_SF_Trigger_SYST_UP" },
        { dummy_musysdo, "MU_SF_Trigger_SYST_DOWN" },
	    { dummy_eleffup, "EL_EFF_Trigger_UP" },
	    { dummy_eleffdo, "EL_EFF_Trigger_DOWN" }
	  }; 
  // for names of lepton SFs
  std::map<top::topSFSyst, std::string> m_lep_sf_names{
    { top::topSFSyst::nominal, "nominal" },
    { top::topSFSyst::EL_SF_Trigger_UP, "EL_SF_Trigger_UP" },
    { top::topSFSyst::EL_SF_Trigger_DOWN, "EL_SF_Trigger_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_STAT_UP, "MU_SF_Trigger_STAT_UP" },
    { top::topSFSyst::MU_SF_Trigger_STAT_DOWN, "MU_SF_Trigger_STAT_DOWN" }, // do not change the order up to this point to match m_lep_trigger_sf_names
    { top::topSFSyst::MU_SF_Trigger_SYST_UP, "MU_SF_Trigger_SYST_UP" },
    { top::topSFSyst::MU_SF_Trigger_SYST_DOWN, "MU_SF_Trigger_SYST_DOWN" },
    { top::topSFSyst::EL_SF_Reco_UP, "EL_SF_Reco_UP" },
    { top::topSFSyst::EL_SF_Reco_DOWN, "EL_SF_Reco_DOWN" },
    { top::topSFSyst::EL_SF_ID_UP, "EL_SF_ID_UP" },
    { top::topSFSyst::EL_SF_ID_DOWN, "EL_SF_ID_DOWN" },
    { top::topSFSyst::EL_SF_Isol_UP, "EL_SF_Isol_UP" },
    { top::topSFSyst::EL_SF_Isol_DOWN, "EL_SF_Isol_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_UP, "MU_SF_Trigger_UP" },
    { top::topSFSyst::MU_SF_Trigger_DOWN, "MU_SF_Trigger_DOWN" },
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
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP,   "TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP"  },
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN, "TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN"},
      { top::topSFSyst::TAU_SF_JETID_TOTAL_UP,    "TAU_SF_JETID_TOTAL_UP"   },
      { top::topSFSyst::TAU_SF_JETID_TOTAL_DOWN,  "TAU_SF_JETID_TOTAL_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_HIGHPT_UP,   "TAU_SF_JETID_HIGHPT_UP"  },
      { top::topSFSyst::TAU_SF_JETID_HIGHPT_DOWN, "TAU_SF_JETID_HIGHPT_DOWN"},
      { top::topSFSyst::TAU_SF_RECO_TOTAL_UP,     "TAU_SF_RECO_TOTAL_UP"    },
      { top::topSFSyst::TAU_SF_RECO_TOTAL_DOWN,   "TAU_SF_RECO_TOTAL_DOWN"  },
      { top::topSFSyst::TAU_SF_RECO_HIGHPT_UP,    "TAU_SF_RECO_HIGHPT_UP"   },
      { top::topSFSyst::TAU_SF_RECO_HIGHPT_DOWN,  "TAU_SF_RECO_HIGHPT_DOWN" },
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

      
      ///-- Tell RootCore to build a dictionary (we need this) --///
  //ClassDef(ttHMultileptonLooseEventSaver, 0);
  };


#endif

