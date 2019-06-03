
#ifndef _EVENT_H_
#define _EVENT_H_


#include "AsgTools/AsgTool.h"
#include "xAODJet/JetContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTruth/xAODTruthHelpers.h"


#include "TopCorrections/ScaleFactorRetriever.h"
#include "TopEventSelectionTools/TreeManager.h"
#include "ttHMultilepton/EventData.h"
#include <vector>
#include <memory>

#define LEPTON_ARR_SIZE 4
#define TAU_ARR_SIZE 3
#define MAXSYST 50

class ttHMultileptonLooseEventSaver;

namespace ttHML {
    struct Variables {
    public:

      Variables();
      virtual ~Variables();
    

    ConstDataVector<xAOD::JetContainer> * selected_jets   =  new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::ElectronContainer> * selected_electrons = new ConstDataVector<xAOD::ElectronContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::MuonContainer> * selected_muons = new ConstDataVector<xAOD::MuonContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::TauJetContainer> * selected_taus = new ConstDataVector<xAOD::TauJetContainer>(SG::VIEW_ELEMENTS);

    ConstDataVector<xAOD::JetContainer> * selected_OR_jets   =  new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::ElectronContainer> * selected_OR_electrons = new ConstDataVector<xAOD::ElectronContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::MuonContainer> * selected_OR_muons = new ConstDataVector<xAOD::MuonContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::TauJetContainer> * selected_OR_taus = new ConstDataVector<xAOD::TauJetContainer>(SG::VIEW_ELEMENTS);


    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, const ttHMultileptonLooseEventSaver*,  bool doSFSystematics);
    std::shared_ptr<ttHML::EventData> m_info;
    void clearReco();
    void Clear();
	  int onelep_type;
    int dilep_type;
    int trilep_type;
    int quadlep_type;
    int total_leptons;
    int total_charge;
    char isQMisIDEvent;
    char isFakeEvent;
    char isLepFromPhEvent; // Lepton coming from a non-GEANT photon
    float Mll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    float Ptll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    float DRll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    char matchDLTll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    float Mlll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-2];
    float Mllll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-2][LEPTON_ARR_SIZE-3];
    float best_Z_Mll, best_Z_other_Mll, best_Z_other_MtLepMet;
    float minOSSFMll, minOSMll;
    float Mlt00;
    float Mlt01;
    float Mlt10;
    float Mlt11;
    float Mtt01;
    float MTlmet;     
    int nJets_OR_T;
    int nTruthJets;
    int nTruthJets_OR;
    int nJets_OR;
    int nJets_OR_T_MV2c10_60;
    int nJets_OR_T_MV2c10_70;
    int nJets_OR_T_MV2c10_77;
    int nJets_OR_T_MV2c10_85;
    int nJets_OR_MV2c10_60;
    int nJets_OR_MV2c10_77;
    int nJets_OR_MV2c10_70;
    int nJets_OR_MV2c10_85;
    int nJets_OR_T_DL1_60;
    int nJets_OR_T_DL1_70;
    int nJets_OR_T_DL1_77;
    int nJets_OR_T_DL1_85;
    int nJets_OR_DL1_60;
    int nJets_OR_DL1_77;
    int nJets_OR_DL1_70;
    int nJets_OR_DL1_85;
    int nTaus_OR_Pt25;
    int nTaus_OR_Loose;
    int nTaus_OR_Medium;
    int nTaus_OR_Tight;
    int nTaus_OR_RNN_VeryLoose;
    int nTaus_OR_RNN_Loose;
    int nTaus_OR_RNN_Medium;
    int nTaus_OR_RNN_Tight;
    bool isBlinded;
    float HT;
    float HT_lep;
    float HT_jets;
    float HT_alljets;
    float Meff;
    float lead_jetPt;
    float lead_jetEta;
    float lead_jetPhi;
    float lead_jetE;
    float sublead_jetPt;
    float sublead_jetEta;
    float sublead_jetPhi;
    float sublead_jetE;
    float lepSFIDLoose;
    float lepSFIDTight;
    float lepSFTrigLoose[MAXSYST];
    float lepSFTrigTight[MAXSYST];
    float lepSFTrigTightLoose[MAXSYST];
    float lepSFTrigLooseTight[MAXSYST];
    float lepEffTrigLoose[MAXSYST];
    float lepEffTrigTight[MAXSYST];
    float lepEffTrigTightLoose[MAXSYST];
    float lepEffTrigLooseTight[MAXSYST];
    float lepDataEffTrigLoose[MAXSYST];
    float lepDataEffTrigTight[MAXSYST];
    float lepDataEffTrigTightLoose[MAXSYST];
    float lepDataEffTrigLooseTight[MAXSYST];
    float lepSFIsoLoose;
    float lepSFIsoTight;
    float lepSFReco;
    float lepSFTTVA;
    float lepSFObjLoose[MAXSYST];
    float lepSFObjTight[MAXSYST];
    float tauSFTight[MAXSYST];
    float tauSFLoose[MAXSYST];
    std::vector<short> selected_jetsOR;
    std::vector<short> selected_jets_TOR; 
    std::vector<short> selected_jetsOR_mv2c10_Ordrd; 
    std::vector<short> selected_jets_TOR_mv2c10_Ordrd;


