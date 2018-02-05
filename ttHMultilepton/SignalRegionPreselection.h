#ifndef SIGNALREGIONPRESELECTION_H_
#define SIGNALREGIONPRESELECTION_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"

#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"

#include "ttHMultilepton/Variables.h"
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"


 //To apply a preselection based on which SR are needed. Used to reduce ntuple size in systematic runs
  class SignalRegionPreselection : public top::EventSelectorBase {
public:
    explicit SignalRegionPreselection(const std::string& params, std::shared_ptr<top::TopConfig> config);

    bool apply(const top::Event& event) const override;
	std::string name() const override;
    bool applyParticleLevel(const top::ParticleLevelEvent& event) const override;
	ttHMLAsgHelper* m_asgHelper;
	
private:
	std::shared_ptr<top::TopConfig> m_config;
	mutable const top::Event* m_event;
	std::string m_params;
};


#endif

