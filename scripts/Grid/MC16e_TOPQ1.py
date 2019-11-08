# Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
import TopExamples.ami
import TopExamples.grid
import grid

grid.Add("TOPQ1_ttbar_ht").datasets = [
    'mc16_13TeV.407342.PhPy8EG_A14_ttbarHT1k5_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6414_s3126_r10724_p3832',
    'mc16_13TeV.407343.PhPy8EG_A14_ttbarHT1k_1k5_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6414_s3126_r10724_p3832',
    'mc16_13TeV.407344.PhPy8EG_A14_ttbarHT6c_1k_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6414_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_ttbar_PowPy8").datasets = [
    'mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_TOPQ1.e6337_s3126_r10724_p3832',
    'mc16_13TeV.410471.PhPy8EG_A14_ttbar_hdamp258p75_allhad.deriv.DAOD_TOPQ1.e6337_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_ttbar_dil_PowPy8").datasets = [
    'mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_TOPQ1.e6348_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_tchan_lep_PowPy8").datasets = [
    'mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_TOPQ1.e6671_s3126_r10724_p3832',
    'mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_TOPQ1.e6671_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_Wt_inc_PowPy8").datasets = [
    'mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_TOPQ1.e6552_s3126_r10724_p3832',
    'mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_TOPQ1.e6552_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_Wt_dil_PowPy8").datasets = [
    'mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_TOPQ1.e6615_s3126_r10724_p3832',
    'mc16_13TeV.410649.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_antitop.deriv.DAOD_TOPQ1.e6615_s3126_r10724_p3832',
]

grid.Add("TOPQ1_schan_noAllHad_PowPy8").datasets = [
    'mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_TOPQ1.e6527_s3126_r10724_p3832',
    'mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_TOPQ1.e6527_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_tZ_noAllHad_PowPy8").datasets = [
    'mc16_13TeV.410560.MadGraphPythia8EvtGen_A14_tZ_4fl_tchan_noAllHad.deriv.DAOD_TOPQ1.e5803_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_tZ_trilepton_PowPy8").datasets = [
    'mc16_13TeV.410550.MadGraphPythia8EvtGen_A14_tZ_4fl_tchan_trilepton.deriv.DAOD_TOPQ1.e5803_e5984_s3126_r10724_p3629',
    ]

grid.Add("TOPQ1_tWZ").datasets = [
    'mc16_13TeV.410408.aMcAtNloPythia8EvtGen_tWZ_Ztoll_minDR1.deriv.DAOD_TOPQ1.e6423_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_3top").datasets = [
    'mc16_13TeV.304014.MadGraphPythia8EvtGen_A14NNPDF23_3top_SM.deriv.DAOD_TOPQ1.e4324_s3126_r10724_p3832',
]

grid.Add("TOPQ1_ttll_lowmass").datasets = [
    'mc16_13TeV.410276.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee_mll_1_5.deriv.DAOD_TOPQ1.e6087_s3126_r10724_p3832',
    'mc16_13TeV.410277.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu_mll_1_5.deriv.DAOD_TOPQ1.e6087_s3126_r10724_p3832',
    'mc16_13TeV.410278.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau_mll_1_5.deriv.DAOD_TOPQ1.e6087_s3126_r10724_p3832',
    'mc16_13TeV.410397.MadGraphPythia8EvtGen_ttbar_wbee_MEN30LO_A14N23LO.deriv.DAOD_TOPQ1.e6086_s3126_r10724_p3761',
    'mc16_13TeV.410398.MadGraphPythia8EvtGen_ttbar_wbmumu_MEN30LO_A14N23LO.deriv.DAOD_TOPQ1.e6086_s3126_r10724_p3761',
    'mc16_13TeV.410399.MadGraphPythia8EvtGen_ttbar_wbtautau_MEN30LO_A14N23LO.deriv.DAOD_TOPQ1.e6086_s3126_r10724_p3761',
]

grid.Add("TOPQ1_diboson_Sherpa").datasets = [
    'mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_TOPQ1.e5525_s3126_r10724_p3830',
    'mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_TOPQ1.e5525_s3126_r10724_p3830',
    'mc16_13TeV.363359.Sherpa_221_NNPDF30NNLO_WpqqWmlv.deriv.DAOD_TOPQ1.e5583_s3126_r10724_p3830',
    'mc16_13TeV.363360.Sherpa_221_NNPDF30NNLO_WplvWmqq.deriv.DAOD_TOPQ1.e5983_s3126_r10724_p3830',
    'mc16_13TeV.363489.Sherpa_221_NNPDF30NNLO_WlvZqq.deriv.DAOD_TOPQ1.e5525_s3126_r10724_p3830',
    'mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_TOPQ1.e5894_s3126_r10724_p3830',
    'mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_TOPQ1.e5916_s3126_r10724_p3830',
    'mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_TOPQ1.e5916_s3126_r10724_p3830',
    'mc16_13TeV.364255.Sherpa_222_NNPDF30NNLO_lvvv.deriv.DAOD_TOPQ1.e5916_s3126_r10724_p3830',
    ]

