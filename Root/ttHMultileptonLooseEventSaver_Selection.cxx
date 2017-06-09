#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCore/AuxContainerBase.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "TH1F.h"


template<typename T, typename U> T returnDecoIfAvailable(const U& obj, const std::string& deconame, T defaultval) {
  //return defaultval;
  T result = (obj.template isAvailable<T>(deconame) ? obj.template auxdataConst<T>(deconame) : defaultval);
  return result;
}

int ttHMultileptonLooseEventSaver::getNInnerPix(const xAOD::Electron& el) {
  uint8_t val8;
  int expInPix = el.trackParticleSummaryValue(val8, xAOD::expectInnermostPixelLayerHit)
    ? val8 : -999;
  int expNextInPix = el.trackParticleSummaryValue(val8, xAOD::expectNextToInnermostPixelLayerHit)
    ? val8 : -999;
  if (1 == expInPix) {
    return (el.trackParticleSummaryValue(val8, xAOD::numberOfInnermostPixelLayerHits)
	    ? val8 : -999);
  }
  else if (1 == expNextInPix) {
    return (el.trackParticleSummaryValue(val8, xAOD::numberOfNextToInnermostPixelLayerHits)
	    ? val8 : -999);
  }
  return -999;
}

int ttHMultileptonLooseEventSaver::getNInnerPix(const xAOD::Muon& mu) {
  uint8_t val8;
  const auto& link = mu.inDetTrackParticleLink();
  if (!link.isValid()) return -999;
  int expInPix = (*link)->summaryValue(val8, xAOD::expectInnermostPixelLayerHit) ? val8 : -999;
  int expNextInPix = (*link)->summaryValue(val8, xAOD::expectNextToInnermostPixelLayerHit) ? val8 : -999;
  if (1 == expInPix) {
    return ((*link)->summaryValue(val8, xAOD::numberOfInnermostPixelLayerHits) ? val8 : -999);
  }
  else if (1 == expNextInPix) {
    return ((*link)->summaryValue(val8, xAOD::numberOfNextToInnermostPixelLayerHits) ? val8 : -999);
  }
  return -999;
}

