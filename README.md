#Directory Sturucture

```bash
setupATLAS
lsetup git
mkdir YourFancyDirectory
cd YourFancyDirectory
mkdir build run source
cd source
git clone https://:@gitlab.cern.ch:8443/atlasHTop/ttHMultiAna.git ttHMultilepton
```
If you want a specific branch,
```bash
git clone https://:@gitlab.cern.ch:8443/atlasHTop/ttHMultiAna.git -b <branch_name> ttHMultilepton
```
#Setting up

You need to have the TrigGlobalEfficiencyCorrection locally in your source directory and the "CMakeLists.txt" of AnalysisTop (this step will be reconsidered).
Follow the instructions to compile in the build directory.
```bash
cd ../build
asetup AnalysisTop,21.2.10,here
cmake ../source
cmake --build ./
source */setup.sh
```

# Running Locally

Go back to your initially created run directory.
```bash
cd ../run
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

