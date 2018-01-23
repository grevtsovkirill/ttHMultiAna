/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEventSelectionTools/TreeManager.h"
#include "ttHMultilepton/Variables.h"

#include "TopConfiguration/TopConfig.h"

#include "TopConfiguration/ConfigurationSettings.h"
#include "TopConfiguration/SelectionConfigurationData.h"
#include "PathResolver/PathResolver.h"

#include <TRandom3.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <cmath>
#include <algorithm>

#include <TRandom3.h>


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
//    m_bTagSF_default("Continuous"),
//    m_bTagSF_weight(1.),
//    m_JVT_weight(1.),
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
    m_sherpaRW("PMGSherpa22VJetsWeightTool")
//    m_higgs(nullptr),
//    m_top(nullptr),
//    m_antitop(nullptr),
//    dummy_nom("dummy"),
//    dummy_elup("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1up"),
//    dummy_eldo("EL_EFF_Trigger_TOTAL_1NPCOR_PLUS_UNCOR__1down"),
//    dummy_muup("MUON_EFF_TrigStatUncertainty__1up"),
//    dummy_mudo("MUON_EFF_TrigStatUncertainty__1down"),
//    dummy_eleffup("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1up"),
//    dummy_eleffdo("EL_EFF_TriggerEff_TOTAL_1NPCOR_PLUS_UNCOR__1down")
  
  {}
//  ttHMultileptonLooseEventSaver::~ttHMultileptonLooseEventSaver(){}
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
//Tools
  if (m_isMC){
    std::string tdpfile = PathResolverFindCalibFile("TopDataPreparation/XSection-MC15-13TeV.data"); 
    top::check( m_sherpaRW.retrieve(), "Failed to retrieve PMGSherpa22VJetsWeightTool" );
    top::check( m_sherpaRW->setProperty("TruthJetContainer", "AntiKt4TruthJets"),
		"Failed to set TruthJetContainer of PMGSherpa22VJetsWeightTool" );
    top::check( m_sampleXsection.readFromFile(tdpfile.c_str()),
		"Failed to open AMI X-section file");
  }

  top::check( m_purwtool.retrieve() , "Failed to retrieve PileupReweightingTool" );
  top::check( m_trigDecTool.retrieve() , "Failed to retrieve TrigDecisionTool" );

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
//    systematicTree->makeOutputVariable(m_pileup_weight, "pileupEventWeight_090");
//    systematicTree->makeOutputVariable(m_bTagSF_weight,   ("bTagSF_weight_"+m_bTagSF_default).c_str());
//    systematicTree->makeOutputVariable(m_bTagSF60_weight, "MV2c10_60_EventWeight");
//    systematicTree->makeOutputVariable(m_bTagSF70_weight, "MV2c10_70_EventWeight");
//    systematicTree->makeOutputVariable(m_bTagSF77_weight, "MV2c10_77_EventWeight");
//    systematicTree->makeOutputVariable(m_bTagSF85_weight, "MV2c10_85_EventWeight");
//    systematicTree->makeOutputVariable(m_bTagSFContinuous_weight, "MV2c10_Continuous_EventWeight");
//    systematicTree->makeOutputVariable(m_JVT_weight,    "JVT_EventWeight");

/*    if ( m_doSFSystematics ) {

      //pileup
      systematicTree->makeOutputVariable(m_pileup_weight_UP,   "pileupEventWeight_UP");
      systematicTree->makeOutputVariable(m_pileup_weight_DOWN, "pileupEventWeight_DOWN");

      //JVT
      systematicTree->makeOutputVariable(m_JVT_weight_UP,   "JVT_EventWeight_UP");
      systematicTree->makeOutputVariable(m_JVT_weight_DOWN, "JVT_EventWeight_DOWN");
    }*/

