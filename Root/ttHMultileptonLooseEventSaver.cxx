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
    m_jetCleaningToolLooseBad("JetCleaningToolLooseBad"),
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
//    m_HF_Classification(0.),
//    m_HF_ClassificationTop(0.),
//    m_DLF_Classification(0.),
    //m_MLF_Classification(0.),
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
  ttHMultileptonLooseEventSaver::~ttHMultileptonLooseEventSaver(){
    delete m_decor_ttHpassOVR;
    delete m_decor_ttHpassTauOVR;
    for (unsigned int t=0; t<m_lep_trigger_sf_names.size(); ++t) delete m_trigGlobEffCorr[t]; 
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
  std::vector<std::string> triggernames = config->allTriggers_Loose("triggers");
  top::check( m_jetCleaningToolLooseBad.retrieve() , "Failed to retrieve JetCleaningToolLooseBad" );


//Muon Tools
  //top::check( muonSelection.setProperty("OutputLevel", MSG::VERBOSE),"muonSelection fails to set OutputLevel");
  top::check( muonSelection.setProperty( "MaxEta", (double)m_config->muonEtacut() ), "muonSelection tool could not set max eta");
  top::check( muonSelection.initialize(),"muonSelection tool fails to initialize");

  auto isolation_WPs={"LooseTrackOnly", "Loose", "Gradient", "GradientLoose","FixedCutTightTrackOnly","FixedCutLoose"};
  top::check( m_purwtool.retrieve() , "Failed to retrieve PileupReweightingTool" );
  top::check( m_trigDecTool.retrieve() , "Failed to retrieve TrigDecisionTool" );

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
        m_sfRetriever->setProperty("OutputLevel", MSG::INFO).ignore();
	    }
	    else{
	      top::ScaleFactorRetriever* topSFR = new top::ScaleFactorRetriever("top::ScaleFactorRetriever");
	      top::check(asg::setProperty(topSFR, "config", m_config), "Failed to set config");
        top::check(asg::setProperty(topSFR,"OutputLevel", MSG::ERROR)," Failed to set output level");
	      top::check(topSFR->initialize(), "Failed to initalialise");
	      m_sfRetriever = topSFR;
	    }

/*std::vector<std::array<std::string,5> > triggerKeys = { // <list of legs>, <list of tags>, <key in map file>, <PID WP>, <iso WP>
    // single-e trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    //{"e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "Signal", "SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "TightLLH", "_isolFixedCutTight"}, 
    //{"e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "Signal", "SINGLE_E_2015_2016", "TightLLH", "_PLIso_isolLoose"},
    {"e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "Signal", "SINGLE_E_2015_2016", "TightLLH", "_PLIso_CFT_isolLoose"}, 
    // single-e trigger, only for untagged electrons, configured wrt tight+iso WP:
    {"e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "Baseline", "SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "LooseAndBLayerLLH", ""}, 
    // dielectron trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    //{"e17_lhvloose_nod0", "Signal", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0", "TightLLH", "_PLIso_isolLoose"}, 
    {"e17_lhvloose_nod0", "Signal", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0", "TightLLH", "_PLIso_CFT_isolLoose"}, 
    // dielectron trigger, only for untagged electrons, configured wrt loose WP:
    {"e17_lhvloose_nod0", "Baseline", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0", "LooseAndBLayerLLH", ""}, 
    // e-mu trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    //{"e17_lhloose_nod0", "Signal", "MULTI_L_2015_e17_lhloose_2016_e17_lhloose_nod0", "TightLLH", "_PLIso_isolLoose"},
    {"e17_lhloose_nod0", "Signal", "MULTI_L_2015_e17_lhloose_2016_e17_lhloose_nod0", "TightLLH", "_PLIso_CFT_isolLoose"},  
    // e-mu trigger, only for untagged electrons, configured wrt loose WP:
    {"e17_lhloose_nod0", "Baseline", "MULTI_L_2015_e17_lhloose_2016_e17_lhloose_nod0", "LooseAndBLayerLLH", ""}
  };
*/
  std::vector<std::array<std::string,5> > triggerKeys = { // <list of legs>, <list of tags>, <key in map file>, <PID WP>, <iso WP>
    //{"e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose, e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "Signal", "SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2017_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "TightLLH", "PLVeto_CFTtight_ambiguity0_isolFixedCutLoose"}, 
    // single-e trigger, only for untagged electrons, configured wrt tight+iso WP:
    //{"e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose, e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "Baseline", "SINGLE_E_2015_e24_lhmedium_L1EM20VH_OR_e60_lhmedium_OR_e120_lhloose_2016_2017_e26_lhtight_nod0_ivarloose_OR_e60_lhmedium_nod0_OR_e140_lhloose_nod0", "LooseAndBLayerLLH", "isolFixedCutLoose"}, 
    // dielectron trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    {"e12_lhloose_L1EM10VH, e17_lhvloose_nod0,e24_lhvloose_nod0", "Signal", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_e24_lhvloose_nod0_L1EM20VH", "TightLLH", "PLVeto_CFTtight_ambiguity0_isolFixedCutLoose"}, 
    // dielectron trigger, only for untagged electrons, configured wrt loose WP:
    {"e12_lhloose_L1EM10VH, e17_lhvloose_nod0, e24_lhvloose_nod0", "Baseline", "DI_E_2015_e12_lhloose_L1EM10VH_2016_e17_lhvloose_nod0_2017_e24_lhvloose_nod0_L1EM20VH", "LooseAndBLayerLLH", "isolFixedCutLoose"}, 
    // e-mu trigger, only for "Signal"-tagged electrons, configured wrt tight+iso WP:
    {"e17_lhloose, e17_lhloose_nod0", "Signal", "MULTI_L_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_e17_lhloose_nod0", "TightLLH", "PLVeto_CFTtight_ambiguity0_isolFixedCutLoose"},  
    // e-mu trigger, only for untagged electrons, configured wrt loose WP:
    {"e17_lhloose, e17_lhloose_nod0", "Baseline", "MULTI_L_2015_e17_lhloose_2016_e17_lhloose_nod0_2017_e17_lhloose_nod0", "LooseAndBLayerLLH", "isolFixedCutLoose"}
  };
 int nTrig = -1;

  m_trigGlobEffCorr.resize(m_lep_trigger_sf_names.size());

  for (unsigned int t=0; t<m_trigGlobEffCorr.size(); ++t)
    m_trigGlobEffCorr[t]=nullptr;
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
    char* const rc = getenv("WorkDir_DIR");
    for(auto& kv : triggerKeys) // electron tool instances for each trigger leg
      for(int j=0;j<2;++j) // one tool instance for efficiencies, another for scale factors
	{
	  auto t = m_electronToolsFactory.emplace(m_electronToolsFactory.end(), "AsgElectronEfficiencyCorrectionTool/ElTrigEff_"+std::to_string(++nTools)+systvar.second);
    std::string filepath="ElectronEfficiencyCorrection/2015_2017/rel21.2/Moriond_February2018_v1/trigger/"+ (std::string)(j?"efficiencySF.":"efficiency.") + kv[2] + "." + kv[3] + "_d0z0_v13_" + kv[4] + ".root";
	  //std::string filepath="ElectronEfficiencyCorrection/2015_2016/rel20.7/Moriond_February2017_v1/trigger/"+ (std::string)(j?"efficiencySF.":"efficiency.") + kv[2] + "." + kv[3] + "_d0z0_v11" + kv[4] + ".root";
	  if (kv[4]!="isolFixedCutLoose") filepath=std::string(rc)+"/data/ttHMultilepton/data/R21_PLV_SFs/"+ (std::string)(j?"efficiencySF.":"efficiency.") + kv[2] + "." + kv[3] + "_d0z0_v13_" + kv[4] + ".root";

	  std::vector<std::string> inputFiles;
	  inputFiles.push_back(filepath);
	  t->setProperty("CorrectionFileNameList",inputFiles).ignore();
	  t->setProperty("CorrelationModel","TOTAL").ignore();
	  t->setProperty("ForceDataType", (int)PATCore::ParticleDataType::Full).ignore();
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
  t->setProperty("CalibrationRelease", "180516_HighEtaUpdate").ignore(); 
  t->setProperty("useRel207",true).ignore();
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
    //m_trigGlobEffCorr[nTrig] = new TrigGlobalEfficiencyCorrectionTool("TrigGlobalEfficiencyCorrectionTool/MyTool");
    m_trigGlobEffCorr[nTrig] = new TrigGlobalEfficiencyCorrectionTool(trigglobname);
    //m_trigGlobEffCorr[nTrig]->setProperty("OutputLevel", MSG::ERROR).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("OutputLevel", MSG::ERROR).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ElectronEfficiencyTools",m_electronEffToolsHandles).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ElectronScaleFactorTools",m_electronSFToolsHandles).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("MuonTools",m_muonToolsHandles).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ListOfLegsPerTool",legsPerTool).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("ListOfTagsPerTool",tagsPerTool).ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2015", " 2e12_lhloose_L12EM10VH || e17_lhloose_mu14 || mu18_mu8noL1").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2016", " 2e17_lhvloose_nod0 || e17_lhloose_nod0_mu14 || mu22_mu8noL1").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("TriggerCombination2017", " 2e24_lhvloose_nod0 || e17_lhloose_nod0_mu14 || mu22_mu8noL1").ignore();
    //m_trigGlobEffCorr[nTrig]->setProperty("LeptonTagDecorations", "Signal,SignalCFT,Baseline").ignore();
    m_trigGlobEffCorr[nTrig]->setProperty("LeptonTagDecorations", "Signal,Baseline").ignore();
    top::check( m_trigGlobEffCorr[nTrig]->initialize(), "TrigGlobalEfficiencyCorrectionTool failed to initialize!" );
    ////////////////////////// end Trigger SF tool
  }
}
    m_ttHEvent = new ttHML::Variables();
