#include "ttHMultilepton/ttHMultileptonObjectLoader.h"

//So we can read stuff from the configuration text file at run time
#include "TopConfiguration/TopConfig.h"

// for top::check
#include "TopEvent/EventTools.h"

//We need this to do our magic
#include "TopObjectSelectionTools/TopObjectSelection.h"

//We'll need these so we can apply some cuts
#include "TopObjectSelectionTools/ElectronLikelihoodDC14.h"
#include "TopObjectSelectionTools/ElectronCutBasedDC14.h"
#include "TopObjectSelectionTools/IsolationTools.h"
#include "TopObjectSelectionTools/MuonDC14.h"
#include "TopObjectSelectionTools/JetDC14.h"
#include "TopObjectSelectionTools/TauDC14.h"
#include "TopObjectSelectionTools/OverlapRemovalASG.h"

//Run once at the start of the program to setup our object selection (and overlap removal)
//top::TopObjectSelection* ttHMultileptonObjectLoader::init(top::TopConfig* topConfig) {
top::TopObjectSelection* ttHMultileptonObjectLoader::init(std::shared_ptr<top::TopConfig> topConfig) {
  //create our new object
  top::TopObjectSelection* objectSelection = new top::TopObjectSelection(topConfig->objectSelectionName());
  top::check(objectSelection->setProperty( "config" , topConfig ) , "Failed to setProperty for top::TopObjectSelection" );
  top::check(objectSelection->initialize() , "Failed to initialize top::TopObjectSelection" );
  
  //configure the electrons, muons, jets, large-R jets
  //objectSelection->electronSelection(new top::ElectronTightIsoDC14(topConfig->electronPtcut(), topConfig->electronVetoLArCrack(), topConfig->electronID(), topConfig->electronIDBkg()));
  if (topConfig->electronID().find("LH") == std::string::npos && topConfig->electronIDLoose().find("LH") == std::string::npos) {
    //both the tight and loose user settings do not contain LH -> cut based
    objectSelection->electronSelection(new top::ElectronCutBasedDC14(topConfig->electronPtcut(), topConfig->electronVetoLArCrack(), topConfig->electronID(), topConfig->electronIDLoose(), new top::StandardIsolation()));
  } else if (topConfig->electronID().find("LH") == 0 && topConfig->electronIDLoose().find("LH") == 0) {
    //user wants likelihood electrons
    LikeEnum::Menu operatingPoint = top::ElectronLikelihoodDC14::textToEgammaEnum(topConfig->electronID());
    LikeEnum::Menu operatingPointLoose = top::ElectronLikelihoodDC14::textToEgammaEnum(topConfig->electronIDLoose());
    objectSelection->electronSelection(new top::ElectronLikelihoodDC14(topConfig->electronPtcut(), topConfig->electronVetoLArCrack(), operatingPoint, operatingPointLoose, new top::StandardIsolation()));
  } else {
    std::cout << "\nHo hum\n";
    std::cout << "Not sure it makes sense to use a mix of LH and cut-based electrons for the tight/loose definitions\n";
    std::cout << "Tight electron definition is " << topConfig->electronID() << "\n";
    std::cout << "Loose electron definition is " << topConfig->electronIDLoose() << "\n";
    std::cout << "If it does make sense, feel free to fix this\n";
    exit(1);
  }

  objectSelection->muonSelection(new top::MuonDC14(10000., 2.5, nullptr)); //new top::ApproxPTVarCone(0.05, 0.)));
  objectSelection->jetSelection(new top::JetDC14(25000., 2.5, 0.5));
  objectSelection->tauSelection(new top::TauDC14(10000., false, TauAnalysisTools::JETID::JETIDBDTMEDIUM, TauAnalysisTools::JETID::JETIDNONE, TauAnalysisTools::ELEID::ELEIDBDTMEDIUM));
  
  //objectSelection->overlapRemovalPreSelection(nullptr);
  objectSelection->overlapRemovalPostSelection(new top::OverlapRemovalASG());
  
  //hand it back to the program
  return objectSelection;
}
