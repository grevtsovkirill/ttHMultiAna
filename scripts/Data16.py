import TopExamples.grid
import TopExamples.ami


TopExamples.grid.Add('data16').datasets = [
'data16_13TeV.00297730.physics_Main.merge.DAOD_HIGG8D1.f694_m1583_p2667',
'data16_13TeV.00298595.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298609.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298633.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298687.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298690.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298771.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298773.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00298862.physics_Main.merge.DAOD_HIGG8D1.f696_m1588_p2667',
'data16_13TeV.00298967.physics_Main.merge.DAOD_HIGG8D1.f696_m1588_p2667',
'data16_13TeV.00299055.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00299144.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00299147.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00299184.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00299243.physics_Main.merge.DAOD_HIGG8D1.f698_m1594_p2667',
'data16_13TeV.00299584.physics_Main.merge.DAOD_HIGG8D1.f703_m1600_p2667',
'data16_13TeV.00300279.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300345.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300415.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300418.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300487.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300540.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300571.physics_Main.merge.DAOD_HIGG8D1.f705_m1606_p2667',
'data16_13TeV.00300600.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00300655.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00300687.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00300784.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00300800.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00300863.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00300908.physics_Main.merge.DAOD_HIGG8D1.f708_m1606_p2667',
'data16_13TeV.00301912.physics_Main.merge.DAOD_HIGG8D1.f709_m1611_p2667',
'data16_13TeV.00301915.physics_Main.merge.DAOD_HIGG8D1.f709_m1611_p2667',
'data16_13TeV.00301918.physics_Main.merge.DAOD_HIGG8D1.f709_m1611_p2667',
'data16_13TeV.00301932.physics_Main.merge.DAOD_HIGG8D1.f709_m1611_p2667',
'data16_13TeV.00301973.physics_Main.merge.DAOD_HIGG8D1.f709_m1611_p2667',
]

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


if __name__ == '__main__':
   
    scope = 'data16_13TeV'
    ptag  = '_p2667'            #p-tag of Data Derivations
    grl   = 'data16_13TeV.periodAllYear_DetStatus-v79-pro20-05_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml'
        #specify ONLY the name of grl file. By default, it will look for it in ttHMultilepton/data folder 
    
    grl_runs = get_grlruns(grl)
    print("GRL Runs are: ",grl_runs)

    ami_list = sorted(TopExamples.grid.listDatasets(scope,'*.physics_Main.merge.DAOD_HIGG8D1.*'+ptag))
    #ami_list = sorted(TopExamples.ami.askAmi('data16_13TeV*physics_Main.merge.DAOD_HIGG8D1*_p2623'))
    ami_list = [ds.encode("ascii") for ds in ami_list] # convert Uni-string to ASCII
    #print ami_list
    datasets = []
    
    for run in ami_list:
        dsid = int(run.split('.')[1])
        if dsid in grl_runs:
            datasets.append(run)
            print "'"+run+"',"

    #print datasets

    
# Check carefully. You might get 2 or more derivations for a single run number. Select only the recent one
