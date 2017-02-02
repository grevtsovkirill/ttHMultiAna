#!/bin/sh
echo "Setting up all the things"

#lsetup knows in which order to do these

lsetup "rcsetup Top,2.4.25" panda rucio pyami
#voms-proxy-init -voms atlas:/atlas/phys-higgs/Role=production -out ${HOME}/.globus/gridproxy.cert -valid 24:0
#export X509_USER_PROXY=${HOME}/.globus/gridproxy.cert

# for bad electrons in HIGG8D1 with no matched clusters (e.g. run 302872)
rc checkout_pkg $(rc version | grep TopObjectSelectionTools)
sed -i 's/\/\/This stops a crash/if (!(el.caloCluster())) return false;/' TopObjectSelectionTools/Root/ElectronLikelihoodMC15.cxx

# for LHE weights
#rc checkout_pkg atlasoff/Generators/GenAnalysisTools/TruthTools/trunk

# for new ttbar MC samples
#rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/TopPhysUtils/TopDataPreparation/tags/TopDataPreparation-00-08-44

rc build

echo "Alright - done."

#cd ttHMultilepton/share
#sed 's/IsAFII False/IsAFII True/' generic_config-mc15.txt > generic_config-mc15_fastSim.txt
#sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys_fastSim.txt
#sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys-Jets1.txt > generic_config-mc15-Sys-Jets1_fastSim.txt
#sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys-Jets2.txt > generic_config-mc15-Sys-Jets2_fastSim.txt
#sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys-Other.txt > generic_config-mc15-Sys-Other_fastSim.txt
#python ../scripts/01SubmitToGrid.py


