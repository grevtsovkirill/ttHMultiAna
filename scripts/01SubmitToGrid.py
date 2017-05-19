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
config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT,ANALY_LANCS_SL6'#'ANALY_GOEGRID'
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
#config.otherOptions = '--forceStaged'

config.suffix       = '2017-05-13.Sys_v28_2los1tau_1l2tau'
config.settingsFile = 'generic_config-mc15-Sys_2los1tau_1l2tau.txt'
#TopExamples.grid.submit(config,fullSim)
config.settingsFile = 'generic_config-mc15-Sys_2los1tau_1l2tau_fastSim.txt'
#TopExamples.grid.submit(config,fastSim)

####################################################################################
#Nominal
config.suffix = '2017-05-06.Nominal_v28'
config.memory = ''
config.maxNFilesPerJob = ''

config.settingsFile = 'generic_config-mc15.txt'
#TopExamples.grid.submit(config,all_fullSim)
config.settingsFile = 'generic_config-mc15_fastSim.txt'
#TopExamples.grid.submit(config,all_fastSim)


########################################################################################
#Data
config.suffix = '2017-05-06.Data_v27'
config.memory = ''
config.maxNFilesPerJob = ''

config.settingsFile = 'generic_config-data15.txt'
TopExamples.grid.Add('data_00284154').datasets = ['user.rwolff.00284154.physics_Main.merge.DAOD_HIGG8D1.r7562_p2521_p2950']
data_00284154 = TopExamples.grid.Samples(['data_00284154'])
#TopExamples.grid.submit(config, data_00284154)
data15 = TopExamples.grid.Samples(['data15'])
#TopExamples.grid.submit(config, data15)

data16 = TopExamples.grid.Samples(['data16'])
config.settingsFile = 'generic_config-data16.txt'
#TopExamples.grid.submit(config,data16)


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
