#!/usr/bin/env python
import TopExamples.grid
#import mc16aR21
import MC16_TOPQ1
#import mc16aR21
#import dataTOPQ1
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
config.gridUsername  = 'phys-exotics'
config.groupProduction= 'True'
config.excludedSites = 'ANALY_GLASGOW_SL6'
config.noSubmit      = False
config.memory	     = ''
config.otherOptions='--forceStaged'

config.mergeType     = 'Default' #'None', 'Default' or 'xAOD'
#config.destSE        = 'CERN-PROD_SCRATCHDISK'#'BNL-OSG2_LOCALGROUPDISK' #This is the default (anywhere), or try e.g. 'UKI-SOUTHGRID-BHAM-HEP_LOCALGROUPDISK'
#config.forceSite     = 'ANALY_CONNECT'
#config.destSE        = ''

####################################################################################
#Nominal
#config.suffix = 'v3-2'
config.suffix = 'v4-1'
#config.suffix ='v3_noskim'
#config.suffix = 'DENEME2'
config.nGBPerJob='4'
config.settingsFile = 'generic_config_LQ_mc16a.txt'
#config.settingsFile = 'generic_config_data.txt'
config.maxFileSize='20000000000000'
config.extFile='.root,.so'

names = [
#    'newsamples',
##    'Data16_TOPQ1',
#   'samples_data15',
#   'samples_data16',
#	'highPriority_mc16a'
#	'highPriority_mc16c'

#    'All_data',
#    'rnn_test',
#   'samples_data17'
#    'samples_data18'

#    'temp'

#    'dijets',

#    'samples_p3553',
#    'samples_data15',
#    'samples_data16',

#    'group_190401'
    # 'temp_190701',

    'TOPQ1_LQ',
    'TOPQ1_LQ_B05',
    'TOPQ1_LQ_tbem_B05',

    'TOPQ1_ttbar_ht',
    'TOPQ1_ttbar_PowPy8', 
    'TOPQ1_ttbar_dil_PowPy8', 
    'TOPQ1_ttV',    
    'TOPQ1_ttH',
    'TOPQ1_tchan_lep_PowPy8',
    'TOPQ1_Wt_inc_PowPy8',
    'TOPQ1_Wt_dil_PowPy8',
    'TOPQ1_schan_noAllHad_PowPy8',
    'TOPQ1_tZ_noAllHad_PowPy8',
    'TOPQ1_diboson_Sherpa',
    'TOPQ1_Wjets_Sherpa221', 
    'TOPQ1_Zjets_Sherpa221', 

    'TOPQ1_tWZ',
    'TOPQ1_3top',
    'TOPQ1_ttll_lowmass',
    'TOPQ1_diboson_EW',
    'TOPQ1_triboson_Sherpa',
    'TOPQ1_VH',

    # 'ttbar_sys'

#    'temp_190425',
   # ''
]

#samples = TopExamples.grid.Samples(names)
#TopExamples.grid.submit(config, samples)
#print grid.checkDatasetExists(names)
samples = grid.Samples(names)
grid.submit(config, samples)
