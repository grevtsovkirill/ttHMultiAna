/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration


#ifndef HOWTOEXTENDANALYSISTOP_EVENEVENTNUMBERSELECTOR_H
#define HOWTOEXTENDANALYSISTOP_EVENEVENTNUMBERSELECTOR_H

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopEvent/Event.h"

namespace top{
  
  /**
  * This is a tool that selects only even numbered events.  But you could do something even cooler.
  
  class EvenEventNumberSelector : public top::EventSelectorBase {
    public:
      //This function sees every event.  If you return true then the event passes this "cut"
      bool apply(const top::Event& event) const override;

      //For humans, something short and catchy
      std::string name() const override;
  };  
  
}

//#endif
*/
#ifndef EvenEventNumberSelector_H_
#define EvenEventNumberSelector_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopConfiguration/TopConfig.h"
#include "TopEvent/Event.h"
#include "HowtoExtendAnalysisTop/Event.h"
#include "HowtoExtendAnalysisTop/EventData.h"

class EvenEventNumberSelector:public top::EventSelectorBase {

 public:

  EvenEventNumberSelector(std::string params, std::shared_ptr<top::TopConfig> config);
  ~EvenEventNumberSelector();
  // void initialise(const top::Event& event) const;
  bool apply(const top::Event & event) const override;
  bool applyParticleLevel(const top::ParticleLevelEvent & event) const override;
  std::string name() const override;

 private:

  std::shared_ptr<top::TopConfig> m_config;


  std::string m_params;


};

#endif

