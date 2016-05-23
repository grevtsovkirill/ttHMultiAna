#!/usr/bin/env python
import TopExamples.grid
#import DerivationTags
import Data15
import MC15bv2

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'hpotti'
config.excludedSites = 'ANALY_GOEGRID'
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = 'SMU2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'

###############################################################################
#Systematics
config.settingsFile  = 'generic_config-mc15-Sys.txt'
config.suffix        = '23.05.16.Sys'
config.maxNFilesPerJob = '1'
config.memory = ''

mc15b                         = TopExamples.grid.Samples(['MC15b'])
mc15a                         = TopExamples.grid.Samples(['MC15a'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',mc15b)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',mc15a)
#all_samples = mc15b
TopExamples.grid.submit(config,mc15b)

config.settingsFile  = 'generic_config-mc15a-Sys.txt'
TopExamples.grid.submit(config,mc15a)

####################################################################################
#Nominal
config.settingsFile  = 'generic_config-mc15.txt'
config.suffix = '23.05.16.Nominal'
config.memory = ''
config.maxNFilesPerJob = ''

#nominal_mc15b                         = TopExamples.grid.Samples(['mc15b_nominal_only'])
#TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',nominal_mc15b)
#all_samples += nominal_mc15b
TopExamples.grid.submit(config,mc15b)

config.settingsFile  = 'generic_config-mc15a.txt'
TopExamples.grid.submit(config,mc15a)

########################################################################################
#data
config.settingsFile  = 'generic_config-data15.txt'
config.suffix = '23.05.16.Data'
config.memory = ''
config.maxNFilesPerJob = ''

data = TopExamples.grid.Samples(['data_2015_25ns_only_grlv73'])
#data = TopExamples.grid.Samples(['failed'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2559',data)
TopExamples.grid.submit(config, data)


#################################################################################
#PRW
'''
samples = samples_zjets_mg + samples_wjets_mg
def makePRWcommand(samples):
    for sample in samples:
        for ds in sample.datasets:
            dsid = ds.split('.')[1]
            print 'pathena PileupReweighting/generatePRW_jobOptions.py --inDS="%s/" --outDS="user.%s.tthML.PURWTconfig.%s.26Jan16.root/"' % (ds,config.gridUsername, dsid)
        
#print makePRWcommand(samples)
'''
