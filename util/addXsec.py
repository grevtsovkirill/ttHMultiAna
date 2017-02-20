datasets = [
"mc15_13TeV.364198.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364199.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364200.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364201.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364202.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364203.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364204.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364205.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364206.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364207.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364208.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364209.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364210.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364211.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364212.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364213.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364214.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BVeto.merge.AOD.e5421_s2726_r7772_r7676",
"mc15_13TeV.364215.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BFilter.merge.AOD.e5421_s2726_r7772_r7676", 
]

#dataset = "mc15_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.merge.AOD.e4706_s2726_r7326_r6282"
for dataset in datasets:
    words = dataset.split('.')
    dsid = words[1]
    generator = words[2].split('_')[0]
    simulation = words[5].split('_')[1]
    simtype = "NA"
    procname = words[2].split('_', 3)[-1]
    if simulation.startswith("s"):
        simtype = "Full"
    elif simulation.startswith("a"):
        simtype = "AFII"
    else:
        print "Simulation type not found for this sample"
        
    print "%s 0.0 0.0 1.0 -- -999 1 %s %s %s" %(dsid, generator, procname, simtype)
