#ifndef ttHMultilepton_Variables
#define ttHMultilepton_Variables 1
#include "TopEventSelectionTools/TreeManager.h"
#include <memory>
#define LEPTON_ARR_SIZE 5
#define TAU_ARR_SIZE 1

namespace ttHMultilepton {
  struct Variables {
    int onelep_type;
    int dilep_type;
    int trilep_type;
    int quadlep_type;
    int total_leptons;
    int total_charge;
    float Mll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    float Ptll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    float DRll[LEPTON_ARR_SIZE-1][LEPTON_ARR_SIZE-1];
    int nJets_OR_T;
    int nJets_OR_T_MV2c20_70;
    int nJets_OR_T_MV2c20_77;
    int nTaus_OR_Pt25;
    bool isBlinded;
    float HT;
    float HT_lep;
    float HT_jets;
    float lead_jetPt;
    float lead_jetEta;
    float lead_jetPhi;
    float sublead_jetPt;
    float sublead_jetEta;
    float sublead_jetPhi;
    float lepSFIDLoose;
    float lepSFIDTight;
    float lepSFTrigLoose;
    float lepSFTrigTight;
    float lepSFIsoLoose;
    float lepSFIsoTight;
    float lepSFReco;
    float lepSFTTVA;
    float lepSFObjLoose;
    float lepSFObjTight;
    void BootstrapTree(std::shared_ptr<top::TreeManager> tree);
    void Clear() { memset(this, 0, sizeof(Variables)); }
  };
}

#endif