/*    if(!m_doSystematics) {
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
      //systematicTree->makeOutputVariable(m_trjet_pt,  "m_truth_jet_pt");
      //systematicTree->makeOutputVariable(m_trjet_eta, "m_truth_jet_eta");
      //systematicTree->makeOutputVariable(m_trjet_phi, "m_truth_jet_phi");
      //systematicTree->makeOutputVariable(m_trjet_e,   "m_truth_jet_e");
      //systematicTree->makeOutputVariable(m_trjet_Wcount,   "m_truth_jet_Wcount");
      //systematicTree->makeOutputVariable(m_trjet_Zcount,   "m_truth_jet_Zcount");
      //systematicTree->makeOutputVariable(m_trjet_Hcount,   "m_truth_jet_Hcount");
      //systematicTree->makeOutputVariable(m_trjet_Tcount,   "m_truth_jet_Tcount");

      //truthEvent information
      systematicTree->makeOutputVariable(m_PDFinfo_X1,        "m_mcevt_pdf_X1");
      systematicTree->makeOutputVariable(m_PDFinfo_X2,        "m_mcevt_pdf_X2");
      systematicTree->makeOutputVariable(m_PDFinfo_PDGID1,    "m_mcevt_pdf_PDGID1");
      systematicTree->makeOutputVariable(m_PDFinfo_PDGID2,    "m_mcevt_pdf_PDGID2");
      systematicTree->makeOutputVariable(m_PDFinfo_Q,         "m_mcevt_pdf_Q");
      systematicTree->makeOutputVariable(m_PDFinfo_XF1,       "m_mcevt_pdf_XF1");
      systematicTree->makeOutputVariable(m_PDFinfo_XF2,       "m_mcevt_pdf_XF2");
    }*/



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

/*    WrapS(scalarvec, [&](const top::Event&){ return m_higgs ? m_higgs->pt()             : 0.0; }, *systematicTree, "higgs_pt");
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
*/
    systematicTree->makeOutputVariable(m_runYear, "RunYear");
// ttbar HF, DLF, MLF classification
//    systematicTree->makeOutputVariable(m_HF_Classification, "HF_Classification");
//    systematicTree->makeOutputVariable(m_HF_ClassificationTop, "HF_ClassificationTop");
//    systematicTree->makeOutputVariable(m_DLF_Classification, "DLF_Classification");
    //systematicTree->makeOutputVariable(m_MLF_Classification, "MLF_Classification");

