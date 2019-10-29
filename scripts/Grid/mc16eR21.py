import TopExamples.grid
import TopExamples.ami
import grid

grid.Add("syst_mc16e").datasets=[
    # 346345 not found
    # 346344 not found
    # 346343 not found
    "mc16_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.deriv.DAOD_HIGG8D1.e7286_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG8D1.e5916_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG8D1.e5894_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG8D1.e5916_e5984_s3126_r10724_r10726_p3983",
    # 364255 not found
    "mc16_13TeV.363355.Sherpa_221_NNPDF30NNLO_ZqqZvv.deriv.DAOD_HIGG8D1.e5525_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG8D1.e5525_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363357.Sherpa_221_NNPDF30NNLO_WqqZvv.deriv.DAOD_HIGG8D1.e5525_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG8D1.e5525_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363359.Sherpa_221_NNPDF30NNLO_WpqqWmlv.deriv.DAOD_HIGG8D1.e5583_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363360.Sherpa_221_NNPDF30NNLO_WplvWmqq.deriv.DAOD_HIGG8D1.e5983_e5984_s3126_r10724_r10726_p3983",
    # 410155 not found
    "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG8D1.e5070_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG8D1.e5070_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG8D1.e5070_e5984_s3126_r10724_r10726_p3983",
    # 410219 not found
    "mc16_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.deriv.DAOD_HIGG8D1.e5070_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410276.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410277.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu_mll_1_5.deriv.DAOD_HIGG8D1.e6087_e5984_s3126_r10724_r10726_p3983",
    # 410278 not found
    "mc16_13TeV.410397.MadGraphPythia8EvtGen_ttbar_wbee_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410398.MadGraphPythia8EvtGen_ttbar_wbmumu_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410399.MadGraphPythia8EvtGen_ttbar_wbtautau_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.304014.MadGraphPythia8EvtGen_A14NNPDF23_3top_SM.deriv.DAOD_HIGG8D1.e4324_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.deriv.DAOD_HIGG8D1.e4111_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG8D1.e4111_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410560.MadGraphPythia8EvtGen_A14_tZ_4fl_tchan_noAllHad.deriv.DAOD_HIGG8D1.e5803_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    # 364248 not found
    "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
]

