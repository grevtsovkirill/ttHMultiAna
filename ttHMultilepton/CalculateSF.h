#ifndef CALCULATESF_H_
#define CALCULATESF_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"

#include "TopCorrections/ScaleFactorRetriever.h"
#include "ttHMultilepton/Variables.h"

#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"

  class CalculateSF : public top::EventSelectorBase {
public:
    explicit CalculateSF(const std::string& params, std::shared_ptr<top::TopConfig> config);
    ~CalculateSF();
    bool apply(const top::Event& event) const override;
	std::string name() const override;
    bool applyParticleLevel(const top::ParticleLevelEvent& event) const override;
     ///Scale factors
     std::unique_ptr<top::ScaleFactorRetriever> m_sfRetriever;

	ttHMLAsgHelper* m_asgHelper;
	bool m_isRemote;
    struct scaleFactors {
      float lepSFIDLoose[MAXSYST];
      float lepSFIDTight[MAXSYST];
      float lepSFIsoLoose[MAXSYST];
      float lepSFIsoTight[MAXSYST];
      float lepSFReco[MAXSYST];
      float lepSFTTVA[MAXSYST];
      float lepSFTrigLoose[MAXSYST];
      float lepSFTrigTight[MAXSYST];
      float lepSFObjLoose[MAXSYST];
      float lepSFObjTight[MAXSYST];
	  float tauSFLoose[MAXSYST];
	  float tauSFTight[MAXSYST];
    };

//	void doEventSFs_Helper(std::shared_ptr<ttHML::Variables> tthevt, int ilep, bool tightIsLoose) const; 	
private:
	std::shared_ptr<top::TopConfig> m_config;
	mutable const top::Event* m_event;
	std::string m_params;

	mutable scaleFactors m_SF;
 	void doEventSFs_Helper(const xAOD::Electron_v1& el, bool tightIsLoose, std::map<top::topSFSyst, std::string> m_lep_sf_names) const;
	void doEventSFs_Helper(const xAOD::Muon_v1& mu, bool tightIsLoose, std::map<top::topSFSyst, std::string> m_lep_sf_names) const;
};

#endif

