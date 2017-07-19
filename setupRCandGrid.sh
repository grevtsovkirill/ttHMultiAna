#!/bin/sh
echo "Setting up all the things"

#lsetup knows in which order to do these

lsetup "rcsetup Top,2.4.32" panda rucio pyami
#voms-proxy-init -voms atlas:/atlas/phys-higgs/Role=production -out ${HOME}/.globus/gridproxy.cert -valid 24:0
#export X509_USER_PROXY=${HOME}/.globus/gridproxy.cert

# for bad electrons in HIGG8D1 with no matched clusters (e.g. run 302872)
if [ ! -d TopObjectSelectionTools ]; then
    rc checkout_pkg TopObjectSelectionTools
    sed -i 's/\/\/This stops a crash/if (!(el.caloCluster())) return false;/' TopObjectSelectionTools/Root/ElectronLikelihoodMC15.cxx
fi

#new tau ele bdt (not needed for v29, 00-02-51 from AnalysisTop enough)
#rc checkout_pkg atlasoff/PhysicsAnalysis/TauID/TauAnalysisTools/tags/TauAnalysisTools-00-02-54

#for latest June 8th b-tagging SFs recommendations and PromptLeptonIso SFs
if [ ! -d TopCPTools ]; then
    rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopCPTools/tags/TopCPTools-00-01-60
    patch -d TopCPTools -p0 < ttHMultilepton/addPromptLeptonIsoSFs.patch
fi

#for missing tau track links
if [ ! -d TopCorrections ]; then
    rc checkout_pkg TopCorrections
    patch -d TopCorrections -p0 < ttHMultilepton/MissingTauTrackLinks.patch
fi

#for new k-factors for ttgamma and ttW ANALYSISTO-326
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/TopPhysUtils/TopDataPreparation/tags/TopDataPreparation-00-08-69

# for retrieve b-tag SF input systematic names (required for EV decomposition)
#rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopConfiguration/tags/TopConfiguration-00-04-47
#rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopCorrection/tags/TopCorrection-00-01-15
#rc checkout_pkg atlasoff/PhysicsAnalysis/JetTagging/JetTagPerformanceCalibration/xAODBTaggingEfficiency/tags/xAODBTaggingEfficiency-00-00-39

# rc build is shortcut for rc find_packages && rc compile
rc build

echo "Alright - done."

pushd .
cd ttHMultilepton/share
# for fastSim samples
sed 's/IsAFII False/IsAFII True/' generic_config-mc15.txt > generic_config-mc15_fastSim.txt
sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys_fastSim.txt
# for promptLepton SFs with CFT for electrons
sed 's/ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLeptonCFT/' generic_config-mc15.txt > generic_config-mc15_CFT.txt
sed 's/ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLeptonCFT/' generic_config-mc15_fastSim.txt > generic_config-mc15_CFT_fastSim.txt
sed 's/ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLeptonCFT/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys_CFT.txt
sed 's/ElectronIsolationLoose PromptLepton/ElectronIsolationLoose PromptLeptonCFT/' generic_config-mc15-Sys_fastSim.txt > generic_config-mc15-Sys_CFT_fastSim.txt
#python ttHMultilepton/scripts/01SubmitToGrid.py


popd
