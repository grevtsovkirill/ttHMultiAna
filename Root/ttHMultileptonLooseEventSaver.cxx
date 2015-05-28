#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "TopEventSelectionTools/TreeManager.h"

#include "TopCorrections/ScaleFactorRetriever.h"
#include "TFile.h"

ttHMultileptonLooseEventSaver::ttHMultileptonLooseEventSaver() : 
  m_eventNumber(0),
  m_runNumber(0),
  m_mcChannelNumber(0),
  m_mu(0),
  m_met_met(0.),
  m_met_phi(0.),
  HLT_e26_tight_iloose(0),
  HLT_e26_lhtight_iloose(0),
  HLT_e60_medium(0),
  HLT_e60_lhmedium(0),
  HLT_e24_tight_iloose(0),
  HLT_e24_lhtight_iloose(0),
  HLT_e24_tight_iloose_L1EM20VH(0),
  HLT_e140_loose(0),
  HLT_e24_lhtight_iloose_L1EM20VH(0),
  HLT_e140_lhloose(0),
  HLT_mu26_imedium(0),
  HLT_mu50(0),
  HLT_mu24_imedium(0),
  HLT_2e12_loose_L12EM10VH(0),
  HLT_2e12_lhloose_L12EM10VH(0),
  HLT_2mu14(0),
  HLT_2mu10(0),
  HLT_e17_loose_mu14(0),
  HLT_e17_lhloose_mu14(0),
  HLT_e7_medium_mu24(0),
  HLT_e7_lhmedium_mu24(0),
  HLT_e26_tight_iloose_PS(-99.),
  HLT_e26_lhtight_iloose_PS(-99.),
  HLT_e60_medium_PS(-99.),
  HLT_e60_lhmedium_PS(-99.),
  HLT_e24_tight_iloose_PS(-99.),
  HLT_e24_lhtight_iloose_PS(-99.),
  HLT_e24_tight_iloose_L1EM20VH_PS(-99.),
  HLT_e140_loose_PS(-99.),
  HLT_e24_lhtight_iloose_L1EM20VH_PS(-99.),
  HLT_e140_lhloose_PS(-99.),
  HLT_mu26_imedium_PS(-99.),
  HLT_mu50_PS(-99.),
  HLT_mu24_imedium_PS(-99.),
  HLT_2e12_loose_L12EM10VH_PS(-99.),
  HLT_2e12_lhloose_L12EM10VH_PS(-99.),
  HLT_2mu14_PS(-99.),
  HLT_2mu10_PS(-99.),
  HLT_e17_loose_mu14_PS(-99.),
  HLT_e17_lhloose_mu14_PS(-99.),
  HLT_e7_medium_mu24_PS(-99.),
  HLT_e7_lhmedium_mu24_PS(-99.),
  configTool("xAODConfigTool"),
  trigDecTool("TrigDecTool"),
  muonSelection("MuonSelection")
{
}

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

template<typename VEC, typename FCN,  typename TM> void Wrap2(VEC& vec, FCN lambda, TM& systematicTree, const char* branch) {
  // cast away the crud from around the lambda
  //vec.push_back(new VectorWrapper(static_cast<typename function_traits<FCN>::pointer>(lambda), systematicTree, branch));
  vec.push_back(new VectorWrapper(static_cast<typename function_traits<FCN>::function>(lambda), systematicTree, branch)); 
}

