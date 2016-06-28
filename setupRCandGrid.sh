#! /bin/sh
echo "Setting up all the things"

lsetup "rcsetup Top,2.4.12" panda rucio pyami
#lsetup knows in which order to do these

rc checkout_pkg atlasoff/PhysicsAnalysis/AnalysisCommon/PMGTools/tags/PMGTools-00-00-01
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopAnalysis/tags/TopAnalysis-00-04-47
rc checkout_pkg atlasoff/PhysicsAnalysis/ElectronPhotonID/ElectronEfficiencyCorrection/tags/ElectronEfficiencyCorrection-00-01-62
rc checkout_pkg atlasoff/PhysicsAnalysis/ElectronPhotonID/ElectronPhotonFourMomentumCorrection/tags/ElectronPhotonFourMomentumCorrection-00-02-11
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/TopPhysUtils/TopDataPreparation/trunk
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopSystematicObjectMaker/tags/TopSystematicObjectMaker-00-03-58
rc checkout_pkg atlasoff/PhysicsAnalysis/MuonID/MuonSelectorTools/tags/MuonSelectorTools-00-05-32
rc checkout_pkg atlasoff/PhysicsAnalysis/MuonID/MuonIDAnalysis/MuonEfficiencyCorrections/tags/MuonEfficiencyCorrections-03-03-05
rc checkout_pkg atlasoff/PhysicsAnalysis/TauID/TauAnalysisTools/tags/TauAnalysisTools-00-02-14
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopCPTools/tags/TopCPTools-00-00-99
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopCorrections/tags/TopCorrections-00-00-85

# change line 30/31 in TopCPTools/Root/TopFlavorTaggingCPTools.cxx to
#   m_cdi_file = "xAODBTaggingEfficiency/13TeV/2016-20_7-13TeV-MC15-CDI-June27_v1.root ";
#   m_efficiency_maps = "410000;410004;410006;410187";

rc build

echo "Alright - done."

# When compiling with TauAnalysisTools-00-02-14
#/atlas/wolff/ATLAS/TtHToMultileptons/ttHMultiAna/devbranches/rwolff5/TopSystematicObjectMaker/Root/TauObjectCollectionMaker.cxx: In member function ‘StatusCode top::TauObjectCollectionMaker::execute()’:
#/atlas/wolff/ATLAS/TtHToMultileptons/ttHMultiAna/devbranches/rwolff5/TopSystematicObjectMaker/Root/TauObjectCollectionMaker.cxx:70:56: warning: ‘virtual StatusCode TauAnalysisTools::ITauTruthMatchingTool::initializeEvent()’ is deprecated (declared at /atlas/wolff/ATLAS/TtHToMultileptons/ttHMultiAna/devbranches/rwolff5/RootCoreBin/include/TauAnalysisTools/ITauTruthMatchingTool.h:56): This function is deprecated. Please remove it from your code.
#For further information please refer to the README:
#https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/TauID/TauAnalysisTools/trunk/doc/README-TauTruthMatchingTool.rst [-Wdeprecated-declarations]
#       top::check( m_truthMatchingTool->initializeEvent(), "Failed to initialseEvent of TauTruthMatchTool." );
