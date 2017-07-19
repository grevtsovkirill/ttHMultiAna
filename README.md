# Setting up AnalysisTop

To set up the AnalysisTop package do
```bash
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
mkdir YourFancyDirectory
cd YourFancyDirectory
```

# Getting the code

After setting up your Kerberos ticket (not needed on lxplus)
```bash
kinit $CERN_USER@CERN.CH
```
get the code, use the following command:
```bash
git clone https://:@gitlab.cern.ch:8443/atlasHTop/ttHMultiAna.git ttHMultilepton
```
If you want a specific tag, do
```bash
cd ttHMultilepton && git checkout <tag number> && cd ..
```
Please follow the instructions in `setupRCandGrid.sh` to properly set up the package.

To compile the code type
```bash
rc build
```

# Running locally

Change back to your initially created YourFancyDirectory.
To run the framework locally over a derivation (HIGG8D1 is recommended) file
```bash
mkdir Run
cd Run
echo $DXAOD_PATH_TO_ROOT_FILE > infile_htop.txt
```
The master command to run on the framework is
```bash
top-xaod ../ttHMultilepton/share/generic_config-data.txt infile_htop.txt
```
for data and for MC it is
```bash
top-xaod ../ttHMultilepton/share/generic_config-mc15.txt infile_htop.txt
```
or for ntuples including the systematic variation trees
```bash
top-xaod ../ttHMultilepton/share/generic_config-mc15-Sys.txt infile_htop.txt
```
The configuration files for AFII (fast simulation) MC samples has to be modified by replacing "IsAFII False" by "IsAFII True".

# Contributing to the development

If you want to participate develope, please see a nice how-to [here](https://gitlab.cern.ch/TRExStats/TRExFitter/blob/master/CONTRIBUTING.md).

Set up your git configuration with
```bash
git config --global user.name "First Last"
git config --global user.email "first.last@cern.ch"
```

Feature development should generally always occur on a dedicated branch, rather than on the master branch

Keep track of the changes using the [ATLAS ttH multilepton JIRA project](https://its.cern.ch/jira/projects/ATLASTTHML). E.g.
```bash
git commit -m "Working on ATLASTTHML-81: moving to new AnalysisTop"
```
will automatically create a comment on the corresponding JIRA ticket [ATLASTTHML-81](https://its.cern.ch/jira/browse/ATLASTTHML-81).