void ttHMultileptonLooseEventSaver::initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches) {

  //EventSaverFlatNtuple::initialise(config, file, treeNames, extraBranches);
  m_outputFile = file;
  m_extraBranches = extraBranches;
  m_selectionDecisions.resize(m_extraBranches.size());
  
  //make a tree for each systematic
  for (auto treeName : *config->systAllTTreeNames())
    m_treeManagers.push_back(std::shared_ptr<top::TreeManager>( new top::TreeManager(treeName.second, file) ) );

  for (auto systematicTree : m_treeManagers){
    systematicTree->makeOutputVariable(m_mcWeight, "mcWeightOrg");
    systematicTree->makeOutputVariable(m_pileup_weight, "pileupEventWeight_090");

    //event info
    systematicTree->makeOutputVariable(m_eventNumber, "eventNumber");
    systematicTree->makeOutputVariable(m_runNumber, "runNumber");
    systematicTree->makeOutputVariable(m_mcChannelNumber, "mcChannelNumber");
    systematicTree->makeOutputVariable(m_mu, "mu");

    //met
    systematicTree->makeOutputVariable(m_met_met, "met_met");
    systematicTree->makeOutputVariable(m_met_phi, "met_phi");
    
    //truth information
    systematicTree->makeOutputVariable(m_mc_pt, "m_truth_pt");
    systematicTree->makeOutputVariable(m_mc_eta, "m_truth_eta");
    systematicTree->makeOutputVariable(m_mc_phi, "m_truth_phi");
    systematicTree->makeOutputVariable(m_mc_e, "m_truth_e");
    systematicTree->makeOutputVariable(m_mc_pdgId, "m_truth_pdgId");
    systematicTree->makeOutputVariable(m_mc_parentPdgId, "m_truth_parentPdgId");
    systematicTree->makeOutputVariable(m_mc_status, "m_truth_status");
    systematicTree->makeOutputVariable(m_mc_barcode, "m_truth_barcode");
    
    //TRIGGER PART
    // Trigger decision tool. 
    ToolHandle<TrigConf::ITrigConfigTool> configHandle(&configTool);
    top::check( configHandle->initialize(),"xAODConfigTool fails to initialize");   
    // The decision tool
    top::check( trigDecTool.setProperty("ConfigTool",configHandle),"TrigDecTool fails to set configHandle");
    //top::check( trigDecTool.setProperty("OutputLevel", MSG::VERBOSE),"TrigDecTool fails to set OutputLevel");
    top::check( trigDecTool.setProperty("TrigDecisionKey","xTrigDecision"),"TrigDecTool fails to set TrigDecisionKey");
    top::check(trigDecTool.initialize(),"TrigDecTool fails to initialize");    
    //Items and their PS
    systematicTree->makeOutputVariable(HLT_e26_tight_iloose, "HLT_e26_tight_iloose");
    systematicTree->makeOutputVariable(HLT_e26_lhtight_iloose, "HLT_e26_lhtight_iloose");
    systematicTree->makeOutputVariable(HLT_e60_medium, "HLT_e60_medium" );
    systematicTree->makeOutputVariable(HLT_e60_lhmedium, "HLT_e60_lhmedium" );
    systematicTree->makeOutputVariable(HLT_e24_tight_iloose, "HLT_e24_tight_iloose" );
    systematicTree->makeOutputVariable(HLT_e24_lhtight_iloose, "HLT_e24_lhtight_iloose" );    
    systematicTree->makeOutputVariable(HLT_e24_tight_iloose_L1EM20VH, "HLT_e24_tight_iloose_L1EM20VH" );
    systematicTree->makeOutputVariable(HLT_e140_loose, "HLT_e140_loose" );
    systematicTree->makeOutputVariable(HLT_e24_lhtight_iloose_L1EM20VH, "HLT_e24_lhtight_iloose_L1EM20VH" );
    systematicTree->makeOutputVariable(HLT_e140_lhloose, "HLT_e140_lhloose" );
    systematicTree->makeOutputVariable(HLT_mu26_imedium, "HLT_mu26_imedium" );
    systematicTree->makeOutputVariable(HLT_mu50, "HLT_mu50" );
    systematicTree->makeOutputVariable(HLT_mu24_imedium, "HLT_mu24_imedium" );
    systematicTree->makeOutputVariable(HLT_2e12_loose_L12EM10VH, "HLT_2e12_loose_L12EM10VH" );
    systematicTree->makeOutputVariable(HLT_2e12_lhloose_L12EM10VH, "HLT_2e12_lhloose_L12EM10VH" );
    systematicTree->makeOutputVariable(HLT_2mu14, "HLT_2mu14" );
    systematicTree->makeOutputVariable(HLT_2mu10, "HLT_2mu10" );
    systematicTree->makeOutputVariable(HLT_e17_loose_mu14, "HLT_e17_loose_mu14" );
    systematicTree->makeOutputVariable(HLT_e17_lhloose_mu14, "HLT_e17_lhloose_mu14" );
    systematicTree->makeOutputVariable(HLT_e7_medium_mu24, "HLT_e7_medium_mu24" );
    systematicTree->makeOutputVariable(HLT_e7_lhmedium_mu24, "HLT_e7_lhmedium_mu24" );
    systematicTree->makeOutputVariable(HLT_e26_tight_iloose_PS, "HLT_e26_tight_iloose_PS");
    systematicTree->makeOutputVariable(HLT_e26_lhtight_iloose_PS, "HLT_e26_lhtight_iloose_PS");
    systematicTree->makeOutputVariable(HLT_e60_medium_PS, "HLT_e60_medium_PS");
    systematicTree->makeOutputVariable(HLT_e60_lhmedium_PS, "HLT_e60_lhmedium_PS");
    systematicTree->makeOutputVariable(HLT_e24_tight_iloose_PS, "HLT_e24_tight_iloose_PS");
    systematicTree->makeOutputVariable(HLT_e24_lhtight_iloose_PS, "HLT_e24_lhtight_iloose_PS");    
    systematicTree->makeOutputVariable(HLT_e24_tight_iloose_L1EM20VH_PS, "HLT_e24_tight_iloose_L1EM20VH_PS");
    systematicTree->makeOutputVariable(HLT_e140_loose_PS, "HLT_e140_loose_PS");
    systematicTree->makeOutputVariable(HLT_e24_lhtight_iloose_L1EM20VH_PS, "HLT_e24_lhtight_iloose_L1EM20VH_PS");
    systematicTree->makeOutputVariable(HLT_e140_lhloose_PS, "HLT_e140_lhloose_PS");
    systematicTree->makeOutputVariable(HLT_mu26_imedium_PS, "HLT_mu26_imedium_PS");
    systematicTree->makeOutputVariable(HLT_mu50_PS, "HLT_mu50_PS");
    systematicTree->makeOutputVariable(HLT_mu24_imedium_PS, "HLT_mu24_imedium_PS");
    systematicTree->makeOutputVariable(HLT_2e12_loose_L12EM10VH_PS, "HLT_2e12_loose_L12EM10VH_PS");
    systematicTree->makeOutputVariable(HLT_2e12_lhloose_L12EM10VH_PS, "HLT_2e12_lhloose_L12EM10VH_PS");
    systematicTree->makeOutputVariable(HLT_2mu14_PS, "HLT_2mu14_PS");
    systematicTree->makeOutputVariable(HLT_2mu10_PS, "HLT_2mu10_PS");
    systematicTree->makeOutputVariable(HLT_e17_loose_mu14_PS, "HLT_e17_loose_mu14_PS");
    systematicTree->makeOutputVariable(HLT_e17_lhloose_mu14_PS, "HLT_e17_lhloose_mu14_PS");
    systematicTree->makeOutputVariable(HLT_e7_medium_mu24_PS, "HLT_e7_medium_mu24_PS");
    systematicTree->makeOutputVariable(HLT_e7_lhmedium_mu24_PS, "HLT_e7_lhmedium_mu24_PS");
    //END trigger


    std::vector<VectorWrapper*> elevec;    
    //Wrap2(elevec, [](const xAOD::Electron& ele) { return (float) ele.pt(); }, *systematicTree, "electron_pt");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.pt(); }, *systematicTree, "electron_pt"); 
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.eta(); }, *systematicTree, "electron_eta");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.phi(); }, *systematicTree, "electron_phi");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.e(); }, *systematicTree, "electron_E");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) ele.author(); }, *systematicTree, "electron_author");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) (11*ele.charge()); }, *systematicTree, "electron_ID");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float d0 = ele.trackParticle()->d0(); float err_d0 = sqrt(ele.trackParticle()->definingParametersCovMatrix()(0,0)); return (float) (d0/err_d0); }, *systematicTree, "electron_sigd0PV");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float z0 = ele.trackParticle()->z0(); float sin_Th = sin(2*atan(exp(-ele.eta()))); return (float) (z0*sin_Th); }, *systematicTree, "electron_z0SinTheta");

    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::etcone20); return iso; }, *systematicTree, "electron_Etcone20");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::etcone30); return iso; }, *systematicTree, "electron_Etcone30");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::etcone40); return iso; }, *systematicTree, "electron_Etcone40");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone20); return iso; }, *systematicTree, "electron_ptcone20");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone30); return iso; }, *systematicTree, "electron_ptcone30");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptcone40); return iso; }, *systematicTree, "electron_ptcone40");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone20); return iso; }, *systematicTree, "electron_topoetcone20");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone30); return iso; }, *systematicTree, "electron_topoetcone30");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::topoetcone40); return iso; }, *systematicTree, "electron_topoetcone40");
    //miniiso
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone20); return iso; }, *systematicTree, "electron_ptvarcone20");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone30); return iso; }, *systematicTree, "electron_ptvarcone30");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float iso = 1e6; ele.isolationValue(iso, xAOD::Iso::ptvarcone40); return iso; }, *systematicTree, "electron_ptvarcone40");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (short) ele.auxdataConst<short>("passLHLoose"); }, *systematicTree, "electron_isLooseLH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (short) ele.auxdataConst<short>("passLHMedium"); }, *systematicTree, "electron_isMediumLH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (short) ele.auxdataConst<short>("passLHTight"); }, *systematicTree, "electron_isTightLH");
    
    vec_electron_wrappers.push_back(VectorWrapperCollection(elevec));
    
    // Muons
    top::check( muonSelection.setProperty("OutputLevel", MSG::VERBOSE),"muonSelection fails to set OutputLevel");
    top::check( muonSelection.setProperty( "MaxEta", 2.5 ), "muonSelection tool could not set max eta");
    top::check( muonSelection.initialize(),"muonSelection tool fails to initialize");   
   
    std::vector<VectorWrapper*> muvec;
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.pt(); }, *systematicTree, "muon_pt");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.eta(); }, *systematicTree, "muon_eta");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.phi(); }, *systematicTree, "muon_phi");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.e(); }, *systematicTree, "muon_E");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { bool isqual = false; if(muonSelection.getQuality(mu) <= xAOD::Muon::Loose)  isqual=true; return (bool) isqual;},*systematicTree, "muon_isLoose");    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { bool isqual = false; if(muonSelection.getQuality(mu) <= xAOD::Muon::Medium) isqual=true; return (bool) isqual;},*systematicTree, "muon_isMedium");    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { bool isqual = false; if(muonSelection.getQuality(mu) <= xAOD::Muon::Tight)  isqual=true; return (bool) isqual;},*systematicTree, "muon_isTight");    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return mu.auxdata<float>("InnerDetectorPt"); }, *systematicTree, "muon_PtID");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return mu.auxdata<float>("MuonSpectrometerPt"); }, *systematicTree, "muon_PtME");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.allAuthors(); }, *systematicTree, "muon_allAuthor");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.author(); }, *systematicTree, "muon_author");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) (13*mu.charge()); }, *systematicTree, "muon_ID");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float d0 = mu.primaryTrackParticle()->d0(); float err_d0 = sqrt(mu.primaryTrackParticle()->definingParametersCovMatrix()(0,0)); return (float) (d0/err_d0); }, *systematicTree, "muon_sigd0PV");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float z0 = mu.primaryTrackParticle()->z0(); float sin_Th = sin(2*atan(exp(-mu.eta()))); return (float) (z0*sin_Th); }, *systematicTree, "muon_z0SinTheta");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float momBalSignif = mu.floatParameter(xAOD::Muon::momentumBalanceSignificance); return (float) (momBalSignif); }, *systematicTree, "muon_momBalSignif");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatCurvSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatNeighSignif = mu.floatParameter(xAOD::Muon::scatteringNeighbourSignificance); return (float) (scatNeighSignif); }, *systematicTree, "muon_scatNeighSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float qOverPSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { uint8_t numberOfPrecisionLayers = mu.uint8SummaryValue(xAOD::SummaryType::numberOfPrecisionLayers); return (uint8_t) (numberOfPrecisionLayers); }, *systematicTree, "muon_numPrecLayers");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::etcone20); return iso; }, *systematicTree, "muon_Etcone20");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::etcone30); return iso; }, *systematicTree, "muon_Etcone30");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::etcone40); return iso; }, *systematicTree, "muon_Etcone40");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptcone20); return iso; }, *systematicTree, "muon_ptcone20");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptcone30); return iso; }, *systematicTree, "muon_ptcone30");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptcone40); return iso; }, *systematicTree, "muon_ptcone40");
    // topoiso
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone20); return iso; }, *systematicTree, "muon_topoetcone20");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone30); return iso; }, *systematicTree, "muon_topoetcone30");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone40); return iso; }, *systematicTree, "muon_topoetcone40");
    // miniiso
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone20); return iso; }, *systematicTree, "muon_ptvarcone20");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone30); return iso; }, *systematicTree, "muon_ptvarcone30");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone40); return iso; }, *systematicTree, "muon_ptvarcone40");

    vec_muon_wrappers.push_back(VectorWrapperCollection(muvec));

    // Jets
    std::vector<VectorWrapper*> jetvec;
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.pt(); }, *systematicTree, "jet_pt");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.eta(); }, *systematicTree, "jet_eta");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.phi(); }, *systematicTree, "jet_phi");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.e(); }, *systematicTree, "jet_E");
    // is it the 1 GeV counting we want?
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto tmp = jet.getAttribute<std::vector<float> >("SumPtTrkPt1000"); return (float) (tmp.size() ? tmp[0] : 0.); }, *systematicTree, "jet_sumPtTrk");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("EMFrac"); }, *systematicTree, "jet_emfrac");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { std::vector<float> tmp = jet.getAttribute<std::vector<float> >("JVF"); return (float) (tmp.size() ? tmp[0] : -2); }, *systematicTree, "jet_jvtxf");
    // not in sample xAOD
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("Jvt"); }, *systematicTree, "jet_jvt");
    // No label tagging in sample MC
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("ConeTruthLabelID"); }, *systematicTree, "jet_flavor_truth_label");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("PartonTruthLabelID"); }, *systematicTree, "jet_flavor_truth_label_ghost");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); return (float) (btagging ? btagging->MV1_discriminant() : 0.); }, *systematicTree, "jet_flavor_weight_MV1");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c00", rv) ? rv : 0.); }, *systematicTree, "jet_flavor_weight_MV2c00");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0.); }, *systematicTree, "jet_flavor_weight_MV2c10");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c20", rv) ? rv : 0.); }, *systematicTree, "jet_flavor_weight_MV2c20");
    vec_jet_wrappers.push_back(VectorWrapperCollection(jetvec));
  }
}

