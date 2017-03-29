#!/bin/sh
echo "Setting up all the things"

#lsetup knows in which order to do these

lsetup "rcsetup Top,2.4.29" panda rucio pyami
#voms-proxy-init -voms atlas:/atlas/phys-higgs/Role=production -out ${HOME}/.globus/gridproxy.cert -valid 24:0
#export X509_USER_PROXY=${HOME}/.globus/gridproxy.cert

# for bad electrons in HIGG8D1 with no matched clusters (e.g. run 302872)
rc checkout_pkg $(rc version | grep TopObjectSelectionTools)
sed -i 's/\/\/This stops a crash/if (!(el.caloCluster())) return false;/' TopObjectSelectionTools/Root/ElectronLikelihoodMC15.cxx

#new tau ele bdt
rc checkout_pkg atlasoff/PhysicsAnalysis/TauID/TauAnalysisTools/tags/TauAnalysisTools-00-02-48

#save sum of weights for all LHE3 variations
rc checkout_pkg TopAnalysis
patch -d TopAnalysis -p0 < ttHMultilepton/LHEweights.patch


rc build

echo "Alright - done."

pushd .
cd ttHMultilepton/share
# temporary 60% b-tagging WP not working properly with newest cdi file
sed -i 's/ FixedCutBEff_60//g' generic_config-*.txt
# for Sys splitting
sed 's/Systematics All/Systematics JET_21NP_JET_EffectiveNP_1__1down,JET_21NP_JET_EffectiveNP_1__1up,JET_21NP_JET_EffectiveNP_2__1down,JET_21NP_JET_EffectiveNP_2__1up,JET_21NP_JET_EffectiveNP_3__1down,JET_21NP_JET_EffectiveNP_3__1up,JET_21NP_JET_EffectiveNP_4__1down,JET_21NP_JET_EffectiveNP_4__1up,JET_21NP_JET_EffectiveNP_5__1down,JET_21NP_JET_EffectiveNP_5__1up,JET_21NP_JET_EffectiveNP_6__1down,JET_21NP_JET_EffectiveNP_6__1up,JET_21NP_JET_EffectiveNP_7__1down,JET_21NP_JET_EffectiveNP_7__1up,JET_21NP_JET_EffectiveNP_8restTerm__1down,JET_21NP_JET_EffectiveNP_8restTerm__1up,JET_21NP_JET_PunchThrough_MC15__1down,JET_21NP_JET_PunchThrough_MC15__1up,JET_21NP_JET_SingleParticle_HighPt__1down,JET_21NP_JET_SingleParticle_HighPt__1up/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys-Jets1.txt
sed 's/Systematics All/Systematics JET_21NP_JET_BJES_Response__1down,JET_21NP_JET_BJES_Response__1up,JET_21NP_JET_EtaIntercalibration_Modelling__1down,JET_21NP_JET_EtaIntercalibration_Modelling__1up,JET_21NP_JET_EtaIntercalibration_NonClosure__1down,JET_21NP_JET_EtaIntercalibration_NonClosure__1up,JET_21NP_JET_EtaIntercalibration_TotalStat__1down,JET_21NP_JET_EtaIntercalibration_TotalStat__1up,JET_21NP_JET_Flavor_Composition__1down,JET_21NP_JET_Flavor_Composition__1up,JET_21NP_JET_Flavor_Response__1down,JET_21NP_JET_Flavor_Response__1up,JET_21NP_JET_Pileup_OffsetMu__1down,JET_21NP_JET_Pileup_OffsetMu__1up,JET_21NP_JET_Pileup_OffsetNPV__1down,JET_21NP_JET_Pileup_OffsetNPV__1up,JET_21NP_JET_Pileup_PtTerm__1down,JET_21NP_JET_Pileup_PtTerm__1up,JET_21NP_JET_Pileup_RhoTopology__1down,JET_21NP_JET_Pileup_RhoTopology__1up,JET_JER_SINGLE_NP__1up/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys-Jets2.txt
sed 's/Systematics All/Systematics AllMuons,AllElectrons,AllTaus,MET_SoftTrk_ResoPara,MET_SoftTrk_ResoPerp,MET_SoftTrk_ScaleDown,MET_SoftTrk_ScaleUp/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys-Other.txt
# for fastSim samples
sed 's/IsAFII False/IsAFII True/' generic_config-mc15.txt > generic_config-mc15_fastSim.txt
sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys.txt > generic_config-mc15-Sys_fastSim.txt
sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys-Jets1.txt > generic_config-mc15-Sys-Jets1_fastSim.txt
sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys-Jets2.txt > generic_config-mc15-Sys-Jets2_fastSim.txt
sed 's/IsAFII False/IsAFII True/' generic_config-mc15-Sys-Other.txt > generic_config-mc15-Sys-Other_fastSim.txt
#python ttHMultilepton/scripts/01SubmitToGrid.py


popd
