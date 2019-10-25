/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/DecorateMuons.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODMuon/MuonContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "ttHMultilepton/ttHMLAsgHelper.h"

DecorateMuons::DecorateMuons(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  iso_1( "iso_1" ),
  m_config(config),
  m_isRemote(false) 
{
    top::check( iso_1.initialize(),"IsolationTool fails to initialize");
//  auto isolation_WPs_mu={"FCTight", "FixedCutPflowLoose", "FCTightTrackOnly_FixedRad", "FCLoose_FixedRad","FixedCutPflowTight","FCLoose"};
  auto isolation_WPs={"FCTight", "FixedCutPflowLoose", "FCTightTrackOnly_FixedRad", "FCLoose_FixedRad","FixedCutPflowTight","FCLoose"};
    for (auto wp : isolation_WPs) {
      top::check( iso_1.addMuonWP(wp), "Error adding muon isolation WP" );
    }
 

   if ( asg::ToolStore::contains<ttHMLAsgHelper>("ttHMLAsgHelper") ) {
     m_asgHelper = asg::ToolStore::get<ttHMLAsgHelper>("ttHMLAsgHelper");
     m_isRemote=true;
   } 
   else {
     m_asgHelper = new ttHMLAsgHelper("ttHMLAsgHelper");
     top::check( m_asgHelper->initialize() , "Failed to initialize ttHMLAsgToolHelper" );
   }
  m_params=params;
  m_pv=nullptr;
  nmuon=0;
}

DecorateMuons::~DecorateMuons(){
  if(!m_isRemote)  delete m_asgHelper;  
}

bool DecorateMuons::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }
  m_vertices = event.m_primaryVertices;
  m_pvNumber = 0;
  m_puNumber = 0;

  for (const xAOD::Vertex* vtx : *m_vertices){
    if(vtx->vertexType() == xAOD::VxType::PriVtx) {
      m_pvNumber++;
      m_pv = vtx;
    }
    else if( vtx->vertexType() == xAOD::VxType::PileUp ) m_puNumber++;
  }

 // double vtx_z = m_pv->z();
  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
    for (auto muItr : event.m_muons) {
      auto isomap = iso_1.accept(*muItr);
      int idx = 0;
//FCTight, FCLoose, FCTightTrackOnly, FCTightTrackOnly_FixedRad, FCLoose_FixedRad, FCTight_FixedRad, FixedCutPflowTight, FixedCutPflowLoose, None
//  auto isolation_WPs={"FCTight", "Loose", "Gradient", "GradientLoose","TightTrackOnly","FCLoose"};
//FCTight, FCLoose, FCTightTrackOnly, FCTightTrackOnly_FixedRad, FCLoose_FixedRad, FCTight_FixedRad, FixedCutPflowTight, FixedCutPflowLoose, None
        for (auto wp : {"Iso_FCTight", "FixedCutPflowLoose", "Iso_FCTightTrackOnly_FixedRad", "Iso_FCLoose_FixedRad","Iso_FixedCutPflowTight","Iso_FCLoose"}) {
          muItr->auxdecor<short>(wp) = isomap.getCutResult(idx++);
        }

     //Default decorations
    muItr->auxdecor<float> ("jet_pt")           = -99;
    muItr->auxdecor<float> ("jet_eta")          = -99;
    muItr->auxdecor<float> ("jet_phi")          = -99;
    muItr->auxdecor<float> ("dRJet")            = -1.0; //name changed for promptLeptonIso calibration
    muItr->auxdecor<float> ("jet_numTrk")       = -99;
    muItr->auxdecor<float> ("jet_sumPtTrk")     = -99;
    muItr->auxdecor<float> ("MV2c10_weight")    = -99;
    muItr->auxdecor<float>("jet_ptRel")         = -99;
    muItr->auxdecor<float> ("jet_tagWeightBin") = -99;
    muItr->auxdecor<float>("muon_BDT")		= -99;
 
    xAOD::Jet* closestJet =0;
    float smallestDr = 1e5;
    for (const auto jetItr : event.m_jets) 
    {
        //if (!m_jetCleaningToolLooseBad->keep(*jetItr)) {
          //continue;
        //}
        if (jetItr->pt() < 25e3) {
          continue;
        }
        if (fabs(jetItr->eta()) > 2.5) {
          continue;
        }
        if( jetItr->auxdataConst<char>("passJVT")==0 ){
		   continue;
   		}
        /*if (jetItr->pt() < 60e3
          && fabs(jetItr->getAttribute<float>("DetectorEta")) < 2.4) {
          continue;
        }
        if (jetItr->isAvailable<float>("AnalysisTop_JVT")) {
          if(jetItr->auxdataConst<float>("AnalysisTop_JVT") < 0.59)
            continue;
        }*/
        float muJetDr = jetItr->p4().DeltaR(muItr->p4());
        if(smallestDr > muJetDr)
        {
           smallestDr = muJetDr;
           closestJet = (xAOD::Jet*)jetItr;
        }
    }


    if(closestJet)
    {
       muItr->auxdecor<float> ("jet_pt")  = closestJet->p4().Pt();
       muItr->auxdecor<float> ("jet_eta") = closestJet->p4().Eta();
       muItr->auxdecor<float> ("jet_phi") = closestJet->p4().Phi();
       muItr->auxdecor<float> ("dRJet")  = smallestDr;
       auto numTrkVec = closestJet->getAttribute<std::vector<int>   >(xAOD::JetAttribute::NumTrkPt500);
       auto numJetTrk =  (numTrkVec.size() ? numTrkVec[m_pv->index()] : 0);
       muItr->auxdecor<float> ("jet_numTrk")      = numJetTrk;
       auto sumPtTrkVec  = closestJet->getAttribute<std::vector<float> >(xAOD::JetAttribute::SumPtTrkPt500);
       auto jetSumPtTrk =  (sumPtTrkVec.size() ? sumPtTrkVec[m_pv->index()] : 0.);
       muItr->auxdecor<float> ("jet_sumPtTrk")    = jetSumPtTrk;

       auto btagging = closestJet->btagging();
       double rv(0);
       muItr->auxdecor<float> ("MV2c10_weight") = btagging && btagging->MVx_discriminant("MV2c10", rv) ? rv : 0. ;
       muItr->auxdecor<float>("jet_tagWeightBin") = ( closestJet->isAvailable<int>("tagWeightBin_MV2c10_Continuous")) ?closestJet->auxdataConst<int>("tagWeightBin_MV2c10_Continuous") : -5;

       float theta= muItr->p4().Vect().Angle(closestJet->p4().Vect());
       muItr->auxdecor<float>("jet_ptRel") = TMath::Sin(theta) * muItr->pt();

       //MuonIDBDT Score
       std::vector<std::string> inputVarNames = {
	        "jetMu_jetPt",
		"jetMu_jetNTrk",
		"jetMu_SumPtTrk", 
		"mv2c10_70", 
		"jetMu_deltaR", 
		"jetMu_ptRel", 
		"jetMu_jetPt/jetMu_muPt", 
		"jetMu_muonSigd0PV", 
		"jetMu_muonZ0SinTheta" };

       //ReadBDTG muonIdBDT(inputVarNames);

       std::vector<double> inputValues ={
	       muItr->auxdataConst<float>("jet_pt"),
	       muItr->auxdataConst<float>("jet_numTrk"),
	       muItr->auxdataConst<float>("jet_sumPtTrk"),
	       (muItr->auxdataConst<float>("MV2c10_weight")> 0.8244) ? 1.0 :0.0,
	       muItr->auxdataConst<float>("dRJet"), //jet_dr -> dRJet
	       smallestDr,muItr->auxdataConst<float>("jet_ptRel"),
	       muItr->auxdataConst<float>("jet_pt")/muItr->pt(),
	       muItr->auxdataConst<float>("d0sig"),
	       muItr->auxdataConst<float>("delta_z0_sintheta")};

       if (smallestDr <=0.4)
       {
           //muItr->auxdecor<float>("muon_BDT") = muonIdBDT.GetMvaValue(inputValues);
       }

    }
    

  }



//std::cout<<"nmuonbefore= " <<nmuon<<std::endl;
  return true;

}

std::string DecorateMuons::name() const{
  return "DECORATEMU";
}