//Variables not for output
    int totalLeptons;
    int totalTaus;
    int totalCharge;


  std::map<top::topSFSyst, std::string> m_lep_sf_names{
    { top::topSFSyst::nominal, "nominal" },
    { top::topSFSyst::EL_SF_Trigger_UP, "EL_SF_Trigger_UP" },
    { top::topSFSyst::EL_SF_Trigger_DOWN, "EL_SF_Trigger_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_STAT_UP, "MU_SF_Trigger_STAT_UP" },
    { top::topSFSyst::MU_SF_Trigger_STAT_DOWN, "MU_SF_Trigger_STAT_DOWN" }, // do not change the order up to this point to match m_lep_trigger_sf_names
    { top::topSFSyst::MU_SF_Trigger_SYST_UP, "MU_SF_Trigger_SYST_UP" },
    { top::topSFSyst::MU_SF_Trigger_SYST_DOWN, "MU_SF_Trigger_SYST_DOWN" },
    { top::topSFSyst::EL_SF_Reco_UP, "EL_SF_Reco_UP" },
    { top::topSFSyst::EL_SF_Reco_DOWN, "EL_SF_Reco_DOWN" },
    { top::topSFSyst::EL_SF_ID_UP, "EL_SF_ID_UP" },
    { top::topSFSyst::EL_SF_ID_DOWN, "EL_SF_ID_DOWN" },
    { top::topSFSyst::EL_SF_Isol_UP, "EL_SF_Isol_UP" },
    { top::topSFSyst::EL_SF_Isol_DOWN, "EL_SF_Isol_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_UP, "MU_SF_Trigger_UP" },
    { top::topSFSyst::MU_SF_Trigger_DOWN, "MU_SF_Trigger_DOWN" },
    { top::topSFSyst::MU_SF_ID_STAT_UP, "MU_SF_ID_STAT_UP" },
    { top::topSFSyst::MU_SF_ID_STAT_DOWN, "MU_SF_ID_STAT_DOWN" },
    { top::topSFSyst::MU_SF_ID_SYST_UP, "MU_SF_ID_SYST_UP" },
    { top::topSFSyst::MU_SF_ID_SYST_DOWN, "MU_SF_ID_SYST_DOWN" },
    { top::topSFSyst::MU_SF_Isol_STAT_UP, "MU_SF_Isol_STAT_UP" },
    { top::topSFSyst::MU_SF_Isol_STAT_DOWN, "MU_SF_Isol_STAT_DOWN" },
    { top::topSFSyst::MU_SF_Isol_SYST_UP, "MU_SF_Isol_SYST_UP" },
    { top::topSFSyst::MU_SF_Isol_SYST_DOWN, "MU_SF_Isol_SYST_DOWN" },
    { top::topSFSyst::MU_SF_TTVA_STAT_UP, "MU_SF_TTVA_STAT_UP" },
    { top::topSFSyst::MU_SF_TTVA_STAT_DOWN, "MU_SF_TTVA_STAT_DOWN" },
    { top::topSFSyst::MU_SF_TTVA_SYST_UP, "MU_SF_TTVA_SYST_UP" },
    { top::topSFSyst::MU_SF_TTVA_SYST_DOWN, "MU_SF_TTVA_SYST_DOWN" },
    { top::topSFSyst::MU_SF_ID_STAT_LOWPT_UP, "MU_SF_ID_STAT_LOWPT_UP" },
    { top::topSFSyst::MU_SF_ID_STAT_LOWPT_DOWN, "MU_SF_ID_STAT_LOWPT_DOWN" },
    { top::topSFSyst::MU_SF_ID_SYST_LOWPT_UP, "MU_SF_ID_SYST_LOWPT_UP" },
    { top::topSFSyst::MU_SF_ID_SYST_LOWPT_DOWN, "MU_SF_ID_SYST_LOWPT_DOWN" },
  };


   std::map<top::topSFSyst, std::string> m_tau_sf_names{
      { top::topSFSyst::nominal, "nominal" },
      { top::topSFSyst::TAU_SF_ELEOLR_TOTAL_UP,   "TAU_SF_ELEOLR_TOTAL_UP"  },
      { top::topSFSyst::TAU_SF_ELEOLR_TOTAL_DOWN, "TAU_SF_ELEOLR_TOTAL_DOWN"},
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_HIGHMU_UP,   "TAU_SF_TRUEELECTRON_ELEOLR_HIGHMU_UP"  },
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_HIGHMU_DOWN, "TAU_SF_TRUEELECTRON_ELEOLR_HIGHMU_DOWN"},
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_LOWMU_UP,   "TAU_SF_TRUEELECTRON_ELEOLR_LOWMU_UP"  },
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_LOWMU_DOWN, "TAU_SF_TRUEELECTRON_ELEOLR_LOWMU_DOWN"},
      { top::topSFSyst::TAU_SF_JETID_1P2530_UP,    "TAU_SF_JETID_1P2530_UP"   },
      { top::topSFSyst::TAU_SF_JETID_1P2530_DOWN,  "TAU_SF_JETID_1P2530_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_1P3040_UP,    "TAU_SF_JETID_1P3040_UP"   },
      { top::topSFSyst::TAU_SF_JETID_1P3040_DOWN,  "TAU_SF_JETID_1P3040_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_1PGE40_UP,    "TAU_SF_JETID_1PGE40_UP"   },
      { top::topSFSyst::TAU_SF_JETID_1PGE40_DOWN,  "TAU_SF_JETID_1PGE40_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_3P2030_UP,    "TAU_SF_JETID_3P2030_UP"   },
      { top::topSFSyst::TAU_SF_JETID_3P2030_DOWN,  "TAU_SF_JETID_3P2030_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_3PGE30_UP,    "TAU_SF_JETID_3PGE30_UP"   },
      { top::topSFSyst::TAU_SF_JETID_3PGE30_DOWN,  "TAU_SF_JETID_3PGE30_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_HIGHPT_UP,   "TAU_SF_JETID_HIGHPT_UP"  },
      { top::topSFSyst::TAU_SF_JETID_HIGHPT_DOWN, "TAU_SF_JETID_HIGHPT_DOWN"},
      { top::topSFSyst::TAU_SF_RECO_TOTAL_UP,     "TAU_SF_RECO_TOTAL_UP"    },
      { top::topSFSyst::TAU_SF_RECO_TOTAL_DOWN,   "TAU_SF_RECO_TOTAL_DOWN"  },
      { top::topSFSyst::TAU_SF_RECO_HIGHPT_UP,    "TAU_SF_RECO_HIGHPT_UP"   },
      { top::topSFSyst::TAU_SF_RECO_HIGHPT_DOWN,  "TAU_SF_RECO_HIGHPT_DOWN" },
        };private:

};

}

#endif

