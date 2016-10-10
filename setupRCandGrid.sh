#! /bin/sh
echo "Setting up all the things"

#lsetup knows in which order to do these

lsetup "rcsetup Top,2.4.19" panda rucio pyami

# for bad electrons in HIGG8D1 with no matched clusters (e.g. run 302872)
rc checkout $(rc version | grep TopObjectSelectionTools)
sed -i 's/\/\/This stops a crash/if (!(el.caloCluster())) return false;/' TopObjectSelectionTools/Root/ElectronLikelihoodMC15.cxx

rc build

echo "Alright - done."


