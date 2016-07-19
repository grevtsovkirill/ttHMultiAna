# /bin/bash

function cleanExit {
    rm -rf $RUNDIR/$gridName
    echo exit $1
    exit $1
}


gridName=$1
eosPath=$2
DSID=$3
fileName=${DSID}.root

echo "Job Info"
echo "Download from: $gridName"
echo "Upload to    : $eosPath/$fileName"
echo

#cd $TMPDIR
#echo $TMPDIR
#echo $pwd
RUNDIR=$(pwd)
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









for file in $(ls *.root*); do
    echo xrdcp -f -np  $file $eosPath/$DSID/
    xrdcp -f -np $file $eosPath/$DSID/
    eoscpExit=$?
    echo "eos cp exit $haddExit"
    [ $eoscpExit -eq 0 ] || cleanExit 3
done
    
echo "alles goed"

cleanExit 0
