// C++
#include <iostream>
#include <math.h>
#include <cstdlib>

// Top
#include "TopEvent/Event.h"

// Local
#include "ttHMultilepton/TruthSelector.h"

using namespace std;

const static int PDG_CHARM = 4;
const static int PDG_BOTTOM = 5;
const static int PDG_TOP = 6;
const static int PDG_ELECTRON = 11;
const static int PDG_ELECTRON_NEUTRINO = 12;
const static int PDG_MUON = 13;
const static int PDG_MUON_NEUTRINO = 14;
const static int PDG_TAU = 15;
const static int PDG_TAU_NEUTRINO = 16;
const static int PDG_GAMMA = 22;
const static int PDG_Z = 23;
const static int PDG_W = 24;
const static int PDG_HIGGS = 25;

const static int NOT_SELECTED = -1;

//-------------------------------------------------------------------------
ttH::TruthPart::TruthPart():
  m          (0.0),
  pt         (0.0),
  eta        (0.0),
  phi        (0.0),
  e          (0.0),
  pdgId      (0),
  status     (0),
  barcode    (0),
  parentPdgId(0)
{
}

//-------------------------------------------------------------------------
ttH::TruthPart::TruthPart(const xAOD::TruthParticle &truth):
  m          (truth.m()),
  pt         (truth.pt()),
  eta        (0.0),
  phi        (0.0),
  e          (truth.e()),
  pdgId      (truth.pdgId()),
  status     (truth.status()),
  barcode    (truth.barcode()),
  parentPdgId(0)
{
  if(truth.pt() > 1.0) {
    eta = truth.eta();
    phi = truth.phi();
  }
}

//-------------------------------------------------------------------------
ttH::TruthSelector::TruthSelector():
  m_truths(nullptr)
{
}

//-------------------------------------------------------------------------
ttH::TruthSelector::~TruthSelector()
{
}

//-------------------------------------------------------------------------
void ttH::TruthSelector::Initialize() 
{
}

//-------------------------------------------------------------------------
const std::vector<ttH::TruthPart>& ttH::TruthSelector::SelectTruth(const xAOD::TruthParticleContainer *truths)
{
  m_select.clear();

  if(truths == nullptr) {
    return m_select;
  }

  m_truths = truths;

  for(const xAOD::TruthParticle *ptr: *m_truths) {
  }

  m_truths = nullptr;

  return m_select;
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsGoodTop(const int pdgId, const vector<int>& children) 
{
  return pdgId == PDG_TOP && HasThisChild(PDG_W, children) && children.size() >= 2;
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsGoodHiggs(const int pdgId, const vector<int>& children)
{
  return pdgId == PDG_HIGGS && children.size() >= 2;
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsGoodW(const int pdgId, const vector<int>& children)
{
  return pdgId == PDG_W && children.size() >= 2;
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsGoodZ(const int pdgId, const vector<int>& children)
{
  return pdgId == PDG_Z && children.size() >= 2;
}
//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsGoodTau(const int pdgId, const vector<int>& children)
{
  return pdgId == PDG_TAU && children.size() >= 2 && HasThisChild(PDG_TAU_NEUTRINO, children);
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsListA(const int pdgId, const vector<int>& children)
{
  return IsGoodTop(pdgId, children) || IsGoodHiggs(pdgId, children) || IsGoodZ(pdgId, children) || IsGoodW(pdgId, children) || IsGoodTau(pdgId, children);
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsHadronicTau(const int pdgId, const vector<int>& children)
{
  if(std::abs(pdgId) != PDG_TAU) {
    return false;
  }

  if(children.size() < 2) {
    return false;
  }

  if(HasThisChild(PDG_ELECTRON, children) || HasThisChild(PDG_MUON, children)) {
    return false;
  }

  return HasThisChild(PDG_TAU_NEUTRINO, children);
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::IsStable(const xAOD::TruthParticle& truth) const
{
  const int   pdgId  = std::abs(truth.pdgId());
  const int   status = truth.status();
  const float pt     = truth.pt();

  if(pdgId == 22 && !(pt > 0.0)) {
    return false;
  }

  if(status % 1000 == 1) {
    return true;
  }

  if(status % 1000 == 2 && status > 1000) {
    return true;
  }

  return false;
}

//-------------------------------------------------------------------------
bool ttH::TruthSelector::HasThisChild(const int childID, const vector<int>& children)
{
  for(size_t i = 0; i < children.size(); i++) {
    const int bc = children.at(i);

    for(const xAOD::TruthParticle *ptr: *m_truths) {
      if(ptr->barcode() != bc) {
	continue;
      }

      if(std::abs(ptr->pdgId()) == childID) {
	return true;
      }
    }
  }

  return false;
}
