# /bin/bash

start=`date +%s`

function cleanExit {
    end=`date +%s`
    runtime=$((end-start))
    echo runtime $runtime seconds

    rm -rf $RUNDIR/$outDS
    echo exit $1
    exit $1
}

outDS=$1
eosPath=$2
DSID=$3
fileName=${DSID}.root
inDS=$4

echo "Job Info"
echo "Download from: $outDS"
echo "Upload to    : $eosPath/$fileName"
echo

#cd $TMPDIR
#echo $TMPDIR
#echo $pwd
RUNDIR=$(pwd)
mkdir $outDS
cd $outDS

echo "Will download $outDS"
rucio download $outDS|tee rucio.log
rucioExit=$?
echo "rucio exit $rucioExit"
grep -q "Files that cannot be downloaded :             0" rucio.log
rucioFail=$?
echo "rucio failed to download? $rucioFail"
echo 
([ $rucioExit -eq 0 ] && [ $rucioFail -eq 0 ]) || ( echo $inDS >> ${LSB_OUTDIR}/../rucio.fail; cleanExit 1 )

cd $outDS
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
