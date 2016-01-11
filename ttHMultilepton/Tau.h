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
    double BDTJetScore;
    int JetBDTSigLoose;
    int JetBDTSigMedium;
    int JetBDTSigTight;
    int numTrack;
    float SFTight[MAXSYST];
    float SFLoose[MAXSYST];
    

    bool operator==(const Tau &other) {
      // compare eta, phi, bleurgh
      return (eta==other.eta && phi==other.phi);
    }
    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index);
  };
}
#endif
