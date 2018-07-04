#!/usr/bin/env python
import TopExamples.grid
import mc16aR21
#import mc16cR21
#import dataR21
#import MC_EPS
#import Data16
import os
import grid
import shutil

configDir = os.getenv('WorkDir_DIR') + '/data/ttHMultilepton/'
configFiles = os.listdir(configDir)
for configFile in configFiles:
    fullFileName = os.path.join(configDir, configFile)
    if os.path.isfile(fullFileName) and os.path.realpath('.') != os.path.realpath(configDir):
        shutil.copy(fullFileName,'.');
config=grid.Config()
#config = TopExamples.grid.Config()
config.CMake = True
config.code          = 'top-xaod'
config.gridUsername  = 'phys-higgs'
config.groupProduction= 'True'
#config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT'#'ANALY_GOEGRID'
config.noSubmit      = True
config.memory	     = ''
config.otherOptions='--forceStaged'

config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
#config.destSE        = 'CERN-PROD_SCRATCHDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'
#config.destSE        = ''

####################################################################################
#Nominal
config.suffix = '2017-02-03-01'
#config.suffix = 'DENEME2'
config.nGBPerJob='4'
config.settingsFile = 'ExtendedAnalysisTop_data.txt'
config.maxFileSize='20000000000000'
config.extFile='.root,.so'
names = [
#    'newsamples',
##    'Data16_TOPQ1',
#	'samples_data15',
#	'samples_data16',
	'highPriority_mc16a'
#	'highPriority_mc16c'
]

#samples = TopExamples.grid.Samples(names)
#TopExamples.grid.submit(config, samples)
#print grid.checkDatasetExists(names)
samples = grid.Samples(names)
grid.submit(config, samples)
