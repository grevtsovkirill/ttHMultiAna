
#include "HowtoExtendAnalysisTop/Event.h"
#include "boost/format.hpp"
using boost::format;

namespace ttHML{

Event::Event(){
}
Event::~Event(){
}


void Event::BootstrapTree(std::shared_ptr<top::TreeManager> tree, bool doSFSystematics){
  tree->makeOutputVariable(onelep_type,   "onelep_type");
}


//void Event::clear(){
//}

}

