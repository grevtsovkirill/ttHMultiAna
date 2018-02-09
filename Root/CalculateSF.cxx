#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/CalculateSF.h"
#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "ttHMultilepton/Variables.h"


#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

CalculateSF::CalculateSF(const std::string& params, std::shared_ptr<top::TopConfig> config) :
  m_event(0),
  m_sfRetriever(nullptr),
  m_config(config)  
{

   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   }
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }

   m_sfRetriever = std::unique_ptr<top::ScaleFactorRetriever> ( new top::ScaleFactorRetriever( config ) );
   
  m_params = params;

}

bool CalculateSF::apply(const top::Event& event) const {
	m_event = &event;
 	if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
    	std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
    	std::cout << "-----> more info: <params: " << m_params
          << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
    	std::cout << "------> aborting :-( " << std::endl;
    	abort();
    }

	std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
	const xAOD::ElectronContainer* Electrons(nullptr);
	const xAOD::MuonContainer* Muons(nullptr);
	const xAOD::TauJetContainer* Taus(nullptr);
	top::check( m_asgHelper->evtStore()->retrieve(Electrons,"SelectedORElectrons"),"Failed to retrieve Electrons");
	top::check( m_asgHelper->evtStore()->retrieve(Muons,"SelectedORMuons"),"Failed to retrieve Muons");
	top::check( m_asgHelper->evtStore()->retrieve(Taus,"SelectedORTaus"),"Failed to retrieve Taus"); 


	typedef std::tuple<const TLorentzVector*, int, std::string> sorttype_t;
	std::vector<sorttype_t> sorter;
	int idx = 0;
	for( const auto elItr : *Electrons){
		sorter.push_back(sorttype_t(&(elItr->p4()), idx, "ELECTRON"));
		idx++;
	}
	idx = 0;
	for( const auto muItr: *Muons){
		sorter.push_back(sorttype_t(&(muItr->p4()), idx, "MUON"));
		idx++;
	}
	
	TLorentzVector p4OS;
	bool is_trilep_q1 = false;
	if(tthevt->totalLeptons == 3 && abs(tthevt->totalCharge) == 1) {is_trilep_q1 = true;}
	if(is_trilep_q1){
		for(const auto elItr : *Electrons){
			if (elItr->charge() == -tthevt->totalCharge){
				p4OS = elItr->p4(); break;
			}
		}
		for(const auto muItr : *Muons){
            if (muItr->charge() == -tthevt->totalCharge){
                p4OS = muItr->p4(); break;
            }
        }
		// For Trilep Type, sort by increasing deltaR from OS lepton (= OS first)
		std::sort(sorter.begin(), sorter.end(),
			[p4OS](sorttype_t a, sorttype_t b) {return std::get<0>(a)->DeltaR(p4OS) < std::get<0>(b)->DeltaR(p4OS);});
	} else {
		// Sort by decreasing pT
		std::sort(sorter.begin(), sorter.end(),
			[](sorttype_t a, sorttype_t b) {return std::get<0>(a)->Pt() > std::get<0>(b)->Pt();});
	}
	
	for (const auto& systvar : tthevt->m_lep_sf_names) {	
	  auto ivar = systvar.first;
	  m_SF.lepSFIDLoose[ivar] = 1;
	  m_SF.lepSFIDTight[ivar] = 1;
	  m_SF.lepSFIsoLoose[ivar] = 1;
	  m_SF.lepSFIsoTight[ivar] = 1;
	  m_SF.lepSFReco[ivar] = 1;
	  m_SF.lepSFTTVA[ivar] = 1;
	  m_SF.lepSFTrigLoose[ivar] = 1;
	  m_SF.lepSFTrigTight[ivar] = 1;
	  m_SF.lepSFObjLoose[ivar] = 1;
	  m_SF.lepSFObjTight[ivar] = 1;
	  m_SF.tauSFLoose[ivar] = 1;
	  m_SF.tauSFTight[ivar] = 1;
	}
	for (const auto& systvar : tthevt->m_tau_sf_names ) {
	  auto ivar = systvar.first;
	  tthevt->tauSFTight[ivar] = 1;
	  tthevt->tauSFLoose[ivar] = 1;
	}

	std::vector<bool> tightIsLoose;
	if (tthevt->totalLeptons == 2 && tthevt->totalCharge == 0 && tthevt->nTaus_OR_Pt25 != 0) {
	  //  for 2los1tau tight = loose*loose
	  tightIsLoose.push_back(true);
	  tightIsLoose.push_back(true);
	} else if (tthevt->totalLeptons == 3) {
	  // for 3l0tau and 3l1tau tight = loose*tight*tight
	  tightIsLoose.push_back( true);
	  tightIsLoose.push_back( false);
	  tightIsLoose.push_back( false);
	} else if (tthevt->totalLeptons == 4) {
	  // for 4l tight = loose*loose*tight*tight
	  tightIsLoose.push_back( true);
	  tightIsLoose.push_back( true);
	  tightIsLoose.push_back( false);
	  tightIsLoose.push_back( false);
	} else {
	  for (int ilep = 0; ilep < tthevt->totalLeptons; ++ilep) {
	    tightIsLoose.push_back( false);
	  }
  	}


	int tightItr = 0;	
	for( const auto lepItr : sorter) {
	  const TLorentzVector* p4;
	  int lidx;
	  std::string type;
	  std::tie(p4, lidx, type) = lepItr;
	  if(type == "ELECTRON"){
	    doEventSFs_Helper(*(*Electrons)[lidx], tightIsLoose[tightItr], tthevt->m_lep_sf_names);
	  } else if (type == "MUON"){
	    doEventSFs_Helper(*(*Muons).at(lidx), tightIsLoose.at(tightItr), tthevt->m_lep_sf_names);
	  } else { std::cout << "ERROR!! INVALID TYPE" << std::endl;}
	  tightItr++;
	}


	tthevt->lepSFIDLoose = m_SF.lepSFIDLoose[0]; 
	tthevt->lepSFIDTight = m_SF.lepSFIDTight[0];
	tthevt->lepSFIsoLoose = m_SF.lepSFIsoLoose[0];
	tthevt->lepSFIsoTight = m_SF.lepSFIsoTight[0];
	tthevt->lepSFReco = m_SF.lepSFReco[0];
	tthevt->lepSFTTVA = m_SF.lepSFTTVA[0];
	

	for (const auto& systvar: tthevt->m_lep_sf_names){
	  auto ivar = systvar.first;
	  tthevt->lepSFObjLoose[ivar] = m_SF.lepSFObjLoose[ivar];
	  tthevt->lepSFObjTight[ivar] = m_SF.lepSFObjTight[ivar];
	}


 
    //taus
    bool m_isMC = m_config->isMC();
    for ( int itau = 0; itau<tthevt->totalTaus; ++itau) {
		for ( auto syst : tthevt->m_tau_sf_names ) {
        	auto ivar = syst.first;
        	m_SF.tauSFLoose[ivar] *= m_isMC ? m_sfRetriever->tauSF(*(*Taus).at(itau), ivar, false) : 1.0;
        	m_SF.tauSFTight[ivar] *= m_isMC ? m_sfRetriever->tauSF(*(*Taus).at(itau), ivar, true)  : 1.0;
    	}
	}
	for (const auto& systvar : tthevt->m_tau_sf_names){
		auto ivar = systvar.first;
		tthevt->tauSFLoose[ivar] = m_SF.tauSFLoose[ivar];
        tthevt->tauSFTight[ivar] = m_SF.tauSFTight[ivar];
 	}
 	




	//normalise variations
    for (const auto& systvar : tthevt->m_lep_sf_names) {
      const auto ivar = systvar.first;
      if (ivar == top::topSFSyst::nominal) continue;
      tthevt->lepSFObjLoose[ivar] /= tthevt->lepSFObjLoose[0];
      tthevt->lepSFObjTight[ivar] /= tthevt->lepSFObjTight[0];
    }


	for ( auto syst : tthevt->m_tau_sf_names ) {
		auto ivar = syst.first;
		if( ivar == top::topSFSyst::nominal ) continue;
		tthevt->tauSFTight[ivar] /= tthevt->tauSFTight[top::topSFSyst::nominal];
		tthevt->tauSFLoose[ivar] /= tthevt->tauSFLoose[top::topSFSyst::nominal];
	}
       

	sorter.clear();
	tightIsLoose.clear();
	return true;
}