/*
  for (auto treeName : *config->systAllTTreeNames()) {
    std::cout << "INITIALIZING SYST TREES" << std::endl;
    m_treeManagers.push_back(std::shared_ptr<top::TreeManager>( new top::TreeManager(treeName.second, file) ) );
    std::cout << m_treeManagers.size() << " " << treeName.second << std::endl;
    }*/



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

    if ( m_doSFSystematics ) {
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

/*
      //truth jets
      //systematicTree->makeOutputVariable(m_trjet_pt,  "m_truth_jet_pt");
      //systematicTree->makeOutputVariable(m_trjet_eta, "m_truth_jet_eta");
      //systematicTree->makeOutputVariable(m_trjet_phi, "m_truth_jet_phi");
      systematicTree->makeOutputVariable(m_trjet_e,   "m_truth_jet_e");
      //systematicTree->makeOutputVariable(m_trjet_Wcount,   "m_truth_jet_Wcount");
      //systematicTree->makeOutputVariable(m_trjet_Zcount,   "m_truth_jet_Zcount");
      //systematicTree->makeOutputVariable(m_trjet_Hcount,   "m_truth_jet_Hcount");
      //systematicTree->makeOutputVariable(m_trjet_Tcount,   "m_truth_jet_Tcount");
*/
      //truthEvent information
      systematicTree->makeOutputVariable(m_PDFinfo_X1,        "m_mcevt_pdf_X1");
      systematicTree->makeOutputVariable(m_PDFinfo_X2,        "m_mcevt_pdf_X2");
      systematicTree->makeOutputVariable(m_PDFinfo_PDGID1,    "m_mcevt_pdf_PDGID1");
      systematicTree->makeOutputVariable(m_PDFinfo_PDGID2,    "m_mcevt_pdf_PDGID2");
      systematicTree->makeOutputVariable(m_PDFinfo_Q,         "m_mcevt_pdf_Q");
      systematicTree->makeOutputVariable(m_PDFinfo_XF1,       "m_mcevt_pdf_XF1");
      systematicTree->makeOutputVariable(m_PDFinfo_XF2,       "m_mcevt_pdf_XF2");
    }



          //event info

    //scalar aka once per event stuff
    std::vector<ScalarWrapper*> scalarvec;
    systematicTree->makeOutputVariable(m_eventNumber, "EventNumber");
    //WrapS(scalarvec, [](const top::Event& event){ return event.m_info->runNumber(); }, *systematicTree, "RunNumber");
    systematicTree->makeOutputVariable(m_runNumber, "RunNumber");
    WrapS(scalarvec, [](const top::Event& event){ return event.m_info->lumiBlock(); }, *systematicTree, "lbn");
    WrapS(scalarvec, [](const top::Event& event){ return event.m_info->bcid(); }, *systematicTree, "bcid");
    WrapS(scalarvec, [](const top::Event& event){ return (event.m_info->errorState(EventInfo::Tile)!=EventInfo::Error && event.m_info->errorState(EventInfo::LAr)!=EventInfo::Error); }, *systematicTree, "passEventCleaning");
    WrapS(scalarvec, [](const top::Event& event){ return event.m_info->eventFlags(EventInfo::EventFlagSubDet::Background); }, *systematicTree, "backgroundFlags");
    WrapS(scalarvec, [&](const top::Event&){ return m_pv->x(); }, *systematicTree, "m_vxp_x");
    WrapS(scalarvec, [&](const top::Event&){ return m_pv->y(); }, *systematicTree, "m_vxp_y");
    WrapS(scalarvec, [&](const top::Event&){ return m_pv->z(); }, *systematicTree, "m_vxp_z");
    WrapS(scalarvec, [&](const top::Event& event)
	  {
	    return event.m_info->isAvailable<double>("TTHML_SherpaNJetRW") ? event.m_info->auxdataConst<double>("TTHML_SherpaNJetRW") : 1.0;
	  }, *systematicTree, "SherpaNJetWeight");
    WrapS(scalarvec, [&](const top::Event& event)
	  {
	    return event.m_info->isAvailable<int>("TTHML_NTruthJetSherpa") ? event.m_info->auxdataConst<int>("TTHML_NTruthJetSherpa") : 0.0;
	  }, *systematicTree, "nTruthJets_SherpaRwght");

    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->pt()             : 0.0; }, *systematicTree, "higgs_pt");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->eta()            : 0.0; }, *systematicTree, "higgs_eta");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->phi()            : 0.0; }, *systematicTree, "higgs_phi");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->e()              : 0.0; }, *systematicTree, "higgs_E");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->p4().Rapidity()  : 0.0; }, *systematicTree, "higgs_rapidity");

    WrapS(scalarvec, [&](const top::Event&){ return m_top ? m_top->pt()             : 0.0; }, *systematicTree, "top_pt");
    WrapS(scalarvec, [&](const top::Event&){ return m_top ? m_top->eta()            : 0.0; }, *systematicTree, "top_eta");
    WrapS(scalarvec, [&](const top::Event&){ return m_top ? m_top->phi()            : 0.0; }, *systematicTree, "top_phi");
    WrapS(scalarvec, [&](const top::Event&){ return m_top ? m_top->e()              : 0.0; }, *systematicTree, "top_E");
    WrapS(scalarvec, [&](const top::Event&){ return m_antitop ? m_antitop->pt()             : 0.0; }, *systematicTree, "antitop_pt");
    WrapS(scalarvec, [&](const top::Event&){ return m_antitop ? m_antitop->eta()            : 0.0; }, *systematicTree, "antitop_eta");
    WrapS(scalarvec, [&](const top::Event&){ return m_antitop ? m_antitop->phi()            : 0.0; }, *systematicTree, "antitop_phi");
    WrapS(scalarvec, [&](const top::Event&){ return m_antitop ? m_antitop->e()              : 0.0; }, *systematicTree, "antitop_E");

    systematicTree->makeOutputVariable(m_runYear, "RunYear");
// ttbar HF, DLF, MLF classification
//    systematicTree->makeOutputVariable(m_HF_Classification, "HF_Classification");
//    systematicTree->makeOutputVariable(m_HF_ClassificationTop, "HF_ClassificationTop");
//    systematicTree->makeOutputVariable(m_DLF_Classification, "DLF_Classification");
    //systematicTree->makeOutputVariable(m_MLF_Classification, "MLF_Classification");

    systematicTree->makeOutputVariable(m_higgsMode,      "higgsDecayMode");

    systematicTree->makeOutputVariable(m_mcChannelNumber, "mc_channel_number");
    systematicTree->makeOutputVariable(m_isAFII, "mc_isAFII");
    WrapS(scalarvec, [&](const top::Event& event){ return top::isSimulation(event) ? m_sampleXsection.getXsection(event.m_info->mcChannelNumber()) : -1.0; }, *systematicTree, "mc_xSection");
    WrapS(scalarvec, [&](const top::Event& event){ return top::isSimulation(event) ? m_sampleXsection.getRawXsection(event.m_info->mcChannelNumber()) : -1.0; }, *systematicTree, "mc_rawXSection");
    WrapS(scalarvec, [&](const top::Event& event){ return top::isSimulation(event) ? m_sampleXsection.getKfactor(event.m_info->mcChannelNumber()) : -1.0; }, *systematicTree, "mc_kFactor");
    WrapS(scalarvec, [&](const top::Event& event){ return top::isSimulation(event) ? m_sampleXsection.getShoweringIndex(event.m_info->mcChannelNumber()) : -1; }, *systematicTree, "mc_showering");
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
    // systematicTree->makeOutputVariable(m_MEphoton_OLtty_keepEvent, "m_MEphoton_OLtty_keepEvent");
    // systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat1, "m_MEphoton_OLtty_cat1");
    // systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat2, "m_MEphoton_OLtty_cat2");
    // systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat3, "m_MEphoton_OLtty_cat3");
    // systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat4, "m_MEphoton_OLtty_cat4");
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

/*    for (auto trigger : triggernames) {
      WrapS(scalarvec, [=](const top::Event&){ return (unsigned int) m_trigDecTool->isPassed( trigger ) ; }, *systematicTree, trigger.c_str());
      if(!m_doSystematics) WrapS(scalarvec, [=](const top::Event&){ return (float) m_trigDecTool->getPrescale( trigger ); }, *systematicTree, (trigger + "_PS").c_str());
    }*/
    //END trigger
    vec_scalar_wrappers.push_back(scalarvec);

    if(!m_doSystematics) {
      // vertex
      std::vector<VectorWrapper*> vtxvec;
      Wrap2(vtxvec, [](const xAOD::Vertex& vtx){ return (float) vtx.x(); },        *systematicTree, "vtx_x");
      Wrap2(vtxvec, [](const xAOD::Vertex& vtx){ return (float) vtx.y(); },        *systematicTree, "vtx_y");
      Wrap2(vtxvec, [](const xAOD::Vertex& vtx){ return (float) vtx.z(); },        *systematicTree, "vtx_z");
      Wrap2(vtxvec, [](const xAOD::Vertex& vtx){ return (int) vtx.vertexType(); }, *systematicTree, "vtx_type");
      Wrap2(vtxvec, [](const xAOD::Vertex& vtx){ return (int) vtx.nTrackParticles(); }, *systematicTree, "vtx_numTrk");
      // vertexType enum in xAODTracking/xAODTracking/TrackingPrimitives.h: 1 is Primary, 3 is PU
      vec_vtx_wrappers.push_back(VectorWrapperCollection(vtxvec));
    }
