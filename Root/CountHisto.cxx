#include "ttHMultilepton/CountHisto.h"

#include "TopEvent/EventTools.h"

#include "TopCorrections/ScaleFactorRetriever.h"

#include <cmath>
#include <array>

#include "TH1.h"
#include "TFile.h"

// Systematic include(s):
#include "PATInterfaces/SystematicSet.h"

CountHisto::CountHisto(const std::string& name, TFile* outputFile, EL::Worker* wk) :
  m_hists(name, outputFile, wk), m_nominalHashValue(0) {

    CP::SystematicSet nominal; 
    m_nominalHashValue = nominal.hash();

    m_hists.addHist("Count", ";;Events", 3, 0., 3.);
    m_hists.hist("Count")->GetXaxis()->SetBinLabel(1,"totalEvents");
    m_hists.hist("Count")->GetXaxis()->SetBinLabel(2,"totalEventsWeighted");
    m_hists.hist("Count")->GetXaxis()->SetBinLabel(3,"totalEventsProcessed");
  }

bool CountHisto::apply(const top::Event& event) const {
  //only nominal

  if (event.m_hashValue != m_nominalHashValue || event.m_isLoose)
    return true;

  //only plot tight selection
  //before, we were plotting tight and loose together
  //if (event.m_isLoose)
  //return true;

  //std::cout << event << std::endl;

  double eventWeight = 1.;
  double pileUpWeight = 1.;
  /*if (top::isSimulation(event)) {
    eventWeight = event.m_info->mcEventWeight();
    //pileup weight needs pileup reweighting tool to have run
    if (top::ScaleFactorRetriever::hasPileupSF(event)) {
      pileUpWeight = top::ScaleFactorRetriever::pileupSF(event);
    }
  }*/

  m_hists.hist("Count")->Fill( 0. ,eventWeight);
  m_hists.hist("Count")->Fill( 1. ,eventWeight*pileUpWeight);
  m_hists.hist("Count")->Fill( 2. , 1);

  return true;
}

std::string CountHisto::name() const {
  return "COUNTHISTO";
}
