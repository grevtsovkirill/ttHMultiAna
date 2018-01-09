# Tutorial
This small project helps learning how to use AnalysisTop.
It currently contains a single package with illustrate how to create an anlaysis package which extends AnalysisTop.

### Status
The code compiles and works with AnalysisTop-21.2.10.

### Setup (assuming git has been used once already)

    setupATLAS
    lsetup git
    kinit <username>@CERN.CH
    mkdir MyDirectory
    cd MyDirectory
    mkdir build run
    git clone https://:@gitlab.cern.ch:8443/atlasphys-top/reco/Tutorial.git
    cd build
    asetup AnalysisTop,21.2.10,here
    cmake  ../Tutorial/
    cmake --build ./
    source */setup.sh


### Testing

    setupATLAS
    lsetup git
    kinit <username>@CERN.CH
    cd MyDirectory
    cd build
    asetup --restore
    source */setup.sh
    cd ../run
    get_files  input-mc-rel21.txt
    cp ../Tutorial/HowtoExtendAnalysisTop/share/ExtendedAnalysisTop.txt .
    
### Twiki

    https://twiki.cern.ch/twiki/bin/view/AtlasProtected/AnalysisTopR21Tutorial