std::shared_ptr<xAOD::ElectronContainer>
ttHMultileptonLooseEventSaver::SelectElectrons(const top::Event& event) {
  xAOD::ElectronContainer* goodElectrons = new xAOD::ElectronContainer();
  xAOD::AuxContainerBase* goodElectronsAux = new xAOD::AuxContainerBase();
  goodElectrons->setStore(goodElectronsAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( goodElectronsAux, "ttHSelectedElectrons"+m_sysName+"Aux." ),
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
    if (!elItr->auxdataConst<int>("passLHLoose")) {
      // passLHLoose is equivalent to LooseLH + BLayer cuts
      // the BLayer cuts are applied by AnalysisTop
      //std::cout << "Fail LH cut" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(4);
    if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
      //std::cout << "Fail z0sintheta" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(5);
    if (fabs(elItr->auxdataConst<float>("d0sig")) > 10) {
      //std::cout << "Fail d0sig" << std::endl;
      continue;
    }
    event.m_ttreeIndex == 0 && m_eleCutflow->Fill(6);
    //if (! elItr->auxdataConst<short>("Iso_Loose")) {
      //std::cout << "Fail isolation" << std::endl;
      //continue;
    //}
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
  top::check(evtStore()->tds()->record( goodMuonsAux, "ttHSelected"+m_sysName+"MuonsAux." ),
	     "Failed to register selected muons");
  for (const auto muItr : event.m_muons) {
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(1);
    auto abseta = fabs(muItr->eta());
    if (!(abseta < 2.5 && muonSelection.getQuality(*muItr) <= xAOD::Muon::Loose && muonSelection.passedIDCuts(*muItr))) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(2);
    if (muItr->pt() < 10e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(3);
    if (fabs(muItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(4);
    if (fabs(muItr->auxdataConst<float>("d0sig")) > 10) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_muCutflow->Fill(5);
    //if (! muItr->auxdataConst<short>("Iso_Loose")) {
    //  continue;
    //}
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
  top::check(evtStore()->tds()->record( goodJetsAux, "ttHSelected"+m_sysName+"JetsAux." ),
	     "Failed to register selected jets");
  for (const auto jetItr : event.m_jets) {
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(1);
    if (!m_jetCleaningToolLooseBad->keep(*jetItr)) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(2);
    if (jetItr->pt() < 25e3) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(3);
    if (fabs(jetItr->eta()) > 2.5) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_jetCutflow->Fill(4);
    if (jetItr->pt() < 60e3
	&& fabs(jetItr->getAttribute<float>("DetectorEta")) < 2.4
	&& jetItr->auxdataConst<float>("AnalysisTop_JVT") < 0.59) {
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
  top::check(evtStore()->tds()->record( goodTausAux, "ttHSelected"+m_sysName+"TausAux." ),
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
    if ( !( tauItr->auxdata<int>("passEleBDT") ) ) {
      continue;
    }
    event.m_ttreeIndex == 0 && m_tauCutflow->Fill(7);
    auto newTau = new xAOD::TauJet();
    newTau->makePrivateStore(*tauItr);
    goodTaus->push_back(newTau);
  }
  return std::shared_ptr<xAOD::TauJetContainer>(goodTaus);
}

template<typename T> int CountPassOR(DataVector<T>& vec, bool doTauOR = false) {
  int rv = 0;
  // Figure this out later ...
  //T::template Decorator<short> passovr("ttHpassOVR");
  //for (size_t idx = 0; idx < vec.size(); ++idx) {
  //if (passovr(vec, idx)) {
  for (const auto iItr : vec) {
    if (iItr->template auxdataConst<char>("ttHpassOVR") && (!doTauOR || iItr->template auxdataConst<char>("ttHpassTauOVR") ) ) {
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
  top::check(evtStore()->tds()->record( newGoodElAux, "ttHOR"+m_sysName+"ElectronsAux." ),
	     "Failed to register electrons after OR");
  top::check(evtStore()->tds()->record( newGoodMuAux, "ttHOR"+m_sysName+"MuonsAux." ),
	     "Failed to register muons after OR");
  top::check(evtStore()->tds()->record( newGoodJetAux, "ttHOR"+m_sysName+"JetsAux." ),
	     "Failed to register jets after OR");
  top::check(evtStore()->tds()->record( newGoodTauAux, "ttHOR"+m_sysName+"TausAux." ),
	     "Failed to register taus after OR");
  for (const auto elItr : *goodEl) {
    elItr->auxdecor<char>("ttHpassOVR") = 1;
  }
  for (const auto muItr : *goodMu) {
    muItr->auxdecor<char>("ttHpassOVR") = 1;
  }
  for (const auto jetItr : *goodJet) {
    jetItr->auxdecor<char>("ttHpassOVR") = 1;
    jetItr->auxdecor<char>("ttHpassTauOVR") = 1;
  }
  for (const auto tauItr : *goodTau) {
    tauItr->auxdecor<char>("ttHpassOVR") = 1;
  }

  //if an electron and muon candidate are within 0.1 of each other: remove the electron 
  for (const auto elItr : *goodEl) {
    auto p4 = elItr->p4();
    for (const auto muItr : *goodMu) {
       if (p4.DeltaR(muItr->p4()) < 0.1) {
  	elItr->auxdecor<char>("ttHpassOVR") = 0;
  	break;
      }
    }
  }
  fillCutflow &&m_eleCutflow->Fill(8, CountPassOR(*goodEl));

  //If two electron candidates within 0.1 of each other: remove the one with lower pt 
  for (size_t i1 = 0; i1 < goodEl->size(); ++i1) {
    auto elItr = goodEl->at(i1);
    if (! elItr->auxdataConst<char>("ttHpassOVR")) {
      continue;
    }
    auto p4 = elItr->p4();
    for (size_t i2 = i1+1; i2 < goodEl->size(); ++i2) {
      auto elItr2 = goodEl->at(i2);
      if (! elItr2->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
      if (p4.DeltaR(elItr2->p4()) < 0.1) {
  	if (elItr2->pt() < elItr->pt()) {
  	  elItr2->auxdecor<char>("ttHpassOVR") = 0;
  	} else {
  	  elItr->auxdecor<char>("ttHpassOVR") = 0;
  	}
      }
    }
  }
  // now done later
  //fillCutflow &&m_eleCutflow->Fill(9, CountPassOR(*goodEl));

  //if an electron and a jet are within 0.3 of each other: remove the jet 
  for (const auto jetItr : *goodJet) {
    auto p4 = jetItr->p4();
    for (const auto elItr : *goodEl) {
      if (! elItr->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
     if (p4.DeltaR(elItr->p4()) < 0.3) {
  	jetItr->auxdecor<char>("ttHpassOVR") = 0;
  	break;
      }
    }
  }
  fillCutflow &&m_jetCutflow->Fill(6, CountPassOR(*goodJet));

  //if a muon and a jet are within 0.04+10[GeV]/pT(muon) of each other: remove the muon
  /*for (const auto jetItr : *goodJet) {
    if (! jetItr->auxdataConst<char>("ttHpassOVR")) {
      continue;
    }
    auto p4 = jetItr->p4();
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
     if (p4.DeltaR(muItr->p4()) < 0.04+10e3/muItr->pt()) {
  	muItr->auxdecor<char>("ttHpassOVR") = 0;
      }
    }
  }*/

  //if a muon and a jet are within (0.4, 0.04+10[GeV]/pT(muon)) of each other: remove the muon
  for (const auto jetItr : *goodJet) {
    if (! jetItr->auxdataConst<char>("ttHpassOVR")) {
      continue;
    }
    auto p4 = jetItr->p4();
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
  	continue;
      }
      if ( p4.DeltaR(muItr->p4()) < std::min(0.4, 0.04+10e3/muItr->pt()) ) {
  	muItr->auxdecor<char>("ttHpassOVR") = 0;
      }
    }
  }

  // now done later
  //fillCutflow &&m_muCutflow->Fill(7, CountPassOR(*goodMu));

  //if an electron and a tau are within 0.2 of each other: remove the tau
  for (const auto tauItr : *goodTau) {
    auto p4 = tauItr->p4();
    for (const auto elItr : *goodEl) {
      if (! elItr->auxdataConst<char>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(elItr->p4()) < 0.2) {
	tauItr->auxdecor<char>("ttHpassOVR") = 0;
	break;
      }
    }
    //if an muon and a tau are within 0.2 of each other: remove the tau 
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(muItr->p4()) < 0.2) {
	tauItr->auxdecor<char>("ttHpassOVR") = 0;
	break;
      }
    }
    //if a tau and a jet are within 0.3 of each other: remove the jet 
    if (tauItr->auxdataConst<char>("ttHpassOVR")) {
      for (const auto jetItr : *goodJet) {
	// don't need additional protection here...
	if (p4.DeltaR(jetItr->p4()) < 0.3) {
	  jetItr->auxdecor<char>("ttHpassTauOVR") = 0;
	}
      }
    }
  }
  fillCutflow &&m_tauCutflow->Fill(8, CountPassOR(*goodTau));
  fillCutflow &&m_jetCutflow->Fill(7, CountPassOR(*goodJet));
  
  for (const auto elItr : *goodEl) {
    if (elItr->auxdataConst<char>("ttHpassOVR")) {
      newGoodEl->push_back(new xAOD::Electron(*elItr));
    }
  }
  for (const auto muItr : *goodMu) {
    if (muItr->auxdataConst<char>("ttHpassOVR")) {
      auto newMu = new xAOD::Muon();
      newMu->makePrivateStore(*muItr);
      newGoodMu->push_back(newMu);
    }
  }
  for (const auto jetItr : *goodJet) {
    //jetItr->auxdecor<char>("ttHJetOVRStatus") = jetItr->auxdataConst<char>("ttHpassOVR") + jetItr->auxdataConst<char>("ttHpassTauOVR");
    //std::cout << std::find(goodJet->begin(), goodJet->end(), *jetItr) << std::endl;
    if (jetItr->auxdataConst<char>("ttHpassOVR")) {
      newGoodJet->push_back(new xAOD::Jet(*jetItr));
    }
  }
  for (const auto tauItr : *goodTau) {
    if (tauItr->auxdataConst<char>("ttHpassOVR")) {
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

void
ttHMultileptonLooseEventSaver::OverlapRemoval_ContOnly(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<JetContainer>& goodJet, std::shared_ptr<TauJetContainer>& goodTau, bool fillCutflow) {
  fillCutflow &&m_eleCutflow->Fill(9, CountPassOR(*goodEl));
  fillCutflow &&m_muCutflow->Fill(7, CountPassOR(*goodMu));
  fillCutflow &&m_tauCutflow->Fill(8, CountPassOR(*goodTau));
  fillCutflow &&m_jetCutflow->Fill(7, CountPassOR(*goodJet));
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
  top::check(evtStore()->tds()->record( newGoodElAux, "ttHOR"+m_sysName+"ElectronsAux." ),
	     "Failed to register electrons after OR");
  top::check(evtStore()->tds()->record( newGoodMuAux, "ttHOR"+m_sysName+"MuonsAux." ),
	     "Failed to register muons after OR");
  top::check(evtStore()->tds()->record( newGoodJetAux, "ttHOR"+m_sysName+"JetsAux." ),
	     "Failed to register jets after OR");
  top::check(evtStore()->tds()->record( newGoodTauAux, "ttHOR"+m_sysName+"TausAux." ),
	     "Failed to register taus after OR");

  for (const auto elItr : *goodEl) {
    if (elItr->auxdataConst<char>("ttHpassOVR")) {
      newGoodEl->push_back(new xAOD::Electron(*elItr));
    }
  }
  for (const auto muItr : *goodMu) {
    if (muItr->auxdataConst<char>("ttHpassOVR")) {
      auto newMu = new xAOD::Muon();
      newMu->makePrivateStore(*muItr);
      newGoodMu->push_back(newMu);
    }
  }
  for (const auto jetItr : *goodJet) {
    //jetItr->auxdecor<char>("ttHJetOVRStatus") = jetItr->auxdataConst<char>("ttHpassOVR") + jetItr->auxdataConst<char>("ttHpassTauOVR");
    //std::cout << std::find(goodJet->begin(), goodJet->end(), *jetItr) << std::endl;
    if (jetItr->auxdataConst<char>("ttHpassOVR")) {
      newGoodJet->push_back(new xAOD::Jet(*jetItr));
    }
  }
  for (const auto tauItr : *goodTau) {
    if (tauItr->auxdataConst<char>("ttHpassTauOVR")) {
      auto newTau = new xAOD::TauJet();
      newTau->makePrivateStore(*tauItr);
      newGoodTau->push_back(newTau);
    }
  }
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
  lep.Index = part.index();
}

void CopyIso(xAOD::IParticle& part, ttHMultilepton::Lepton& lep) {
  lep.isolationLooseTrackOnly = part.auxdataConst<short>("Iso_LooseTrackOnly");
  lep.isolationLoose = part.auxdataConst<short>("Iso_Loose");
  lep.isolationGradient = part.auxdataConst<short>("Iso_Gradient");
  lep.isolationGradientLoose = part.auxdataConst<short>("Iso_GradientLoose");
  lep.isolationFixedCutTightTrackOnly = part.auxdataConst<short>("Iso_FixedCutTightTrackOnly");
  lep.isolationFixedCutLoose = part.auxdataConst<short>("Iso_FixedCutLoose");

}

void CopyIParam(xAOD::IParticle& part, ttHMultilepton::Lepton& lep) {
  lep.sigd0PV = part.auxdataConst<float>("d0sig");
  lep.Z0SinTheta = part.auxdataConst<float>("delta_z0_sintheta");
  lep.deltaz0 = part.auxdataConst<float>("delta_z0");
}

float muonEff_Trigger(const xAOD::Muon& x,const std::string& id,const top::topSFSyst SFSyst)
{
  float sf(1.);
  if (x.isAvailable<float>("MU_EFF_Trigger_"+id)) {
    sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id);
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_STAT_UP) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_STAT_UP")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_STAT_UP");
    }
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_STAT_DOWN) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_STAT_DOWN")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_STAT_DOWN");
    }
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_SYST_UP) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_SYST_UP")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_SYST_UP");
    }
  }

  if (SFSyst == top::topSFSyst::MU_SF_Trigger_SYST_DOWN) {
    if (x.isAvailable<float>("MU_EFF_Trigger_"+id+"_SYST_DOWN")) {
      sf = x.auxdataConst<float>("MU_EFF_Trigger_"+id+"_SYST_DOWN");
    }
  }
  return sf;
}

float electronEff_Trigger(const xAOD::Electron& x,const std::string& id,const top::topSFSyst SFSyst)
{
  float sf(1.);
  if (x.isAvailable<float>("EL_EFF_Trigger_"+id)) {
    sf = x.auxdataConst<float>("EL_EFF_Trigger_"+id);
  }

  if (SFSyst == top::topSFSyst::EL_SF_Trigger_UP) {
    if (x.isAvailable<float>("EL_EFF_Trigger_"+id+"_UP")) {
      sf = x.auxdataConst<float>("EL_EFF_Trigger_"+id+"_UP");
    }
  }

  if (SFSyst == top::topSFSyst::EL_SF_Trigger_DOWN) {
    if (x.isAvailable<float>("EL_EFF_Trigger_"+id+"_DOWN")) {
      sf = x.auxdataConst<float>("EL_EFF_Trigger_"+id+"_DOWN");
    }
  }

  return sf;
}


void ttHMultileptonLooseEventSaver::
CopyElectron(xAOD::Electron& el, ttHMultilepton::Lepton& lep) {
    // const SG::IConstAuxStore* store = el.container()->getConstStore();
    // const SG::auxid_set_t& auxids = store->getAuxIDs();
    // SG::AuxTypeRegistry& reg = SG::AuxTypeRegistry::instance();
    // //std::cout << "=============" << std::endl;
    // for( auto auxid : auxids ) {
    //   //std::cout << reg.getName( auxid ) << std::endl;
    // }

  lep.EtaBE2 = el.caloCluster()->etaBE(2);
  CopyIParticle(el, lep);
  CopyIso(el, lep);
  CopyIParam(el, lep);
  lep.ID = -11*el.charge();
  lep.isLooseLH  = el.auxdataConst<int>("passLHLoose");
  // passLHLoose is equivalent to LooseLH + BLayer cuts
  // the BLayer cuts are applied by AnalysisTop
  lep.isMediumLH = el.auxdataConst<int>("passLHMedium");
  lep.isTightLH  = el.auxdataConst<int>("passLHTight");
  lep.isolationFixedCutTight = el.auxdataConst<short>("Iso_FixedCutTight");

  lep.d0 = el.trackParticle()->d0();
  lep.z0 = el.trackParticle()->z0();
  lep.vz = el.trackParticle()->vz();

  // truth matching, fakes, QMisId
  int TruthType = -99;
  int TruthOrigin = -99;
  /*
  int bkgElMotherPdgID = -99;
  int bkgElType = -99;
  int bkgElOrigin = -99;
  */

  if(m_isMC) {
    static SG::AuxElement::Accessor<int> origel("truthOrigin");
    if (origel.isAvailable(el)) TruthOrigin = origel(el);

    static SG::AuxElement::Accessor<int> typeel("truthType");
    if (typeel.isAvailable(el)) TruthType = typeel(el);
    /*
    static SG::AuxElement::Accessor<int> typebkgel("bkgTruthType");
    static SG::AuxElement::Accessor<int> origbkgel("bkgTruthOrigin");
    static SG::AuxElement::Accessor<int> bkgMotherPdgID("bkgMotherPdgId");
    if (typebkgel.isAvailable(el)) {std::cout << "it is available: type! " << std::endl; bkgElType  = typebkgel(el);}
    if (origbkgel.isAvailable(el)) {std::cout << "it is available: origin! " << std::endl; bkgElOrigin= origbkgel(el);}
    if (bkgMotherPdgID.isAvailable(el)) {std::cout << "it is available: MotherPDGID! " << std::endl; bkgElMotherPdgID= bkgMotherPdgID(el);}
    */
    //truthType   = (int) xAOD::TruthHelpers::getParticleTruthType(el);
    //truthOrigin = (int) xAOD::TruthHelpers::getParticleTruthOrigin(el);
  }

  if (TruthType == 2 || TruthType == 6)
    lep.isPrompt = 1;
  else
    lep.isPrompt = 0;

  static SG::AuxElement::Accessor<char> QMisID("isQMisID");
  lep.isQMisID = ( QMisID.isAvailable(el) ) ?  QMisID(el) : -1;

  static SG::AuxElement::Accessor<char> ConvPh("isConvPh");
  lep.isConvPh = ( ConvPh.isAvailable(el) ) ?  ConvPh(el) : -1;

  static SG::AuxElement::Accessor<char> ISR_FSR_Ph("isISR_FSR_Ph");
  lep.isISR_FSR_Ph = ( ISR_FSR_Ph.isAvailable(el) ) ?  ISR_FSR_Ph(el) : -1;

  static SG::AuxElement::Accessor<char> isBrems("isBrems");
  lep.isBrems = ( isBrems.isAvailable(el) ) ? isBrems(el) : -1;
  //std::cout << "Its Brems Elec and bkgMotherPdgId is " << bkgElMotherPdgID << " and type: " << bkgElType << " and origin: " << bkgElOrigin << std::endl;

  // Whatever is not a prompt or a QMisID, is a fake to us!
  lep.isFakeLep = ( !( lep.isPrompt == 1 ) && !( lep.isQMisID == 1 ) );

  static SG::AuxElement::Accessor<float> promptLeptonIso_TagWeight("PromptLeptonIso_TagWeight");
  lep.promptLeptonIso_TagWeight = ( promptLeptonIso_TagWeight.isAvailable(el) ) ? promptLeptonIso_TagWeight(el) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_sv1_jf_ntrkv("PromptLeptonIso_sv1_jf_ntrkv");
  lep.promptLeptonIso_sv1_jf_ntrkv = ( promptLeptonIso_sv1_jf_ntrkv.isAvailable(el) ) ? promptLeptonIso_sv1_jf_ntrkv(el) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_TrackJetNTrack("PromptLeptonIso_TrackJetNTrack");
  lep.promptLeptonIso_TrackJetNTrack = ( promptLeptonIso_TrackJetNTrack.isAvailable(el) ) ? promptLeptonIso_TrackJetNTrack(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip2("PromptLeptonIso_ip2");
  lep.promptLeptonIso_ip2 = ( promptLeptonIso_ip2.isAvailable(el) ) ? promptLeptonIso_ip2(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip3("PromptLeptonIso_ip3");
  lep.promptLeptonIso_ip3 = ( promptLeptonIso_ip3.isAvailable(el) ) ? promptLeptonIso_ip3(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_DRlj("PromptLeptonIso_DRlj");
  lep.promptLeptonIso_DRlj = ( promptLeptonIso_DRlj.isAvailable(el) ) ? promptLeptonIso_DRlj(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_LepJetPtFrac("PromptLeptonIso_LepJetPtFrac");
  lep.promptLeptonIso_LepJetPtFrac = ( promptLeptonIso_LepJetPtFrac.isAvailable(el) ) ? promptLeptonIso_LepJetPtFrac(el) : -99;

  static SG::AuxElement::Accessor<float> promptLepton_TagWeight("PromptLepton_TagWeight");
  lep.promptLepton_TagWeight = ( promptLepton_TagWeight.isAvailable(el) ) ? promptLepton_TagWeight(el) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonNoIso_TagWeight("PromptLeptonNoIso_TagWeight");
  lep.promptLeptonNoIso_TagWeight = ( promptLeptonNoIso_TagWeight.isAvailable(el) ) ? promptLeptonNoIso_TagWeight(el) : -99;

  static SG::AuxElement::Accessor<float> chargeIDBDTLoose("chargeIDBDTLoose");
  lep.chargeIDBDTLoose = ( chargeIDBDTLoose.isAvailable(el) ) ? chargeIDBDTLoose(el) : -99;

  static SG::AuxElement::Accessor<float> chargeIDBDTMedium("chargeIDBDTMedium");
  lep.chargeIDBDTMedium = ( chargeIDBDTMedium.isAvailable(el) ) ? chargeIDBDTMedium(el) : -99;

  static SG::AuxElement::Accessor<float> chargeIDBDTTight("chargeIDBDTTight");
  lep.chargeIDBDTTight = ( chargeIDBDTTight.isAvailable(el) ) ? chargeIDBDTTight(el) : -99;

  static SG::AuxElement::Accessor<char> isTruthMatched("isTruthMatched");
  lep.isTruthMatched = ( isTruthMatched.isAvailable(el) ) ? isTruthMatched(el) : -1;

  lep.truthOrigin = TruthOrigin;
  lep.truthType = TruthType;


  static SG::AuxElement::Accessor<int> truthPdgId("truthPdgId");
  lep.truthPdgId = ( truthPdgId.isAvailable(el) ) ? truthPdgId(el) : -1;

  static SG::AuxElement::Accessor<int> truthStatus("truthStatus");
  lep.truthStatus = ( truthStatus.isAvailable(el) ) ? truthStatus(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentType("ancestorTruthType");
  lep.truthParentType = ( truthParentType.isAvailable(el) ) ? truthParentType(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentOrigin("ancestorTruthOrigin");
  lep.truthParentOrigin = ( truthParentOrigin.isAvailable(el) ) ? truthParentOrigin(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentPdgId("ancestorTruthPdgId");
  lep.truthParentPdgId = ( truthParentPdgId.isAvailable(el) ) ? truthParentPdgId(el) : -1;

  static SG::AuxElement::Accessor<int> truthParentStatus("ancestorTruthStatus");
  lep.truthParentStatus = ( truthParentStatus.isAvailable(el) ) ? truthParentStatus(el) : -1;

  static SG::AuxElement::Accessor<float> truthPt("truthPt");
  lep.truthPt = ( truthPt.isAvailable(el) ) ? truthPt(el) : -1;

  static SG::AuxElement::Accessor<float> truthEta("truthEta");
  lep.truthEta = ( truthEta.isAvailable(el) ) ? truthEta(el) : -1;

  static SG::AuxElement::Accessor<float> truthPhi("truthPhi");
  lep.truthPhi = ( truthPhi.isAvailable(el) ) ? truthPhi(el) : -1;

  static SG::AuxElement::Accessor<float> truthM("truthM");
  lep.truthM = ( truthM.isAvailable(el) ) ? truthM(el) : -1;

  static SG::AuxElement::Accessor<float> truthE("truthE");
  lep.truthE = ( truthE.isAvailable(el) ) ? truthE(el) : -1;

  static SG::AuxElement::Accessor<float> truthRapidity("truthRapidity");
  lep.truthRapidity = ( truthRapidity.isAvailable(el) ) ? truthRapidity(el) : -1;
  
  // trigger matching, electron pt > 25 GeV
  if (m_runYear == 2015) {
    lep.isTrigMatch = ( el.pt() > 25e3 && (
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e24_lhmedium_L1EM20VH", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e120_lhloose", (char) 0)));
  }
  else if (m_runYear == 2016) {
    lep.isTrigMatch = ( el.pt() > 27e3 && (
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e26_lhtight_nod0_ivarloose", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium_nod0", (char) 0) ||
					   returnDecoIfAvailable(el, "TRIGMATCH_HLT_e140_lhloose_nod0", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  if (m_runYear == 2015) {
    lep.isTrigMatchDLT = ( (el.pt() > 13e3 && returnDecoIfAvailable(el, "TRIGMATCH_HLT_2e12_lhloose_L12EM10VH", (char) 0)) || 
			   (el.pt() > 18e3 && returnDecoIfAvailable(el, "TRIGMATCH_HLT_e17_lhloose_mu14"      , (char) 0)) );
  }
  else if (m_runYear == 2016) {
    lep.isTrigMatchDLT = ( el.pt() > 18e3 && (
                                              returnDecoIfAvailable(el, "TRIGMATCH_HLT_2e17_lhvloose_nod0"   , (char) 0) ||
                                              returnDecoIfAvailable(el, "TRIGMATCH_HLT_e17_lhloose_nod0_mu14", (char) 0)));
  } else {
    lep.isTrigMatchDLT = 0;
  }

  /* //////// Different pT threshold for pre and post-ICHEP dataset
  else if (m_runNumber == 298687) { // for full statistics in this run
    lep.isTrigMatch = ( el.pt() > 25e3 && (
      returnDecoIfAvailable(el, "TRIGMATCH_HLT_e24_lhtight_nod0_ivarloose", (char) 0) ||
      returnDecoIfAvailable(el, "TRIGMATCH_HLT_e24_lhmedium_nod0_L1EM20VH", (char) 0) ||
			returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium_nod0", (char) 0) ||
			returnDecoIfAvailable(el, "TRIGMATCH_HLT_e140_lhloose_nod0", (char) 0)));
  } else if (m_runYear == 2016 && m_runNumber < 302900) { // period A to D3 in 2016 data
    lep.isTrigMatch = ( el.pt() > 25e3 && (
      returnDecoIfAvailable(el, "TRIGMATCH_HLT_e24_lhtight_nod0_ivarloose", (char) 0) ||
			returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium_nod0", (char) 0) ||
			returnDecoIfAvailable(el, "TRIGMATCH_HLT_e140_lhloose_nod0", (char) 0)));
  } else if (m_runYear == 2016) { // since period D4 in 2016 data (high luminosity triggers)
    lep.isTrigMatch = ( el.pt() > 27e3 && (
      returnDecoIfAvailable(el, "TRIGMATCH_HLT_e26_lhtight_nod0_ivarloose", (char) 0) ||
			returnDecoIfAvailable(el, "TRIGMATCH_HLT_e60_lhmedium_nod0", (char) 0) ||
			returnDecoIfAvailable(el, "TRIGMATCH_HLT_e140_lhloose_nod0", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  */

  // isolation variables
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone20); lep.ptVarcone20 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone30); lep.ptVarcone30 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone40); lep.ptVarcone40 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone20); lep.topoEtcone20 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone30); lep.topoEtcone30 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone40); lep.topoEtcone40 = iso;}

  lep.nInnerPix = getNInnerPix(el);

  // scale factors
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    if( !m_doSFSystematics && ivar != 0 ) continue; // break after doing nominal
    lep.SFIDLoose[ivar] = m_sfRetriever->electronSF_ID(el, ivar, false);
    lep.SFIDTight[ivar] = m_sfRetriever->electronSF_ID(el, ivar, true);
    lep.SFTrigLoose[ivar] = m_sfRetriever->electronSF_Trigger(el, ivar, false);
    lep.SFTrigTight[ivar] = m_sfRetriever->electronSF_Trigger(el, ivar, true);
    if (lep.SFTrigLoose[ivar] == 0) lep.SFTrigLoose[ivar] = 1;
    if (lep.SFTrigTight[ivar] == 0) lep.SFTrigTight[ivar] = 1;
    lep.SFIsoLoose[ivar] = m_sfRetriever->electronSF_Isol(el, ivar, false);
    lep.SFIsoTight[ivar] = m_sfRetriever->electronSF_Isol(el, ivar, true);
    lep.SFReco[ivar] = m_sfRetriever->electronSF_Reco(el, ivar);
    lep.SFTTVA[ivar] = 1;
    // I know the loose/tight swap looks weird, but it's intentional
    lep.EffTrigLoose[ivar] = electronEff_Trigger(el, m_config->electronID(), ivar);
    lep.EffTrigTight[ivar] = electronEff_Trigger(el, m_config->electronIDLoose(), ivar);
    // Everything except trigger
    lep.SFObjLoose[ivar] = lep.SFIDLoose[ivar]*lep.SFIsoLoose[ivar]*lep.SFReco[ivar];
    lep.SFObjTight[ivar] = lep.SFIDTight[ivar]*lep.SFIsoTight[ivar]*lep.SFReco[ivar];
  }
}

void ttHMultileptonLooseEventSaver::
CopyMuon(xAOD::Muon& mu, ttHMultilepton::Lepton& lep) {
  CopyIParticle(mu, lep);
  CopyIso(mu, lep);
  CopyIParam(mu, lep);
  lep.ID = -13*mu.charge();
  lep.isLoose  = (char) ( muonSelection.getQuality(mu) <= xAOD::Muon::Loose  && muonSelection.passedIDCuts(mu) );
  lep.isMedium = (char) ( muonSelection.getQuality(mu) <= xAOD::Muon::Medium && muonSelection.passedIDCuts(mu) );
  lep.isTight  = (char) ( muonSelection.getQuality(mu) <= xAOD::Muon::Tight  && muonSelection.passedIDCuts(mu) );

  // lep.d0 = mu.trackParticle(xAOD::Muon::TrackParticleType::CombinedTrackParticle)->d0();
  // lep.z0 = mu.trackParticle(xAOD::Muon::TrackParticleType::CombinedTrackParticle)->z0();
  lep.d0 = mu.primaryTrackParticle()->d0();
  lep.z0 = mu.primaryTrackParticle()->z0();
  lep.vz = mu.primaryTrackParticle()->vz();

  static SG::AuxElement::Accessor<float> mujet_jetPt("jet_pt");
  lep.mujet_jetPt = (mujet_jetPt.isAvailable(mu)) ? mujet_jetPt(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_jetNTrk("jet_numTrk");
  lep.mujet_jetNTrk = (mujet_jetNTrk.isAvailable(mu)) ? mujet_jetNTrk(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_jetSumPtTrk("jet_sumPtTrk");
  lep.mujet_jetSumPtTrk = (mujet_jetSumPtTrk.isAvailable(mu)) ? mujet_jetSumPtTrk(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_mv2c10("MV2c10_weight");
  lep.mujet_mv2c10 = (mujet_mv2c10.isAvailable(mu)) ? mujet_mv2c10(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_deltaR("dRJet"); //changed for PromptLeptonIso calibration
  lep.mujet_deltaR = (mujet_deltaR.isAvailable(mu)) ? mujet_deltaR(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_ptRel("jet_ptRel");
  lep.mujet_ptRel = (mujet_ptRel.isAvailable(mu)) ? mujet_ptRel(mu): -99;

  static SG::AuxElement::Accessor<float> mujet_jetPtOverpt("jet_pt");
  lep.mujet_jetPtOverpt = (mujet_jetPtOverpt.isAvailable(mu)) ? mujet_jetPtOverpt(mu)/mu.pt(): -99;

  static::SG::AuxElement::Accessor<float> mujet_BDT("muon_BDT");
  lep.mujet_BDT        = (mujet_BDT.isAvailable(mu)) ? mujet_BDT(mu): -99;



  // trigger matching
  if (m_runYear == 2015) {
    lep.isTrigMatch = (mu.pt() > 21e3 && (
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu20_iloose_L1MU15", (char) 0) ||
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else if (m_runYear == 2016) { // since period D4 on in 2016 data (high luminosity triggers)
    lep.isTrigMatch = (mu.pt() > 27e3 && (
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu26_ivarmedium", (char) 0) ||
					  returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  if (m_runYear == 2015) {
    lep.isTrigMatchDLT = ( (mu.pt() > 9e3  && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu18_mu8noL1"    , (char) 0)) ||
			   (mu.pt() > 15e3 && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_e17_lhloose_mu14", (char) 0)) );
  }
  else if (m_runYear == 2016) {
    lep.isTrigMatchDLT = ( (mu.pt() > 9e3  && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu22_mu8noL1"         , (char) 0)) ||
                           (mu.pt() > 15e3 && returnDecoIfAvailable(mu, "TRIGMATCH_HLT_e17_lhloose_nod0_mu14", (char) 0)) );
  } else {
    lep.isTrigMatchDLT = 0;
  }

  /* //////// Different pT threshold for pre and post-ICHEP dataset
  else if (m_runYear == 2016 && m_runNumber < 302900) { // period A to D3 in 2016 data
    lep.isTrigMatch = (mu.pt() > 25e3 && (
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu24_ivarmedium", (char) 0) ||
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else if (m_runYear == 2016) { // since period D4 on in 2016 data (high luminosity triggers)
    lep.isTrigMatch = (mu.pt() > 27e3 && (
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu26_ivarmedium", (char) 0) ||
	    returnDecoIfAvailable(mu, "TRIGMATCH_HLT_mu50", (char) 0)));
  } else { // MC events with pileupEventWeight==0
    lep.isTrigMatch = 0;
  }
  */

  // truth matching, fakes, QMisId
  int TruthType = -99;
  int TruthOrigin = -99;

  if(m_isMC) {
    static SG::AuxElement::Accessor<int> acc_mctt("truthType");
    const xAOD::TrackParticle* mutrack = mu.primaryTrackParticle();
    if (mutrack!=nullptr) {
      if (acc_mctt.isAvailable(*mutrack)) TruthType = acc_mctt(*mutrack);
    }

    static SG::AuxElement::Accessor<int> acc_mcto("truthOrigin");
    if (mutrack!=nullptr) {
      if (acc_mcto.isAvailable(*mutrack)) TruthOrigin = acc_mcto(*mutrack);
    }
  }

  // const xAOD::TruthParticle* matched_truth_muon=0;
  // if(mu.isAvailable<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink")) {
  //   ElementLink<xAOD::TruthParticleContainer> link = mu.auxdata<ElementLink<xAOD::TruthParticleContainer> >("truthParticleLink");
  //   if(link.isValid()){
  //     matched_truth_muon = *link;
  //     truthOrigin = matched_truth_muon->auxdata<int>("truthOrigin");
  //   }
  // }

  // const xAOD::TrackParticle* idtp=0;
  // ElementLink<xAOD::TrackParticleContainer> idtpLink = mu.inDetTrackParticleLink();
  // if(idtpLink.isValid()){
  //   idtp = *idtpLink;
  //   if(m_isMC) truthType = idtp->auxdata<int>("truthType");
  // }

  if (TruthType == 2 || TruthType == 6)
    lep.isPrompt = 1;
  else
    lep.isPrompt = 0;

  static SG::AuxElement::Accessor<char> QMisID("isQMisID");
  lep.isQMisID = ( QMisID.isAvailable(mu) ) ?  QMisID(mu) : -1;

  static SG::AuxElement::Accessor<char> ConvPh("isConvPh");
  lep.isConvPh = ( ConvPh.isAvailable(mu) ) ?  ConvPh(mu) : -1;

  static SG::AuxElement::Accessor<char> ISR_FSR_Ph("isISR_FSR_Ph");
  lep.isISR_FSR_Ph = ( ISR_FSR_Ph.isAvailable(mu) ) ?  ISR_FSR_Ph(mu) : -1;

  static SG::AuxElement::Accessor<char> isBrems("isBrems");
  lep.isBrems = ( isBrems.isAvailable(mu) ) ? isBrems(mu) : -1;
  //std::cout << "Its Brems Elec and bkgMotherPdgId is " << bkgElMotherPdgID << " and type: " << bkgElType << " and origin: " << bkgElOrigin << std::endl;

  static SG::AuxElement::Accessor<float> promptLeptonIso_TagWeight("PromptLeptonIso_TagWeight");
  lep.promptLeptonIso_TagWeight = ( promptLeptonIso_TagWeight.isAvailable(mu) ) ? promptLeptonIso_TagWeight(mu) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_sv1_jf_ntrkv("PromptLeptonIso_sv1_jf_ntrkv");
  lep.promptLeptonIso_sv1_jf_ntrkv = ( promptLeptonIso_sv1_jf_ntrkv.isAvailable(mu) ) ? promptLeptonIso_sv1_jf_ntrkv(mu) : -99;

  static SG::AuxElement::Accessor<short> promptLeptonIso_TrackJetNTrack("PromptLeptonIso_TrackJetNTrack");
  lep.promptLeptonIso_TrackJetNTrack = ( promptLeptonIso_TrackJetNTrack.isAvailable(mu) ) ? promptLeptonIso_TrackJetNTrack(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip2("PromptLeptonIso_ip2");
  lep.promptLeptonIso_ip2 = ( promptLeptonIso_ip2.isAvailable(mu) ) ? promptLeptonIso_ip2(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_ip3("PromptLeptonIso_ip3");
  lep.promptLeptonIso_ip3 = ( promptLeptonIso_ip3.isAvailable(mu) ) ? promptLeptonIso_ip3(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_DRlj("PromptLeptonIso_DRlj");
  lep.promptLeptonIso_DRlj = ( promptLeptonIso_DRlj.isAvailable(mu) ) ? promptLeptonIso_DRlj(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonIso_LepJetPtFrac("PromptLeptonIso_LepJetPtFrac");
  lep.promptLeptonIso_LepJetPtFrac = ( promptLeptonIso_LepJetPtFrac.isAvailable(mu) ) ? promptLeptonIso_LepJetPtFrac(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLepton_TagWeight("PromptLepton_TagWeight");
  lep.promptLepton_TagWeight = ( promptLepton_TagWeight.isAvailable(mu) ) ? promptLepton_TagWeight(mu) : -99;

  static SG::AuxElement::Accessor<float> promptLeptonNoIso_TagWeight("PromptLeptonNoIso_TagWeight");
  lep.promptLeptonNoIso_TagWeight = ( promptLeptonNoIso_TagWeight.isAvailable(mu) ) ? promptLeptonNoIso_TagWeight(mu) : -99;

  // Whatever is not a prompt or a QMisID, is a fake to us!
  lep.isFakeLep = ( !( lep.isPrompt == 1 ) && !( lep.isQMisID == 1 ) );

  static SG::AuxElement::Accessor<char> isTruthMatched("isTruthMatched");
  lep.isTruthMatched = ( isTruthMatched.isAvailable(mu) ) ? isTruthMatched(mu) : -1;

  lep.truthOrigin = TruthOrigin;
  lep.truthType = TruthType;

  static SG::AuxElement::Accessor<int> truthPdgId("truthPdgId");
  lep.truthPdgId = ( truthPdgId.isAvailable(mu) ) ? truthPdgId(mu) : -1;

  static SG::AuxElement::Accessor<int> truthStatus("truthStatus");
  lep.truthStatus = ( truthStatus.isAvailable(mu) ) ? truthStatus(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentType("ancestorTruthType");
  lep.truthParentType = ( truthParentType.isAvailable(mu) ) ? truthParentType(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentOrigin("ancestorTruthOrigin");
  lep.truthParentOrigin = ( truthParentOrigin.isAvailable(mu) ) ? truthParentOrigin(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentPdgId("ancestorTruthPdgId");
  lep.truthParentPdgId = ( truthParentPdgId.isAvailable(mu) ) ? truthParentPdgId(mu) : -1;

  static SG::AuxElement::Accessor<int> truthParentStatus("ancestorTruthStatus");
  lep.truthParentStatus = ( truthParentStatus.isAvailable(mu) ) ? truthParentStatus(mu) : -1;

  static SG::AuxElement::Accessor<float> truthPt("truthPt");
  lep.truthPt = ( truthPt.isAvailable(mu) ) ? truthPt(mu) : -1;

  static SG::AuxElement::Accessor<float> truthEta("truthEta");
  lep.truthEta = ( truthEta.isAvailable(mu) ) ? truthEta(mu) : -1;

  static SG::AuxElement::Accessor<float> truthPhi("truthPhi");
  lep.truthPhi = ( truthPhi.isAvailable(mu) ) ? truthPhi(mu) : -1;

  static SG::AuxElement::Accessor<float> truthM("truthM");
  lep.truthM = ( truthM.isAvailable(mu) ) ? truthM(mu) : -1;

  static SG::AuxElement::Accessor<float> truthE("truthE");
  lep.truthE = ( truthE.isAvailable(mu) ) ? truthE(mu) : -1;

  static SG::AuxElement::Accessor<float> truthRapidity("truthRapidity");
  lep.truthRapidity = ( truthRapidity.isAvailable(mu) ) ? truthRapidity(mu) : -1;

  // isolation variables
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone20); lep.ptVarcone20 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone30); lep.ptVarcone30 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone40); lep.ptVarcone40 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone20); lep.topoEtcone20 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone30); lep.topoEtcone30 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone40); lep.topoEtcone40 = iso;}

  lep.nInnerPix = getNInnerPix(mu);

  // scale factors
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    if( !m_doSFSystematics && ivar != 0 ) continue;
    // I know the loose/tight swap looks weird, but it's intentional
    lep.SFIDLoose[ivar] = m_sfRetriever->muonSF_ID(mu, ivar, false);
    lep.SFIDTight[ivar] = m_sfRetriever->muonSF_ID(mu, ivar, true);
    lep.SFTrigLoose[ivar] = m_sfRetriever->muonSF_Trigger(mu, ivar, false);
    lep.SFTrigTight[ivar] = m_sfRetriever->muonSF_Trigger(mu, ivar, true);
    lep.SFIsoLoose[ivar] = m_sfRetriever->muonSF_Isol(mu, ivar, false);
    lep.SFIsoTight[ivar] = m_sfRetriever->muonSF_Isol(mu, ivar, true);
    lep.SFTTVA[ivar] = m_isMC ? m_sfRetriever->muonSF_TTVA(mu, ivar) : 1.0;
    lep.SFReco[ivar] = 1;
    lep.EffTrigLoose[ivar] = muonEff_Trigger(mu, m_config->muonQuality(), ivar);
    lep.EffTrigTight[ivar] = muonEff_Trigger(mu, m_config->muonQualityLoose(), ivar);
  // Everything except trigger
    lep.SFObjLoose[ivar] = lep.SFIDLoose[ivar]*lep.SFIsoLoose[ivar]*lep.SFTTVA[ivar];
    lep.SFObjTight[ivar] = lep.SFIDTight[ivar]*lep.SFIsoTight[ivar]*lep.SFTTVA[ivar];
  }
}

void
ttHMultileptonLooseEventSaver::CopyLeptons(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu) {
  memset(&m_leptons, 0, sizeof(m_leptons));
  const int totleptons = goodEl->size() + goodMu->size();
  m_variables->total_leptons = totleptons;
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
    //m_variables->Mll01 = p4_01.M();
    //m_variables->Ptll01 = p4_01.Pt();
    //m_variables->DRll01 = p4s[0]->DeltaR(*p4s[1]);
    int zidx[2]{-1,-1};
    for (int idx1 = 0; idx1 < capped_totleptons-1; ++idx1) {
      for (int idx2 = idx1+1; idx2 < capped_totleptons; ++idx2) {
	TLorentzVector p4sum = *p4s[idx1] + *p4s[idx2];
	m_variables->Mll[idx1][idx2-1] = p4sum.M();
	m_variables->Ptll[idx1][idx2-1] = p4sum.Pt();
	m_variables->DRll[idx1][idx2-1] = p4s[idx1]->DeltaR(*p4s[idx2]);
        m_variables->matchDLTll[idx1][idx2-1] = ( (int)m_leptons[idx1].isTrigMatchDLT && (int)m_leptons[idx2].isTrigMatchDLT
          && std::max(m_leptons[idx1].Pt, m_leptons[idx2].Pt)
          > (abs(m_leptons[idx1].ID*m_leptons[idx2].ID)==169)*((m_runYear==2015)*19e3+(m_runYear==2016)*23e3) );
	// min Mll variables
	if (m_leptons[idx1].ID * m_leptons[idx2].ID < 0) {
	  if (m_variables->minOSMll == 0 || 
	      m_variables->Mll[idx1][idx2-1] < m_variables->minOSMll) {
	    m_variables->minOSMll = m_variables->Mll[idx1][idx2-1];
	  }
	}
	if (m_leptons[idx1].ID == -m_leptons[idx2].ID) {
	  if (m_variables->best_Z_Mll == 0 ||
	      (fabs(m_variables->Mll[idx1][idx2-1]-91.1876e3) <
	       fabs(m_variables->best_Z_Mll-91.1876e3))) {
	    m_variables->best_Z_Mll=m_variables->Mll[idx1][idx2-1];
	    zidx[0] = idx1; zidx[1] = idx2;
	  }
	  // min Mll variables
	  if (m_variables->minOSSFMll == 0 || 
	      m_variables->Mll[idx1][idx2-1] < m_variables->minOSSFMll) {
	    m_variables->minOSSFMll = m_variables->Mll[idx1][idx2-1];
	  }
	}
	for (int idx3 = idx2+1; idx3 < capped_totleptons; ++idx3) {
	  TLorentzVector p4sum3 = p4sum + *p4s[idx3];
	  m_variables->Mlll[idx1][idx2-1][idx3-2] = p4sum3.M();
	  for (int idx4 = idx3+1; idx4 < capped_totleptons; ++idx4) {
	    TLorentzVector p4sum4 = p4sum3 + *p4s[idx4];
	    m_variables->Mllll[idx1][idx2-1][idx3-2][idx4-3] = p4sum4.M();
	  }
	}
      }
    }
    if (totleptons==3 && zidx[0] >= 0) {
      int oidx = 3 - zidx[0] - zidx[1];
      TLorentzVector p4met;
      p4met.SetPtEtaPhiM(m_met_met,0,m_met_phi,0);
      m_variables->best_Z_other_MtLepMet = (p4met + *p4s[oidx]).Mt();
    }
    if (totleptons==4 && zidx[0] >= 0) {
      std::vector<int> otherleps;
      for (int idx = 0; idx < 4; ++idx) {
	if (idx != zidx[0] && idx != zidx[1]) {
	  otherleps.push_back(idx);
	}
      }
      m_variables->best_Z_other_Mll = m_variables->Mll[otherleps[0]][otherleps[1]-1];
    }
  }

  // Flag event if there's at least one truth-QMisID/truth-fake/truth-From-Non-GEANT-Photon lepton
  //
  // By construction, "isLepFromPhEvent==1" is a subset of "isFakeEvent==1"
  //
  if ( m_isMC && totleptons >= 1 ) {

    m_variables->isQMisIDEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
      if ( m_leptons[idx].isQMisID == 1 ) {
    	m_variables->isQMisIDEvent = 1;
    	break;
      }
    }
    m_variables->isFakeEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
      if ( m_leptons[idx].isFakeLep == 1 ) {
    	m_variables->isFakeEvent = 1;
    	break;
      }
    }
    m_variables->isLepFromPhEvent = 0; // default
    for (short idx = 0; idx < capped_totleptons; ++idx) {
	if ( m_leptons[idx].isConvPh == 1 || m_leptons[idx].isISR_FSR_Ph == 1 ) {
    	m_variables->isLepFromPhEvent = 1;
    	break;
      }
    }
  } else {
    m_variables->isQMisIDEvent    = -1; // default for data
    m_variables->isFakeEvent      = -1; // default for data
    m_variables->isLepFromPhEvent = -1; // default for data
  }
}

void
ttHMultileptonLooseEventSaver::doEventTrigSFs(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, const top::Event& event) {
  
  for (const auto& systvar : m_lep_sf_names) {
    auto ivar = systvar.first;
    m_variables->lepSFTrigLoose[ivar] = 1;
    m_variables->lepSFTrigTight[ivar] = 1;
  }

  // The following: index 0 = 1-eff(mc), index 1 = 1-eff(data)
  //  double oneMinusTrigEffLoose[2]{1,1}, oneMinusTrigEffTight[2]{1,1};
  double oneMinusTrigEffLoose[MAXSYST][2], oneMinusTrigEffTight[MAXSYST][2];
  for (int idx1 = 0; idx1 < MAXSYST; ++idx1) {
    for (int idx2 = 0; idx2 < 2; ++idx2) {
      oneMinusTrigEffLoose[idx1][idx2] = oneMinusTrigEffTight[idx1][idx2] = 1.;
    }
  }

  SG::AuxElement::Decorator<char> dec_tight("Signal"); // to tag electrons passing tight PID and PLI
  SG::AuxElement::Decorator<char> dec_tightCFT("SignalCFT"); // to tag electrons passing tight PID and PLI+CFT
  SG::AuxElement::Decorator<char> dec_loose("Baseline"); // to tag electrons passing loose PID
 
  //std::cout << "doEventTrigSFs::Starting event loop" << std::endl;
  //int errors = 0;
  
  //const int totleptons = goodEl->size() + goodMu->size();
    
  unsigned runNumber = 305291; // 2016 period G
  event.m_info->auxdecor<unsigned int>("RandomRunNumber") = runNumber;
  
  std::vector<const xAOD::Electron*> myTriggeringElectrons;
  std::vector<const xAOD::Muon*> myTriggeringMuons;

  //int nAbove18GeV = 0;
  for(auto electron : *goodEl)
    {
      //float pt = 0.001f*electron->pt(), eta = (electron->caloCluster()? fabs(electron->caloCluster()->etaBE(2)) : 10.f);
      //if(pt<10.f || eta>2.47) continue;
      //int type = electron->auxdata<int>("truthType"), origin = electron->auxdata<int>("truthOrigin");
      //if(type!=2 || !(origin==10 || (origin>=12 && origin<=22) || origin==43)) continue;
      myTriggeringElectrons.push_back(electron);
      //if(pt>18.f) ++nAbove18GeV;
    }
  
  float leadMuonPt = -1000.;
  for(auto muon : *goodMu)
    {
      float pt = 0.001f*muon->pt();
      //if(pt<10.f || eta>=2.5 || (muon->muonType()!=xAOD::Muon::Combined && muon->muonType()!=xAOD::Muon::MuonStandAlone)) continue;
      //int type = muon->primaryTrackParticle()->auxdata<int>("truthType"), origin = muon->primaryTrackParticle()->auxdata<int>("truthOrigin");
      //if(type!=6 || !(origin==10 || (origin>=12 && origin<=22) || origin==43)) continue;
      leadMuonPt = std::max(pt,leadMuonPt);
      myTriggeringMuons.push_back(muon);
    }
  
  //Calculate per-Event Trigger lepton SFs
  switch (m_variables->total_leptons) {
  case 2:
    {
      //if(nAbove18GeV<2) return;
      int nTrig = -1;
      for (const auto& systvar : m_lep_trigger_sf_names) {
	++nTrig;
	
	if (abs(m_variables->total_charge) == 0 && m_variables->nTaus_OR_Pt25>0){
	  for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_tightCFT(*e) = 0; dec_loose(*e) = 1;}//TightTight SF 2LOS
	}
	else {
	  for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_tightCFT(*e) = 1; dec_loose(*e) = 0;}//TightTight SF 2LSS
	}

	double sf_tt = 1.;
	auto cc_tt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_tt);
	if(cc_tt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigTight[nTrig] = sf_tt;
	    //std::cout << "2LSSTightTight:TriggerScaleFactor is for sys " << systvar.second << " : " << sf_tt << std::endl;
	  }
	double dummy,eff_tt = 0.; //TightTight EFF
	auto cc_Ett = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy, eff_tt);
	if(cc_Ett==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigTight[nTrig] = eff_tt;
	    m_variables->lepDataEffTrigTight[nTrig] = dummy;
	    
	    // std::cout << "2LSSTightTight:TriggerEff is for sys " << systvar.second << " : " << eff_tt << std::endl;
	    // std::cout << "2LSSTightTight:TriggerEff Data is for sys " << systvar.second << " : " << dummy << std::endl;
	  }
      
	for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_tightCFT(*e) = 0; dec_loose(*e) = 1;} //LooseLoose SF
	double sf_ll = 1.;
	auto cc_ll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_ll);
	if(cc_ll==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigLoose[nTrig] = sf_ll;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_2,eff_ll = 0.; //LooseLoose EFF
	auto cc_Ell = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_2, eff_ll);
	if(cc_Ell==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigLoose[nTrig] = eff_ll;
	    m_variables->lepDataEffTrigLoose[nTrig] = dummy_2;
	    //std::cout << "2LSSLooseLoose:TriggerEff is for sys " << systvar.second << " : " << eff_ll << std::endl;
	  }
	
	float leadElectronPt = -1000.;
	int nCount=-1;
	for(auto e : myTriggeringElectrons) {
	  ++nCount;
	  float pt = 0.001f*e->pt();
	  //std::cout << nCount << " electron pT " << pt << std::endl;
	  leadElectronPt = std::max(pt,leadElectronPt);
	  dec_tight(*e) = 0;
	  if (myTriggeringMuons.size()==0){
	    if (nCount==0) { dec_tightCFT(*e) = 1; dec_loose(*e) = 0; }
	    else if (nCount==1) { dec_tightCFT(*e) = 0; dec_loose(*e) = 1; }
	  }
	  else {
	    if (leadElectronPt > leadMuonPt) { dec_tightCFT(*e) = 1; dec_loose(*e) = 0; }
	    else { dec_tightCFT(*e) = 0; dec_loose(*e) = 1; }
	  }
	} //TightLoose SF
	double sf_tl = 1.;
	auto cc_tl = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_tl);
	if(cc_tl==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigTightLoose[nTrig] = sf_tl;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_3,eff_tl = 0.; //TightLoose EFF
	auto cc_Etl = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_3, eff_tl);
	if(cc_Etl==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigTightLoose[nTrig] = eff_tl;
	    m_variables->lepDataEffTrigTightLoose[nTrig] = dummy_3;
	    //std::cout << "2LSSTightLoose:TriggerEff is for sys " << systvar.second << " : " << eff_tl << std::endl;
	  }
	
	leadElectronPt = -1000.;
	nCount=-1;
	for(auto e : myTriggeringElectrons) {
	  ++nCount;
	  float pt = 0.001f*e->pt();
	  //std::cout << nCount << " electron pT " << pt << std::endl;
	  leadElectronPt = std::max(pt,leadElectronPt);
	  dec_tight(*e) = 0;
	  if (myTriggeringMuons.size()==0){
	    if (nCount==0) { dec_tightCFT(*e) = 0; dec_loose(*e) = 1; }
	    else if (nCount==1) { dec_tightCFT(*e) = 1; dec_loose(*e) = 0; }
	  }
	  else {
	    if (leadElectronPt > leadMuonPt) { dec_tightCFT(*e) = 0; dec_loose(*e) = 1; }
	    else { dec_tightCFT(*e) = 1; dec_loose(*e) = 0; }
	  }
	} //LooseTight SF
	double sf_lt = 1.;
	auto cc_lt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_lt);
	if(cc_lt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigLooseTight[nTrig] = sf_lt;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_4,eff_lt = 0.; //TightLoose EFF
	auto cc_Elt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_4, eff_lt);
	if(cc_Elt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigLooseTight[nTrig] = eff_lt;
	    m_variables->lepDataEffTrigLooseTight[nTrig] = dummy_4;
	    //std::cout << "2LSSLooseTight:TriggerEff is for sys " << systvar.second << " : " << eff_lt << std::endl;
	  }
	

      }
      
    }
    break;
  case 1:
    {
      for (int ilep = 0; ilep < m_variables->total_leptons; ++ilep) {
	for (const auto& systvar : m_lep_sf_names) {
	  auto ivar = systvar.first;
	  oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[ilep].EffTrigLoose[ivar]);
	  oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[ilep].EffTrigLoose[ivar]*m_leptons[ilep].SFTrigLoose[ivar]);
	  oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[ilep].EffTrigTight[ivar]);
	  oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[ilep].EffTrigTight[ivar]*m_leptons[ilep].SFTrigTight[ivar]);
	}
      }
      
      m_variables->lepSFTrigLoose[0] = oneMinusTrigEffLoose[0][0] != 1 ? (1-oneMinusTrigEffLoose[0][1])/(1-oneMinusTrigEffLoose[0][0]) : 1;
      m_variables->lepSFTrigTight[0] = oneMinusTrigEffTight[0][0] != 1 ? (1-oneMinusTrigEffTight[0][1])/(1-oneMinusTrigEffTight[0][0]) : 1;
      for (const auto& systvar : m_lep_sf_names) {
	auto ivar = systvar.first;
	//std::cout << "In systematic number " << ivar << " and systematic: " << systvar.second <<  std::endl;
	if (ivar == top::topSFSyst::nominal) continue;
	m_variables->lepSFTrigLoose[ivar] = oneMinusTrigEffLoose[ivar][0] != 1 ? (1-oneMinusTrigEffLoose[ivar][1])/(1-oneMinusTrigEffLoose[ivar][0])/m_variables->lepSFTrigLoose[0] : 1;
	m_variables->lepSFTrigTight[ivar] = oneMinusTrigEffTight[ivar][0] != 1 ? (1-oneMinusTrigEffTight[ivar][1])/(1-oneMinusTrigEffTight[ivar][0])/m_variables->lepSFTrigTight[0] : 1;
      }
    }
    break;
  case 3:
    {

      // Do a sorting for objects
      // (pt, idx, leptype)
      // 3l |q| = 1 has special sorting by Delta R from OS lepton
      typedef std::tuple<const TLorentzVector*, int, ttHMultilepton::LepType> sorttype_t;
      std::vector<sorttype_t> sorter;
      // Get p4 for OS in trilep case
      TLorentzVector p4OS;
      bool is_trilep_q1 = m_variables->trilep_type && abs(m_variables->total_charge) == 1;
      if (is_trilep_q1) {
	for (const auto elItr : myTriggeringElectrons) {
	  if (elItr->charge() == -m_variables->total_charge) {
	    p4OS = elItr->p4(); break;
	  }
	}
	for (const auto muItr : myTriggeringMuons) {
	  if (muItr->charge() == -m_variables->total_charge) {
	    p4OS = muItr->p4(); break;
	  }
	}
      }
      
      size_t idx = 0;
      for (const auto elItr : myTriggeringElectrons) {
	sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHMultilepton::ELECTRON));
      }
      idx = 0;
      for (const auto muItr : myTriggeringMuons) {
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
      
      int nTrig = -1;
      for (const auto& systvar : m_lep_trigger_sf_names) {
	++nTrig;
	
	for(auto e : myTriggeringElectrons) {
	  dec_tight(*e) = 0;
	  if (e->charge() == -m_variables->total_charge){ 
	    dec_loose(*e) = 1;
	    dec_tightCFT(*e) = 0;
	  }
	  else {
	    dec_loose(*e) = 0;	  
	    dec_tightCFT(*e) = 1;
	  }
	}//TightTight
	
	double sf_ltt = 1.;
	auto cc_ltt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_ltt);
	if(cc_ltt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigTight[nTrig] = sf_ltt;
	    //std::cout << "3LTight:TriggerScaleFactor is: " << sf_ltt << std::endl;
	  }
	
	double dummy,eff_ltt = 0.; //TightTight EFF
	auto cc_Eltt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy, eff_ltt);
	if(cc_Eltt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigTight[nTrig] = eff_ltt;
	    m_variables->lepDataEffTrigTight[nTrig] = dummy;
	    //std::cout << "3LTightTight:TriggerEff is for sys " << systvar.second << " : " << eff_ltt << std::endl;
	  }
      
	for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_tightCFT(*e) = 0; dec_loose(*e) = 1;} //LooseLoose SF
	double sf_lll = 1.;
	auto cc_lll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_lll);
	if(cc_lll==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigLoose[nTrig] = sf_lll;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_lll << std::endl;
	  }
	double dummy_2,eff_lll = 0.; //LooseLoose EFF
	auto cc_Elll = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_2, eff_lll);
	if(cc_Elll==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigLoose[nTrig] = eff_lll;
	    m_variables->lepDataEffTrigLoose[nTrig] = dummy_2;
	    //std::cout << "3LLooseLoose:TriggerEff is for sys " << systvar.second << " : " << eff_lll << std::endl;
	  }
	
	short capped_totleptons = std::min(m_variables->total_leptons, LEPTON_ARR_SIZE);
	for (short idx = 0; idx < capped_totleptons; ++idx) {
	  const TLorentzVector* p4;
	  int lidx;
	  ttHMultilepton::LepType typ;
	  std::tie(p4, lidx, typ) = sorter[idx];
	  dec_tight(*(myTriggeringElectrons)[lidx]) = 0;
	  if (typ == ttHMultilepton::ELECTRON){
	    if (idx==0) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==1) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 1;}
	    else if (idx==2) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 0;}
	  }
	} //TightLoose SF

	double sf_ltl = 1.;
	auto cc_ltl = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_ltl);
	if(cc_ltl==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigTightLoose[nTrig] = sf_ltl;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_3,eff_ltl = 0.; //TightLoose EFF
	auto cc_Eltl = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_3, eff_ltl);
	if(cc_Eltl==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigTightLoose[nTrig] = eff_ltl;
	    m_variables->lepDataEffTrigTightLoose[nTrig] = dummy_3;
	    //std::cout << "3LTightLoose:TriggerEff is for sys " << systvar.second << " : " << eff_ltl << std::endl;
	  }


	for (short idx = 0; idx < capped_totleptons; ++idx) {
	  const TLorentzVector* p4;
	  int lidx;
	  ttHMultilepton::LepType typ;
	  std::tie(p4, lidx, typ) = sorter[idx];
	  dec_tight(*(myTriggeringElectrons)[lidx]) = 0;
	  if (typ == ttHMultilepton::ELECTRON){
	    if (idx==0) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==1) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==2) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 1;}
	  }
	} //LooseTight SF

	double sf_llt = 1.;
	auto cc_llt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_llt);
	if(cc_llt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigLooseTight[nTrig] = sf_llt;
	    //std::cout << "2LSSLooseLoose:TriggerScaleFactor is: " << sf_ll << std::endl;
	  }
	double dummy_4,eff_llt = 0.; //TightLoose EFF
	auto cc_Ellt = m_trigGlobEffCorr[nTrig]->getEfficiency(runNumber, myTriggeringElectrons, myTriggeringMuons, dummy_4, eff_llt);
	if(cc_Ellt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepEffTrigLooseTight[nTrig] = eff_llt;
	    m_variables->lepDataEffTrigLooseTight[nTrig] = dummy_4;
	    //std::cout << "3LLooseTight:TriggerEff is for sys " << systvar.second << " : " << eff_llt << std::endl;
	  }
	
      }
    }
    /* // OLD trigger SF computation for SLT
	 for (const auto& systvar : m_lep_sf_names) {
	 auto ivar = systvar.first;
	 oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[0].EffTrigLoose[ivar]);
	 oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[0].EffTrigLoose[ivar]*m_leptons[0].SFTrigLoose[ivar]);
	 oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[0].EffTrigLoose[ivar]);
      oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[0].EffTrigLoose[ivar]*m_leptons[0].SFTrigLoose[ivar]);
    }
    for (int ilep = 1; ilep < m_variables->total_leptons; ++ilep) {
      for (const auto& systvar : m_lep_sf_names) {
	auto ivar = systvar.first;
	oneMinusTrigEffLoose[ivar][0] *= (1-m_leptons[ilep].EffTrigLoose[ivar]);
	oneMinusTrigEffLoose[ivar][1] *= (1-m_leptons[ilep].EffTrigLoose[ivar]*m_leptons[ilep].SFTrigLoose[ivar]);
	oneMinusTrigEffTight[ivar][0] *= (1-m_leptons[ilep].EffTrigTight[ivar]);
	oneMinusTrigEffTight[ivar][1] *= (1-m_leptons[ilep].EffTrigTight[ivar]*m_leptons[ilep].SFTrigTight[ivar]);
      }
    }
    m_variables->lepSFTrigLoose[0] = oneMinusTrigEffLoose[0][0] != 1 ? (1-oneMinusTrigEffLoose[0][1])/(1-oneMinusTrigEffLoose[0][0]) : 1;
    m_variables->lepSFTrigTight[0] = oneMinusTrigEffTight[0][0] != 1 ? (1-oneMinusTrigEffTight[0][1])/(1-oneMinusTrigEffTight[0][0]) : 1;
    //std::cout << "3L:TriggerScaleFactor is: " << m_variables->lepSFTrigTight[0] << std::endl;
    for (const auto& systvar : m_lep_sf_names) {
      auto ivar = systvar.first;
      if (ivar == top::topSFSyst::nominal) continue;
      m_variables->lepSFTrigLoose[ivar] = oneMinusTrigEffLoose[ivar][0] != 1 ? (1-oneMinusTrigEffLoose[ivar][1])/(1-oneMinusTrigEffLoose[ivar][0])/m_variables->lepSFTrigLoose[0] : 1;
      m_variables->lepSFTrigTight[ivar] = oneMinusTrigEffTight[ivar][0] != 1 ? (1-oneMinusTrigEffTight[ivar][1])/(1-oneMinusTrigEffTight[ivar][0])/m_variables->lepSFTrigTight[0] : 1;
    */
  
    break;
  case 4:
    {
      // Do a sorting for objects
      // (pt, idx, leptype)
      typedef std::tuple<const TLorentzVector*, int, ttHMultilepton::LepType> sorttype_t;
      std::vector<sorttype_t> sorter;
            
      size_t idx = 0;
      for (const auto elItr : myTriggeringElectrons) {
	sorter.push_back(std::make_tuple(&(elItr->p4()), idx++, ttHMultilepton::ELECTRON));
      }
      idx = 0;
      for (const auto muItr : myTriggeringMuons) {
	sorter.push_back(sorttype_t(&(muItr->p4()), idx++, ttHMultilepton::MUON));
      }
      // sort by decreasing pt
      std::sort(sorter.begin(), sorter.end(),
		[](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });
    
      
      int nTrig = -1;
      for (const auto& systvar : m_lep_trigger_sf_names) {
	++nTrig;

	short capped_totleptons = std::min(m_variables->total_leptons, LEPTON_ARR_SIZE);
	for (short idx = 0; idx < capped_totleptons; ++idx) {
	  const TLorentzVector* p4;
	  int lidx;
	  ttHMultilepton::LepType typ;
	  std::tie(p4, lidx, typ) = sorter[idx];
	  dec_tightCFT(*(myTriggeringElectrons)[lidx]) = 0;
	  if (typ == ttHMultilepton::ELECTRON){
	    if (idx==0) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==1) {dec_loose(*(myTriggeringElectrons)[lidx]) = 1; dec_tight(*(myTriggeringElectrons)[lidx]) = 0;}
	    else if (idx==2) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tight(*(myTriggeringElectrons)[lidx]) = 1;}
	    else if (idx==3) {dec_loose(*(myTriggeringElectrons)[lidx]) = 0; dec_tight(*(myTriggeringElectrons)[lidx]) = 1;}
	  }
	}//TightTight

	double sf_tttt = 1.;
	auto cc_tttt = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_tttt);
	if(cc_tttt==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigTight[nTrig] = sf_tttt;
	    //std::cout << "4L:TriggerScaleFactor is: " << sf_tttt << std::endl;
	  }
	
	for(auto e : myTriggeringElectrons) {dec_tight(*e) = 0; dec_tightCFT(*e) = 0; dec_loose(*e) = 1;} //LooseLoose
	double sf_llll = 1.;
	auto cc_llll = m_trigGlobEffCorr[nTrig]->getEfficiencyScaleFactor(runNumber, myTriggeringElectrons, myTriggeringMuons, sf_llll);
	if(cc_llll==CP::CorrectionCode::Ok)
	  {
	    m_variables->lepSFTrigLoose[nTrig] = sf_llll;
	    //std::cout << "4LLooseLoose:TriggerScaleFactor is: " << sf_llll << std::endl;
	  }	
      }
    }
    break;
  default:
    return;
  }
    
  //naaaaan
  for ( auto syst : m_lep_sf_names ) {
    auto ivar = syst.first;
      if( m_variables->lepSFTrigLoose[ivar] != m_variables->lepSFTrigLoose[ivar] ) {
	//std::cout<<"nanananana"<<std::endl;
	m_variables->lepSFTrigLoose[ivar] = 1;
      }
      if( m_variables->lepSFTrigTight[ivar] != m_variables->lepSFTrigTight[ivar] ) {
	//std::cout<<"nanananana"<<std::endl;
	m_variables->lepSFTrigTight[ivar] = 1;
      }
      
  }
  
}

