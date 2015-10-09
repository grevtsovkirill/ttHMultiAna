#include "ttHMultilepton/ttHMultileptonElectronLikelihoodDC14.h"

#include "TopEvent/EventTools.h"

namespace ttHMultilepton {

ElectronLikelihoodDC14::ElectronLikelihoodDC14(double ptcut, bool vetoCrack, LikeEnum::Menu operatingPoint, LikeEnum::Menu operatingPointLoose, IsolationBase* isolation) :
                m_operatingPoint(operatingPoint),
                m_operatingPointLoose(operatingPointLoose),
                m_ptcut(ptcut),
                m_vetoCrack(vetoCrack),
                m_isolation(isolation),
		m_workingPointList 
                    { { LikeEnum::Loose, "LHLoose" }, 
	              { LikeEnum::Medium, "LHMedium" }, 
                      { LikeEnum::Tight, "LHTight" } }
 {

    // Set up likelihood tool map
    for (const auto wp : m_workingPointList) {
      //std::cout << wp.first << " " << wp.second << std::endl;
      auto ltool = new AsgElectronLikelihoodTool("CP::AsgElectronLikelihoodToolGeneric" + wp.second);
      top::check(ltool->setProperty("primaryVertexContainer", "PrimaryVertices"), "Failed to set LHSelector property");
      top::check(ltool->setProperty("ConfigFile", getConfigFile(wp.first)), "Failed to set config file");
      top::check(ltool->initialize(), "Failed to initialise LHSelector");
      m_likelihoodToolMap[wp.first].reset(ltool);
    } 

}

bool ElectronLikelihoodDC14::passSelection(const xAOD::Electron& el) const {
  // decorate electron with likelihood pattern
  if ((el.author() != xAOD::EgammaParameters::AuthorElectron && el.author() != xAOD::EgammaParameters::AuthorAmbiguous) || el.pt() < m_ptcut) {
    // do not consider this electron object
    for (const auto wp : m_workingPointList) {
      el.auxdecor<short>("pass" + wp.second) = false;
    }
  } else {
    for (const auto wp : m_workingPointList) {
      el.auxdecor<short>("pass" + wp.second) = m_likelihoodToolMap.at(wp.first)->accept(el);
    }
  }
  if (!passSelectionNoIsolation(el, m_likelihoodToolMap.at(m_operatingPoint)))
        return false;

    if (m_isolation && !m_isolation->passSelection(el))
        return false;

    return true;
}

bool ElectronLikelihoodDC14::passSelectionLoose(const xAOD::Electron& el) const {
  if (!passSelectionNoIsolation(el, m_likelihoodToolMap.at(m_operatingPointLoose)))
        return false;

    if (m_isolation && !m_isolation->passSelectionLoose(el))
        return false;

    return true;
}

bool ElectronLikelihoodDC14::passSelectionNoIsolation(const xAOD::Electron& el, std::shared_ptr<AsgElectronLikelihoodTool> likelihoodTool) const {
    if (el.author() != xAOD::EgammaParameters::AuthorElectron && el.author() != xAOD::EgammaParameters::AuthorAmbiguous)
        return false;

    if (el.pt() < m_ptcut)
        return false;

    if (!likelihoodTool->accept(el))
        return false;

    //WARNING: Not all electrons keep clusters in the derivation
    //i.e. bad electrons (which is why we moved the check on the likelihood
    //before the check on the calo cluster)
    //This stops a crash
    //Good electrons should always have a cluster, if not then crash to warn us
    //Better than checking and silently doing nothing...
    //if (std::fabs(el.caloCluster()->eta()) > 2.47)
    if (std::fabs(el.caloCluster()->etaBE(2)) > 2.47)
         return false;

    //if (m_vetoCrack && std::fabs(el.caloCluster()->eta()) > 1.37 && std::fabs(el.caloCluster()->eta()) < 1.52)
    if (m_vetoCrack && std::fabs(el.caloCluster()->etaBE(2)) > 1.37 && std::fabs(el.caloCluster()->etaBE(2)) < 1.52)
        return false;

    return true;
}

void ElectronLikelihoodDC14::print(std::ostream& os) const {
    os << "ElectronLikelihoodDC14\n";
    os << "    * pT > " << m_ptcut << "\n";
    os << "    * |cluster_eta BE(2)| < 2.47 is applied hard-wired in the code\n";
    os << "    * Veto 1.37 < |cluster_eta BE(2)| < 1.52? " << std::boolalpha << m_vetoCrack << "\n";

    //os << "    * LH Tool Operating Point: " << m_likelihood->getOperatingPointName() << "\n";
    //does exactly what I want but is a private method in the likelihood class :( - asked egamma to make it public

    //hack because of above
    std::string op;
    if (m_operatingPoint == LikeEnum::VeryLoose)
        op = "VeryLoose";
    else if (m_operatingPoint == LikeEnum::Loose)
        op =  "Loose";
    else if (m_operatingPoint == LikeEnum::Medium)
        op =  "Medium";
    else if (m_operatingPoint == LikeEnum::Tight)
        op =  "Tight";
    else if (m_operatingPoint == LikeEnum::VeryTight)
        op =  "VeryTight";
    else if (m_operatingPoint == LikeEnum::LooseRelaxed)
        op =  "LooseRelaxed";
    else if (m_operatingPoint == LikeEnum::CustomOperatingPoint)
        op =  "CustomOperatingPoint";

    os << "    * LH Tool Operating Point: " << op << "\n";
    //end hack

    if (!m_isolation)
        os << "    * No isolation requirement\n";
    else
        m_isolation->print(os);
}

LikeEnum::Menu ElectronLikelihoodDC14::textToEgammaEnum(const std::string& text) {
    LikeEnum::Menu operatingPoint;
    if (text == "LHLoose" || text == "LooseLH")
        operatingPoint = LikeEnum::Loose;
    else if (text == "LHMedium" || text == "MediumLH")
        operatingPoint = LikeEnum::Medium;
    else if (text == "LHTight" || text == "TightLH")
        operatingPoint = LikeEnum::Tight;
    else {
        std::cout << "ElectronLikelihoodDC14: Not sure what to set the Electron LH Quality to - LHLoose, LHMedium, LHTight are allowed" << std::endl;
        std::cout << "You said --" << text << "--" << std::endl;
        exit(1);
    }

    return operatingPoint;
}

std::string ElectronLikelihoodDC14::getConfigFile(const LikeEnum::Menu operatingPoint) {
  std::string config_file = "ElectronPhotonSelectorTools/offline/mc15_20150429/";

  if (operatingPoint == LikeEnum::Tight)
    config_file += "ElectronLikelihoodTightOfflineConfig2015.conf";
  else if (operatingPoint == LikeEnum::Medium)
    config_file += "ElectronLikelihoodMediumOfflineConfig2015.conf";
  else if (operatingPoint == LikeEnum::Loose)
    config_file += "ElectronLikelihoodLooseOfflineConfig2015.conf";
  
  return config_file;
  
}

}
