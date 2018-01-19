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
//    m_trigDecTool("Trig::TrigDecisionTool"),
//    m_purwtool("CP::PileupReweightingTool"),
    // m_jetCleaningToolLooseBad("JetCleaningToolLooseBad"),
//    m_electronToolsFactory(0),
    //m_muonToolsHandles("MuonToolsHandles"),
//    m_muonToolsFactory(0),
    //m_trigGlobEffCorr(0),
//    m_mcWeight(1.),
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
    m_truthMET_sumet(-1.0)
//    m_sherpaRW("PMGSherpa22VJetsWeightTool"),
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

    m_ttHEvent = new ttHML::Variables();
  for (auto treeName : *config->systAllTTreeNames()) {
    std::cout << "INITIALIZING SYST TREES" << std::endl;
    m_treeManagers.push_back(std::shared_ptr<top::TreeManager>( new top::TreeManager(treeName.second, file) ) );
    std::cout << m_treeManagers.size() << " " << treeName.second << std::endl;
    }



    ///-- Loop over the systematic TTrees and add the custom variables --///
    for (auto systematicTree : m_treeManagers) {
      m_doSFSystematics = systematicTree->name() ==  m_config->systematicName(m_config->nominalHashValue());
       if(!m_isMC) m_doSFSystematics = false;
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
/*    WrapS(scalarvec, [&](const top::Event& event)
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
*/
    systematicTree->makeOutputVariable(m_runYear, "RunYear");
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
    const xAOD::ElectronContainer* Electrons(nullptr);
    const xAOD::MuonContainer* Muons(nullptr);
    top::check( evtStore()->retrieve(Electrons,"Selected_Electrons"),"Failed to retrieve Electrons");
    top::check( evtStore()->retrieve(Muons,"Selected_muons"),"Failed to retrieve Muons");
    CopyLeptons(*Electrons,*Muons);
    m_ttHEvent->AssignOutput(m_ttHEvent,tthevt);   
    ///-- Let the base class do all the hard work --///
    top::EventSaverFlatNtuple::saveEvent(event);
  }
  

