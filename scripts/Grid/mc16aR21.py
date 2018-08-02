import TopExamples.grid
import TopExamples.ami
import grid

grid.Add("syst_mc16a").datasets=[
    #410155 - sub as individualSample
    #410218 - sub as individualSample
    #410219 - sub as individualSample
    #410220 - sub as individualSample
    #345672 - sub as individualSample
    #345673 - sub as individualSample
    #345674 - sub as individualSample
    "mc16_13TeV.343273.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_lep.deriv.DAOD_HIGG8D1.e4606_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364286.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW4.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.deriv.DAOD_HIGG8D1.e4111_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363360.Sherpa_221_NNPDF30NNLO_WplvWmqq.deriv.DAOD_HIGG8D1.e5983_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410560.MadGraphPythia8EvtGen_A14_tZ_4fl_tchan_noAllHad.deriv.DAOD_HIGG8D1.e5803_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342282.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_inc.deriv.DAOD_HIGG8D1.e4850_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410016.PowhegPythiaEvtGen_P2012_Wt_dilepton_antitop.deriv.DAOD_HIGG8D1.e3753_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341488.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_ZZ4lep.deriv.DAOD_HIGG8D1.e3951_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342283.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_inc.deriv.DAOD_HIGG8D1.e4246_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363489.Sherpa_221_NNPDF30NNLO_WlvZqq.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341471.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_ZZ4lep.deriv.DAOD_HIGG8D1.e3951_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG8D1.e4111_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410397.MadGraphPythia8EvtGen_ttbar_wbee_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364255.Sherpa_222_NNPDF30NNLO_lvvv.deriv.DAOD_HIGG8D1.e5916_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410276.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410013.PowhegPythiaEvtGen_P2012_Wt_inclusive_top.deriv.DAOD_HIGG8D1.e3753_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410399.MadGraphPythia8EvtGen_ttbar_wbtautau_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363359.Sherpa_221_NNPDF30NNLO_WpqqWmlv.deriv.DAOD_HIGG8D1.e5583_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG8D1.e5894_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410014.PowhegPythiaEvtGen_P2012_Wt_inclusive_antitop.deriv.DAOD_HIGG8D1.e3753_s3126_r9364_r9315_p3480",
"mc16_13TeV.342285.Pythia8EvtGen_A14NNPDF23LO_ZH125_inc.deriv.DAOD_HIGG8D1.e4246_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410277.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410278.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342001.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus1.deriv.DAOD_HIGG8D1.e4394_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345709.Sherpa_222_NNPDF30NNLO_ggllllNoHiggs_130M4l.deriv.DAOD_HIGG8D1.e6213_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.342284.Pythia8EvtGen_A14NNPDF23LO_WH125_inc.deriv.DAOD_HIGG8D1.e4246_s3126_r9364_r9315_p3480",
    "mc16_13TeV.304014.MadGraphPythia8EvtGen_A14NNPDF23_3top_SM.deriv.DAOD_HIGG8D1.e4324_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345708.Sherpa_222_NNPDF30NNLO_ggllllNoHiggs_0M4l130.deriv.DAOD_HIGG8D1.e6213_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345716.Sherpa_222_NNPDF30NNLO_ggllvvIntNoHiggs.deriv.DAOD_HIGG8D1.e6480_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364287.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410015.PowhegPythiaEvtGen_P2012_Wt_dilepton_top.deriv.DAOD_HIGG8D1.e3753_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410398.MadGraphPythia8EvtGen_ttbar_wbmumu_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG8D1.e5916_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG8D1.e5916_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG8D1.e5894_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363355.Sherpa_221_NNPDF30NNLO_ZqqZvv.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363357.Sherpa_221_NNPDF30NNLO_WqqZvv.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410389.MadGraphPythia8EvtGen_A14NNPDF23_ttgamma_nonallhadronic.deriv.DAOD_HIGG8D1.e6155_e5984_s3126_r9364_r9315_p3480",
]

grid.Add("singleSample_410155").datasets=[
    "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
]
grid.Add("singleSample_410218").datasets=[
    "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
]
grid.Add("singleSample_410219").datasets=[
    "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
]
grid.Add("singleSample_410220").datasets=[
    "mc16_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
]
grid.Add("singleSample_345875").datasets=[
    "mc16_13TeV.345875.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_hdamp352p5_dilep.deriv.DAOD_HIGG8D1.e6474_e5984_s3126_r9364_r9315_p3552",
    ]
grid.Add("singleSample_345874").datasets=[
    "mc16_13TeV.345874.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_hdamp352p5_semilep.deriv.DAOD_HIGG8D1.e6474_e5984_s3126_r9364_r9315_p3552",
    ]