//leptons
    std::vector<VectorWrapper*> elevec;
    std::vector<VectorWrapper*> muvec;

    //Isolation
    if(!m_doSystematics) {
      for (auto wp : isolation_WPs) {
        std::string isoname("Iso_"); isoname += wp;
        std::string eleisoname("electron_isolation"); eleisoname += wp;
        std::string muisoname("muon_isolation"); muisoname += wp;
        Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>(isoname); }, *systematicTree, eleisoname.c_str());
        Wrap2(muvec,  [=](const xAOD::Muon& mu) {      return (char)  mu.auxdataConst<short>(isoname); }, *systematicTree, muisoname.c_str());
      }
    }

    /// special case for FixedCutTight (el only)
    if(!m_doSystematics) {
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>("Iso_FixedCutTight"); },
        *systematicTree, "electron_isolationFixedCutTight");
    }

    //debug inconsistency between our Iso and Top Iso
    //Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<char>("AnalysisTop_Isol_Loose"); }, *systematicTree, "electron_isolationLoose_Top");
    //Wrap2(elevec, [=](const xAOD::Muon& mu) { return (char) mu.auxdataConst<char>("AnalysisTop_Isol_Loose"); }, *systematicTree, "muon_isolationLoose_Top");


    //leptons
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.pt(); },  *systematicTree, "electron_pt");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.eta(); }, *systematicTree, "electron_eta");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.caloCluster()->etaBE(2); }, *systematicTree, "electron_EtaBE2");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.phi(); }, *systematicTree, "electron_phi");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.e(); },   *systematicTree, "electron_E");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) (-11*ele.charge()); }, *systematicTree, "electron_ID");

    if(!m_doSystematics) {
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("d0sig"); },             *systematicTree, "electron_sigd0PV");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("delta_z0_sintheta"); }, *systematicTree, "electron_z0SinTheta");

      //Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone20); return iso; }, *systematicTree, "electron_ptcone20");
      //Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone30); return iso; }, *systematicTree, "electron_ptcone30");
      //Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone40); return iso; }, *systematicTree, "electron_ptcone40");

      Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone20); return iso; },
        *systematicTree, "electron_topoetcone20");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone30); return iso; },
        *systematicTree, "electron_topoetcone30");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone40); return iso; },
        *systematicTree, "electron_topoetcone40");
      //miniiso
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone20); return iso; },
        *systematicTree, "electron_ptvarcone20");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone30); return iso; },
        *systematicTree, "electron_ptvarcone30");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone40); return iso; },
        *systematicTree, "electron_ptvarcone40");
    }

    if(!m_doSystematics) {
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<int>("passLHLoose"); },  *systematicTree, "electron_isLooseLH");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<int>("passLHMedium"); }, *systematicTree, "electron_isMediumLH");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<int>("passLHTight"); },  *systematicTree, "electron_isTightLH");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<char>("sharesTrk"); },  *systematicTree, "electron_sharesTrk");
    }
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<char>("ttHpassOVR"); }, *systematicTree, "electron_passOR");

    //non-prompt bdt vars - OLD VARIABLE, MAYBE SHOULD BE DELETED
    /*
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	  float m_el_nonprompt_bdt = -99.;
	  static SG::AuxElement::Accessor<float> AccessorNonPromptBDT("PromptLeptonIso_TagWeight");
	  if(AccessorNonPromptBDT.isAvailable(ele)) m_el_nonprompt_bdt = AccessorNonPromptBDT(ele);
	  return (float) m_el_nonprompt_bdt; }, *systematicTree, "electron_PromptLeptonIso_TagWeight");
		*/


    // electron QmisID
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
          float m_el_QmisID = -99;
          static SG::AuxElement::Accessor<char> AccessorQmisID("isQMisID");
          if(AccessorQmisID.isAvailable(ele)) m_el_QmisID = AccessorQmisID(ele);
          return (char) m_el_QmisID; }, *systematicTree, "electron_isQMisID");

    // electron charge flip tagger tool
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
          float chargeIDBDTLoose = -99.;
          static SG::AuxElement::Accessor<float> AccessorChargeIDBDTLoose("chargeIDBDTLoose");
          if(AccessorChargeIDBDTLoose.isAvailable(ele)) chargeIDBDTLoose = AccessorChargeIDBDTLoose(ele);
          return (float) chargeIDBDTLoose; }, *systematicTree, "electron_ChargeIDBDTLoose");

    Wrap2(elevec, [=](const xAOD::Electron& ele) {
          float chargeIDBDTMedium = -99.;
          static SG::AuxElement::Accessor<float> AccessorChargeIDBDTMedium("chargeIDBDTMedium");
          if(AccessorChargeIDBDTMedium.isAvailable(ele)) chargeIDBDTMedium = AccessorChargeIDBDTMedium(ele);
          return (float) chargeIDBDTMedium; }, *systematicTree, "electron_ChargeIDBDTMedium");

    Wrap2(elevec, [=](const xAOD::Electron& ele) {
          float chargeIDBDTTight = -99.;
          static SG::AuxElement::Accessor<float> AccessorChargeIDBDTTight("chargeIDBDTTight");
          if(AccessorChargeIDBDTTight.isAvailable(ele)) chargeIDBDTTight = AccessorChargeIDBDTTight(ele);
          return (float) chargeIDBDTTight; }, *systematicTree, "electron_ChargeIDBDTTight");

    if(!m_doSystematics) {
      for (std::string trigger_name : triggernames) {
        if( trigger_name.find("_e") == std::string::npos && trigger_name.find("_2e") == std::string::npos ) continue;
        std::string trigmatch_name = "TRIGMATCH_"; trigmatch_name += trigger_name;
        std::string branch_name = "electron_match_"; branch_name += trigger_name;
        Wrap2(elevec, [=](const xAOD::Electron& ele) {
            int is_matched(0);
            if (ele.isAvailable<char>(trigmatch_name)) is_matched = ele.auxdataConst<char>(trigmatch_name);
            return (int) is_matched;
          }, *systematicTree, branch_name.c_str() );
      }
    }
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	return getNInnerPix(ele);
      }, *systematicTree, "electron_nInnerPix");

    //////// NOMINAL ONLY
    if(!m_doSystematics) {
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) ele.author(); }, *systematicTree, "electron_author");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float d0 = ele.trackParticle()->d0(); return (float) (d0); }, *systematicTree, "electron_d0");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float z0 = ele.trackParticle()->z0(); return (float) (z0); }, *systematicTree, "electron_z0");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { float vz = ele.trackParticle()->vz(); return (float) (vz); }, *systematicTree, "electron_vz");
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("delta_z0"); },        *systematicTree, "electron_deltaz0");

      //truth origin HERE
      //coding of the enums, see here: https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/MCTruthClassifier/tags/MCTruthClassifier-00-00-26/MCTruthClassifier/MCTruthClassifierDefs.h
      //meaning of the enums, see here: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/MCTruthClassifier#Egamma_electrons_classification

      // Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) xAOD::TruthHelpers::getParticleTruthOrigin(ele); }, *systematicTree, "electron_truthOrigin");
      // Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) xAOD::TruthHelpers::getParticleTruthType(ele); },   *systematicTree, "electron_truthType");
      Wrap2(elevec, [=](const xAOD::Electron& ele) {
	  int m_el_true_origin = -99;
	  static SG::AuxElement::Accessor<int> origel("truthOrigin");
	  if (origel.isAvailable(ele)) m_el_true_origin = origel(ele);
	  return (int) m_el_true_origin; }, *systematicTree, "electron_truthOrigin");

      Wrap2(elevec, [=](const xAOD::Electron& ele) {
	  int m_el_true_type = -99;
	  static SG::AuxElement::Accessor<int> typeel("truthType");
	  if (typeel.isAvailable(ele)) m_el_true_type = typeel(ele);
	  return (int) m_el_true_type; },   *systematicTree, "electron_truthType");

      Wrap2(elevec, [=](const xAOD::Electron& ele) {
	  int m_el_true_type = -99;
	  static SG::AuxElement::Accessor<int> typeel("firstEgMotherPdgId");
	  if (typeel.isAvailable(ele)) m_el_true_type = typeel(ele);
	  return (int) m_el_true_type; },   *systematicTree, "electron_firstEgMotherPdgId");

      Wrap2(elevec, [=](const xAOD::Electron& ele) {
          int m_el_true_type = -99;
          static SG::AuxElement::Accessor<int> typeel("firstEgMotherTruthType");
          if (typeel.isAvailable(ele)) m_el_true_type = typeel(ele);
          return (int) m_el_true_type; },   *systematicTree, "electron_firstEgMotherTruthType");

      Wrap2(elevec, [=](const xAOD::Electron& ele) {
          int m_el_true_type = -99;
          static SG::AuxElement::Accessor<int> typeel("firstEgMotherTruthOrigin");
          if (typeel.isAvailable(ele)) m_el_true_type = typeel(ele);
          return (int) m_el_true_type; },   *systematicTree, "electron_firstEgMotherTruthOrigin");

      // Add non-prompt electron vars
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<double>("jetFitterComb"); }, *systematicTree, "electron_jetFitterComb");

  /*    std::vector<std::string> short_vars = {"PromptLeptonIso_sv1_jf_ntrkv", "PromptLeptonIso_TrackJetNTrack"};
      for(std::string var: short_vars) {
	Wrap2(elevec, [=](const xAOD::Electron& ele) {
	    short m_el_nonprompt_short = -99;
	    SG::AuxElement::Accessor<short> AccessorNonPrompt(var);
	    if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_short = AccessorNonPrompt(ele);
	    return (short) m_el_nonprompt_short; }, *systematicTree, ("electron_" + var).c_str());
      }

      bool m_writeAllNonPromptInputVars = true;

      if(m_writeAllNonPromptInputVars) {
	std::vector<std::string> float_vars = {"PromptLeptonIso_ip2", "PromptLeptonIso_ip3",
					       "PromptLeptonIso_DRlj", "PromptLeptonIso_LepJetPtFrac",
					       "PromptLepton_TagWeight", "PromptLeptonNoIso_TagWeight"};
	for(std::string var: float_vars) {
	  Wrap2(elevec, [=](const xAOD::Electron& ele) {
	      float m_el_nonprompt_float = -99.;
	      SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
	      if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_float = AccessorNonPrompt(ele);
	      return (float) m_el_nonprompt_float; }, *systematicTree, ("electron_" + var).c_str());
	}
      }
*/
    }


	std::vector<std::string> short_vars = {"PromptLeptonInput_sv1_jf_ntrkv", "PromptLeptonInput_TrackJetNTrack"};
	for(std::string var: short_vars) {
		Wrap2(elevec, [=](const xAOD::Electron& ele) {
        short m_el_nonprompt_short = -99;
        SG::AuxElement::Accessor<short> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_short = AccessorNonPrompt(ele);
        return (short) m_el_nonprompt_short; }, *systematicTree, ("electron_" + var).c_str());
    }

 
    std::vector<std::string> float_vars = {"PromptLeptonInput_DL1mu", "PromptLeptonInput_DRlj", "PromptLeptonInput_LepJetPtFrac",
				"PromptLeptonInput_PtFrac", "PromptLeptonInput_PtRel", "PromptLeptonInput_ip2", "PromptLeptonInput_ip3",
				"PromptLeptonInput_rnnip"};
	for(std::string var: float_vars) {
		Wrap2(elevec, [=](const xAOD::Electron& ele){
		float m_el_nonprompt_float = -99.;
		SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_float = AccessorNonPrompt(ele);
		return (float) m_el_nonprompt_float;}, *systematicTree, ("electron_" + var).c_str());
	}


   std::vector<std::string> R21_Ele_PLI_vars = {"PromptLeptonIso", "PromptLeptonVeto"};
    for(std::string var: R21_Ele_PLI_vars){
	Wrap2(elevec, [=](const xAOD::Electron& ele) { 
	float m_el_nonprompt_float = -99.;
        SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_float = AccessorNonPrompt(ele);
        return (float) m_el_nonprompt_float;}, *systematicTree, ("electron_" + var + "_TagWeight").c_str());
    }

    Wrap2(elevec, [=](const xAOD::Electron& ele) {
    	unsigned char m_el_ambigtype_int = -99;
    	SG:AuxElement::Accessor<unsigned char> AccessorAmbigType("ambiguityType");
	if(AccessorAmbigType.isAvailable(ele)) {
		m_el_ambigtype_int = AccessorAmbigType(ele);}
	return (unsigned char) m_el_ambigtype_int;}, *systematicTree, ("electron_ambiguityType"));
    
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	static SG::AuxElement::Accessor<unsigned char> Accessor_numPixLayerHits("numberOfInnermostPixelLayerHits");
	unsigned char m_el_numPixLayerHits=-99;
	const xAOD::TrackParticle* eltrack = ele.trackParticle(0);
	if(eltrack!=nullptr){
		m_el_numPixLayerHits=1;}
		//if (Accessor_numPixLayerHits.isAvailable(*eltrack)) m_el_numPixLayerHits=Accessor_numPixLayerHits(*eltrack);}
	return (unsigned char) m_el_numPixLayerHits; }, *systematicTree, "electron_numberOfInnermostPixelLayerHits");

    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	static SG::AuxElement::Accessor<unsigned char> Accessor_numPixLayerOutliers("numberOfInnermostPixelLayerOutliers");
	unsigned char m_el_numPixLayerOutliers=-99;
	const xAOD::TrackParticle* eltrack = ele.trackParticle(0);
	if(eltrack!=nullptr){
		if (Accessor_numPixLayerOutliers.isAvailable(*eltrack)) m_el_numPixLayerOutliers=Accessor_numPixLayerOutliers(*eltrack);}
	return (unsigned char) m_el_numPixLayerOutliers; }, *systematicTree, "electron_numberOfInnermostPixelLayerOutliers");

    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	static SG::AuxElement::Accessor<unsigned char> Accessor_expectInnerPixelLayerHit("expectInnermostPixelLayerHit");
	unsigned char m_el_expectInnerPixelLayerHit=-99;
	const xAOD::TrackParticle* eltrack = ele.trackParticle(0);
	if(eltrack!=nullptr){
		if (Accessor_expectInnerPixelLayerHit.isAvailable(*eltrack)) m_el_expectInnerPixelLayerHit=Accessor_expectInnerPixelLayerHit(*eltrack);}
	return (unsigned char) m_el_expectInnerPixelLayerHit; }, *systematicTree, "electron_expectInnerPixelLayerHit");



    vec_electron_wrappers.push_back(VectorWrapperCollection(elevec));

