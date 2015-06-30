#! /bin/sh
echo "Setting up RootCore and Top Analysis version 2.3.15b..."
rcSetup Top,2.3.15b

echo "Setting up all grid-related libraries..."
localSetupPandaClient --noAthenaCheck
localSetupPyAMI
localSetupRucioClients

echo "Alright - done."
