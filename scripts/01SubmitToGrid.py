import TopExamples.grid
import MC_PostICHEP
import Data16

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'rwolff'
config.excludedSites = ''#'ANALY_GOEGRID'
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = ''#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'

###############################################################################
#Systematics
config.suffix        = '2016-11-23.Sys'
config.maxNFilesPerJob = '1'
config.memory = ''

reduced_fullSim = TopExamples.grid.Samples(['reduced_fullSim'])
reduced_fastSim = TopExamples.grid.Samples(['reduced_fastSim'])
full_fullSim    = TopExamples.grid.Samples(['full'])
new_fullSim     = TopExamples.grid.Samples(['new_fullSim'])
new_fastSim     = TopExamples.grid.Samples(['new_fastSim'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2879',reduced_fullSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2879',reduced_fastSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2879',full_fullSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2879',new_fullSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2879',new_fastSim)
all_fullSim = reduced_fullSim + full_fullSim + new_fullSim
all_fastSim = reduced_fastSim + new_fastSim

config.settingsFile = 'generic_config-mc15-Sys.txt'
#TopExamples.grid.submit(config,reduced_fullSim+new_fullSim)
config.settingsFile = 'generic_config-mc15-Sys_fastSim.txt'
#TopExamples.grid.submit(config,reduced_fastSim+new_fastSim)

####################################################################################
#Nominal
config.suffix = '2016-12-06.Nominal'
config.memory = ''
config.maxNFilesPerJob = ''

config.settingsFile = 'generic_config-mc15.txt'
TopExamples.grid.submit(config,all_fullSim)
config.settingsFile = 'generic_config-mc15_fastSim.txt'
TopExamples.grid.submit(config,all_fastSim)


########################################################################################
#Data
config.suffix = '2016-12-06.Data'
config.memory = ''
config.maxNFilesPerJob = ''

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