grid.Add("TOPQ1_diboson_EW").datasets = [
    'mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_TOPQ1.e6055_s3126_r10724_p3832',
    'mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_TOPQ1.e6055_s3126_r10724_p3832',
    'mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_TOPQ1.e6055_s3126_r10724_p3832',
    'mc16_13TeV.364286.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW4.deriv.DAOD_TOPQ1.e6055_s3126_r10724_p3761',
    'mc16_13TeV.364287.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW6.deriv.DAOD_TOPQ1.e6055_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_triboson_Sherpa").datasets = [
    'mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    'mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_TOPQ1.e5887_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_Zjets_Sherpa221").datasets = [                                
    'mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_TOPQ1.e5271_s3126_r10724_p3830',
    'mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_TOPQ1.e5299_s3126_r10724_p3830',
    'mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_TOPQ1.e5313_s3126_r10724_p3830',
    'mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_TOPQ1.e5313_s3126_r10724_p3830',
    'mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_TOPQ1.e5307_s3126_r10724_p3830',
    'mc16_13TeV.366140.Sh_224_NN30NNLO_eegamma_LO_pty_7_15.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366141.Sh_224_NN30NNLO_eegamma_LO_pty_15_35.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366142.Sh_224_NN30NNLO_eegamma_LO_pty_35_70.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366143.Sh_224_NN30NNLO_eegamma_LO_pty_70_140.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366144.Sh_224_NN30NNLO_eegamma_LO_pty_140_E_CMS.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366145.Sh_224_NN30NNLO_mumugamma_LO_pty_7_15.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366146.Sh_224_NN30NNLO_mumugamma_LO_pty_15_35.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366147.Sh_224_NN30NNLO_mumugamma_LO_pty_35_70.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366148.Sh_224_NN30NNLO_mumugamma_LO_pty_70_140.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366149.Sh_224_NN30NNLO_mumugamma_LO_pty_140_E_CMS.deriv.DAOD_TOPQ1.e7006_s3126_r10724_p3830',
    'mc16_13TeV.366150.Sh_224_NN30NNLO_tautaugamma_LO_pty_7_15.deriv.DAOD_TOPQ1.e7029_s3126_r10724_p3830',
    'mc16_13TeV.366151.Sh_224_NN30NNLO_tautaugamma_LO_pty_15_35.deriv.DAOD_TOPQ1.e7029_s3126_r10724_p3830',
    'mc16_13TeV.366152.Sh_224_NN30NNLO_tautaugamma_LO_pty_35_70.deriv.DAOD_TOPQ1.e7029_s3126_r10724_p3830',
    'mc16_13TeV.366153.Sh_224_NN30NNLO_tautaugamma_LO_pty_70_140.deriv.DAOD_TOPQ1.e7029_s3126_r10724_p3830',
    'mc16_13TeV.366154.Sh_224_NN30NNLO_tautaugamma_LO_pty_140_E_CMS.deriv.DAOD_TOPQ1.e7029_s3126_r10724_p3830',
    ]

grid.Add("TOPQ1_Wjets_Sherpa221").datasets = [
    'mc16_13TeV.364156.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364157.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364158.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364159.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364160.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364161.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364162.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364163.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364164.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364165.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364166.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364167.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364168.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV500_1000.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364169.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV1000_E_CMS.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364170.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364171.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364172.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364173.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364174.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364175.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364176.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364177.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364178.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364179.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364180.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364181.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364182.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV500_1000.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364183.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV1000_E_CMS.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364184.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364185.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364186.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364187.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364188.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364189.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364190.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364191.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364192.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364193.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364194.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364195.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_BFilter.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364196.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV500_1000.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364197.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV1000_E_CMS.deriv.DAOD_TOPQ1.e5340_s3126_r10724_p3830',
    'mc16_13TeV.364522.Sherpa_222_NNPDF30NNLO_enugamma_pty_15_35.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364523.Sherpa_222_NNPDF30NNLO_enugamma_pty_35_70.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364524.Sherpa_222_NNPDF30NNLO_enugamma_pty_70_140.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364525.Sherpa_222_NNPDF30NNLO_enugamma_pty_140_E_CMS.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364527.Sherpa_222_NNPDF30NNLO_munugamma_pty_15_35.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364528.Sherpa_222_NNPDF30NNLO_munugamma_pty_35_70.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364529.Sherpa_222_NNPDF30NNLO_munugamma_pty_70_140.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364530.Sherpa_222_NNPDF30NNLO_munugamma_pty_140_E_CMS.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364532.Sherpa_222_NNPDF30NNLO_taunugamma_pty_15_35.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364533.Sherpa_222_NNPDF30NNLO_taunugamma_pty_35_70.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364534.Sherpa_222_NNPDF30NNLO_taunugamma_pty_70_140.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    'mc16_13TeV.364535.Sherpa_222_NNPDF30NNLO_taunugamma_pty_140_E_CMS.deriv.DAOD_TOPQ1.e5928_s3126_r10724_p3830',
    ]

