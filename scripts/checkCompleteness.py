import ROOT
import sys
import os

#pyami
import pyAMI.client
import pyAMI.atlas.api as AtlasAPI
client = pyAMI.client.Client("atlas")
AtlasAPI.init()

# Top samples for DS names
import TopExamples.grid
import MC15b
import Data15

mc15b = TopExamples.grid.Samples(['MC15b'])
mc15a = TopExamples.grid.Samples(['MC15a'])
mc15b_nom = TopExamples.grid.Samples(['mc15b_nominal_only'])
data  = TopExamples.grid.Samples(['data_2015_25ns_only_grlv73'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',mc15b)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',mc15a)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',mc15b_nom)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',data)
all_samples = mc15a + mc15b + data + mc15b_nom

def getLogicalDSName(dsid):
    for sample in all_samples:
        for ds in sample.datasets:
            current_dsid = ds.split('.')[1]
            if dsid == current_dsid:
                return ds

    return "Logical DS Name for", dsid, "not found in Top Samples."


#this is my fuse mount location
filepath = "/data/harish/eos/escience/UniTexas/HSG8/multileptons_ntuple_run2/25ns_v12/Data"
files = [ f for f in os.listdir(filepath) if os.path.isfile(os.path.join(filepath,f)) ] 

total = 0
incomplete = 0
corrupt = 0

for f in files:
    total += 1
    fullpath = os.path.join(filepath,f)
    dsid = f[:-5]
    f = ROOT.TFile( fullpath )
    t = f.Get("nominal")
    try:
        t.GetEntries()
    except:
        print dsid, "is corrupt."
        corrupt += 1
        continue
    
    Count = f.Get("loose/Count")
    processedEvents = Count.GetBinContent(3)

    logicalDSName = getLogicalDSName(dsid)
    ds_dict = AtlasAPI.get_dataset_info(client, logicalDSName )
    totalEventsAMI = ds_dict[0]["totalEvents"]
    print dsid,totalEventsAMI, processedEvents
    if int(totalEventsAMI) != int(processedEvents):
        print dsid, "not complete. AMI:",totalEventsAMI, "Processed:",int(processedEvents)
        incomplete += 1
    
    f.Close()

print "Summary"
print "Total files:", total
print "Incomplete files:", incomplete
print "Corrupt files:", corrupt


#GetDataSetInfo -logicalDataSetName=mc...
#GetDataSetProv
