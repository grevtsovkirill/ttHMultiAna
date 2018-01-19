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

    m_ttHEvent = new ttHML::Variables();
    
    ///-- Loop over the systematic TTrees and add the custom variables --///
    for (auto systematicTree : treeManagers()) {

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
  

