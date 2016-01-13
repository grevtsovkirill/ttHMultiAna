import TopExamples.grid

#For your info print them to the screen
#for ds in sorted(TopExamples.grid.listDatasets('mc15_13TeV', '*410000*.AOD.*r6264')):
#    print ds

#use with p2501
TopExamples.grid.Add('systematic_production').datasets = [
#ttV
'mc15_13TeV.410073.MadGraphPythia8EvtGen_A14NNPDF23LO_ttZnnqq_Np0.merge.AOD.e4631_s2726_r7326_r6282',
'mc15_13TeV.410074.MadGraphPythia8EvtGen_A14NNPDF23LO_ttZnnqq_Np1.merge.AOD.e4631_s2726_r7326_r6282',
'mc15_13TeV.410075.MadGraphPythia8EvtGen_A14NNPDF23LO_ttZnnqq_Np2.merge.AOD.e4631_s2726_r7326_r6282',
'mc15_13TeV.410111.MadGraphPythia8EvtGen_A14NNPDF23LO_ttee_Np0.merge.AOD.e4632_s2726_r7326_r6282',
'mc15_13TeV.410112.MadGraphPythia8EvtGen_A14NNPDF23LO_ttee_Np1.merge.AOD.e4632_s2726_r7326_r6282',
'mc15_13TeV.410113.MadGraphPythia8EvtGen_A14NNPDF23LO_ttmumu_Np0.merge.AOD.e4632_s2726_r7326_r6282',
'mc15_13TeV.410114.MadGraphPythia8EvtGen_A14NNPDF23LO_ttmumu_Np1.merge.AOD.e4632_s2726_r7326_r6282',
'mc15_13TeV.410115.MadGraphPythia8EvtGen_A14NNPDF23LO_tttautau_Np0.merge.AOD.e4632_s2726_r7326_r6282',
'mc15_13TeV.410116.MadGraphPythia8EvtGen_A14NNPDF23LO_tttautau_Np1.merge.AOD.e4632_s2726_r7326_r6282',

#top
'mc15_13TeV.410011.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_top.merge.AOD.e3824_s2608_s2183_r7326_r6282',
'mc15_13TeV.410012.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_antitop.merge.AOD.e3824_s2608_s2183_r7326_r6282',
'mc15_13TeV.410013.PowhegPythiaEvtGen_P2012_Wt_inclusive_top.merge.AOD.e3753_s2608_s2183_r7326_r6282',
'mc15_13TeV.410014.PowhegPythiaEvtGen_P2012_Wt_inclusive_antitop.merge.AOD.e3753_s2608_s2183_r7326_r6282',

#diboson
'mc15_13TeV.361063.Sherpa_CT10_llll.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361064.Sherpa_CT10_lllvSFMinus.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361065.Sherpa_CT10_lllvOFMinus.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361066.Sherpa_CT10_lllvSFPlus.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361067.Sherpa_CT10_lllvOFPlus.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361068.Sherpa_CT10_llvv.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361069.Sherpa_CT10_llvvjj_ss_EW4.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361070.Sherpa_CT10_llvvjj_ss_EW6.merge.AOD.e3836_s2608_s2183_r7267_r6282',
'mc15_13TeV.361078.Sherpa_CT10_ggllvvNoHiggs.merge.AOD.e4641_s2726_r7326_r6282',
'mc15_13TeV.361084.Sherpa_CT10_WqqZll.merge.AOD.e3836_s2608_s2183_r7326_r6282',
'mc15_13TeV.361086.Sherpa_CT10_ZqqZll.merge.AOD.e3926_s2608_s2183_r7326_r6282',

#tH, WtH, tZ
'mc15_13TeV.341988.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_gamgam.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341989.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_gamgam.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341990.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_gamgam.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341991.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_bbbar.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341992.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_bbbar.merge.AOD.e4610_s2726_r7267_r6282',
'mc15_13TeV.341993.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_bbbar.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341994.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_lep.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341995.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_lep.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.341996.MadGraphHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_tHjb125_lep.merge.AOD.e4606_s2726_r7267_r6282',
'mc15_13TeV.410049.MadGraphPythiaEvtGen_P2012_tZ_4fl_tchan_trilepton.merge.AOD.e4440_s2608_r7326_r6282',
'mc15_13TeV.410050.MadGraphPythiaEvtGen_P2012_tZ_4fl_tchan_noAllHad.merge.AOD.e4279_s2608_s2183_r7326_r6282',
]

