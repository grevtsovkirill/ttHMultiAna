import TopExamples.grid
import TopExamples.analysis
import os

#FULL SIM
TopExamples.grid.Add('All_fullSim').datasets = [

#ttH NLO
'mc15_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.merge.AOD.e4706_s2726_r7772_r7676',
'mc15_13TeV.343366.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_semilep.merge.AOD.e4706_s2726_r7772_r7676',
'mc15_13TeV.343367.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_allhad.merge.AOD.e4706_s2726_r7772_r7676',

#ttH herwig (alternative)
'mc15_13TeV.341177.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_dil.merge.AOD.e4277_s2608_s2183_r7772_r7676',
'mc15_13TeV.341270.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_semilep.merge.AOD.e4277_s2608_s2183_r7772_r7676',
'mc15_13TeV.341271.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_allhad.merge.AOD.e4277_s2608_s2183_r7772_r7676',

#ttH HtoZZto4L
'mc15_13TeV.342561.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_4l.merge.AOD.e4540_s2726_r7772_r7676'

#ttH HtoGamGam
'mc15_13TeV.343436.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_gamgam.merge.AOD.e4704_s2726_r7772_r7676',

#ttH Hto2tau
'mc15_13TeV.342170.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_dilep.merge.AOD.e4273_s2608_r7772_r7676',
'mc15_13TeV.342171.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_semilep.merge.AOD.e4273_s2608_r7772_r7676',
'mc15_13TeV.342172.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_allhad.merge.AOD.e4273_s2608_r7772_r7676',

#tHjb and WtH
'mc15_13TeV.341998.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus1.merge.AOD.e4394_s2608_r7772_r7676',
'mc15_13TeV.342001.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus1.merge.AOD.e4394_s2608_r7772_r7676',
'mc15_13TeV.342004.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_plus1.merge.AOD.e4394_s2608_r7772_r7676',
'mc15_13TeV.343267.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_gamgam.merge.AOD.e4606_s2726_r7772_r7676',
'mc15_13TeV.343270.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_bbbar.merge.AOD.e4610_s2726_r7772_r7676',
'mc15_13TeV.343273.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_lep.merge.AOD.e4606_s2726_r7772_r7676',

#Other Higgs ggH, VBFH, WH, ZH, HH
'mc15_13TeV.341471.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_ZZ4lep.merge.AOD.e3951_s2608_s2183_r7772_r7676',
'mc15_13TeV.341488.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_ZZ4lep.merge.AOD.e3951_s2608_s2183_r7772_r7676',
'mc15_13TeV.342282.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_inc.merge.AOD.e4246_s2608_s2183_r7772_r7676',
'mc15_13TeV.342283.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_inc.merge.AOD.e4246_s2608_s2183_r7772_r7676',
'mc15_13TeV.342284.Pythia8EvtGen_A14NNPDF23LO_WH125_inc.merge.AOD.e4246_s2608_s2183_r7772_r7676',
'mc15_13TeV.342285.Pythia8EvtGen_A14NNPDF23LO_ZH125_inc.merge.AOD.e4246_s2608_s2183_r7772_r7676',

#ttV NLO
'mc15_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.merge.AOD.e5070_s2726_r7772_r7676',
'mc15_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.merge.AOD.e5070_s2726_r7772_r7676',

#tZ
#>= 3L
'mc15_13TeV.410049.MadGraphPythiaEvtGen_P2012_tZ_4fl_tchan_trilepton.merge.AOD.e4440_s2608_r7725_r7676',
#2L
'mc15_13TeV.410050.MadGraphPythiaEvtGen_P2012_tZ_4fl_tchan_noAllHad.merge.AOD.e4279_s2608_s2183_r7725_r7676',

#WtZ
'mc15_13TeV.410215.aMcAtNloPythia8EvtGen_A14_NNPDF23LO_260000_tWZDR.merge.AOD.e4851_s2726_r7725_r7676',

#4Tops, ttWW
'mc15_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.merge.AOD.e4111_s2608_s2183_r7725_r7676',
'mc15_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.merge.AOD.e4111_s2608_s2183_r7725_r7676',

#Diboson
'mc15_13TeV.361063.Sherpa_CT10_llll.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361064.Sherpa_CT10_lllvSFMinus.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361065.Sherpa_CT10_lllvOFMinus.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361066.Sherpa_CT10_lllvSFPlus.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361067.Sherpa_CT10_lllvOFPlus.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361068.Sherpa_CT10_llvv.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361069.Sherpa_CT10_llvvjj_ss_EW4.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361070.Sherpa_CT10_llvvjj_ss_EW6.merge.AOD.e3836_s2608_s2183_r7725_r7676',
'mc15_13TeV.361071.Sherpa_CT10_lllvjj_EW6.merge.AOD.e3836_s2726_r7772_r7676',
'mc15_13TeV.361072.Sherpa_CT10_lllljj_EW6.merge.AOD.e3836_s2608_s2183_r7772_r7676',
'mc15_13TeV.361073.Sherpa_CT10_ggllll.merge.AOD.e3836_s2608_s2183_r7772_r7676',
'mc15_13TeV.361077.Sherpa_CT10_ggllvv.merge.AOD.e3836_s2608_s2183_r7772_r7676',
'mc15_13TeV.361088.Sherpa_CT10_lvvv.merge.AOD.e4483_s2726_r7772_r7676',
'mc15_13TeV.361089.Sherpa_CT10_vvvv.merge.AOD.e4483_s2726_r7772_r7676',
'mc15_13TeV.361091.Sherpa_CT10_WplvWmqq_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361092.Sherpa_CT10_WpqqWmlv_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361093.Sherpa_CT10_WlvZqq_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361094.Sherpa_CT10_WqqZll_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361095.Sherpa_CT10_WqqZvv_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361096.Sherpa_CT10_ZqqZll_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',
'mc15_13TeV.361097.Sherpa_CT10_ZqqZvv_SHv21_improved.merge.AOD.e4607_s2726_r7772_r7676',

#Diboson b-filter Sherpa for 4l
'mc15_13TeV.344422.Sherpa_CT10_llll_BFilter.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344423.Sherpa_CT10_llll_BVeto.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344424.Sherpa_CT10_lllvSFMinus_BFilter.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344425.Sherpa_CT10_lllvSFMinus_BVeto.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344426.Sherpa_CT10_lllvOFMinus_BFilter.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344427.Sherpa_CT10_lllvOFMinus_BVeto.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344428.Sherpa_CT10_lllvSFPlus_BFilter.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344429.Sherpa_CT10_lllvSFPlus_BVeto.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344430.Sherpa_CT10_lllvOFPlus_BFilter.merge.AOD.e5210_s2726_r7772_r7676',
'mc15_13TeV.344431.Sherpa_CT10_lllvOFPlus_BVeto.merge.AOD.e5210_s2726_r7772_r7676',

#Triboson
'mc15_13TeV.361620.Sherpa_CT10_WWW_3l3v.merge.AOD.e4093_s2608_s2183_r8112_r7676',
'mc15_13TeV.361621.Sherpa_CT10_WWZ_4l2v.merge.AOD.e4053_s2608_s2183_r8112_r7676',
'mc15_13TeV.361622.Sherpa_CT10_WWZ_2l4v.merge.AOD.e4053_s2608_s2183_r8112_r7676',
'mc15_13TeV.361623.Sherpa_CT10_WZZ_5l1v.merge.AOD.e4093_s2608_s2183_r8112_r7676',
'mc15_13TeV.361624.Sherpa_CT10_WZZ_3l3v.merge.AOD.e4093_s2608_s2183_r8112_r7676',
'mc15_13TeV.361625.Sherpa_CT10_ZZZ_6l0v.merge.AOD.e4093_s2608_s2183_r7772_r7676',
'mc15_13TeV.361626.Sherpa_CT10_ZZZ_4l2v.merge.AOD.e4093_s2608_s2183_r7772_r7676',
'mc15_13TeV.361627.Sherpa_CT10_ZZZ_2l4v.merge.AOD.e4093_s2608_s2183_r7772_r7676',

#ttgamma
'mc15_13TeV.410082.MadGraphPythia8EvtGen_A14NNPDF23LO_ttgamma_noallhad.merge.AOD.e4404_s2726_r7772_r7676',

#Single top
'mc15_13TeV.410011.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_top.merge.AOD.e3824_s2608_s2183_r7725_r7676',
'mc15_13TeV.410012.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_antitop.merge.AOD.e3824_s2608_s2183_r7725_r7676',
'mc15_13TeV.410013.PowhegPythiaEvtGen_P2012_Wt_inclusive_top.merge.AOD.e3753_s2608_s2183_r7725_r7676',
'mc15_13TeV.410014.PowhegPythiaEvtGen_P2012_Wt_inclusive_antitop.merge.AOD.e3753_s2608_s2183_r7725_r7676',
'mc15_13TeV.410015.PowhegPythiaEvtGen_P2012_Wt_dilepton_top.merge.AOD.e3753_s2608_s2183_r7725_r7676',
'mc15_13TeV.410016.PowhegPythiaEvtGen_P2012_Wt_dilepton_antitop.merge.AOD.e3753_s2608_s2183_r7725_r7676',
'mc15_13TeV.410025.PowhegPythiaEvtGen_P2012_SingleTopSchan_noAllHad_top.merge.AOD.e3998_s2608_s2183_r7725_r7676',
'mc15_13TeV.410026.PowhegPythiaEvtGen_P2012_SingleTopSchan_noAllHad_antitop.merge.AOD.e3998_s2608_s2183_r7725_r7676',
]