// Muons
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.pt(); },  *systematicTree, "muon_pt");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.eta(); }, *systematicTree, "muon_eta");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.phi(); }, *systematicTree, "muon_phi");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.e(); },   *systematicTree, "muon_E");
    if(!m_doSystematics) {
      Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Loose && muonSelection.passedIDCuts(mu))
        isqual=1; return isqual;},*systematicTree, "muon_isLoose");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Medium && muonSelection.passedIDCuts(mu))
        isqual=1; return isqual;},*systematicTree, "muon_isMedium");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Tight && muonSelection.passedIDCuts(mu))
        isqual=1; return isqual;},*systematicTree, "muon_isTight");
      // Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdata<float>("InnerDetectorPt"); },    *systematicTree, "muon_PtID");
      // Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdata<float>("MuonSpectrometerPt"); }, *systematicTree, "muon_PtME");
      // Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.allAuthors(); }, *systematicTree, "muon_allAuthor");
    }
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) (-13*mu.charge()); }, *systematicTree, "muon_ID");

    if(!m_doSystematics) {
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("d0sig"); }, *systematicTree, "muon_sigd0PV");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("delta_z0_sintheta"); }, *systematicTree, "muon_z0SinTheta");

      Wrap2(muvec, [=](const xAOD::Muon& mu) { float momBalSignif = mu.floatParameter(xAOD::Muon::momentumBalanceSignificance);
        return (float) (momBalSignif); }, *systematicTree, "muon_momBalSignif");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatCurvSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance);
        return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatNeighSignif = mu.floatParameter(xAOD::Muon::scatteringNeighbourSignificance);
        return (float) (scatNeighSignif); }, *systematicTree, "muon_scatNeighSignif");

      // Wrap2(muvec, [=](const xAOD::Muon& mu) {
      // 	 const xAOD::TrackParticle* cbtrack = mu.trackParticle( xAOD::Muon::CombinedTrackParticle );
      // 	 float qOverP = cbtrack->qOverP();
      // 	 return qOverP; }, *systematicTree, "muon_qOverP");
    }

    if(!m_doSystematics) {
      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	const xAOD::TrackParticle* idtrack = mu.trackParticle( xAOD::Muon::InnerDetectorTrackParticle );
	const xAOD::TrackParticle* metrack = mu.trackParticle( xAOD::Muon::ExtrapolatedMuonSpectrometerTrackParticle );
	float rho=-9999;
	if( idtrack && metrack ) {
	  float mePt = -999999., idPt = -999999.;

	  try{
	    static SG::AuxElement::Accessor<float> mePt_acc("MuonSpectrometerPt");
	    static SG::AuxElement::Accessor<float> idPt_acc("InnerDetectorPt");
	    mePt = mePt_acc(mu);
	    idPt = idPt_acc(mu);
	  } catch ( SG::ExcNoAuxStore b ) {
	    ATH_MSG_FATAL( "No MomentumCorrections decorations available! MuonSelectionTool can not work!!! " <<
			   "Please apply MuonMomentumCorrections before feeding the muon to MuonSelectorTools." );
	    throw std::runtime_error( "No MomentumCorrections decorations available, throwing a runtime error" );
	  }


	  float cbPt = mu.pt();
	  rho           = fabs( idPt - mePt ) / cbPt;
	}
	return rho; }, *systematicTree, "muon_rho");

      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	const xAOD::TrackParticle* idtrack = mu.trackParticle( xAOD::Muon::InnerDetectorTrackParticle );
	const xAOD::TrackParticle* metrack = mu.trackParticle( xAOD::Muon::ExtrapolatedMuonSpectrometerTrackParticle );
	float qOverPsigma = -9999;
	if( idtrack && metrack ) {
	  qOverPsigma   = sqrt( idtrack->definingParametersCovMatrix()(4,4) + metrack->definingParametersCovMatrix()(4,4) );
	}
	return qOverPsigma; }, *systematicTree, "muon_qOverPsigma");

      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	const xAOD::TrackParticle* idtrack = mu.trackParticle( xAOD::Muon::InnerDetectorTrackParticle );
	const xAOD::TrackParticle* metrack = mu.trackParticle( xAOD::Muon::ExtrapolatedMuonSpectrometerTrackParticle );
	float qOverPsignif = -9999;
	if( idtrack && metrack ) {
	  float mePt = -999999., idPt = -999999.;

	  try{
	    static SG::AuxElement::Accessor<float> mePt_acc("MuonSpectrometerPt");
	    static SG::AuxElement::Accessor<float> idPt_acc("InnerDetectorPt");
	    mePt = mePt_acc(mu);
	    idPt = idPt_acc(mu);
	  } catch ( SG::ExcNoAuxStore b ) {
	    ATH_MSG_FATAL( "No MomentumCorrections decorations available! MuonSelectionTool can not work!!! " <<
			   "Please apply MuonMomentumCorrections before feeding the muon to MuonSelectorTools." );
	    throw std::runtime_error( "No MomentumCorrections decorations available, throwing a runtime error" );
	  }

	  float meP  = 1.0 / ( sin(metrack->theta()) / mePt);
	  float idP  = 1.0 / ( sin(idtrack->theta()) / idPt);
	  float qOverPsigma   = sqrt( idtrack->definingParametersCovMatrix()(4,4) + metrack->definingParametersCovMatrix()(4,4) );
	  qOverPsignif  = fabs( (metrack->charge() / meP) - (idtrack->charge() / idP) ) / qOverPsigma;
	}
	return qOverPsignif; }, *systematicTree, "muon_qOverPsignif");

      Wrap2(muvec, [=](const xAOD::Muon& mu) { float reducedChi2   = mu.primaryTrackParticle()->chiSquared()/mu.primaryTrackParticle()->numberDoF();return reducedChi2; }, *systematicTree, "muon_reducedChi2");

      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	uint8_t nprecisionLayers;

	if( fabs(mu.eta()) > 2.0 ) {
	  nprecisionLayers = 0;
	  uint8_t innerSmallHits, innerLargeHits, middleSmallHits, middleLargeHits, outerSmallHits, outerLargeHits;
	  if ( !mu.summaryValue(innerSmallHits, xAOD::MuonSummaryType::innerSmallHits) ||
	       !mu.summaryValue(innerLargeHits, xAOD::MuonSummaryType::innerLargeHits) ||
	       !mu.summaryValue(middleSmallHits, xAOD::MuonSummaryType::middleSmallHits) ||
	       !mu.summaryValue(middleLargeHits, xAOD::MuonSummaryType::middleLargeHits) ||
	       !mu.summaryValue(outerSmallHits, xAOD::MuonSummaryType::outerSmallHits) ||
	       !mu.summaryValue(outerLargeHits, xAOD::MuonSummaryType::outerLargeHits) ){

	    ATH_MSG_VERBOSE("getQuality - Muon in CSC region and MS hits information missing!!!");
	  }
	  else {
	    if( innerSmallHits>1  || innerLargeHits>1  ) nprecisionLayers += 1;
	    if( middleSmallHits>2 || middleLargeHits>2 ) nprecisionLayers += 1;
	    if( outerSmallHits>2  || outerLargeHits>2  ) nprecisionLayers += 1;
	  }
	}
	else {
	  mu.summaryValue(nprecisionLayers, xAOD::SummaryType::numberOfPrecisionLayers);
	}
	return nprecisionLayers; }, *systematicTree, "muon_numPrecLayers");
    }

    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float momBalSignif = mu.floatParameter(xAOD::Muon::momentumBalanceSignificance); return (float) (momBalSignif); }, *systematicTree, "muon_momBalSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatCurvSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatNeighSignif = mu.floatParameter(xAOD::Muon::scatteringNeighbourSignificance); return (float) (scatNeighSignif); }, *systematicTree, "muon_scatNeighSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float qOverPSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { return (short) mu.uint8SummaryValue(xAOD::SummaryType::numberOfPrecisionLayers); }, *systematicTree, "muon_numPrecLayers");

    if(!m_doSystematics) {
      // Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptcone20); return iso; }, *systematicTree, "muon_ptcone20");
      // Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptcone30); return iso; }, *systematicTree, "muon_ptcone30");
      // Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptcone40); return iso; }, *systematicTree, "muon_ptcone40");
      // topoiso
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone20); return iso; }, *systematicTree, "muon_topoetcone20");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone30); return iso; }, *systematicTree, "muon_topoetcone30");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone40); return iso; }, *systematicTree, "muon_topoetcone40");
      // miniiso
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone20); return iso; }, *systematicTree, "muon_ptvarcone20");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone30); return iso; }, *systematicTree, "muon_ptvarcone30");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone40); return iso; }, *systematicTree, "muon_ptvarcone40");

      Wrap2(muvec, [=](const xAOD::Muon& mu) { return mu.auxdataConst<char>("sharesTrk"); },  *systematicTree, "muon_sharesTrk");
    }
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return mu.auxdataConst<char>("ttHpassOVR"); }, *systematicTree, "muon_passOR");

    //non-prompt bdt vars - OLD AND PROBABLY SHOULD BE DELETED
    /*
    Wrap2(muvec, [=](const xAOD::Muon& mu) {
	  float m_mu_nonprompt_bdt = -99.;
	  static SG::AuxElement::Accessor<float> AccessorNonPromptBDT("PromptLeptonIso_TagWeight");
	  if(AccessorNonPromptBDT.isAvailable(mu)) m_mu_nonprompt_bdt = AccessorNonPromptBDT(mu);
	  return (float) m_mu_nonprompt_bdt; }, *systematicTree, "muon_PromptLeptonIso_TagWeight");
*/


    // muon QmisID
    if(!m_doSystematics) {
      Wrap2(muvec, [=](const xAOD::Muon& mu) {
          float m_mu_QmisID = -99;
          static SG::AuxElement::Accessor<char> AccessorQmisID("isQMisID");
          if(AccessorQmisID.isAvailable(mu)) m_mu_QmisID = AccessorQmisID(mu);
          return (char) m_mu_QmisID; }, *systematicTree, "muon_isQMisID");
    }

    //Trigger matching
    if(!m_doSystematics) {
      for (std::string trigger_name : triggernames) {
        if( trigger_name.find("_mu") == std::string::npos && trigger_name.find("_2mu") == std::string::npos ) continue;
        std::string trigmatch_name = "TRIGMATCH_"; trigmatch_name += trigger_name;
        std::string branch_name = "muon_match_"; branch_name += trigger_name;
        Wrap2(muvec, [=](const xAOD::Muon& mu) {
            int is_matched(0);
            if (mu.isAvailable<char>(trigmatch_name)) is_matched = mu.auxdataConst<char>(trigmatch_name);
            return (int) is_matched;
          }, *systematicTree, branch_name.c_str() );
      }
    }


    //////// NOMINAL ONLY
    if(!m_doSystematics) {

      //extra IP info
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.primaryTrackParticle()->d0(); }, *systematicTree, "muon_d0");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.primaryTrackParticle()->z0(); }, *systematicTree, "muon_z0");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.primaryTrackParticle()->vz(); }, *systematicTree, "muon_vz");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("delta_z0"); }, *systematicTree, "muon_deltaz0");

      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.author(); },   *systematicTree, "muon_author");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.muonType(); }, *systematicTree, "muon_type");

      //truth origin HERE
      //For muons - one more step as the info is attached to TruthMuonParticle, not xAOD::Muon.
      //coding of the enums, see here: https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/MCTruthClassifier/tags/MCTruthClassifier-00-00-26/MCTruthClassifier/MCTruthClassifierDefs.h
      //meaning of the enums, see here: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/MCTruthClassifier#Egamma_electrons_classification


      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	  static SG::AuxElement::Accessor<int> acc_mctt("truthType");
	  int m_mu_true_type=-99;
	  const xAOD::TrackParticle* mutrack = mu.primaryTrackParticle();
	  if (mutrack!=nullptr) {
	    if (acc_mctt.isAvailable(*mutrack)) m_mu_true_type = acc_mctt(*mutrack);
	  }
	  return (int) m_mu_true_type; }, *systematicTree, "muon_truthType");

      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	  static SG::AuxElement::Accessor<int> acc_mcto("truthOrigin");
	  int m_mu_true_origin=-99;
	  const xAOD::TrackParticle* mutrack = mu.primaryTrackParticle();
	  if (mutrack!=nullptr) {
	    if (acc_mcto.isAvailable(*mutrack)) m_mu_true_origin = acc_mcto(*mutrack);
	  }
	  return (int) m_mu_true_origin; }, *systematicTree, "muon_truthOrigin");


      // Wrap2(muvec, [=](const xAOD::Muon& mu) {
      // 	  const xAOD::TruthParticle* matched_truth_muon=0;
      // 	  int mu_type = -99;
      // 	  if(mu.isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
      // 	    ElementLink<xAOD::TruthParticleContainer> link = mu.auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
      // 	    if(link.isValid()){
      // 	      matched_truth_muon = *link;
      // 	      mu_type = matched_truth_muon->auxdata<int>("truthType");
      // 	    }
      // 	  } return (int) mu_type; }, *systematicTree, "muon_truthType");

      // Wrap2(muvec, [=](const xAOD::Muon& mu) {
      // 	  const xAOD::TruthParticle* matched_truth_muon=0;
      // 	  int mu_orig = -99;
      // 	  if(mu.isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
      // 	    ElementLink<xAOD::TruthParticleContainer> link = mu.auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
      // 	    if(link.isValid()){
      // 	      matched_truth_muon = *link;
      // 	      mu_orig = matched_truth_muon->auxdata<int>("truthOrigin");
      // 	    }
      // 	  } return (int) mu_orig; }, *systematicTree, "muon_truthOrigin");

      //There is a second way to get truth type for all muons, from track particle. See diffs from https://twiki.cern.ch/twiki/bin/view/Atlas/XAODMuon#How_to_retrieve_truth_type_and_o
      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	  const xAOD::TrackParticle* idtp=0;
	  int mu_type = -99;
	  ElementLink<xAOD::TrackParticleContainer> idtpLink = mu.inDetTrackParticleLink();
	  if(idtpLink.isValid()){
	    idtp = *idtpLink;
	    mu_type = idtp->auxdata<int>("truthType");
	  } return (int) mu_type; }, *systematicTree, "muon_trackType");

      Wrap2(muvec, [=](const xAOD::Muon& mu) {
	  const xAOD::TrackParticle* idtp=0;
	  int mu_orig = -99;
	  ElementLink<xAOD::TrackParticleContainer> idtpLink = mu.inDetTrackParticleLink();
	  if(idtpLink.isValid()){
	    idtp = *idtpLink;
	    mu_orig = idtp->auxdata<int>("truthOrigin");
	  } return (int) mu_orig; }, *systematicTree, "muon_trackOrigin");

      // Add non-prompt muon vars
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<double>("jetFitterComb"); }, *systematicTree, "muon_jetFitterComb");