TopExamples.grid.Add('systematic_production_high_efficiency').datasets = [
#ttH
'mc15_13TeV.341177.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_dil.merge.AOD.e4277_s2608_s2183_r6869_r6282',
'mc15_13TeV.341270.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_semilep.merge.AOD.e4277_s2608_s2183_r6869_r6282',
'mc15_13TeV.341271.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_allhad.merge.AOD.e4277_s2608_s2183_r6869_r6282',
'mc15_13TeV.342170.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_dilep.merge.AOD.e4273_s2608_r6869_r6282',
'mc15_13TeV.342171.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_semilep.merge.AOD.e4273_s2608_r6869_r6282',
'mc15_13TeV.342172.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_allhad.merge.AOD.e4273_s2608_r6869_r6282',

#top
'mc15_13TeV.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.merge.AOD.e3698_s2608_s2183_r7267_r6282',
'mc15_13TeV.410009.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_dil.merge.AOD.e4511_s2608_s2183_r7326_r6282',
]

#use with p2434
TopExamples.grid.Add('systematic_production_diboson_mc15a').datasets = [
'mc15_13TeV.361071.Sherpa_CT10_lllvjj_EW6.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361072.Sherpa_CT10_lllljj_EW6.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361073.Sherpa_CT10_ggllll.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361077.Sherpa_CT10_ggllvv.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361079.Sherpa_CT10_ggllvvOnlyHiggs.merge.AOD.e3911_s2608_s2183_r6869_r6282',
'mc15_13TeV.361081.Sherpa_CT10_WplvWmqq.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361082.Sherpa_CT10_WpqqWmlv.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361083.Sherpa_CT10_WlvZqq.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361085.Sherpa_CT10_WqqZvv.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361087.Sherpa_CT10_ZqqZvv.merge.AOD.e3926_s2608_s2183_r6869_r6282',
]


################################################################################################################
#below is just for knowing which samples need PRW
#need PRW configs for these
TopExamples.grid.Add('systematic_production_mc15a').datasets = [
#ttV
'mc15_13TeV.410066.MadGraphPythia8EvtGen_A14NNPDF23LO_ttW_Np0.merge.AOD.e4111_s2608_s2183_r6869_r6282',
'mc15_13TeV.410067.MadGraphPythia8EvtGen_A14NNPDF23LO_ttW_Np1.merge.AOD.e4111_s2608_s2183_r6869_r6282',
'mc15_13TeV.410068.MadGraphPythia8EvtGen_A14NNPDF23LO_ttW_Np2.merge.AOD.e4111_s2608_s2183_r6869_r6282',
'mc15_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.merge.AOD.e4111_s2608_s2183_r6869_r6282',
'mc15_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.merge.AOD.e4111_s2608_s2183_r6869_r6282',
    
#tH, WtH, tZ
'mc15_13TeV.341997.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_minus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.341998.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.341999.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus2.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342000.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_minus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342001.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342002.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus2.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342003.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_minus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342004.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_plus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342005.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_plus2.merge.AOD.e4394_s2608_r6869_r6282',

#diboson
'mc15_13TeV.361071.Sherpa_CT10_lllvjj_EW6.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361072.Sherpa_CT10_lllljj_EW6.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361073.Sherpa_CT10_ggllll.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361077.Sherpa_CT10_ggllvv.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361079.Sherpa_CT10_ggllvvOnlyHiggs.merge.AOD.e3911_s2608_s2183_r6869_r6282',
'mc15_13TeV.361081.Sherpa_CT10_WplvWmqq.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361082.Sherpa_CT10_WpqqWmlv.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361083.Sherpa_CT10_WlvZqq.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361085.Sherpa_CT10_WqqZvv.merge.AOD.e3836_s2608_s2183_r6869_r6282',
'mc15_13TeV.361087.Sherpa_CT10_ZqqZvv.merge.AOD.e3926_s2608_s2183_r6869_r6282',
]


TopExamples.grid.Add('pileup_reweighting_mc15a').datasets = [
#ttH tautau
'mc15_13TeV.342170.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_dilep.merge.AOD.e4273_s2608_r6869_r6282',
'mc15_13TeV.342171.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_semilep.merge.AOD.e4273_s2608_r6869_r6282',
'mc15_13TeV.342172.aMcAtNloHppEG_UE5_C6L1_CT10ME_ttH125_H2tau_allhad.merge.AOD.e4273_s2608_r6869_r6282',
#tH, WtH, tZ
'mc15_13TeV.341997.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_minus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.341998.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.341999.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus2.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342000.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_minus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342001.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342002.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus2.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342003.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_minus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342004.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_plus1.merge.AOD.e4394_s2608_r6869_r6282',
'mc15_13TeV.342005.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_plus2.merge.AOD.e4394_s2608_r6869_r6282',
]

TopExamples.grid.Add('ttbar_dilep').datasets = [
'mc15_13TeV.410009.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_dil.merge.DAOD_HIGG8D1.e4511_s2608_s2183_r7326_r6282_p2501'
]
