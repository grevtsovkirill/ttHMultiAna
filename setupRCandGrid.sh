#! /bin/sh
echo "Setting up RootCore and Top Analysis version 2.3.11..."
rcSetup Top,2.3.13

echo "Setting up all grid-related libraries..."
localSetupPandaClient --noAthenaCheck
localSetupPyAMI
localSetupRucioClients

echo "Alright - done."