void
ttHMultileptonLooseEventSaver::MakeJetIndices(const std::shared_ptr<xAOD::JetContainer>& goodJets,
					      const xAOD::JetContainer& allJets) {
  m_variables->selected_jets.clear();
  m_variables->selected_jets_T.clear();
  for (const auto jetItr : *goodJets) {
    if (!jetItr->template auxdataConst<char>("ttHpassOVR")) continue;
    auto& goodp4 = jetItr->p4();
    bool found = false;
    for (size_t idx = 0; idx < allJets.size(); ++idx) {
      if (goodp4 == allJets[idx]->p4()) {
	found = true;
	m_variables->selected_jets.push_back(idx);
	if (jetItr->template auxdataConst<char>("ttHpassTauOVR")) {
	  m_variables->selected_jets_T.push_back(idx);
	}
	break;
      }
    }
    if (!found) {
      std::cerr << "Unable to find a jet match. Sad!" << std::endl;
    }
  }
}

void
ttHMultileptonLooseEventSaver::CopyJets(std::shared_ptr<xAOD::JetContainer>& goodJets) {
  // don't actually copy anything ATM, just give yields of jets & btags
  m_variables->nJets_OR = goodJets->size();
  m_variables->nJets_OR_T = CountPassOR(*goodJets, true);
  m_variables->nTruthJets_OR = this->getNTruthJets(goodJets);


  m_variables->nJets_OR_MV2c20_85   = 0;
  m_variables->nJets_OR_MV2c20_70   = 0;
  m_variables->nJets_OR_MV2c20_77   = 0;
  m_variables->nJets_OR_MV2c20_60   = 0;
  m_variables->nJets_OR_T_MV2c20_85 = 0;
  m_variables->nJets_OR_T_MV2c20_70 = 0;
  m_variables->nJets_OR_T_MV2c20_77 = 0;
  m_variables->nJets_OR_T_MV2c20_60 = 0;
  m_variables->nJets_OR_MV2c10_85   = 0;
  m_variables->nJets_OR_MV2c10_70   = 0;
  m_variables->nJets_OR_MV2c10_77   = 0;
  m_variables->nJets_OR_MV2c10_60   = 0;
  m_variables->nJets_OR_T_MV2c10_85 = 0;
  m_variables->nJets_OR_T_MV2c10_70 = 0;
  m_variables->nJets_OR_T_MV2c10_77 = 0;
  m_variables->nJets_OR_T_MV2c10_60 = 0;

  m_variables->lead_jetPt = 0;
  m_variables->sublead_jetPt = 0;
  m_variables->lead_jetEta = 0;
  m_variables->sublead_jetEta = 0;
  m_variables->lead_jetPhi = 0;
  m_variables->sublead_jetPhi = 0;
  m_variables->lead_jetE = 0;
  m_variables->sublead_jetE =0;

  typedef std::tuple<const TLorentzVector*, int> sortvec_t;
  std::vector<sortvec_t> sorter_jets;
  size_t idx = 0;
  for (const auto jetItr : *goodJets) {
    sorter_jets.push_back(std::make_tuple(&(jetItr->p4()), idx++));

    auto btagging = jetItr->btagging();
    if (btagging) {
      double mv2c;
      if( btagging->MVx_discriminant("MV2c20", mv2c) ) {
	if (mv2c > 0.0206) {
	  m_variables->nJets_OR_MV2c20_85++;
	  if (mv2c > 0.4803) {
	    m_variables->nJets_OR_MV2c20_77++;
	    if (mv2c > 0.7110) {
	      m_variables->nJets_OR_MV2c20_70++;
	      if (mv2c > 0.8867) {
		m_variables->nJets_OR_MV2c20_60++;
	      }
	    }
	  }
	}
      }
      if( btagging->MVx_discriminant("MV2c10", mv2c) ) {
	if (mv2c > 0.1758) {
	  m_variables->nJets_OR_MV2c10_85++;
	  if (mv2c > 0.6459) {
	    m_variables->nJets_OR_MV2c10_77++;
	    if (mv2c > 0.8244) {
	      m_variables->nJets_OR_MV2c10_70++;
	      if (mv2c > 0.9349) {
		m_variables->nJets_OR_MV2c10_60++;
	      }
	    }
	  }
	}
      }
    }
  }

  //same thing for jet with tau OR
  for (const auto jetItr : *goodJets) {
    if( jetItr->auxdataConst<char>("ttHpassTauOVR") ) {

      auto btagging = jetItr->btagging();
      if (btagging) {
	double mv2c;
	if( btagging->MVx_discriminant("MV2c20", mv2c) ) {
	  if (mv2c > 0.0206) {
	    m_variables->nJets_OR_T_MV2c20_85++;
	    if (mv2c > 0.4803) {
	      m_variables->nJets_OR_T_MV2c20_77++;
	      if (mv2c > 0.7110) {
		m_variables->nJets_OR_T_MV2c20_70++;
		if (mv2c > 0.8867) {
		  m_variables->nJets_OR_T_MV2c20_60++;
		}
	      }
	    }
	  }
	}
	if( btagging->MVx_discriminant("MV2c10", mv2c) ) {
	  if (mv2c > 0.1758) {
	    m_variables->nJets_OR_T_MV2c10_85++;
	    if (mv2c > 0.6459) {
	      m_variables->nJets_OR_T_MV2c10_77++;
	      if (mv2c > 0.8244) {
		m_variables->nJets_OR_T_MV2c10_70++;
		if (mv2c > 0.9349) {
		  m_variables->nJets_OR_T_MV2c10_60++;
		}
	      }
	    }
	  }
	}
      }
    }
  }

  std::sort(sorter_jets.begin(), sorter_jets.end(),
	      [](sortvec_t a, sortvec_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); });

  std::vector<const TLorentzVector*> p4s;
  const int totjets = goodJets->size();
  for (short idx1 = 0; idx1 < totjets; ++idx1) {
    const TLorentzVector* p4;
    int lidx;
    std::tie(p4, lidx) = sorter_jets[idx1];
    p4s.push_back(p4);
  }

  if (goodJets->size() > 0){
    m_variables->lead_jetPt  = p4s[0]->Pt();
    m_variables->lead_jetEta = p4s[0]->Eta();
    m_variables->lead_jetPhi = p4s[0]->Phi();
    m_variables->lead_jetE   = p4s[0]->E();
    }
  if (goodJets->size() > 1){
    m_variables->sublead_jetPt  = p4s[1]->Pt();
    m_variables->sublead_jetEta = p4s[1]->Eta();
    m_variables->sublead_jetPhi = p4s[1]->Phi();
    m_variables->sublead_jetE	= p4s[1]->E();
  }
}