TopExamples.grid.Add('ttbar_fullSim').datasets = [

#ttbar 2L
'mc15_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.merge.AOD.e5458_s2726_r7772_r7676',

#ttbar 3L
'mc15_13TeV.410503.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_dil.merge.AOD.e5475_s2726_r7772_r7676',
'mc15_13TeV.410250.Sherpa_221_NNPDF30NNLO_ttbar_SingleLeptonP_MEPS_NLO.merge.AOD.e5450_s2726_r7772_r7676',
'mc15_13TeV.410251.Sherpa_221_NNPDF30NNLO_ttbar_SingleLeptonM_MEPS_NLO.merge.AOD.e5450_s2726_r7772_r7676',
'mc15_13TeV.410252.Sherpa_221_NNPDF30NNLO_ttbar_dilepton_MEPS_NLO.merge.AOD.e5450_s2726_r7772_r7676',
]

#FASTSIM
TopExamples.grid.Add('All_fastSim').datasets = [
#3tops
'mc15_13TeV.304014.MadGraphPythia8EvtGen_A14NNPDF23_3top_SM.merge.AOD.e4324_a766_a818_r7676',

#Other Higgs ggH, VBFH, WH, ZH, HH
'mc15_13TeV.344133.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10nlo_hh_4w_wplep.merge.AOD.e5060_a766_a821_r7676',
'mc15_13TeV.344134.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10nlo_hh_4w_wmlep.merge.AOD.e5060_a766_a821_r7676',

#BSM HppHmm
'mc15_13TeV.344364.CalcHepPythia8_A14_CTEQ6L1_HppHmm_500GeV_4W.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344365.CalcHepPythia8_A14_CTEQ6L1_HppHmm_600GeV_4W.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344366.CalcHepPythia8_A14_CTEQ6L1_HppHmm_700GeV_4W.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344367.CalcHepPythia8_A14_CTEQ6L1_HppmmHmp_200GeV.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344368.CalcHepPythia8_A14_CTEQ6L1_HppmmHmp_300GeV.merge.AOD.e5207_a766_a821_r7676',
'mc15_13TeV.344369.CalcHepPythia8_A14_CTEQ6L1_HppmmHmp_400GeV.merge.AOD.e5207_a766_a821_r7676',

#ttV (nominal)
'mc15_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.merge.AOD.e5070_a766_a821_r7676',
'mc15_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.merge.AOD.e5070_a766_a821_r7676',
'mc15_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.merge.AOD.e5070_a766_a821_r7676',
'mc15_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.merge.AOD.e5070_a766_a821_r7676',
'mc15_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.merge.AOD.e5070_a766_a821_r7676',
'mc15_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.merge.AOD.e5070_a766_a821_r7676',

#ttV (alternative)
'mc15_13TeV.410142.Sherpa_NNPDF30NNLO_ttll_mll5.merge.AOD.e4686_a766_a818_r7676',
'mc15_13TeV.410143.Sherpa_NNPDF30NNLO_ttZnnqq.merge.AOD.e4686_a766_a818_r7676',
'mc15_13TeV.410144.Sherpa_NNPDF30NNLO_ttW.merge.AOD.e4686_a766_a818_r7676',
]

