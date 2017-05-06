#ifndef REMOVEOSDILEPNOTAUSELECTOR_H_
#define REMOVEOSDILEPNOTAUSELECTOR_H_

//Your tool must inherit from this
#include "TopEventSelectionTools/EventSelectorBase.h"

class RemoveOSDilepNoTauSelector : public top::EventSelectorBase {
  public:
    //This function sees every event.  If you return true then the event passes this "cut"
    bool apply(const top::Event& event) const override;
    std::string name() const override;
};

#endif
