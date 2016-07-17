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
    return grl_runs

def get_logical_dataset_names(scope, ptag, grl_runs):
    ami_list = sorted(TopExamples.grid.listDatasets(scope,'*.physics_Main.merge.DAOD_HIGG8D1.*'+ptag))
    #ami_list = sorted(TopExamples.ami.askAmi('data16_13TeV*physics_Main.merge.DAOD_HIGG8D1*_p2623'))
    ami_list = [ds.encode("ascii") for ds in ami_list] # convert Uni-string to ASCII
    #print ami_list
    datasets = []

    dsid_set = {} # in the C++ sense ie unique keys
    
    for run in ami_list:
        dsid = int(run.split('.')[1])
        if dsid in grl_runs:
            dsid_set[dsid] = run  #always takes the latest name if multiple runs since the list is sorted
            datasets.append(run)
            #print "'"+run+"',"

    #print datasets
    return sorted(dsid_set.values())

def get_data_all(scope, grl_runs):
    ptags  = ['_p2667','_p2689']            #p-tag of Data Derivations

    ds_names = []
    for ptag in ptags:
        ds_names += get_logical_dataset_names(scope, ptag, grl_runs)

    return ds_names






#specify ONLY the name of grl file. By default, it will look for it in ttHMultilepton/data folder
grl15 = 'data15_13TeV.periodAllYear_DetStatus-v79-repro20-02_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml'
grl_runs15 = get_grlruns(grl15)
ds_names15 = get_data_all('data15_13TeV', grl_runs15)

grl16 = 'data16_13TeV.periodAllYear_DetStatus-v80-pro20-07_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns_TriggerMenu1e34only.xml'
grl_runs16 = get_grlruns(grl16)
ds_names16 = get_data_all('data16_13TeV', grl_runs16)

grl_runs = grl_runs15 + grl_runs16
ds_names = ds_names15 + ds_names16

###################################################
# setting the DS names 
###################################################
TopExamples.grid.Add('data15').datasets = ds_names15
TopExamples.grid.Add('data16').datasets = ds_names16
###################################################


if __name__ == '__main__':

    
    print("GRL Runs are: ",grl_runs)
    
    print "DS names",ds_names

    print "Runs in 2015:",len(TopExamples.grid.Samples(['data15'])[0].datasets)
    print "Runs in 2016:",len(TopExamples.grid.Samples(['data16'])[0].datasets)
    print 'Do we have all runs in  GRL?',len(grl_runs) == len(ds_names)