grid.Add("TOPQ1_ttV").datasets = [
    'mc16_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.deriv.DAOD_TOPQ1.e7286_s3126_r10724_p3832',
    'mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_TOPQ1.e5070_s3126_r10724_p3832',
    'mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_TOPQ1.e5070_s3126_r10724_p3832',
    'mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_TOPQ1.e5070_s3126_r10724_p3832',
    'mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_TOPQ1.e5070_s3126_r10724_p3832',
    'mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_TOPQ1.e5070_s3126_r10724_p3832',
    'mc16_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.deriv.DAOD_TOPQ1.e5070_s3126_r10724_p3832',
    'mc16_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.deriv.DAOD_TOPQ1.e4111_s3126_r10724_p3832',
    'mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_TOPQ1.e4111_s3126_r10724_p3832',
    ]         

grid.Add("TOPQ1_ttH").datasets=[
    'mc16_13TeV.346343.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_allhad.deriv.DAOD_TOPQ1.e7148_s3126_r10724_p3832',
    'mc16_13TeV.346344.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_semilep.deriv.DAOD_TOPQ1.e7148_s3126_r10724_p3832',
    'mc16_13TeV.346345.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_dilep.deriv.DAOD_TOPQ1.e7148_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_VH").datasets =[
    'mc16_13TeV.342284.Pythia8EvtGen_A14NNPDF23LO_WH125_inc.deriv.DAOD_TOPQ1.e4246_s3126_r10724_p3832',
    'mc16_13TeV.342285.Pythia8EvtGen_A14NNPDF23LO_ZH125_inc.deriv.DAOD_TOPQ1.e4246_s3126_r10724_p3832',
]

grid.Add("ttbar_sys").datasets=[
    'mc16_13TeV.410464.aMcAtNloPy8EvtGen_MEN30NLO_A14N23LO_ttbar_noShWe_SingleLep.deriv.DAOD_TOPQ1.e6762_a875_r10724_p3832',
    'mc16_13TeV.410465.aMcAtNloPy8EvtGen_MEN30NLO_A14N23LO_ttbar_noShWe_dil.deriv.DAOD_TOPQ1.e6762_a875_r10724_p3832',
    'mc16_13TeV.410466.aMcAtNloPy8EvtGen_MEN30NLO_A14N23LO_ttbar_noShWe_AllHadronic.deriv.DAOD_TOPQ1.e6762_a875_r10724_p3832',
    'mc16_13TeV.410480.PhPy8EG_A14_ttbar_hdamp517p5_SingleLep.deriv.DAOD_TOPQ1.e6454_a875_r10724_p3832',
    'mc16_13TeV.410481.PhPy8EG_A14_ttbar_hdamp517p5_allhad.deriv.DAOD_TOPQ1.e6520_a875_r10724_p3832',
    'mc16_13TeV.410482.PhPy8EG_A14_ttbar_hdamp517p5_dil.deriv.DAOD_TOPQ1.e6454_a875_r10724_p3832',
    'mc16_13TeV.410557.PowhegHerwig7EvtGen_H7UE_tt_hdamp258p75_704_SingleLep.deriv.DAOD_TOPQ1.e6366_a875_r10724_p3832',
    'mc16_13TeV.410558.PowhegHerwig7EvtGen_H7UE_tt_hdamp258p75_704_dil.deriv.DAOD_TOPQ1.e6366_a875_r10724_p3832',
    'mc16_13TeV.410559.PowhegHerwig7EvtGen_H7UE_tt_hdamp258p75_allhad.deriv.DAOD_TOPQ1.e6567_s3126_r10724_p3832',
    ]

grid.Add("TOPQ1_LQ").datasets= [
    'mc16_13TeV.312244.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M800.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
    'mc16_13TeV.312245.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M900.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
    'mc16_13TeV.310176.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M1000.deriv.DAOD_TOPQ1.e6726_a875_r10724_p3832',
    'mc16_13TeV.312246.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M1100.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
    'mc16_13TeV.312247.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M1200.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
    'mc16_13TeV.312248.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M1300.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
    'mc16_13TeV.312249.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M1400.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
    'mc16_13TeV.312250.aMcAtNloPy8EG_A14N30NLO_LQd_gstTL_0p3_nonallhad_M1500.deriv.DAOD_TOPQ1.e7555_a875_r10724_p3832',
]

