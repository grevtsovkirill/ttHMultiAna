#!/usr/bin/env python
import TopExamples.grid
import DerivationTags
import Data15
import MC15

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.settingsFile  = 'generic_config-mc15-Sys.txt'

config.gridUsername  = 'dhohn'
config.suffix        = 'v3.Sys'
config.excludedSites = ''
config.noSubmit      = True
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = '' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'

###############################################################################

samples_p2501                 = TopExamples.grid.Samples(['systematic_production'])
samples_p2501_high_efficiency = TopExamples.grid.Samples(['systematic_production_high_efficiency'])
samples_p2434                 = TopExamples.grid.Samples(['systematic_production_diboson_mc15a'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_p2501)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_p2501_high_efficiency)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_p2434)

#submit with default --maxNFilesPerJob
samples = samples_p2501+samples_p2434
TopExamples.grid.submit(config, samples)

#submit with --maxNFilesPerJob=1 because many events are expected to pass skimming
config.maxNFilesPerJob = '1'
TopExamples.grid.submit(config, samples_p2501_high_efficiency)




#PRW
samples_prw_mc15a = TopExamples.grid.Samples(['pileup_reweighting_mc15a'])
samples_prw_mc15b = TopExamples.grid.Samples(['ttbar_dilep'])
#TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_prw_mc15b)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_prw_mc15a)
samples = samples_prw_mc15a+samples_prw_mc15b

def makePRWcommand(samples):
    for sample in samples:
        for ds in sample.datasets:
            dsid = ds.split('.')[1]
            print 'pathena PileupReweighting/generatePRW_jobOptions.py --inDS="%s/" --outDS="user.dhohn.tthML.PURWTconfig.%s.root/"' % (ds, dsid)
        
