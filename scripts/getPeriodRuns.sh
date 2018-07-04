#!/bin/bash

#This script will extract the data campaign->period->run mapping using rucio methods.
#The script works assuming that the period containers with p-tag p3372 are not obsoleted. One might need to change the p-tag in the future because of the n-1 deletion policy of DPD

pTag=p3372
derivation=DAOD_HIGG8D1

for campaign in data15_13TeV data16_13TeV data17_13TeV;
do
    for period in $(rucio list-dids $campaign:$campaign\*period\*physics_Main.PhysCont.$derivation\*$pTag --short);
    do
        echo $campaign: $(echo $period|cut -d "." -f2);
        echo $(rucio list-content $period --short |cut -d "." -f2)
        echo 
    done
done
