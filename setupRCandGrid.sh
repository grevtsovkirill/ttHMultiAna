#!/bin/sh
echo "Setting up all the things"

#lsetup knows in which order to do these

lsetup "rcsetup Top,2.4.30" panda rucio pyami
#voms-proxy-init -voms atlas:/atlas/phys-higgs/Role=production -out ${HOME}/.globus/gridproxy.cert -valid 24:0
#export X509_USER_PROXY=${HOME}/.globus/gridproxy.cert

# for bad electrons in HIGG8D1 with no matched clusters (e.g. run 302872)
rc checkout_pkg TopObjectSelectionTools
sed -i 's/\/\/This stops a crash/if (!(el.caloCluster())) return false;/' TopObjectSelectionTools/Root/ElectronLikelihoodMC15.cxx

#new tau ele bdt
rc checkout_pkg atlasoff/PhysicsAnalysis/TauID/TauAnalysisTools/tags/TauAnalysisTools-00-02-51

#for latest April 25th b-tagging SFs recommendations
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopCPTools/tags/TopCPTools-00-01-56


#for PromptLeptonIso SFs
rc checkout_pkg MuonEfficiencyCorrections
patch -p0 < ttHMultilepton/addPromptLeptonIsoSFs.patch

#for EleBDT SFs
rc checkout_pkg TopCorrections
patch -d TopCorrections -p0 < ttHMultilepton/newTauEffNPs.patch
patch -d TopCorrections -p0 < ttHMultilepton/MissingTauTrackLinks.patch


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