void
ttHMultileptonLooseEventSaver::CopyTau(xAOD::TauJet& xTau, ttHMultilepton::Tau& MLTau) {
  MLTau.pt              = xTau.pt();
  MLTau.eta             = xTau.eta();
  MLTau.phi             = xTau.phi();
  MLTau.charge          = xTau.charge();
  MLTau.e               = xTau.e();
  MLTau.BDTJetScore     = xTau.discriminant(xAOD::TauJetParameters::TauID::BDTJetScore);
  MLTau.JetBDTSigLoose  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigLoose);
  MLTau.JetBDTSigMedium = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigMedium);
  MLTau.JetBDTSigTight  = xTau.isTau(xAOD::TauJetParameters::IsTauFlag::JetBDTSigTight);
  MLTau.numTrack        = xTau.nTracks();
  MLTau.isHadronic      = xTau.auxdata<int>("IsHadronic");
  MLTau.tagWeightBin    = xTau.auxdata<int>("tagWeightBin");
  MLTau.fromPV          = xTau.auxdata<char>("fromPV");
  MLTau.passEleOLR      = xTau.auxdata<int>("passEleOLR");
  MLTau.passEleBDT      = xTau.auxdata<int>("passEleBDT");
  MLTau.passMuonOLR     = xTau.auxdata<int>("passMuonOLR");

  for( auto syst : m_tau_sf_names ) {
    auto ivar = syst.first;
    if( !m_doSFSystematics && ivar != 0 ) continue;
    // AnalysisTop tight/loose and our tight/loose are reversed
    MLTau.SFTight[ivar] = m_isMC ? m_sfRetriever->tauSF(xTau, ivar, /*isLoose = */ true) : 1.0;
    MLTau.SFLoose[ivar] = m_isMC ? m_sfRetriever->tauSF(xTau, ivar, false)               : 1.0;
  }
}

