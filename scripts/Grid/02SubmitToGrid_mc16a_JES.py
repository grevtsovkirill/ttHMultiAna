#!/usr/bin/env python
import TopExamples.grid
import mc16aR21
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
#config.excludedSites = 'ANALY_CONNECT,ANALY_CONNECT_SHORT'#'ANALY_GOEGRID'
config.noSubmit      = True
config.memory	     = ''
config.otherOptions='--forceStaged'

config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
config.destSE        = 'CERN-PROD_SCRATCHDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'
#config.destSE        = ''

####################################################################################
#Nominal
#config.suffix = 'DENEME2'
config.nGBPerJob='4'
config.maxFileSize='20000000000000'
config.extFile='.root,.so'

# THIS IS NOT NEEDED - in beggining is check to copy files from $WorkDir
# if not os.path.isfile("generic_config_systmc16a.txt"):
# 	print "Missing generic_config_systmc16a.txt. Code will crash. Exiting..."
# 	sys.exit()
# for dsid in ["345674", "345673", "345672", "410470", "410472", "410155", "410218", "410219" ,"410220"]:
# 	if not os.path.isfile("generic_config_systmc16a_" + dsid + ".txt"):
# 		print "Missing generic_config_systmc16a_"+ dsid + ".txt. Code will crash. Exiting..."
# 		sys.exit()

subsuf="CHANGEME"
# for systematics
baseSuffix = subsuf+"_sys_mc16a"
# unused sampels:
#           old sig "345674", "345673", "345672",
for dsid in ["410470", "410472","345875","345874","345873","410155", "410218", "410219" ,"410220"]:
    # individual files
    config.settingsFile = 'generic_config_systmc16a_' + dsid + '.txt'
    config.suffix = baseSuffix
    names = ["singleSample_" + dsid,]
    samples = grid.Samples(names)
    grid.submit(config, samples)
else:
    # other systematics
    config.suffix = baseSuffix
    names = ["syst_mc16a",]
    config.settingsFile = "generic_config_systmc16a.txt"
    samples = grid.Samples(names)
    grid.submit(config, samples)

#for nominal:
baseSuffix = subsuf+"_nom_mc16a"
config.suffix = baseSuffix
names = ["FS_mc16a",]
config.settingsFile = "generic_config_mc16a.txt"
samples = grid.Samples(names)
grid.submit(config, samples)

# for AFII:
baseSuffix = subsuf+"_af2_mc16a"
config.suffix = baseSuffix
names = ["AF_mc16a",]
config.settingsFile = "generic_config_AFIImc16a.txt"
samples = grid.Samples(names)
grid.submit(config, samples)