TopExamples.grid.Add('ttbar_fastSim').datasets = [
#ttbar 2L
'mc15_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.merge.AOD.e5458_a766_a821_r7676',

#ttbar 3L
'mc15_13TeV.410503.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_dil.merge.AOD.e5475_a766_a821_r7676',

#ttbar alternative
'mc15_13TeV.410511.PowhegPythia8EvtGen_A14v3cUp_ttbar_hdamp517p5_nonallhad.merge.AOD.e5556_a766_a821_r7676',
'mc15_13TeV.410512.PowhegPythia8EvtGen_A14v3cDo_ttbar_hdamp258p75_nonallhad.merge.AOD.e5556_a766_a821_r7676',
#2L
'mc15_13TeV.410225.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttbar_nonallhad.merge.AOD.e5465_a766_a821_r7676',
#3L
'mc15_13TeV.410226.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttbar_dil.merge.AOD.e5465_a766_a821_r7676',
]

#FULLSIM VJETS
TopExamples.grid.Add('VJets_fullSim').datasets = [

#Z+Jets
'mc15_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.merge.AOD.e5271_s2726_r7772_r7676',
'mc15_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.merge.AOD.e5299_s2726_r7772_r7676',
'mc15_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.merge.AOD.e5313_s2726_r7772_r7676',
'mc15_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.merge.AOD.e5313_s2726_r7772_r7676',
'mc15_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.merge.AOD.e5307_s2726_r7772_r7676',
'mc15_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.merge.AOD.e5307_s2726_r7772_r7676',

#Low Mass ZJets
'mc15_13TeV.364198.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364199.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364200.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364201.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364202.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364203.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364204.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364205.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364206.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364207.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364208.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364209.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364210.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364211.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364212.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364213.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BFilter.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364214.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BVeto.merge.AOD.e5421_s2726_r7772_r7676',
'mc15_13TeV.364215.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BFilter.merge.AOD.e5421_s2726_r7772_r7676',

# W+jets
'mc15_13TeV.364156.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364157.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364158.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364159.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364160.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364161.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364162.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364163.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364164.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364165.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364166.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364167.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364168.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV500_1000.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364169.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV1000_E_CMS.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364170.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364171.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364172.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364173.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364174.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364175.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364176.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364177.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364178.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364179.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364180.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364181.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364182.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV500_1000.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364183.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV1000_E_CMS.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364184.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364185.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364186.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364187.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364188.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364189.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364190.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364191.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364192.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364193.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CVetoBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364194.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CFilterBVeto.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364195.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_BFilter.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364196.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV500_1000.merge.AOD.e5340_s2726_r7772_r7676',
'mc15_13TeV.364197.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV1000_E_CMS.merge.AOD.e5340_s2726_r7772_r7676',

#V+gamma
'mc15_13TeV.301535.Sherpa_CT10_eegammaPt10_35.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301536.Sherpa_CT10_mumugammaPt10_35.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301887.Sherpa_CT10_enugammaPt10_35.merge.AOD.e4452_s2726_r7725_r7676',
'mc15_13TeV.301888.Sherpa_CT10_munugammaPt10_35.merge.AOD.e4452_s2608_s2183_r7725_r7676',
'mc15_13TeV.301889.Sherpa_CT10_taunugammaPt10_35.merge.AOD.e4452_s2608_s2183_r7725_r7676',
'mc15_13TeV.301890.Sherpa_CT10_enugammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301891.Sherpa_CT10_enugammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301892.Sherpa_CT10_enugammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301893.Sherpa_CT10_munugammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301894.Sherpa_CT10_munugammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301895.Sherpa_CT10_munugammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301896.Sherpa_CT10_taunugammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301897.Sherpa_CT10_taunugammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301898.Sherpa_CT10_taunugammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301899.Sherpa_CT10_eegammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301900.Sherpa_CT10_eegammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301901.Sherpa_CT10_eegammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301902.Sherpa_CT10_mumugammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301903.Sherpa_CT10_mumugammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301904.Sherpa_CT10_mumugammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301905.Sherpa_CT10_tautaugammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301906.Sherpa_CT10_tautaugammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301907.Sherpa_CT10_tautaugammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301908.Sherpa_CT10_nunugammaPt35_70.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301909.Sherpa_CT10_nunugammaPt70_140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.301910.Sherpa_CT10_nunugammaPt140.merge.AOD.e3952_s2608_s2183_r7725_r7676',
'mc15_13TeV.343243.Sherpa_CT10_tautaugammaPt10_35.merge.AOD.e4759_s2726_r7725_r7676',
'mc15_13TeV.304776.Sherpa_CT10_tautaugammaPt10_35.merge.AOD.e4687_s2726_r7725_r7676',
]

