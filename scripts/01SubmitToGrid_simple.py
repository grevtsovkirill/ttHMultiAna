#!/usr/bin/env python
import TopExamples.grid
import mc16r21
#import MC_EPS
#import Data16
import os
import grid
#import shutil

#configDir = os.getenv('WorkDir_DIR') + '/data/ttHMultilepton/'
#configFiles = os.listdir(configDir)
#for configFile in configFiles:
#    fullFileName = os.path.join(configDir, configFile)
#    if os.path.isfile(fullFileName) and os.path.realpath('.') != #os.path.realpath(configDir):
#        shutil.copy(fullFileName,'.');
config=grid.Config()
#config = TopExamples.grid.Config()
config.CMake = True
config.code          = 'top-xaod'
config.gridUsername  = 'magaras'
config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT'#'ANALY_GOEGRID'
config.noSubmit      = True
config.memory	     = ''

config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = 'IN2P3-CPPM_LOCALGROUPDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'
#config.destSE        = ''

####################################################################################
#Nominal
#config.suffix = '02-06-02'
config.suffix = 'DENEME2'
config.maxNFilesPerJob = '20'
config.settingsFile = 'generic_config-mc15.txt'
config.maxFileSize='20000000000000'
config.extFile='.root,.so'
names = [
    'newsamples',
#    'Data16_TOPQ1',
]

#samples = TopExamples.grid.Samples(names)
#TopExamples.grid.submit(config, samples)
samples = grid.Samples(names)
grid.submit(config, samples)
