// Dear emacs, this is -*- c++ -*-

#ifndef __TTH_CODE_TRUTH_SELECTOR_H__
#define __TTH_CODE_TRUTH_SELECTOR_H__

// C++
#include <string>
#include <vector>
#include <map>

// xAOD
#include "xAODTruth/TruthEventContainer.h"

//Root
#include <TH1F.h>

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

    std::vector<int> bc_children;
    std::vector<int> bc_parents;

    std::string AsStr() const;
  };

    enum decaymode {
        bb,cc,ss,
        WW,ZZ,gg,
        tautau,mumu,
        gamgam,Zgamma,taugamma,
        unclassified,noproducts,nohiggs,
        problem};
   
  

  class TruthSelector {
 
    
   public:
    TruthSelector();
    virtual ~TruthSelector();
    
    void Initialize();
    
    const std::vector<TruthPart>& SelectTruth(const xAOD::TruthParticleContainer *truths);
 
    decaymode GetHiggsDecayMode(const xAOD::TruthParticle* part);
    std::vector<std::string> GetHiggsDecayModeString(const xAOD::TruthParticleContainer *truthCont);

    void FillHiggsDecayMode(TH1F* hist, const xAOD::TruthParticleContainer *truths);
    
  private:
    
    bool IsGoodTop    (const int pdgId, const std::vector<int>& children);
    bool IsGoodHiggs  (const int pdgId, const std::vector<ttH::TruthPart> &children);
    bool IsGoodHiggs  (const int pdgId, const std::vector<int>& children);
    bool IsGoodW      (const int pdgId, const std::vector<int>& children);
    bool IsGoodZ      (const int pdgId, const std::vector<int>& children);
    bool IsGoodTau    (const int pdgId, const std::vector<int>& children);
    bool IsListA      (const int pdgId, const std::vector<int>& children);
    bool IsHadronicTau(const int pdgId, const std::vector<int>& children);
    bool HasThisChild (const int child, const std::vector<int>& children);

    bool IsStable(const xAOD::TruthParticle& truth) const;
    bool IsLepton(const xAOD::TruthParticle& truth) const;
    bool IsGenerator(int status, int barcode) const;

    std::vector<TruthPart> GetParents (const xAOD::TruthParticle &truth);
    std::vector<TruthPart> GetChildren(const xAOD::TruthParticle &truth);

    void PruneSelectedParticles();

  private:
    bool                                m_debug;
    int                                 m_ntotal;
    int                                 m_nselect;

    const xAOD::TruthParticleContainer *m_truths;
    
    std::vector<TruthPart>              m_select;
    std::map<int,std::string>           decaymodestr;
  }; // class TruthSelector
}

#endif