//    systematicTree->makeOutputVariable(m_higgsMode,      "higgsDecayMode");

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
    systematicTree->makeOutputVariable(m_MEphoton_OLtty_keepEvent, "m_MEphoton_OLtty_keepEvent");
    systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat1, "m_MEphoton_OLtty_cat1");
    systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat2, "m_MEphoton_OLtty_cat2");
    systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat3, "m_MEphoton_OLtty_cat3");
    systematicTree->makeOutputVariable(m_MEphoton_OLtty_cat4, "m_MEphoton_OLtty_cat4");
    systematicTree->makeOutputVariable(m_MEphoton_pt, "m_MEphoton_pt");
    systematicTree->makeOutputVariable(m_MEphoton_eta, "m_MEphoton_eta");
    systematicTree->makeOutputVariable(m_MEphoton_phi, "m_MEphoton_phi");
    systematicTree->makeOutputVariable(m_MEphoton_mother_pdgId, "m_MEphoton_mother_pdgId");
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

    for (size_t idx = 0; idx < LEPTON_ARR_SIZE; ++idx) {
      m_leptons[idx].BootstrapTree(systematicTree, idx);
    }


    m_ttHEvent->BootstrapTree(systematicTree,false);
    }
  }
  
  ///-- saveEvent - run for every systematic and every event --///
  void ttHMultileptonLooseEventSaver::saveEvent(const top::Event& event) 
  {
    std::shared_ptr<ttHML::Variables> tthevt;
    if(event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
      tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
    }
/*  if (event.m_ttreeIndex >= m_treeManagers.size()) {
    // this is some forced loose tree nonsense : just ignore it, it's non-diagetic
    return;
  }

  // only save selected events
  if(!event.m_saveEvent) {
    return;
  }*/

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
 // m_mu      = m_purwtool->getCorrectedMu( *event.m_info, false);
  m_mu      = m_purwtool->getCorrectedAverageInteractionsPerCrossing( *event.m_info, false);

  if(top::isSimulation(event)){
    m_mu      = m_mu_unc;
    m_pu_hash = m_purwtool->getPRWHash( *event.m_info );
  }

  //if (event.m_info->eventFlags(EventInfo::EventFlagSubDet::Background) &(1<<17)) std::cout << "Background flag is HaloMuon Segment" << std::endl;
/*
  // Truth Matrix element photon
  m_hasMEphoton = false;
  m_hasMEphoton_DRgt02_nonhad = false;
  m_MEphoton_OLtty_keepEvent = false;
  m_MEphoton_OLtty_cat1 = false;
  m_MEphoton_OLtty_cat2 = false;
  m_MEphoton_OLtty_cat3 = false;
  m_MEphoton_OLtty_cat4 = false;
  m_MEphoton_pt = -1.;
  m_MEphoton_eta = 0.;
  m_MEphoton_phi = 0.;
  m_MEphoton_mother_pdgId = 0;
  m_MEphoton_mother_pt = -1.;
  m_MEphoton_mother_eta = 0.;
  m_MEphoton_mother_phi = 0.;
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
           std::cout << motherPdgId << " " << particle->barcode() << " " << particle->p4().DeltaR(mother->p4()) << " " << particle->pt() << std::endl;
          double dr = particle->p4().DeltaR(mother->p4()); // always look at DR
          if (dr > 0.2 && particle->pt() > 15e3 && (abs(motherPdgId) < 11 || abs(motherPdgId) > 18))
            m_hasMEphoton_DRgt02_nonhad = true; // in selection use with "(!m_hasMEphoton_DRgt02_nonhad)!=(mc_channel_number==410082)"
          if (dr > 0.2 && particle->pt() > 15e3 && (abs(motherPdgId) < 11 || abs(motherPdgId) > 18) && m_mcChannelNumber == 410082) {
            m_MEphoton_OLtty_cat1 = true;
            m_MEphoton_OLtty_keepEvent = true;  // this is tty - top left cell of the tty table, > 15 GeV
          } else if (dr > 0.2 && particle->pt() > 15e3 && (abs(motherPdgId) >= 11 && abs(motherPdgId) <= 18) && m_mcChannelNumber != 410082) {
            m_MEphoton_OLtty_cat2 = true;
            m_MEphoton_OLtty_keepEvent = true;  // this is ttbar - top right cell of the ttbar table
          } else if (dr < 0.2  && particle->pt() > 15e3 && m_mcChannelNumber != 410082) {
            m_MEphoton_OLtty_cat3 = true;
            m_MEphoton_OLtty_keepEvent = true;  // this is ttbar, dr < 0.2 row from the ttbar table
          } else if (particle->pt() < 15e3 && m_mcChannelNumber != 410082) {
            m_MEphoton_OLtty_cat4 = true;
            m_MEphoton_OLtty_keepEvent = true;  // this is ttbar, ME photon pT < 15000 regardless the DR
          }
          if(particle->pt() > m_MEphoton_pt) {
            m_MEphoton_pt = particle->pt();
            m_MEphoton_eta = particle->eta();
            m_MEphoton_phi = particle->phi();
            m_MEphoton_mother_pdgId = motherPdgId;
            m_MEphoton_mother_pt = motherPt;
            m_MEphoton_mother_eta = mother->eta();
            m_MEphoton_mother_phi = mother->phi();
          }
        }
      }
     }
    }
  }
  if (!m_hasMEphoton)
    m_MEphoton_OLtty_keepEvent = true;

  // Truth Matching
  if ( top::isSimulation(event) ) {
    top::check( m_truthMatchAlgo->executeTruthMatching(event), "Failed to execute executeTruthMatching(). Aborting");
  }

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
  }

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
  // }*/

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
//////////////////////////////////////////////////////




    const xAOD::ElectronContainer* Electrons(nullptr);
    const xAOD::MuonContainer* Muons(nullptr);
    const xAOD::JetContainer* Jets(nullptr);
    const xAOD::TauJetContainer* Taus(nullptr);
    top::check( evtStore()->retrieve(Electrons,"Selected_Electrons"),"Failed to retrieve Electrons");
    top::check( evtStore()->retrieve(Muons,"Selected_muons"),"Failed to retrieve Muons");
    top::check( evtStore()->retrieve(Jets,"Selected_jets"),"Failed to retrieve JEts");
    top::check( evtStore()->retrieve(Taus,"Selected_taus"),"Failed to retrieve Taus");
    CopyLeptons(*Electrons,*Muons);
    CopyJets(*Jets);
    CopyTaus(*Taus);
    CheckIsBlinded();
    m_ttHEvent->AssignOutput(m_ttHEvent,tthevt);   
    ///-- Let the base class do all the hard work --///
    top::EventSaverFlatNtuple::saveEvent(event);
  }
  

