#! /bin/sh
echo "Setting up RootCore and requested Top Analysis version..."
rcSetup Top,2.3.18

echo "Setting up all grid-related libraries..."
localSetupPandaClient --noAthenaCheck
localSetupPyAMI
localSetupRucioClients

echo "Alright - done."
