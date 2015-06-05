#ifndef TTHMULTILEPTONLOADER
#define TTHMULTILEPTONLOADER

#include "TopEventSelectionTools/ToolLoaderBase.h"

/*** This class is loaded by top-xaod when it starts.  Actually what it does is look for a class
   * that matches the name of the package with the word Loader added on to the end.  If it
    * doesn't find one, it doesn't care.
   */
   class ttHMultileptonLoader : public top::ToolLoaderBase {
   public:
       //This is a factory for making tools that exist in your package.
     top::EventSelectorBase* initTool(const std::string& name, const std::string& line, TFile* outputFile, std::shared_ptr<top::TopConfig> config, EL::Worker* wk = nullptr);
   
       //Magic root stuff
       ClassDef(ttHMultileptonLoader, 0)
   };
   
   #endif
