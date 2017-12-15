import TopExamples.grid
import mc16r21
#import MC_EPS
#import Data16
import os
import shutil

configDir = os.getenv('WorkDir_DIR') + '/data/ttHMultilepton/'
configFiles = os.listdir(configDir)
for configFile in configFiles:
    fullFileName = os.path.join(configDir, configFile)
    if os.path.isfile(fullFileName) and os.path.realpath('.') != #os.path.realpath(configDir):
        shutil.copy(fullFileName,'.');

config = TopExamples.grid.Config()
config.CMake = True
config.code          = 'top-xaod'
config.gridUsername  = 'magaras'
config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT'#'ANALY_GOEGRID'
config.noSubmit      = False
config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
#config.destSE        = 'IN2P3-CPPM_LOCALGROUPDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'
config.destSE        = ''
####################################################################################
#Nominal
config.suffix = '02-06-02'
#config.suffix = '2017-06-09.Nominal_v29_noCFT'
config.memory = ''
config.maxNFilesPerJob = ''

config.settingsFile = 'generic_config-mc15.txt'

names = [
    'newsamples',
#    'Data16_TOPQ1',
]

samples = TopExamples.grid.Samples(names)
TopExamples.grid.submit(config, samples)

