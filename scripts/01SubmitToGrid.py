#!/usr/bin/env python
import TopExamples.grid
#import DerivationTags
import Data15
import MC15

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'hpotti'
config.excludedSites = ''
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = '' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'

###############################################################################
#Systematics
config.settingsFile  = 'generic_config-mc15-Sys.txt'
config.suffix        = '26.1.16.v4.Sys'

#priority samples for producing systematics
samples_p2501                 = TopExamples.grid.Samples(['systematic_production'])
samples_p2501_high_efficiency = TopExamples.grid.Samples(['systematic_production_high_efficiency'])
samples_p2434                 = TopExamples.grid.Samples(['systematic_production_diboson_mc15a'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_p2501)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2501', samples_p2501_high_efficiency)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_p2434)

#submit with default --maxNFilesPerJob
all_samples = samples_p2501+samples_p2434
#TopExamples.grid.submit(config, all_samples)

#submit with --maxNFilesPerJob=1 because many events are expected to pass skimming
config.maxNFilesPerJob = '1'
#TopExamples.grid.submit(config, samples_p2501_high_efficiency)
all_samples += samples_p2501_high_efficiency

####################################################################################
#Nominal
config.settingsFile  = 'generic_config-mc15.txt'
config.suffix = '26.1.16.v4.Nominal'
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
#and these only have p2434
samples_specials = TopExamples.grid.Samples(['specials'])

all_samples += samples_zjets_sherpa
all_samples += samples_zjets_sherpa_p2480
all_samples += samples_wjets_sherpa
all_samples += samples_ttv_sherpa
all_samples += samples_specials
print all_samples[1]
#TopExamples.grid.submit(config, all_samples)


#alternative zjets, wjets
samples_zjets_mg = TopExamples.grid.Samples(['systematic_production_zjets_mg'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_zjets_mg)
samples_wjets_mg = TopExamples.grid.Samples(['systematic_production_wjets_mg'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1', 'p2434', samples_wjets_mg)

config.suffix = '27.1.16.v4.alt.Nominal'
#TopExamples.grid.submit(config, samples_zjets_mg + samples_wjets_mg)

########################################################################################
#data
config.settingsFile  = 'generic_config-data15.txt'
config.suffix = '26.1.16.v4.Data'
config.memory = ''
config.maxNFilesPerJob = ''

data = TopExamples.grid.Samples(['data_2015_25ns_only_grlv73'])
#TopExamples.grid.submit(config, data)


#################################################################################
#PRW
samples = samples_zjets_mg + samples_wjets_mg
def makePRWcommand(samples):
    for sample in samples:
        for ds in sample.datasets:
            dsid = ds.split('.')[1]
            print 'pathena PileupReweighting/generatePRW_jobOptions.py --inDS="%s/" --outDS="user.%s.tthML.PURWTconfig.%s.26Jan16.root/"' % (ds,config.gridUsername, dsid)
        

#print makePRWcommand(samples)
