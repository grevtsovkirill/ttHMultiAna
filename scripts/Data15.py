import TopExamples.grid
import TopExamples.ami

#https://twiki.cern.ch/twiki/bin/view/Atlas/DataPreparationReprocessing

#repro19 containers
#periodA = TopExamples.ami.getContainerContents('data15_13TeV.periodA.physics_Main.PhysCont.AOD.repro19_v01')
#periodB = TopExamples.ami.getContainerContents('data15_13TeV.periodC.physics_Main.PhysCont.AOD.repro19_v01')
#TopExamples.grid.Add('Data15_PeriodAB_repro19').datasets = periodA + periodB

#t0pro19_v01
#periodD = TopExamples.ami.getContainerContents('data15_13TeV.periodD.physics_Main.PhysCont.AOD.t0pro19_v01')
#TopExamples.grid.Add('Data15_PeriodD_t0pro19').datasets = periodD

#or you can manually add dataset names
#TopExamples.grid.Add('MyData').datasets = [
#'dataBlah..',
#'dataBlah2..',
#]


TopExamples.grid.Add('data_2015_20.7').datasets = [
'data15_13TeV.00276262.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276329.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276336.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276416.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276511.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276689.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276778.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276790.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276952.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00276954.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00278880.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00278912.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00278968.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279169.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279259.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279279.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279284.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279345.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279515.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279598.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279685.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279813.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279867.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279928.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279932.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00279984.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280231.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280273.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280319.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280368.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280423.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280464.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280500.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280520.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280614.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280673.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280753.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280853.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280862.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280950.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00280977.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00281070.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00281074.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00281075.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00281317.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00281385.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00281411.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00282625.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00282631.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00282712.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00282784.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00282992.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00283074.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00283155.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00283270.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00283429.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00283608.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00283780.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284006.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284154.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284213.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284285.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284420.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284427.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',
'data15_13TeV.00284484.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2667',

]

GRLruns = [
"00276262",
"00276329",
"00276336",
"00276416",
"00276511",
"00276689",
"00276778",
"00276790",
"00276952",
"00276954",
"00278880",
"00278912",
"00278968",
"00279169",
"00279259",
"00279279",
"00279284",
"00279345",
"00279515",
"00279598",
"00279685",
"00279764",
"00279813",
"00279867",
"00279928",
"00279932",
"00279984",
"00280231",
"00280319",
"00280368",
"00280423",
"00280464",
"00280500",
"00280520",
"00280614",
"00280673",
"00280753",
"00280853",
"00280862",
"00280950",
"00280977",
"00281070",
"00281074",
"00281075",
"00281317",
"00281385",
"00281411",
"00282625",
"00282631",
"00282712",
"00282784",
"00282992",
"00283074",
"00283155",
"00283270",
"00283429",
"00283608",
"00283780",
"00284006",
"00284154",
"00284213",
"00284285",
"00284420",
"00284427",
"00284484",
]
        
if __name__ == '__main__':

    count_ds = 0
    
    samples = TopExamples.grid.Samples(['data_2015_20.7'])
    all_dsids = []
    for sample in samples:
        for ds in sample.datasets:
            dsid = ds.split('.')[1]
            if dsid in GRLruns:
                print ds
                count_ds += 1

        print count_ds, len(sample.datasets)

            
    #for r in GRLruns:
        
        
    #runs = sorted(TopExamples.grid.listDatasets('data15_13TeV', '*.physics_Main.merge.AOD.f*'))

    #print len(runs)
    #for ds in runs:
    #    print ds
