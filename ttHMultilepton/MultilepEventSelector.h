#ifndef MULTILEPEVENTSELECTOR_H_
#define MULTILEPEVENTSELECTOR_H_

//Your tool must inherit from this
#include "TopEventSelectionTools/EventSelectorBase.h"
//#include "TopEvent/EventTools.h"

class MultilepEventSelector : public top::EventSelectorBase {
 public:
  //This function sees every event.  If you return true then the event passes this "cut"
    bool apply(const top::Event& event) const override;
    
    //For humans, something short and catchy
    std::string name() const override;
};

#endif