void
ttHMultileptonLooseEventSaver::CopyTaus(std::shared_ptr<xAOD::TauJetContainer>& goodTaus) {
  memset(&m_taus, 0, sizeof(m_taus));
  int totalTaus = goodTaus->size();
  m_variables->nTaus_OR_Pt25 = totalTaus;

  goodTaus->sort(top::descendingPtSorter);

  for(int i = 0; i < totalTaus && i < TAU_ARR_SIZE; ++i) {
    CopyTau( *(goodTaus->at(i)) , m_taus[i] );
  }
}

void
ttHMultileptonLooseEventSaver::CopyHT(std::shared_ptr<xAOD::ElectronContainer>& goodEl, std::shared_ptr<xAOD::MuonContainer>& goodMu, std::shared_ptr<xAOD::JetContainer>& goodJets, std::shared_ptr<xAOD::TauJetContainer>& goodTaus) {
  m_variables->HT = 0;
  m_variables->HT_lep = 0;
  m_variables->HT_jets = 0;

  for (const auto jetItr : *goodJets) {
    m_variables->HT += jetItr->pt();
    m_variables->HT_jets += jetItr->pt();
  }
  for (const auto elItr : *goodEl) {
    m_variables->HT += elItr->pt();
    m_variables->HT_lep += elItr->pt();
  }
  for (const auto muItr : *goodMu) {
    m_variables->HT += muItr->pt();
    m_variables->HT_lep += muItr->pt();
  }
  for (const auto tauItr : *goodTaus) {
    m_variables->HT += tauItr->pt();
  }
}

