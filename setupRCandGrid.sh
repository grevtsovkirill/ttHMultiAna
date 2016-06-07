#! /bin/sh
echo "Setting up all the things"

lsetup "rcsetup Top,2.4.6" panda rucio pyami
#lsetup knows in which order to do these

rc checkout_pkg atlasoff/PhysicsAnalysis/AnalysisCommon/PMGTools/trunk
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopAnalysis/tags/TopAnalysis-00-04-36
rc build

echo "Alright - done."
