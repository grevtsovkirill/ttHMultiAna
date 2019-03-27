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

const static int PDG_LQu = 43;// mistake?????
const static int PDG_LQd = 42;

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
     decaymodestr[bb]           = "bb";
     decaymodestr[cc]           = "cc";
     decaymodestr[ss]           = "ss";
     decaymodestr[WW]           = "WW";
     decaymodestr[ZZ]           = "ZZ";
     decaymodestr[gg]           = "gg";
     decaymodestr[tautau]       = "tautau";
     decaymodestr[mumu]         = "mumu";
     decaymodestr[gamgam]       = "gamgam";
     decaymodestr[Zgamma]       = "Zgamma";
     decaymodestr[taugamma]     = "taugamma";
     decaymodestr[unclassified] = "unclassified";
     decaymodestr[noproducts]   = "noproducts";
     decaymodestr[nohiggs]      = "nohiggs";
     decaymodestr[problem]      = "problem";

     LQdecaymodestr[ttau]           = "ttau";
     LQdecaymodestr[tnu]            = "tnu";
     LQdecaymodestr[btau]           = "btau";
     LQdecaymodestr[bnu]            = "bnu";
     LQdecaymodestr[unclassifiedLQ] = "unclassified";
     LQdecaymodestr[noproductsLQ]   = "noproducts";
     LQdecaymodestr[noLQ]           = "noLQ";
     LQdecaymodestr[problemLQ]      = "problem";
     LQdecaymodestr[ttau]           = "tmu";
     LQdecaymodestr[tnu]            = "tel";
     LQdecaymodestr[btau]           = "bmu";
     LQdecaymodestr[bnu]            = "bel";

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