/*      std::vector<std::string> short_vars = {"PromptLeptonIso_sv1_jf_ntrkv", "PromptLeptonIso_TrackJetNTrack"};
      for(std::string &var: short_vars) {
	Wrap2(muvec, [=](const xAOD::Muon& mu) {
	    short m_mu_nonprompt_short = -99;
	    SG::AuxElement::Accessor<short> AccessorNonPrompt(var);
	    if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_short = AccessorNonPrompt(mu);
	    return (short) m_mu_nonprompt_short; }, *systematicTree, ("muon_" + var).c_str());
      }

      bool m_writeAllNonPromptInputVars = true;

      if(m_writeAllNonPromptInputVars) {
	std::vector<std::string> float_vars = {"PromptLeptonIso_ip2", "PromptLeptonIso_ip3", "PromptLeptonIso_DRlj",
					       "PromptLeptonIso_LepJetPtFrac", "PromptLepton_TagWeight",
					       "PromptLeptonNoIso_TagWeight"};
	for(std::string &var: float_vars) {
	  Wrap2(muvec, [=](const xAOD::Muon& mu) {
	      float m_mu_nonprompt_float = -99.;
	      SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
	      if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_float = AccessorNonPrompt(mu);
	      return (float) m_mu_nonprompt_float; }, *systematicTree, ("muon_" + var).c_str());
	}
      }
 */   }


    std::vector<std::string> short_mu_vars = {"PromptLeptonInput_sv1_jf_ntrkv", "PromptLeptonInput_TrackJetNTrack"};
    for(std::string var: short_mu_vars) {
        Wrap2(muvec, [=](const xAOD::Muon& mu) {
        short m_mu_nonprompt_short = -99;
        SG::AuxElement::Accessor<short> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_short = AccessorNonPrompt(mu);
        return (short) m_mu_nonprompt_short; }, *systematicTree, ("muon_" + var).c_str());
    }


    std::vector<std::string> float_mu_vars = {"PromptLeptonInput_DL1mu", "PromptLeptonInput_DRlj", "PromptLeptonInput_LepJetPtFrac",
                "PromptLeptonInput_PtFrac", "PromptLeptonInput_PtRel", "PromptLeptonInput_ip2", "PromptLeptonInput_ip3",
                "PromptLeptonInput_rnnip"};
    for(std::string var: float_mu_vars) {
        Wrap2(muvec, [=](const xAOD::Muon& mu){
        float m_mu_nonprompt_float = -99.;
        SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_float = AccessorNonPrompt(mu);
        return (float) m_mu_nonprompt_float;}, *systematicTree, ("muon_" + var).c_str());
    }






	std::vector<std::string> R21_Mu_PLI_vars = {"PromptLeptonIso", "PromptLeptonVeto"};
    for(std::string var: R21_Mu_PLI_vars){
    Wrap2(muvec, [=](const xAOD::Muon& mu) {
    float m_mu_nonprompt_float = -99.;
        SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_float = AccessorNonPrompt(mu);
        return (float) m_mu_nonprompt_float;}, *systematicTree, ("muon_" + var + "_TagWeight").c_str());
    }

    //muon_D BDT
    if(!m_doSystematics) {
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_pt");}, *systematicTree, "muon_jet_pt");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_eta");}, *systematicTree, "muon_jet_eta");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_phi");}, *systematicTree, "muon_jet_phi");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("dRJet");}, *systematicTree, "muon_jet_dr");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_ptRel");}, *systematicTree, "muon_jet_ptRel");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_numTrk");}, *systematicTree, "muon_jet_numTrk");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_sumPtTrk");},*systematicTree, "muon_jet_sumPtTrk");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("MV2c10_weight");},*systematicTree, "muon_jet_MV2c10_Weight");
      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("jet_tagWeightBin");}, *systematicTree, "muon_jet_tagWeightBin");

      Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float> ("muon_BDT");},*systematicTree, "muon_jet_BDT");
    }

    vec_muon_wrappers.push_back(VectorWrapperCollection(muvec));

    // Jets
    std::vector<VectorWrapper*> jetvec;
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.pt(); }, *systematicTree, "m_jet_pt");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.eta(); }, *systematicTree, "m_jet_eta");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.phi(); }, *systematicTree, "m_jet_phi");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.e(); }, *systematicTree, "m_jet_E");
    if(!m_doSystematics) {
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (float) this->getattr_truthJet<float>(jet,"pt");},*systematicTree,"m_truth_jet_pt");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (float) this->getattr_truthJet<float>(jet,"eta");},*systematicTree,"m_truth_jet_eta");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (float) this->getattr_truthJet<float>(jet,"phi");},*systematicTree,"m_truth_jet_phi");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (float) this->getattr_truthJet<float>(jet,"e");},*systematicTree,"m_truth_jet_e");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (float) this->getattr_truthJet<float>(jet,"m");},*systematicTree,"m_truth_jet_m");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (int) this->getattr_truthJet<int>(jet,"GhostHBosonsCount");},*systematicTree,"m_truth_jet_Hcount");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (int) this->getattr_truthJet<int>(jet,"GhostTQuarksFinalCount");},*systematicTree,"m_truth_jet_Tcount");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (int) this->getattr_truthJet<int>(jet,"GhostWBosonsCount");},*systematicTree,"m_truth_jet_Wcount");
      Wrap2(jetvec, [&](const xAOD::Jet& jet) {return (int) this->getattr_truthJet<int>(jet,"GhostZBosonsCount");},*systematicTree,"m_truth_jet_Zcount");
    }


    if(!m_doSystematics) {
      //Wrap2(jetvec, [](const xAOD::Jet& jet) { std::vector<float> tmp = jet.getAttribute<std::vector<float> >("JVF");
      //  return (float) (tmp.size() ? tmp[0] : -2); }, *systematicTree, "m_jet_jvtxf");
      // not in sample xAOD
      //Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("Jvt"); }, *systematicTree, "m_jet_jvt_uncal");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.jetP4("JetEMScaleMomentum").eta(); }, *systematicTree, "m_jet_etaEM");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { float this_jvt = -999.; if(jet.isAvailable<float>("AnalysisTop_JVT"))
        this_jvt = jet.auxdataConst<float>("AnalysisTop_JVT"); return this_jvt;}, *systematicTree, "m_jet_jvt");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { int this_jvt = -1; if(jet.isAvailable<char>("passJVT")) 
        this_jvt = jet.auxdataConst<char>("passJVT"); return this_jvt;}, *systematicTree, "m_jet_passjvt");
      //Jet cleaning flag
      Wrap2(jetvec, [=](const xAOD::Jet& jet) { int keepJet = m_jetCleaningToolLooseBad->keep(jet); return (int)keepJet;}, *systematicTree, "m_jet_isLooseBad");
      //Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); return (float) (btagging ? btagging->MV1_discriminant() : 0.); },
      //  *systematicTree, "m_jet_flavor_weight_MV1");
    }
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0);
      return (float) (btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0.); },
      *systematicTree, "m_jet_flavor_weight_MV2c10");
    //Wrap2(jetvec, [](const xAOD::Jet& jet) { return (jet.isAvailable<short>("ttHJetOVRStatus") ? jet.auxdataConst<short>("ttHJetOVRStatus") : 0); },
    //  *systematicTree, "m_jet_OVRStatus");
    if(!m_doSystematics) {
      Wrap2(jetvec, [&](const xAOD::Jet& jet) { auto tmp = jet.getAttribute<std::vector<int>>(xAOD::JetAttribute::NumTrkPt500);
        return (int)   (tmp.size() ? tmp[m_pv->index()] : 0);  }, *systematicTree, "m_jet_numTrk");
    }
    //Continous b-tag
    //https://twiki.cern.ch/twiki/bin/view/AtlasProtected/BTaggingCalibrationDataInterface#Example_for_continuous_tagging
    //    Wrap2(jetvec, [](const xAOD::Jet& jet){return (int) ( jet.isAvailable<int>("tagWeightBin_MV2c10_Continuous")) ?jet.auxdataConst<int>("tagWeightBin_MV2c10_Continuous") : -5;},      *systematicTree,"m_jet_tagWeightBin");

    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.auxdataConst<char>("ttHpassOVR"); },    *systematicTree, "m_jet_passOR");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.auxdataConst<char>("ttHpassTauOVR"); }, *systematicTree, "m_jet_passTauOR");

    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("ConeTruthLabelID"); }, *systematicTree, "m_jet_flavor_truth_label");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("PartonTruthLabelID"); }, *systematicTree, "m_jet_flavor_truth_label_ghost");

    //////// NOMINAL ONLY
    if(!m_doSystematics) {
      Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c00", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c00");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c20", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c20");
      // is it the 1 GeV counting we want?
      Wrap2(jetvec, [&](const xAOD::Jet& jet) { auto tmp = jet.getAttribute<std::vector<float> >(xAOD::JetAttribute::SumPtTrkPt500); return (float) (tmp.size() ? tmp[m_pv->index()] : 0.); }, *systematicTree, "m_jet_sumPtTrk");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("EMFrac"); }, *systematicTree, "m_jet_emfrac");
      // No label tagging in sample MC
    }

    vec_jet_wrappers.push_back(VectorWrapperCollection(jetvec));

    //Taus
    std::vector<VectorWrapper*> tauvec;
    std::string tauprefix = "m_tau_";
    if(!m_doSystematics) {
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.pt(); },          *systematicTree, std::string(tauprefix+"pt").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.eta(); },         *systematicTree, std::string(tauprefix+"eta").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.phi(); },         *systematicTree, std::string(tauprefix+"phi").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.e(); },           *systematicTree, std::string(tauprefix+"E").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.charge(); },              *systematicTree, std::string(tauprefix+"charge").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.nTracks(); },     *systematicTree, std::string(tauprefix+"numTrack").c_str());
     // Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.nWideTracks(); }, *systematicTree, std::string(tauprefix+"numWideTrack").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.discriminant(xAOD::TauJetParameters::TauID::BDTJetScore); },         *systematicTree, std::string(tauprefix+"BDTJetScore").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.discriminant(xAOD::TauJetParameters::TauID::BDTJetScoreSigTrans); }, *systematicTree, std::string(tauprefix+"BDTJetScoreSigTrans").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigLoose); },   *systematicTree, std::string(tauprefix+"JetBDTSigLoose").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium); },  *systematicTree, std::string(tauprefix+"JetBDTSigMedium").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigTight); },   *systematicTree, std::string(tauprefix+"JetBDTSigTight").c_str());
      
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.auxdataConst<char>("MVATESQuality"); },   *systematicTree, std::string(tauprefix+"MVATESQuality").c_str());
  
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.auxdataConst<char>("ttHpassTauOVR"); }, *systematicTree, std::string(tauprefix+"passOR").c_str());
  
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
        return tau.auxdata<int>("passEleOLR");
      }, *systematicTree, std::string(tauprefix+"passEleOLR").c_str());
    
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
        return tau.auxdata<int>("passEleBDT");
      }, *systematicTree, std::string(tauprefix+"passEleBDT").c_str());

      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
        return tau.auxdata<int>("passMuonOLR");
      }, *systematicTree, std::string(tauprefix+"passMuonOLR").c_str());
      
      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
        return tau.auxdata<int>("IsHadronic");
      }, *systematicTree, std::string(tauprefix+"isHadronicTau").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
        return tau.auxdata<float>("MV2c10");
      }, *systematicTree, std::string(tauprefix+"MV2c10").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	    return tau.auxdata<int>("tagWeightBin");
      }, *systematicTree, std::string(tauprefix+"tagWeightBin").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	    return tau.auxdata<char>("passJVT");
      }, *systematicTree, std::string(tauprefix+"passJVT").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
        return tau.auxdata<char>("fromPV");
      }, *systematicTree, std::string(tauprefix+"fromPV").c_str());
    }

    Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
        return tau.auxdata<float>("BDTEleScoreSigTrans");
    }, *systematicTree, std::string(tauprefix+"BDTEleScoreSigTrans").c_str());

	Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
		return tau.auxdata<float>("BDTJetScoreSigTrans");
	}, *systematicTree, std::string(tauprefix+"BDTJetScoreSigTrans").c_str());

    //////// NOMINAL ONLY
    if(!m_doSystematics) {
      //substructure

      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.auxdataConst<float>("ptTauEtaCalib"); },    *systematicTree, std::string(tauprefix+"ptTauEtaCalib").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.auxdataConst<float>("etaTauEtaCalib"); },   *systematicTree, std::string(tauprefix+"etaTauEtaCalib").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.auxdataConst<float>("phiTauEtaCalib"); },   *systematicTree, std::string(tauprefix+"phiTauEtaCalib").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.auxdataConst<float>("mTauEtaCalib"); },     *systematicTree, std::string(tauprefix+"mTauEtaCalib").c_str());
      

      //Wrap2(tauvec, [](const xAOD::TauJet& tau) {float d = 1e6; tau.detail(xAOD::TauJetParameters::Detail::ipZ0SinThetaSigLeadTrk, d); return d;}, *systematicTree, std::string(tauprefix+"ipZ0SinThetaSigLeadTrk").c_str());
      //Wrap2(tauvec, [](const xAOD::TauJet& tau) {float d = 1e6; tau.detail(xAOD::TauJetParameters::Detail::ipSigLeadTrk, d); return d;}, *systematicTree, std::string(tauprefix+"ipSigLeadTrk").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	  int isTruthMatched = 0;
	  if(tau.isAvailable<char>("IsTruthMatched")) isTruthMatched = (int) tau.auxdata<char>("IsTruthMatched");
	  return isTruthMatched;
	}, *systematicTree, std::string(tauprefix+"isTruthMatched").c_str());

      //decorated in ttHMultileptonLooseEventSaver_Decorate.cxx
      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	  return tau.auxdata<int>("tauTruthOrigin");
	}, *systematicTree, std::string(tauprefix+"truthOrigin").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	  return tau.auxdata<int>("tauTruthType");
	}, *systematicTree, std::string(tauprefix+"truthType").c_str());

      Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	  return tau.auxdata<int>("truthJetFlavour");
	}, *systematicTree, std::string(tauprefix+"truthJetFlavour").c_str());


      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	  return tau.auxdata<float>("ele_match_lhscore");
	}, *systematicTree, std::string(tauprefix+"ele_match_lhscore").c_str());

    }

    std::vector<std::string> short_tau_vars = {"PromptTauInput_TrackJetNTrack"};
    for(std::string var: short_tau_vars) {
        Wrap2(tauvec, [=](const xAOD::TauJet& tau) {
        short m_tau_nonprompt_short = -99;
        SG::AuxElement::Accessor<short> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(tau)) m_tau_nonprompt_short = AccessorNonPrompt(tau);
        return (short) m_tau_nonprompt_short; }, *systematicTree, (tauprefix + var).c_str());
    }


    std::vector<std::string> float_tau_vars = {"PromptTauInput_DRlj","PromptTauInput_JetF", "PromptTauInput_LepJetPtFrac",
                "PromptTauInput_MV2c10rnn", "PromptTauInput_SV1", "PromptTauInput_ip2", "PromptTauInput_ip3",
                "PromptTauInput_rnnip", "PromptTauInput_MV2c10"};
    for(std::string var: float_tau_vars) {
        Wrap2(tauvec, [=](const xAOD::TauJet& tau){
        float m_tau_nonprompt_float = -99.;
        SG::AuxElement::Accessor<float> AccessorNonPrompt(var);
        if(AccessorNonPrompt.isAvailable(tau)) m_tau_nonprompt_float = AccessorNonPrompt(tau);
        return (float) m_tau_nonprompt_float;}, *systematicTree, (tauprefix + var).c_str());
    }	



	  Wrap2(tauvec, [=](const xAOD::TauJet& tau) {
	  float m_tau_PTV_float = -99.;
		SG::AuxElement::Accessor<float> AccessorNonPrompt("PromptTauVeto");
		if(AccessorNonPrompt.isAvailable(tau)) m_tau_PTV_float = AccessorNonPrompt(tau);
		return (float) m_tau_PTV_float;}, *systematicTree, std::string(tauprefix+"PromptTauVeto").c_str());

      Wrap2(tauvec, [=](const xAOD::TauJet& tau) {
      float m_tau_PTI_float = -99.;
        SG::AuxElement::Accessor<float> AccessorNonPrompt("PromptTauIso");
        if(AccessorNonPrompt.isAvailable(tau)) m_tau_PTI_float = AccessorNonPrompt(tau);
        return (float) m_tau_PTI_float;}, *systematicTree, std::string(tauprefix+"PromptTauIso").c_str());



    vec_tau_wrappers.push_back(VectorWrapperCollection(tauvec));

    //Truth jets
    //std::vector<VectorWrapper*> trjetvec;
    //Wrap2(trjetvec, [](const xAOD::Jet& trjet) { return (float) trjet.pt();  }, *systematicTree, "m_jetTruth_pt");
    //Wrap2(trjetvec, [](const xAOD::Jet& trjet) { return (float) trjet.eta(); }, *systematicTree, "m_jetTruth_eta");
    //Wrap2(trjetvec, [](const xAOD::Jet& trjet) { return (float) trjet.phi(); }, *systematicTree, "m_jetTruth_phi");
    //Wrap2(trjetvec, [](const xAOD::Jet& trjet) { return (float) trjet.e();   }, *systematicTree, "m_jetTruth_E");

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
ORUtils::ORFlags OR_flags("OverlapRemovalToolElMu",
			    "passPreORSelection");
  OR_flags.doElectrons = m_config->useElectrons();
  OR_flags.doMuons     = m_config->useMuons();
  OR_flags.doJets      = false;
  OR_flags.doTaus      = false;
  OR_flags.doPhotons   = false;
  OR_flags.outputLabel = "sharesTrk";

  top::check(ORUtils::recommendedTools(OR_flags,m_ORtoolBox[0]),
	     "Failed to setup OR Tool box");

  // if (m_config->useMuons() && m_config->useElectrons())
  //   top::check(m_ORtoolBox[0].eleMuORT.setProperty("RemoveCaloMuons", false),
  // 	       "Failed to set RemoveCaloMuons in eleMuORT");

  top::check(m_ORtoolBox[0].initialize(),
	     "Failed to initialize overlap removal tools");
  m_overlapRemovalTool[0] = std::move(m_ORtoolBox[0].masterTool);

  // everything
  ORUtils::ORFlags OR_flags_nominal("OverlapRemovalttHNom",
				    "",
				    "ttHpassTauOVR");
  OR_flags_nominal.doElectrons = m_config->useElectrons();
  OR_flags_nominal.doMuons     = m_config->useMuons();
  OR_flags_nominal.doJets      = true;
  OR_flags_nominal.doTaus      = true;
  OR_flags_nominal.doPhotons   = false;
  OR_flags_nominal.outputPassValue = true;

  top::check(ORUtils::recommendedTools(OR_flags_nominal,m_ORtoolBox[1]),
	     "Failed to setup OR Tool box for nominal selections");

  top::check(m_ORtoolBox[1].muJetORT.setProperty("MuJetPtRatio", 100000),
  	     "Failed to set MuJetPtRatio to a crazy threshold");
  top::check(m_ORtoolBox[1].muJetORT.setProperty("MuJetTrkPtRatio", 100000),
             "Failed to set MuJetTrkPtRatio to a crazy threshold");

  // if (m_config->useMuons() && m_config->useElectrons())
  //   top::check(m_ORtoolBox[1].eleMuORT.setProperty("RemoveCaloMuons", false),
  // 	       "Failed to set RemoveCaloMuons in nominal OR");

  top::check(m_ORtoolBox[1].initialize(),
	     "Failed to initialize overlap removal tools for nominal selection");
  m_overlapRemovalTool[1] = std::move(m_ORtoolBox[1].masterTool);

  // everything except tau
  ORUtils::ORFlags OR_flags_nominal_no_tau("OverlapRemovalttHNomNoTau",
					   "",
					   "ttHpassOVR");
  OR_flags_nominal_no_tau.doElectrons = m_config->useElectrons();
  OR_flags_nominal_no_tau.doMuons     = m_config->useMuons();
  OR_flags_nominal_no_tau.doJets      = true;
  OR_flags_nominal_no_tau.doTaus      = false;
  OR_flags_nominal_no_tau.doPhotons   = false;
  OR_flags_nominal_no_tau.outputPassValue = true;
  OR_flags_nominal_no_tau.outputLabel = "ttHpassOVR";

  top::check(ORUtils::recommendedTools(OR_flags_nominal_no_tau,m_ORtoolBox[2]),
	     "Failed to setup OR Tool box for nominal-but-tau selections");

  // if (m_config->useMuons() && m_config->useElectrons())
  //   top::check(m_ORtoolBox[2].eleMuORT.setProperty("RemoveCaloMuons", false),
  // 	       "Failed to set RemoveCaloMuons in nominal-but-tau OR");

  top::check(m_ORtoolBox[2].muJetORT.setProperty("MuJetPtRatio", 100000),
             "Failed to set MuJetPtRatio to a crazy threshold");
  top::check(m_ORtoolBox[2].muJetORT.setProperty("MuJetTrkPtRatio", 100000),
             "Failed to set MuJetTrkPtRatio to a crazy threshold");


  top::check(m_ORtoolBox[2].initialize(),
	     "Failed to initialize overlap removal tools for nominal selection");
  m_overlapRemovalTool[2] = std::move(m_ORtoolBox[2].masterTool);

  //for decorating the OR decision back onto the vectors
  m_decor_ttHpassOVR    = new SG::AuxElement::Decorator< char >("ttHpassOVR");
  m_decor_ttHpassTauOVR = new SG::AuxElement::Decorator< char >("ttHpassTauOVR");



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
  if (top::isSimulation(event)) {
    m_runNumber = m_purwtool->getRandomRunNumber(*event.m_info);
  } else {
    m_runNumber = event.m_info->runNumber();
  }
  m_mu_ac   = event.m_info->actualInteractionsPerCrossing();
  m_mu_unc  = event.m_info->averageInteractionsPerCrossing();
  //see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/ExtendedPileupReweighting#Using_the_tool_for_pileup_reweig
  if (m_runNumber >= 320000) {
    m_runYear = 2017;
  } else if (m_runNumber >=290000) {
    m_runYear = 2016;
  } else if (m_runNumber > 0) {
    m_runYear = 2015;
  } else {
    m_runYear = 0;
  }

  // waiting for fix in TopCorrections
 // m_mu      = m_purwtool->getCorrectedMu( *event.m_info, false);
  m_mu      = m_purwtool->getCorrectedAverageInteractionsPerCrossing( *event.m_info, false);

  if(top::isSimulation(event)){
    m_mu      = m_mu_unc;
    m_pu_hash = m_purwtool->getPRWHash( *event.m_info );
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

  //if (event.m_info->eventFlags(EventInfo::EventFlagSubDet::Background) &(1<<17)) std::cout << "Background flag is HaloMuon Segment" << std::endl;

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
           //std::cout << motherPdgId << " " << particle->barcode() << " " << particle->p4().DeltaR(mother->p4()) << " " << particle->pt() << std::endl;
	  //          double dr = particle->p4().DeltaR(mother->p4()); // always look at DR
	  //          if (dr > 0.2 && particle->pt() > 15e3 && (abs(motherPdgId) < 11 || abs(motherPdgId) > 18))
          // if (dr > 0.2 && particle->pt() > 15e3 && (abs(motherPdgId) < 11 || abs(motherPdgId) > 18) && m_mcChannelNumber == 410082) {
          //   m_MEphoton_OLtty_cat1 = true;
          //   m_MEphoton_OLtty_keepEvent = true;  // this is tty - top left cell of the tty table, > 15 GeV
          // } else if (dr > 0.2 && particle->pt() > 15e3 && (abs(motherPdgId) >= 11 && abs(motherPdgId) <= 18) && m_mcChannelNumber != 410082) {
          //   m_MEphoton_OLtty_cat2 = true;
          //   m_MEphoton_OLtty_keepEvent = true;  // this is ttbar - top right cell of the ttbar table
          // } else if (dr < 0.2  && particle->pt() > 15e3 && m_mcChannelNumber != 410082) {
          //   m_MEphoton_OLtty_cat3 = true;
          //   m_MEphoton_OLtty_keepEvent = true;  // this is ttbar, dr < 0.2 row from the ttbar table
          // } else if (particle->pt() < 15e3 && m_mcChannelNumber != 410082) {
           //   m_MEphoton_OLtty_cat4 = true;
          //   m_MEphoton_OLtty_keepEvent = true;  // this is ttbar, ME photon pT < 15000 regardless the DR
          // }
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
      }
     }
    }
  }
  // if (!m_hasMEphoton)
  //   m_MEphoton_OLtty_keepEvent = true;

  // Truth Matching
