
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


#include "TopEventSelectionTools/TreeManager.h"
#include "ttHMultilepton/EventData.h"
#include <vector>
#include <memory>

#define LEPTON_ARR_SIZE 5
#define TAU_ARR_SIZE 2
#define MAXSYST 50

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


    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, bool doSFSystematics);
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
    int nJets_OR_T;
    int nTruthJets;
    int nTruthJets_OR;
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






    private:

};

}

#endif