void ttHMultileptonLooseEventSaver::saveEvent(const top::Event& event){
  
  m_mcWeight = 0.;
  if (top::isSimulation(event))
    m_mcWeight = event.m_info->mcEventWeight();

  m_pileup_weight = 0.;
  if (top::ScaleFactorRetriever::hasPileupSF(event))
    m_pileup_weight = top::ScaleFactorRetriever::pileupSF(event);

  //met
  m_met_met = event.m_met->met();
  m_met_phi = event.m_met->phi();
  
  //MC particle
  /**
  if (event.m_truth != nullptr) {
    unsigned int i = 0;
    unsigned int truthSize = event.m_truth->size();
    m_mc_pt.resize(truthSize);
    m_mc_eta.resize(truthSize);
    m_mc_phi.resize(truthSize);
    m_mc_e.resize(truthSize);
    m_mc_pdgId.resize(truthSize);
    m_mc_parentPdgId.resize(truthSize);
    m_mc_status.resize(truthSize);
    m_mc_barcode.resize(truthSize);
    for (const xAOD::TruthParticle*  mcPtr : *event.m_truth) {
      if(mcPtr->pt()<5000.) continue;
      m_mc_pt[i] = mcPtr->pt();
      m_mc_eta[i] = mcPtr->eta();
      m_mc_phi[i] = mcPtr->phi();
      m_mc_e[i] = mcPtr->e();
      m_mc_pdgId[i] = mcPtr->pdgId();
      m_mc_status[i] = mcPtr->status();
      m_mc_barcode[i] = mcPtr->barcode(); 
      if(mcPtr->parent()) m_mc_parentPdgId[i] = mcPtr->parent()->pdgId();
      else m_mc_parentPdgId[i] = 99999.;
      ++i;
      }
      }
  */

  //Trigger INFO
  HLT_e26_tight_iloose = 0;
  HLT_e26_lhtight_iloose = 0;
  HLT_e60_medium = 0;
  HLT_e60_lhmedium = 0;
  HLT_e24_tight_iloose = 0;
  HLT_e24_lhtight_iloose = 0;
  HLT_e24_tight_iloose_L1EM20VH = 0;
  HLT_e140_loose = 0;
  HLT_e24_lhtight_iloose_L1EM20VH = 0;
  HLT_e140_lhloose = 0;
  HLT_mu26_imedium = 0;
  HLT_mu50 = 0;
  HLT_mu24_imedium = 0;
  HLT_2e12_loose_L12EM10VH = 0;
  HLT_2e12_lhloose_L12EM10VH = 0;
  HLT_2mu14 = 0;
  HLT_2mu10 = 0;
  HLT_e17_loose_mu14 = 0;
  HLT_e17_lhloose_mu14 = 0;
  HLT_e7_medium_mu24 = 0;
  HLT_e7_lhmedium_mu24 = 0;

  HLT_e26_tight_iloose_PS = -99;
  HLT_e26_lhtight_iloose_PS = -99;
  HLT_e60_medium_PS = -99;
  HLT_e60_lhmedium_PS = -99;
  HLT_e24_tight_iloose_PS = -99;
  HLT_e24_lhtight_iloose_PS = -99;
  HLT_e24_tight_iloose_L1EM20VH_PS = -99;
  HLT_e140_loose_PS = -99;
  HLT_e24_lhtight_iloose_L1EM20VH_PS = -99;
  HLT_e140_lhloose_PS = -99;
  HLT_mu26_imedium_PS = -99;
  HLT_mu50_PS = -99;
  HLT_mu24_imedium_PS = -99;
  HLT_2e12_loose_L12EM10VH_PS = -99;
  HLT_2e12_lhloose_L12EM10VH_PS = -99;
  HLT_2mu14_PS = -99;
  HLT_2mu10_PS = -99;
  HLT_e17_loose_mu14_PS = -99;
  HLT_e17_lhloose_mu14_PS = -99;
  HLT_e7_medium_mu24_PS = -99;
  HLT_e7_lhmedium_mu24_PS = -99;

  
  if( trigDecTool.isPassed( "HLT_e26_tight_iloose" ) ){
    HLT_e26_tight_iloose = 1;
    HLT_e26_tight_iloose_PS = trigDecTool.getPrescale( "HLT_e26_tight_iloose" );
  }
  if( trigDecTool.isPassed( "HLT_e26_lhtight_iloose" ) ){
    HLT_e26_lhtight_iloose = 1;
    HLT_e26_lhtight_iloose_PS = trigDecTool.getPrescale( "HLT_e26_lhtight_iloose" );
  }
  if( trigDecTool.isPassed( "HLT_e60_medium" ) ){
    HLT_e60_medium = 1;
    HLT_e60_medium_PS = trigDecTool.getPrescale( "HLT_e60_medium" );
  }
  if( trigDecTool.isPassed( "HLT_e60_lhmedium" ) ){
    HLT_e60_lhmedium = 1;
    HLT_e60_lhmedium_PS = trigDecTool.getPrescale( "HLT_e60_lhmedium" );
  }
  if( trigDecTool.isPassed( "HLT_e24_tight_iloose" ) ){
    HLT_e24_tight_iloose = 1;
    HLT_e24_tight_iloose_PS = trigDecTool.getPrescale( "HLT_e24_tight_iloose");
  }
  if( trigDecTool.isPassed( "HLT_e24_lhtight_iloose" ) ){
    HLT_e24_lhtight_iloose = 1;
    HLT_e24_lhtight_iloose_PS = trigDecTool.getPrescale( "HLT_e24_lhtight_iloose");
  }
  if( trigDecTool.isPassed( "HLT_e24_tight_iloose_L1EM20VH" ) ){
    HLT_e24_tight_iloose_L1EM20VH = 1;
    HLT_e24_tight_iloose_L1EM20VH_PS = trigDecTool.getPrescale( "HLT_e24_tight_iloose_L1EM20VH");
  }
  if( trigDecTool.isPassed( "HLT_e24_lhtight_iloose_L1EM20VH" ) ){
    HLT_e24_lhtight_iloose_L1EM20VH = 1;
    HLT_e24_lhtight_iloose_L1EM20VH_PS = trigDecTool.getPrescale( "HLT_e24_lhtight_iloose_L1EM20VH");
  }
  if( trigDecTool.isPassed( "HLT_e140_loose" ) ){
    HLT_e140_loose = 1;
    HLT_e140_loose_PS = trigDecTool.getPrescale( "HLT_e140_loose");
  }
  if( trigDecTool.isPassed( "HLT_e140_lhloose" ) ){
    HLT_e140_lhloose = 1;
    HLT_e140_lhloose_PS = trigDecTool.getPrescale( "HLT_e140_lhloose");
  }
  if( trigDecTool.isPassed( "HLT_mu26_imedium" ) ){ 
    HLT_mu26_imedium = 1;
    HLT_mu26_imedium_PS = trigDecTool.getPrescale( "HLT_mu26_imedium");
  }
  if( trigDecTool.isPassed( "HLT_mu24_imedium" ) ){ 
    HLT_mu24_imedium = 1;
    HLT_mu24_imedium_PS = trigDecTool.getPrescale( "HLT_mu24_imedium");
  }
  if( trigDecTool.isPassed( "HLT_mu50" ) ){
    HLT_mu50 = 1;
    HLT_mu50_PS = trigDecTool.getPrescale( "HLT_mu50"); 
  }
  if( trigDecTool.isPassed( "HLT_2e12_loose_L12EM10VH" ) ){
    HLT_2e12_loose_L12EM10VH = 1;
    HLT_2e12_loose_L12EM10VH_PS = trigDecTool.getPrescale( "HLT_2e12_loose_L12EM10VH");
  }
  if( trigDecTool.isPassed( "HLT_2e12_lhloose_L12EM10VH" ) ){
    HLT_2e12_lhloose_L12EM10VH = 1;
    HLT_2e12_lhloose_L12EM10VH_PS = trigDecTool.getPrescale( "HLT_2e12_lhloose_L12EM10VH");
  }
  if( trigDecTool.isPassed( "HLT_2mu14" ) ){
    HLT_2mu14 = 1;
    HLT_2mu14_PS = trigDecTool.getPrescale( "HLT_2mu14");
  }
  if( trigDecTool.isPassed( "HLT_2mu10" ) ){
    HLT_2mu10 = 1;
    HLT_2mu10_PS = trigDecTool.getPrescale( "HLT_2mu10");
  }
  if( trigDecTool.isPassed( "HLT_e17_loose_mu14" ) ){
    HLT_e17_loose_mu14 = 1;
    HLT_e17_loose_mu14_PS = trigDecTool.getPrescale( "HLT_e17_loose_mu14");    
  }
  if( trigDecTool.isPassed( "HLT_e17_lhloose_mu14" ) ){
    HLT_e17_lhloose_mu14 = 1;
    HLT_e17_lhloose_mu14_PS = trigDecTool.getPrescale( "HLT_e17_lhloose_mu14");    
  }
  if( trigDecTool.isPassed( "HLT_e7_medium_mu24" ) ){
    HLT_e7_medium_mu24 = 1;
    HLT_e7_medium_mu24_PS = trigDecTool.getPrescale( "HLT_e7_medium_mu24");
  }
  if( trigDecTool.isPassed( "HLT_e7_lhmedium_mu24" ) ){
    HLT_e7_lhmedium_mu24 = 1;
    HLT_e7_lhmedium_mu24_PS = trigDecTool.getPrescale( "HLT_e7_lhmedium_mu24");
  }

  /**
  auto cg = trigDecTool.getChainGroup("HLT_e26_lhtight_iloose");
  auto fc = cg->features();
  auto eleFeatureContainers = fc.containerFeature<TrigElectronContainer>();
  std::cout << "OK2" << std::endl;
  for(auto econt : eleFeatureContainers) {
    std::cout << "OK3" << std::endl;
    for (auto e : *econt.cptr()) {
      std::cout << "OK4" << std::endl;
      std::cout << "    -> ele pt = " << e->pt()/1000.0 << " [GeV]" << std::endl;
      std::cout << "OK5" << std::endl;
    }
  }
  std::cout << "OK6" << std::endl;
  */  
  //END trigger info




  // for (const auto* const elPtr : event.m_electrons) {
  //   std::cout << "Passes?" << elPtr->auxdataConst< char >("passPreORSelection") << std::endl;
  // }
  vec_electron_wrappers[event.m_ttreeIndex].push_all(event.m_electrons);
  vec_muon_wrappers[event.m_ttreeIndex].push_all(event.m_muons);
  vec_jet_wrappers[event.m_ttreeIndex].push_all(event.m_jets);
  m_treeManagers[event.m_ttreeIndex]->fill();


}

void ttHMultileptonLooseEventSaver::finalize() {
  m_outputFile->Write();
}
