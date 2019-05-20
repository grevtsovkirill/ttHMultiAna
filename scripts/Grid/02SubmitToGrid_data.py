
#!/usr/bin/env python                                                                                                                                                                                                         
import TopExamples.grid
import dataR21_byPeriod
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
config.CMake = True
config.code          = 'top-xaod'
config.gridUsername  = 'phys-higgs'
config.groupProduction= 'True'
config.noSubmit      = False
config.memory        = ''
config.otherOptions='--forceStaged'

config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'                                                                                                                                                                 
config.destSE        = 'CERN-PROD_SCRATCHDISK'

#################################################################################### 
config.nGBPerJob='4'
config.maxFileSize='20000000000000'
config.extFile='.root,.so'

subsuf="FILLME"
v_subsuf="_v9"
baseSuffix = subsuf+"_data"+v_subsuf
                                                                                                                                                                          

#for nominal:                                                                                                                                                                                                                 
config.settingsFile = "generic_config_data.txt"

baseSuffix = subsuf+"_d15"+v_subsuf
config.suffix = baseSuffix
names = ["samples_period_data15",]
samples = grid.Samples(names)
grid.submit(config, samples)

baseSuffix = subsuf+"_d16"+v_subsuf
config.suffix = baseSuffix
names = ["samples_period_data16",]
samples = grid.Samples(names)
grid.submit(config, samples)

baseSuffix = subsuf+"_d17"+v_subsuf
config.suffix = baseSuffix
names = ["samples_period_data17",]
samples = grid.Samples(names)
grid.submit(config, samples)