grid.Add("singleSample_345873").datasets=[
    "mc16_13TeV.345873.PowhegPythia8EvtGen_A14NNPDF23_NNPDF30ME_ttH125_allhad.deriv.DAOD_HIGG8D1.e6553_e5984_s3126_r9364_r9315_p3552",
    ]

grid.Add("singleSample_410470").datasets=[
    "mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_HIGG8D1.e6337_e5984_s3126_r9364_r9315_p3480",
]
grid.Add("singleSample_410472").datasets=[
    "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG8D1.e6348_e5984_s3126_r9364_r9315_p3480",
]

grid.Add("FS_mc16a").datasets=[
    "mc16_13TeV.304014.MadGraphPythia8EvtGen_A14NNPDF23_3top_SM.deriv.DAOD_HIGG8D1.e4324_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341177.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_dil.deriv.DAOD_HIGG8D1.e4277_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341270.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_semilep.deriv.DAOD_HIGG8D1.e4277_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341271.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_allhad.deriv.DAOD_HIGG8D1.e4277_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341471.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_ZZ4lep.deriv.DAOD_HIGG8D1.e3951_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341488.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_ZZ4lep.deriv.DAOD_HIGG8D1.e3951_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.341998.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus1.deriv.DAOD_HIGG8D1.e4394_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342001.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_lep_yt_plus1.deriv.DAOD_HIGG8D1.e4394_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342004.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_bbbar_yt_plus1.deriv.DAOD_HIGG8D1.e4394_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342282.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_inc.deriv.DAOD_HIGG8D1.e4850_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342283.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_inc.deriv.DAOD_HIGG8D1.e4246_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342284.Pythia8EvtGen_A14NNPDF23LO_WH125_inc.deriv.DAOD_HIGG8D1.e4246_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342285.Pythia8EvtGen_A14NNPDF23LO_ZH125_inc.deriv.DAOD_HIGG8D1.e4246_s3126_r9364_r9315_p3480",
    "mc16_13TeV.342561.aMcAtNloHerwigppEvtGen_UEEE5_CTEQ6L1_CT10ME_ttH125_4l.deriv.DAOD_HIGG8D1.e4540_s3126_r9364_r9315_p3480",
    "mc16_13TeV.343267.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_gamgam.deriv.DAOD_HIGG8D1.e4606_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.343270.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_bbbar.deriv.DAOD_HIGG8D1.e4610_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.343273.MadGraphPythia8EvtGen_A14_CT10ME_tHjb125_lep.deriv.DAOD_HIGG8D1.e4606_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.344388.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30nlo_ttH125_mumu.deriv.DAOD_HIGG8D1.e5272_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345672.PowhegPythia8EvtGen_A14NNPDF23_NNPDF30ME_ttH125_allhad.deriv.DAOD_HIGG8D1.e6322_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345673.PowhegPythia8EvtGen_A14NNPDF23_NNPDF30ME_ttH125_semilep.deriv.DAOD_HIGG8D1.e6322_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.361250.Pythia8B_A14_NNPDF23LO_bbTomu15.deriv.DAOD_HIGG8D1.e3878_s3126_r9364_r9315_p3480",
    "mc16_13TeV.361251.Pythia8B_A14_NNPDF23LO_ccTomu15.deriv.DAOD_HIGG8D1.e3878_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363355.Sherpa_221_NNPDF30NNLO_ZqqZvv.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363357.Sherpa_221_NNPDF30NNLO_WqqZvv.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363359.Sherpa_221_NNPDF30NNLO_WpqqWmlv.deriv.DAOD_HIGG8D1.e5583_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363360.Sherpa_221_NNPDF30NNLO_WplvWmqq.deriv.DAOD_HIGG8D1.e5983_s3126_r9364_r9315_p3480",
    "mc16_13TeV.363489.Sherpa_221_NNPDF30NNLO_WlvZqq.deriv.DAOD_HIGG8D1.e5525_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5313_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364139.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5313_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364156.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364157.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364158.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364159.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364160.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364162.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364163.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364164.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364165.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364166.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364167.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364168.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364169.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364170.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364171.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364172.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364173.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364175.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364176.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364177.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364179.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364180.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364181.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364182.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364183.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364184.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364185.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364186.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364187.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364188.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364189.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364190.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364191.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364192.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364193.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364194.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364195.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364196.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364197.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364198.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364199.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364200.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364201.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364202.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364203.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364204.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364205.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364206.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364207.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364208.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364209.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364210.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364211.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364212.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364213.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364214.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364215.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364248.Sherpa_222_NNPDF30NNLO_ZZZ_4l2v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364255.Sherpa_222_NNPDF30NNLO_lvvv.deriv.DAOD_HIGG8D1.e5916_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364501.Sherpa_222_NNPDF30NNLO_eegamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364502.Sherpa_222_NNPDF30NNLO_eegamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364503.Sherpa_222_NNPDF30NNLO_eegamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364504.Sherpa_222_NNPDF30NNLO_eegamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364505.Sherpa_222_NNPDF30NNLO_mumugamma_pty_7_15.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364507.Sherpa_222_NNPDF30NNLO_mumugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364508.Sherpa_222_NNPDF30NNLO_mumugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364509.Sherpa_222_NNPDF30NNLO_mumugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364510.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_7_15.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364511.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364512.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364513.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5982_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364514.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364521.Sherpa_222_NNPDF30NNLO_enugamma_pty_7_15.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364522.Sherpa_222_NNPDF30NNLO_enugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364523.Sherpa_222_NNPDF30NNLO_enugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364524.Sherpa_222_NNPDF30NNLO_enugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364525.Sherpa_222_NNPDF30NNLO_enugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364526.Sherpa_222_NNPDF30NNLO_munugamma_pty_7_15.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364528.Sherpa_222_NNPDF30NNLO_munugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364529.Sherpa_222_NNPDF30NNLO_munugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364530.Sherpa_222_NNPDF30NNLO_munugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364531.Sherpa_222_NNPDF30NNLO_taunugamma_pty_7_15.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364532.Sherpa_222_NNPDF30NNLO_taunugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364533.Sherpa_222_NNPDF30NNLO_taunugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364534.Sherpa_222_NNPDF30NNLO_taunugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364535.Sherpa_222_NNPDF30NNLO_taunugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410011.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_top.deriv.DAOD_HIGG8D1.e3824_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410012.PowhegPythiaEvtGen_P2012_singletop_tchan_lept_antitop.deriv.DAOD_HIGG8D1.e3824_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410013.PowhegPythiaEvtGen_P2012_Wt_inclusive_top.deriv.DAOD_HIGG8D1.e3753_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410014.PowhegPythiaEvtGen_P2012_Wt_inclusive_antitop.deriv.DAOD_HIGG8D1.e3753_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410015.PowhegPythiaEvtGen_P2012_Wt_dilepton_top.deriv.DAOD_HIGG8D1.e3753_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410016.PowhegPythiaEvtGen_P2012_Wt_dilepton_antitop.deriv.DAOD_HIGG8D1.e3753_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410025.PowhegPythiaEvtGen_P2012_SingleTopSchan_noAllHad_top.deriv.DAOD_HIGG8D1.e3998_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410026.PowhegPythiaEvtGen_P2012_SingleTopSchan_noAllHad_antitop.deriv.DAOD_HIGG8D1.e3998_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.deriv.DAOD_HIGG8D1.e4111_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG8D1.e4111_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410082.MadGraphPythia8EvtGen_A14NNPDF23LO_ttgamma_noallhad.deriv.DAOD_HIGG8D1.e4404_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410143.Sherpa_NNPDF30NNLO_ttZnnqq.deriv.DAOD_HIGG8D1.e4686_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410144.Sherpa_NNPDF30NNLO_ttW.deriv.DAOD_HIGG8D1.e4686_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410276.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410277.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410370.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_ttee.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410371.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3DownN23LO_ttee.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410372.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_ttmumu.deriv.DAOD_HIGG8D1.e6125_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410374.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_tttautau.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410375.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3DownN23LO_tttautau.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410376.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_ttW.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410397.MadGraphPythia8EvtGen_ttbar_wbee_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410398.MadGraphPythia8EvtGen_ttbar_wbmumu_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410399.MadGraphPythia8EvtGen_ttbar_wbtautau_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410471.PhPy8EG_A14_ttbar_hdamp258p75_allhad.deriv.DAOD_HIGG8D1.e6337_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364286.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW4.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345708.Sherpa_222_NNPDF30NNLO_ggllllNoHiggs_0M4l130.deriv.DAOD_HIGG8D1.e6213_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345716.Sherpa_222_NNPDF30NNLO_ggllvvIntNoHiggs.deriv.DAOD_HIGG8D1.e6480_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410377.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3DownN23LO_ttW.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410560.MadGraphPythia8EvtGen_A14_tZ_4fl_tchan_noAllHad.deriv.DAOD_HIGG8D1.e5803_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364287.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364527.Sherpa_222_NNPDF30NNLO_munugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410278.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345674.PowhegPythia8EvtGen_A14NNPDF23_NNPDF30ME_ttH125_dilep.deriv.DAOD_HIGG8D1.e6322_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410219.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364112.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.343366.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_semilep.deriv.DAOD_HIGG8D1.e4706_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.343365.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_dilep.deriv.DAOD_HIGG8D1.e4706_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364500.Sherpa_222_NNPDF30NNLO_eegamma_pty_7_15.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410503.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG8D1.e5475_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410251.Sherpa_221_NNPDF30NNLO_ttbar_SingleLeptonM_MEPS_NLO.deriv.DAOD_HIGG8D1.e5450_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364178.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG8D1.e5070_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410408.aMcAtNloPythia8EvtGen_tWZ_Ztoll_minDR1.deriv.DAOD_HIGG8D1.e6423_e5984_s3126_r9364_r9315_p3552",
    "mc16_13TeV.410389.MadGraphPythia8EvtGen_A14NNPDF23_ttgamma_nonallhadronic.deriv.DAOD_HIGG8D1.e6155_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG8D1.e5916_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364174.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG8D1.e5916_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410252.Sherpa_221_NNPDF30NNLO_ttbar_dilepton_MEPS_NLO.deriv.DAOD_HIGG8D1.e5450_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_HIGG8D1.e6337_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410142.Sherpa_NNPDF30NNLO_ttll_mll5.deriv.DAOD_HIGG8D1.e4686_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410544.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_threelepton.deriv.DAOD_HIGG8D1.e6147_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5271_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG8D1.e5894_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG8D1.e6348_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410250.Sherpa_221_NNPDF30NNLO_ttbar_SingleLeptonP_MEPS_NLO.deriv.DAOD_HIGG8D1.e5450_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364130.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5307_s3126_r9364_r9315_p3480",
    "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410501.PowhegPythia8EvtGen_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_HIGG8D1.e5458_s3126_r9364_r9315_p3480",
    "mc16_13TeV.410373.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3DownN23LO_ttmumu.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.343367.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30ME_ttH125_allhad.deriv.DAOD_HIGG8D1.e4706_e5984_s3126_r9364_r9315_p3480",
    "mc16_13TeV.345874.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_hdamp352p5_semilep.deriv.DAOD_HIGG8D1.e6474_e5984_s3126_r9364_r9315_p3552",
    "mc16_13TeV.345873.PowhegPythia8EvtGen_A14NNPDF23_NNPDF30ME_ttH125_allhad.deriv.DAOD_HIGG8D1.e6553_e5984_s3126_r9364_r9315_p3552",
    "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG8D1.e6527_e5984_s3126_r9364_r9315_p3552",
    "mc16_13TeV.345875.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_hdamp352p5_dilep.deriv.DAOD_HIGG8D1.e6474_e5984_s3126_r9364_r9315_p3552",
    "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG8D1.e6527_e5984_s3126_r9364_r9315_p3552",
    "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG8D1.e6671_e5984_s3126_r9364_r9315_p3552",
]

