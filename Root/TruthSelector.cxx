// C++
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <set>
#include <sstream>

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

//=========================================================================
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

//=========================================================================
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

  for(size_t i = 0; i < truth.nParents(); ++i) {
    const xAOD::TruthParticle *p = truth.parent(i);
    
    if(p) {
      bc_parents.push_back(p->barcode());
    }
  }

  for(size_t i = 0; i < truth.nChildren(); ++i) {
    const xAOD::TruthParticle *p = truth.child(i);
    
    if(p) {
      bc_children.push_back(p->barcode());
    }
  }
}

//=========================================================================
std::string ttH::TruthPart::AsStr() const
{
  stringstream str;
  str << "pdg ID, status, barcode, pt=" 
      << setw(5) << setfill(' ') << std::right << pdgId   << ", "
      << setw(5) << setfill(' ') << std::right << status  << ", "
      << setw(9) << setfill(' ') << std::right << barcode << ", "
      << pt;
  
  return str.str();
}

//=========================================================================
ttH::TruthSelector::TruthSelector():
  m_debug (false),
  m_truths(nullptr)
{
}

//=========================================================================
ttH::TruthSelector::~TruthSelector()
{
}

//=========================================================================
void ttH::TruthSelector::Initialize() 
{
}

//=========================================================================
const std::vector<ttH::TruthPart>& ttH::TruthSelector::SelectTruth(const xAOD::TruthParticleContainer *truths)
{
  m_select.clear();

  if(truths == nullptr) {
    return m_select;
  }

  m_truths = truths;

  if(m_debug) {
    cout << "-------------------------------------------------------------------------" << endl
	 << "Number of truth particles: " << m_truths->size() << endl;
  }
  
  for(const xAOD::TruthParticle *ptr: *m_truths) {
    if(!ptr) {
      continue;
    }

    bool pass = false;
    TruthPart p(*ptr);

    //-------------------------------------------------------------------------
    // Select list A particles
    //
    if(IsListA(p.pdgId, p.bc_children)) {
      pass = true;     

      const std::vector<ttH::TruthPart> children = GetChildren(*ptr);
      m_select.insert(m_select.end(), children.begin(), children.end());

      if(m_debug) {
	cout << "SelectTruth - select list A: " << p.AsStr() << endl;

	for(const ttH::TruthPart &part: children) {
	  cout << "              list A child:  " << part.AsStr() << endl;	
	}
      }
    }

    //-------------------------------------------------------------------------
    // Select stable leptons and their parents
    //
    if(IsStable(*ptr) && IsLepton(*ptr) && ptr->pt() > 1000.0 && IsGenerator(ptr->status(),ptr->barcode())) {
      pass = true;
      
      const std::vector<ttH::TruthPart> parents = GetParents(*ptr);
      m_select.insert(m_select.end(), parents.begin(), parents.end());

      if(m_debug) {
	cout << "SelectTruth - select lepton: " << p.AsStr() << endl;

	for(const ttH::TruthPart &part: parents) {
	  cout << "              lepton parent: " << part.AsStr() << endl;	
	}
	
	if(parents.empty()) {
	  cout << "              warning: missing lepton parent" << endl;
	}
      }
    }

    if(pass) {
      m_select.push_back(p);
    }
  }

  PruneSelectedParticles();

  m_truths = nullptr;

  return m_select;
}

//=========================================================================
bool ttH::TruthSelector::IsGoodTop(const int pdgId, const vector<int>& children) 
{
  return std::abs(pdgId) == PDG_TOP && HasThisChild(PDG_W, children) && children.size() >= 2;
}

//=========================================================================
bool ttH::TruthSelector::IsGoodHiggs(const int pdgId, const vector<int>& children)
{
  return std::abs(pdgId) == PDG_HIGGS && children.size() >= 2;
}

//=========================================================================
bool ttH::TruthSelector::IsGoodW(const int pdgId, const vector<int>& children)
{
  return std::abs(pdgId) == PDG_W && children.size() >= 2;
}

//=========================================================================
bool ttH::TruthSelector::IsGoodZ(const int pdgId, const vector<int>& children)
{
  return std::abs(pdgId) == PDG_Z && children.size() >= 2;
}
//=========================================================================
bool ttH::TruthSelector::IsGoodTau(const int pdgId, const vector<int>& children)
{
  return std::abs(pdgId) == PDG_TAU && children.size() >= 2 && HasThisChild(PDG_TAU_NEUTRINO, children);
}

//=========================================================================
bool ttH::TruthSelector::IsListA(const int pdgId, const vector<int>& children)
{
  return IsGoodTop(pdgId, children) || IsGoodHiggs(pdgId, children) || IsGoodZ(pdgId, children) || IsGoodW(pdgId, children) || IsGoodTau(pdgId, children);
}

//=========================================================================
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

//=========================================================================
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

//=========================================================================
bool ttH::TruthSelector::IsLepton(const xAOD::TruthParticle& truth) const
{
  const int pdgId = std::abs(truth.pdgId());

  if(11 <= pdgId && pdgId <= 16) {
    return true;
  }

  return false;
}

//=================================================================================
bool ttH::TruthSelector::IsGenerator(int status, int barcode) const
{
  
  return barcode < 200000 && (status < 200 ||
			      status % 1000 == 1 || status % 1000 == 2 ||
			      status == 10902);
}

//=========================================================================
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

//=========================================================================
std::vector<ttH::TruthPart> ttH::TruthSelector::GetParents(const xAOD::TruthParticle &truth)
{
  std::set<int> bc_set;

  for(size_t i = 0; i < truth.nParents(); ++i) {
    const xAOD::TruthParticle *p = truth.parent(i);
    
    if(p) {
      bc_set.insert(p->barcode());
    }
  }

  std::vector<ttH::TruthPart> out;
 
  for(const xAOD::TruthParticle *ptr: *m_truths) {
    if(!ptr) {
      continue;
    }

    if(bc_set.count(ptr->barcode())) {
      out.push_back(TruthPart(*ptr));
    }
  }

  return out;
}

//=========================================================================
std::vector<ttH::TruthPart> ttH::TruthSelector::GetChildren(const xAOD::TruthParticle &truth)
{
  std::set<int> bc_set;

  for(size_t i = 0; i < truth.nChildren(); ++i) {
    const xAOD::TruthParticle *p = truth.child(i);
    
    if(p) {
      bc_set.insert(p->barcode());
    }
  }

  std::vector<ttH::TruthPart> out;
 
  for(const xAOD::TruthParticle *ptr: *m_truths) {
    if(!ptr) {
      continue;
    }

    if(bc_set.count(ptr->barcode())) {
      out.push_back(TruthPart(*ptr));
    }
  }

  return out;
}

//=========================================================================
void ttH::TruthSelector::PruneSelectedParticles()
{
  std::set<int> bcs;

  std::vector<TruthPart>::iterator sit = m_select.begin();
  
  while(sit != m_select.end()) {
    if(bcs.insert(sit->barcode).second) {
      sit++;
    }
    else {
      sit = m_select.erase(sit);
    }
  }
}
