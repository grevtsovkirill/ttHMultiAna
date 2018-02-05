

#include "ttHMultilepton/ttHMLAsgHelper.h"
#include "ttHMultilepton/Variables.h"
#include "TopEvent/EventTools.h"
#include "xAODTracking/TrackParticle.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>

ttHMLAsgHelper::ttHMLAsgHelper(std::string name):
  asg::AsgTool(name)
 {
 
}

ttHMLAsgHelper::~ttHMLAsgHelper(){

}



const xAOD::TauJetContainer*  ttHMLAsgHelper::RetrieveTaus(std::string retname)const{
  const xAOD::TauJetContainer* fj(nullptr);
  top::check(evtStore()->retrieve(fj,retname),"Failed to retrieve Taus");
  return fj;
}

const xAOD::MuonContainer*  ttHMLAsgHelper::RetrieveMuons(std::string retname)const{
  const xAOD::MuonContainer* fj(nullptr);
  top::check(evtStore()->retrieve(fj,retname),"Failed to retrieve Muons ");
  return fj;
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
    
	if( jet->auxdataConst<char>("passJVT")==0 ){ continue;}
    /*if (jet->pt() < 60e3
      && fabs(jet->getAttribute<float>("DetectorEta")) < 2.4)
      continue;
    if (jet->isAvailable<float>("AnalysisTop_JVT")) {
      if(jet->auxdataConst<float>("AnalysisTop_JVT") < 0.59)
      continue;
    }*/

  selected_jets->push_back(jet);
  }
  std::sort (selected_jets->begin(), selected_jets->end(), ttHMLAsgHelper::pt_sort());
 // if(!top::check(evtStore()->record(selected_jets, "SelectedJets").isSuccess()) std::cout << "Could not record Selected Jets" << std::endl;
 // top::check(evtStore()->record(selected_jets.release(), "SelectedJets"),"Could not record Selected Jets");
  top::check(evtStore()->record(selected_jets, "SelectedJets"),"Could not record Selected Jets");

}


const xAOD::ElectronContainer*  ttHMLAsgHelper::RetrieveElectrons(std::string retname)const{
  const xAOD::ElectronContainer* fj(nullptr);
  top::check(evtStore()->retrieve(fj,retname),"Failed to retrieve Electrons ");
  return fj;
}
void ttHMLAsgHelper::getElectronContainer(std::string name) {
  //const xAOD::JetContainer* selected_jets(nullptr);
  std::cout<<name<<std::endl;
  const xAOD::ElectronContainer* electrons(nullptr);
  top::check(evtStore()->retrieve(electrons,name),"Failed to retrieve Jets");
  std::cout<<electrons->size()<<std::endl;
  ConstDataVector<xAOD::ElectronContainer> * selected_electrons   =  new ConstDataVector<xAOD::ElectronContainer>(SG::VIEW_ELEMENTS);
  for(const auto elItr :*electrons){
    if(elItr->pt() < 10e3){
    continue;
    }
    auto abseta = fabs(elItr->caloCluster()->etaBE(2));
    if(!(abseta < 1.37 || (1.52 < abseta && abseta < 2.47))){
    continue;
    }
    if (!elItr->auxdataConst<int>("passLHLoose")){
    continue;
    }
    if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
    if (fabs(elItr->auxdataConst<float>("d0sig")) > 10) {
      continue;
    }

  selected_electrons->push_back(elItr);
  }
  std::sort (selected_electrons->begin(), selected_electrons->end(), ttHMLAsgHelper::pt_sort());
 // if(!top::check(evtStore()->record(selected_jets, "SelectedJets").isSuccess()) std::cout << "Could not record Selected Jets" << std::endl;
 // top::check(evtStore()->record(selected_jets.release(), "SelectedJets"),"Could not record Selected Jets");
  top::check(evtStore()->record(selected_electrons, "SelectedElectrons"),"Could not record Selected Electrons");

}
