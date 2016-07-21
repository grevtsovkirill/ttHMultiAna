#! /bin/sh
echo "Setting up all the things"

lsetup "rcsetup Top,2.4.16" panda rucio pyami
#lsetup knows in which order to do these
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopSystematicObjectMaker/tags/TopSystematicObjectMaker-00-03-59
rc checkout_pkg atlasoff/PhysicsAnalysis/TopPhys/xAOD/TopObjectSelectionTools/tags/TopObjectSelectionTools-00-03-85

# manually add following line to TopObjectSelectionTools/Root/ElectronLikelihoodMC15.cxx line 107:
#   if (!(el.caloCluster())) return false;

rc build

echo "Alright - done."