noShowerDatasets = []
tdp = TopExamples.analysis.TopDataPreparation(os.getenv('ROOTCOREBIN') + '/data/TopDataPreparation/XSection-MC15-13TeV.data')
for TopSample in TopExamples.grid.availableDatasets.values():
    for sample in TopSample.datasets:
        dsid = sample.split('.')[1]
        dsid = int(dsid)
        #print tdp.hasID(dsid), tdp.getShower(dsid)
        hasShower = tdp.getShower(dsid) in ['sherpa','sherpa21','pythia','pythia8','herwigpp']
        if not tdp.hasID(dsid) or not hasShower:
            noShowerDatasets += [dsid]

if len(noShowerDatasets) > 0:
    print 'The following datasets dont have a showering algorithm defined in TopDataPreparation and will fail on the grid.'
    for ds in set(noShowerDatasets):
        print ds
    raise RuntimeError("Datasets without shower.")

# for sys_ datasets collections use only (all) signal and all priority-1 background samples
xsecfile1 = open(os.getenv('ROOTCOREBIN') + '/../ttHMultilepton/util/Xsection13TeV_tth_bkg_v1.txt')
xsecfile2 = open(os.getenv('ROOTCOREBIN') + '/../ttHMultilepton/util/Xsection13TeV_tth_sig_v1.txt')
contentBkg = xsecfile1.readlines()
contentSig = xsecfile2.readlines()
if os.path.isfile(os.getenv('ROOTCOREBIN') + '/../ttHMultilepton/scripts/files_done.txt'):
    donefile = open(os.getenv('ROOTCOREBIN') + '/../ttHMultilepton/scripts/files_done.txt')
    contentDone = donefile.readlines()
else:
    contentDone = ''
sys_fullSim = []
sys_fastSim = []
for TopSample in TopExamples.grid.availableDatasets.values():
    for sample in TopSample.datasets:
        dsid = sample.split('.')[1]
        fastSim = "_a766" in sample
        lineBkg = [line for line in contentBkg if dsid in line]
        lineSig = [line for line in contentSig if dsid in line]
        lineDone = [line for line in contentDone if dsid in line]
        line = lineBkg + lineSig
        if len(line) != 1:
            print "WARNING: dsid " + dsid + " has " + str(len(line)) + " matches in Xsection13TeV_tth_*_v1.txt"
            priority = '1'
        else:
            priority = line[0].split()[6]
        if (priority == '1' or len(lineSig) == 1) and len(lineDone) == 0:
            if fastSim:
                sys_fastSim.append(sample)
            else:
                sys_fullSim.append(sample)
TopExamples.grid.Add('sys_fullSim').datasets = sys_fullSim
TopExamples.grid.Add('sys_fastSim').datasets = sys_fastSim
