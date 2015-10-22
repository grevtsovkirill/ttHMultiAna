#ifndef DUPLICATESELECTOR_H_
#define DUPLICATESELECTOR_H_

#include "TopEventSelectionTools/EventSelectorBase.h"

#include <set>

/**
 * @brief Create HWW style Count histogram
 */
class DuplicateSelector : public top::EventSelectorBase {
public:
    /**
     * @brief Setup some example plots.
     *
     * Add a bunch of histograms.
     *
     * @param name The name of the directory to store histograms in, in the
     * output file.  e.g. you might have ee, mumu and emu.
     * @param outputFile The output file. Needs setting up at the very start
     * so that we can attach the files.
     * @param wk Only used by EventLoop, ok as nullptr as default.
     */
  DuplicateSelector();

    /**
     * @brief Fill the histograms.
     *
     * @return True because it doesn't select any events.
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
    mutable std::set<std::pair<int, int> > m_processedEvents;
  
    // Nominal hash value
    std::size_t m_nominalHashValue;
};

#endif
