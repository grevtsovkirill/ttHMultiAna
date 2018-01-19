
#ifndef ttHMLCreateEvent_H_
#define ttHMLCreateEvent_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "TopEvent/Event.h"
#include "ttHMultilepton/Variables.h"
#include "ttHMultilepton/EventData.h"

class ttHMLCreateEvent:public top::EventSelectorBase {

 public:

  ttHMLCreateEvent(std::string params, std::shared_ptr<top::TopConfig> config);
  ~ttHMLCreateEvent();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  bool applyParticleLevel(const top::ParticleLevelEvent & event) const override;
  std::string name() const override;

 private:

  std::shared_ptr<top::TopConfig> m_config;


  std::string m_params;


};

#endif

