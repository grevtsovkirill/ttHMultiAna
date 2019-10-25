#!/bin/sh
echo "Setting up all the things..."
echo "This must be run in the Base directory of ttHMultiAna. ie. GFW1/source/ttHMultiAna"

#Setting up AnalysisTop release in source directory and copying patched packages
cd ../
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
asetup AnalysisTop,21.2.96,here

#Patching MuonEfficiencyCorrections
echo "Patching ElectronPhotonSelectorTool..."
cp -r /cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisTop/21.2.75/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/ElectronPhotonID/ElectronPhotonSelectorTools/ ./
cd ElectronPhotonSelectorTools/Root/
patch < ../../ttHMultiAna/patches/ElectronPhotonSelectorTools/patch_AsgElectronChargeIDSelectorTool_cxx.diff
cd ../ElectronPhotonSelectorTools/
patch < ../../ttHMultiAna/patches/ElectronPhotonSelectorTools/patch_AsgElectronChargeIDSelectorTool_h.diff
cd ../../

#Patching TopCPTools
#echo "Patching TopCPTools..."
#cp -r  /cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisTop/21.2.75/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/TopPhys/xAOD/TopCPTools ./
#cd TopCPTools/Root/
#patch < ../../ttHMultiAna/patches/TopCPTools/patch_TopEgammaCPTools_cxx.diff
#cd ../TopCPTools/
#patch < ../../ttHMultiAna/patches/TopCPTools/patch_TopEgammaCPTools_h.diff
#cd ../../

#cd ttHMultiAna/share

#Uncommenting the PromptLepton Option in config files
#for period in data mc16a mc16c mc16d mc16e AFIImc16a AFIImc16c AFIImc16d AFIImc16e systmc16a systmc16c systmc16d systmc16e
#do
#	sed "s/#ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLepton/" generic_config_$period.txt > generic_config_temp.txt
#	mv generic_config_temp.txt generic_config_$period.txt
	#sed "s/#MuonIsolationLoose PromptLepton/MuonIsolationLoose PromptLepton/" generic_config_$period.txt > generic_config_temp.txt
	#mv generic_config_temp.txt generic_config_$period.txt
#done
#cd ..
#echo "Done. You must rebuild the code now."

