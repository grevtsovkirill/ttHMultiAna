#ifndef __ttHMultileptonTau__
#define __tthMultileptonTau__ 1

#include <memory>
#include "TopEventSelectionTools/TreeManager.h"

#define MAXSYST 50

namespace ttHMultilepton {

  struct Tau {
    float pt;
    float eta;
    float phi;
    float charge;
    float e;
    double BDTJetScore;
    int JetBDTSigLoose;
    int JetBDTSigMedium;
    int JetBDTSigTight;
    int numTrack;
    int isHadronic;
    int tagWeightBin;
    char fromPV;
    float SFTight[MAXSYST];
    float SFLoose[MAXSYST];

    int passEleOLR, passEleBDT, passMuonOLR;
    int truthOrigin, truthType, truthJetFlavour;

    bool operator==(const Tau &other) {
      // compare eta, phi, bleurgh
      return (eta==other.eta && phi==other.phi);
    }
    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index);
  };
}
#endif
