#ifndef TTHMULTILEPTON_TAUMC15_H_
#define TTHMULTILEPTON_TAUMC15_H_

#include "TopObjectSelectionTools/TauSelectionBase.h"
#include "TauAnalysisTools/TauSelectionTool.h"

namespace ttHMultilepton {

/**
 * @brief To select taus based on BoostedDecisionTree definition.
 */
class TauMC15 : public top::TauSelectionBase {
public:
    /**
     * @brief Cut on  BDT based tauJetID and tauEleID 
     *
     * @param configPath path the to config file for the TauSelectionTool
     */
  TauMC15(std::string configPath);

    virtual ~TauMC15(){}
    /**
     * @brief Selection for the main analysis (i.e. tight object definitions).
     *
     * @param tauJet The tau in question
     * @return True if it passes the selection, false otherwise.
     */
    virtual bool passSelection(const xAOD::TauJet& tau) const override;

    /**
     * @brief Selection for the "loose" object definitions (e.g. in fakes
     * estimates).
     *
     * @param tauJet The tau in question
     * @return True if it passes the selection, false otherwise.
     */
    virtual bool passSelectionLoose(const xAOD::TauJet& tau) const override;

    /**
     * @brief Why would you not want to know what you're running?
     *
     * @param os Print details of the cuts to the output stream.
     */
    virtual void print(std::ostream& os) const override;

    
protected:

  // path to config file for TauSelectionTool
  std::string m_configPath;
  
  ///The likelihood tool to use for the tight (main) analysis.
  std::unique_ptr<TauAnalysisTools::TauSelectionTool> m_tauSelection;

};

}

#endif //TTHMULTILEPTON_TAUMC15_H_
