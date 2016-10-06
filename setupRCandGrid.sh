#! /bin/sh
echo "Setting up all the things"

#lsetup knows in which order to do these

lsetup "rcsetup Top,2.4.19" panda rucio pyami

rc build

echo "Alright - done."