ttH::decaymode ttH::TruthSelector::GetHiggsDecayMode(const xAOD::TruthParticleContainer* cont)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodHiggs(p.pdgId,p.bc_children) )
        {
            std::vector<int> higgs_cpdg;
            higgs_cpdg.clear();

            for(unsigned int mcp_c = 0; mcp_c < GetChildren(*part).size();mcp_c++)
            {
                ttH::TruthPart child = GetChildren(*part).at(mcp_c);
                int cpdg = child.pdgId;
                
                //15: status 2
                //5 : status 23
                //24: status 22
                //23: status 22?
                //22: status 1, 23?
                //13: status 1
                //21: status 23
                if(abs(cpdg) == 5)
                {
                    //if(child.status !=23) continue;
                    higgs_cpdg.push_back(cpdg);
                }
                else if(abs(cpdg)==24)
                {
                    //if(child.status !=22) continue;
                    higgs_cpdg.push_back(cpdg);
                }
                else if(abs(cpdg)==15)
                {
                    //if(child.status !=2) continue;
                    higgs_cpdg.push_back(cpdg);
                }
                else if(abs(cpdg)==4)
                {
                    //if(child.status !=23) continue;
                    higgs_cpdg.push_back(cpdg);
                }
                else if(abs(cpdg)==23)
                {
                    //if(child.status !=22) continue;
                    higgs_cpdg.push_back(cpdg);
                }
                else if(abs(cpdg)==21)
                {
                     //if(child.status !=23) continue;
                     higgs_cpdg.push_back(cpdg);
                 }
                 else if(abs(cpdg)==22)
                 {
                     //if(child.status !=1 && child.status !=23) continue;
                     higgs_cpdg.push_back(cpdg);
                 }
                 else if(abs(cpdg)==13)
                 {
                     //if(child.status !=1) continue;
                     higgs_cpdg.push_back(cpdg);
                 }
                 else if(abs(cpdg)==3)
                 {
                     //if(child.status !=23) continue;
                     higgs_cpdg.push_back(cpdg);
                  }   
            }
                      
            int gammacount = 0;
            //if there is one (or more) extra gamma(s), remove it(them)
            if(higgs_cpdg.size() > 2 )
            {
                gammacount = count(higgs_cpdg.begin(), higgs_cpdg.end(), 22);
                if(higgs_cpdg.size() - gammacount >= 1)
                {
                    vector<int>::iterator pos;
                    //if only 1 other particle + photons, leave last photon
                    if(higgs_cpdg.size() - gammacount == 1) gammacount--;
                    for(int iter = 0; iter < gammacount; iter++)
                    {
                        pos = find(higgs_cpdg.begin(), higgs_cpdg.end(),22);
                        higgs_cpdg.erase(pos);
                    }
                }
            }

            if(higgs_cpdg.size()==2)
            {
                if(higgs_cpdg[0] + higgs_cpdg[1] == 0)
                {
                    if(abs(higgs_cpdg[0]) == 5) return bb;
                    if(abs(higgs_cpdg[0]) == 3) return ss;
                    if(abs(higgs_cpdg[0]) == 24) return WW;
                    if(abs(higgs_cpdg[0]) == 23) return ZZ;
                    if(abs(higgs_cpdg[0]) == 4) return cc;
                    if(abs(higgs_cpdg[0]) == 15) return tautau;
                    if(abs(higgs_cpdg[0]) == 22) return gamgam;
                    if(abs(higgs_cpdg[0]) == 13) return mumu;
                    if(abs(higgs_cpdg[0]) == 21) return gg;
                }
                else if(higgs_cpdg[0] == higgs_cpdg[1])
                {
                    if(higgs_cpdg[0] == 23) return ZZ;
                    if(higgs_cpdg[0] == 22) return gamgam;
                    if(higgs_cpdg[0] == 21) return gg;
                }
                //else if(higgs_cpdg[0] + higgs_cpdg[1] == 45) return Zgamma;
                else if(higgs_cpdg[0] == 22 && higgs_cpdg[1] == 23) return Zgamma;
                else if(higgs_cpdg[0] == 23 && higgs_cpdg[1] == 22) return Zgamma;
                else if(abs(higgs_cpdg[0]) == 15 && higgs_cpdg[1] == 22) return taugamma;
                else if(higgs_cpdg[0] == 22 && abs(higgs_cpdg[1]) == 15) return taugamma;
                else cerr << "1 = " << higgs_cpdg[0] << ", 2 = " << higgs_cpdg[1] << endl;
            }
	    std::cout<<"Warning: Higgs children size: "<<higgs_cpdg.size() <<std::endl;
            return unclassified;   
        }
    }
    return unclassified;
}

