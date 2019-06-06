#!/bin/sh
echo "Setting up all the things..."
echo "This must be run in the Base directory of ttHMultiAna. ie. GFW1/source/ttHMultiAna"

#Setting up AnalysisTop release in source directory and copying patched packages
cd ../
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
asetup AnalysisTop,21.2.75,here

#Patching MuonEfficiencyCorrections
echo "Copying old ElectronPhotonSelectorTool..."
cp -r /cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisTop/21.2.36/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/ElectronPhotonID/ElectronPhotonSelectorTools/ ./

cd ../build

echo "Done. You must rebuild the code now."
