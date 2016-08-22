
import TopExamples.grid
#import DerivationTags
#import Data15
import MC_ichep
import Data16

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'dhohn'
config.excludedSites = ''#'ANALY_GOEGRID'
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = ''#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'

###############################################################################
#Systematics
config.settingsFile  = 'generic_config-mc15-Sys.txt'
config.suffix        = '22.07.16.Sys'
config.maxNFilesPerJob = '1'
config.memory = ''

reduced = TopExamples.grid.Samples(['reduced'])
full    = TopExamples.grid.Samples(['full'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2666',reduced)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2666',full)
all_samples = reduced + full

#~ TopExamples.grid.submit(config,mc15c)

####################################################################################
#Nominal
config.settingsFile  = 'generic_config-mc15.txt'
config.suffix = '18.08.16.Nominal-04'
config.memory = ''
config.maxNFilesPerJob = ''

TopExamples.grid.submit(config,all_samples)


########################################################################################
#data
#config.settingsFile  = 'generic_config-data15.txt'
config.suffix = '18.08.16.Data-04'
config.memory = ''
config.maxNFilesPerJob = ''

#data15 = TopExamples.grid.Samples(['data_2015_20.7'])
data15 = TopExamples.grid.Samples(['data15'])
config.settingsFile = 'generic_config-data15.txt'
TopExamples.grid.submit(config, data15)

data16 = TopExamples.grid.Samples(['data16'])
config.settingsFile = 'generic_config-data16.txt'
TopExamples.grid.submit(config,data16)


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