//  if ( top::isSimulation(event) ) {
//    top::check( m_truthMatchAlgo->executeTruthMatching(event), "Failed to execute executeTruthMatching(). Aborting");
//  }
/*
  //ttbar HF classification
  std::set<unsigned int> ttHF_samples =
  {
    410000,
    410001,
    410002,
    410003,
    410009,
    410004,
    410159,
    410187,
    410188,
    410189,
    410500,
    410501,
    410503,
    410512,
    410225,
    410226,
    410250,
    410251,
    410252,
    410155,
    410156,
    410157,
    410218,
    410219,
    410220,
    410397,
    410398,
    410399,
    410276,
    410277,
    410278,
  };
  //std::cout << "m_mcChannelNumber: " << m_mcChannelNumber << std::endl;
  if ( top::isSimulation(event) && ttHF_samples.count(m_mcChannelNumber) ){
    m_HF_Classification=m_classifyttbarHF->ClassifyEvent(event);
    //std::cout << "HF classification is: " << m_HF_Classification  << std::endl;
  }
  if(event.m_info->isAvailable<int>("TopHeavyFlavorFilterFlag")) {
    m_HF_ClassificationTop = event.m_info->auxdata<int>("TopHeavyFlavorFilterFlag");
  }*/

  //ttbar DLF, MLF classification
  if (top::isSimulation(event)) {
//    m_DLF_Classification = truthSelector.CountTopWLeptons(event.m_truth);
    //m_MLF_Classification = truthSelector.CountLightLeptons(event.m_truth, 10e3, 2.6);
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

  //Event selection variable for each event selection region (pass/fail)
 // recordSelectionDecision(event);

/*
  if(top::isSimulation(event) and !m_doSystematics) {
    // MET Truth
    const xAOD::MissingETContainer* truthMETCont(nullptr);
    top::check( evtStore()->retrieve(truthMETCont, "MET_Truth"),"Failed to retrieve MET_Truth container");

    // https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/Run2xAODMissingET
    //
    const xAOD::MissingET* truthMET = *(truthMETCont->find("NonInt"));

    m_truthMET_px = truthMET->mpx();
    m_truthMET_py = truthMET->mpy();
    m_truthMET_phi = truthMET->phi();
    m_truthMET_sumet = truthMET->sumet();
  }
*/
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


  // for (const auto* const elPtr : event.m_electrons) {
  //   std::cout << "Passes?" << elPtr->auxdataConst< char >("passPreORSelection") << std::endl;
  // }

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

  if(!m_doSystematics){
    vec_vtx_wrappers[event.m_ttreeIndex].push_all(*m_vertices);
  }

    const xAOD::ElectronContainer* Electrons(nullptr);
    const xAOD::MuonContainer* Muons(nullptr);
    const xAOD::JetContainer* Jets(nullptr);
    const xAOD::TauJetContainer* Taus(nullptr);
    const xAOD::JetContainer* SelJets(nullptr);
    top::check( evtStore()->retrieve(Electrons,"SelectedORElectrons_"+m_config->systematicName(event.m_hashValue) ),"Failed to retrieve Electrons");
    top::check( evtStore()->retrieve(Muons,"SelectedORMuons_"+m_config->systematicName(event.m_hashValue) ),"Failed to retrieve Muons");
    top::check( evtStore()->retrieve(Jets,"SelectedORJets_"+m_config->systematicName(event.m_hashValue) ),"Failed to retrieve JEts");
    top::check( evtStore()->retrieve(Taus,"SelectedORTaus_"+m_config->systematicName(event.m_hashValue) ),"Failed to retrieve Taus");
    CopyLeptons(*Electrons,*Muons);
    CopyJets(*Jets);
    //MakeJetIndices(*Jets,event.m_jets);
    CopyTaus(*Taus);
    CopyHT(*Electrons,*Muons,*Jets,*Taus);
    CheckIsBlinded();
    if (m_isMC){
    doEventTrigSFs(*Electrons,*Muons,event);}
    //m_ttHEvent->AssignOutput(m_ttHEvent,tthevt);   
  xAOD::JetContainer* calibratedJets(nullptr);
  top::check(evtStore()->retrieve(calibratedJets, m_config->sgKeyJetsTDS(sysHash,false)), "Failed to retrieve calibrated jets");

  vec_electron_wrappers[event.m_ttreeIndex].push_all(event.m_electrons);
  vec_scalar_wrappers[event.m_ttreeIndex].push_all(event);
  vec_muon_wrappers[event.m_ttreeIndex].push_all(event.m_muons);
  vec_tau_wrappers[event.m_ttreeIndex].push_all(event.m_tauJets);

    //Assigning SFs to output
    m_ttHEvent->lepSFIDLoose = tthevt->lepSFIDLoose;
    m_ttHEvent->lepSFIDTight = tthevt->lepSFIDTight;
    m_ttHEvent->lepSFIsoLoose = tthevt->lepSFIsoLoose;
    m_ttHEvent->lepSFIsoTight = tthevt->lepSFIsoTight;
    m_ttHEvent->lepSFReco = tthevt->lepSFReco;
    m_ttHEvent->lepSFTTVA = tthevt->lepSFTTVA;

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

  top::check( evtStore()->retrieve(SelJets,"SelectedJets_"+m_config->systematicName(event.m_hashValue)),"Failed to retrieve JEts_2");
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
  if(m_doSystematics) {
   for(auto alljet : event.m_jets) {
      for(auto goodjet : *Jets) {
	if( goodjet->p4() == alljet->p4() ) {
	  (*m_decor_ttHpassOVR)   (*alljet) = (*m_decor_ttHpassOVR)   (*goodjet);
	  (*m_decor_ttHpassTauOVR)(*alljet) = (*m_decor_ttHpassTauOVR)(*goodjet);
	}
      }
    }

    vec_jet_wrappers[event.m_ttreeIndex].push_all(event.m_jets);
    MakeJetIndices(*Jets, event.m_jets);
  }
  else {
   for(auto alljet : *calibratedJets) {
      for(auto goodjet : *Jets ) {
	if( goodjet->p4() == alljet->p4() ) {
	  (*m_decor_ttHpassOVR)   (*alljet) = (*m_decor_ttHpassOVR)   (*goodjet);
	  (*m_decor_ttHpassTauOVR)(*alljet) = (*m_decor_ttHpassTauOVR)(*goodjet);
	}
      }
    }
    vec_jet_wrappers[event.m_ttreeIndex].push_all(*calibratedJets);
    MakeJetIndices(*Jets, *calibratedJets);
  }


  top::EventSaverFlatNtuple::saveEvent(event);
  tthevt->clearReco();




    ///-- Let the base class do all the hard work --///
  //  top::EventSaverFlatNtuple::saveEvent(event);
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

