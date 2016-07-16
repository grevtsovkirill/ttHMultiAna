#! /bin/sh
echo "Setting up all the things"

lsetup "rcsetup Top,2.4.15" panda rucio pyami
#lsetup knows in which order to do these

rc build

echo "Alright - done."