grid.Add("TOPQ1_LQ_B05").datasets= [
    'mc16_13TeV.310550.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M300.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310551.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M300.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310552.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M500.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310553.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M500.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310554.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310555.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310556.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1300.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310557.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1300.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310558.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1700.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310559.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1700.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.310560.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_1p0_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6981_a875_r10724_p3832',
    'mc16_13TeV.312201.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M400.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312202.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M400.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312203.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M600.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312204.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M600.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312205.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M700.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312206.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M700.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312207.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M800.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312208.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M800.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312209.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M850.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312210.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M850.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312211.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M950.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312212.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M950.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312213.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1000.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312214.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1000.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312215.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1050.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312216.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1050.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312217.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1100.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312218.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1100.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312219.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1150.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312220.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1150.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312221.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1200.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312222.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1200.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312223.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1250.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312224.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1250.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312225.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1350.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312226.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1350.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312227.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1400.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312228.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1400.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312229.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1450.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312230.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1450.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312231.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1500.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312232.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1500.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312233.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1550.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312234.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1550.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312235.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1600.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312236.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1600.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312237.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1800.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312238.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1800.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312239.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M1900.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312240.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M1900.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312241.aMcAtNloPy8EG_OffDiag_LQu_ta_ld_0p3_beta_0p5_hnd_1p0_M2000.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    'mc16_13TeV.312242.aMcAtNloPy8EG_OffDiag_LQd_ta_ld_0p3_beta_0p5_hnd_1p0_M2000.deriv.DAOD_TOPQ1.e7536_a875_r10724_p3832',
    ]

grid.Add("TOPQ1_LQ_tbem_B05").datasets= [
    'mc16_13TeV.309867.aMcAtNloPy8EG_A14N30NLO_LQu_el_ld_0p3_beta_0p5_hnd_1p0_M300.deriv.DAOD_TOPQ1.e6675_a875_r10724_p3761',
    'mc16_13TeV.309868.aMcAtNloPy8EG_A14N30NLO_LQu_el_ld_0p3_beta_0p5_hnd_1p0_M500.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309869.aMcAtNloPy8EG_A14N30NLO_LQu_el_ld_0p3_beta_0p5_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309870.aMcAtNloPy8EG_A14N30NLO_LQu_el_ld_0p3_beta_0p5_hnd_1p0_M1300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309871.aMcAtNloPy8EG_A14N30NLO_LQu_el_ld_0p3_beta_0p5_hnd_1p0_M1700.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309872.aMcAtNloPy8EG_A14N30NLO_LQu_mu_ld_0p3_beta_0p5_hnd_1p0_M300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309873.aMcAtNloPy8EG_A14N30NLO_LQu_mu_ld_0p3_beta_0p5_hnd_1p0_M500.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309874.aMcAtNloPy8EG_A14N30NLO_LQu_mu_ld_0p3_beta_0p5_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309875.aMcAtNloPy8EG_A14N30NLO_LQu_mu_ld_0p3_beta_0p5_hnd_1p0_M1300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309876.aMcAtNloPy8EG_A14N30NLO_LQu_mu_ld_0p3_beta_0p5_hnd_1p0_M1700.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309877.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309878.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M500.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309879.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309880.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309881.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1700.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309882.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309883.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M500.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309884.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M900.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309885.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1300.deriv.DAOD_TOPQ1.e6677_a875_r10724_p3761',
    'mc16_13TeV.309886.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1700.deriv.DAOD_TOPQ1.e6675_a875_r10724_p3761',
    'mc16_13TeV.312159.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M400.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312160.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M600.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312161.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M700.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312162.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M800.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312163.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M850.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312164.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M950.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312165.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1000.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312166.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1050.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312167.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1100.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312168.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1150.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312169.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1200.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312170.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1250.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312171.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1350.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312172.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1400.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312173.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1450.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312174.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1500.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312175.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1550.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312176.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1600.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312177.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1800.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312178.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M1900.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312179.aMcAtNloPy8EG_A14N30NLO_LQd_el_ld_0p3_beta_0p5_hnd_1p0_M2000.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312180.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M400.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312181.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M600.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312182.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M700.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312183.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M800.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312184.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M850.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312185.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M950.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312186.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1000.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312187.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1050.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312188.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1100.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312189.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1150.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312190.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1200.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312191.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1250.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312192.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1350.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312193.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1400.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312194.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1450.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312195.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1500.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312196.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1550.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312197.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1600.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312198.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1800.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312199.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M1900.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    'mc16_13TeV.312200.aMcAtNloPy8EG_A14N30NLO_LQd_mu_ld_0p3_beta_0p5_hnd_1p0_M2000.deriv.DAOD_TOPQ1.e7539_a875_r10724_p3832',
    ]

