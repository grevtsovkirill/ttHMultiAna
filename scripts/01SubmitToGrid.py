import TopExamples.grid
import MC_EPS
import Data16
import os
import shutil

configDir = os.getenv('ROOTCOREBIN') + '/../ttHMultilepton/share/'
configFiles = os.listdir(configDir)
for configFile in configFiles:
    fullFileName = os.path.join(configDir, configFile)
    if os.path.isfile(fullFileName) and os.path.realpath('.') != os.path.realpath(configDir):
        shutil.copy(fullFileName,'.');

config = TopExamples.grid.Config()
config.code          = 'top-xaod'
config.gridUsername  = 'rwolff'
config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT'#'ANALY_GOEGRID'
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = 'IN2P3-CPPM_LOCALGROUPDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'

###############################################################################
#Samples
All_fullSim    = TopExamples.grid.Samples(['All_fullSim'])
All_fastSim    = TopExamples.grid.Samples(['All_fastSim'])
ttbar_fullSim  = TopExamples.grid.Samples(['ttbar_fullSim'])
ttbar_fastSim  = TopExamples.grid.Samples(['ttbar_fastSim'])
VJets_fullSim  = TopExamples.grid.Samples(['VJets_fullSim'])

TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2949', All_fullSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2949', All_fastSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p3075', ttbar_fullSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p3075', ttbar_fastSim)
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2949', VJets_fullSim)

fullSim = All_fullSim + ttbar_fullSim + VJets_fullSim
fastSim = All_fastSim + ttbar_fastSim

#Systematics
config.maxNFilesPerJob = '1'
config.memory = ''

config.suffix       = '2017-06-09.Sys_v29_noCFT'
config.settingsFile = 'generic_config-mc15-Sys.txt'
#TopExamples.grid.submit(config,fullSim)
config.settingsFile = 'generic_config-mc15-Sys_fastSim.txt'
#TopExamples.grid.submit(config,fastSim)

config.suffix       = '2017-06-09.Sys_v29_CFT'
config.settingsFile = 'generic_config-mc15-Sys_CFT.txt'
#TopExamples.grid.submit(config,fullSim)
config.settingsFile = 'generic_config-mc15-Sys_CFT_fastSim.txt'
#TopExamples.grid.submit(config,fastSim)

####################################################################################
#Nominal
config.suffix = '2017-06-09.Nominal_v29_noCFT'
config.memory = ''
config.maxNFilesPerJob = ''

config.settingsFile = 'generic_config-mc15.txt'
#TopExamples.grid.submit(config,all_fullSim)
config.settingsFile = 'generic_config-mc15_fastSim.txt'
#TopExamples.grid.submit(config,all_fastSim)


########################################################################################
#Data
config.suffix = '2017-06-09.Data_v29'
config.memory = ''
config.maxNFilesPerJob = ''
config.otherOptions = '--forceStaged'

config.settingsFile = 'generic_config-data.txt'

TopExamples.grid.Add('data_00284154').datasets = ['user.rwolff.00284154.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2950']
data_00284154 = TopExamples.grid.Samples(['data_00284154'])
data15 = TopExamples.grid.Samples(['data15'])
data16 = TopExamples.grid.Samples(['data16'])

data = data_00284154 + data15 + data16
#TopExamples.grid.submit(config,data)


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
