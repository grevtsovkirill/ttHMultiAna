
#ifndef _EVENT_H_
#define _EVENT_H_

#include "TopEventSelectionTools/TreeManager.h"
#include "HowtoExtendAnalysisTop/EventData.h"
#include <vector>
#include <memory>


namespace ttHML {
  struct Event {
public:
Event();
virtual ~Event();
    int onelep_type;
    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, bool doSFSystematics);
    std::shared_ptr<ttHML::EventData> m_info;
};

}

#endif

