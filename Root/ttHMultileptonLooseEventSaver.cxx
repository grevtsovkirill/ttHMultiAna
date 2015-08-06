#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"

#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "TopEventSelectionTools/TreeManager.h"

#include "TopParticleLevel/ParticleLevelEvent.h"

#include "TopCorrections/ScaleFactorRetriever.h"

#include "PathResolver/PathResolver.h"

#include "xAODTracking/TrackParticlexAODHelpers.h"

//ROOT
#include "TFile.h"
#include "TH1.h"

ttHMultileptonLooseEventSaver::ttHMultileptonLooseEventSaver() : 
  m_outputFile(0),
  m_sfRetriever(nullptr),
  configTool("xAODConfigTool"),
  trigDecTool("TrigDecTool"),
  muonSelection("MuonSelection"),
  iso_1( "iso_1" ),
  m_tauEffTool("TauEfficiencyCorrectionsTool"),
  m_tauSelectionEleOLR("TauSelectionEleOLR"),
  m_mcWeight(0.),
  m_pileup_weight(0.),
  m_leptonSF_weight(0.),
  m_eventNumber(0),
  m_runNumber(0),
  m_mcChannelNumber(0),
  m_mu(0),
  m_mu_unc(0),  
  m_mu_ac(0),
  m_pu_hash(0),
  m_pvNumber(0),
  m_puNumber(0),
  m_met_met(0.),
  m_met_phi(0.)
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

  //Cutflow histograms
  m_eleCutflow = new TH1I("eleCutflow", "Electron cutflow", 10, 0.5, 10.5);
  int idx = 1;
  for (const auto label : { "initial", "pt", "eta", "ident", "z0sinth", "d0sig", "iso", "e-#mu OR", "e-e OR"}) {
    m_eleCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_muCutflow = new TH1I("muCutflow", "Muon cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto label : { "initial", "eta/qual", "pt", "z0sinth", "d0sig", "iso", "#mu-jet OR"}) {
    m_muCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_jetCutflow = new TH1I("jetCutflow", "Jet cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto label : { "initial", "cleaning", "pt", "eta", "jvt", "jet-e OR", "jet-#tau OR"}) {
    m_jetCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  m_tauCutflow = new TH1I("tauCutflow", "Tau cutflow", 10, 0.5, 10.5);
  idx = 1;
  for (const auto label : { "initial", "charge", "ntracks", "eta", "jetbdt", "pt", "EleOLR", "#tau-e,#mu OR"}) {
    m_tauCutflow->GetXaxis()->SetBinLabel(idx++, label);
  }
  
  //make a tree for each systematic
  for (auto treeName : *config->systAllTTreeNames()) {
    std::cout << "INITIALIZING SYST TREES" << std::endl;
    m_treeManagers.push_back(std::shared_ptr<top::TreeManager>( new top::TreeManager(treeName.second, file) ) );
    std::cout << m_treeManagers.size() << " " << treeName.second << std::endl;
    }

  for (auto systematicTree : m_treeManagers){
    systematicTree->makeOutputVariable(m_mcWeight, "mcWeightOrg");
    systematicTree->makeOutputVariable(m_pileup_weight, "pileupEventWeight_090");
    systematicTree->makeOutputVariable(m_leptonSF_weight, "lepTrigSFEventWeight");

    //event info
    std::vector<ScalarWrapper*> scalarvec; 
    systematicTree->makeOutputVariable(m_eventNumber, "EventNumber");
    WrapS(scalarvec, [](const top::Event& event){ return event.m_info->runNumber(); }, *systematicTree, "RunNumber");
    WrapS(scalarvec, [](const top::Event& event){ return event.m_info->lumiBlock(); }, *systematicTree, "lbn");
    WrapS(scalarvec, [](const top::Event& event){ return event.m_info->bcid(); }, *systematicTree, "bcid");
    WrapS(scalarvec, [](const top::Event& event){ bool passClean=true; if( (event.m_info->errorState(EventInfo::Tile)==EventInfo::Error) || (event.m_info->errorState(EventInfo::LAr)==EventInfo::Error) ) passClean=false; return (bool) passClean; }, *systematicTree, "passEventCleaning");


    systematicTree->makeOutputVariable(m_mcChannelNumber, "mc_channel_number");
    systematicTree->makeOutputVariable(m_mu_unc, "averageIntPerXing_uncorr");
    systematicTree->makeOutputVariable(m_mu, "averageIntPerXing");
    systematicTree->makeOutputVariable(m_mu_ac, "actualIntPerXing");
    systematicTree->makeOutputVariable(m_pu_hash, "pileupHash");
    systematicTree->makeOutputVariable(m_pvNumber, "m_vxp_n");
    systematicTree->makeOutputVariable(m_puNumber, "m_vxpu_n");

    //met
    systematicTree->makeOutputVariable(m_met_met, "MET_RefFinal_et");
    systematicTree->makeOutputVariable(m_met_phi, "MET_RefFinal_phi");
    
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

    //truthEvent information
    systematicTree->makeOutputVariable(m_PDFinfo_x1,        "m_mcevt_pdf_x1");
    systematicTree->makeOutputVariable(m_PDFinfo_x2,        "m_mcevt_pdf_x2");
    systematicTree->makeOutputVariable(m_PDFinfo_id1,       "m_mcevt_pdf_id1");
    systematicTree->makeOutputVariable(m_PDFinfo_id2,       "m_mcevt_pdf_id2");
    systematicTree->makeOutputVariable(m_PDFinfo_scalePDF,  "m_mcevt_pdf_scale");
    systematicTree->makeOutputVariable(m_PDFinfo_pdf1,      "m_mcevt_pdf_pdf1");
    systematicTree->makeOutputVariable(m_PDFinfo_pdf2,      "m_mcevt_pdf_pdf2");

    //truth jets
    systematicTree->makeOutputVariable(m_trjet_pt,  "m_truth_jet_pt");
    systematicTree->makeOutputVariable(m_trjet_eta, "m_truth_jet_eta");
    systematicTree->makeOutputVariable(m_trjet_phi, "m_truth_jet_phi");
    systematicTree->makeOutputVariable(m_trjet_e,   "m_truth_jet_e");
    
    //PURW
    m_purwtool = new CP::PileupReweightingTool("prw_tthml");
    std::vector<std::string> pileup_config = config->PileupConfig();
    for ( std::string& s: pileup_config )
      s = PathResolverFindCalibFile( s );
    std::vector<std::string> pileup_lumi_calc = config->PileupLumiCalc();
    for ( std::string& s: pileup_lumi_calc )
      s = PathResolverFindCalibFile( s );
    // Let's have the option of having one config file per MC sample- set default channel
    // to < 0 if you are doing this.
    int default_channel = config->PileupDefaultChannel();
    if ( default_channel > 0 )
      top::check( m_purwtool->setProperty("DefaultChannel", default_channel), "Failed to set pileup reweighting config files" );    
    top::check( m_purwtool->setProperty("ConfigFiles", pileup_config), "Failed to set pileup reweighting config files" );
    top::check( m_purwtool->setProperty("LumiCalcFiles", pileup_lumi_calc), "Failed to set pileup reweighting lumicalc files");
    top::check( m_purwtool->setProperty("OutputLevel", MSG::VERBOSE),"m_purwtool fails to set OutputLevel");
    top::check( m_purwtool->initialize(), "Failed to initialize pileup reweighting tool" );
    
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
    std::vector<std::string> triggernames
    {   "HLT_e24_lhmedium_L1EM18VH",
	"HLT_e24_lhmedium_iloose_L1EM18VH",
	"HLT_e24_tight_iloose",
	"HLT_e24_lhtight_iloose", 
	"HLT_e24_tight_iloose_L1EM20VH",
	"HLT_e24_lhtight_iloose_L1EM20VH", 
	"HLT_e26_tight_iloose",
	"HLT_e26_lhtight_iloose",
	"HLT_e60_medium",
	"HLT_e60_lhmedium", 
	"HLT_e120_lhloose",
	"HLT_e140_loose",
	"HLT_e140_lhloose", 
	"HLT_mu20_iloose_L1MU15",
	"HLT_mu24_imedium",
	"HLT_mu26_imedium", 
	"HLT_mu40",
	"HLT_mu50",
	"HLT_2e12_loose_L12EM10VH",
	"HLT_2e12_lhloose_L12EM10VH",
	"HLT_e17_lhloose_2e9_lhloose",
	"HLT_2mu14",
	"HLT_2mu10",
	"HLT_e17_loose_mu14",
	"HLT_e17_lhloose_mu14", 
	"HLT_e7_medium_mu24",
	"HLT_e7_lhmedium_mu24"};
    
    for (auto trigger : triggernames) {
      WrapS(scalarvec, [=](const top::Event&){ return (unsigned int) trigDecTool.isPassed( trigger ) ; }, *systematicTree, trigger.c_str());
      WrapS(scalarvec, [=](const top::Event&){ return (float) trigDecTool.getPrescale( trigger ); }, *systematicTree, (trigger + "_PS").c_str());
    }
    //END trigger
    vec_scalar_wrappers.push_back(scalarvec);

    //leptons
    std::vector<VectorWrapper*> elevec;    
    std::vector<VectorWrapper*> muvec;

    //Isolation tool for leptons
//    top::check( iso_1.setProperty("MuonWP","Loose"),"IsolationTool fails to set MuonWP" );
//    top::check( iso_1.setProperty("ElectronWP","Loose"),"IsolationTool fails to set ElectronWP");
    top::check( iso_1.initialize(),"IsolationTool fails to initialize");
    auto WPs{"LooseTrackOnly", "Loose", "Tight", "Gradient", "GradientLoose"};
    for (auto wp : WPs) {
      top::check( iso_1.addMuonWP(wp), "Error adding muon isolation WP" );
      top::check( iso_1.addElectronWP(wp), "Error adding electron isolation WP" );
      std::string isoname("Iso_"); isoname += wp;
      std::string eleisoname("electron_isolation"); eleisoname += wp;
      std::string muisoname("muon_isolation"); muisoname += wp;
      Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>(isoname); }, *systematicTree, eleisoname.c_str());
      Wrap2(elevec, [=](const xAOD::Muon& mu) { return (char) mu.auxdataConst<short>(isoname); }, *systematicTree, muisoname.c_str());
    }
    
    //leptons
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.pt(); }, *systematicTree, "electron_pt"); 
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.eta(); }, *systematicTree, "electron_eta");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.caloCluster()->eta(); }, *systematicTree, "electron_ClEta");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.caloCluster()->etaBE(2); }, *systematicTree, "electron_EtaBE2");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.phi(); }, *systematicTree, "electron_phi");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.e(); }, *systematicTree, "electron_E");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) ele.author(); }, *systematicTree, "electron_author");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) (-11*ele.charge()); }, *systematicTree, "electron_ID");
    //d0  and sig d0 are wrt Beamline (see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/InDetTrackingPerformanceGuidelines#Variables) -- "PV" is left to ensure compatibility with Run1 code, but it is NOT corrected for PV position as it is not recommended
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float d0 = ele.trackParticle()->d0();  return (float) (d0); }, *systematicTree, "electron_d0");
    //Wrap2(elevec, [=](const xAOD::Electron& ele) { float d0 = ele.trackParticle()->d0(); float err_d0 = sqrt(ele.trackParticle()->definingParametersCovMatrix()(0,0)); return (float) (d0/err_d0); }, *systematicTree, "electron_sigd0PV_hand"); //INACCURATE: USE following one by Tracking CP

    //Wrap2(elevec, [=](const xAOD::Electron& ele) { double d0sig = xAOD::TrackingHelpers::d0significance( ele.trackParticle(), m_eventInfo->beamPosSigmaX(), m_eventInfo->beamPosSigmaY(), m_eventInfo->beamPosSigmaXY() ); return (float) (d0sig); }, *systematicTree, "electron_sigd0PV");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("d0significance"); }, *systematicTree, "electron_sigd0PV");

    //z0sinTh raw and corrected for PV (see https://twiki.cern.ch/twiki/bin/view/AtlasProtected/InDetTrackingDC14)
    Wrap2(elevec, [=](const xAOD::Electron& ele) { float z0 = ele.trackParticle()->z0(); float theta = ele.trackParticle()->theta(); float sin_Th = sin(theta); return (float) (z0*sin_Th); }, *systematicTree, "electron_z0SinTheta_uncorr");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (float) ele.auxdataConst<float>("z0sintheta"); }, *systematicTree, "electron_z0SinTheta");    
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

    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>("passLHLoose"); }, *systematicTree, "electron_isLooseLH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>("passLHMedium"); }, *systematicTree, "electron_isMediumLH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (char) ele.auxdataConst<short>("passLHTight"); }, *systematicTree, "electron_isTightLH");

    //truth origin HERE
    //coding of the enums, see here: https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/MCTruthClassifier/tags/MCTruthClassifier-00-00-26/MCTruthClassifier/MCTruthClassifierDefs.h
    //meaning of the enums, see here: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/MCTruthClassifier#Egamma_electrons_classification
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) xAOD::TruthHelpers::getParticleTruthOrigin(ele); }, *systematicTree, "electron_truthOrig");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { return (int) xAOD::TruthHelpers::getParticleTruthType(ele); }, *systematicTree, "electron_truthType");
    //Trigger matching
    Wrap2(elevec, [=](const xAOD::Electron& ele) { int is_matched(0); if (ele.isAvailable<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM18VH")) is_matched = ele.auxdataConst<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM18VH"); return (int) is_matched; }, *systematicTree, "electron_match_HLT_e24_lhmedium_L1EM18VH");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { int is_matched(0); if (ele.isAvailable<char>("TRIGMATCH_HLT_e26_lhtight_iloose")) is_matched = ele.auxdataConst<char>("TRIGMATCH_HLT_e26_lhtight_iloose"); return (int) is_matched; }, *systematicTree, "electron_match_HLT_e26_lhtight_iloose");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { int is_matched(0); if (ele.isAvailable<char>("TRIGMATCH_HLT_e60_lhmedium")) is_matched = ele.auxdataConst<char>("TRIGMATCH_HLT_e60_lhmedium"); return (int) is_matched; }, *systematicTree, "electron_match_HLT_e60_lhmedium");
    Wrap2(elevec, [=](const xAOD::Electron& ele) { int is_matched(0); if (ele.isAvailable<char>("TRIGMATCH_HLT_e120_lhloose")) is_matched = ele.auxdataConst<char>("TRIGMATCH_HLT_e120_lhloose"); return (int) is_matched; }, *systematicTree, "electron_match_HLT_e120_lhloose");

    vec_electron_wrappers.push_back(VectorWrapperCollection(elevec));
    
    // Muons
    top::check( muonSelection.setProperty("OutputLevel", MSG::VERBOSE),"muonSelection fails to set OutputLevel");
    top::check( muonSelection.setProperty( "MaxEta", 2.7 ), "muonSelection tool could not set max eta");
    top::check( muonSelection.initialize(),"muonSelection tool fails to initialize");   
   
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.pt(); }, *systematicTree, "muon_pt");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.eta(); }, *systematicTree, "muon_eta");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.phi(); }, *systematicTree, "muon_phi");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.e(); }, *systematicTree, "muon_E");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Loose && muonSelection.passedIDCuts(mu))  isqual=1; return isqual;},*systematicTree, "muon_isLoose");    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Medium && muonSelection.passedIDCuts(mu)) isqual=1; return isqual;},*systematicTree, "muon_isMedium");    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { char isqual = 0; if(muonSelection.getQuality(mu) <= xAOD::Muon::Tight && muonSelection.passedIDCuts(mu))  isqual=1; return isqual;},*systematicTree, "muon_isTight");    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdata<float>("InnerDetectorPt"); },    *systematicTree, "muon_PtID");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdata<float>("MuonSpectrometerPt"); }, *systematicTree, "muon_PtME");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.allAuthors(); }, *systematicTree, "muon_allAuthor");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.author(); }, *systematicTree, "muon_author");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) mu.muonType(); }, *systematicTree, "muon_type");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (int) (-13*mu.charge()); }, *systematicTree, "muon_ID");
    //d0  and sig d0 are wrt Beamline (see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/InDetTrackingPerformanceGuidelines#Variables) -- "PV" is left to ensure compatibility with Run1 code, but it is NOT corrected for PV position as it is not recommended
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float d0 = mu.primaryTrackParticle()->d0();  return (float) (d0); }, *systematicTree, "muon_d0");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float d0 = mu.primaryTrackParticle()->d0(); float err_d0 = sqrt(mu.primaryTrackParticle()->definingParametersCovMatrix()(0,0)); return (float) (d0/err_d0); }, *systematicTree, "muon_sigd0PV_hand");  //INACCURATE: USE following one by Tracking CP
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { double d0sig = xAOD::TrackingHelpers::d0significance( mu.primaryTrackParticle(), m_eventInfo->beamPosSigmaX(), m_eventInfo->beamPosSigmaY(), m_eventInfo->beamPosSigmaXY() ); return (float) (d0sig); }, *systematicTree, "muon_sigd0PV");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("d0significance"); }, *systematicTree, "muon_sigd0PV");
    //z0sinTh raw and corrected for PV (see https://twiki.cern.ch/twiki/bin/view/AtlasProtected/InDetTrackingDC14)
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float z0 = mu.primaryTrackParticle()->z0(); float theta = mu.primaryTrackParticle()->theta(); float sin_Th = sin(theta); return (float) (z0*sin_Th); }, *systematicTree, "muon_z0SinTheta_uncorr");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (float) mu.auxdataConst<float>("z0sintheta"); }, *systematicTree, "muon_z0SinTheta");
    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float momBalSignif = mu.floatParameter(xAOD::Muon::momentumBalanceSignificance); return (float) (momBalSignif); }, *systematicTree, "muon_momBalSignif");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatCurvSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { float scatNeighSignif = mu.floatParameter(xAOD::Muon::scatteringNeighbourSignificance); return (float) (scatNeighSignif); }, *systematicTree, "muon_scatNeighSignif");
    //Wrap2(muvec, [=](const xAOD::Muon& mu) { float qOverPSignif = mu.floatParameter(xAOD::Muon::scatteringCurvatureSignificance); return (float) (scatCurvSignif); }, *systematicTree, "muon_scatCurvSignif");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { return (short) mu.uint8SummaryValue(xAOD::SummaryType::numberOfPrecisionLayers); }, *systematicTree, "muon_numPrecLayers");
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

    //Trigger matching
    Wrap2(muvec, [=](const xAOD::Muon& mu) { int is_matched(0); if (mu.isAvailable<char>("TRIGMATCH_HLT_mu20_iloose_L1MU15")) is_matched = mu.auxdataConst<char>("TRIGMATCH_HLT_mu20_iloose_L1MU15"); return (int) is_matched; }, *systematicTree, "muon_match_HLT_mu20_iloose_L1MU15");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { int is_matched(0); if (mu.isAvailable<char>("TRIGMATCH_HLT_mu26_imedium")) is_matched = mu.auxdataConst<char>("TRIGMATCH_HLT_mu26_imedium"); return (int) is_matched; }, *systematicTree, "muon_match_HLT_mu26_imedium");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { int is_matched(0); if (mu.isAvailable<char>("TRIGMATCH_HLT_mu40")) is_matched = mu.auxdataConst<char>("TRIGMATCH_HLT_mu40"); return (int) is_matched; }, *systematicTree, "muon_match_HLT_mu40");
    Wrap2(muvec, [=](const xAOD::Muon& mu) { int is_matched(0); if (mu.isAvailable<char>("TRIGMATCH_HLT_mu50")) is_matched = mu.auxdataConst<char>("TRIGMATCH_HLT_mu50"); return (int) is_matched; }, *systematicTree, "muon_match_HLT_mu50");

    //truth origin HERE
    //For muons - one more step as the info is attached to TruthMuonParticle, not xAOD::Muon. 
    //coding of the enums, see here: https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/MCTruthClassifier/tags/MCTruthClassifier-00-00-26/MCTruthClassifier/MCTruthClassifierDefs.h
    //meaning of the enums, see here: https://twiki.cern.ch/twiki/bin/view/AtlasProtected/MCTruthClassifier#Egamma_electrons_classification
    Wrap2(muvec, [=](const xAOD::Muon& mu) { 
	const xAOD::TruthParticle* matched_truth_muon=0;
	int mu_type = -99;
	if(mu.isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
	  ElementLink<xAOD::TruthParticleContainer> link = mu.auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
	  if(link.isValid()){
	    matched_truth_muon = *link;
	    mu_type = matched_truth_muon->auxdata<int>("truthType");
	  }
	} return (int) mu_type; }, *systematicTree, "muon_truthType");
    
    Wrap2(muvec, [=](const xAOD::Muon& mu) { 
	const xAOD::TruthParticle* matched_truth_muon=0;
	int mu_orig = -99;
	if(mu.isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
	  ElementLink<xAOD::TruthParticleContainer> link = mu.auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
	  if(link.isValid()){
	    matched_truth_muon = *link;
	    mu_orig = matched_truth_muon->auxdata<int>("truthOrigin");
	  }
	} return (int) mu_orig; }, *systematicTree, "muon_truthOrigin");
    
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
    
    vec_muon_wrappers.push_back(VectorWrapperCollection(muvec));
  
    //Jet cleaning tool is initialized here
    cleaningTool = new JetCleaningTool("MyCleaningTool");
    top::check( cleaningTool->setProperty("CutLevel", "LooseBad"), "Jet Cleaning tool failed to set cut level"); // also "TightBad"
    top::check( cleaningTool->setProperty("DoUgly", false), "Jet Cleaning tool failed to set value for DoUgly flag");
    top::check( cleaningTool->initialize(), "Jet Cleaning tool failed to initialize");

    // Jets
    std::vector<VectorWrapper*> jetvec;
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.pt(); }, *systematicTree, "m_jet_pt");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.eta(); }, *systematicTree, "m_jet_eta");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.phi(); }, *systematicTree, "m_jet_phi");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return (float) jet.e(); }, *systematicTree, "m_jet_E");
    // is it the 1 GeV counting we want?
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto tmp = jet.getAttribute<std::vector<float> >("SumPtTrkPt1000"); return (float) (tmp.size() ? tmp[0] : 0.); }, *systematicTree, "m_jet_sumPtTrk");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("EMFrac"); }, *systematicTree, "m_jet_emfrac");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { std::vector<float> tmp = jet.getAttribute<std::vector<float> >("JVF"); return (float) (tmp.size() ? tmp[0] : -2); }, *systematicTree, "m_jet_jvtxf");
    // not in sample xAOD
    //Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<float>("Jvt"); }, *systematicTree, "m_jet_jvt_uncal");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.jetP4("JetEMScaleMomentum").eta(); }, *systematicTree, "m_jet_etaEM");    
    Wrap2(jetvec, [](const xAOD::Jet& jet) { float this_jvt = -999.; if(jet.isAvailable<float>("AnalysisTop_JVT")) this_jvt = jet.auxdataConst<float>("AnalysisTop_JVT"); return this_jvt;}, *systematicTree, "m_jet_jvt");
    //Jet cleaning flag
    Wrap2(jetvec, [=](const xAOD::Jet& jet) { int keepJet = cleaningTool->keep(jet); return (int)keepJet;}, *systematicTree, "m_jet_isLooseBad"); 
    // No label tagging in sample MC
    //if (0) {
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("ConeTruthLabelID"); }, *systematicTree, "m_jet_flavor_truth_label");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { return jet.getAttribute<int>("PartonTruthLabelID"); }, *systematicTree, "m_jet_flavor_truth_label_ghost");
    //}
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); return (float) (btagging ? btagging->MV1_discriminant() : 0.); }, *systematicTree, "m_jet_flavor_weight_MV1");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c00", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c00");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c10");
    Wrap2(jetvec, [](const xAOD::Jet& jet) { auto btagging = jet.btagging(); double rv(0); return (float) (btagging && btagging->MVx_discriminant("MV2c20", rv) ? rv : 0.); }, *systematicTree, "m_jet_flavor_weight_MV2c20");
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
    //Wrap2(tauvec, [](const xAOD::TauJet& tau) {float d = 1e6; tau.detail(xAOD::TauJetParameters::Detail::ipZ0SinThetaSigLeadTrk, d); return d;}, *systematicTree, std::string(tauprefix+"ipZ0SinThetaSigLeadTrk").c_str());
    //Wrap2(tauvec, [](const xAOD::TauJet& tau) {float d = 1e6; tau.detail(xAOD::TauJetParameters::Detail::ipSigLeadTrk, d); return d;}, *systematicTree, std::string(tauprefix+"ipSigLeadTrk").c_str());

    Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	int isTruthMatched = 0;
    	if(tau.isAvailable<char>("IsTruthMatched")) isTruthMatched = (int) tau.auxdata<char>("IsTruthMatched");
	return isTruthMatched;
      }, *systematicTree, std::string(tauprefix+"isTruthMatched").c_str());

    //decorated in ttHMultileptonLooseEventSaver_Decorate.cxx
    Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	return tau.auxdata<int>("IsHadronic");
      }, *systematicTree, std::string(tauprefix+"isHadronicTau").c_str());
    
    Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	return tau.auxdata<int>("tauTruthOrigin");
      }, *systematicTree, std::string(tauprefix+"truthOrigin").c_str());

    Wrap2(tauvec, [&](const xAOD::TauJet& tau) {
	return tau.auxdata<int>("tauTruthType");
      }, *systematicTree, std::string(tauprefix+"truthType").c_str());
    
    Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	return tau.auxdata<double>("TauScaleFactorReconstructionHadTau");
      }, *systematicTree, std::string(tauprefix+"RecoSF").c_str());

    Wrap2(tauvec, [](const xAOD::TauJet& tau) {
	return tau.auxdata<int>("passEleOLR");
      }, *systematicTree, std::string(tauprefix+"passEleOLR").c_str());
    
    vec_tau_wrappers.push_back(VectorWrapperCollection(tauvec));

    //tau tools
    top::check( m_tauEffTool.initialize(), "Failed to initialise TauEffTool" );
    m_tauSelectionEleOLR.msg().setLevel(MSG::VERBOSE);
    top::check( m_tauSelectionEleOLR.setProperty("ConfigPath", "ttHMultilepton/EleOLR_tau_selection.conf" ), "TauSelectionEleOLR:Failed to set ConfigPath");
    top::check( m_tauSelectionEleOLR.initialize(), "Failed to initialise TauSelectionTool for EleOLR" );
    
    
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
    m_variables = new ttHMultilepton::Variables();
    m_variables->BootstrapTree(systematicTree);
  }

  // dont mix MC and data in the same job
  m_isMC = config->isMC();

  // Shall we do scale factors?
  if (config->doCalculateSF()) {
    m_sfRetriever = std::unique_ptr<top::ScaleFactorRetriever> ( new top::ScaleFactorRetriever( config ) );
  }
  
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
  //if(!event.m_saveEvent) {
  // return;
  //}
  
  m_mcWeight = 1.;
  m_pileup_weight = 1.;
  m_leptonSF_weight = 1.;
  m_mcChannelNumber = 0;
 
  if (top::isSimulation(event)){
    m_mcChannelNumber = event.m_info->mcChannelNumber();
    m_mcWeight        = event.m_info->mcEventWeight(); 
    if(m_sfRetriever){
      m_pileup_weight   = m_sfRetriever->pileupSF(event);
      m_leptonSF_weight = m_sfRetriever->leptonSF(event,top::topSFSyst::nominal);
    }
  }

  //event info
  m_eventNumber = event.m_info->eventNumber();
  m_runNumber = event.m_info->runNumber();
  m_mu_ac   = event.m_info->actualInteractionsPerCrossing();
  m_mu_unc  = event.m_info->averageInteractionsPerCrossing();
  //see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/ExtendedPileupReweighting#Using_the_tool_for_pileup_reweig
  //top::check(m_purwtool->apply( *event.m_info ), "Failed to apply pileup weight");
  m_mu      = m_purwtool->getLumiBlockMu( *event.m_info);
  if(top::isSimulation(event)){
    m_mu      = m_mu_unc;
    m_pu_hash = m_purwtool->getPRWHash( *event.m_info );
  }

  //Event selection variable for each event selection region (pass/fail)
  recordSelectionDecision(event);

  //met
  m_met_met = event.m_met->met();
  m_met_phi = event.m_met->phi();
  
  //MC particle
  if (event.m_truth != nullptr) {
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

  //TruthEvent info here (pdf, MC weights, etc)
  if (event.m_truthEvent != nullptr) {
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
  for (const xAOD::Vertex* vtx : *m_vertices){ 
    if(vtx->vertexType() == xAOD::VxType::PriVtx) m_pvNumber++;
    else if( vtx->vertexType() == xAOD::VxType::PileUp ) m_puNumber++;
  }
  
  m_variables->Clear();
  Decorate(event);
  auto goodEl = SelectElectrons(event);
  auto goodMu = SelectMuons(event);
  auto goodJet = SelectJets(event);
  auto goodTau = SelectTaus(event);
  OverlapRemoval(goodEl, goodMu, goodJet, goodTau, event.m_ttreeIndex == 0);
  CopyLeptons(goodEl, goodMu);
  CopyJets(goodJet);
  CopyTaus(goodTau);
  CheckIsBlinded();

  vec_scalar_wrappers[event.m_ttreeIndex].push_all(event);
  vec_electron_wrappers[event.m_ttreeIndex].push_all(event.m_electrons);
  vec_muon_wrappers[event.m_ttreeIndex].push_all(event.m_muons);
  vec_jet_wrappers[event.m_ttreeIndex].push_all(event.m_jets);
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
  // copy number of events before event cleaning for data
  if(!m_isMC) {
    double goodCalo = static_cast<TH1D*>(m_outputFile->Get("loose/cutflow"))->GetBinContent(2);
    static_cast<TH1D*>(m_outputFile->Get("loose/Count"))->SetBinContent(3,goodCalo);
  }
  m_outputFile->WriteTObject(m_eleCutflow);
  m_outputFile->WriteTObject(m_muCutflow);
  m_outputFile->WriteTObject(m_jetCutflow);
  m_outputFile->WriteTObject(m_tauCutflow);
  m_outputFile->Write();
}
