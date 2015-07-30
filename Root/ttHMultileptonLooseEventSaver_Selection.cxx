#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCore/AuxContainerBase.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "TH1F.h"

std::shared_ptr<xAOD::ElectronContainer>
ttHMultileptonLooseEventSaver::SelectElectrons(const top::Event& event) {
  xAOD::ElectronContainer* goodElectrons = new xAOD::ElectronContainer();
  xAOD::AuxContainerBase* goodElectronsAux = new xAOD::AuxContainerBase();
  goodElectrons->setStore(goodElectronsAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( goodElectronsAux, "ttHSelectedElectronsAux" ), 
	     "Failed to register selected electrons");
  if (event.m_electrons.size() > 0) {
    //std::cout << "Initial size: " << event.m_electrons.size() << std::endl;
  }
  for (const auto elItr : event.m_electrons) {
    // Fill only for nominal tree
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(1);
    if (elItr->pt() < 10e3) {
      //std::cout << "Fail pt cut" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(2);
    auto abseta = fabs(elItr->caloCluster()->etaBE(2));
    if (!(abseta < 1.37 || (1.52 < abseta && abseta < 2.47))) {
      //std::cout << "Fail eta cut" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(3);
    if (!elItr->auxdataConst<short>("passLHTight")) {
      //std::cout << "Fail LH cut" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(4);
    if (fabs(elItr->auxdataConst<float>("z0sintheta")) > 2) {
      //std::cout << "Fail z0sintheta" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(5);
    if (fabs(elItr->auxdataConst<float>("d0significance")) > 10) {
      //std::cout << "Fail d0sig" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(6);
    if (! iso_1.accept( *elItr )) {
      //std::cout << "Fail isolation" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(7);
    auto newElectron = new xAOD::Electron(*elItr);
    goodElectrons->push_back(newElectron);
  }
  if (event.m_electrons.size() > 0) {
    //std::cout << "Passing size: " << goodElectrons->size() << std::endl;
  }
  return std::shared_ptr<xAOD::ElectronContainer>(goodElectrons);
}

std::shared_ptr<xAOD::MuonContainer>
ttHMultileptonLooseEventSaver::SelectMuons(const top::Event& event) {
  xAOD::MuonContainer* goodMuons = new xAOD::MuonContainer();
  xAOD::AuxContainerBase* goodMuonsAux = new xAOD::AuxContainerBase();
  goodMuons->setStore(goodMuonsAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( goodMuonsAux, "ttHSelectedMuonsAux" ),
	     "Failed to register selected muons");
  for (const auto muItr : event.m_muons) {
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(1);
    auto abseta = fabs(muItr->eta());
    if (!(abseta < 2.5 && muonSelection.getQuality(*muItr) <= xAOD::Muon::Medium && muonSelection.passedIDCuts(*muItr))) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(2);
    if (muItr->pt() < 10e3) {
      continue;
    }    
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(3);
    if (fabs(muItr->auxdataConst<float>("z0sintheta")) > 2) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(4);
    if (fabs(muItr->auxdataConst<float>("d0significance")) > 10) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(5);
    if (! iso_1.accept( *muItr )) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(6);
    auto newMuon = new xAOD::Muon();
    newMuon->makePrivateStore(*muItr);
    goodMuons->push_back(newMuon);
  }
  // if (goodMuons->size() > 0) {
  //   std::cout << "Found some muons" << std::endl;
  //   std::cout << "Another phi " << goodMuons->at(0)->phi() << std::endl;
  // } else {
  //   std::cout << "No muons" << std::endl;
  // }
  return std::shared_ptr<xAOD::MuonContainer>(goodMuons);
}

std::shared_ptr<xAOD::JetContainer>
ttHMultileptonLooseEventSaver::SelectJets(const top::Event& event) {
  xAOD::JetContainer* goodJets = new xAOD::JetContainer();
  xAOD::AuxContainerBase* goodJetsAux = new xAOD::AuxContainerBase();
  goodJets->setStore(goodJetsAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( goodJetsAux, "ttHSelectedJetsAux" ),
	     "Failed to register selected jets");
  for (const auto jetItr : event.m_jets) {
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(1);
    if (!cleaningTool->keep(*jetItr)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(2);
    if (jetItr->pt() < 25e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(3);
    auto abseta = fabs(jetItr->eta());
    if (abseta > 2.5) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(4);
    if (jetItr->pt() < 50e3 && abseta < 2.4 && jetItr->auxdataConst<float>("AnalysisTop_JVT") < 0.64) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(5);
    auto newJet = new xAOD::Jet(*jetItr);
    goodJets->push_back(newJet);
  }
  return std::shared_ptr<xAOD::JetContainer>(goodJets);
}

std::shared_ptr<xAOD::TauJetContainer>
ttHMultileptonLooseEventSaver::SelectTaus(const top::Event& event) {
  auto goodTaus = new xAOD::TauJetContainer();
  auto goodTausAux = new xAOD::AuxContainerBase();
  goodTaus->setStore(goodTausAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( goodTausAux, "ttHSelectedTausAux" ),
	     "Failed to register selected taus");
  for (const auto tauItr : event.m_tauJets) {
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(1);
    if (abs(tauItr->charge()) != 1) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(2);
    if (!(tauItr->nTracks() == 1 || tauItr->nTracks() == 3)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(3);
    auto abseta = fabs(tauItr->eta());
    if (!(abseta < 1.37 || (1.52 < abseta && abseta < 2.5))) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(4);
    if (!tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(5);
    if (tauItr->pt() < 25e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(6);
    if (tauItr->isTau(xAOD::TauJetParameters::IsTauFlag::EleBDTLoose)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(7);
    auto newTau = new xAOD::TauJet();
    newTau->makePrivateStore(*tauItr);
    goodTaus->push_back(newTau);
  }
  return std::shared_ptr<xAOD::TauJetContainer>(goodTaus);
}

template<typename T> int CountPassOR(DataVector<T>& vec) {
  int rv = 0;
  // Figure this out later ...
  //T::template Decorator<short> passovr("ttHpassOVR");
  //for (size_t idx = 0; idx < vec.size(); ++idx) {
  //if (passovr(vec, idx)) {
  for (const auto iItr : vec) {
    if (iItr->template auxdataConst<short>("ttHpassOVR")) {
      rv++;
    }
  }
  return rv;
}

void
ttHMultileptonLooseEventSaver::OverlapRemoval(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<JetContainer>& goodJet, std::shared_ptr<TauJetContainer>& goodTau, bool fillCutflow) {
  auto newGoodEl = std::shared_ptr<xAOD::ElectronContainer>(new xAOD::ElectronContainer());
  auto newGoodElAux = new xAOD::AuxContainerBase();
  newGoodEl->setStore(newGoodElAux);
  auto newGoodMu = std::shared_ptr<xAOD::MuonContainer>(new xAOD::MuonContainer());
  auto newGoodMuAux = new xAOD::AuxContainerBase();
  newGoodMu->setStore(newGoodMuAux);
  auto newGoodJet = std::shared_ptr<xAOD::JetContainer>(new xAOD::JetContainer());
  auto newGoodJetAux = new xAOD::AuxContainerBase();
  newGoodJet->setStore(newGoodJetAux);
  auto newGoodTau = std::shared_ptr<xAOD::TauJetContainer>(new xAOD::TauJetContainer());
  auto newGoodTauAux = new xAOD::AuxContainerBase();
  newGoodTau->setStore(newGoodTauAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( newGoodElAux, "ttHORElectronsAux" ),
	     "Failed to register electrons after OR");
  top::check(evtStore()->tds()->record( newGoodMuAux, "ttHORMuonsAux" ),
	     "Failed to register muons after OR");
  top::check(evtStore()->tds()->record( newGoodJetAux, "ttHORJetsAux" ),
	     "Failed to register jets after OR");
  top::check(evtStore()->tds()->record( newGoodTauAux, "ttHORTausAux" ),
	     "Failed to register taus after OR");
  for (const auto elItr : *goodEl) {
    elItr->auxdecor<short>("ttHpassOVR") = 1;
  }
  for (const auto muItr : *goodMu) {
    muItr->auxdecor<short>("ttHpassOVR") = 1;
  }
  for (const auto jetItr : *goodJet) {
    jetItr->auxdecor<short>("ttHpassOVR") = 1;
  }
  for (const auto tauItr : *goodTau) {
    tauItr->auxdecor<short>("ttHpassOVR") = 1;
  }

  for (const auto elItr : *goodEl) {
    auto p4 = elItr->p4();
    for (const auto muItr : *goodMu) {
       if (p4.DeltaR(muItr->p4()) < 0.1) {
  	elItr->auxdecor<short>("ttHpassOVR") = 0;
  	break;
      }
    }
  }
  fillCutflow &&m_eleCutflow->Fill(8, CountPassOR(*goodEl));

  for (size_t i1 = 0; i1 < goodEl->size(); ++i1) {
    auto elItr = goodEl->at(i1);
    if (! elItr->auxdataConst<short>("ttHpassOVR")) {
      continue;
    }
    auto p4 = elItr->p4();
    for (size_t i2 = i1+1; i2 < goodEl->size(); ++i2) {
      auto elItr2 = goodEl->at(i2);
      if (! elItr2->auxdataConst<short>("ttHpassOVR")) {
  	continue;
      }
      if (p4.DeltaR(elItr2->p4()) < 0.1) {
  	if (elItr2->pt() < elItr->pt()) {
  	  elItr2->auxdecor<short>("ttHpassOVR") = 0;
  	} else {
  	  elItr->auxdecor<short>("ttHpassOVR") = 0;
  	}
      }
    }
  }
  fillCutflow &&m_eleCutflow->Fill(9, CountPassOR(*goodEl));

  for (const auto jetItr : *goodJet) {
    auto p4 = jetItr->p4();
    for (const auto elItr : *goodEl) {
      if (! elItr->auxdataConst<short>("ttHpassOVR")) {
  	continue;
      }
     if (p4.DeltaR(elItr->p4()) < 0.3) {
  	jetItr->auxdecor<short>("ttHpassOVR") = 0;
  	break;
      }
    }
  }
  fillCutflow &&m_jetCutflow->Fill(6, CountPassOR(*goodJet));

  for (const auto jetItr : *goodJet) {
    if (! jetItr->auxdataConst<short>("ttHpassOVR")) {
      continue;
    }
    auto p4 = jetItr->p4();
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<short>("ttHpassOVR")) {
  	continue;
      }
     if (p4.DeltaR(muItr->p4()) < 0.04+10e3/muItr->pt()) {
  	muItr->auxdecor<short>("ttHpassOVR") = 0;
      }
    }
  }
  fillCutflow &&m_muCutflow->Fill(7, CountPassOR(*goodMu));

  for (const auto tauItr : *goodTau) {
    auto p4 = tauItr->p4();
    for (const auto elItr : *goodEl) {
      if (! elItr->auxdataConst<short>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(elItr->p4()) < 0.2) {
	tauItr->auxdecor<short>("ttHpassOVR") = 0;
	break;
      }
    }
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<short>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(muItr->p4()) < 0.2) {
	tauItr->auxdecor<short>("ttHpassOVR") = 0;
	break;
      }
    }
    if (tauItr->auxdataConst<short>("ttHpassOVR")) {
      for (const auto jetItr : *goodJet) {
	// don't need additional protection here...
	if (p4.DeltaR(jetItr->p4()) < 0.3) {
	  jetItr->auxdecor<short>("ttHpassOVR") = 0;
	}
      }
    }
  }
  fillCutflow &&m_tauCutflow->Fill(8, CountPassOR(*goodTau));
  fillCutflow &&m_jetCutflow->Fill(7, CountPassOR(*goodJet));

  for (const auto elItr : *goodEl) {
    if (elItr->auxdataConst<short>("ttHpassOVR")) {
      newGoodEl->push_back(new xAOD::Electron(*elItr));
    }
  }
  for (const auto muItr : *goodMu) {
    if (muItr->auxdataConst<short>("ttHpassOVR")) {
      auto newMu = new xAOD::Muon();
      newMu->makePrivateStore(*muItr);
      newGoodMu->push_back(newMu);
    }
  }
  for (const auto jetItr : *goodJet) {
    if (jetItr->auxdataConst<short>("ttHpassOVR")) {
      newGoodJet->push_back(new xAOD::Jet(*jetItr));
    }
  }
  for (const auto tauItr : *goodTau) {
    if (tauItr->auxdataConst<short>("ttHpassOVR")) {
      auto newTau = new xAOD::TauJet();
      newTau->makePrivateStore(*tauItr);
      newGoodTau->push_back(newTau);
    }
  }

  // m_eleCutflow->Fill(8, newGoodEl->size());
  // m_muCutflow->Fill(7, newGoodMu->size());
  // m_jetCutflow->Fill(6, newGoodJet->size());
  // m_tauCutflow->Fill(8, newGoodTau->size());
  
  newGoodEl.swap(goodEl);
  newGoodMu.swap(goodMu);
  newGoodJet.swap(goodJet);
  newGoodTau.swap(goodTau);
}

void CopyIParticle(xAOD::IParticle& part, ttHMultilepton::Lepton& lep) {
  lep.Pt = part.pt();
  lep.E = part.e();
  lep.Eta = part.eta();
  lep.Phi = part.phi();
}
  
void CopyElectron(xAOD::Electron& el, ttHMultilepton::Lepton& lep) {
  CopyIParticle(el, lep);
  lep.ID = -11*el.charge();
  lep.isLooseLH = el.auxdataConst<short>("passLHLoose");
  lep.isMediumLH = el.auxdataConst<short>("passLHMedium");
  lep.isTightLH = el.auxdataConst<short>("passLHTight");
}

void CopyMuon(xAOD::Muon& mu, ttHMultilepton::Lepton& lep) {
  CopyIParticle(mu, lep);
  lep.ID = -13*mu.charge();
}

void
ttHMultileptonLooseEventSaver::CopyLeptons(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu) {
  memset(&m_leptons, 0, sizeof(m_leptons));
  const int totleptons = goodEl->size() + goodMu->size();
  int keyval = 1 + goodEl->size();
  switch(totleptons) {
  case 1:
    m_variables->onelep_type = keyval;
    break;
  case 2:
    m_variables->dilep_type = keyval;
    break;
  case 3:
    m_variables->trilep_type = keyval;
    break;
  case 4:
    m_variables->quadlep_type = keyval;
    break;
  }
  for (const auto elItr : *goodEl) { m_variables->total_charge += elItr->charge(); }
  for (const auto muItr : *goodMu) { m_variables->total_charge += muItr->charge(); }
  // Do a sorting for objects
  // (pt, idx, leptype)
  // 3l |q| = 1 has special sorting by Delta R from OS lepton
  typedef std::tuple<const TLorentzVector*, int, ttHMultilepton::LepType> sorttype_t;
  std::vector<sorttype_t> sorter;
  // Get p4 for OS in trilep case
  TLorentzVector p4OS;
  bool is_trilep_q1 = m_variables->trilep_type && abs(m_variables->total_charge) == 1;
  if (is_trilep_q1) {
    for (const auto elItr : *goodEl) {
      if (elItr->charge() == -m_variables->total_charge) {
	p4OS = elItr->p4(); break;
      }
    }
    for (const auto muItr : *goodMu) {
      if (muItr->charge() == -m_variables->total_charge) {
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
  for (short idx = 0; idx < totleptons && idx < LEPTON_ARR_SIZE; ++idx) {
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
    //m_variables->Mll01 = p4_01.M();
    //m_variables->Ptll01 = p4_01.Pt();
    //m_variables->DRll01 = p4s[0]->DeltaR(*p4s[1]);
    for (int idx1 = 0; idx1 < totleptons-1; ++idx1) {
      for (int idx2 = idx1+1; idx2 < totleptons; ++idx2) {
	TLorentzVector p4sum = *p4s[idx1] + *p4s[idx2];
	m_variables->Mll[idx1][idx2-1] = p4sum.M();
	m_variables->Ptll[idx1][idx2-1] = p4sum.Pt();
	m_variables->DRll[idx1][idx2-1] = p4s[idx1]->DeltaR(*p4s[idx2]);
      }
    }
  }

}

void
ttHMultileptonLooseEventSaver::CopyJets(std::shared_ptr<xAOD::JetContainer>& goodJets) {
  // don't actually copy anything ATM, just give yields of jets & btags
  m_variables->nJets_OR_T = goodJets->size();
  m_variables->nJets_OR_T_MV2c20_70 = 0;
  m_variables->nJets_OR_T_MV2c20_77 = 0;
  for (const auto jetItr : *goodJets) {
    auto btagging = jetItr->btagging(); 
    if (btagging) {
      double mv2c;
      if( btagging->MVx_discriminant("MV2c20", mv2c) ) {
	if (mv2c > -0.4434) {
	  m_variables->nJets_OR_T_MV2c20_77++;
	  if (mv2c > -0.0436) {
	    m_variables->nJets_OR_T_MV2c20_70++;
	  }
	}
      }
    }
  }
}

void
ttHMultileptonLooseEventSaver::CopyTaus(std::shared_ptr<xAOD::TauJetContainer>& goodTaus) {
  m_variables->nTaus_OR_Pt25 = goodTaus->size();
}

void
ttHMultileptonLooseEventSaver::CheckIsBlinded() {
  bool isBlinded = false;
  if (m_variables->dilep_type) {
    if (abs(m_variables->total_charge) == 2
	&& m_variables->nJets_OR_T >= 4
	&& m_variables->nJets_OR_T_MV2c20_70 >= 1) {
      isBlinded = true;
    }
  } else if (m_variables->trilep_type) {
    // remember Mll01 = Mll[0][0] and Mll02 = Mll[0][1]
    if (abs(m_variables->total_charge) == 1
	&& ((m_variables->nJets_OR_T >=4 
	     && m_variables->nJets_OR_T_MV2c20_70 >= 1) 
	    || (m_variables->nJets_OR_T ==3 
		&& m_variables->nJets_OR_T_MV2c20_70 >= 2))
	&& ! ((m_leptons[0].ID == - m_leptons[1].ID && fabs(m_variables->Mll[0][0] - 91.2e3) < 10e3)
	      || (m_leptons[0].ID == - m_leptons[2].ID && fabs(m_variables->Mll[0][1] - 91.2e3) < 10e3))
	) {
      isBlinded = true;
    }
  } else if (m_variables->quadlep_type) {
    if (m_variables->nJets_OR_T_MV2c20_70 >= 1) {
      isBlinded = true;
    }
  }
  m_variables->isBlinded = isBlinded;
}
