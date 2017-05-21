import TopExamples.grid
import TopExamples.analysis
import os

#FULL SIM
TopExamples.grid.Add('All_fullSim').datasets = [
'mc15_13TeV.341998.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus1.merge.AOD.e4394_s2608_r7772_r7676',
'mc15_13TeV.342170.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_dilep.merge.AOD.e4273_s2608_r7772_r7676',
'mc15_13TeV.344423.Sherpa_CT10_llll_BVeto.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.361067.Sherpa_CT10_lllvOFPlus.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361069.Sherpa_CT10_llvvjj_ss_EW4.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361071.Sherpa_CT10_lllvjj_EW6.merge.AOD.e3836_s2726_r7772_r7676',
'mc15_13TeV.361091.Sherpa_CT10_WplvWmqq_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361620.Sherpa_CT10_WWW_3l3v.merge.AOD.e4093_s2608_s2183_r8112_r7676',
'mc15_13TeV.361623.Sherpa_CT10_WZZ_5l1v.merge.AOD.e4093_s2608_s2183_r8112_r7676',
'mc15_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364162.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364163.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364184.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364187.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364189.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364196.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV500_1000.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364207.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.410049.MadGraphPythiaEvtGen_P2012_tZ_4fl_tchan_trilepton.merge.AOD.e4440_s2608_r7725_r7676',
'mc15_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.merge.AOD.e5070_s2726_r7772_r7676',
]

TopExamples.grid.Add('ttbar_fullSim').datasets = [
'mc15_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.merge.AOD.e5458_s2726_r7772_r7676',
]

TopExamples.grid.Add('All_fastSim').datasets = [
'mc15_13TeV.344133.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10nlo_hh_4w_wplep.merge.AOD.e5060_a766_a821_r7676',
'mc15_13TeV.344134.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10nlo_hh_4w_wmlep.merge.AOD.e5060_a766_a821_r7676',
'mc15_13TeV.344364.CalcHepPythia8_A14_CTEQ6L1_HppHmm_500GeV_4W.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344365.CalcHepPythia8_A14_CTEQ6L1_HppHmm_600GeV_4W.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344366.CalcHepPythia8_A14_CTEQ6L1_HppHmm_700GeV_4W.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344367.CalcHepPythia8_A14_CTEQ6L1_HppmmHmp_200GeV.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344368.CalcHepPythia8_A14_CTEQ6L1_HppmmHmp_300GeV.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344369.CalcHepPythia8_A14_CTEQ6L1_HppmmHmp_400GeV.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.410142.Sherpa_NNPDF30NNLO_ttll_mll5.merge.AOD.e4686_a766_a818_r7676',
'mc15_13TeV.410143.Sherpa_NNPDF30NNLO_ttZnnqq.merge.AOD.e4686_a766_a818_r7676',
'mc15_13TeV.410144.Sherpa_NNPDF30NNLO_ttW.merge.AOD.e4686_a766_a818_r7676',
]

TopExamples.grid.Add('ttbar_fastSim').datasets = [
'mc15_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.merge.AOD.e5458_a766_a821_r7676',
'mc15_13TeV.410225.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttbar_nonallhad.merge.AOD.e5465_a766_a821_r7676',
]
