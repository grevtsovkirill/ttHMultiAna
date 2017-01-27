#ifndef __ttHMultileptonLepton__
#define __tthMultileptonLepton__ 1

#include <memory>
#include "TopEventSelectionTools/TreeManager.h"

#define MAXSYST 50

namespace ttHMultilepton {
  enum LepType { ELECTRON, MUON, GENERIC };
  struct Lepton
  {
    float SFIDTight[MAXSYST];
    float SFIDLoose[MAXSYST];
    //double SFIsoEventWeight;
    //double SFRecoError;
    //double SFRecoErrorSys;
    //double SFIdError;
    //double SFIsoError;
    float SFTrigTight[MAXSYST];
    float SFTrigLoose[MAXSYST];
    float SFIsoTight[MAXSYST];
    float SFIsoLoose[MAXSYST];
    float SFReco[MAXSYST];
    float SFTTVA[MAXSYST];
    float SFObjTight[MAXSYST];
    float SFObjLoose[MAXSYST];
    float  d0;
    float  z0;
    float  vz;
    float  deltaz0;
    float  Z0SinTheta;
    float  MagD0;
    float  Pt;
    float  Eta;
    float  matchchi2;
    float  EtaBE2;
    float  Phi;
    float  Charge;
    float  Px;
    float  Py;
    float  Pz;
    float  E;
    float  z0PV;
    float  sigd0PV;
    float  ID;
    float  PtID;
    float  PtIDuncorr;
    float  PtME;
    float  PtMEuncorr;
    bool   Match_EF_mu24_tight;
    bool   Match_EF_mu24i_tight;
    bool   Match_EF_mu36_tight;
    bool   Match_EF_mu40_MSonly_barrel_tight;
    bool   Match_EF_mu18_tight;
    bool   Match_EF_mu8_EFFS;
    bool   Match_EF_mu13;
    bool   Match_EF_e22vh_medium1;
    bool   Match_EF_e24vhi_medium1;
    bool   Match_EF_e45_medium1;
    bool   Match_EF_e60_medium1;
    bool   Match_EF_e12Tvh_loose1;
    float  Etcone20;
    float  Etcone30;
    float  Etcone40;
    float  Etcone20Uncorr;
    float  Etcone30Uncorr;
    float  Etcone40Uncorr;
    float  Ptcone20;
    float  Ptcone30;
    float  Ptcone40;
    int    Nucone20;
    int    Nucone30;
    int    Nucone40;
    float  MI10_max40_ptsum;
    float  Eiso90Etcone20;
    float  Eiso90ptcone30;
    float  HSG3Iso;
    char    BLayer_hit;
    char    conv;
    char    isTightPP;
    char    isMediumPP;
    char    isLoosePP;
    char    isMultiLepton;
    char    isVeryTightLH;
    char    isTightLH;
    char    isMediumLH;
    char    isLooseLH;
    char    isVeryLooseLH;
    char    isCombined;
    char    isTight;
    char    isMedium;
    char    isLoose;
    char    isHSG3Clear;
    char    isHSG3IsoClear;
    int    isolationLooseTrackOnly;
    int    isolationLoose;
    int    isolationGradient;
    int    isolationGradientLoose;
    int    isolationFixedCutTight;
    int    isolationFixedCutTightTrackOnly;
    int    isolationFixedCutLoose;

    char    isTrigMatch;
    char    isTrigMatchDLT;
    char    isFakable;
    int     Author;
    int     allAuthor;
    int     Index;
    int     D3PDIndex;
    int     Truth_parent_particle_ID;
    int     Truth_particle_ID;

    char    isPrompt;
    char    isFakeLep;
    char    isQMisID;
    char    isConvPh;
    char    isISR_FSR_Ph;
    char    isBrems;

    float   chargeIDBDTLoose;
    float   chargeIDBDTMedium;
    float   chargeIDBDTTight;
    float   promptLeptonIso_TagWeight;
    short   promptLeptonIso_sv1_jf_ntrkv;
    short   promptLeptonIso_TrackJetNTrack;
    float   promptLeptonIso_ip2;
    float   promptLeptonIso_ip3;
    float   promptLeptonIso_DRlj;
    float   promptLeptonIso_LepJetPtFrac;
    float   promptLepton_TagWeight;
    float   promptLeptonNoIso_TagWeight;

    char    isTruthMatched;
    int     truthPdgId;
    int     truthStatus;
    int     truthType;
    int     truthOrigin;
    int     truthParentPdgId;
    int     truthParentStatus;
    int     truthParentType;
    int     truthParentOrigin;
    float   truthPt;
    float   truthEta;
    float   truthPhi;
    float   truthM;
    float   truthE;
    float   truthRapidity;

    float   topoEtcone20;
    float   topoEtcone30;
    float   topoEtcone40;
    float   ptVarcone20;
    float   ptVarcone30;
    float   ptVarcone40;

    float   EffTrigLoose[MAXSYST];
    float   EffTrigTight[MAXSYST];

    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index);

    bool operator==(const Lepton &other) {
      // compare eta, phi, ID, bleurgh
      return (Eta==other.Eta && Phi==other.Phi && ID==other.ID);
    }
  };
}
#endif
