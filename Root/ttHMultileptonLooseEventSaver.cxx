#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "xAODMissingET/MissingETContainer.h"

//Top
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "TopConfiguration/ConfigurationSettings.h"
#include "TopParticleLevel/ParticleLevelEvent.h"

//ROOT
#include "TFile.h"
#include "TH1.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

//ASG OR
#include "AssociationUtils/OverlapRemovalInit.h"

ttHMultileptonLooseEventSaver::ttHMultileptonLooseEventSaver() :
  m_outputFile(nullptr),
  m_doSystematics(false),
  m_doSFSystematics(true),
  m_sfRetriever(nullptr),
  m_trigDecTool("Trig::TrigDecisionTool"),
  m_purwtool("CP::PileupReweightingTool"),
  m_jetCleaningToolLooseBad("JetCleaningToolLooseBad"),
  muonSelection("MuonSelection"),
  iso_1( "iso_1" ),
  m_tauSelectionEleOLR("TauSelectionEleOLR"),
  m_mcWeight(1.),
  m_pileup_weight(1.),
  m_bTagSF_weight(1.),
  m_JVT_weight(1.),
  m_eventNumber(0),
  m_runNumber(0),
  m_mcChannelNumber(0),
  m_mu(0),
  m_mu_unc(0),
  m_mu_ac(0),
  m_pu_hash(0),
  m_pvNumber(0),
  m_puNumber(0),
  m_pv(nullptr),
  m_runYear(0),
  m_HF_Classification(0.),
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
  m_higgs(nullptr)
{}

ttHMultileptonLooseEventSaver::~ttHMultileptonLooseEventSaver(){}

// Dearest and most respected user
// The following is black magic, don't worry too much about how it works
// just know that you can store vectors of information like this
// In the EventSaver class header, add a member variable to store the wrappers
// (this is a vector because we have one for each tree to be written out)
//
// std::vector<VectorWrapperCollection> vec_electron_wrappers;
//
// In initialization, create a vector of "VectorWrapper*"
//
// std::vector<VectorWrapper*> elevec;
//
// then use Wrap2 to specify functions to compute all the variables you
// want to store, e.g.
//
// Wrap2(elevec, [](const xAOD::Electron& ele) { return (float) ele.pt(); }, *systematicTree, "electron_pt");
//
// the second argument is a "lambda function" - a function that you create
// just at this point, which takes the argument "ele".  (For those of you
// who know details of C++11, only non-capturing lambdas ([]) can be used.)
// The type of vector stored in the TTree will be automatically determined
// based on the return value of the lambda function.
// Fully initialize the VectorWrapperCollection vector
//
// vec_electron_wrappers.push_back(VectorWrapperCollection(elevec));
//
// Finally, in the actual event loop (saveEvent), push the vector of objects to
// save through the relevant VectorWrapperCollection:
//
// vec_electron_wrappers[event.m_ttreeIndex].push_all(event.m_electrons);
//

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

