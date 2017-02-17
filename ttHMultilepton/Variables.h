#ifndef ttHMultilepton_Variables
#define ttHMultilepton_Variables 1
#include "TopEventSelectionTools/TreeManager.h"
#include <memory>
#define LEPTON_ARR_SIZE 5
#define TAU_ARR_SIZE 2
#define MAXSYST 50

class ttHMultileptonLooseEventSaver;

namespace ttHMultilepton {
  struct Variables {
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
    float best_Z_Mll, best_Z_other_Mll;
    int nJets_OR_T;
    int nJets_OR;
    int nJets_OR_T_MV2c20_60;
    int nJets_OR_T_MV2c20_70;
    int nJets_OR_T_MV2c20_77;
    int nJets_OR_T_MV2c20_85;
    int nJets_OR_MV2c20_60;
    int nJets_OR_MV2c20_77;
    int nJets_OR_MV2c20_70;
    int nJets_OR_MV2c20_85;
    int nJets_OR_T_MV2c10_60;
    int nJets_OR_T_MV2c10_70;
    int nJets_OR_T_MV2c10_77;
    int nJets_OR_T_MV2c10_85;
    int nJets_OR_MV2c10_60;
    int nJets_OR_MV2c10_77;
    int nJets_OR_MV2c10_70;
    int nJets_OR_MV2c10_85;
    int nTaus_OR_Pt25;
    bool isBlinded;
    float HT;
    float HT_lep;
    float HT_jets;
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
    float lepSFIsoLoose;
    float lepSFIsoTight;
    float lepSFReco;
    float lepSFTTVA;
    float lepSFObjLoose[MAXSYST];
    float lepSFObjTight[MAXSYST];
    float tauSFTight[MAXSYST];
    float tauSFLoose[MAXSYST];
    std::vector<short> selected_jets;
    std::vector<short> selected_jets_T;
    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, const ttHMultileptonLooseEventSaver* ntupler, bool doSFSystematics);
    void Clear() { memset(this, 0, sizeof(Variables)); }
  };
}

#endif
