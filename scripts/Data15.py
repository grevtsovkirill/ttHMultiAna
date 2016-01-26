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

TopExamples.grid.Add('data_2015_all').datasets = [
'data15_13TeV.00266904.physics_Main.merge.DAOD_HIGG8D1.r6944_p2410_p2432',
'data15_13TeV.00266919.physics_Main.merge.DAOD_HIGG8D1.r6944_p2410_p2432',
'data15_13TeV.00267073.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00267152.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00267162.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00267167.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00267638.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00267639.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270441.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270448.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270588.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270806.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270816.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270949.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00270953.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271048.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271298.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271388.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271421.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271516.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271595.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00271744.physics_Main.merge.DAOD_HIGG8D1.r6943_p2410_p2432',
'data15_13TeV.00276073.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276147.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276161.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276176.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276181.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276183.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276189.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276212.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276245.physics_Main.merge.DAOD_HIGG8D1.f618_m1480_p2432',
'data15_13TeV.00276262.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276329.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276330.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276336.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276416.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276511.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276689.physics_Main.merge.DAOD_HIGG8D1.f623_m1480_p2432',
'data15_13TeV.00276731.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276778.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276790.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276952.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00276954.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432',
'data15_13TeV.00278727.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278731.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278734.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278748.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278880.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278912.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278968.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00278970.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279169.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279259.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279279.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279284.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279345.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279515.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279598.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279685.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279764.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279813.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279867.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279928.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432',
'data15_13TeV.00279932.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00279984.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280231.physics_Main.merge.DAOD_HIGG8D1.f630_m1504_p2432',
'data15_13TeV.00280273.physics_Main.merge.DAOD_HIGG8D1.f630_m1504_p2432',
'data15_13TeV.00280319.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280368.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280422.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280423.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280464.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280500.physics_Main.merge.DAOD_HIGG8D1.f631_m1504_p2432',
'data15_13TeV.00280520.physics_Main.merge.DAOD_HIGG8D1.f632_m1504_p2432',
'data15_13TeV.00280614.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280673.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2436',
'data15_13TeV.00280753.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280853.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280862.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280950.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00280977.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281070.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281074.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281075.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281130.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281143.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281317.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281327.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281381.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281385.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281411.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281471.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281662.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281669.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281682.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281712.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281724.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281958.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281976.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281978.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00281995.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282026.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282248.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282417.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282418.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282420.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282421.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282423.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282431.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282455.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282457.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432',
'data15_13TeV.00282625.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00282630.physics_Main.merge.DAOD_HIGG8D1.f638_m1511_p2432',
'data15_13TeV.00282631.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00282712.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00282784.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00282992.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00283074.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00283077.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00283155.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432',
'data15_13TeV.00283270.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2436',
'data15_13TeV.00283429.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436',
'data15_13TeV.00283608.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436',
'data15_13TeV.00283780.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436',
'data15_13TeV.00284006.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436',
'data15_13TeV.00284154.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436',
'data15_13TeV.00284213.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436',
'data15_13TeV.00284285.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432',
'data15_13TeV.00284420.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432',
'data15_13TeV.00284427.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432',
'data15_13TeV.00284473.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432',
'data15_13TeV.00284484.physics_Main.merge.DAOD_HIGG8D1.f644_m1518_p2432',
]

#only runs that are actually in grlv73
TopExamples.grid.Add('data_2015_25ns_only_grlv73').datasets = [
'data15_13TeV.00276262.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276329.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276336.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276416.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276511.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276689.physics_Main.merge.DAOD_HIGG8D1.f623_m1480_p2432'
'data15_13TeV.00276778.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276790.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276952.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00276954.physics_Main.merge.DAOD_HIGG8D1.f620_m1480_p2432'
'data15_13TeV.00278880.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00278912.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00278968.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279169.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279259.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279279.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279284.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279345.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279515.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279598.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279685.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279764.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279813.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279867.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279928.physics_Main.merge.DAOD_HIGG8D1.f628_m1497_p2432'
'data15_13TeV.00279932.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00279984.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280231.physics_Main.merge.DAOD_HIGG8D1.f630_m1504_p2432'
'data15_13TeV.00280319.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280368.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280423.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280464.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280500.physics_Main.merge.DAOD_HIGG8D1.f631_m1504_p2432'
'data15_13TeV.00280520.physics_Main.merge.DAOD_HIGG8D1.f632_m1504_p2432'
'data15_13TeV.00280614.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280673.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2436'
'data15_13TeV.00280753.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280853.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280862.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280950.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00280977.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00281070.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00281074.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00281075.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00281317.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00281385.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00281411.physics_Main.merge.DAOD_HIGG8D1.f629_m1504_p2432'
'data15_13TeV.00282625.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00282631.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00282712.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00282784.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00282992.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00283074.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00283155.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2432'
'data15_13TeV.00283270.physics_Main.merge.DAOD_HIGG8D1.f640_m1511_p2436'
'data15_13TeV.00283429.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436'
'data15_13TeV.00283608.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436'
'data15_13TeV.00283780.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436'
'data15_13TeV.00284006.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436'
'data15_13TeV.00284154.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436'
'data15_13TeV.00284213.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2436'
'data15_13TeV.00284285.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432'
'data15_13TeV.00284420.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432'
'data15_13TeV.00284427.physics_Main.merge.DAOD_HIGG8D1.f643_m1518_p2432'
'data15_13TeV.00284484.physics_Main.merge.DAOD_HIGG8D1.f644_m1518_p2432'
]


        
#if __name__ == '__main__':
    #for sample in TopExamples.grid.Samples(['Data15_PeriodAB_repro19', 'Data15_PeriodD_t0pro19']):
        #sample.details()

    #runs = sorted(TopExamples.grid.listDatasets('data15_13TeV', '*.physics_Main.merge.AOD.f*'))

    #print len(runs)
    #for ds in runs:
    #    print ds