void ttHMultileptonLooseEventSaver::initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches) {

  //EventSaverFlatNtuple::initialise(config, file, treeNames, extraBranches);
  m_outputFile = file;
  m_extraBranches = extraBranches;
  m_selectionDecisions.resize(m_extraBranches.size());

  m_config = config;

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
  m_eleCutflow = new TH1I("eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
  int idx = 1;
  for (const auto& label : { "initial", "pt", "eta", "ident", "z0sinth", "d0sig", "iso", "e-#mu OR", "e-e OR"}) {
    m_eleCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_muCutflow = new TH1I("muCutflow", "Muon cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto& label : { "initial", "eta/qual", "pt", "z0sinth", "d0sig", "iso", "#mu-jet OR"}) {
    m_muCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_jetCutflow = new TH1I("jetCutflow", "Jet cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto& label : { "initial", "cleaning", "pt", "eta", "jvt", "jet-e OR", "jet-#tau OR"}) {
    m_jetCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_tauCutflow = new TH1I("tauCutflow", "Tau cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto& label : { "initial", "charge", "ntracks", "eta", "jetbdt", "pt", "EleOLR", "#tau-e,#mu OR"}) {
    m_tauCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }

  m_variables = new ttHMultilepton::Variables();

  m_truthMatchAlgo  = new ttHMultilepton::TruthMatchAlgo();
  m_truthMatchAlgo->msg().setLevel( MSG::INFO ); // DEBUG, VERBOSE, WARNING, INFO

  m_classifyttbarHF = new ttHMultilepton::ClassifyHF("AntiKt4TruthJets");

  if (m_isMC){
    top::check( m_sherpaRW.retrieve(), "Failed to retrieve PMGSherpa22VJetsWeightTool" );
    top::check( m_sherpaRW->setProperty("TruthJetContainer", "AntiKt4TruthJets"),
		"Failed to set TruthJetContainer of PMGSherpa22VJetsWeightTool" );
    top::check( m_sampleXsection.readFromFile((std::string(getenv("ROOTCOREBIN"))+"/data/TopDataPreparation/XSection-MC15-13TeV.data").c_str()),
		"Failed to open AMI X-section file");
  }

  //prepare btag eigen vectors
  if (m_isMC) {
    m_weight_bTagSF_70_eigen_B_up      .resize(m_config->btagging_num_B_eigenvars("FixedCutBEff_70") );
    m_weight_bTagSF_70_eigen_B_down    .resize(m_config->btagging_num_B_eigenvars("FixedCutBEff_70") );
    m_weight_bTagSF_70_eigen_C_up      .resize(m_config->btagging_num_C_eigenvars("FixedCutBEff_70") );
    m_weight_bTagSF_70_eigen_C_down    .resize(m_config->btagging_num_C_eigenvars("FixedCutBEff_70") );
    m_weight_bTagSF_70_eigen_Light_up  .resize(m_config->btagging_num_Light_eigenvars("FixedCutBEff_70") );
    m_weight_bTagSF_70_eigen_Light_down.resize(m_config->btagging_num_Light_eigenvars("FixedCutBEff_70") );
  }
  //init Tools

  //Pileup Reweighting Tool from TopToolStore
  top::check( m_purwtool.retrieve() , "Failed to retrieve PileupReweightingTool" );

  //Trigger Tool from TopToolStore
  top::check( m_trigDecTool.retrieve() , "Failed to retrieve TrigDecisionTool" );

  //Isolation tools for leptons
  //    top::check( iso_1.setProperty("MuonWP","Loose"),"IsolationTool fails to set MuonWP" );
  //    top::check( iso_1.setProperty("ElectronWP","Loose"),"IsolationTool fails to set ElectronWP");
  top::check( iso_1.initialize(),"IsolationTool fails to initialize");
  auto isolation_WPs{"LooseTrackOnly", "Loose", "Gradient", "GradientLoose","FixedCutTightTrackOnly","FixedCutLoose"};
  for (auto wp : isolation_WPs) {
    top::check( iso_1.addMuonWP(wp), "Error adding muon isolation WP" );
    top::check( iso_1.addElectronWP(wp), "Error adding electron isolation WP" );
  }
  /// special case for FixedCutTight (el only)
  top::check( iso_1.addElectronWP("FixedCutTight"), "Error adding electron isolation WP" );

  //Muon Tools
  //top::check( muonSelection.setProperty("OutputLevel", MSG::VERBOSE),"muonSelection fails to set OutputLevel");
  top::check( muonSelection.setProperty( "MaxEta", (double)m_config->muonEtacut() ), "muonSelection tool could not set max eta");
  top::check( muonSelection.initialize(),"muonSelection tool fails to initialize");

  //Jet Tool from Top Tool Store
  top::check( m_jetCleaningToolLooseBad.retrieve() , "Failed to retrieve JetCleaningToolLooseBad" );

  //Tau Tools
  //m_tauSelectionEleOLR.msg().setLevel(MSG::VERBOSE);
  top::check( m_tauSelectionEleOLR.setProperty("ConfigPath", "ttHMultilepton/EleOLR_tau_selection.conf" ), "TauSelectionEleOLR:Failed to set ConfigPath");
  top::check( m_tauSelectionEleOLR.initialize(), "Failed to initialise TauSelectionTool for EleOLR" );


  //define triggers
  //Items and their PS
  // defined in config files with TRIGDEC selectors
  // "triggers" is the name of that dummy selection
  std::vector<std::string> triggernames = config->allTriggers("triggers");

  //make a tree for each systematic
  for (auto treeName : *config->systAllTTreeNames()) {
    std::cout << "INITIALIZING SYST TREES" << std::endl;
    m_treeManagers.push_back(std::shared_ptr<top::TreeManager>( new top::TreeManager(treeName.second, file) ) );
    std::cout << m_treeManagers.size() << " " << treeName.second << std::endl;
    }

  for (auto systematicTree : m_treeManagers){
    m_doSFSystematics = systematicTree->name() ==  m_config->systematicName(m_config->nominalHashValue());
    if(!m_isMC) m_doSFSystematics = false;

    systematicTree->makeOutputVariable(m_mcWeight,      "mcWeightOrg");
    systematicTree->makeOutputVariable(m_pileup_weight, "pileupEventWeight_090");
    systematicTree->makeOutputVariable(m_bTagSF_weight, "MV2c10_70_EventWeight");
    systematicTree->makeOutputVariable(m_bTagSF77_weight, "MV2c10_77_EventWeight");
    systematicTree->makeOutputVariable(m_JVT_weight,    "JVT_EventWeight");

    if ( m_doSFSystematics ) {

      //pileup
      systematicTree->makeOutputVariable(m_pileup_weight_UP,   "pileupEventWeight_UP");
      systematicTree->makeOutputVariable(m_pileup_weight_DOWN, "pileupEventWeight_DOWN");

      //btag
      //B
      for( unsigned int i=0; i<m_config->btagging_num_B_eigenvars("FixedCutBEff_70"); ++i) {
	std::stringstream branchName; branchName << "MV2c10_70_EventWeight_B" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_B_up.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_B_down.at(i),
					   branchNameDown );
      }
      //C
      for( unsigned int i=0; i<m_config->btagging_num_C_eigenvars("FixedCutBEff_70"); ++i) {
	std::stringstream branchName; branchName << "MV2c10_70_EventWeight_C" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_C_up.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_C_down.at(i),
					   branchNameDown );
      }
      //Light
      for( unsigned int i=0; i<m_config->btagging_num_Light_eigenvars("FixedCutBEff_70"); ++i) {
	std::stringstream branchName; branchName << "MV2c10_70_EventWeight_Light" << i;
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_Light_up.at(i),
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_Light_down.at(i),
					   branchNameDown );
      }
      //Others (extrapolation)
      for (auto name : m_config->btagging_namedSysts("FixedCutBEff_70")) {
	std::stringstream branchName; branchName << "MV2c10_70_EventWeight_" << betterBtagNamedSyst(name);
	std::string branchNameUp  (branchName.str()); branchNameUp   += "_up";
	std::string branchNameDown(branchName.str()); branchNameDown += "_down";

	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_Others_up[name],
					   branchNameUp );
	systematicTree->makeOutputVariable(m_weight_bTagSF_70_eigen_Others_down[name],
					   branchNameDown );
      }

      // systematicTree->makeOutputVariable(m_weight_bTagSF_70_extrapolation_up,
      // 					 "MV2c10_70_EventWeight_extrapolation_up" );
      // systematicTree->makeOutputVariable(m_weight_bTagSF_70_extrapolation_down,
      // 					 "MV2c10_70_EventWeight_extrapolation_down" );

      // systematicTree->makeOutputVariable(m_weight_bTagSF_70_extrapolation_from_charm_up,
      // 					 "MV2c10_70_EventWeight_extrapolation_from_charm_up" );
      // systematicTree->makeOutputVariable(m_weight_bTagSF_70_extrapolation_from_charm_down,
      // 					 "MV2c10_70_EventWeight_extrapolation_from_charm_down" );

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
      systematicTree->makeOutputVariable(m_trjet_e,   "m_truth_jet_e");

      //truthEvent information
      systematicTree->makeOutputVariable(m_PDFinfo_x1,        "m_mcevt_pdf_x1");
      systematicTree->makeOutputVariable(m_PDFinfo_x2,        "m_mcevt_pdf_x2");
      systematicTree->makeOutputVariable(m_PDFinfo_id1,       "m_mcevt_pdf_id1");
      systematicTree->makeOutputVariable(m_PDFinfo_id2,       "m_mcevt_pdf_id2");
      systematicTree->makeOutputVariable(m_PDFinfo_scalePDF,  "m_mcevt_pdf_scale");
      systematicTree->makeOutputVariable(m_PDFinfo_pdf1,      "m_mcevt_pdf_pdf1");
      systematicTree->makeOutputVariable(m_PDFinfo_pdf2,      "m_mcevt_pdf_pdf2");
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
	    return event.m_info->isAvailable<int>("TTHML_NTruthJet") ? event.m_info->auxdataConst<int>("TTHML_NTruthJet") : 0.0;
	  }, *systematicTree, "nTruthJets");

    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->pt()             : 0.0; }, *systematicTree, "higgs_pt");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->eta()            : 0.0; }, *systematicTree, "higgs_eta");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->phi()            : 0.0; }, *systematicTree, "higgs_phi");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->e()              : 0.0; }, *systematicTree, "higgs_E");
    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->p4().Rapidity()  : 0.0; }, *systematicTree, "higgs_rapidity");

    systematicTree->makeOutputVariable(m_runYear, "RunYear");

    // HF classification ttbar
    systematicTree->makeOutputVariable(m_HF_Classification, "HF_Classification");

    systematicTree->makeOutputVariable(m_higgsMode,      "higgsDecayMode");

    systematicTree->makeOutputVariable(m_mcChannelNumber, "mc_channel_number");
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

    for (auto trigger : triggernames) {
      WrapS(scalarvec, [=](const top::Event&){ return (unsigned int) m_trigDecTool->isPassed( trigger ) ; }, *systematicTree, trigger.c_str());
      if(!m_doSystematics) WrapS(scalarvec, [=](const top::Event&){ return (float) m_trigDecTool->getPrescale( trigger ); }, *systematicTree, (trigger + "_PS").c_str());
    }
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
    for (auto wp : isolation_WPs) {
      std::string isoname("Iso_"); isoname += wp;
      std::string eleisoname("electron_isolation"); eleisoname += wp;
      std::string muisoname("muon_isolation"); muisoname += wp;
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>(isoname); }, *systematicTree, eleisoname.c_str());
      Wrap2(muvec,  [=](const xAOD::Muon& mu) {      return (char)  mu.auxdataConst<short>(isoname); }, *systematicTree, muisoname.c_str());
    }

    /// special case for FixedCutTight (el only)
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>("Iso_FixedCutTight"); }, *systematicTree, "electron_isolationFixedCutTight");

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

    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("d0sig"); },             *systematicTree, "electron_sigd0PV");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("delta_z0_sintheta"); }, *systematicTree, "electron_z0SinTheta");

    //Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone20); return iso; }, *systematicTree, "electron_ptcone20");
    //Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone30); return iso; }, *systematicTree, "electron_ptcone30");
    //Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone40); return iso; }, *systematicTree, "electron_ptcone40");

    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone20); return iso; }, *systematicTree, "electron_topoetcone20");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone30); return iso; }, *systematicTree, "electron_topoetcone30");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone40); return iso; }, *systematicTree, "electron_topoetcone40");
    //miniiso
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone20); return iso; }, *systematicTree, "electron_ptvarcone20");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone30); return iso; }, *systematicTree, "electron_ptvarcone30");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone40); return iso; }, *systematicTree, "electron_ptvarcone40");

    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<int>("passLHLoose"); },  *systematicTree, "electron_isLooseLH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<int>("passLHMedium"); }, *systematicTree, "electron_isMediumLH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<int>("passLHTight"); },  *systematicTree, "electron_isTightLH");

    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<char>("sharesTrk"); },  *systematicTree, "electron_sharesTrk");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<char>("ttHpassOVR"); }, *systematicTree, "electron_passOR");

    //non-prompt bdt vars
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	  float m_el_nonprompt_bdt = -99.;
	  static SG::AuxElement::Accessor<float> AccessorNonPromptBDT("PromptLepton_TagWeight");
	  if(AccessorNonPromptBDT.isAvailable(ele)) m_el_nonprompt_bdt = AccessorNonPromptBDT(ele);
	  return (float) m_el_nonprompt_bdt; }, *systematicTree, "electron_PromptLepton_TagWeight");
    Wrap2(elevec, [=](const xAOD::Electron& ele) {
	short m_el_nonprompt_short = -99;
	SG::AuxElement::Accessor<short> AccessorNonPrompt("PromptLepton_TrackJetNTrack");
	if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_short = AccessorNonPrompt(ele);
	return (short) m_el_nonprompt_short; }, *systematicTree, "electron_PromptLepton_TrackJetNTrack");

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

      // Add non-prompt electron vars
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<double>("jetFitterComb"); }, *systematicTree, "electron_jetFitterComb");

      std::vector<std::string> short_vars = {"sv1_ntkv", "jf_ntrkv"};
      for(std::string var: short_vars) {
	Wrap2(elevec, [=](const xAOD::Electron& ele) {
	    short m_el_nonprompt_short = -99;
	    SG::AuxElement::Accessor<short> AccessorNonPrompt("PromptLepton_"+ var);
	    if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_short = AccessorNonPrompt(ele);
	    return (short) m_el_nonprompt_short; }, *systematicTree, ("electron_PromptLepton_" + var).c_str());
      }

      bool m_writeAllNonPromptInputVars = true;

      if(m_writeAllNonPromptInputVars) {
	std::vector<std::string> float_vars = {"ip2", "ip2_cu", "ip3", "ip3_cu", "EtTopoCone20Rel"};
	for(std::string var: float_vars) {
	  Wrap2(elevec, [=](const xAOD::Electron& ele) {
	      float m_el_nonprompt_float = -99.;
	      SG::AuxElement::Accessor<float> AccessorNonPrompt("PromptLepton_" + var);
	      if(AccessorNonPrompt.isAvailable(ele)) m_el_nonprompt_float = AccessorNonPrompt(ele);
	      return (float) m_el_nonprompt_float; }, *systematicTree, ("electron_PromptLepton_" + var).c_str());
	}
      }
    }

    vec_electron_wrappers.push_back(VectorWrapperCollection(elevec));

    // Muons
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.pt(); },  *systematicTree, "muon_pt");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.eta(); }, *systematicTree, "muon_eta");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.phi(); }, *systematicTree, "muon_phi");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.e(); },   *systematicTree, "muon_E");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Loose && muonSelection.passedIDCuts(mu))  isqual=1; return isqual;},*systematicTree, "muon_isLoose");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Medium && muonSelection.passedIDCuts(mu)) isqual=1; return isqual;},*systematicTree, "muon_isMedium");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Tight && muonSelection.passedIDCuts(mu))  isqual=1; return isqual;},*systematicTree, "muon_isTight");
    // Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdata<float>("InnerDetectorPt"); },    *systematicTree, "muon_PtID");
    // Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdata<float>("MuonSpectrometerPt"); }, *systematicTree, "muon_PtME");
    // Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.allAuthors(); }, *systematicTree, "muon_allAuthor");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) (-13*mu.charge()); }, *systematicTree, "muon_ID");

    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("d0sig"); }, *systematicTree, "muon_sigd0PV");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("delta_z0_sintheta"); }, *systematicTree, "muon_z0SinTheta");

    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float momBalSignif = mu.floatParameter(xAOD::Muon::momentumBalanceSignificance); return (float) (momBalSignif); }, *systematicTree, "muon_momBalSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatCurvSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatNeighSignif = mu.floatParameter(xAOD::Muon::scatteringNeighbourSignificance); return (float) (scatNeighSignif); }, *systematicTree, "muon_scatNeighSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float qOverPSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { return (short) mu.uint8SummaryValue(xAOD::SummaryType::numberOfPrecisionLayers); }, *systematicTree, "muon_numPrecLayers");

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
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return mu.auxdataConst<char>("ttHpassOVR"); }, *systematicTree, "muon_passOR");

    //non-prompt bdt vars
    Wrap2(muvec, [=](const xAOD::Muon& mu) {
	  float m_mu_nonprompt_bdt = -99.;
	  static SG::AuxElement::Accessor<float> AccessorNonPromptBDT("PromptLepton_TagWeight");
	  if(AccessorNonPromptBDT.isAvailable(mu)) m_mu_nonprompt_bdt = AccessorNonPromptBDT(mu);
	  return (float) m_mu_nonprompt_bdt; }, *systematicTree, "muon_PromptLepton_TagWeight");
    Wrap2(muvec, [=](const xAOD::Muon& mu) {
	short m_mu_nonprompt_short = -99;
	static SG::AuxElement::Accessor<short> AccessorNonPrompt("PromptLepton_TrackJetNTrack");
	if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_short = AccessorNonPrompt(mu);
	return (short) m_mu_nonprompt_short; }, *systematicTree, "muon_PromptLepton_TrackJetNTrack");

    //Trigger matching

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

      std::vector<std::string> short_vars = {"sv1_ntkv", "jf_ntrkv"};
      for(std::string &var: short_vars) {
	Wrap2(muvec, [=](const xAOD::Muon& mu) {
	    short m_mu_nonprompt_short = -99;
	    SG::AuxElement::Accessor<short> AccessorNonPrompt("PromptLepton_"+ var);
	    if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_short = AccessorNonPrompt(mu);
	    return (short) m_mu_nonprompt_short; }, *systematicTree, ("muon_PromptLepton_" + var).c_str());
      }

      bool m_writeAllNonPromptInputVars = true;

      if(m_writeAllNonPromptInputVars) {
	std::vector<std::string> float_vars = {"ip2", "ip2_cu", "ip3", "ip3_cu", "EtTopoCone20Rel"};
	for(std::string &var: float_vars) {
	  Wrap2(muvec, [=](const xAOD::Muon& mu) {
	      float m_mu_nonprompt_float = -99.;
	      SG::AuxElement::Accessor<float> AccessorNonPrompt("PromptLepton_" + var);
	      if(AccessorNonPrompt.isAvailable(mu)) m_mu_nonprompt_float = AccessorNonPrompt(mu);
	      return (float) m_mu_nonprompt_float; }, *systematicTree, ("muon_PromptLepton_" + var).c_str());
	}
      }
    }

    vec_muon_wrappers.push_back(VectorWrapperCollection(muvec));

    // Jets
    std::vector<VectorWrapper*> jetvec;
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.pt(); }, *systematicTree, "m_jet_pt");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.eta(); }, *systematicTree, "m_jet_eta");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.phi(); }, *systematicTree, "m_jet_phi");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.e(); }, *systematicTree, "m_jet_E");
    //Wrap2(jetvec, [](const xAOD::Jet& jet) { std::vector<float> tmp = jet.getAttribute<std::vector<float> >("JVF"); return (float) (tmp.size() ? tmp[0] : -2); }, *systematicTree, "m_jet_jvtxf");
    // not in sample xAOD
    //Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("Jvt"); }, *systematicTree, "m_jet_jvt_uncal");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.jetP4("JetEMScaleMomentum").eta(); }, *systematicTree, "m_jet_etaEM");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { float this_jvt = -999.; if(jet.isAvailable<float>("AnalysisTop_JVT")) this_jvt = jet.auxdataConst<float>("AnalysisTop_JVT"); return this_jvt;}, *systematicTree, "m_jet_jvt");
    //Jet cleaning flag
    Wrap2(jetvec, [=](const xAOD::Jet& jet) { int keepJet = m_jetCleaningToolLooseBad->keep(jet); return (int)keepJet;}, *systematicTree, "m_jet_isLooseBad");
    //Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); return (float) (btagging ? btagging->MV1_discriminant() : 0.); }, *systematicTree, "m_jet_flavor_weight_MV1");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c10");
    //Wrap2(jetvec, [](const xAOD::Jet& jet) { return (jet.isAvailable<short>("ttHJetOVRStatus") ? jet.auxdataConst<short>("ttHJetOVRStatus") : 0); }, *systematicTree, "m_jet_OVRStatus");
    Wrap2(jetvec, [&](const xAOD::Jet& jet) { auto tmp = jet.getAttribute<std::vector<int>   >(xAOD::JetAttribute::NumTrkPt500);   return (int)   (tmp.size() ? tmp[m_pv->index()] : 0);  }, *systematicTree, "m_jet_numTrk");

    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.auxdataConst<char>("ttHpassOVR"); },    *systematicTree, "m_jet_passOR");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.auxdataConst<char>("ttHpassTauOVR"); }, *systematicTree, "m_jet_passTauOR");

    //////// NOMINAL ONLY
    if(!m_doSystematics) {
      Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c00", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c00");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c20", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c20");
      // is it the 1 GeV counting we want?
      Wrap2(jetvec, [&](const xAOD::Jet& jet) { auto tmp = jet.getAttribute<std::vector<float> >(xAOD::JetAttribute::SumPtTrkPt500); return (float) (tmp.size() ? tmp[m_pv->index()] : 0.); }, *systematicTree, "m_jet_sumPtTrk");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("EMFrac"); }, *systematicTree, "m_jet_emfrac");
      // No label tagging in sample MC
      Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("ConeTruthLabelID"); }, *systematicTree, "m_jet_flavor_truth_label");
      Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("PartonTruthLabelID"); }, *systematicTree, "m_jet_flavor_truth_label_ghost");

    }

    vec_jet_wrappers.push_back(VectorWrapperCollection(jetvec));

    //Taus
    std::vector<VectorWrapper*> tauvec;
    std::string tauprefix = "m_tau_";
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.pt(); }, *systematicTree, std::string(tauprefix+"pt").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.eta(); }, *systematicTree, std::string(tauprefix+"eta").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.phi(); }, *systematicTree, std::string(tauprefix+"phi").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.e(); }, *systematicTree, std::string(tauprefix+"E").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.charge(); }, *systematicTree, std::string(tauprefix+"charge").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.nTracks(); }, *systematicTree, std::string(tauprefix+"numTrack").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (float) tau.nWideTracks(); }, *systematicTree, std::string(tauprefix+"numWideTrack").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.discriminant(xAOD::TauJetParameters::TauID::BDTJetScore); }, *systematicTree, std::string(tauprefix+"BDTJetScore").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigLoose); }, *systematicTree, std::string(tauprefix+"JetBDTSigLoose").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium); }, *systematicTree, std::string(tauprefix+"JetBDTSigMedium").c_str());
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return (int) tau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigTight); }, *systematicTree, std::string(tauprefix+"JetBDTSigTight").c_str());

    Wrap2(tauvec, [](const xAOD::TauJet& tau) {return tau.auxdataConst<char>("ttHpassTauOVR"); }, *systematicTree, std::string(tauprefix+"passOR").c_str());

    Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	return tau.auxdata<int>("passEleOLR");
      }, *systematicTree, std::string(tauprefix+"passEleOLR").c_str());

    Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	return tau.auxdata<int>("IsHadronic");
      }, *systematicTree, std::string(tauprefix+"isHadronicTau").c_str());

    //////// NOMINAL ONLY
    if(!m_doSystematics) {
      //substructure


      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	  int decayMode = 0;
	  tau.panTauDetail(xAOD::TauJetParameters::PanTauDetails::pantau_CellBasedInput_DecayMode, decayMode);
	  return decayMode;
	}, *systematicTree, std::string(tauprefix+"PanTauDecayMode").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	  return tau.ptPanTauCellBased();
	}, *systematicTree, std::string(tauprefix+"ptPanTau").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	  return tau.etaPanTauCellBased();
	}, *systematicTree, std::string(tauprefix+"etaPanTau").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	  return tau.phiPanTauCellBased();
	}, *systematicTree, std::string(tauprefix+"phiPanTau").c_str());
      Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	  auto p4 = tau.p4(xAOD::TauJetParameters::PanTauCellBased);
	  return p4.E();
	}, *systematicTree, std::string(tauprefix+"EPanTau").c_str());


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

    m_variables->BootstrapTree(systematicTree, this, m_doSFSystematics);
  }

  // Shall we do scale factors?
  // apparently not a question anymore
  m_sfRetriever = std::unique_ptr<top::ScaleFactorRetriever> ( new top::ScaleFactorRetriever( config ) );


  //tools for OR
  // only el/mu for now

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
  if (m_config->useTaus() && m_config->useElectrons())
    top::check(m_ORtoolBox[1].tauEleORT.setProperty("ElectronID",
						    "DFCommonElectronsLHLoose"),
  	       "Failed to set loose LH for electron def for ORTool");

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

