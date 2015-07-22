#include "ttHMultilepton/TauMC15.h"

// error checking
#include "TopEvent/EventTools.h"

namespace ttHMultilepton {

  TauMC15::TauMC15(std::string configPath) :
    m_configPath(configPath),
    m_tauSelection(new TauAnalysisTools::TauSelectionTool("TauSelectionTool"))
  {

    //set the tool to verbose
    m_tauSelection->msg().setLevel(MSG::VERBOSE);
    // main selection: tight-like taus
    top::check(m_tauSelection->setProperty("ConfigPath", m_configPath ), "TauMC15:Failed to set ConfigPath");
    top::check(m_tauSelection->initialize(), "TauMC15:Failed to initialize TauSelectionTool for tight-like object");
  }

  bool TauMC15::passSelection(const xAOD::TauJet& tau) const {
    //return true;
    // get the WP related decisions from TauSelectionTool
    if(!m_tauSelection->accept(tau)) return false;
    return true;
  }

  bool TauMC15::passSelectionLoose(const xAOD::TauJet& tau) const {
    return true;
  }

  void TauMC15::print(std::ostream& os) const {
    os << "TauMC15\n";
    os << "Configured by: " << m_configPath << "\n";
  }
  
}
