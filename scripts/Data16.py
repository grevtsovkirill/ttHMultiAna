import TopExamples.grid
import TopExamples.ami

def get_grlruns(grl):
    import xml.etree.ElementTree as ET
    import os
    rc = os.getenv("ROOTCOREBIN")
    tree = ET.parse(rc+'/../ttHMultilepton/data/'+grl)
    root = tree.getroot()
    #text_runs = root[0][5].text   # simple way
    for child in root.iter('Metadata'):
        if child.attrib == {'Name': 'RunList'}:
            text_runs = child.text
    string_runs = text_runs.split(',')
    grl_runs = [int(i) for i in string_runs]
    return sorted(grl_runs)

def get_logical_dataset_names(scope, grl_runs):
    ami_list = []
    for ptag in ['p2667','p2689']:
        ami_list += TopExamples.grid.listDatasets(scope,'*.physics_Main.merge.DAOD_HIGG8D1.*_'+ptag)
    #ami_list = sorted(TopExamples.ami.askAmi('data16_13TeV*physics_Main.merge.DAOD_HIGG8D1*_p2623'))
    ami_list = [ds.encode("ascii") for ds in ami_list] # convert Uni-string to ASCII
    #print ami_list

    dsid_set = {} # in the C++ sense ie unique keys

    for dsid in grl_runs:
        matching_runs = sorted([run for run in ami_list if str(dsid) in run])
        #print dsid, matching_runs
        dsid_set[dsid] = matching_runs[-1] # always take the latest

    return sorted(dsid_set.values())



#specify ONLY the name of grl file. By default, it will look for it in ttHMultilepton/data folder
grl15 = 'data15_13TeV.periodAllYear_DetStatus-v79-repro20-02_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml'
grl_runs15 = get_grlruns(grl15)
ds_names15 = get_logical_dataset_names('data15_13TeV', grl_runs15)

grl16 = 'data16_13TeV.periodAllYear_DetStatus-v80-pro20-08_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns_TriggerMenu1e34only.xml'
grl_runs16 = get_grlruns(grl16)
ds_names16 = get_logical_dataset_names('data16_13TeV', grl_runs16)

grl_runs = grl_runs15 + grl_runs16
ds_names = ds_names15 + ds_names16

###################################################
# setting the DS names 
###################################################
TopExamples.grid.Add('data15').datasets = ds_names15
TopExamples.grid.Add('data16').datasets = ds_names16
###################################################


if __name__ == '__main__':

    
    print "GRL Runs are: ", grl_runs
    
    print "DS names"
    for ds in ds_names:
        print ds

    print "Runs in 2015:",len(TopExamples.grid.Samples(['data15'])[0].datasets)
    print "Runs in 2016:",len(TopExamples.grid.Samples(['data16'])[0].datasets)
    print 'Do we have all runs? GRL:',len(grl_runs),'Datasets:',len(ds_names)

