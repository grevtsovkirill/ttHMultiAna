/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCore/AuxContainerBase.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "TH1F.h"

#include "ttHMultilepton/ttHMLAsgHelper.h"

template<typename T, typename U> T returnDecoIfAvailable(const U& obj, const std::string& deconame, T defaultval) {
  //return defaultval;
  T result = (obj.template isAvailable<T>(deconame) ? obj.template auxdataConst<T>(deconame) : defaultval);
  return result;
}

void ttHMultileptonLooseEventSaver::CopyLeptons(const xAOD::ElectronContainer& Electrons, const xAOD::MuonContainer& Muons){

  //const xAOD::ElectronContainer* Electrons = m_asgHelper->RetrieveElectrons(m_elec);
  //const xAOD::MuonContainer* Muons = m_asgHelper->RetrieveMuons(m_muon);
  memset(&m_leptons, 0, sizeof(m_leptons));
  const int totleptons = Electrons.size() + Muons.size();
  m_ttHEvent->total_leptons = totleptons;
  int keyval = 1 + Electrons.size();
  switch(totleptons) {
  case 1:
    m_ttHEvent->onelep_type = keyval;
    break;
  case 2:
    m_ttHEvent->dilep_type = keyval;
    break;
  case 3:
    m_ttHEvent->trilep_type = keyval;
    break;
  case 4:
    m_ttHEvent->quadlep_type = keyval;
    break;
  }
/*
  for (const auto elItr : Electrons) { tthevt->total_charge += elItr->charge(); }
  for (const auto muItr : Muons) { tthevt->total_charge += muItr->charge(); }

  // Do a sorting for objects
  // (pt, idx, leptype)
  // 3l |q| = 1 has special sorting by Delta R from OS lepton
  typedef std::tuple<const TLorentzVector*, int, ttHML::LepType> sorttype_t;
  std::vector<sorttype_t> sorter;
  // Get p4 for OS in trilep case
  TLorentzVector p4OS;
  bool is_trilep_q1 = tthevt->trilep_type && abs(tthevt->total_charge) == 1;
  if (is_trilep_q1) {
    for (const auto elItr : *Electrons) {
      if (elItr->charge() == -tthevt->total_charge) {
	p4OS = elItr->p4(); break;
      }
    }
    for (const auto muItr : *Muons) {
      if (muItr->charge() == -tthevt->total_charge) {
	p4OS = muItr->p4(); break;
      }
    }
  }

  size_t idx = 0;
  for (const auto elItr : *Electrons) {
    sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHML::ELECTRON));
  }
  idx = 0;
  for (const auto muItr : *Muons) {
    sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHML::MUON));
  }
  if (is_trilep_q1) {
    // sort by increasing delta R from OS lepton (= OS first)
    std::sort(sorter.begin(), sorter.end(),
	      [p4OS](sorttype_t a, sorttype_t b) { return std::get<0>(a)->DeltaR(p4OS) < std::get<0>(b)->DeltaR(p4OS); });
  } else {
    // sort by decreasing pt
    std::sort(sorter.begin(), sorter.end(),
	      [](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
  }*/
}