void ttHMultileptonLooseEventSaver::recordSelectionDecision(const top::Event& event) {
  int index(0);
  for (const auto& branchName : m_extraBranches) {
    m_selectionDecisions[index] = event.m_info->auxdecor<int>(branchName);
    ++index;
  }
}

void ttHMultileptonLooseEventSaver::saveEvent(const top::Event& event){
  if (event.m_ttreeIndex >= m_treeManagers.size()) {
    // this is some forced loose tree nonsense : just ignore it, it's non-diagetic
    return;
  }

  // only save selected events
  if(!event.m_saveEvent) {
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

  if (top::isSimulation(event)){
    m_mcChannelNumber = event.m_info->mcChannelNumber();

    m_mcWeight        = event.m_info->mcEventWeight();
    if(m_sfRetriever){
      m_pileup_weight = m_sfRetriever->pileupSF(event);
      m_bTagSF_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"FixedCutBEff_70",false);
      m_bTagSF77_weight = m_sfRetriever->btagSF(event,top::topSFSyst::nominal,"FixedCutBEff_77",false);
      m_JVT_weight = m_sfRetriever->jvtSF(event,top::topSFSyst::nominal);

      //do sys weights only in "nominal" tree
      if( m_doSFSystematics ){

	m_pileup_weight_UP = m_sfRetriever->pileupSF( event, +1 ); // up variation
	m_pileup_weight_DOWN = m_sfRetriever->pileupSF( event, -1 ); // down variation
	//normalise
	m_pileup_weight_UP    = relativeSF(m_pileup_weight_UP,   m_pileup_weight);
	m_pileup_weight_DOWN  = relativeSF(m_pileup_weight_DOWN, m_pileup_weight);

	//btag
	m_sfRetriever->btagSF_eigen_vars(event,
					 top::topSFSyst::BTAG_SF_EIGEN_B,
					 m_weight_bTagSF_70_eigen_B_up,
					 m_weight_bTagSF_70_eigen_B_down, "FixedCutBEff_70");
	m_sfRetriever->btagSF_eigen_vars(event,
					 top::topSFSyst::BTAG_SF_EIGEN_C,
					 m_weight_bTagSF_70_eigen_C_up,
					 m_weight_bTagSF_70_eigen_C_down, "FixedCutBEff_70");
	m_sfRetriever->btagSF_eigen_vars(event,
					 top::topSFSyst::BTAG_SF_EIGEN_LIGHT,
					 m_weight_bTagSF_70_eigen_Light_up,
					 m_weight_bTagSF_70_eigen_Light_down, "FixedCutBEff_70");

	for (auto name : m_config->btagging_namedSysts("FixedCutBEff_70")) {
	  m_weight_bTagSF_70_eigen_Others_up[name] = m_sfRetriever->btagSF( event, top::topSFSyst::BTAG_SF_NAMED_UP, "FixedCutBEff_70", false, name );
	  m_weight_bTagSF_70_eigen_Others_down[name] = m_sfRetriever->btagSF( event, top::topSFSyst::BTAG_SF_NAMED_DOWN, "FixedCutBEff_70", false, name );
	  //std::cout << "m_weight_bTagSF_70_eigen_Others_up[name] " << m_weight_bTagSF_70_eigen_Others_up[name] << std::endl;
	}



	//normalise
	for( unsigned int i=0; i<m_config->btagging_num_B_eigenvars("FixedCutBEff_70"); ++i) {
	  m_weight_bTagSF_70_eigen_B_up.at(i)   /= m_bTagSF_weight;
	  m_weight_bTagSF_70_eigen_B_down.at(i) /= m_bTagSF_weight;
	}
	for( unsigned int i=0; i<m_config->btagging_num_C_eigenvars("FixedCutBEff_70"); ++i) {
	  m_weight_bTagSF_70_eigen_C_up.at(i)   /= m_bTagSF_weight;
	  m_weight_bTagSF_70_eigen_C_down.at(i) /= m_bTagSF_weight;
	}
	for( unsigned int i=0; i<m_config->btagging_num_Light_eigenvars("FixedCutBEff_70"); ++i) {
	  m_weight_bTagSF_70_eigen_Light_up.at(i)   /= m_bTagSF_weight;
	  m_weight_bTagSF_70_eigen_Light_down.at(i) /= m_bTagSF_weight;
	}
	for (auto name : m_config->btagging_namedSysts("FixedCutBEff_70")) {
	  m_weight_bTagSF_70_eigen_Others_up[name]   /= m_bTagSF_weight;
	  m_weight_bTagSF_70_eigen_Others_down[name] /= m_bTagSF_weight;
	}

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
  if (m_runNumber >= 290000) {
    m_runYear = 2016;
  } else if (m_runNumber > 0) {
    m_runYear = 2015;
  } else {
    m_runYear = 0;
  }

  // waiting for fix in TopCorrections
  m_mu      = m_purwtool->getCorrectedMu( *event.m_info, false);

  if(top::isSimulation(event)){
    m_mu      = m_mu_unc;
    m_pu_hash = m_purwtool->getPRWHash( *event.m_info );
  }

  //if (event.m_info->eventFlags(EventInfo::EventFlagSubDet::Background) &(1<<17)) std::cout << "Background flag is HaloMuon Segment" << std::endl;

  // Truth Matching
  if ( top::isSimulation(event) ) {
    top::check( m_truthMatchAlgo->executeTruthMatching(event), "Failed to execute executeTruthMatching(). Aborting");
  }

  //ttbar HF classification
  //std::cout << "m_mcChannelNumber: " << m_mcChannelNumber << std::endl;
  if ( top::isSimulation(event) && m_mcChannelNumber==410000){
    m_HF_Classification=m_classifyttbarHF->ClassifyEvent(event);
    //std::cout << "HF classification is: " << m_HF_Classification  << std::endl;
  }

  //sherpa rw
  if( top::isSimulation(event) and ( ( m_mcChannelNumber >= 363102 and m_mcChannelNumber <= 363122 ) or
				     ( m_mcChannelNumber >= 363331 and m_mcChannelNumber <= 363354 ) or
				     ( m_mcChannelNumber >= 363361 and m_mcChannelNumber <= 363483 )
				     )
      ) {
    uint nTruthJets      = m_sherpaRW->getSherpa22VJets_NJet("AntiKt4TruthJets");
    double sherpa_weight = m_sherpaRW->getSherpa22VJets_NJetCorrection(nTruthJets);

    event.m_info->auxdecor<int>   ("TTHML_NTruthJet")    = nTruthJets;
    event.m_info->auxdecor<double>("TTHML_SherpaNJetRW") = sherpa_weight;
  }

  //Event selection variable for each event selection region (pass/fail)
  recordSelectionDecision(event);

  //met
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

  //MC particle
  if (event.m_truth != nullptr) {
    m_higgsMode = truthSelector.GetHiggsDecayMode(event.m_truth);
    m_higgs     = truthSelector.GetHiggs(event.m_truth);
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

      const std::vector<ttH::TruthPart> selected_truths = truthSelector.SelectTruth(event.m_truth);

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
    m_PDFinfo_x1.resize(truthEventSize);
    m_PDFinfo_x2.resize(truthEventSize);
    m_PDFinfo_id1.resize(truthEventSize);
    m_PDFinfo_id2.resize(truthEventSize);
    m_PDFinfo_scalePDF.resize(truthEventSize);
    m_PDFinfo_pdf1.resize(truthEventSize);
    m_PDFinfo_pdf2.resize(truthEventSize);
    for (const auto* const tePtr : *event.m_truthEvent) {
      std::string PDFinfoVarName="X1";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_x1[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="X2";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_x2[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="PDGID1";
      if (event.m_truthEvent->isAvailable<int>(PDFinfoVarName))
	m_PDFinfo_id1[i] = (*tePtr).auxdataConst< int >( PDFinfoVarName );

      PDFinfoVarName="PDGID2";
      if (event.m_truthEvent->isAvailable<int>(PDFinfoVarName))
	m_PDFinfo_id2[i] = (*tePtr).auxdataConst< int >( PDFinfoVarName );

      PDFinfoVarName="SCALE";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_scalePDF[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="PDF1";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_pdf1[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );

      PDFinfoVarName="PDF2";
      if (event.m_truthEvent->isAvailable<float>(PDFinfoVarName))
	m_PDFinfo_pdf2[i] = (*tePtr).auxdataConst< float >( PDFinfoVarName );
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

  if(!m_doSystematics){
    vec_vtx_wrappers[event.m_ttreeIndex].push_all(*m_vertices);
  }


  m_variables->Clear();
  Decorate(event);
  auto goodEl = SelectElectrons(event);
  auto goodMu = SelectMuons(event);
  auto goodJet = SelectJets(event);
  auto goodTau = SelectTaus(event);

  //OverlapRemoval(goodEl, goodMu, goodJet, goodTau, event.m_ttreeIndex == 0);

  top::check( m_overlapRemovalTool[1]->removeOverlaps( goodEl.get(), goodMu.get(), goodJet.get(), goodTau.get() ) , "Failed to do nominal OR" );
  top::check( m_overlapRemovalTool[2]->removeOverlaps( goodEl.get(), goodMu.get(), goodJet.get(), goodTau.get() ) , "Failed to do nominal-but-tau OR" );
  top::check( m_overlapRemovalTool[0]->removeOverlaps( &event.m_electrons, &event.m_muons, &event.m_jets ) , "Failed to remove el/mu overlaps" );

  OverlapRemoval_ContOnly(goodEl, goodMu, goodJet, goodTau, event.m_ttreeIndex == 0);

  CopyLeptons(goodEl, goodMu);

  // dont do the rest if we skim here anyway
  if ( m_doSystematics && m_variables->total_leptons < 2 ) return;

  CopyJets(goodJet);
  CopyTaus(goodTau);
  CopyHT(goodEl, goodMu, goodJet, goodTau);
  CheckIsBlinded();
  doEventSFs();


  //blame David and the other vector people for this...
  for(auto allel : event.m_electrons) {
    (*m_decor_ttHpassOVR)(*allel) = 0;
    //allel->auxdecor<char>("ttHpassOVR") = 0;
    for(auto goodel : *goodEl ) {
      if( goodel->p4() == allel->p4() ) {
	(*m_decor_ttHpassOVR)(*allel) = (*m_decor_ttHpassOVR)(*goodel);
	//allel->auxdecor<char>("ttHpassOVR")    = goodel->auxdecor<char>("ttHpassOVR");
      }
    }
  }

  for(auto allmu : event.m_muons) {
    //allmu->auxdecor<char>("ttHpassOVR") = 0;
    (*m_decor_ttHpassOVR)(*allmu) = 0;
    for(auto goodmu : *goodMu ) {
      if( goodmu->p4() == allmu->p4() ) {
	(*m_decor_ttHpassOVR)(*allmu) = (*m_decor_ttHpassOVR)(*goodmu);
	//allmu->auxdecor<char>("ttHpassOVR")    = goodmu->auxdecor<char>("ttHpassOVR");
      }
    }
  }

  for(auto alltau : event.m_tauJets) {
    //alltau->auxdecor<char>("ttHpassTauOVR") = 0;
    (*m_decor_ttHpassTauOVR)(*alltau) = 0;
    for(auto goodtau : *goodTau ) {
      if( goodtau->p4() == alltau->p4() )
	(*m_decor_ttHpassTauOVR)(*alltau) = (*m_decor_ttHpassTauOVR)(*goodtau);
      //alltau->auxdecor<char>("ttHpassTauOVR") = goodtau->auxdecor<char>("ttHpassTauOVR");
    }
  }


  //save ALL jets
  xAOD::JetContainer* calibratedJets(nullptr);
  top::check(evtStore()->retrieve(calibratedJets, m_config->sgKeyJetsTDS(sysHash,false)), "Failed to retrieve calibrated jets");

  if(m_doSystematics) {
    //only selected jets
    for(auto alljet : event.m_jets) {
      //alljet->auxdecor<char>("ttHpassOVR") = 0;
      //alljet->auxdecor<char>("ttHpassTauOVR") = 0;
      (*m_decor_ttHpassOVR)(*alljet) = 0;
      (*m_decor_ttHpassTauOVR)(*alljet) = 0;
      for(auto goodjet : *goodJet ) {
	if( goodjet->p4() == alljet->p4() ) {
	  (*m_decor_ttHpassOVR)   (*alljet) = (*m_decor_ttHpassOVR)   (*goodjet);
	  (*m_decor_ttHpassTauOVR)(*alljet) = (*m_decor_ttHpassTauOVR)(*goodjet);
	  //alljet->auxdecor<char>("ttHpassOVR") = goodjet->auxdecor<char>("ttHpassOVR");
	  //alljet->auxdecor<char>("ttHpassTauOVR") = goodjet->auxdecor<char>("ttHpassTauOVR");
	}
      }
    }

    vec_jet_wrappers[event.m_ttreeIndex].push_all(event.m_jets);
    MakeJetIndices(goodJet, event.m_jets);
  }
  else {
    //all jets
    for(auto alljet : *calibratedJets) {
      //alljet->auxdecor<char>("ttHpassOVR") = 0;
      //alljet->auxdecor<char>("ttHpassTauOVR") = 0;
      (*m_decor_ttHpassOVR)(*alljet) = 0;
      (*m_decor_ttHpassTauOVR)(*alljet) = 0;
      for(auto goodjet : *goodJet ) {
	if( goodjet->p4() == alljet->p4() ) {
	  (*m_decor_ttHpassOVR)   (*alljet) = (*m_decor_ttHpassOVR)   (*goodjet);
	  (*m_decor_ttHpassTauOVR)(*alljet) = (*m_decor_ttHpassTauOVR)(*goodjet);
	  //alljet->auxdecor<char>("ttHpassOVR") = goodjet->auxdecor<char>("ttHpassOVR");
	  //alljet->auxdecor<char>("ttHpassTauOVR") = goodjet->auxdecor<char>("ttHpassTauOVR");
	}
      }
    }

    vec_jet_wrappers[event.m_ttreeIndex].push_all(*calibratedJets);
    MakeJetIndices(goodJet, *calibratedJets);
  }

  // xAOD::ElectronContainer* calibratedElectrons(nullptr);
  // top::check(evtStore()->retrieve(calibratedElectrons, m_config->sgKeyElectronsTDS(sysHash)), "Failed to retrieve calibrated electrons");
  // std::function<bool(const xAOD::Electron&)>elecSelector = [](const xAOD::Electron& el){ return el.auxdataConst<int>("passLHLoose") && el.pt()>5e3 ; };
  // vec_electron_wrappers[event.m_ttreeIndex].push_selected(*calibratedElectrons, elecSelector);

  vec_electron_wrappers[event.m_ttreeIndex].push_all(event.m_electrons);
  vec_scalar_wrappers[event.m_ttreeIndex].push_all(event);
  vec_muon_wrappers[event.m_ttreeIndex].push_all(event.m_muons);
  vec_tau_wrappers[event.m_ttreeIndex].push_all(event.m_tauJets);


  //std::cout << m_eventNumber << " " << event.m_ttreeIndex << " " << m_treeManagers[event.m_ttreeIndex] << std::endl;

  m_treeManagers[event.m_ttreeIndex]->fill();

}

void ttHMultileptonLooseEventSaver::saveParticleLevelEvent(const top::ParticleLevelEvent& plEvent) {
  //jets
  unsigned int i = 0;
  m_trjet_pt.resize(plEvent.m_jets->size());
  m_trjet_eta.resize(plEvent.m_jets->size());
  m_trjet_phi.resize(plEvent.m_jets->size());
  m_trjet_e.resize(plEvent.m_jets->size());
  for (const auto & jetPtr : * plEvent.m_jets) {
    m_trjet_pt[i] = jetPtr->pt();
    m_trjet_eta[i] = jetPtr->eta();
    m_trjet_phi[i] = jetPtr->phi();
    m_trjet_e[i] = jetPtr->e();
    ++i;
  }
}

//nothing happens in this method, but it needs to be defined because otherwise we have a crash
void ttHMultileptonLooseEventSaver::saveTruthEvent() {
}

void ttHMultileptonLooseEventSaver::finalize() {
  //Count histogram
  auto Count = static_cast<TH1D*>(m_outputFile->Get("loose/Count"));

  // copy number of events before event cleaning for data
  // and before PRIVTX for mc
  double totalEventsProcessed = static_cast<TH1D*>(m_outputFile->Get("loose/cutflow"))->GetBinContent(1);
  Count->SetBinContent(3,totalEventsProcessed);

  //overwrite Count histogram with values from CutBookkeepers
  //only for skimmed MC
  if(m_isMC) {
    TTreeReader sumWeightsReader("sumWeights", m_outputFile);
    TTreeReaderValue<unsigned long long> totalEvents(sumWeightsReader, "totalEvents");
    TTreeReaderValue<Float_t> totalEventsWeighted(sumWeightsReader, "totalEventsWeighted");
    double totalEventsUnskimmed         = 0;
    double totalEventsWeightedUnskimmed = 0;
    while(sumWeightsReader.Next()) {
      totalEventsUnskimmed         += *totalEvents;
      totalEventsWeightedUnskimmed += *totalEventsWeighted;
    }
    double totalEventsSkimmed = Count->GetBinContent(3);
    if(totalEventsUnskimmed != totalEventsSkimmed) {
      Count->SetBinContent(1,totalEventsUnskimmed);
      Count->SetBinContent(2,totalEventsWeightedUnskimmed);
    }
  }
  m_outputFile->WriteTObject(m_eleCutflow);
  m_outputFile->WriteTObject(m_muCutflow);
  m_outputFile->WriteTObject(m_jetCutflow);
  m_outputFile->WriteTObject(m_tauCutflow);
  m_outputFile->Write();
}

void ttHMultileptonLooseEventSaver::doEventSFs() {
  // logic: for 3l Tight = Loose * Tight * Tight
  // otherwise = Product of corresponding SF
  m_variables->lepSFIDLoose = 1;
  m_variables->lepSFIDTight = 1;
  m_variables->lepSFIsoLoose = 1;
  m_variables->lepSFIsoTight = 1;
  m_variables->lepSFReco = 1;
  m_variables->lepSFTTVA = 1;
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    m_variables->lepSFTrigLoose[ivar] = 1;
    m_variables->lepSFTrigTight[ivar] = 1;
    m_variables->lepSFObjLoose[ivar] = 1;
    m_variables->lepSFObjTight[ivar] = 1;
  }
  for (const auto& systvar : m_tau_sf_names ) {
    auto ivar = systvar.first;
    m_variables->tauSFTight[ivar] = 1;
    m_variables->tauSFLoose[ivar] = 1;
  }

  // The following: index 0 = 1-eff(mc), index 1 = 1-eff(data)
  //  double oneMinusTrigEffLoose[2]{1,1}, oneMinusTrigEffTight[2]{1,1};
  double oneMinusTrigEffLoose[MAXSYST][2], oneMinusTrigEffTight[MAXSYST][2];
  for (int idx1 = 0; idx1 < MAXSYST; ++idx1) {
    for (int idx2 = 0; idx2 < 2; ++idx2) {
      oneMinusTrigEffLoose[idx1][idx2] = oneMinusTrigEffTight[idx1][idx2] = 1.;
    }
  }
  switch (m_variables->total_leptons) {
  case 1:
  case 2:
  case 4:
    for (int ilep = 0; ilep < m_variables->total_leptons; ++ilep) {
      m_variables->lepSFIDLoose *= m_leptons[ilep].SFIDLoose[0];
      m_variables->lepSFIDTight *= m_leptons[ilep].SFIDTight[0];
      m_variables->lepSFIsoLoose *= m_leptons[ilep].SFIsoLoose[0];
      m_variables->lepSFIsoTight *= m_leptons[ilep].SFIsoTight[0];
      m_variables->lepSFReco *= m_leptons[ilep].SFReco[0];
      m_variables->lepSFTTVA *= m_leptons[ilep].SFTTVA[0];
      for (const auto& systvar : m_lep_sf_names) {
	auto ivar = systvar.first;
	m_variables->lepSFObjLoose[ivar] *= m_leptons[ilep].SFObjLoose[ivar];
	m_variables->lepSFObjTight[ivar] *= m_leptons[ilep].SFObjTight[ivar];
	oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[ilep].EffTrigLoose[ivar]);
	oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[ilep].EffTrigLoose[ivar]*m_leptons[ilep].SFTrigLoose[ivar]);
	oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[ilep].EffTrigTight[ivar]);
	oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[ilep].EffTrigTight[ivar]*m_leptons[ilep].SFTrigTight[ivar]);
      }
    }
    // if (m_variables->total_leptons == 1 && abs(m_leptons[0].ID) == 13) {
    //   std::cout << m_leptons[0].EffTrigTight << " " << m_leptons[0].SFTrigTight << " " << oneMinusTrigEffTight[0] << " " << oneMinusTrigEffTight[1] << std::endl;
    // }
    break;
  case 3:
    m_variables->lepSFIDLoose *= m_leptons[0].SFIDLoose[0];
    m_variables->lepSFIDTight *= m_leptons[0].SFIDLoose[0];
    m_variables->lepSFIsoLoose *= m_leptons[0].SFIsoLoose[0];
    m_variables->lepSFIsoTight *= m_leptons[0].SFIsoLoose[0];
    m_variables->lepSFReco *= m_leptons[0].SFReco[0];
    m_variables->lepSFTTVA *= m_leptons[0].SFTTVA[0];
    for (const auto& systvar : m_lep_sf_names) {
      auto ivar = systvar.first;
      m_variables->lepSFObjLoose[ivar] *= m_leptons[0].SFObjLoose[ivar];
      m_variables->lepSFObjTight[ivar] *= m_leptons[0].SFObjLoose[ivar];
      oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[0].EffTrigLoose[ivar]);
      oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[0].EffTrigLoose[ivar]*m_leptons[0].SFTrigLoose[ivar]);
      oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[0].EffTrigLoose[ivar]);
      oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[0].EffTrigLoose[ivar]*m_leptons[0].SFTrigLoose[ivar]);
    }
    for (int ilep = 1; ilep < m_variables->total_leptons; ++ilep) {
      m_variables->lepSFIDLoose *= m_leptons[ilep].SFIDLoose[0];
      m_variables->lepSFIDTight *= m_leptons[ilep].SFIDTight[0];
      m_variables->lepSFIsoLoose *= m_leptons[ilep].SFIsoLoose[0];
      m_variables->lepSFIsoTight *= m_leptons[ilep].SFIsoTight[0];
      m_variables->lepSFReco *= m_leptons[ilep].SFReco[0];
      m_variables->lepSFTTVA *= m_leptons[ilep].SFTTVA[0];
      for (const auto& systvar : m_lep_sf_names) {
	auto ivar = systvar.first;
	m_variables->lepSFObjLoose[ivar] *= m_leptons[ilep].SFObjLoose[ivar];
	m_variables->lepSFObjTight[ivar] *= m_leptons[ilep].SFObjTight[ivar];
	oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[ilep].EffTrigLoose[ivar]);
	oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[ilep].EffTrigLoose[ivar]*m_leptons[ilep].SFTrigLoose[ivar]);
	oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[ilep].EffTrigTight[ivar]);
	oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[ilep].EffTrigTight[ivar]*m_leptons[ilep].SFTrigTight[ivar]);
      }
    }
    break;
  default:
    return;
  }
  for (const auto& systvar : m_lep_sf_names) {
    const auto ivar = systvar.first;
    if (ivar == top::topSFSyst::nominal) continue;
    m_variables->lepSFObjLoose[ivar] /= m_variables->lepSFObjLoose[0];
    m_variables->lepSFObjTight[ivar] /= m_variables->lepSFObjTight[0];
  }

  m_variables->lepSFTrigLoose[0] = oneMinusTrigEffLoose[0][0] != 1 ? (1-oneMinusTrigEffLoose[0][1])/(1-oneMinusTrigEffLoose[0][0]) : 1;
  m_variables->lepSFTrigTight[0] = oneMinusTrigEffTight[0][0] != 1 ? (1-oneMinusTrigEffTight[0][1])/(1-oneMinusTrigEffTight[0][0]) : 1;
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    if (ivar == top::topSFSyst::nominal) continue;
    m_variables->lepSFTrigLoose[ivar] = oneMinusTrigEffLoose[ivar][0] != 1 ? (1-oneMinusTrigEffLoose[ivar][1])/(1-oneMinusTrigEffLoose[ivar][0])/m_variables->lepSFTrigLoose[0] : 1;
    m_variables->lepSFTrigTight[ivar] = oneMinusTrigEffTight[ivar][0] != 1 ? (1-oneMinusTrigEffTight[ivar][1])/(1-oneMinusTrigEffTight[ivar][0])/m_variables->lepSFTrigTight[0] : 1;
  }

  //taus
  for ( int itau = 0; itau<m_variables->nTaus_OR_Pt25; ++itau) {
    for ( auto syst : m_tau_sf_names ) {
      auto ivar = syst.first;
      m_variables->tauSFTight[ivar] *= m_taus[itau].SFTight[ivar];
      m_variables->tauSFLoose[ivar] *= m_taus[itau].SFLoose[ivar];
    }
  }

  //normalise variations
  for ( auto syst : m_tau_sf_names ) {
      auto ivar = syst.first;
      if( ivar == top::topSFSyst::nominal ) continue;
      m_variables->tauSFTight[ivar] /= m_variables->tauSFTight[top::topSFSyst::nominal];
      m_variables->tauSFLoose[ivar] /= m_variables->tauSFLoose[top::topSFSyst::nominal];

      if( m_variables->tauSFTight[ivar] != m_variables->tauSFTight[ivar] ) m_variables->tauSFTight[ivar] = 1;
      if( m_variables->tauSFLoose[ivar] != m_variables->tauSFLoose[ivar] ) m_variables->tauSFLoose[ivar] = 1;
    }

  //naaaaan
  for ( auto syst : m_lep_sf_names ) {
    auto ivar = syst.first;
    if( m_variables->lepSFTrigLoose[ivar] != m_variables->lepSFTrigLoose[ivar] ) {
      //std::cout<<"nanananana"<<std::endl;
      m_variables->lepSFTrigLoose[ivar] = 1;
    }
    if( m_variables->lepSFTrigTight[ivar] != m_variables->lepSFTrigTight[ivar] ) {
      //std::cout<<"nanananana"<<std::endl;
      m_variables->lepSFTrigTight[ivar] = 1;
    }

  }
}

double ttHMultileptonLooseEventSaver::relativeSF(double variation, double nominal) {
  if (nominal == 0) return 0;
  else return variation/nominal;
}

// remove "FT_EFF_", spaces, and "-" in named systematics
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
