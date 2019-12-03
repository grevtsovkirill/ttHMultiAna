/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEventSelectionTools/TreeManager.h"
#include "ttHMultilepton/Variables.h"
#include "AssociationUtils/OverlapRemovalInit.h"


#include "TopConfiguration/TopConfig.h"

#include "xAODCutFlow/CutBookkeeper.h"
#include "xAODCutFlow/CutBookkeeperContainer.h"

#include "TopConfiguration/ConfigurationSettings.h"
#include "TopConfiguration/SelectionConfigurationData.h"
#include "PathResolver/PathResolver.h"
#include "xAODMissingET/MissingET.h"
#include "xAODMissingET/MissingETContainer.h"
#include "TopEvent/EventTools.h"
#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <cmath>
#include <algorithm>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>

#include <TRandom3.h>

//Define global cutflow hists, so they can be accessed by selectors
TH1I* m_eleCutflow;
TH1I* m_muCutflow;
TH1I* m_jetCutflow;
TH1I* m_tauCutflow;

  ///-- Constrcutor --///
  ttHMultileptonLooseEventSaver::ttHMultileptonLooseEventSaver() :
    m_randomNumber(0.),
    m_someOtherVariable(0.),
    m_outputFile(nullptr),
    m_doSystematics(false),
    m_doSFSystematics(true),
    m_sfRetriever(nullptr),
    m_trigDecTool("Trig::TrigDecisionTool"),
    m_purwtool("CP::PileupReweightingTool"),
   // m_jetCleaningToolLooseBad("JetCleaningToolLooseBad"),
//    m_electronToolsFactory(0),
    //m_muonToolsHandles("MuonToolsHandles"),
//    m_muonToolsFactory(0),
    //m_trigGlobEffCorr(0),
    m_mcWeight(1.),
//    m_pileup_weight(1.),
    m_bTagSF_default("MV2c10_FixedCutBEff_70"),
    m_bTagSF_DL1("DL1_FixedCutBEff_70"),
    m_bTagSF_weight(1.),
    m_JVT_weight(1.),
    m_eventNumber(0),
    m_runNumber(0),
    m_mcChannelNumber(0),
    m_isAFII(0),
    m_mu(0),
    m_mu_unc(0),
    m_mu_ac(0),
    m_pu_hash(0),
    m_pvNumber(0),
    m_puNumber(0),
    m_vertex_density(-999.),
    m_beam_posz(-999),
    m_beam_sigmaz(-999),
    m_pv(nullptr),
    m_runYear(0),
    muonSelection("MuonSelection"),
    m_met_met(0.),
    m_met_phi(0.),
    m_met_sumet(0.),
    MET_softTrk_et(-999.0),
    MET_softTrk_phi(-999.0),
    MET_softClus_et(-999.0),
    MET_softClus_phi(-999.0),
    m_truthMET_px(-999.0),
    m_truthMET_py(-999.0),
    m_truthMET_phi(-999.0),
    m_truthMET_sumet(-1.0),
    m_sherpaRW("PMGSherpa22VJetsWeightTool"),
    m_higgs(nullptr),
    m_top(nullptr),
    m_antitop(nullptr),
//    dummy_nom("dummy"),
    dummy_elup("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up"),
    dummy_eldo("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down"),
    dummy_muup("MUON_EFF_TrigStatUncertainty__1up"),
    dummy_mudo("MUON_EFF_TrigStatUncertainty__1down"),
    dummy_musysup("MUON_EFF_TrigSystUncertainty__1up"),
    dummy_musysdo("MUON_EFF_TrigSystUncertainty__1down"),
    dummy_eleffup("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up"),
    dummy_eleffdo("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down")

  {
    branchFilters().push_back(std::bind(&getBranchStatus, std::placeholders::_1, std::placeholders::_2));
}
  

template<typename FCN>
struct function_traits : public function_traits<decltype(&FCN::operator())>
{};

template<typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>
{
  typedef ReturnType (*pointer)(Args...);
  typedef std::function<ReturnType(Args...)> function;
};

template<typename VEC, typename FCN, typename TM> void Wrap2(VEC& vec, FCN lambda, TM& systematicTree, const char* branch) {
  // cast away the crud from around the lambda
  //vec.push_back(new VectorWrapper(static_cast<typename function_traits<FCN>::pointer>(lambda), systematicTree, branch));
  vec.push_back(new VectorWrapper(static_cast<typename function_traits<FCN>::function>(lambda), systematicTree, branch));
}

