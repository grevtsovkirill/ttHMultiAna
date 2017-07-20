#include "ttHMultilepton/ClassifyHF.h"
#include "TVector3.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "TopEvent/EventTools.h" 



	
#define HADPTCUT 5000
#define JETPTCUT 15000
#define JETETACUT 2.5
#define DRCONE   0.4



//-----------------------------------------------//

ttHMultilepton::ClassifyHF::ClassifyHF(std::string jetcollName) :asg::AsgTool( "ClassifyHF" ),m_event(0),m_jetcollName(jetcollName),m_ext_code(-9999),m_jet_trueflav(0),m_jet_count(0),m_jet_id(0),m_jet_pt(0),m_jet_eta(0),m_jet_phi(0),m_jet_m(0)
{

}

ttHMultilepton::ClassifyHF::~ClassifyHF(){

}

//--------//


int ttHMultilepton::ClassifyHF::ClassifyEvent(const top::Event& event){

  m_event = &event;
  
  
  
  initEvent();
  
 
  if (event.m_truth != nullptr) {





    flagJets();
    m_ext_code=countJets();
    
    
       
    
  }else{std::cout<<"No truth info "<<std::endl;}

	

  return m_ext_code;



}




void ttHMultilepton::ClassifyHF::initEvent(){

  const xAOD::JetContainer* truthJets(nullptr);
  top::check( evtStore()->retrieve(truthJets, m_jetcollName),"Failed to retrieve truthJets"); 
  
  int jet_n=truthJets->size();
  
  ///initialization of data members///

  m_jet_trueflav.clear();
  m_jet_count.clear();
  m_jet_id.clear();
  m_jet_pt.clear();
  m_jet_eta.clear();
  m_jet_phi.clear();
  m_jet_m.clear();
  m_jet_trueflav.resize(jet_n,0);
  m_jet_count.resize(jet_n,0);
  m_jet_id.resize(jet_n,0);
  
  for(auto jptr : *truthJets){  
    m_jet_pt.push_back(jptr->pt());
    m_jet_eta.push_back(jptr->eta());
    m_jet_phi.push_back(jptr->phi());
    m_jet_m.push_back(jptr->m());
  }
  

}




void ttHMultilepton::ClassifyHF::flagJets(){

  ///matches hadrons with jets///

  m_FinalHadrons.clear();
  m_HadronJets.clear();


  int flav;
  
 
  
  for(const xAOD::TruthParticle*  part : *m_event->m_truth) {//loop truth
        
    int OriginFlag;
    try {
      OriginFlag = part->auxdata< int >("TopHadronOriginFlag");
    }
    catch(std::exception& e) {
      continue;
    }
    
    if(OriginFlag==6) continue; //only hadrons flagged with origin at derivation level
    m_FinalHadrons[part->index()]=OriginFlag;
    
    
    flav = hadronType(part->pdgId());
    
    TVector3 hadron, jet;
    hadron.SetPtEtaPhi(part->pt(),part->eta(),part->phi());
    float mindr=99;
    int bestjet=-1;
    //match closest jet in DR
    
   
    for(unsigned int jcount=0;jcount<m_jet_pt.size();jcount++){  
      
      jet.SetPtEtaPhi(m_jet_pt.at(jcount),m_jet_eta.at(jcount),m_jet_phi.at(jcount));
     
      if(jet.DeltaR(hadron) < DRCONE && jet.DeltaR(hadron) < mindr ){
	mindr = jet.DeltaR(hadron);
	bestjet = jcount;
      }
      
    }//loop over jets
    
    
    
    if(bestjet!=-1){
      
      m_HadronJets[part->index()]=bestjet;
      
      if((m_jet_id.at(bestjet)==0 || (OriginFlag>0 && OriginFlag>m_jet_id.at(bestjet)) || (OriginFlag<0 && m_jet_id.at(bestjet)<0 && OriginFlag<m_jet_id.at(bestjet)) ) ){
	
	m_jet_id.at(bestjet) = OriginFlag;

      }
      
      if(flav > m_jet_trueflav.at(bestjet) && part->pt()>= HADPTCUT){
	
	m_jet_trueflav.at(bestjet) = flav;
	m_jet_count.at(bestjet) = 1;
	
      }
      else if(flav == m_jet_trueflav.at(bestjet)){
	
	m_jet_count.at(bestjet) += 1;
      }
      
    }//jet chosen
  }//loop over hadrons

}




int ttHMultilepton::ClassifyHF::countJets(){

  ///count how many hadrons are in a jet///

  
  int b=0, B=0, c=0, C=0;
  int b_prompt=0, B_prompt=0, c_prompt=0, C_prompt=0;
  for(unsigned int i=0;i<m_jet_id.size();i++){
    if(m_jet_pt.at(i) < JETPTCUT || fabs(m_jet_eta.at(i)) > JETETACUT) continue;
    ///count just additional HF for btype <3 while for c-type <1 and >-3///
    if(m_jet_trueflav.at(i)==5 && m_jet_id.at(i) < 3){
      if(m_jet_count.at(i) > 1){
	B++;
      }
      else{
	b++;
      }
    }
    if(m_jet_trueflav.at(i)==4 && (m_jet_id.at(i)==0 || m_jet_id.at(i)==-1 || m_jet_id.at(i)==-2)){
      if(m_jet_count.at(i) > 1){
	C++;
      }
      else{
	c++;
      }
    }

    if(m_jet_trueflav.at(i)==5 && m_jet_id.at(i)==0){
      
      if(m_jet_count.at(i) > 1){
	B_prompt++;
      }
      else{
	b_prompt++;
      }
    }
    if(m_jet_trueflav.at(i)==4 && m_jet_id.at(i)==0){
      if(m_jet_count.at(i) > 1){
	C_prompt++;
      }
      else{
	c_prompt++;
      }
    }

   
  }



  int ext_code = 1000*b+100*B+10*c+1*C;

  int prompt_code=1000*b_prompt+100*B_prompt+10*c_prompt+1*C_prompt;

  ///MPI and FSR categories///

  if(prompt_code==0 && ext_code!=0){
    ext_code=0;
    for(uint ii=0; ii< m_jet_id.size(); ii++){
      if(m_jet_pt.at(ii) < JETPTCUT || fabs(m_jet_eta.at(ii)) > JETETACUT) continue;
      if(m_jet_id.at(ii)==1 && m_jet_trueflav.at(ii)==5){ //b MPI
	ext_code -= 1000;
      } else if(m_jet_id.at(ii)==2 && m_jet_trueflav.at(ii)==5){ //b FSR
	ext_code -= 100;
      } else if(m_jet_id.at(ii)==-1 && m_jet_trueflav.at(ii)==4){ //c MPI
	ext_code -= 10;
      } else if(m_jet_id.at(ii)==-2 && m_jet_trueflav.at(ii)==4) { //c FSR
	ext_code -= 1;
      }
    }
  }


  
  return ext_code;

}






int ttHMultilepton::ClassifyHF::hadronType(int pdgid){

  ///method to transform hadron pdg id to parton flavor///

  int rest1(abs(pdgid%1000));
  int rest2(abs(pdgid%10000));
  
  if ( rest2 >= 5000 && rest2 < 6000 ) return 5;
  if( rest1 >= 500 && rest1 < 600 ) return 5;
  
  if ( rest2 >= 4000 && rest2 < 5000 ) return 4;
  if( rest1 >= 400 && rest1 < 500 ) return 4;
  
  return 0;

}







