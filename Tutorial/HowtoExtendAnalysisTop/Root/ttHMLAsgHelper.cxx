

#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"
#include "HowtoExtendAnalysisTop/Event.h"
#include "TopEvent/EventTools.h"
#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>

ttHMLAsgHelper::ttHMLAsgHelper(std::string name):
  asg::AsgTool(name)
 {
 
}

ttHMLAsgHelper::~ttHMLAsgHelper(){

}

//void xAOD::JetContainer* ttHMLAsgHelper::getJetContainer(xAOD::JetContainer* jets) {
const xAOD::JetContainer*  ttHMLAsgHelper::RetrieveJets(std::string retname)const{
  const xAOD::JetContainer* fj(nullptr);
  top::check(evtStore()->retrieve(fj,retname),"Failed to retrieve Jets");
  return fj;
}
//void ttHMLAsgHelper::getJetContainer(xAOD::JetContainer* jets) {
void ttHMLAsgHelper::getJetContainer(std::string name) {
  //const xAOD::JetContainer* selected_jets(nullptr);
std::cout<<name<<std::endl;
  const xAOD::JetContainer* jets(nullptr);
  top::check(evtStore()->retrieve(jets,name),"Failed to retrieve Jets");
std::cout<<jets->size()<<std::endl;
  ConstDataVector<xAOD::JetContainer> * selected_jets   =  new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
  //xAOD::JetContainer * selected_jets = new xAOD::JetContainer;
 // auto selected_jets = std::make_unique<ConstDataVector<xAOD::JetContainer>> (SG::VIEW_ELEMENTS);
  for(const auto jet :*jets){
    if(jet->pt() < 25e3){
    continue;
    }
    if(fabs(jet->eta()) > 2.5){
    continue;
    }
    if (jet->pt() < 60e3
      && fabs(jet->getAttribute<float>("DetectorEta")) < 2.4)
      continue;
    if (jet->isAvailable<float>("AnalysisTop_JVT")) {
      if(jet->auxdataConst<float>("AnalysisTop_JVT") < 0.59)
      continue;
    }

  selected_jets->push_back(jet);
  }
  std::sort (selected_jets->begin(), selected_jets->end(), ttHMLAsgHelper::pt_sort());
 // if(!top::check(evtStore()->record(selected_jets, "SelectedJets").isSuccess()) std::cout << "Could not record Selected Jets" << std::endl;
 // top::check(evtStore()->record(selected_jets.release(), "SelectedJets"),"Could not record Selected Jets");
  top::check(evtStore()->record(selected_jets, "SelectedJets"),"Could not record Selected Jets");

}
