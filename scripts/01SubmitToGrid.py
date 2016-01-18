#!/usr/bin/env python
import TopExamples.grid
import DerivationTags
import Data15
import MC15

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'dhohn'
config.excludedSites = ''
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = '' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'

###############################################################################
#Systematics
config.settingsFile  = 'generic_config-mc15-Sys.txt'
config.suffix        = 'v3.Sys'

#priority samples for producing systematics
samples_p2501                 = TopExamples.grid.Samples(['systematic_production'])
samples_p2501_high_efficiency = TopExamples.grid.Samples(['systematic_production_high_efficiency'])
samples_p2434                 = TopExamples.grid.Samples(['systematic_production_diboson_mc15a'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_p2501)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_p2501_high_efficiency)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_p2434)

stragglers = TopExamples.grid.Samples(['stragglers'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', stragglers)
#TopExamples.grid.submit(config, stragglers)

#submit with default --maxNFilesPerJob
samples = samples_p2501+samples_p2434
#TopExamples.grid.submit(config, samples)

#submit with --maxNFilesPerJob=1 because many events are expected to pass skimming
config.maxNFilesPerJob = '1'
#TopExamples.grid.submit(config, samples_p2501_high_efficiency)

####################################################################################
#Nominal
config.settingsFile  = 'generic_config-mc15.txt'
config.suffix = 'v3.Nominal'
config.memory = ''
config.maxNFilesPerJob = ''

#rest of samples for nominal unskimmed production
samples_zjets_sherpa = TopExamples.grid.Samples(['systematic_production_zjets_sherpa'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_zjets_sherpa)
samples_wjets_sherpa = TopExamples.grid.Samples(['systematic_production_wjets_sherpa'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_wjets_sherpa)
#for some reason this one didnt get submitted with p2501
samples_zjets_sherpa_p2480 = TopExamples.grid.Samples(['zjets_sherpa_p2480'])
samples_ttv_sherpa = TopExamples.grid.Samples(['systematic_production_ttv_sherpa'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_ttv_sherpa)

all_samples = []
all_samples += samples_p2501
all_samples += samples_p2434
all_samples += samples_p2501_high_efficiency
all_samples += samples_zjets_sherpa
all_samples += samples_zjets_sherpa_p2480
all_samples += samples_wjets_sherpa
all_samples += samples_ttv_sherpa
#TopExamples.grid.submit(config, all_samples)

config.suffix = 'v3.x.Nominal'
specials = TopExamples.grid.Samples(['specials'])
TopExamples.grid.submit(config, specials)

#alternative zjets, wjets
samples_zjets_mg = TopExamples.grid.Samples(['systematic_production_zjets_mg'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_zjets_mg)
samples_wjets_mg = TopExamples.grid.Samples(['systematic_production_wjets_mg'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_wjets_mg)

config.suffix = 'v3.alt.Nominal'
#TopExamples.grid.submit(config, samples_zjets_mg + samples_wjets_mg)

########################################################################################
#data
config.settingsFile  = 'generic_config-data15.txt'
config.suffix = 'v3.Data'
config.memory = ''
config.maxNFilesPerJob = ''

data = TopExamples.grid.Samples(['data_25ns'])
#TopExamples.grid.submit(config, data)

config.suffix = 'v3.Data.x'
data = TopExamples.grid.Samples(['data_25ns_broken'])
#TopExamples.grid.submit(config, data)


#################################################################################
#PRW

def makePRWcommand(samples):
    for sample in samples:
        for ds in sample.datasets:
            dsid = ds.split('.')[1]
            print 'pathena PileupReweighting/generatePRW_jobOptions.py --inDS="%s/" --outDS="user.%s.tthML.PURWTconfig.%s.root/"' % (config.gridUsername, ds, dsid)
        
