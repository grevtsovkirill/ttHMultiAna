datasets = ["mc15_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.merge.AOD.e4706_s2726_r7326_r6282",
"mc15_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.merge.AOD.e4706_s2726_r7326_r6282"]

#dataset = "mc15_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.merge.AOD.e4706_s2726_r7326_r6282"
for dataset in datasets:
    words = dataset.split('.')
    dsid = words[1]
    generator = words[2].split('_')[0]
    simulation = words[5].split('_')[1]
    simtype = "NA"
    procname = words[2].split('_', 4)[-1]
    if simulation.startswith("s"):
        simtype = "Full"
    elif simulation.startswith("a"):
        simtype = "AFII"
    else:
        print "Simulation type not found for this sample"
        
    print "%s 0.0 0.0 1.0 -- -999 2 %s %s %s" %(dsid, generator, procname, simtype)
