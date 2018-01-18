/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "HowtoExtendAnalysisTop/FillVariables.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "HowtoExtendAnalysisTop/ttHMLAsgHelper.h"

FillVariables::FillVariables(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  m_config(config)
{
   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_elec="Selected_Electrons";
  m_muon="Selected_muons";
}

FillVariables::~FillVariables(){

}

bool FillVariables::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Event>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  std::shared_ptr<ttHML::Event> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Event> >("ttHMLEventVariables");

  //top::check(m_asgHelper->evtStore()->retrieve(tthevt->selected_electrons,"Selected_Electrons"), "recording Selected_Electrons failed.");
  const xAOD::ElectronContainer* Electrons = m_asgHelper->RetrieveElectrons(m_elec);
  const xAOD::MuonContainer* Muons = m_asgHelper->RetrieveMuons(m_muon);
const int totleptons = Electrons->size() + Muons->size();
  tthevt->total_leptons = totleptons;
  int keyval = 1 + Electrons->size();
  switch(totleptons) {
  case 1:
    tthevt->onelep_type = keyval;
    break;
  case 2:
    tthevt->dilep_type = keyval;
    break;
  case 3:
    tthevt->trilep_type = keyval;
    break;
  case 4:
    tthevt->quadlep_type = keyval;
    break;
  }

  for (const auto elItr : *Electrons) { tthevt->total_charge += elItr->charge(); }
  for (const auto muItr : *Muons) { tthevt->total_charge += muItr->charge(); }
/*
  // Do a sorting for objects
  // (pt, idx, leptype)
  // 3l |q| = 1 has special sorting by Delta R from OS lepton
  typedef std::tuple<const TLorentzVector*, int, ttHMultilepton::LepType> sorttype_t;
  std::vector<sorttype_t> sorter;
  // Get p4 for OS in trilep case
  TLorentzVector p4OS;
  bool is_trilep_q1 = tthevt->trilep_type && abs(tthevt->total_charge) == 1;
  if (is_trilep_q1) {
    for (const auto elItr : *goodEl) {
      if (elItr->charge() == -tthevt->total_charge) {
	p4OS = elItr->p4(); break;
      }
    }
    for (const auto muItr : *goodMu) {
      if (muItr->charge() == -tthevt->total_charge) {
	p4OS = muItr->p4(); break;
      }
    }
  }

  size_t idx = 0;
  for (const auto elItr : *goodEl) {
    sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHMultilepton::ELECTRON));
  }
  idx = 0;
  for (const auto muItr : *goodMu) {
    sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHMultilepton::MUON));
  }
  if (is_trilep_q1) {
    // sort by increasing delta R from OS lepton (= OS first)
    std::sort(sorter.begin(), sorter.end(),
	      [p4OS](sorttype_t a, sorttype_t b) { return std::get<0>(a)->DeltaR(p4OS) < std::get<0>(b)->DeltaR(p4OS); });
  } else {
    // sort by decreasing pt
    std::sort(sorter.begin(), sorter.end(),
	      [](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
  }

  std::vector<const TLorentzVector*> p4s;
  short capped_totleptons = std::min(totleptons, LEPTON_ARR_SIZE);
  for (short idx = 0; idx < capped_totleptons; ++idx) {
    const TLorentzVector* p4;
    int lidx;
    ttHMultilepton::LepType typ;
    std::tie(p4, lidx, typ) = sorter[idx];
    p4s.push_back(p4);
    if (typ == ttHMultilepton::ELECTRON) {
      CopyElectron(*(*goodEl)[lidx], m_leptons[idx]);
    } else {
      CopyMuon(*(*goodMu)[lidx], m_leptons[idx]);
    }
  }

  if (totleptons >= 2) {
    TLorentzVector p4_01 = (*p4s[0]+*p4s[1]);
    //tthevt->Mll01 = p4_01.M();
    //tthevt->Ptll01 = p4_01.Pt();
    //tthevt->DRll01 = p4s[0]->DeltaR(*p4s[1]);
    int zidx[2]{-1,-1};
    for (int idx1 = 0; idx1 < capped_totleptons-1; ++idx1) {
      for (int idx2 = idx1+1; idx2 < capped_totleptons; ++idx2) {
	TLorentzVector p4sum = *p4s[idx1] + *p4s[idx2];
	tthevt->Mll[idx1][idx2-1] = p4sum.M();
	tthevt->Ptll[idx1][idx2-1] = p4sum.Pt();
	tthevt->DRll[idx1][idx2-1] = p4s[idx1]->DeltaR(*p4s[idx2]);
        tthevt->matchDLTll[idx1][idx2-1] = ( (int)m_leptons[idx1].isTrigMatchDLT && (int)m_leptons[idx2].isTrigMatchDLT
          && std::max(m_leptons[idx1].Pt, m_leptons[idx2].Pt)
          > (abs(m_leptons[idx1].ID*m_leptons[idx2].ID)==169)*((m_runYear==2015)*19e3+(m_runYear==2016)*23e3) );
	// min Mll variables
	if (m_leptons[idx1].ID * m_leptons[idx2].ID < 0) {
	  if (tthevt->minOSMll == 0 || 
	      tthevt->Mll[idx1][idx2-1] < tthevt->minOSMll) {
	    tthevt->minOSMll = tthevt->Mll[idx1][idx2-1];
	  }
	}
	if (m_leptons[idx1].ID == -m_leptons[idx2].ID) {
	  if (tthevt->best_Z_Mll == 0 ||
	      (fabs(tthevt->Mll[idx1][idx2-1]-91.1876e3) <
	       fabs(tthevt->best_Z_Mll-91.1876e3))) {
	    tthevt->best_Z_Mll=tthevt->Mll[idx1][idx2-1];
	    zidx[0] = idx1; zidx[1] = idx2;
	  }
	  // min Mll variables
	  if (tthevt->minOSSFMll == 0 || 
	      tthevt->Mll[idx1][idx2-1] < tthevt->minOSSFMll) {
	    tthevt->minOSSFMll = tthevt->Mll[idx1][idx2-1];
	  }
	}
	for (int idx3 = idx2+1; idx3 < capped_totleptons; ++idx3) {
	  TLorentzVector p4sum3 = p4sum + *p4s[idx3];
	  tthevt->Mlll[idx1][idx2-1][idx3-2] = p4sum3.M();
	  for (int idx4 = idx3+1; idx4 < capped_totleptons; ++idx4) {
	    TLorentzVector p4sum4 = p4sum3 + *p4s[idx4];
	    tthevt->Mllll[idx1][idx2-1][idx3-2][idx4-3] = p4sum4.M();
	  }
	}
      }
    }
    if (totleptons==3 && zidx[0] >= 0) {
      int oidx = 3 - zidx[0] - zidx[1];
      TLorentzVector p4met;
      p4met.SetPtEtaPhiM(m_met_met,0,m_met_phi,0);
      tthevt->best_Z_other_MtLepMet = (p4met + *p4s[oidx]).Mt();
    }
    if (totleptons==4 && zidx[0] >= 0) {
      std::vector<int> otherleps;
      for (int idx = 0; idx < 4; ++idx) {
	if (idx != zidx[0] && idx != zidx[1]) {
	  otherleps.push_back(idx);
	}
      }
      tthevt->best_Z_other_Mll = tthevt->Mll[otherleps[0]][otherleps[1]-1];
    }
  }

  // Flag event if there's at least one truth-QMisID/truth-fake/truth-From-Non-GEANT-Photon lepton
  //
  // By construction, "isLepFromPhEvent==1" is a subset of "isFakeEvent==1"
  //
  if ( m_isMC && totleptons >= 1 ) {

    tthevt->isQMisIDEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
      if ( m_leptons[idx].isQMisID == 1 ) {
    	tthevt->isQMisIDEvent = 1;
    	break;
      }
    }
    tthevt->isFakeEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
      if ( m_leptons[idx].isFakeLep == 1 ) {
    	tthevt->isFakeEvent = 1;
    	break;
      }
    }
    tthevt->isLepFromPhEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
	if ( m_leptons[idx].isConvPh == 1 || m_leptons[idx].isISR_FSR_Ph == 1 ) {
    	tthevt->isLepFromPhEvent = 1;
    	break;
      }
    }
  } else {
    tthevt->isQMisIDEvent    = -1; // default for data
    tthevt->isFakeEvent      = -1; // default for data
    tthevt->isLepFromPhEvent = -1; // default for data
  }
*/
  return true;

}

std::string FillVariables::name() const{
  return "FILLVARIABLES";
}



