#include "ttHMultilepton/ttHMultileptonLoader.h"

//Include the header for every one of your tools
#include "ttHMultilepton/MLLSFWinSelector.h"
#include "ttHMultilepton/MultilepEventSelector.h"
#include "ttHMultilepton/CountHisto.h"
#include "ttHMultilepton/DuplicateSelector.h"

/*** This is where the magic happens.  When top-xaod comes across a cut in the configuration file it tries to load it.
 * So if it comes across the word "EVEN" it'll make and return a new EvenNumberSelector object (which
 * you just wrote above).
 */
top::EventSelectorBase* ttHMultileptonLoader::initTool(const std::string& name, const std::string& line, TFile* outputFile, std::shared_ptr<top::TopConfig> /*config*/, EL::Worker* wk) {
  if (line.find("MLLSFWIN") == 0){
    MLLSFWinSelector *mllsf = new MLLSFWinSelector();
    return mllsf;
    //return new MLLSFWinSelector();
  } else if (line.find("TTHMULTILEP") == 0){
    return new MultilepEventSelector();
  }
  else if (line.find("COUNTHISTO") == 0)
    return new CountHisto(name,outputFile,wk);
  else if (line.find("DUPLICATEVETO") == 0)
    return new DuplicateSelector();
  //else if (line.find("OTHER_TOOL") == 0)
  //  return new OtherToolThatYouInvented();
  
  //we need it to fall through at the end in case the tool is in someone else's library (not yours)
  //don't worry the main code checks for a nullptr
  return nullptr;
}