template<typename VEC, typename FCN, typename TM> void WrapS(VEC& vec, FCN lambda, TM& systematicTree, const char* branch) {
  vec.push_back(new ScalarWrapper(static_cast<typename function_traits<FCN>::function>(lambda), systematicTree, branch));
}

  ///-- initialize - done once at the start of a job before the loop over events --///
  void ttHMultileptonLooseEventSaver::initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches)
  {

  top::EventSaverFlatNtuple::initialize(config, file, extraBranches);
  m_outputFile = file;
  m_extraBranches = extraBranches;
  m_selectionDecisions.resize(m_extraBranches.size());

  m_config = config;
  //m_classifyttbarHF = new ttHMultilepton::ClassifyHF("AntiKt4TruthJets");
  // dont mix MC and data in the same job
  m_isMC = config->isMC();

  // do we want to skim and slim?
  // configured with DynamicKeys in the cuts file
  auto* const settings = top::ConfigurationSettings::get();
  try {
    m_doSystematics = settings->value("DoSystematics") == "True";
    if(m_doSystematics) std::cout<<"SKIMMING AND SLIMMING FOR SYSTEMATICS"<<std::endl;
    else         std::cout<<"NO SKIM, NO SLIM"<<std::endl;
  }
  catch(std::exception& e) {
    m_doSystematics = false; //just to be very clear
    std::cout<<"NO SKIM, NO SLIM"<<std::endl;
  }

  //Cutflow histograms
  m_eleCutflow = new TH1I("m_eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
  std::cout << "setting bin names" << std::endl;
  int idx = 1;
  for (const auto& label : { "initial", "pt", "eta", "ident", "z0sinth", "d0sig", "iso", "e-#mu OR", "e-e OR"}) {
    m_eleCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_muCutflow = new TH1I("m_muCutflow", "Muon cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto& label : { "initial", "eta/qual", "pt", "z0sinth", "d0sig", "iso", "#mu-jet OR"}) {
    m_muCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_jetCutflow = new TH1I("m_jetCutflow", "Jet cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto& label : { "initial", "cleaning", "pt", "eta", "jvt", "pt-eta", "jet-e OR", "jet-#tau OR"}) {
    m_jetCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_tauCutflow = new TH1I("m_tauCutflow", "Tau cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto& label : { "initial", "charge", "ntracks", "eta", "jetbdt", "pt", "EleOLR", "#tau-e,#mu OR"}) {
    m_tauCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }

//Tools
  if (m_isMC){
    std::string tdpfile = PathResolverFindCalibFile("/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/AnalysisTop/TopDataPreparation/XSection-MC15-13TeV.data");
    top::check( m_sherpaRW.retrieve(), "Failed to retrieve PMGSherpa22VJetsWeightTool" );
    top::check( m_sherpaRW->setProperty("TruthJetContainer", "AntiKt4TruthJets"),
		"Failed to set TruthJetContainer of PMGSherpa22VJetsWeightTool" );
    top::check( m_sampleXsection.readFromFile(tdpfile.c_str()),
		"Failed to open AMI X-section file");
  }
  //std::vector<std::string> triggernames = config->allTriggers_Loose("triggers");
 // top::check( m_jetCleaningToolLooseBad.retrieve() , "Failed to retrieve JetCleaningToolLooseBad" );
//Muon Tools
  //top::check( muonSelection.setProperty("OutputLevel", MSG::VERBOSE),"muonSelection fails to set OutputLevel");
  top::check( muonSelection.setProperty( "MaxEta", (double)m_config->muonEtacut() ), "muonSelection tool could not set max eta");
  top::check( muonSelection.initialize(),"muonSelection tool fails to initialize");

  //prepare btag eigen vectors
  if (m_isMC) {
    m_weight_bTagSF_eigen_B_up      .resize(m_config->btagging_num_B_eigenvars(m_bTagSF_default) );
    m_weight_bTagSF_eigen_B_down    .resize(m_config->btagging_num_B_eigenvars(m_bTagSF_default) );
    m_weight_bTagSF_eigen_C_up      .resize(m_config->btagging_num_C_eigenvars(m_bTagSF_default) );
    m_weight_bTagSF_eigen_C_down    .resize(m_config->btagging_num_C_eigenvars(m_bTagSF_default) );
    m_weight_bTagSF_eigen_Light_up  .resize(m_config->btagging_num_Light_eigenvars(m_bTagSF_default) );
    m_weight_bTagSF_eigen_Light_down.resize(m_config->btagging_num_Light_eigenvars(m_bTagSF_default) );
    m_weight_bTagSF_eigen_B_up_DL1      .resize(m_config->btagging_num_B_eigenvars(m_bTagSF_DL1) );
    m_weight_bTagSF_eigen_B_down_DL1    .resize(m_config->btagging_num_B_eigenvars(m_bTagSF_DL1) );
    m_weight_bTagSF_eigen_C_up_DL1      .resize(m_config->btagging_num_C_eigenvars(m_bTagSF_DL1) );
    m_weight_bTagSF_eigen_C_down_DL1    .resize(m_config->btagging_num_C_eigenvars(m_bTagSF_DL1) );
    m_weight_bTagSF_eigen_Light_up_DL1  .resize(m_config->btagging_num_Light_eigenvars(m_bTagSF_DL1) );
    m_weight_bTagSF_eigen_Light_down_DL1.resize(m_config->btagging_num_Light_eigenvars(m_bTagSF_DL1) );
  }
  //

//m_sfRetriever = std::unique_ptr<top::ScaleFactorRetriever> ( new top::ScaleFactorRetriever( m_config ) );

	if(asg::ToolStore::contains<top::ScaleFactorRetriever>("top::ScaleFactorRetriever")){
	      m_sfRetriever = asg::ToolStore::get<top::ScaleFactorRetriever>("top::ScaleFactorRetriever");
        m_sfRetriever->setProperty("OutputLevel", MSG::ERROR).ignore();
	    }
	    else{
	      top::ScaleFactorRetriever* topSFR = new top::ScaleFactorRetriever("top::ScaleFactorRetriever");
	      top::check(asg::setProperty(topSFR, "config", m_config), "Failed to set config");
        top::check(asg::setProperty(topSFR,"OutputLevel", MSG::ERROR)," Failed to set output level");
	      top::check(topSFR->initialize(), "Failed to initalialise");
	      m_sfRetriever = topSFR;
	    }


  std::vector<std::array<std::string,5> > triggerKeys = { // <list of legs>, <list of tags>, <key in map file>, <PID WP>, <iso WP>
    // dielectron trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    {"e12_lhloose_L1EM10VH, e17_lhvloose_nod0,e24_lhvloose_nod0_L1EM20VH", "Signal", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH", "TightLLH", "isolFCTight"},
    // dielectron trigger, only for untagged electrons, configured wrt loose WP:
    {"e12_lhloose_L1EM10VH, e17_lhvloose_nod0, e24_lhvloose_nod0_L1EM20VH", "Baseline", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_2018_e24_lhvloose_nod0_L1EM20VH", "LooseAndBLayerLLH", "isolFCTight"},
    // e-mu trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    {"e17_lhloose, e17_lhloose_nod0", "Signal", "MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0", "TightLLH", "isolFCTight"},
    // e-mu trigger, only for untagged electrons, configured wrt loose WP:
    {"e17_lhloose, e17_lhloose_nod0", "Baseline", "MULTI_L_2015_e17_lhloose_2016_2018_e17_lhloose_nod0", "LooseAndBLayerLLH", "isolFCTight"}
  };
 int nTrig = -1;

  m_trigGlobEffCorr.resize(m_lep_trigger_sf_names.size());

  //for (unsigned int t=0; t<m_trigGlobEffCorr.size(); ++t)
   // m_trigGlobEffCorr[t]=nullptr;
  if (m_isMC){
for (const auto& systvar : m_lep_trigger_sf_names) {
    std::cout << "INFO INFO: Doing: " << systvar.second << std::endl;
    auto ivar = systvar.first;
    ++nTrig;
    std::map<std::string,std::string> legsPerTool;
    std::map<std::string,std::string> tagsPerTool;

    int nTools = -1;
    m_electronEffToolsHandles.clear();
    m_electronSFToolsHandles.clear();
    m_muonToolsHandles.clear();
  //  char* const rc = getenv("WorkDir_DIR");
    for(auto& kv : triggerKeys) // electron tool instances for each trigger leg
      for(int j=0;j<2;++j) // one tool instance for efficiencies, another for scale factors
	{
	  auto t = m_electronToolsFactory.emplace(m_electronToolsFactory.end(), "AsgElectronEfficiencyCorrectionTool/ElTrigEff_"+std::to_string(++nTools)+systvar.second);
    std::string filepath="ElectronEfficiencyCorrection/2015_2017/rel21.2/Consolidation_September2018_v1/trigger/"+ (std::string)(j?"efficiencySF.":"efficiency.") + kv[2] + "." + kv[3] + "_d0z0_v13_" + kv[4] + ".root";
	  std::vector<std::string> inputFiles;
	  inputFiles.push_back(filepath);
	  t->setProperty("CorrectionFileNameList",inputFiles).ignore();
	  t->setProperty("CorrelationModel","TOTAL").ignore();
	  t->setProperty("ForceDataType", (int)PATCore::ParticleDataType::Full).ignore();
    t->setProperty("OutputLevel", MSG::DEBUG).ignore();
	  top::check( t->initialize(), "TrigGlobalEfficiencyCorrectionTool:electronToolsFactory failed to initialize!" );
	  auto& handles = j? m_electronSFToolsHandles : m_electronEffToolsHandles;
	  handles.push_back(t->getHandle());
	  // Safer to retrieve the name from the final ToolHandle, it might be prefixed (by the parent tool name) when the handle is copied
	  std::string name = handles[handles.size()-1].name();
	  legsPerTool.emplace(name, kv[0]);
	  if(kv[1]!="") tagsPerTool.emplace(name, kv[1]);
	}

    if (systvar.second=="EL_SF_Trigger_UP" || systvar.second=="EL_SF_Trigger_DOWN") {
      for(auto& ettool : m_electronSFToolsHandles){
	if(ettool->applySystematicVariation(systvar.first) != CP::SystematicCode::Ok)
	  std::cout << "Unable to apply systematic variation " << systvar.second << std::endl;
      }
    }
    else if (systvar.second=="EL_EFF_Trigger_UP" || systvar.second=="EL_EFF_Trigger_DOWN") {
      for(auto& ettool : m_electronEffToolsHandles){
	if(ettool->applySystematicVariation(systvar.first) != CP::SystematicCode::Ok)
	  std::cout << "Unable to apply systematic variation " << systvar.second << std::endl;
      }
    }

	auto t = m_muonToolsFactory.emplace(m_muonToolsFactory.end());
	ASG_SET_ANA_TOOL_TYPE(*t, CP::MuonTriggerScaleFactors);
	t->setName("MuonTrigEff_"+std::to_string(++nTools)+systvar.second);
  t->setProperty("CalibrationRelease", "190129_Winter_r21").ignore();
    t->setProperty("useRel207", false).ignore();
	t->setProperty("MuonQuality", "Medium").ignore();
  t->setProperty("AllowZeroSF",true).ignore();
	top::check( t->initialize(), "TrigGlobalEfficiencyCorrectionTool:muonToolsFactory failed to initialize!");
	m_muonToolsHandles.push_back(t->getHandle());

    if (systvar.second=="MU_SF_Trigger_STAT_UP" || systvar.second=="MU_SF_Trigger_STAT_DOWN" || systvar.second=="MU_SF_Trigger_SYST_UP" || systvar.second=="MU_SF_Trigger_SYST_DOWN") {
      for(auto& mutool : m_muonToolsHandles){
	if(mutool->applySystematicVariation(systvar.first) != CP::SystematicCode::Ok)
	  std::cout << "Unable to apply systematic variation " << systvar.second << std::endl;
      }
    }


    // Configure the trigger SF tool: Nominal
    std::string trigglobname = "TrigGlobalEfficiencyCorrectionTool"+systvar.second;
    m_trigGlobEffCorr[nTrig] = new TrigGlobalEfficiencyCorrectionTool(trigglobname);
    m_trigGlobEffCorr[nTrig]->setProperty("OutputLevel", MSG::ERROR).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ElectronEfficiencyTools",m_electronEffToolsHandles).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ElectronScaleFactorTools",m_electronSFToolsHandles).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("MuonTools",m_muonToolsHandles).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ListOfLegsPerTool",legsPerTool).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ListOfTagsPerTool",tagsPerTool).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2015", " 2e12_lhloose_L12EM10VH || e17_lhloose_mu14 || mu18_mu8noL1").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2016", " 2e17_lhvloose_nod0 || e17_lhloose_nod0_mu14 || mu20_mu8noL1").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2017", " 2e24_lhvloose_nod0 || e17_lhloose_nod0_mu14 || mu22_mu8noL1").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2018", " 2e24_lhvloose_nod0 || e17_lhloose_nod0_mu14 || mu22_mu8noL1").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("LeptonTagDecorations", "Signal,Baseline").ignore();
    top::check( m_trigGlobEffCorr[nTrig]->initialize(), "TrigGlobalEfficiencyCorrectionTool failed to initialize!" );
    ////////////////////////// end Trigger SF tool
  }
}
    m_ttHEvent = new ttHML::Variables();

    ///-- Loop over the systematic TTrees and add the custom variables --///
    for (auto systematicTree :treeManagers()) {
      m_doSFSystematics = systematicTree->name() ==  m_config->systematicName(m_config->nominalHashValue());
       if(!m_isMC) m_doSFSystematics = false;


    systematicTree->makeOutputVariable(m_mcWeight,      "mcWeightOrg");
    systematicTree->makeOutputVariable(m_lhe3weights,   "mcEventWeights");
    systematicTree->makeOutputVariable(m_pileup_weight, "pileupEventWeight_090");
    systematicTree->makeOutputVariable(m_bTagSF_weight,   ("bTagSF_weight_"+m_bTagSF_default).c_str());
    systematicTree->makeOutputVariable(m_bTagSF60_weight, "MV2c10_60_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF70_weight, "MV2c10_70_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF77_weight, "MV2c10_77_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF85_weight, "MV2c10_85_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSFContinuous_weight, "MV2c10_Continuous_EventWeight");
    systematicTree->makeOutputVariable(m_JVT_weight,    "JVT_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF_weight_DL1,   ("bTagSF_weight_"+m_bTagSF_DL1).c_str());
    systematicTree->makeOutputVariable(m_bTagSF60_weight_DL1, "DL1_60_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF70_weight_DL1, "DL1_70_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF77_weight_DL1, "DL1_77_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF85_weight_DL1, "DL1_85_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSFContinuous_weight_DL1, "DL1_Continuous_EventWeight");

    if ( m_doSFSystematics && m_doSystematics) {
      //pileup
      systematicTree->makeOutputVariable(m_pileup_weight_UP,   "pileupEventWeight_UP");
      systematicTree->makeOutputVariable(m_pileup_weight_DOWN, "pileupEventWeight_DOWN");
//btag
      //B
      for( unsigned int i=0; i<m_config->btagging_num_B_eigenvars(m_bTagSF_default); ++i) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_default << "_B" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_B_up.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_B_down.at(i),
					   branchNameDown );
      }
      //C
      for( unsigned int i=0; i<m_config->btagging_num_C_eigenvars(m_bTagSF_default); ++i) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_default << "_C" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_C_up.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_C_down.at(i),
					   branchNameDown );
      }
      //Light
      for( unsigned int i=0; i<m_config->btagging_num_Light_eigenvars(m_bTagSF_default); ++i) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_default << "_Light" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Light_up.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Light_down.at(i),
					   branchNameDown );
      }
      //Others (extrapolation)
      for (auto name : m_config->btagging_namedSysts(m_bTagSF_default)) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_default << "_" << betterBtagNamedSyst(name);
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Others_up[name],
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Others_down[name],
					   branchNameDown );
      }
      for( unsigned int i=0; i<m_config->btagging_num_B_eigenvars(m_bTagSF_DL1); ++i) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_DL1 << "_B" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_B_up_DL1.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_B_down_DL1.at(i),
					   branchNameDown );
      }
      //C
      for( unsigned int i=0; i<m_config->btagging_num_C_eigenvars(m_bTagSF_DL1); ++i) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_DL1 << "_C" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_C_up_DL1.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_C_down_DL1.at(i),
					   branchNameDown );
      }
      //Light
      for( unsigned int i=0; i<m_config->btagging_num_Light_eigenvars(m_bTagSF_DL1); ++i) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_DL1 << "_Light" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Light_up_DL1.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Light_down_DL1.at(i),
					   branchNameDown );
      }
      //Others (extrapolation)
      for (auto name : m_config->btagging_namedSysts(m_bTagSF_DL1)) {
	std::stringstream branchName; branchName << "bTagSF_weight_" << m_bTagSF_DL1 << "_" << betterBtagNamedSyst(name);
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Others_up_DL1[name],
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_eigen_Others_down_DL1[name],
					   branchNameDown );
}
      //JVT
      systematicTree->makeOutputVariable(m_JVT_weight_UP,   "JVT_EventWeight_UP");
      systematicTree->makeOutputVariable(m_JVT_weight_DOWN, "JVT_EventWeight_DOWN");
    }

      if(!m_doSystematics) {
      //truth information
      systematicTree->makeOutputVariable(m_mc_m,           "m_truth_m");
      systematicTree->makeOutputVariable(m_mc_pt,          "m_truth_pt");
      systematicTree->makeOutputVariable(m_mc_eta,         "m_truth_eta");
      systematicTree->makeOutputVariable(m_mc_phi,         "m_truth_phi");
      systematicTree->makeOutputVariable(m_mc_e,           "m_truth_e");
      systematicTree->makeOutputVariable(m_mc_pdgId,       "m_truth_pdgId");
      systematicTree->makeOutputVariable(m_mc_status,      "m_truth_status");
      systematicTree->makeOutputVariable(m_mc_barcode,     "m_truth_barcode");
      systematicTree->makeOutputVariable(m_mc_parents,     "m_truth_parents");
      systematicTree->makeOutputVariable(m_mc_children,    "m_truth_children");


      //truth jets
      systematicTree->makeOutputVariable(m_trjet_pt,  "m_truth_jet_pt");
      systematicTree->makeOutputVariable(m_trjet_eta, "m_truth_jet_eta");
      systematicTree->makeOutputVariable(m_trjet_phi, "m_truth_jet_phi");
      systematicTree->makeOutputVariable(m_trjet_m,   "m_truth_jet_m");
      systematicTree->makeOutputVariable(m_trjet_Wcount,   "m_truth_jet_Wcount");
      systematicTree->makeOutputVariable(m_trjet_Zcount,   "m_truth_jet_Zcount");
      systematicTree->makeOutputVariable(m_trjet_Hcount,   "m_truth_jet_Hcount");
      systematicTree->makeOutputVariable(m_trjet_Tcount,   "m_truth_jet_Tcount");
      systematicTree->makeOutputVariable(m_trjet_BHandronCount,   "m_truth_jet_BHadronCount");
      systematicTree->makeOutputVariable(m_trjet_CHandronCount,   "m_truth_jet_CHadronCount");
      systematicTree->makeOutputVariable(m_trjet_ConeTruthLabelID,   "m_truth_jet_ConeTruthLabelID");
      systematicTree->makeOutputVariable(m_trjet_PartonTruthLabelID,   "m_truth_jet_PartonTruthLabelID");

      //truthEvent information
      systematicTree->makeOutputVariable(m_PDFinfo_X1,        "m_mcevt_pdf_X1");
      systematicTree->makeOutputVariable(m_PDFinfo_X2,        "m_mcevt_pdf_X2");
      systematicTree->makeOutputVariable(m_PDFinfo_PDGID1,    "m_mcevt_pdf_PDGID1");
      systematicTree->makeOutputVariable(m_PDFinfo_PDGID2,    "m_mcevt_pdf_PDGID2");
      systematicTree->makeOutputVariable(m_PDFinfo_Q,         "m_mcevt_pdf_Q");
      systematicTree->makeOutputVariable(m_PDFinfo_XF1,       "m_mcevt_pdf_XF1");
      systematicTree->makeOutputVariable(m_PDFinfo_XF2,       "m_mcevt_pdf_XF2");
    }


    systematicTree->makeOutputVariable(m_eventNumber, "EventNumber");
    systematicTree->makeOutputVariable(m_runNumber, "RunNumber");
    systematicTree->makeOutputVariable(m_runYear, "RunYear");
    systematicTree->makeOutputVariable(m_higgsMode,      "higgsDecayMode");
    systematicTree->makeOutputVariable(m_mcChannelNumber, "mc_channel_number");
    systematicTree->makeOutputVariable(m_isAFII, "mc_isAFII");
    systematicTree->makeOutputVariable(m_mu_unc, "averageIntPerXing_uncorr");
    systematicTree->makeOutputVariable(m_mu, "averageIntPerXing");
    systematicTree->makeOutputVariable(m_mu_ac, "actualIntPerXing");
    systematicTree->makeOutputVariable(m_pu_hash, "pileupHash");
    systematicTree->makeOutputVariable(m_pvNumber, "m_vxp_n");
    systematicTree->makeOutputVariable(m_puNumber, "m_vxpu_n");

    // Add extra variables for pileup studies
    systematicTree->makeOutputVariable(m_vertex_density, "m_vx_density");
    systematicTree->makeOutputVariable(m_beam_posz,      "m_beam_posz");
    systematicTree->makeOutputVariable(m_beam_sigmaz,    "m_beam_sigmaz");

    // Truth Matrix element photon
    systematicTree->makeOutputVariable(m_hasMEphoton, "m_hasMEphoton");
    systematicTree->makeOutputVariable(m_hasMEphoton_DRgt02_nonhad, "m_hasMEphoton_DRgt02_nonhad");
    systematicTree->makeOutputVariable(m_hasFSRPhotonLargeDeltaR, "m_hasFSRPhotonLargeDeltaR");
    systematicTree->makeOutputVariable(m_MEphoton_e, "m_MEphoton_e");
    systematicTree->makeOutputVariable(m_MEphoton_pt, "m_MEphoton_pt");
    systematicTree->makeOutputVariable(m_MEphoton_eta, "m_MEphoton_eta");
    systematicTree->makeOutputVariable(m_MEphoton_phi, "m_MEphoton_phi");
    systematicTree->makeOutputVariable(m_MEphoton_mother_pdgId, "m_MEphoton_mother_pdgId");
    systematicTree->makeOutputVariable(m_MEphoton_mother_e, "m_MEphoton_mother_e");
    systematicTree->makeOutputVariable(m_MEphoton_mother_pt, "m_MEphoton_mother_pt");
    systematicTree->makeOutputVariable(m_MEphoton_mother_eta, "m_MEphoton_mother_eta");
    systematicTree->makeOutputVariable(m_MEphoton_mother_phi, "m_MEphoton_mother_phi");

    //met
    systematicTree->makeOutputVariable(m_met_met, "MET_RefFinal_et");
    systematicTree->makeOutputVariable(m_met_phi, "MET_RefFinal_phi");
    systematicTree->makeOutputVariable(m_met_sumet, "MET_RefFinal_sumet");
    systematicTree->makeOutputVariable(MET_softTrk_et, "MET_RefFinal_softTrk_et");
    systematicTree->makeOutputVariable(MET_softTrk_phi, "MET_RefFinal_softTrk_phi");
    systematicTree->makeOutputVariable(MET_softClus_et, "MET_RefFinal_softClus_et");
    systematicTree->makeOutputVariable(MET_softClus_phi, "MET_RefFinal_softClus_phi");

    if(!m_doSystematics) {
      systematicTree->makeOutputVariable(m_truthMET_px, "MET_Truth_px");
      systematicTree->makeOutputVariable(m_truthMET_py, "MET_Truth_py");
      systematicTree->makeOutputVariable(m_truthMET_phi, "MET_Truth_phi");
      systematicTree->makeOutputVariable(m_truthMET_sumet, "MET_Truth_sumet");
    }



    //Event selection pass/fail branches
    int index(0);
    for (const auto& branchName : m_extraBranches) {
        m_selectionDecisions[index] = 0;
        systematicTree->makeOutputVariable(m_selectionDecisions[index], branchName);
        ++index;
    }


    for (size_t idx = 0; idx < LEPTON_ARR_SIZE; ++idx) {
      m_leptons[idx].BootstrapTree(systematicTree, idx);
    }
    for (size_t idx = 0; idx < TAU_ARR_SIZE; ++idx) {
      m_taus[idx].BootstrapTree(systematicTree, idx);
    }

    m_ttHEvent->BootstrapTree(systematicTree,this,m_doSFSystematics);
    }

  }

  ///-- saveEvent - run for every systematic and every event --///
  void ttHMultileptonLooseEventSaver::saveEvent(const top::Event& event)
  {
    m_ttHEvent->Clear();
    std::shared_ptr<ttHML::Variables> tthevt;
    if(event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
      tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
    }
if (m_config->saveOnlySelectedEvents() && !event.m_saveEvent){
    if(tthevt)tthevt->clearReco();
    return;
  }
  if(!m_config->saveOnlySelectedEvents()){
    top::EventSaverFlatNtuple::saveEvent(event);
    if(tthevt)tthevt->clearReco();
    return;
  }


  //unique name for selected containers
  std::size_t sysHash = event.m_hashValue;
  m_sysName = m_config->systematicName(sysHash);

  //SF systematics only in Nominal tree
  m_doSFSystematics = event.m_hashValue == m_config->nominalHashValue();
  if(!m_isMC) m_doSFSystematics = false;

  m_mcWeight = 1.;
  m_pileup_weight = 1.;
  m_mcChannelNumber = 0;
  m_isAFII = 0;

  if (top::isSimulation(event)){
    m_mcChannelNumber = event.m_info->mcChannelNumber();
    m_isAFII = m_config->isAFII();

    m_mcWeight        = event.m_info->mcEventWeight();
    // LHE3 weights
    //m_lhe3weights = (*event.m_truthEvent)[0]->weights();
    m_lhe3weights = event.m_info->mcEventWeights();
    if(m_sfRetriever){
      m_pileup_weight = m_sfRetriever->pileupSF(event);
      m_JVT_weight = m_sfRetriever->jvtSF(event,top::topSFSyst::nominal);
      //btag moved to own function

      //do sys weights only in "nominal" tree
      if( m_doSFSystematics ){

	      m_pileup_weight_UP = m_sfRetriever->pileupSF( event, +1 ); // up variation
	      m_pileup_weight_DOWN = m_sfRetriever->pileupSF( event, -1 ); // down variation
	      //normalise
	      m_pileup_weight_UP    = relativeSF(m_pileup_weight_UP,   m_pileup_weight);
	      m_pileup_weight_DOWN  = relativeSF(m_pileup_weight_DOWN, m_pileup_weight);
	      // JVT SF
	      m_JVT_weight_UP = m_sfRetriever->jvtSF(event,top::topSFSyst::JVT_UP);
      	m_JVT_weight_DOWN = m_sfRetriever->jvtSF(event,top::topSFSyst::JVT_DOWN);

	      //normalise
	      m_JVT_weight_UP   = relativeSF(m_JVT_weight_UP,  m_JVT_weight);
	      m_JVT_weight_DOWN = relativeSF(m_JVT_weight_DOWN,m_JVT_weight);

      } //end if isNominal
    } //end if m_sfRetriever
  } //end if isSimulation

 //event info
  m_eventNumber = event.m_info->eventNumber();
  m_runNumber = event.m_info->runNumber();
  
  m_mu_ac   = event.m_info->actualInteractionsPerCrossing();
  m_mu_unc  = event.m_info->averageInteractionsPerCrossing();

    if (m_config->isMC()) {
      m_mu = m_mu_unc;
     // m_mu_actual = m_mu_ac;
    }
    if (!m_config->isMC()) {
      // If we have the corrected mu value from pileup reweighting then save that
      // instead of mu value in (d)xAOD.
      if (event.m_info->isAvailable<float>("corrected_averageInteractionsPerCrossing")) m_mu = event.m_info->auxdataConst<float>("corrected_averageInteractionsPerCrossing");
      //if (event.m_info->isAvailable<float>("corrected_actualInteractionsPerCrossing")) m_mu_actual = event.m_info->auxdataConst<float>("corrected_actualInteractionsPerCrossing");
    }


  m_met_met = event.m_met->met();
  m_met_phi = event.m_met->phi();
  m_met_sumet = event.m_met->sumet();
  const xAOD::MissingETContainer *newMetContainer(nullptr);
  top::check( evtStore()->retrieve(newMetContainer, "MET_nominal"),"Failed to retrieve MET container");

  const xAOD::MissingET *softTrkMet = (*newMetContainer)["PVSoftTrk"];
  MET_softTrk_et = softTrkMet->met();
  MET_softTrk_phi = softTrkMet->phi();

  const xAOD::MissingET *softClusMet = (*newMetContainer)["SoftClus"];
  MET_softClus_et = softClusMet->met();
  MET_softClus_phi = softClusMet->phi();

  // Truth Matrix element photon
  m_hasMEphoton = false;
  m_hasMEphoton_DRgt02_nonhad = false;
  // m_MEphoton_OLtty_keepEvent = false;
  // m_MEphoton_OLtty_cat1 = false;
  // m_MEphoton_OLtty_cat2 = false;
  // m_MEphoton_OLtty_cat3 = false;
  // m_MEphoton_OLtty_cat4 = false;
  m_MEphoton_e = -10.;
  m_MEphoton_pt = -10.;
  m_MEphoton_eta = -10.;
  m_MEphoton_phi = -10.;
  m_MEphoton_mother_pdgId = 0;
  m_MEphoton_mother_e = -10.;
  m_MEphoton_mother_pt = -10.;
  m_MEphoton_mother_eta = -10.;
  m_MEphoton_mother_phi = -10.;

  bool found=false;
  float minDR = 999.9;
  m_hasFSRPhotonLargeDeltaR = false;
  std::vector<const xAOD::TruthParticle* > truleptons;
  //const xAOD::TruthParticle* truleptons= nullptr;
  if (event.m_truth != nullptr ) {
  for (const auto& leptons : *(event.m_truth)) {
    //if (leptons!=nullptr ){
      if((fabs(leptons->pdgId()) == 11 && leptons->status() == 1 && leptons->barcode()<2e5) || (fabs(leptons->pdgId()) == 13 && leptons->status() == 1 && leptons->barcode()<2e5) )truleptons.push_back(leptons);
    //}
  }
  //std::cout<<"--> nleptons= " <<truleptons.size()<<std::endl;
}
//&&  fabs(leptons->parent(0)->pdgId()) != 11)
//int g=0;
  if (event.m_truth != nullptr ) {
    for (const auto& particle : *(event.m_truth)) {
      int pdgId = 22; // look at photons
      if (particle!=nullptr && particle->parent(0)!=nullptr){
      if (fabs(particle->pdgId()) == pdgId
          && (particle->nParents()==0 || fabs(particle->parent(0)->pdgId()) != pdgId)) {// this particle is a photon
        int motherPdgId = 999;
        float motherPt = -1;
        const xAOD::TruthParticle* mother = nullptr;
        if (particle->nParents() > 0) {
          mother = particle->parent(0);  // i am interested in DR only of the mother
          motherPdgId = mother->pdgId();
          motherPt = mother->pt();
        }
        
        if (abs(motherPdgId) < 100 && particle->barcode() < 2e5 && particle->pt() > 0 && motherPt > 0) {
          m_hasMEphoton = true;
          if(particle->pt() > m_MEphoton_pt) {
            m_MEphoton_e = particle->e();
            m_MEphoton_pt = particle->pt();
            m_MEphoton_eta = particle->eta();
            m_MEphoton_phi = particle->phi();
            m_MEphoton_mother_pdgId = motherPdgId;
            m_MEphoton_mother_pt = motherPt;
            m_MEphoton_mother_e = mother->e();
            m_MEphoton_mother_eta = mother->eta();
            m_MEphoton_mother_phi = mother->phi();

	    // we want this for the highest pT only
	    if (particle->pt() > 15e3 && (abs(motherPdgId) == 24 || abs(motherPdgId) == 6))
	      m_hasMEphoton_DRgt02_nonhad = true;// in selection use with "ttbar && !m_hasMEphoton_DRgt02_nonhad" or "tty && m_hasMEphoton_DRgt02_nonhad"
	    else
	      m_hasMEphoton_DRgt02_nonhad = false;// in selection use with "ttbar && !m_hasMEphoton_DRgt02_nonhad" or "tty && m_hasMEphoton_DRgt02_nonhad"
          }
        }
        if((abs(motherPdgId) == 11 || abs(motherPdgId) == 13) && particle->status() == 1 && particle->pt() > 7e3 && abs(particle->eta()) < 2.5 && motherPt > 0 && particle->barcode()<2e5){
        //m_hasFSRPhotonLargeDeltaR = true;
        found = true;
        //g++;
        //std::cout<<"--> found photon from lepton " <<g<<std::endl;
        //std::cout<<"mother of the photon= "<<particle->parent(0)->pdgId()<<std::endl;
        //std::cout<<"barcode of mother of the photon= "<<particle->parent(0)->barcode()<<std::endl;
        //std::cout<<"photon barcode= "<<particle->barcode()<<std::endl;
          for(unsigned int iL=0; iL<truleptons.size(); iL++){
            const xAOD::TruthParticle* lepAfterRad = truleptons.at(iL);
            //std::cout<<"Leptonpt= " <<lepAfterRad->pt()<<std::endl;
           // auto dr= (particle->p4()).DeltaR(lepAfterRad->p4());
            //std::cout<<"--> Delta R lepton after rad- photon:" <<dr<<std::endl;
            //std::cout<<"electron barcode = "<<lepAfterRad->barcode()<<std::endl;
            //std::cout<<"mother electron barcode = "<<lepAfterRad->parent(0)->barcode()<<std::endl;
              if (minDR > (particle->p4()).DeltaR(lepAfterRad->p4())){
                minDR = (particle->p4()).DeltaR(lepAfterRad->p4()); 
              }
          }
          //std::cout<<"minDR= " <<minDR<<std::endl;
          if(minDR > 0.1 )
          m_hasFSRPhotonLargeDeltaR = true;
          //break;
          else 
          m_hasFSRPhotonLargeDeltaR = false;
        }
       }
     }
    }
  }

  //sherpa rw
  if( top::isSimulation(event) and ( ( m_mcChannelNumber >= 363102 and m_mcChannelNumber <= 363122 ) or
				     ( m_mcChannelNumber >= 363331 and m_mcChannelNumber <= 363354 ) or
				     ( m_mcChannelNumber >= 363361 and m_mcChannelNumber <= 363483 )
				     )
      ) {
    uint nTruthJetsSherpa      = m_sherpaRW->getSherpa22VJets_NJet("AntiKt4TruthJets");
    double sherpa_weight = m_sherpaRW->getSherpa22VJets_NJetCorrection(nTruthJetsSherpa);

    event.m_info->auxdecor<int>   ("TTHML_NTruthJetSherpa")    = nTruthJetsSherpa;
    event.m_info->auxdecor<double>("TTHML_SherpaNJetRW") = sherpa_weight;
  }


  //MC particle
  if (event.m_truth != nullptr) {
    m_higgsMode = truthSelector.GetHiggsDecayMode(event.m_truth);
    m_higgs     = truthSelector.GetHiggs(event.m_truth);
    m_top       = truthSelector.GetTop(event.m_truth);
    m_antitop   = truthSelector.GetAntiTop(event.m_truth);
  }

  if (event.m_truth != nullptr and !m_doSystematics) {

    if( !m_doSystematics ){
      m_mc_m       .clear();
      m_mc_pt      .clear();
      m_mc_eta     .clear();
      m_mc_phi     .clear();
      m_mc_e       .clear();
      m_mc_pdgId   .clear();
      m_mc_parents .clear();
      m_mc_children.clear();
      m_mc_status  .clear();
      m_mc_barcode .clear();

      const std::vector<ttH::TruthPart> selected_truths = event.m_info->auxdata<std::vector<ttH::TruthPart> >("ttHMLEventVariablesT");
      for (const ttH::TruthPart &truth : selected_truths) {

	m_mc_m       .push_back(truth.m);
	m_mc_pt      .push_back(truth.pt);
	m_mc_eta     .push_back(truth.eta);
	m_mc_phi     .push_back(truth.phi);
	m_mc_e       .push_back(truth.e);
	m_mc_pdgId   .push_back(truth.pdgId);
	m_mc_status  .push_back(truth.status);
	m_mc_barcode .push_back(truth.barcode);
	m_mc_children.push_back(truth.bc_children);
	m_mc_parents .push_back(truth.bc_parents);
      }
    }

  }

  //TruthEvent info here (pdf, MC weights, etc)
  if (event.m_truthEvent != nullptr and m_doSFSystematics ) {
    unsigned int i(0);
    unsigned int truthEventSize = event.m_truthEvent->size();
    m_PDFinfo_X1.resize(truthEventSize);
    m_PDFinfo_X2.resize(truthEventSize);
    m_PDFinfo_PDGID1.resize(truthEventSize);
    m_PDFinfo_PDGID2.resize(truthEventSize);
    m_PDFinfo_Q.resize(truthEventSize);
    m_PDFinfo_XF1.resize(truthEventSize);
    m_PDFinfo_XF2.resize(truthEventSize);
    for (const auto* const tePtr : *event.m_truthEvent) {
      std::string PDFinfoVarName="X1";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_X1[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="X2";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_X2[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="PDGID1";
      if (event.m_truthEvent->isAvailable<int>(PDFinfoVarName))
	m_PDFinfo_PDGID1[i] = (*tePtr).auxdataConst< int >( PDFinfoVarName );

      PDFinfoVarName="PDGID2";
      if (event.m_truthEvent->isAvailable<int>(PDFinfoVarName))
	m_PDFinfo_PDGID2[i] = (*tePtr).auxdataConst< int >( PDFinfoVarName );

      PDFinfoVarName="Q";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_Q[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="XF1";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_XF1[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="XF2";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_XF2[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );
      ++i;
    }

  }

  //Event info (for TrackingxAODHelpers)
  m_eventInfo = event.m_info;

  // Probably we want to bomb out if the vertices nonexist?
  if (event.m_primaryVertices == nullptr) {
      std::cerr << "WARNING!! Null vertex container! Expect segfault" << std::endl;
  }
  m_vertices = event.m_primaryVertices;

  m_pvNumber = 0;
  m_puNumber = 0;
  m_pv = nullptr;
  for (const xAOD::Vertex* vtx : *m_vertices){
    if(vtx->vertexType() == xAOD::VxType::PriVtx) {
      m_pvNumber++;
      m_pv = vtx;
    }
    else if( vtx->vertexType() == xAOD::VxType::PileUp ) m_puNumber++;
  }

  // Add beam positions and vertex density
  m_beam_posz   = m_eventInfo->beamPosZ();
  m_beam_sigmaz = m_eventInfo->beamPosSigmaZ();

  if(m_pv) {
    // Use uncorrected for now, can recompute later with saved beam parameters
    float mu          = m_eventInfo->averageInteractionsPerCrossing();
    float primaryVtxZ = m_pv->z();
    m_vertex_density  = mu * TMath::Gaus(primaryVtxZ, m_beam_posz, m_beam_sigmaz, true);
  }

    const xAOD::ElectronContainer* Electrons(nullptr);
    const xAOD::MuonContainer* Muons(nullptr);
    const xAOD::JetContainer* Jets(nullptr);
    const xAOD::TauJetContainer* Taus(nullptr);
    const xAOD::JetContainer* SelJets(nullptr);
    top::check( evtStore()->retrieve(Electrons,"SelectedORElectrons_"+m_config->systematicName(event.m_hashValue) + "_" + std::to_string(event.m_isLoose) ),"Failed to retrieve Electrons");
    top::check( evtStore()->retrieve(Muons,"SelectedORMuons_"+m_config->systematicName(event.m_hashValue) + "_" + std::to_string(event.m_isLoose) ),"Failed to retrieve Muons");
    top::check( evtStore()->retrieve(Jets,"SelectedORJets_"+m_config->systematicName(event.m_hashValue) + "_" + std::to_string(event.m_isLoose) ),"Failed to retrieve JEts");
    top::check( evtStore()->retrieve(Taus,"SelectedORTaus_"+m_config->systematicName(event.m_hashValue) + "_" + std::to_string(event.m_isLoose) ),"Failed to retrieve Taus");
    CopyLeptons(*Electrons,*Muons);
    CopyJets(*Jets);
    //MakeJetIndices(*Jets,event.m_jets);
    std::cout<<"aaaaaa"<<std::to_string(event.m_isLoose)<<std::endl;
    CopyTaus(*Taus);
    CopyHT(*Electrons,*Muons,*Jets,*Taus);
    CheckIsBlinded();
    if (m_isMC){
    doEventTrigSFs(*Electrons,*Muons,event);}
    //m_ttHEvent->AssignOutput(m_ttHEvent,tthevt);
  xAOD::JetContainer* calibratedJets(nullptr);
  top::check(evtStore()->retrieve(calibratedJets, m_config->sgKeyJetsTDS(sysHash,false)), "Failed to retrieve calibrated jets");

    //Assigning SFs to output
    m_ttHEvent->lepSFIDLoose = tthevt->lepSFIDLoose;
    m_ttHEvent->lepSFIDTight = tthevt->lepSFIDTight;
    m_ttHEvent->lepSFIsoLoose = tthevt->lepSFIsoLoose;
    m_ttHEvent->lepSFIsoTight = tthevt->lepSFIsoTight;
    m_ttHEvent->lepSFReco = tthevt->lepSFReco;
    m_ttHEvent->lepSFTTVA = tthevt->lepSFTTVA;


    // Truth Jets Information...
	m_excludedDSIDs = {
		423300,
		423100,423101,423102,423103,423104,423105,423106,423107,423108,423109,
		364500,364501,364502,364503,364504,364505,364506,364507,364508,364509
	};
	
	if ( !m_doSystematics && m_isMC && !(std::find(m_excludedDSIDs.begin(), m_excludedDSIDs.end(), m_mcChannelNumber) != m_excludedDSIDs.end()) ) {
		m_trjet_pt.clear();
		m_trjet_eta.clear();
		m_trjet_phi.clear();
		m_trjet_m.clear();
		m_trjet_Wcount.clear();
		m_trjet_Zcount.clear();
		m_trjet_Hcount.clear();
		m_trjet_Tcount.clear();
		m_trjet_BHandronCount.clear();
		m_trjet_CHandronCount.clear();
		m_trjet_ConeTruthLabelID.clear();
		m_trjet_PartonTruthLabelID.clear();
		const xAOD::JetContainer* truthJets(nullptr);
		top::check (evtStore()->retrieve( truthJets, "AntiKt4TruthJets"), "Failed to retrieve Truth Jets");
		//ATH_MSG_INFO ("execute(): number of truth jets = " << truthJets->size());
		for (const xAOD::Jet* jet : *truthJets) {
			//ATH_MSG_INFO ("execute(): truth jet pt = " << (jet->pt() * 0.001) << " GeV");
			m_trjet_pt.push_back(jet->pt());
			m_trjet_eta.push_back(jet->eta());
			m_trjet_phi.push_back(jet->phi());
			m_trjet_m.push_back(jet->m());
			//m_trjet_Wcount.push_back(jet->auxdata<int>("GhostWBosonsCount"));
			//m_trjet_Zcount.push_back(jet->auxdata<int>("GhostZBosonsCount"));
			//m_trjet_Hcount.push_back(jet->auxdata<int>("GhostHBosonsCount"));
			//m_trjet_Tcount.push_back(jet->auxdata<int>("GhostTQuarksFinalCount"));
			//m_trjet_BHandronCount.push_back(jet->auxdata<int>("GhostBHadronsFinalCount"));
			//m_trjet_CHandronCount.push_back(jet->auxdata<int>("GhostCHadronsFinalCount"));
			m_trjet_ConeTruthLabelID.push_back(jet->auxdata<int>("ConeTruthLabelID"));
			m_trjet_PartonTruthLabelID.push_back(jet->auxdata<int>("PartonTruthLabelID"));
		}
	}



    for (const auto& systvar: tthevt->m_lep_sf_names){
      auto ivar = systvar.first;
      m_ttHEvent->lepSFObjLoose[ivar] = tthevt->lepSFObjLoose[ivar];
      m_ttHEvent->lepSFObjTight[ivar] = tthevt->lepSFObjTight[ivar];
    }

    for (const auto& systvar : tthevt->m_tau_sf_names){
        auto ivar = systvar.first;
        m_ttHEvent->tauSFLoose[ivar] = tthevt->tauSFLoose[ivar];
        m_ttHEvent->tauSFTight[ivar] = tthevt->tauSFTight[ivar];
    }

////Be careful, we break the constantless of the event after here///////////

  top::check( evtStore()->retrieve(SelJets,"SelectedJets_"+m_config->systematicName(event.m_hashValue)+ "_" + std::to_string(event.m_isLoose) ),"Failed to retrieve JEts_2");
  top::Event& nc_event = const_cast<top::Event&>(event);
  xAOD::JetContainer orig_jets = event.m_jets;
  xAOD::JetContainer tmp_jets(SG::VIEW_ELEMENTS);
  xAOD::JetContainer tmp_jets_T(SG::VIEW_ELEMENTS);
//try here with selected jets
  //auto goodjets_2 = tthevt->selected_jets;
      //const xAOD::JetContainer* Jets(nullptr);
  //xAOD::JetContainer goodjets(SG::VIEW_ELEMENTS);

 xAOD::JetContainer*goodjets=const_cast<xAOD::JetContainer*>(SelJets);
  for(const auto jetItr : *goodjets ) {
    if(jetItr->auxdataConst<char>("ttHpassOVR"))
      tmp_jets.push_back(jetItr);
    if(jetItr->auxdataConst<char>("ttHpassOVR") and jetItr->auxdataConst<char>("ttHpassTauOVR") )
      tmp_jets_T.push_back(jetItr);
  }
  tmp_jets.sort(top::descendingPtSorter);
  tmp_jets_T.sort(top::descendingPtSorter);

  if(tthevt->total_leptons == 1 or (tthevt->total_leptons == 2 and tthevt->total_charge == 0 ) or tthevt->total_leptons == 4)
    nc_event.m_jets = tmp_jets;
  else
    nc_event.m_jets = tmp_jets_T;

  setBtagSFs(event);
  setBtagSFs_ForDL1(event);
  nc_event.m_jets = tmp_jets;
 /*  for(auto alljet : event.m_jets) {
      for(auto goodjet : *Jets) {
	if( goodjet->p4() == alljet->p4() ) {
	  (*m_decor_ttHpassOVR)   (*alljet) = (*m_decor_ttHpassOVR)   (*goodjet);
	  (*m_decor_ttHpassTauOVR)(*alljet) = (*m_decor_ttHpassTauOVR)(*goodjet);
	}
      }
    }*/

    MakeJetIndices(*Jets, event.m_jets);


  top::EventSaverFlatNtuple::saveEvent(event);
  tthevt->clearReco();

  }
std::string ttHMultileptonLooseEventSaver::betterBtagNamedSyst (const std::string name) {
  std::string str = "FT_EFF_";
  std::string out = name;
  if (out.find(str) != std::string::npos) {
    out.replace(out.find(str),str.length(),"");
  }
  str = " ";
  while (out.find(str) != std::string::npos) {
    out.replace(out.find(str),str.length(),"_");
  }
  str = "-";
  while (out.find(str) != std::string::npos) {
    out.replace(out.find(str),str.length(),"_");
  }
  return out;
}

void ttHMultileptonLooseEventSaver::setBtagSFs(const top::Event& event) {
  //do sys weights only in "nominal" tree

  if(     top::isSimulation(event) and m_sfRetriever ){
    m_bTagSF_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,m_bTagSF_default,false);
    m_bTagSF60_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"MV2c10_FixedCutBEff_60",false);
    m_bTagSF70_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"MV2c10_FixedCutBEff_70",false);
    m_bTagSF77_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"MV2c10_FixedCutBEff_77",false);
    m_bTagSF85_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"MV2c10_FixedCutBEff_85",false);
    //    m_bTagSFContinuous_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"MV2c10_Continuous",false);
    //btag
    if(m_doSFSystematics) {
      m_sfRetriever->btagSF_eigen_vars(event,
				       top::topSFSyst::BTAG_SF_EIGEN_B,
				       m_weight_bTagSF_eigen_B_up,
				       m_weight_bTagSF_eigen_B_down, m_bTagSF_default);
      m_sfRetriever->btagSF_eigen_vars(event,
				       top::topSFSyst::BTAG_SF_EIGEN_C,
				       m_weight_bTagSF_eigen_C_up,
				       m_weight_bTagSF_eigen_C_down, m_bTagSF_default);
      m_sfRetriever->btagSF_eigen_vars(event,
				       top::topSFSyst::BTAG_SF_EIGEN_LIGHT,
				       m_weight_bTagSF_eigen_Light_up,
				       m_weight_bTagSF_eigen_Light_down, m_bTagSF_default);

      for (auto name : m_config->btagging_namedSysts(m_bTagSF_default)) {
	m_weight_bTagSF_eigen_Others_up[name] = m_sfRetriever->btagSF( event, top::topSFSyst::BTAG_SF_NAMED_UP, m_bTagSF_default, false, name );
	m_weight_bTagSF_eigen_Others_down[name] = m_sfRetriever->btagSF( event, top::topSFSyst::BTAG_SF_NAMED_DOWN, m_bTagSF_default, false, name );
      }



      //normalise
      for( unsigned int i=0; i<m_config->btagging_num_B_eigenvars(m_bTagSF_default); ++i) {
	m_weight_bTagSF_eigen_B_up.at(i)   /= m_bTagSF_weight;
	m_weight_bTagSF_eigen_B_down.at(i) /= m_bTagSF_weight;
      }
      for( unsigned int i=0; i<m_config->btagging_num_C_eigenvars(m_bTagSF_default); ++i) {
	m_weight_bTagSF_eigen_C_up.at(i)   /= m_bTagSF_weight;
	m_weight_bTagSF_eigen_C_down.at(i) /= m_bTagSF_weight;
      }
      for( unsigned int i=0; i<m_config->btagging_num_Light_eigenvars(m_bTagSF_default); ++i) {
	m_weight_bTagSF_eigen_Light_up.at(i)   /= m_bTagSF_weight;
	m_weight_bTagSF_eigen_Light_down.at(i) /= m_bTagSF_weight;
      }
      for (auto name : m_config->btagging_namedSysts(m_bTagSF_default)) {
	m_weight_bTagSF_eigen_Others_up[name]   /= m_bTagSF_weight;
	m_weight_bTagSF_eigen_Others_down[name] /= m_bTagSF_weight;
      }

    }//endif sys
  }//endif nom
}
void ttHMultileptonLooseEventSaver::setBtagSFs_ForDL1(const top::Event& event) {
  //do sys weights only in "nominal" tree

  if(     top::isSimulation(event) and m_sfRetriever ){
    m_bTagSF_weight_DL1 = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,m_bTagSF_DL1,false);
    m_bTagSF60_weight_DL1 = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"DL1_FixedCutBEff_60",false);
    m_bTagSF70_weight_DL1 = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"DL1_FixedCutBEff_70",false);
    m_bTagSF77_weight_DL1 = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"DL1_FixedCutBEff_77",false);
    m_bTagSF85_weight_DL1 = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"DL1_FixedCutBEff_85",false);
    //    m_bTagSFContinuous_weight_DL1 = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"DL1_Continuous",false);
    //btag
    if(m_doSFSystematics) {
      m_sfRetriever->btagSF_eigen_vars(event,
				       top::topSFSyst::BTAG_SF_EIGEN_B,
				       m_weight_bTagSF_eigen_B_up_DL1,
				       m_weight_bTagSF_eigen_B_down_DL1, m_bTagSF_DL1);
      m_sfRetriever->btagSF_eigen_vars(event,
				       top::topSFSyst::BTAG_SF_EIGEN_C,
				       m_weight_bTagSF_eigen_C_up_DL1,
				       m_weight_bTagSF_eigen_C_down_DL1, m_bTagSF_DL1);
      m_sfRetriever->btagSF_eigen_vars(event,
				       top::topSFSyst::BTAG_SF_EIGEN_LIGHT,
				       m_weight_bTagSF_eigen_Light_up_DL1,
				       m_weight_bTagSF_eigen_Light_down_DL1, m_bTagSF_DL1);

      for (auto name : m_config->btagging_namedSysts(m_bTagSF_DL1)) {
	m_weight_bTagSF_eigen_Others_up_DL1[name] = m_sfRetriever->btagSF( event, top::topSFSyst::BTAG_SF_NAMED_UP, m_bTagSF_DL1, false, name );
	m_weight_bTagSF_eigen_Others_down_DL1[name] = m_sfRetriever->btagSF( event, top::topSFSyst::BTAG_SF_NAMED_DOWN, m_bTagSF_DL1, false, name );
      }



      //normalise
      for( unsigned int i=0; i<m_config->btagging_num_B_eigenvars(m_bTagSF_DL1); ++i) {
	m_weight_bTagSF_eigen_B_up_DL1.at(i)   /= m_bTagSF_weight_DL1;
	m_weight_bTagSF_eigen_B_down_DL1.at(i) /= m_bTagSF_weight_DL1;
      }
      for( unsigned int i=0; i<m_config->btagging_num_C_eigenvars(m_bTagSF_DL1); ++i) {
	m_weight_bTagSF_eigen_C_up_DL1.at(i)   /= m_bTagSF_weight_DL1;
	m_weight_bTagSF_eigen_C_down_DL1.at(i) /= m_bTagSF_weight_DL1;
      }
      for( unsigned int i=0; i<m_config->btagging_num_Light_eigenvars(m_bTagSF_DL1); ++i) {
	m_weight_bTagSF_eigen_Light_up_DL1.at(i)   /= m_bTagSF_weight_DL1;
	m_weight_bTagSF_eigen_Light_down_DL1.at(i) /= m_bTagSF_weight_DL1;
      }
      for (auto name : m_config->btagging_namedSysts(m_bTagSF_DL1)) {
	m_weight_bTagSF_eigen_Others_up_DL1[name]   /= m_bTagSF_weight_DL1;
	m_weight_bTagSF_eigen_Others_down_DL1[name] /= m_bTagSF_weight_DL1;
      }

    }//endif sys
  }//endif nom
}
void ttHMultileptonLooseEventSaver::finalize()
{
  auto Count = static_cast<TH1D*>(m_outputFile->Get("loose/Count"));

  double totalEventsProcessed = static_cast<TH1D*>(m_outputFile->Get("loose/cutflow"))->GetBinContent(1);
  Count->SetBinContent(3,totalEventsProcessed);

  //overwrite Count histogram with values from CutBookkeepers
  if(m_isMC)
  {
    TTree *myTree = (TTree*)m_outputFile->Get("sumWeights");
    double totalEventsUnskimmed         	= 0;
    double totalEventsWeightedUnskimmed 	= 0;
    unsigned long long totalEvents 		= 0;
    float totalEventsWeighted		 	= 0;
    std::vector<float>* totalEventsWeighted_lhe	= 0;
    std::vector<std::string> *names_lhe		= 0;

    myTree->SetBranchAddress("totalEventsWeighted_mc_generator_weights",&totalEventsWeighted_lhe);
    myTree->SetBranchAddress("names_mc_generator_weights",&names_lhe);
    myTree->SetBranchAddress("totalEvents",&totalEvents);
    myTree->SetBranchAddress("totalEventsWeighted",&totalEventsWeighted);


    if(m_config->doMCGeneratorWeights())
    {

      m_outputFile->cd();
      myTree->GetEntry(0);


      m_outputFile->cd("loose");
      TH1D* count_histo_lhe_weights = new TH1D("Count_LHE", "LHE weights", names_lhe->size(), -0.5, names_lhe->size() - 0.5);

      for(size_t i =0;i <names_lhe->size(); ++i)
      {
	count_histo_lhe_weights->GetXaxis()->SetBinLabel(i+1,names_lhe->at(i).c_str());
      }
      for (int i = 0; i < myTree->GetEntriesFast(); ++i)
      {
	myTree->GetEntry(i);
	for (size_t j = 0; j < names_lhe->size(); j++)
	{
	  count_histo_lhe_weights->Fill(j,totalEventsWeighted_lhe->at(j));
	}
      }
    }//end if generatorweights

    for (int i = 0 ; i  < myTree->GetEntriesFast(); ++i)
    {
      myTree->GetEntry(i);
      totalEventsUnskimmed +=totalEvents;
      totalEventsWeightedUnskimmed += totalEventsWeighted;
    }

    double totalEventsSkimmed = Count->GetBinContent(3);
    if(totalEventsUnskimmed != totalEventsSkimmed) {
      Count->SetBinContent(1,totalEventsUnskimmed);
      Count->SetBinContent(2,totalEventsWeightedUnskimmed);
    }
  }//end if MC
  m_outputFile->Write();
}
double ttHMultileptonLooseEventSaver::relativeSF(double variation, double nominal) {
  if (nominal == 0) return 0;
  else return variation/nominal;
}
/** remove branches from output n-tuple using pattern matching */
int ttHMultileptonLooseEventSaver::getBranchStatus(top::TreeManager const * treeManager, std::string const & variableName) {
  //we can use the treeManager to remove these branches only for some of the TTrees
  // e.g. add a condition like if (m_config->systematicName(treeManager->name() != "nominal")
  //if (variableName == "jet_ip3dsv1" || variableName == "jet_mv2c00") return 0;
  if (variableName.find("weight_")==0|| variableName.find("jet_")==0|| variableName.find("el_")==0 ||variableName.find("mu_")==0||variableName.find("ph_")==0 )
    return 0;
  //if (variableName.find("tau_")!=std::string::npos || variableName.find("weight_tau") != std::string::npos) return 0;
  return -1;
}
