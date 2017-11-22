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
config.noSubmit      = True
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

TopExamples.grid.Add('newSamples').datasets = [
'mc15_13TeV.410276.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee_mll_1_5.merge.AOD.e6087_s2726_r7772_r7676',
'mc15_13TeV.410277.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu_mll_1_5.merge.AOD.e6087_s2726_r7772_r7676',
'mc15_13TeV.410278.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau_mll_1_5.merge.AOD.e6087_s2726_r7772_r7676',
'mc15_13TeV.410397.MadGraphPythia8EvtGen_ttbar_wbee_MEN30LO_A14N23LO.merge.AOD.e6086_s2726_r7772_r7676',
'mc15_13TeV.410398.MadGraphPythia8EvtGen_ttbar_wbmumu_MEN30LO_A14N23LO.merge.AOD.e6086_s2726_r7772_r7676',
'mc15_13TeV.410399.MadGraphPythia8EvtGen_ttbar_wbtautau_MEN30LO_A14N23LO.merge.AOD.e6086_s2726_r7772_r7676',
'mc15_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.merge.AOD.e5070_s2726_r7772_r7676',
]
newSamples = TopExamples.grid.Samples(['newSamples'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p3201', newSamples)
TopExamples.grid.Add('extra').datasets = [
'mc15_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.merge.AOD.e4706_s2726_r7772_r7676',
'mc15_13TeV.343366.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_semilep.merge.AOD.e4706_s2726_r7772_r7676',
'mc15_13TeV.343367.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_allhad.merge.AOD.e4706_s2726_r7772_r7676',
]
extra = TopExamples.grid.Samples(['extra'])
TopExamples.grid.convertAODtoTOPQ('DAOD_HIGG8D1','p2949', extra)

#Systematics
config.maxNFilesPerJob = '1'
config.memory = ''

config.suffix       = '2017-06-09.Sys_v29_noCFT_skim'
config.settingsFile = 'generic_config-mc15-Sys.txt'
#TopExamples.grid.submit(config,fullSim)
#TopExamples.grid.submit(config,extra)
config.settingsFile = 'generic_config-mc15-Sys_fastSim.txt'
#TopExamples.grid.submit(config,fastSim)
#TopExamples.grid.submit(config,noCFT_ttbar_fastSim)

config.suffix       = '2017-06-09.Sys_v29_CFT_skim'
config.settingsFile = 'generic_config-mc15-Sys_CFT.txt'
#TopExamples.grid.submit(config,fullSim)
#TopExamples.grid.submit(config,extra)
config.settingsFile = 'generic_config-mc15-Sys_CFT_fastSim.txt'
#TopExamples.grid.submit(config,fastSim)
#TopExamples.grid.submit(config,CFT_ttbar_fastSim)

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
# print list of all datasets
def printSampleList():
    for name, ds in  TopExamples.grid.AvailableDatasets().iteritems():
        print "set:",name
        for ds_name in  ds.datasets:
            print ds_name

printSampleList()

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