grid.Add("AF_mc16a").datasets=[
    "mc16_13TeV.345865.PowhegHerwig7EvtGen_H7UE_ttH125_hdamp352p5_semilep.deriv.DAOD_HIGG8D1.e6475_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.345866.PowhegHerwig7EvtGen_H7UE_ttH125_hdamp352p5_dilep.deriv.DAOD_HIGG8D1.e6475_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG8D1.e6348_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_HIGG8D1.e6337_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.410389.MadGraphPythia8EvtGen_A14NNPDF23_ttgamma_nonallhadronic.deriv.DAOD_HIGG8D1.e6155_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.410471.PhPy8EG_A14_ttbar_hdamp258p75_allhad.deriv.DAOD_HIGG8D1.e6337_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.345709.Sherpa_222_NNPDF30NNLO_ggllllNoHiggs_130M4l.deriv.DAOD_HIGG8D1.e6213_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.345874.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_hdamp352p5_semilep.deriv.DAOD_HIGG8D1.e6474_e5984_a875_r9364_r9315_p3552",
    "mc16_13TeV.345875.PhPy8EG_A14NNPDF23_NNPDF30ME_ttH125_hdamp352p5_dilep.deriv.DAOD_HIGG8D1.e6474_e5984_a875_r9364_r9315_p3552",
    "mc16_13TeV.345941.aMcAtNloPythia8EvtGen_ttH_semilep.deriv.DAOD_HIGG8D1.e6654_e5984_a875_r9364_r9315_p3552",
    "mc16_13TeV.345942.aMcAtNloPythia8EvtGen_ttH_allhad.deriv.DAOD_HIGG8D1.e6654_e5984_a875_r9364_r9315_p3552",
    "mc16_13TeV.410558.PowhegHerwig7EvtGen_H7UE_tt_hdamp258p75_704_dil.deriv.DAOD_HIGG8D1.e6366_e5984_a875_r9364_r9315_p3480",
    "mc16_13TeV.410557.PowhegHerwig7EvtGen_H7UE_tt_hdamp258p75_704_SingleLep.deriv.DAOD_HIGG8D1.e6366_e5984_a875_r9364_r9315_p3480",
]

