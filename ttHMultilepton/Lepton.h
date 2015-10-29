#ifndef __ttHMultileptonLepton__
#define __tthMultileptonLepton__ 1

#include <memory>
#include "TopEventSelectionTools/TreeManager.h"

namespace ttHMultilepton {
  enum LepType { ELECTRON, MUON, GENERIC };
  struct Lepton 
  {
    double SFRecoEventWeight;
    double SFIdEventWeight;
    double SFIsoEventWeight;
    double SFRecoError;
    double SFRecoErrorSys;
    double SFIdError;
    double SFIsoError;
    double TrigSFEventWeight;
    double TrigSFError;
    float  D0;
    float  Z0SinTheta;
    float  MagD0;
    float  Pt;
    float  Eta;
    float  matchchi2;
    float  ClEta;
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
    char    isFakable;
    int     Author;
    int     allAuthor;
    int     Index;
    int     D3PDIndex;
    int     Truth_parent_particle_ID;
    int     Truth_particle_ID;

    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index);

    bool operator==(const Lepton &other) {
      // compare eta, phi, ID, bleurgh
      return (Eta==other.Eta && Phi==other.Phi && ID==other.ID);
    }
  };
}
#endif
