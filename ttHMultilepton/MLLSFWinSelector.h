#ifndef MLLSFWINSELECTOR_H_
#define MLLSFWINSELECTOR_H_

//Your tool must inherit from this
#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopEvent/EventTools.h"

/*** This is a tool that selects only even numbered events.  But you could do something even cooler.*/
class MLLSFWinSelector : public top::EventSelectorBase {
 public:
  //This function sees every event.  If you return true then the event passes this "cut"
    bool apply(const top::Event& event) const override;
    
    //For humans, something short and catchy
    std::string name() const override;
};

#endif