grid.Add("FS_mc16e").datasets=[
    "mc16_13TeV.364194.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.410560.MadGraphPythia8EvtGen_A14_tZ_4fl_tchan_noAllHad.deriv.DAOD_HIGG8D1.e5803_s3126_r10724_p3983",
    "mc16_13TeV.364167.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410276.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee_mll_1_5.deriv.DAOD_HIGG8D1.e6087_s3126_r10724_p3983",
    "mc16_13TeV.364192.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364288.Sherpa_222_NNPDF30NNLO_llll_lowMllPtComplement.deriv.DAOD_HIGG8D1.e6096_s3126_r10724_p3983",
    "mc16_13TeV.364138.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5313_s3126_r10724_p3983",
    "mc16_13TeV.410220.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_tttautau.deriv.DAOD_HIGG8D1.e5070_s3126_r10724_p3983",
    "mc16_13TeV.364105.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5271_s3126_r10724_p3983",
    "mc16_13TeV.364115.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364207.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BFilter.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.deriv.DAOD_HIGG8D1.e5894_s3126_r10724_p3983",
    "mc16_13TeV.364183.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364163.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364181.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364107.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364290.Sherpa_222_NNPDF30NNLO_llvv_lowMllPtComplement.deriv.DAOD_HIGG8D1.e6096_s3126_r10724_p3983",
    "mc16_13TeV.361106.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zee.deriv.DAOD_HIGG8D1.e3601_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364175.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364287.Sherpa_222_NNPDF30NNLO_llvvjj_ss_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.deriv.DAOD_HIGG8D1.e7286_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364135.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r10724_p3983",
    "mc16_13TeV.364193.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364162.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364126.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5299_s3126_r10724_p3983",
    "mc16_13TeV.410218.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttee.deriv.DAOD_HIGG8D1.e5070_s3126_r10724_p3983",
    "mc16_13TeV.364501.Sherpa_222_NNPDF30NNLO_eegamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.364100.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363355.Sherpa_221_NNPDF30NNLO_ZqqZvv.deriv.DAOD_HIGG8D1.e5525_s3126_r10724_p3983",
    "mc16_13TeV.364120.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r10724_p3983",
    "mc16_13TeV.364110.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364141.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5307_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364202.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BVeto.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364203.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV280_E_CMS_BFilter.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.423103.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP70_140.deriv.DAOD_HIGG8D1.e3791_s3126_r10724_p3983",
    "mc16_13TeV.364106.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364157.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364199.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410144.Sherpa_NNPDF30NNLO_ttW.deriv.DAOD_HIGG8D1.e4686_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364113.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5271_s3126_r10724_p3983",
    "mc16_13TeV.364188.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364195.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364187.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.410471.PhPy8EG_A14_ttbar_hdamp258p75_allhad.deriv.DAOD_HIGG8D1.e6337_s3126_r10724_p3983",
    "mc16_13TeV.364124.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r10724_p3983",
    "mc16_13TeV.364533.Sherpa_222_NNPDF30NNLO_taunugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.deriv.DAOD_HIGG8D1.e4111_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364134.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r10724_p3983",
    "mc16_13TeV.364176.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364117.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.361251.Pythia8B_A14_NNPDF23LO_ccTomu15.deriv.DAOD_HIGG8D1.e3878_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410372.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_ttmumu.deriv.DAOD_HIGG8D1.e6125_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.342284.Pythia8EvtGen_A14NNPDF23LO_WH125_inc.deriv.DAOD_HIGG8D1.e4246_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.361602.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_WZlvvv_mll4.deriv.DAOD_HIGG8D1.e4054_s3126_r10724_p3983",
    "mc16_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.deriv.DAOD_HIGG8D1.e6348_s3126_r10724_p3983",
    "mc16_13TeV.364160.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410659.PhPy8EG_A14_tchan_BW50_lept_antitop.deriv.DAOD_HIGG8D1.e6671_s3126_r10724_p3983",
    "mc16_13TeV.413001.Sherpa_ttW_multilegNLO.deriv.DAOD_HIGG8D1.e7071_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364123.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364289.Sherpa_222_NNPDF30NNLO_lllv_lowMllPtComplement.deriv.DAOD_HIGG8D1.e6133_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410647.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_antitop.deriv.DAOD_HIGG8D1.e6552_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364247.Sherpa_222_NNPDF30NNLO_ZZZ_6l0v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364121.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364741.MGPy8EG_NNPDF30NLO_A14NNPDF23LO_lvlljjEW6_SFMinus.deriv.DAOD_HIGG8D1.e7421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364205.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364506.Sherpa_222_NNPDF30NNLO_mumugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.364185.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364103.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r10724_p3983",
    "mc16_13TeV.364511.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364242.Sherpa_222_NNPDF30NNLO_WWW_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r10724_p3983",
    "mc16_13TeV.364168.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364119.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364171.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.345716.Sherpa_222_NNPDF30NNLO_ggllvvIntNoHiggs.deriv.DAOD_HIGG8D1.e6480_s3126_r10724_p3983",
    "mc16_13TeV.364532.Sherpa_222_NNPDF30NNLO_taunugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.410081.MadGraphPythia8EvtGen_A14NNPDF23_ttbarWW.deriv.DAOD_HIGG8D1.e4111_s3126_r10724_p3983",
    "mc16_13TeV.364159.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364285.Sherpa_222_NNPDF30NNLO_llvvjj_EW6.deriv.DAOD_HIGG8D1.e6055_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364111.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.423109.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP1500_2000.deriv.DAOD_HIGG8D1.e4453_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410398.MadGraphPythia8EvtGen_ttbar_wbmumu_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363360.Sherpa_221_NNPDF30NNLO_WplvWmqq.deriv.DAOD_HIGG8D1.e5983_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364524.Sherpa_222_NNPDF30NNLO_enugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.423104.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP140_280.deriv.DAOD_HIGG8D1.e3791_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364186.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.410408.aMcAtNloPythia8EvtGen_tWZ_Ztoll_minDR1.deriv.DAOD_HIGG8D1.e6423_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364174.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364114.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364213.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
    "mc16_13TeV.364128.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364140.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5307_s3126_r10724_p3983",
    "mc16_13TeV.364503.Sherpa_222_NNPDF30NNLO_eegamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.345709.Sherpa_222_NNPDF30NNLO_ggllllNoHiggs_130M4l.deriv.DAOD_HIGG8D1.e6213_s3126_r10724_p3983",
    "mc16_13TeV.364109.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r10724_p3983",
    "mc16_13TeV.410658.PhPy8EG_A14_tchan_BW50_lept_top.deriv.DAOD_HIGG8D1.e6671_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.341488.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_VBFH125_ZZ4lep.deriv.DAOD_HIGG8D1.e3951_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364131.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.341998.aMcAtNloHppEG_UEEE5_CTEQ6L1_CT10ME_tWH125_gamgam_yt_plus1.deriv.DAOD_HIGG8D1.e4394_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.361250.Pythia8B_A14_NNPDF23LO_bbTomu15.deriv.DAOD_HIGG8D1.e3878_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364133.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5307_s3126_r10724_p3983",
    "mc16_13TeV.410376.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_ttW.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364129.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5307_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364191.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364196.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.423106.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP500_800.deriv.DAOD_HIGG8D1.e3791_s3126_r10724_p3983",
    "mc16_13TeV.410645.PowhegPythia8EvtGen_A14_singletop_schan_lept_antitop.deriv.DAOD_HIGG8D1.e6527_s3126_r10724_p3983",
    "mc16_13TeV.364182.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV500_1000.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.361107.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Zmumu.deriv.DAOD_HIGG8D1.e3601_s3126_r10724_p3983",
    "mc16_13TeV.410644.PowhegPythia8EvtGen_A14_singletop_schan_lept_top.deriv.DAOD_HIGG8D1.e6527_s3126_r10724_p3983",
    "mc16_13TeV.364508.Sherpa_222_NNPDF30NNLO_mumugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364108.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410370.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3UpN23LO_ttee.deriv.DAOD_HIGG8D1.e6113_s3126_r10724_p3983",
    "mc16_13TeV.364190.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV140_280_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364244.Sherpa_222_NNPDF30NNLO_WWZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364530.Sherpa_222_NNPDF30NNLO_munugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.364512.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.364254.Sherpa_222_NNPDF30NNLO_llvv.deriv.DAOD_HIGG8D1.e5916_s3126_r10724_p3983",
    "mc16_13TeV.363359.Sherpa_221_NNPDF30NNLO_WpqqWmlv.deriv.DAOD_HIGG8D1.e5583_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410371.aMcAtNloPythia8EvtGen_MEN30NLO_A14Var3DownN23LO_ttee.deriv.DAOD_HIGG8D1.e6113_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364200.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV70_280_BVeto.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364535.Sherpa_222_NNPDF30NNLO_taunugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363489.Sherpa_221_NNPDF30NNLO_WlvZqq.deriv.DAOD_HIGG8D1.e5525_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364125.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV280_500_BFilter.deriv.DAOD_HIGG8D1.e5299_s3126_r10724_p3983",
    "mc16_13TeV.364164.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.410142.Sherpa_NNPDF30NNLO_ttll_mll5.deriv.DAOD_HIGG8D1.e4686_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364156.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364172.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364214.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
    "mc16_13TeV.364169.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.423105.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP280_500.deriv.DAOD_HIGG8D1.e3791_s3126_r10724_p3983",
    "mc16_13TeV.363357.Sherpa_221_NNPDF30NNLO_WqqZvv.deriv.DAOD_HIGG8D1.e5525_s3126_r10724_p3983",
    "mc16_13TeV.364284.Sherpa_222_NNPDF30NNLO_lllvjj_EW6.deriv.DAOD_HIGG8D1.e6055_s3126_r10724_p3983",
    "mc16_13TeV.423107.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP800_1000.deriv.DAOD_HIGG8D1.e4453_s3126_r10724_p3983",
    "mc16_13TeV.364243.Sherpa_222_NNPDF30NNLO_WWZ_4l2v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r10724_p3983",
    "mc16_13TeV.304014.MadGraphPythia8EvtGen_A14NNPDF23_3top_SM.deriv.DAOD_HIGG8D1.e4324_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364177.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364204.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV0_70_BVeto.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410277.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttmumu_mll_1_5.deriv.DAOD_HIGG8D1.e6087_s3126_r10724_p3983",
    "mc16_13TeV.364198.Sherpa_221_NN30NNLO_Zmm_Mll10_40_MAXHTPTV0_70_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
    "mc16_13TeV.364104.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364184.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.413023.Sherpa_221_ttll_multileg_NLO.deriv.DAOD_HIGG8D1.e7504_s3126_r10724_p3983",
    "mc16_13TeV.410389.MadGraphPythia8EvtGen_A14NNPDF23_ttgamma_nonallhadronic.deriv.DAOD_HIGG8D1.e6155_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410470.PhPy8EG_A14_ttbar_hdamp258p75_nonallhad.deriv.DAOD_HIGG8D1.e6337_s3126_r10724_p3983",
    "mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.deriv.DAOD_HIGG8D1.e6055_s3126_r10724_p3983",
    "mc16_13TeV.344388.aMcAtNloPythia8EvtGen_A14_NNPDF23_NNPDF30nlo_ttH125_mumu.deriv.DAOD_HIGG8D1.e5272_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364178.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.423101.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP35_50.deriv.DAOD_HIGG8D1.e3904_s3126_r10724_p3983",
    "mc16_13TeV.364127.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364534.Sherpa_222_NNPDF30NNLO_taunugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364116.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5299_s3126_r10724_p3983",
    "mc16_13TeV.342285.Pythia8EvtGen_A14NNPDF23LO_ZH125_inc.deriv.DAOD_HIGG8D1.e4246_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364525.Sherpa_222_NNPDF30NNLO_enugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364137.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5307_s3126_r10724_p3983",
    "mc16_13TeV.364504.Sherpa_222_NNPDF30NNLO_eegamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364507.Sherpa_222_NNPDF30NNLO_mumugamma_pty_35_70.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.364206.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV70_280_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
    "mc16_13TeV.410648.PowhegPythia8EvtGen_A14_Wt_DR_dilepton_top.deriv.DAOD_HIGG8D1.e6615_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364529.Sherpa_222_NNPDF30NNLO_munugamma_pty_70_140.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364118.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5299_s3126_r10724_p3983",
    "mc16_13TeV.410399.MadGraphPythia8EvtGen_ttbar_wbtautau_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_s3126_r10724_p3983",
    "mc16_13TeV.364509.Sherpa_222_NNPDF30NNLO_mumugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.364253.Sherpa_222_NNPDF30NNLO_lllv.deriv.DAOD_HIGG8D1.e5916_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364208.Sherpa_221_NN30NNLO_Zee_Mll10_40_MAXHTPTV280_E_CMS_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
    "mc16_13TeV.342282.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_inc.deriv.DAOD_HIGG8D1.e4850_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363358.Sherpa_221_NNPDF30NNLO_WqqZll.deriv.DAOD_HIGG8D1.e5525_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364132.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV70_140_CFilterBVeto.deriv.DAOD_HIGG8D1.e5307_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364210.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BVeto.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
    "mc16_13TeV.345705.Sherpa_222_NNPDF30NNLO_ggllll_0M4l130.deriv.DAOD_HIGG8D1.e6213_s3126_r10724_p3983",
    "mc16_13TeV.423102.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP50_70.deriv.DAOD_HIGG8D1.e3791_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364136.Sherpa_221_NNPDF30NNLO_Ztautau_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5307_s3126_r10724_p3983",
    "mc16_13TeV.364122.Sherpa_221_NNPDF30NNLO_Zee_MAXHTPTV140_280_BFilter.deriv.DAOD_HIGG8D1.e5299_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364527.Sherpa_222_NNPDF30NNLO_munugamma_pty_15_35.deriv.DAOD_HIGG8D1.e5928_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364212.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV70_280_BVeto.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364245.Sherpa_222_NNPDF30NNLO_WZZ_5l1v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r10724_p3983",
    "mc16_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.deriv.DAOD_HIGG8D1.e5070_s3126_r10724_p3983",
    "mc16_13TeV.364215.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV280_E_CMS_BFilter.deriv.DAOD_HIGG8D1.e5421_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.410156.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZnunu.deriv.DAOD_HIGG8D1.e5070_s3126_r10724_p3983",
    "mc16_13TeV.364246.Sherpa_222_NNPDF30NNLO_WZZ_3l3v_EW6.deriv.DAOD_HIGG8D1.e5887_s3126_r10724_p3983",
    "mc16_13TeV.341471.PowhegPythia8EvtGen_CT10_AZNLOCTEQ6L1_ggH125_ZZ4lep.deriv.DAOD_HIGG8D1.e3951_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364179.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.361102.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wplustaunu.deriv.DAOD_HIGG8D1.e3601_s3126_r10724_p3983",
    "mc16_13TeV.423300.Pythia8EvtGen_A14NNPDF23LO_perf_JF17.deriv.DAOD_HIGG8D1.e3848_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.410397.MadGraphPythia8EvtGen_ttbar_wbee_MEN30LO_A14N23LO.deriv.DAOD_HIGG8D1.e6086_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364102.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5271_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364197.Sherpa_221_NNPDF30NNLO_Wtaunu_MAXHTPTV1000_E_CMS.deriv.DAOD_HIGG8D1.e5340_s3126_r10724_p3983",
    "mc16_13TeV.364170.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV0_70_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364742.MGPy8EG_NNPDF30NLO_A14NNPDF23LO_lvlljjEW6_SFPlus.deriv.DAOD_HIGG8D1.e7421_s3126_r10724_p3983",
    "mc16_13TeV.364514.Sherpa_222_NNPDF30NNLO_tautaugamma_pty_140_E_CMS.deriv.DAOD_HIGG8D1.e5928_s3126_r10724_p3983",
    "mc16_13TeV.410646.PowhegPythia8EvtGen_A14_Wt_DR_inclusive_top.deriv.DAOD_HIGG8D1.e6552_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364249.Sherpa_222_NNPDF30NNLO_ZZZ_2l4v_EW6.deriv.DAOD_HIGG8D1.e5887_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364173.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV70_140_CVetoBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_s3136_r10724_r10726_p3983",
    "mc16_13TeV.364101.Sherpa_221_NNPDF30NNLO_Zmumu_MAXHTPTV0_70_CFilterBVeto.deriv.DAOD_HIGG8D1.e5271_s3126_r10724_p3983",
    "mc16_13TeV.361100.PowhegPythia8EvtGen_AZNLOCTEQ6L1_Wplusenu.deriv.DAOD_HIGG8D1.e3601_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.423108.Pythia8EvtGen_A14NNPDF23LO_gammajet_DP1000_1500.deriv.DAOD_HIGG8D1.e4453_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364180.Sherpa_221_NNPDF30NNLO_Wenu_MAXHTPTV280_500_CFilterBVeto.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.363356.Sherpa_221_NNPDF30NNLO_ZqqZll.deriv.DAOD_HIGG8D1.e5525_s3126_r10724_p3983",
    "mc16_13TeV.364161.Sherpa_221_NNPDF30NNLO_Wmunu_MAXHTPTV70_140_BFilter.deriv.DAOD_HIGG8D1.e5340_e5984_s3126_r10724_r10726_p3983",
    "mc16_13TeV.364211.Sherpa_221_NN30NNLO_Ztt_Mll10_40_MAXHTPTV0_70_BFilter.deriv.DAOD_HIGG8D1.e5421_s3126_r10724_p3983",
]

grid.Add("AF_mc16e").datasets=[
    "mc16_13TeV.450578.aMcAtNloHerwig7EvtGen_H7UEMMHT_CT10ME_hh_bbZZ_4l.deriv.DAOD_HIGG8D1.e7396_e5984_a875_r10724_r10726_p3983",
    "mc16_13TeV.450663.aMcAtNloHerwig7EvtGen_H7UEMMHT_CT10ME_hh_4lup.deriv.DAOD_HIGG8D1.e7463_e5984_a875_r10724_r10726_p3983",
    "mc16_13TeV.450661.aMcAtNloHerwig7EvtGen_H7UEMMHT_CT10ME_hh_2l.deriv.DAOD_HIGG8D1.e7463_e5984_a875_r10724_r10726_p3983",
    "mc16_13TeV.450662.aMcAtNloHerwig7EvtGen_H7UEMMHT_CT10ME_hh_3l.deriv.DAOD_HIGG8D1.e7463_e5984_a875_r10724_r10726_p3983",
]

