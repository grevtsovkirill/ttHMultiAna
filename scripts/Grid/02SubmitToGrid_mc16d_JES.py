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
import sys

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
config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT'#'ANALY_GOEGRID'
config.noSubmit      = True
config.memory	     = ''

config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = 'IN2P3-CPPM_LOCALGROUPDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'
#config.destSE        = ''

####################################################################################
#Nominal
#config.suffix = 'DENEME2'
config.nGBPerJob='4'
config.maxFileSize='20000000000000'
config.extFile='.root,.so'


if not os.path.isfile("generic_config_systmc16d.txt"):
	print "Missing generic_config_systmc16d.txt. Code will crash. Exiting..."
	sys.exit()
for dsid in ["345674", "345673", "345672", "410470", "410472", "410155", "410218", "410219" ,"410220"]:
	if not os.path.isfile("generic_config_systmc16d_" + dsid + ".txt"):
		print "Missing generic_config_systmc16d_"+ dsid + ".txt. Code will crash. Exiting..."
		sys.exit()

baseSuffix = "2018-05-02-01"
for dsid in ["345674", "345673", "345672", "410470", "410472", "410155", "410218", "410219" ,"410220"]:
	config.settingsFile = 'generic_config_systmc16d_' + dsid + '.txt'
	config.suffix = baseSuffix + "-" + dsid
	names = ["singleSample_" + dsid,]
	samples = grid.Samples(names)
	grid.submit(config, samples)

config.suffix = baseSuffix
names = ["highPriority_NominalConfig",]
config.settingsFile = "generic_config_systmc16d.txt"
samples = grid.Samples(names)
grid.submit(config, samples)
