#ifndef TTHMULTILEPTONLOOSEOBJECTLOADER_H_
#define TTHMULTILEPTONLOOSEOBJECTLOADER_H_

#include "TopAnalysis/ObjectLoaderBase.h"

/*** A class that can be loaded by name at run time and creates our object selection*/
class ttHMultileptonLooseObjectLoader : public top::ObjectLoaderBase {
 public:
  //A method that creates a pointer to a TopObjectSelection tool which contains info on which cuts to enable and configure
  //top::TopObjectSelection* init(top::TopConfig* topConfig);
    top::TopObjectSelection* init(std::shared_ptr<top::TopConfig> topConfig);
  //Clever root stuff
    ClassDef(ttHMultileptonLooseObjectLoader, 0)
};

#endif
