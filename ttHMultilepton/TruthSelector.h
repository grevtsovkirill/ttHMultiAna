// Dear emacs, this is -*- c++ -*-
#ifndef __TTH_CODE_TRUTH_SELECTOR_H__
#define __TTH_CODE_TRUTH_SELECTOR_H__

// C++
#include <string>
#include <vector>

// xAOD
#include "xAODTruth/TruthEventContainer.h"

namespace ttH 
{
  struct TruthPart 
  {
    TruthPart();
    explicit TruthPart(const xAOD::TruthParticle &truth);

    float m;
    float pt;
    float eta;
    float phi;
    float e;
    int   pdgId;
    int   status;
    int   barcode;
    int   parentPdgId;  

    std::vector<int> bc_childrens;
    std::vector<int> bc_parentss;
  };


  class TruthSelector {
  public:
    
    TruthSelector();
    virtual ~TruthSelector();
    
    void Initialize();
    
    const std::vector<TruthPart>& SelectTruth(const xAOD::TruthParticleContainer *truths);
    
  private:
    
    bool IsGoodTop    (const int pdgId, const std::vector<int>& children);
    bool IsGoodHiggs  (const int pdgId, const std::vector<int>& children);
    bool IsGoodW      (const int pdgId, const std::vector<int>& children);
    bool IsGoodZ      (const int pdgId, const std::vector<int>& children);
    bool IsGoodTau    (const int pdgId, const std::vector<int>& children);
    bool IsListA      (const int pdgId, const std::vector<int>& children);
    bool IsHadronicTau(const int pdgId, const std::vector<int>& children);
    bool HasThisChild (const int child, const std::vector<int>& children);

    bool IsStable     (const xAOD::TruthParticle& truth) const;

  private:
    
    const xAOD::TruthParticleContainer *m_truths;
    
    std::vector<TruthPart>              m_select;
  }; // class TruthSelector
}

#endif // __HWW_TTH_CODE_TRUTH_SELECTOR_H__
