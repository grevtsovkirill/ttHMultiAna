# Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration

#!/usr/bin/env python
import sys
include("MuonEfficiencyCorrections/CommonToolSetup.py")

# a simple testing macro for the MuonEfficiencyCorrections_xAOD package in athena
#
# Usage: athena --filesInput <InputFile> MuonEfficiencyCorrections/MuonEfficiencyCorrections_xAOD_Testing_jobOptions.py

# Access the algorithm sequence:
AssembleIO("MUONEFFTESTER")
from AthenaCommon.AlgSequence import AlgSequence
theJob = AlgSequence()

# Add the test algorithm:
from MuonEfficiencyCorrections.MuonEfficiencyCorrectionsConf import CP__MuonEfficiencyCorrections_TestAlg
alg = CP__MuonEfficiencyCorrections_TestAlg("EffiTestAlg")
alg.PileupReweightingTool = GetPRWTool()
alg.DefaultRelease="cPreRecs"
alg.ValidationRelease="cCaloFix"

WPs = [
         # reconstruction WPs
        # "LowPt",
        # "Loose", 
        # "Medium", 
        # "Tight", 
        # "HighPt",
         # track-to-vertex-association WPs
         "TTVA",
         # BadMuon veto SFs
        # "BadMuonVeto_HighPt",
         # isolation WPs
        # "FixedCutLooseIso", "LooseTrackOnlyIso", "LooseIso", "GradientIso", "GradientLooseIso",
        # "FixedCutTightTrackOnlyIso", "FixedCutHighPtTrackOnlyIso", "FixedCutTightIso"
        ]

for WP in WPs: 
    alg.EfficiencyTools += [GetMuonEfficiencyTool(WP, Release = "170916_Rel21PreRec")]
    alg.EfficiencyToolsForComparison += [GetMuonEfficiencyTool(WP, Release="CaloTest", CustomInput = "/afs/cern.ch/user/j/jojungge/public/MCP/ScaleFactorFiles/180516_HighEtaUpdate")]
theJob += alg

# Do some additional tweaking:
from AthenaCommon.AppMgr import theApp
#theApp.EvtMax = 200

#ServiceMgr.MessageSvc.OutputLevel = INFO
#ServiceMgr.MessageSvc.defaultLimit = 100