void
ttHMultileptonLooseEventSaver::CheckIsBlinded() {
  bool isBlinded = false;
  if (m_variables->dilep_type) {
    if (abs(m_variables->total_charge) == 2
	&& m_variables->nJets_OR_T >= 4
	&& m_variables->nJets_OR_T_MV2c10_77 >= 1) {
      isBlinded = true;
    }
  } else if (m_variables->trilep_type) {
    // remember Mll01 = Mll[0][0] and Mll02 = Mll[0][1]
    if (abs(m_variables->total_charge) == 1
	&& ((m_variables->nJets_OR_T >=4
	     && m_variables->nJets_OR_T_MV2c10_77 >= 1)
	    || (m_variables->nJets_OR_T ==3
		&& m_variables->nJets_OR_T_MV2c10_77 >= 2))
	&& ! ((m_leptons[0].ID == - m_leptons[1].ID && fabs(m_variables->Mll[0][0] - 91.2e3) < 10e3)
	      || (m_leptons[0].ID == - m_leptons[2].ID && fabs(m_variables->Mll[0][1] - 91.2e3) < 10e3))
	) {
      isBlinded = true;
    }
  } else if (m_variables->quadlep_type) {
    if (m_variables->nJets_OR_T_MV2c10_77 >= 1
	&& m_variables->nJets_OR_T >= 2
	&& fabs(m_variables->best_Z_Mll - 91.2e3) > 10e3) {
      isBlinded = true;
    }
  }
  m_variables->isBlinded = isBlinded;
}


float ttHMultileptonLooseEventSaver::getattr_truthJet(const xAOD::Jet &jet, std::string  attr)
{
  float attr_value = -99;
  if (jet.isAvailable<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink") && jet.auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink").isValid())
  {
    const xAOD::Jet* trthjet = *jet.auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink");
    if(trthjet->pt() >10000) attr_value = trthjet->auxdataConst<float>(attr.c_str()); //10 GeV cut recommended for finding hard-scattering jet
  }
  return attr_value;
}

int ttHMultileptonLooseEventSaver::getNTruthJets(std::shared_ptr<xAOD::JetContainer> jetColl)
{
  int nTruth = 0;
  for(auto jet: *jetColl) 
  {
    if (jet->isAvailable<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink") && jet->auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink").isValid())
    {
      const xAOD::Jet* trthjet = *(jet->auxdata<ElementLink<xAOD::JetContainer> >("GhostTruthAssociationLink"));
      if(trthjet->pt() >10000) nTruth++;
    }
  }
  return nTruth;
}

