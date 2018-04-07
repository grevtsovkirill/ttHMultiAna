#ifndef __ttHMultileptonTau__
#define __tthMultileptonTau__ 1

#include <memory>
#include "TopEventSelectionTools/TreeManager.h"

#define MAXSYST 50

namespace ttHML {

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

	float MV2c10;
	float BDTEleScoreSigTrans;
	float BDTJetScoreSigTrans;
    
	short   promptTauInput_TrackJetNTrack;
    float   promptTauInput_JetF;
    float   promptTauInput_DRlj;
    float   promptTauInput_LepJetPtFrac;
    float   promptTauInput_SV1;
    float   promptTauInput_MV2c10rnn;
    float   promptTauInput_ip2;
    float   promptTauInput_ip3;
    float   promptTauInput_rnnip;
	float	promptTauInput_MV2c10;

  float promptTauVeto;
  float promptTauIso;
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

