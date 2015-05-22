#ifndef TTHELECTRONLIKELIHOODDC14_H_
#define TTHELECTRONLIKELIHOODDC14_H_

#include "TopObjectSelectionTools/ElectronSelectionBase.h"
#include "TopObjectSelectionTools/IsolationTools.h"

#include "ElectronPhotonSelectorTools/AsgElectronLikelihoodTool.h"

#include <memory>

using top::IsolationBase;

namespace ttHMultilepton {

/**
 * @brief To select electrons based on the "likelihood" definition.
 */
class ElectronLikelihoodDC14 : public top::ElectronSelectionBase {
public:
    /**
     * @brief Cut on likelihood electrons
     *
     * @param ptcut The minimum pT electrons should have
     * @param vetoCrack Do you want to veto 1.37 < |cluster_eta| < 1.52?
     * @param operatingPoint Likelihood operating point for the main object
     * definition
     * @param operatingPointLoose Likelihood operating point for the loose
     * objects (fakes estimates?)
     * @param isolation The isolation tool the user wants to use.  If you don't
     * want any isolation cuts to be applied then leave this as a nullptr.
     */
    ElectronLikelihoodDC14(double ptcut, bool vetoCrack, LikeEnum::Menu operatingPoint, LikeEnum::Menu operatingPointLoose, IsolationBase* isolation);

    /**
     * @brief Selection for the main analysis (i.e. tight object definitions).
     *
     * @param el The electron in question
     * @return True if it passes the selection, false otherwise.
     */
    bool passSelection(const xAOD::Electron& el) const override;

    /**
     * @brief Selection for the loose object definitions (e.g. in fakes
     * estimates).
     *
     * @param el The electron in question
     * @return True if it passes the selection, false otherwise.
     */
    bool passSelectionLoose(const xAOD::Electron& el) const override;

    /**
     * @brief Why would you not want to know what you're running?
     *
     * @param os Print details of the cuts to the output stream.
     */
    void print(std::ostream& os) const override;

    /**
     * @brief So that we can convert a string into the egamma enum for the
     * likelihood tool.
     *
     * Do they have some code to do this, so we don't have to?
     *
     * @param text The string
     * @return Either a valid enum, or ends the program with a message.  We can't
     * really have invalid things running in a job now, can we?
     */
    static LikeEnum::Menu textToEgammaEnum(const std::string& text);

private:
    /**
     * @brief The loose and tight selections are the same, except they have different
     * isolation and use a different likelihood tool.
     *
     * @param el The electron in question.
     * @param likelihoodTool The tool to use (m_likelihood, or m_likelihoodLoose)
     * @return True if it's good, False if it's not
     */
    bool passSelectionNoIsolation(const xAOD::Electron& el, std::shared_ptr<AsgElectronLikelihoodTool> likelihoodTool) const;

    /**
     *
     *
     *
     */
  std::string getConfigFile(const LikeEnum::Menu operatingPoint);
  
    ///todo: remove Only needed to cout - remove when Likelihood tool updated to make getOperatingPointName public
    LikeEnum::Menu m_operatingPoint;
    LikeEnum::Menu m_operatingPointLoose;

    ///Minimum pT that electrons should have
    double m_ptcut;

    ///Veto the crack region?
    bool m_vetoCrack;

    ///Likelihood tools for ALL the working points
    std::map<LikeEnum::Menu, std::shared_ptr<AsgElectronLikelihoodTool> > m_likelihoodToolMap;

    ///The isolation tool, or nullptr.
    std::unique_ptr<top::IsolationBase> m_isolation;

    // List of working points (shouldn't change during a job ...)
    std::vector<std::pair<LikeEnum::Menu, std::string> > m_workingPointList;

};

}

#endif
