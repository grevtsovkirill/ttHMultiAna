#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "ttHMultilepton/SignalRegionPreselection.h"

#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

SignalRegionPreselection::SignalRegionPreselection(const std::string& params, std::shared_ptr<top::TopConfig> config) :
  m_event(0),
  m_config(config)  
{
   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }

  m_params = params;

}

bool SignalRegionPreselection::apply(const top::Event& event) const {
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

    if(!m_asgHelper->evtStore()->retrieve(Electrons,"SelectedORElectrons_"+m_config->systematicName(m_event->m_hashValue) + "_" + std::to_string(event.m_isLoose)) || 
                !m_asgHelper->evtStore()->retrieve(Muons,"SelectedORMuons_"+m_config->systematicName(event.m_hashValue) + "_" + std::to_string(event.m_isLoose)) || 
                !m_asgHelper->evtStore()->retrieve(Taus,"SelectedORTaus_"+m_config->systematicName(event.m_hashValue) + "_" + std::to_string(event.m_isLoose)) ){
      std::cout<< "Failed to retrieve leptons, skip event" << std::endl;

      std::cout << "-----> more info: <params: " << m_params
                << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
      return false;
    }

	const int totalLeptons = Electrons->size() +  Muons->size();
	int totalTaus = Taus->size();
	int totalCharge = 0;
	for (const auto elItr : *Electrons) { totalCharge += elItr->charge(); }
	for (const auto muItr : *Muons) { totalCharge += muItr->charge(); }
	tthevt->totalLeptons = totalLeptons;
	tthevt->totalTaus = totalTaus;
	tthevt->totalCharge = totalCharge;
	



	//Set as if false for now, should make this configurable from config file
	if(m_params == "SRONLY"){
		if (totalLeptons + totalTaus < 2)
			return false;
		if (totalLeptons == 2 && totalTaus == 0 && totalCharge == 0 )
			return false;
		if (totalLeptons == 1 && totalTaus <= 1)
			return false;
	} else if(m_params == "LEPTONS") {
		if (totalLeptons + totalTaus == 0)
			return false;
	} else if(m_params == "NONE") {
			return true;
	} else if(m_params == ""){
		std::cout << "No parameter given for SRPRESKIM" << std::endl;
	} else {
		std::cout << "SRPRESKIM is not configured properly. Skipping..." << std::endl;
	}
    return true;
}

bool SignalRegionPreselection::applyParticleLevel(const top::ParticleLevelEvent& event) const {
    return false;
}

std::string SignalRegionPreselection::name() const{
	return "SRPRESKIM";
} 

