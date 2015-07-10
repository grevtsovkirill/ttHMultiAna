
svn co svn+ssh://svn.cern.ch/reps/atlasoff/PhysicsAnalysis/TopPhys/TopPhysUtils/TopDataPreparation/trunk/data/
mv $(pwd)/data/XSection-MC15-13TeV-fromSusyGrp.data .
g++ xsection_reader.cpp
./a.out
rm XSection-MC15-13TeV-fromSusyGrp.data
rm -rf ./data/
echo "Successfully Updated Cross-sections and K-factors"
~              
