#! /bin/sh
echo "Setting up all the things"

lsetup "rcsetup Top,2.4.13" panda rucio pyami
#lsetup knows in which order to do these

rc checkout_pkg atlasoff/PhysicsAnalysis/AnalysisCommon/PMGTools/tags/PMGTools-00-00-01
rc checkout_pkg atlasoff/PhysicsAnalysis/ElectronPhotonID/ElectronEfficiencyCorrection/tags/ElectronEfficiencyCorrection-00-01-62
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/TopPhysUtils/TopDataPreparation/trunk
rc checkout_pkg atlasoff/PhysicsAnalysis/TauID/TauAnalysisTools/tags/TauAnalysisTools-00-02-14

rc build

echo "Alright - done."


