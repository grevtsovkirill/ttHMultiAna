#ifndef COUNTHISTO_H_
#define COUNTHISTO_H_

#include "TopEventSelectionTools/EventSelectorBase.h"
#include "TopEventSelectionTools/PlotManager.h"

class TFile;

namespace EL {
  class Worker;
}

/**
 * @brief Create HWW style Count histogram
 */
class CountHisto : public top::EventSelectorBase {
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
    CountHisto(const std::string& name, TFile* outputFile, EL::Worker* wk = nullptr);

    /**
     * @brief Fill the histograms.
     *
     * @return True because it doesn't select any events.
     */
    virtual bool apply(const top::Event& event) const override;

    /**
     * @brief Return the name for the cutflow table.
     *
     * @return The word COUNTHISTO.
     */
    std::string name() const override;

  private:

    ///Easy access to histograms.
    top::PlotManager m_hists;

    // Nominal hash value
    std::size_t m_nominalHashValue;
};

#endif

