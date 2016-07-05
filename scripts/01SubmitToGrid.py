
import TopExamples.grid
#import DerivationTags
import Data15
import MC_ichep
import Data16

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'hpotti'
config.excludedSites = 'ANALY_GOEGRID'
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = 'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'

###############################################################################
#Systematics
config.settingsFile  = 'generic_config-mc15-Sys.txt'
config.suffix        = '05.07.16.Sys'
config.maxNFilesPerJob = '1'
config.memory = ''

mc15c                          = TopExamples.grid.Samples(['ptag_p2666'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2666',mc15c)
all_samples = mc15c

TopExamples.grid.submit(config,mc15c)

####################################################################################
#Nominal
config.settingsFile  = 'generic_config-mc15.txt'
config.suffix = '05.07.16.Nominal'
config.memory = ''
config.maxNFilesPerJob = ''

TopExamples.grid.submit(config,mc15c)


########################################################################################
#data
config.settingsFile  = 'generic_config-data15.txt'
config.suffix = '05.07.16.Data'
config.memory = ''
config.maxNFilesPerJob = ''

data15 = TopExamples.grid.Samples(['data_2015_20.7'])
data16 = TopExamples.grid.Samples(['data16'])
TopExamples.grid.submit(config, data15)

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
