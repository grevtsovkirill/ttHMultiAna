#!/bin/sh
echo "Setting up all the things..."
echo "This must be run in the Base directory of ttHMultiAna. ie. GFW1/source/ttHMultiAna"

setupATLAS

#Setting up AnalysisTop release in source directory and copying patched packages
cd ../
asetup AnalysisTop,21.2.36,here

#Patching MuonEfficiencyCorrections
echo "Patching MuonEfficiencyCorrections..."
cp -r /cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisTop/21.2.36/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/MuonID/MuonIDAnalysis/MuonEfficiencyCorrections/ ./
cd MuonEfficiencyCorrections/Root/
patch < ../../ttHMultiAna/patches/MuonEfficiencyCorrections/patch_MuonTriggerScaleFactors_cxx.diff
cd ../MuonEfficiencyCorrections/
patch < ../../ttHMultiAna/patches/MuonEfficiencyCorrections/patch_MuonTriggerScaleFactors_h.diff
cd ../../

#Patching TopCPTools
echo "Patching TopCPTools..."
cp -r  /cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisTop/21.2.36/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/TopPhys/xAOD/TopCPTools ./
cd TopCPTools/Root/
patch < ../../ttHMultiAna/patches/TopCPTools/patch_TopEgammaCPTools_cxx.diff
patch < ../../ttHMultiAna/patches/TopCPTools/patch_TopMuonCPTools_cxx.diff
patch < ../../ttHMultiAna/patches/TopCPTools/patch_TopFlavorTaggingCPTools_cxx.diff
cd ../TopCPTools/
patch < ../../ttHMultiAna/patches/TopCPTools/patch_TopEgammaCPTools_h.diff
cd ../../

cd ttHMultiAna/share

#Uncommenting the PromptLepton Option in config files
for period in data mc16a mc16c mc16d mc16e AFIImc16a AFIImc16c AFIImc16d AFIImc16e systmc16a systmc16c systmc16d systmc16e
do
	sed "s/#ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLepton/" generic_config_$period.txt > generic_config_temp.txt
	mv generic_config_temp.txt generic_config_$period.txt
	sed "s/#MuonIsolationLoose PromptLepton/MuonIsolationLoose PromptLepton/" generic_config_$period.txt > generic_config_temp.txt
	mv generic_config_temp.txt generic_config_$period.txt
done


for dsid in 345674 345673 345672 410470 410472 410155 410218 410219 410220 345875 345874 345873 
do
    sed 's|#JetUncertainties_QGFracFile ttHMultiAna/FlavourComposition.root|JetUncertainties_QGFracFile $WorkDir_DIR/data/ttHMultilepton/data/'$dsid'_preselections_FlavourComposition.root|g' generic_config_systmc16a.txt > generic_config_systmc16a_$dsid.txt
    sed 's|#JetUncertainties_QGFracFile ttHMultiAna/FlavourComposition.root|JetUncertainties_QGFracFile $WorkDir_DIR/data/ttHMultilepton/data/'$dsid'_preselections_FlavourComposition.root|g' generic_config_systmc16d.txt > generic_config_systmc16d_$dsid.txt
    sed 's|#JetUncertainties_QGFracFile ttHMultiAna/FlavourComposition.root|JetUncertainties_QGFracFile $WorkDir_DIR/data/ttHMultilepton/data/'$dsid'_preselections_FlavourComposition.root|g' generic_config_systmc16e.txt > generic_config_systmc16e_$dsid.txt
done

for dsid in 345674 345673 345672
do
sed 's|#JetUncertainties_QGFracFile ttHMultiAna/FlavourComposition.root|JetUncertainties_QGFracFile $WorkDir_DIR/data/ttHMultilepton/data/'$dsid'_preselections_FlavourComposition.root|g' generic_config_systmc16c.txt > generic_config_systmc16c_$dsid.txt
done

cd ..
echo "Done. You must rebuild the code now."
