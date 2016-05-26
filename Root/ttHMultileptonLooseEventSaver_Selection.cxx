#include "ttHMultilepton/ttHMultileptonLooseEventSaver.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODJet/JetContainer.h"
#include "xAODCore/AuxContainerBase.h"
#include "TopEvent/Event.h"
#include "TopEvent/EventTools.h"
#include "TopConfiguration/TopConfig.h"
#include "xAODTracking/TrackParticlexAODHelpers.h"
#include "TH1F.h"

std::shared_ptr<xAOD::ElectronContainer>
ttHMultileptonLooseEventSaver::SelectElectrons(const top::Event& event) {
  xAOD::ElectronContainer* goodElectrons = new xAOD::ElectronContainer();
  xAOD::AuxContainerBase* goodElectronsAux = new xAOD::AuxContainerBase();
  goodElectrons->setStore(goodElectronsAux);
  // have TStore manage aux
  top::check(evtStore()->tds()->record( goodElectronsAux, "ttHSelectedElectrons"+m_sysName+"Aux" ), 
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
    if (! elItr->auxdataConst<short>("Iso_Loose")) {
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
  top::check(evtStore()->tds()->record( goodMuonsAux, "ttHSelected"+m_sysName+"MuonsAux" ),
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
    if (! muItr->auxdataConst<short>("Iso_Loose")) {
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
  top::check(evtStore()->tds()->record( goodJetsAux, "ttHSelected"+m_sysName+"JetsAux" ),
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
  top::check(evtStore()->tds()->record( goodTausAux, "ttHSelected"+m_sysName+"TausAux" ),
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
    if ( !tauItr->auxdata<int>("passEleOLR")) {
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
  /*
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
  top::check(evtStore()->tds()->record( newGoodElAux, "ttHOR"+m_sysName+"ElectronsAux" ),
	     "Failed to register electrons after OR");
  top::check(evtStore()->tds()->record( newGoodMuAux, "ttHOR"+m_sysName+"MuonsAux" ),
	     "Failed to register muons after OR");
  top::check(evtStore()->tds()->record( newGoodJetAux, "ttHOR"+m_sysName+"JetsAux" ),
	     "Failed to register jets after OR");
  top::check(evtStore()->tds()->record( newGoodTauAux, "ttHOR"+m_sysName+"TausAux" ),
	     "Failed to register taus after OR");
  */
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

  for (const auto jetItr : *goodJet) {
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
  }
  // now done later
  //fillCutflow &&m_muCutflow->Fill(7, CountPassOR(*goodMu));

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
    for (const auto muItr : *goodMu) {
      if (! muItr->auxdataConst<char>("ttHpassOVR")) {
	continue;
      }
      if (p4.DeltaR(muItr->p4()) < 0.2) {
	tauItr->auxdecor<char>("ttHpassOVR") = 0;
	break;
      }
    }
    if (tauItr->auxdataConst<char>("ttHpassOVR")) {
      for (const auto jetItr : *goodJet) {
	// don't need additional protection here...
	if (p4.DeltaR(jetItr->p4()) < 0.3) {
	  jetItr->auxdecor<char>("ttHpassTauOVR") = 0;
	}
      }
    }
  }
  /*
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
  */
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
  top::check(evtStore()->tds()->record( newGoodElAux, "ttHOR"+m_sysName+"ElectronsAux" ),
	     "Failed to register electrons after OR");
  top::check(evtStore()->tds()->record( newGoodMuAux, "ttHOR"+m_sysName+"MuonsAux" ),
	     "Failed to register muons after OR");
  top::check(evtStore()->tds()->record( newGoodJetAux, "ttHOR"+m_sysName+"JetsAux" ),
	     "Failed to register jets after OR");
  top::check(evtStore()->tds()->record( newGoodTauAux, "ttHOR"+m_sysName+"TausAux" ),
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
    if (tauItr->auxdataConst<char>("ttHpassOVR")) {
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

  lep.truthOrigin = TruthOrigin;
  lep.truthType = TruthType;

  
  if (TruthType == 2 || TruthType == 6)
    lep.isPrompt = 1;
  else
    lep.isPrompt = 0;

  if (TruthOrigin == 5 && TruthType == 4){ // assuming most QFlip come from trident events
    lep.isBremsElec = 1;
    //std::cout << "Its Brems Elec and bkgMotherPdgId is " << bkgElMotherPdgID << " and type: " << bkgElType << " and origin: " << bkgElOrigin << std::endl;
  }
  else
    lep.isBremsElec = 0;

  if (!(TruthType == 2 || TruthType == 6) && !(TruthOrigin == 5 && TruthType == 4))
    lep.isFakeLep = 1;
  else
    lep.isFakeLep = 0;


  // trigger matching, electron pt > 25 GeV
  if (!m_isMC) {
    //if( el.pt() > 25e3 && (el.auxdataConst<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM20VH") || el.auxdataConst<char>("TRIGMATCH_HLT_e60_lhmedium") || el.auxdataConst<char>("TRIGMATCH_HLT_e120_lhloose")) ) //data
    if( el.pt() > 25e3 && ((el.isAvailable<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM20VH") ? el.auxdataConst<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM20VH"):0) || 
			   (el.isAvailable<char>("TRIGMATCH_HLT_e60_lhmedium") ? el.auxdataConst<char>("TRIGMATCH_HLT_e60_lhmedium"):0) || 
			   (el.isAvailable<char>("TRIGMATCH_HLT_e120_lhloose") ? el.auxdataConst<char>("TRIGMATCH_HLT_e120_lhloose"):0) ) ) //data
      lep.isTrigMatch = 1;
    else lep.isTrigMatch = 0;
  }
  else {
    if( el.pt() > 25e3 && ((el.isAvailable<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM20VH") ? el.auxdataConst<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM20VH"):0) || 
			   (el.isAvailable<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM18VH") ? el.auxdataConst<char>("TRIGMATCH_HLT_e24_lhmedium_L1EM18VH"):0) || 
			   (el.isAvailable<char>("TRIGMATCH_HLT_e60_lhmedium") ? el.auxdataConst<char>("TRIGMATCH_HLT_e60_lhmedium"):0) || 
			   (el.isAvailable<char>("TRIGMATCH_HLT_e120_lhloose") ? el.auxdataConst<char>("TRIGMATCH_HLT_e120_lhloose"):0) ) ) //MC
      lep.isTrigMatch = 1;
    else lep.isTrigMatch = 0;
  }

  // isolation variables
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone20); lep.ptVarcone20 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone30); lep.ptVarcone30 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::ptvarcone40); lep.ptVarcone40 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone20); lep.topoEtcone20 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone30); lep.topoEtcone30 = iso;}
  {float iso = 1e6; el.isolationValue(iso, xAOD::Iso::topoetcone40); lep.topoEtcone40 = iso;}
  
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

  // trigger matching, require lepton pt > 21 GeV
  if (mu.pt() > 25e3
      && ((mu.isAvailable<char>("TRIGMATCH_HLT_mu20_iloose_L1MU15") ? mu.auxdataConst<char>("TRIGMATCH_HLT_mu20_iloose_L1MU15"):0) || //2015
	  (mu.isAvailable<char>("TRIGMATCH_HLT_mu50") ? mu.auxdataConst<char>("TRIGMATCH_HLT_mu50"):0) || 
	  (mu.isAvailable<char>("TRIGMATCH_HLT_mu24_iloose") ? mu.auxdataConst<char>("TRIGMATCH_HLT_mu24_iloose"):0) ||  //2016
	  //(mu.isAvailable<char>("TRIGMATCH_HLT_mu24_ivarloose") ? mu.auxdataConst<char>("TRIGMATCH_HLT_mu24_ivarloose"):0) || 
	  (mu.isAvailable<char>("TRIGMATCH_HLT_mu40") ? mu.auxdataConst<char>("TRIGMATCH_HLT_mu40"):0) ))
      //&& (mu.auxdataConst<char>("TRIGMATCH_HLT_mu20_iloose_L1MU15") || mu.auxdataConst<char>("TRIGMATCH_HLT_mu50")))
    lep.isTrigMatch = 1;
  else
    lep.isTrigMatch = 0;

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

  lep.truthOrigin = TruthOrigin;
  lep.truthType = TruthType;

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

  if (TruthOrigin == 5 && TruthType == 4) // assuming most QFlip come from trident events
    lep.isBremsElec = 1;
  else
    lep.isBremsElec = 0;

  if (!(TruthType == 2 || TruthType == 6) && !(TruthOrigin == 5 && TruthType == 4))
    lep.isFakeLep = 1;
  else
    lep.isFakeLep = 0;

  // isolation variables
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone20); lep.ptVarcone20 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone30); lep.ptVarcone30 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::ptvarcone40); lep.ptVarcone40 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone20); lep.topoEtcone20 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone30); lep.topoEtcone30 = iso;}
  {float iso = 1e6; mu.isolation(iso, xAOD::Iso::topoetcone40); lep.topoEtcone40 = iso;}

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
	if (m_leptons[idx1].ID == -m_leptons[idx2].ID) {
	  if (m_variables->best_Z_Mll == 0 ||
	      (fabs(m_variables->Mll[idx1][idx2-1]-91.1876e3) <
	       fabs(m_variables->best_Z_Mll-91.1876e3))) {
	    m_variables->best_Z_Mll=m_variables->Mll[idx1][idx2-1];
	    zidx[0] = idx1; zidx[1] = idx2;
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
    }
  if (goodJets->size() > 1){
    m_variables->sublead_jetPt  = p4s[1]->Pt();
    m_variables->sublead_jetEta = p4s[1]->Eta();
    m_variables->sublead_jetPhi = p4s[1]->Phi();
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
