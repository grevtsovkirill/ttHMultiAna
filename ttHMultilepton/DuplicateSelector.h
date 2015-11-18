#ifndef DUPLICATESELECTOR_H_
#define DUPLICATESELECTOR_H_

#include "TopEventSelectionTools/EventSelectorBase.h"

#include <set>

/**
 * @brief keep track of dupes
 */
class DuplicateSelector : public top::EventSelectorBase {
public:

  DuplicateSelector();

    /**
     * @brief Check dupes
     *
     * @return True if event is not dupe
     */
    virtual bool apply(const top::Event& event) const override;

    /**
     * @brief Return the name for the cutflow table.
     *
     * @return The word DUPLICATEVETO.
     */
    std::string name() const override;

private:

    // all processed events
    mutable std::set<std::pair<int, uint64_t> > m_processedEvents;
  
    // Nominal hash value
    std::size_t m_nominalHashValue;
};

#endif