ttH::LQdecaymode ttH::TruthSelector::GetLQDecayMode(const xAOD::TruthParticleContainer* cont, bool LQbar)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodLQ(p.pdgId,p.bc_children) )
        {
	  
	  if(LQbar&&part->pdgId()>0)continue;
	  if(!(LQbar)&&part->pdgId()<0)continue;	  

	    
            std::vector<int> LQ_cpdg;
            LQ_cpdg.clear();

	    part = findAfterFSR(part);

            for(unsigned int mcp_c = 0; mcp_c < GetChildren(*part).size();mcp_c++)
            {
                ttH::TruthPart child = GetChildren(*part).at(mcp_c);
                int cpdg = child.pdgId;		
		LQ_cpdg.push_back(cpdg);
	    }                      
            int gammacount = 0;
            //if there is one (or more) extra gamma(s), remove it(them)
            if(LQ_cpdg.size() > 2 )
            {
                gammacount = count(LQ_cpdg.begin(), LQ_cpdg.end(), 22);
                if(LQ_cpdg.size() - gammacount >= 1)
                {
                    vector<int>::iterator pos;
                    //if only 1 other particle + photons, leave last photon
                    if(LQ_cpdg.size() - gammacount == 1) gammacount--;
                    for(int iter = 0; iter < gammacount; iter++)
                    {
                        pos = find(LQ_cpdg.begin(), LQ_cpdg.end(),22);
                        LQ_cpdg.erase(pos);
                    }
                }
            }
 
            if(LQ_cpdg.size()==2)
            {
	      if(abs(LQ_cpdg[0]) == 6 && abs(LQ_cpdg[1]) == 15) return ttau;
	      else if(abs(LQ_cpdg[0]) == 15 && abs(LQ_cpdg[1]) == 6) return ttau;
	      else if(abs(LQ_cpdg[0]) == 5 && abs(LQ_cpdg[1]) == 15) return btau;
	      else if(abs(LQ_cpdg[0]) == 15 && abs(LQ_cpdg[1]) == 5) return btau;
	      else if(abs(LQ_cpdg[0]) == 5 && abs(LQ_cpdg[1]) == 12) return bnu;
	      else if(abs(LQ_cpdg[0]) == 5 && abs(LQ_cpdg[1]) == 14) return bnu;
	      else if(abs(LQ_cpdg[0]) == 5 && abs(LQ_cpdg[1]) == 16) return bnu;
	      else if(abs(LQ_cpdg[0]) == 12 && abs(LQ_cpdg[1]) == 5) return bnu;
	      else if(abs(LQ_cpdg[0]) == 14 && abs(LQ_cpdg[1]) == 5) return bnu;
	      else if(abs(LQ_cpdg[0]) == 16 && abs(LQ_cpdg[1]) == 5) return bnu;
	      else if(abs(LQ_cpdg[0]) == 6 && abs(LQ_cpdg[1]) == 12) return tnu;
	      else if(abs(LQ_cpdg[0]) == 6 && abs(LQ_cpdg[1]) == 14) return tnu;
	      else if(abs(LQ_cpdg[0]) == 6 && abs(LQ_cpdg[1]) == 16) return tnu;
	      else if(abs(LQ_cpdg[0]) == 12 && abs(LQ_cpdg[1]) == 6) return tnu;
	      else if(abs(LQ_cpdg[0]) == 14 && abs(LQ_cpdg[1]) == 6) return tnu;
	      else if(abs(LQ_cpdg[0]) == 16 && abs(LQ_cpdg[1]) == 6) return tnu;
	      else if(abs(LQ_cpdg[0]) == 6 && abs(LQ_cpdg[1]) == 13) return tmu;
	      else if(abs(LQ_cpdg[0]) == 13 && abs(LQ_cpdg[1]) == 6) return tmu;
	      else if(abs(LQ_cpdg[0]) == 6 && abs(LQ_cpdg[1]) == 11) return tel;
	      else if(abs(LQ_cpdg[0]) == 11 && abs(LQ_cpdg[1]) == 6) return tel;
	      else if(abs(LQ_cpdg[0]) == 5 && abs(LQ_cpdg[1]) == 13) return bmu;
	      else if(abs(LQ_cpdg[0]) == 13 && abs(LQ_cpdg[1]) == 5) return bmu;
	      else if(abs(LQ_cpdg[0]) == 5 && abs(LQ_cpdg[1]) == 13) return bel;
	      else if(abs(LQ_cpdg[0]) == 13 && abs(LQ_cpdg[1]) == 5) return bel;

	      else cerr << "1 = " << LQ_cpdg[0] << ", 2 = " << LQ_cpdg[1] << endl;
            }
	    std::cout<<"Warning: LQ children size: "<<LQ_cpdg.size() <<std::endl;
            return unclassifiedLQ;   
        }
    }
    return unclassifiedLQ;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetHiggs(const xAOD::TruthParticleContainer* cont)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodHiggs(p.pdgId,p.bc_children))
        {
	  return part;
	}
    }
    
    return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetLQ(const xAOD::TruthParticleContainer* cont)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodLQ(p.pdgId,p.bc_children) && p.pdgId>0)
        {
	  return findAfterFSR(part);
	}
    }
    
    return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetLQbar(const xAOD::TruthParticleContainer* cont)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodLQ(p.pdgId,p.bc_children) && p.pdgId<0)
        {
	  return findAfterFSR(part);
	}
    }
    
    return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetLQlep(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQbar(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetLQ(cont));
  for (auto child : children) {
    //    if (child.pdgId == PDG_ELECTRON || child.pdgId == PDG_MUON || child.pdgId == PDG_TAU) {
    if (IsLepton(child)) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetLQbarlep(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQbar(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetLQbar(cont));
  for (auto child : children) {
    //    if (child.pdgId == PDG_ELECTRON || child.pdgId == PDG_MUON || child.pdgId == PDG_TAU) {
    if (IsLepton(child)) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetLQq(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQ(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetLQ(cont));
  for (auto child : children) {
    //    if (child.pdgId == PDG_ELECTRON || child.pdgId == PDG_MUON || child.pdgId == PDG_TAU) {
    if (!IsLepton(child)) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetLQbarq(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQbar(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetLQbar(cont));
  for (auto child : children) {
    //    if (child.pdgId == PDG_ELECTRON || child.pdgId == PDG_MUON || child.pdgId == PDG_TAU) {
    if (!IsLepton(child)) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetTop(const xAOD::TruthParticleContainer* cont)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodTop(p.pdgId,p.bc_children) && p.pdgId>0 )
        {
	  return part;
	}
    }
    
    return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetTopW(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQ(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetTop(cont));
  for (auto child : children) {
    if (IsGoodW(child.pdgId, child.bc_children) && child.pdgId>0) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetTopWLep(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQ(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetTopW(cont));
  for (auto child : children) {
    if (child.pdgId == -PDG_ELECTRON || child.pdgId == -PDG_MUON || child.pdgId == -PDG_TAU) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetAntiTop(const xAOD::TruthParticleContainer* cont)
{
    m_truths    = cont;
    for(const xAOD::TruthParticle *part: *m_truths)
    {
        if(!part)
        {
            continue;
        }
	TruthPart p(*part);
        if(IsGoodTop(p.pdgId,p.bc_children) && p.pdgId<0 )
        {
	  return part;
	}
    }
    
    return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetAntiTopW(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQ(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetAntiTop(cont));
  for (auto child : children) {
    if (IsGoodW(child.pdgId, child.bc_children) && child.pdgId<0) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
}

//=========================================================================
const xAOD::TruthParticle* ttH::TruthSelector::GetAntiTopWLep(const xAOD::TruthParticleContainer* cont)
{
  if(GetLQ(cont)==nullptr) return nullptr;
  const std::vector<ttH::TruthPart> children = GetChildren(*GetAntiTopW(cont));
  for (auto child : children) {
    if (child.pdgId == PDG_ELECTRON || child.pdgId == PDG_MUON || child.pdgId == PDG_TAU) {
      for (const xAOD::TruthParticle *part: *cont) {
        if (part->barcode() == child.barcode) {
          return part;
        }
      }
    }
  }
  return nullptr;
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
bool ttH::TruthSelector::IsGoodLQ(const int pdgId, const vector<int>& children)
{
  return (std::abs(pdgId) == PDG_LQu || std::abs(pdgId) == PDG_LQd)&& children.size() >= 2;
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

//=========================================================================
bool ttH::TruthSelector::IsLepton(const ttH::TruthPart& truth) const
{
  const int pdgId = std::abs(truth.pdgId);

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
  std::vector<ttH::TruthPart> out;
  std::set<int> bc_set;

  for(size_t i = 0; i < truth.nChildren(); ++i) {
    const xAOD::TruthParticle *p = truth.child(i);
    
    if(p) {
      bc_set.insert(p->barcode());
    }
  }

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

//=========================================================================
unsigned int ttH::TruthSelector::CountJets(const xAOD::JetContainer* truthJets, const xAOD::TruthParticleContainer* truthParticles)
{
  uint jet_n = 0;
  for( auto jet: *truthJets) {
    bool overlaps = false;
    for( auto tp: *truthParticles){
      if( IsStable(*tp) and IsLepton(*tp) and tp->pt() > 25e3 and fabs(tp->eta()) < 2.5) {
	if(tp->p4().DeltaR(jet->p4()) < 0.2) {
	  overlaps = true;
	  break;
	}
      }
    }
    if( not overlaps and jet->pt() > 20e3 and fabs(jet->eta() ) < 4.5 ) ++jet_n;
  }

  return jet_n;
}

//=========================================================================
/*unsigned int ttH::TruthSelector::CountTopWLeptons(const xAOD::TruthParticleContainer* truthParticles)
{
  return (GetTopWLep(truthParticles) != nullptr) + (GetAntiTopWLep(truthParticles) != nullptr);
}*/

//=========================================================================
unsigned int ttH::TruthSelector::CountLightLeptons(const xAOD::TruthParticleContainer* truthParticles, float ptMin, float etaMax)
{
  unsigned int nLightLeptons = 0;
  for (auto part : *truthParticles)
    if ((part->pdgId() == PDG_ELECTRON || part->pdgId() == PDG_MUON) && part->pt() > ptMin && part->eta() < etaMax)
      nLightLeptons++;
  return nLightLeptons;
}

//=========================================================================
unsigned int ttH::TruthSelector::GetLQttauttauMode(const xAOD::TruthParticleContainer* truthParticles)
{
  int  tau0=0, tau1=0, top0=0, top1=0;

  for (const auto& p : *truthParticles) {
    if (!(fabs(p->pdgId())==15)) continue;
    if (hasParticleIdenticalParent(p)) continue;

    for (size_t iparent = 0; iparent < p->nParents(); ++iparent){
      if (p->parent(iparent) == nullptr) continue;
      if (!(fabs(p->parent(iparent)->pdgId())==42)) continue;
      const auto& tau = findAfterFSR(p);
      if(p->parent(iparent)->pdgId()==42){
        for (size_t i = 0; i < tau->nChildren(); ++i) {
          const auto& child = tau->child(i);
          if (!child) continue;
          if (fabs(child->pdgId())==12 || fabs(child->pdgId())==14 || fabs(child->pdgId())==16) continue;
          if (fabs(child->pdgId())==11 || fabs(child->pdgId())==13) tau0 = 1;
          else tau0 = 2;
	}//for tau children
      }//if 42
      if(p->parent(iparent)->pdgId()==-42){
        for (size_t i = 0; i < tau->nChildren(); ++i) {
          const auto& child = tau->child(i);
          if (!child) continue;
          if (fabs(child->pdgId())==12 || fabs(child->pdgId())==14 || fabs(child->pdgId())==16) continue;
          if (fabs(child->pdgId())==11 || fabs(child->pdgId())==13) tau1 = 1;
          else tau1 = 2;
	}//for tau
      }// if -42
    }//for tau parents
  }// for truth

  for (const auto& p : *truthParticles) {
    if(!(fabs(p->pdgId())==6)) continue;
    if(hasParticleIdenticalParent(p)) continue;
    const auto& top = findAfterFSR(p);
    for (size_t k=0; k < top->nChildren(); k++) {
      const xAOD::TruthParticle* topChildren = top->child(k);
      if (!(abs(topChildren->pdgId()) == 24)) continue;
      topChildren = findAfterFSR(topChildren);
      
      for (size_t q = 0; q < topChildren->nChildren(); ++q) {
	const xAOD::TruthParticle* WChildren = topChildren->child(q);
	if (fabs(WChildren->pdgId())==12 || fabs(WChildren->pdgId())==14 || fabs(WChildren->pdgId())==16) continue;
	
	if (abs(WChildren->pdgId())<17){
	  if (topChildren->pdgId()>0){
	    if(abs(WChildren->pdgId())==11 || abs(WChildren->pdgId())==13) top0 = 1;
	    else if (abs(WChildren->pdgId())==15){
	      for(size_t r = 0; r < WChildren->nChildren(); ++r){
		const xAOD::TruthParticle* tauChildren = WChildren->child(r);
		if(abs(tauChildren->pdgId())==12 || abs(tauChildren->pdgId())==14 || abs(tauChildren->pdgId())==16) continue;
		if(abs(tauChildren->pdgId())==11 || abs(tauChildren->pdgId())==13) top0=1;
		else top0 = 2;
	      }//for wchildren
	    }else top0 = 3;
	  }else{
	    if(abs(WChildren->pdgId())==11 || abs(WChildren->pdgId())==13) top1 = 1;
	    else if (abs(WChildren->pdgId())==15){
	      for(size_t r = 0; r < WChildren->nChildren(); ++r){
		const xAOD::TruthParticle* tauChildren = WChildren->child(r);
		if(abs(tauChildren->pdgId())==12 || abs(tauChildren->pdgId())==14 || abs(tauChildren->pdgId())==16) continue;
		if(abs(tauChildren->pdgId())==11 || abs(tauChildren->pdgId())==13) top1=1;
		else top1 = 2;
	      }
	    }else top1 = 3;
	  }//else
	}//Wchildren
      }//for top children children
    }//for top children
  }//for all truth

  //  cout<<tau0<<tau1<<top0<<top1<<endl;

  if(tau0==1 && tau1==1){
    if(top0==1 && top1==1)                              return 1;
    else if((top0==1 && top1==2)||(top0==2 && top1==1)) return 2;
    else if((top0==1 && top1==3)||(top0==3 && top1==1)) return 3;
    else if( top0==2 && top1==2)                        return 4;
    else if((top0==2 && top1==3)||(top0==3 && top1==2)) return 5;
    else if( top0==3 && top1==3)                        return 6;
    else return 0;
  }else if(tau0==2 && tau1==2){
    if(top0==1 && top1==1)                              return 13;
    else if((top0==1 && top1==2)||(top0==2 && top1==1)) return 14;
    else if((top0==1 && top1==3)||(top0==3 && top1==1)) return 15;
    else if( top0==2 && top1==2)                        return 16;
    else if((top0==2 && top1==3)||(top0==3 && top1==2)) return 17;
    else if( top0==3 && top1==3)                        return 18;
    else return 0;
  }else{
    if(top0==1 && top1==1)                              return 7;
    else if((top0==1 && top1==2)||(top0==2 && top1==1)) return 8;
    else if((top0==1 && top1==3)||(top0==3 && top1==1)) return 9;
    else if( top0==2 && top1==2)                        return 10;
    else if((top0==2 && top1==3)||(top0==3 && top1==2)) return 11;
    else if( top0==3 && top1==3)                        return 12;
    else return 0;
  }

}

const xAOD::TruthParticle* ttH::TruthSelector::findAfterFSR(const xAOD::TruthParticle* particle) {
  bool isAfterFSR(false);
  const int particle_ID = particle->pdgId();
  int forLoop  = 0;
  while(!isAfterFSR){

    forLoop  = 0;
    for (size_t j=0; j< particle->nChildren(); j++ ) {
      const xAOD::TruthParticle* tmp_children = particle->child(j);
      if (tmp_children && tmp_children->pdgId()==particle_ID){
	particle = particle->child(j);
	forLoop++;
	break;
      }//if
    }//for
    if (forLoop == 0)       isAfterFSR = true;
  }//while
  return particle;
}

bool ttH::TruthSelector::hasParticleIdenticalParent(const xAOD::TruthParticle* particle) {
  bool skipit(false);
  for (size_t i=0; i< particle->nParents(); i++ ) {
    const xAOD::TruthParticle* parent = particle->parent(i);
    if (parent && parent->pdgId()==particle->pdgId()){
      skipit=true;
      break;
    }//if
  }//for
  return skipit;
}

