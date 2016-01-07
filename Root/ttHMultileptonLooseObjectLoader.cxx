#include "ttHMultilepton/ttHMultileptonLooseObjectLoader.h"

//So we can read stuff from the configuration text file at run time
#include "TopConfiguration/TopConfig.h"

//We need this to do our magic
#include "TopObjectSelectionTools/TopObjectSelection.h"

// for top::check
#include "TopEvent/EventTools.h"

//We'll need these so we can apply some cuts
#include "TopObjectSelectionTools/ElectronLikelihoodMC15.h"
#include "TopObjectSelectionTools/ElectronCutBasedMC15.h"
#include "TopObjectSelectionTools/IsolationTools.h"
#include "TopObjectSelectionTools/MuonMC15.h"
#include "TopObjectSelectionTools/JetMC15.h"
#include "TopObjectSelectionTools/TauMC15.h"
#include "ttHMultilepton/DummyOverlapRemoval.h"
#include "TopObjectSelectionTools/OverlapRemovalASG.h"

//Run once at the start of the program to setup our object selection (and overlap removal)
//top::TopObjectSelection* ttHMultileptonLooseObjectLoader::init(top::TopConfig* topConfig) {
top::TopObjectSelection* ttHMultileptonLooseObjectLoader::init(std::shared_ptr<top::TopConfig> topConfig) { 
  //create our new object
  top::TopObjectSelection* objectSelection = new top::TopObjectSelection(topConfig->objectSelectionName());
  top::check(objectSelection->setProperty( "config" , topConfig ) , "Failed to setProperty for top::TopObjectSelection" );
  top::check(objectSelection->initialize() , "Failed to initialize top::TopObjectSelection" ); 
 
  //configure the electrons, muons, jets, large-R jets
  if (topConfig->electronID().find("LH") == std::string::npos && topConfig->electronIDLoose().find("LH") == std::string::npos) {
    //both the tight and loose user settings do not contain LH -> cut based
    objectSelection->electronSelection(new top::ElectronCutBasedMC15(topConfig->electronPtcut(), false, topConfig->electronID(), topConfig->electronIDLoose(), new top::StandardIsolation()));
  } else if (topConfig->electronID().find("LH") != std::string::npos && topConfig->electronIDLoose().find("LH") != std::string::npos) {
    //user wants likelihood electrons
    auto electronSelection = new top::ElectronLikelihoodMC15(topConfig->isPrimaryxAOD(),
							     topConfig->electronPtcut(), 
							     topConfig->electronVetoLArCrack(), 
							     topConfig->electronID(), 
							     topConfig->electronIDLoose(), 
							     nullptr );
    objectSelection->electronSelection( electronSelection );
  } else {
    std::cout << "\nHo hum\n";
    std::cout << "Not sure it makes sense to use a mix of LH and cut-based electrons for the tight/loose definitions\n";
    std::cout << "Tight electron definition is " << topConfig->electronID() << "\n";
    std::cout << "Loose electron definition is " << topConfig->electronIDLoose() << "\n";
    std::cout << "If it does make sense, feel free to fix this\n";
    exit(1);
  }
  
  objectSelection->muonSelection(new top::MuonMC15(topConfig->muonPtcut(), nullptr)); 
  objectSelection->jetSelection(new top::JetMC15(topConfig->jetPtcut(), topConfig->jetEtacut(), 0.));

  objectSelection->tauSelection( new top::TauMC15() );
  
  //and the overlap removal
  //objectSelection->overlapRemovalPreSelection();
  objectSelection->overlapRemovalPostSelection(new DummyOverlapRemoval());
  //objectSelection->overlapRemovalPostSelection(new top::OverlapRemovalASG());
 
  //hand it back to the program
  return objectSelection;
}
