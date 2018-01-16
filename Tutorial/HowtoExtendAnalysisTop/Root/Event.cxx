
#include "HowtoExtendAnalysisTop/Event.h"
#include "boost/format.hpp"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"
#include "TopEvent/EventTools.h"

#include "xAODJet/JetContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTruth/xAODTruthHelpers.h"

using boost::format;

namespace ttHML{

Event::Event():
    asg::AsgTool("temp")
  {
  /*Event::GetJetContainer("AntiKt4EMTopoJets");
  Event::GetElectronContainer("Electrons");
  Event::GetMuonContainer("Muons");
  Event::GetTauContainer("TauJets");*/

  ConstDataVector<xAOD::JetContainer> * selected_jets   =  new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
  ConstDataVector<xAOD::ElectronContainer> * selected_electrons = new ConstDataVector<xAOD::ElectronContainer>(SG::VIEW_ELEMENTS);
  ConstDataVector<xAOD::MuonContainer> * selected_muons = new ConstDataVector<xAOD::MuonContainer>(SG::VIEW_ELEMENTS);
  ConstDataVector<xAOD::TauJetContainer> * selected_taus = new ConstDataVector<xAOD::TauJetContainer>(SG::VIEW_ELEMENTS); 

}

Event::~Event(){
}
/*
void Event::GetJetContainer(std::string name = "Jets"){
  const xAOD::JetContainer* jets(nullptr);
  top::check(evtStore()->retrieve(jets,name),"Failed to retrieve Jets");
  std::cout<<"Jet Size: " << jets->size()<<std::endl;
  ConstDataVector<xAOD::JetContainer> * selected_jets   =  new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
  for(const auto jet :*jets){
    if(jet->pt() < 25e3){ continue;}
    if(fabs(jet->eta()) > 2.5){ continue;}
    if (jet->pt() < 60e3 && fabs(jet->getAttribute<float>("DetectorEta")) < 2.4) {continue;}
    if (jet->isAvailable<float>("AnalysisTop_JVT")) {
      if(jet->auxdataConst<float>("AnalysisTop_JVT") < 0.59) continue;}
    selected_jets->push_back(jet);
  }
  std::sort (selected_jets->begin(), selected_jets->end(), ttHMLAsgHelper::pt_sort());
  top::check(evtStore()->record(selected_jets, "SelectedJets"),"Could not record Selected Jets");
}


void Event::GetElectronContainer(std::string name = "Electrons"){
  const xAOD::ElectronContainer* electrons(nullptr);
  top::check(evtStore()->retrieve(electrons,name), "Failed to retrieve Electrons");
  std::cout<<"Electrons Size: " << electrons->size()<<std::endl;
  ConstDataVector<xAOD::ElectronContainer> * selected_electrons = new ConstDataVector<xAOD::ElectronContainer>(SG::VIEW_ELEMENTS);
  for(const auto elItr :*electrons){
    //Need to put a basic electron selection here, not working at the moment, see ttHMLAsgHelper
    selected_electrons->push_back(elItr);
  }
  std::sort (selected_electrons->begin(), selected_electrons->end(), ttHMLAsgHelper::pt_sort());
  top::check(evtStore()->record(selected_electrons, "SelectedElectrons"), "Could not record Selected Electrons");
}


void Event::GetMuonContainer(std::string name = "Muons"){
  const xAOD::MuonContainer* muons(nullptr);
  top::check(evtStore()->retrieve(muons,name), "Failed to retrieve Muons");
  std::cout<<"Muons Size: " << muons->size()<<std::endl;
  ConstDataVector<xAOD::MuonContainer> * selected_muons = new ConstDataVector<xAOD::MuonContainer>(SG::VIEW_ELEMENTS);
  for(const auto muItr :*muons){
    //Need to put a basic muon selection here
    selected_muons->push_back(muItr);
  }
  std::sort (selected_muons->begin(), selected_muons->end(), ttHMLAsgHelper::pt_sort());
  top::check(evtStore()->record(selected_muons, "SelectedMuons"), "Could not record Selected Muons");
}

void Event::GetTauContainer(std::string name = "TauJets"){
  const xAOD::TauJetContainer* taus(nullptr);
  top::check(evtStore()->retrieve(taus,name), "Failed to retrieve Taus");
  std::cout<<"Taus Size: " << taus->size()<<std::endl;
  ConstDataVector<xAOD::TauJetContainer> * selected_taus = new ConstDataVector<xAOD::TauJetContainer>(SG::VIEW_ELEMENTS);
  for(const auto tauItr :*taus){
    //Need to put a basic tau selection here
    selected_taus->push_back(tauItr);
  }
  std::sort (selected_taus->begin(), selected_taus->end(), ttHMLAsgHelper::pt_sort());
  top::check(evtStore()->record(selected_taus, "SelectedTaus"), "Could not record Selected Taus");
*/




void Event::BootstrapTree(std::shared_ptr<top::TreeManager> tree, bool doSFSystematics){
  tree->makeOutputVariable(onelep_type,   "onelep_type");
}


//void Event::clear(){
//}

}

