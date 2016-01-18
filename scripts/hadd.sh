# /bin/bash

function cleanExit {
    rm -rf $TMPDIR/$gridName
    echo exit $1
    exit $1
}


gridName=$1
eosPath=$2
fileName=$3

echo "Job Info"
echo "Download from: $gridName"
echo "Upload to    : $eosPath/$fileName"
echo

#cd $TMPDIR
#echo $TMPDIR
#echo $pwd 
mkdir $gridName
cd $gridName

echo "Will download $gridName"
rucio download $gridName|tee rucio.log
rucioExit=$?
echo "rucio exit $rucioExit"
[ $rucioExit -eq 0 ] || cleanExit 1
grep -q "Files that cannot be downloaded :             0" rucio.log
[ $? -eq 0 ] || cleanExit 1

cd $gridName
echo ls -l
ls -l
echo

echo "Will hadd $(ls -1 *.root*|wc -l) files"
hadd -n 5 $fileName *.root*
haddExit=$?
echo "hadd exit $haddExit"
[ $haddExit -eq 0 ] || cleanExit 2

ls -l $fileName

echo xrdcp -f -np $fileName $eosPath/$fileName;
xrdcp -f -np $fileName $eosPath/$fileName;
eoscpExit=$?
echo "eos cp exit $haddExit"
[ $eoscpExit -eq 0 ] || cleanExit 3

echo "alles goed"

cleanExit 0
