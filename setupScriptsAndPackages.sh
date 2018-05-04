#!/bin/sh
echo "Setting up all the things..."
echo "This must be run in the Base directory of ttHMultiAna. ie. GFW1/source/ttHMultiAna"

setupATLAS

#Setting up AnalysisTop release in source directory and copying patched packages
cd ../
asetup AnalysisTop,21.2.26,here
cp -r /eos/user/a/acasha/TTHML/TopCPTools/ ./

cd ttHMultiAna/share

#Uncommenting the PromptLepton Option in config files
for period in data mc16a mc16c mc16d systmc16a systmc16c systmc16d
do
	sed "s/#ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLepton/" generic_config_$period.txt > generic_config_temp.txt
	mv generic_config_temp.txt generic_config_$period.txt
	sed "s/#MuonIsolationLoose PromptLepton/MuonIsolationLoose PromptLepton/" generic_config_$period.txt > generic_config_temp.txt
	mv generic_config_temp.txt generic_config_$period.txt
done


for dsid in 345674 345673 345672 410470 410472 410155 410218 410219 410220
do
    sed 's|#JetUncertainties_QGFracFile ttHMultiAna/FlavourComposition.root|JetUncertainties_QGFracFile $WorkDir_DIR/data/ttHMultilepton/data/'$dsid'_preselections_FlavourComposition.root|g' generic_config_systmc16a.txt > generic_config_systmc16a_$dsid.txt
    sed 's|#JetUncertainties_QGFracFile ttHMultiAna/FlavourComposition.root|JetUncertainties_QGFracFile $WorkDir_DIR/data/ttHMultilepton/data/'$dsid'_preselections_FlavourComposition.root|g' generic_config_systmc16d.txt > generic_config_systmc16d_$dsid.txt
done


cd ..
echo "Done. You must rebuild the code now."