void CalculateSF::doEventSFs_Helper(const xAOD::Electron_v1& el, bool tightIsLoose, std::map<top::topSFSyst, std::string> m_lep_sf_names) const {
	for (const auto& systvar : m_lep_sf_names){	
	  auto ivar = systvar.first;
	  
	  m_SF.lepSFIDLoose[ivar] *= m_sfRetriever->electronSF_ID(el, ivar, false);
	  m_SF.lepSFIDTight[ivar] *= m_sfRetriever->electronSF_ID(el, ivar, !tightIsLoose);
	  
	  m_SF.lepSFIsoLoose[ivar] *= m_sfRetriever->electronSF_Isol(el, ivar, false);
	  m_SF.lepSFIsoTight[ivar] *= m_sfRetriever->electronSF_Isol(el, ivar, !tightIsLoose);
	  
	  m_SF.lepSFReco[ivar] *= m_sfRetriever->electronSF_Reco(el, ivar);
	  m_SF.lepSFTTVA[ivar] *= 1;
	  
	  m_SF.lepSFTrigLoose[ivar] *= m_sfRetriever->electronSF_Trigger(el, ivar, false);
	  m_SF.lepSFTrigTight[ivar] *= m_sfRetriever->electronSF_Trigger(el, ivar, !tightIsLoose);
	  if(m_SF.lepSFTrigLoose[ivar] == 0) m_SF.lepSFTrigLoose[ivar] = 1;
	  if(m_SF.lepSFTrigTight[ivar] == 0) m_SF.lepSFTrigTight[ivar] = 1;
	  
	  m_SF.lepSFObjLoose[ivar] *= m_SF.lepSFIDLoose[ivar]*m_SF.lepSFIsoLoose[ivar]*m_SF.lepSFReco[ivar];
	  m_SF.lepSFObjTight[ivar] *= (tightIsLoose ? m_SF.lepSFObjLoose[ivar] :  m_SF.lepSFIDTight[ivar]*m_SF.lepSFIsoTight[ivar]*m_SF.lepSFReco[ivar] );
	}
}
void CalculateSF::doEventSFs_Helper(const  xAOD::Muon_v1& mu, bool tightIsLoose, std::map<top::topSFSyst, std::string> m_lep_sf_names) const {
	bool m_isMC = m_config->isMC();
	for (const auto& systvar : m_lep_sf_names){
	  auto ivar = systvar.first;
	  m_SF.lepSFIDLoose[ivar] *= m_sfRetriever->muonSF_ID(mu, ivar, false);
	  m_SF.lepSFIDTight[ivar] *= m_sfRetriever->muonSF_ID(mu, ivar, !tightIsLoose);
	  
	  m_SF.lepSFIsoLoose[ivar] *= m_sfRetriever->muonSF_Isol(mu, ivar, false);
	  m_SF.lepSFIsoTight[ivar] *= m_sfRetriever->muonSF_Isol(mu, ivar, !tightIsLoose);
	  
	  m_SF.lepSFReco[ivar] *= 1;
	  m_SF.lepSFTTVA[ivar] *= m_isMC ? m_sfRetriever->muonSF_TTVA(mu, ivar) : 1.0;
	  
	  m_SF.lepSFTrigLoose[ivar] *= m_sfRetriever->muonSF_Trigger(mu, ivar, false);
	  m_SF.lepSFTrigTight[ivar] *= m_sfRetriever->muonSF_Trigger(mu, ivar, !tightIsLoose);
	  if(m_SF.lepSFTrigLoose[ivar] == 0) m_SF.lepSFTrigLoose[ivar] = 1;
	  if(m_SF.lepSFTrigTight[ivar] == 0) m_SF.lepSFTrigTight[ivar] = 1;
	  
	  m_SF.lepSFObjLoose[ivar] *= m_SF.lepSFIDLoose[ivar]*m_SF.lepSFIsoLoose[ivar]*m_SF.lepSFReco[ivar];
	  m_SF.lepSFObjTight[ivar] *= (tightIsLoose ? m_SF.lepSFObjLoose[ivar] :  m_SF.lepSFIDTight[ivar]*m_SF.lepSFIsoTight[ivar]*m_SF.lepSFReco[ivar] );
	}

}


bool CalculateSF::applyParticleLevel(const top::ParticleLevelEvent& event) const {
    return false;
}

std::string CalculateSF::name() const{
	return "CALCULATESF";
} 

