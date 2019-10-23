/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "ttHMultilepton/DecorateElectrons.h"

#include "TLorentzVector.h"
#include <sstream>
#include <algorithm>
#include "xAODEgamma/ElectronContainer.h"
#include "TopEvent/EventTools.h"


//#include <AthContainers/ConstDataVector.h>
#include "AsgTools/AsgTool.h"
#include "AsgTools/ToolHandle.h"
#include "xAODEgamma/EgammaxAODHelpers.h" 
#include "ttHMultilepton/ttHMLAsgHelper.h"

static const float Pi = 3.14159;
static const float PTTOCURVATURE = -0.301; // ATLAS B=+2T (in MeV/mm) 
static const float SEPCUT      = 1;
static const float DCTCUT      = 0.02;
static const float SIMINHITS   = 7; // requiring min 7 Si hits
static const float MAXZ0DIFF = 0.5; // (in mm) 

DecorateElectrons::DecorateElectrons(std::string params,std::shared_ptr<top::TopConfig> config):
  m_event(0),
  iso_1( "iso_1" ),
  m_electronChargeIDLoose("ElectronChargeIDSelectorLoose"),
  m_electronChargeIDMedium("ElectronChargeIDSelectorMedium"),
  m_electronChargeIDTight("ElectronChargeIDSelectorTight"),
  m_config(config),
  m_isRemote(false)
{
    top::check( iso_1.initialize(),"IsolationTool fails to initialize");
    auto isolation_WPs = {"FCLoose","FCTight"};
    //    auto isolation_WPs = {"LooseTrackOnly","Loose", "Gradient", "GradientLoose","FixedCutTightTrackOnly","FixedCutLoose","FixedCutTight"};
    for (auto wp : isolation_WPs) {
      top::check( iso_1.addElectronWP(wp), "Error adding electron isolation WP" );
    }


  top::check( m_electronChargeIDLoose.setProperty("TrainingFile", "ElectronPhotonSelectorTools/ChargeID/ECIDS_20180731rel21Summer2018.root"), "ElectronChargeIDLoose: Failed to set training file." );
  top::check( m_electronChargeIDLoose.setProperty("OutputLevel", MSG::ERROR), "ElectronChargeIDLoose: Failed to set output level." );
  top::check( m_electronChargeIDLoose.initialize(), "ElectronChargeIDLoose: Failed to initialize." );
  top::check( m_electronChargeIDMedium.setProperty("TrainingFile", "ElectronPhotonSelectorTools/ChargeID/ECIDS_20180731rel21Summer2018.root"), "ElectronChargeIDMedium: Failed to set training file." );
  top::check( m_electronChargeIDMedium.setProperty("OutputLevel", MSG::ERROR), "ElectronChargeIDMedium: Failed to set output level." );
  top::check( m_electronChargeIDMedium.initialize(), "ElectronChargeIDMedium: Failed to initialize." );
  top::check( m_electronChargeIDTight.setProperty("TrainingFile", "ElectronPhotonSelectorTools/ChargeID/ECIDS_20180731rel21Summer2018.root"), "ElectronChargeIDTight: Failed to set training file." );
  top::check( m_electronChargeIDTight.setProperty("OutputLevel", MSG::ERROR), "ElectronChargeIDTight: Failed to set output level." );
  top::check( m_electronChargeIDTight.initialize(), "ElectronChargeIDTight: Failed to initialize." );

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
  nelec=0;
}

DecorateElectrons::~DecorateElectrons(){
  if(!m_isRemote)  delete m_asgHelper;
}

bool DecorateElectrons::apply(const top::Event & event) const{

  m_event = &event;

  if(!event.m_info->isAvailable<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables")){
   std::cout <<name() <<": ttHMLEventVariables (std::shared_ptr<ttHML::Variables>) object not found" << std::endl;
   std::cout << "-----> more info: <params: " << m_params 
	     << "> <systname: " << m_config->systematicName(event.m_hashValue) << ">" << std::endl;
   std::cout << "------> aborting :-( " << std::endl;
   abort();
 }

  float mll_conv;                                                                                                                                                                                                                                                                                                          
  float mll_conv_atConvV;
  float radius_conv, radius_convX, radius_convY;
  float closestSiTracknIL, closestSiTrackeIL, closestSiTracknNIL, closestSiTrackeNIL;
  float closestSiTrackPt, closestSiTrackEta, closestSiTrackPhi, closestSiTrackD0, closestSiTrackZ0, closestSiTrackQ;
  float bestmatchSiTrackPt, bestmatchSiTrackEta, bestmatchSiTrackPhi, bestmatchSiTrackD0, bestmatchSiTrackZ0, bestmatchSiTrackQ;
  float separationMinDCT;
  
  const xAOD::Vertex *pvtx = nullptr;
  const xAOD::VertexContainer *vtxC = 0;
  top::check( m_asgHelper->evtStore()->retrieve(vtxC,"PrimaryVertices"),"Failed to retrieve PrimaryVertices");
  for (auto vertex: *vtxC) {
    if (vertex->vertexType() == xAOD::VxType::VertexType::PriVtx) {
      pvtx     = vertex;
      break;
    }
   }
  
  std::shared_ptr<ttHML::Variables> tthevt = event.m_info->auxdecor<std::shared_ptr<ttHML::Variables> >("ttHMLEventVariables");
    for (auto elItr : event.m_electrons) {
      auto isomap = iso_1.accept(*elItr);
      int idx = 0;
        for (auto wp : {"Iso_FCLoose","Iso_FCTight"}) {
	  //        for (auto wp : {"Iso_LooseTrackOnly", "Iso_Loose", "Iso_Gradient", "Iso_GradientLoose","Iso_FixedCutTightTrackOnly","Iso_FixedCutLoose","Iso_FixedCutTight"}) {
          elItr->auxdecor<short>(wp) = isomap.getCutResult(idx++);
        }

      auto WPs = {"LHLoose","LHMedium","LHTight"};
        for( auto wp : WPs ) {
          std::string ttHML_LH_decoration("pass");                        ttHML_LH_decoration += wp;
          std::string derivation_LH_decoration("DFCommonElectrons"); derivation_LH_decoration += wp;
            if(m_config->isPrimaryxAOD()) {
	//there will be only one LH wp when using xAOD
	//it seems the type of the decoration was changed at some point
	          try {
	            elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<int> (m_config->electronIDDecoration());
	          }
	          catch(std::exception& e) {
	            elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<char>(m_config->electronIDDecoration());
	          }
            }
          else { // not primary xAOD
	        try {
	          elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<int> (derivation_LH_decoration);
	        }
	        catch(std::exception& e) {
	          elItr->auxdecor<int>( ttHML_LH_decoration ) = elItr->auxdataConst<char>(derivation_LH_decoration);
	        }
          }
      }

    
    elItr->auxdecor<float>("chargeIDBDTLoose") = (float)m_electronChargeIDLoose.calculate(elItr);
    elItr->auxdecor<float>("chargeIDBDTMedium") = (float)m_electronChargeIDMedium.calculate(elItr);
    elItr->auxdecor<float>("chargeIDBDTTight") = (float)m_electronChargeIDTight.calculate(elItr);

    // Tracks associated to the electron

    mll_conv=-999;
    mll_conv_atConvV=-999;
    radius_conv=-999;
    radius_convX=-999;
    radius_convY=-999;
    closestSiTracknIL = -999;
    closestSiTrackeIL = -999;
    closestSiTracknNIL = -999;
    closestSiTrackeNIL = -999;

    closestSiTrackPt = closestSiTrackEta = closestSiTrackPhi = closestSiTrackD0 = closestSiTrackZ0  = closestSiTrackQ = -999;
    bestmatchSiTrackPt = bestmatchSiTrackEta = bestmatchSiTrackPhi = bestmatchSiTrackD0 = bestmatchSiTrackZ0 = bestmatchSiTrackQ = -999;

    separationMinDCT = -999; // how good the distance between the circles is 

    int nTPSi = 0;
    int nTPSiNoIBL = 0;
    double detaMin(999);
    
    const xAOD::TrackParticleContainer *tpC(nullptr);
    top::check( m_asgHelper->evtStore()->retrieve(tpC,"InDetTrackParticles"),"Failed to retrieve InDetTrackParticles");
      
    if (tpC)
      { 
	const xAOD::TrackParticle *closestSiTrack(0);
	const xAOD::TrackParticle *bestmatchedGSFElTrack=elItr->trackParticle(0);
	const xAOD::TrackParticle *bestmatchedElTrack = xAOD::EgammaHelpers::getOriginalTrackParticleFromGSF(bestmatchedGSFElTrack);

	//std::cout << "Validation w Henri: electron pT" << elItr->pt() << std::endl;

	for (auto tracks1 : *tpC)  // loop on all tracks
	  {
	    double dR = bestmatchedElTrack->p4().DeltaR(tracks1->p4());
	    double dz0 = fabs(bestmatchedElTrack->z0() - tracks1->z0())*sin(bestmatchedElTrack->theta()); 
	    if (  (dR<0.3) && (dz0<MAXZ0DIFF) ) // loose DeltaR cut and tight delta(z0) cut  
	      {
		//std::cout << "Looping on all tracks" << std::endl;
		
		bool hasSi(false); 
		uint8_t nBL = 0, nIL = 0, nNIL = 0, nPix = 0, nSCT = 0; 
		uint8_t nPshared = 0, nSshared = 0; 
		uint8_t eBL = 1, eIL = 1, eNIL = 1; 
		tracks1->summaryValue(nPix,xAOD::numberOfPixelHits); 
		tracks1->summaryValue(nBL,xAOD::numberOfBLayerHits); 
		tracks1->summaryValue(nIL,xAOD::numberOfInnermostPixelLayerHits); 
		tracks1->summaryValue(nNIL,xAOD::numberOfNextToInnermostPixelLayerHits); 
		tracks1->summaryValue(nSCT,xAOD::numberOfSCTHits); 
		tracks1->summaryValue(eBL,xAOD::expectBLayerHit); 
		tracks1->summaryValue(eIL,xAOD::expectInnermostPixelLayerHit); 
		tracks1->summaryValue(eNIL,xAOD::expectNextToInnermostPixelLayerHit); 
		tracks1->summaryValue(nPshared,xAOD::numberOfPixelSharedHits); 
		tracks1->summaryValue(nSshared,xAOD::numberOfSCTSharedHits); 
		if((nPix+nSCT)>=SIMINHITS){ // requiring min 8 Si hits
		  hasSi=true;
		  nTPSi++;
		  if( (nIL==0 && eIL>0) || (eIL==0 && eNIL>0 && nNIL==0) ){
		    nTPSiNoIBL++; 
		    }
		}
		
		double deta=fabs(tracks1->eta()-bestmatchedElTrack->eta()); 
		if(deta<detaMin && hasSi && ((bestmatchedElTrack->charge() * tracks1->charge()) < 0) ){ // opposite-sign
		  detaMin=deta;
		  closestSiTrack = tracks1;
		  closestSiTracknIL = nIL;
		  closestSiTrackeIL = eIL;
		  closestSiTracknNIL = nNIL;
		  closestSiTrackeNIL = eNIL;
		}
	      }
	  }  // end loop on all tracks
	
	// std::cout << "Validation w Henri: nTPSi: " << nTPSi << std::endl;
	// std::cout << "Validation w Henri: nTPSiNoIBL: " << nTPSiNoIBL << std::endl;

	bestmatchSiTrackPt    = bestmatchedElTrack->pt(); 
	bestmatchSiTrackEta   = bestmatchedElTrack->eta(); 
	bestmatchSiTrackPhi   = bestmatchedElTrack->phi(); 
	bestmatchSiTrackD0    = bestmatchedElTrack->d0(); 
	bestmatchSiTrackZ0    = bestmatchedElTrack->z0(); 
	bestmatchSiTrackQ     = bestmatchedElTrack->charge(); 
	
	if (closestSiTrack){
	  // Keep pt, eta, phi, d0, z0
	  closestSiTrackPt    = closestSiTrack->pt();
	  closestSiTrackEta   = closestSiTrack->eta();
	  closestSiTrackPhi   = closestSiTrack->phi();
	  closestSiTrackD0    = closestSiTrack->d0();
	  closestSiTrackZ0    = closestSiTrack->z0();
	  closestSiTrackQ     = closestSiTrack->charge();
	
	  TLorentzVector p0,p1;  
	  p0.SetPtEtaPhiM(bestmatchedElTrack->pt(),bestmatchedElTrack->eta(),bestmatchedElTrack->phi(),0.511);   
	  p1.SetPtEtaPhiM(closestSiTrack->pt(),closestSiTrack->eta(),closestSiTrack->phi(),0.511);
	  
	  mll_conv=(p0+p1).M()*1e-3;
	  
	  p0.SetPtEtaPhiM(bestmatchedElTrack->pt(),bestmatchedElTrack->eta(),0,0.511);   
	  p1.SetPtEtaPhiM(closestSiTrack->pt(),closestSiTrack->eta(),0,0.511);
	  
	  mll_conv_atConvV=(p0+p1).M()*1e-3;
	  
	  
	  // Conversion methods
	  // Helix array:
	  // 0 cotan(theta)
	  // 1 curvature
	  // 2 z
	  // 3 d0
	  // 4 phi
	  
	  double helix1[5];
	  double helix2[5];
	  
	  ////////////// TrackToHelix Reco Electron Track
	  
	  helix1[0] = 1./tan(bestmatchedElTrack->theta());
	  helix1[1] = PTTOCURVATURE*bestmatchedElTrack->charge()/bestmatchedElTrack->pt();
	  
	  if(bestmatchedElTrack->phi0()>0.)
	    helix1[4] = bestmatchedElTrack->phi0();
	  else
	    helix1[4] = 2*Pi + bestmatchedElTrack->phi0();
	  
	  double c1 = cos(bestmatchedElTrack->phi0());
	  double s1 = sin(bestmatchedElTrack->phi0());
	  helix1[3] = bestmatchedElTrack->d0() + c1*pvtx->y() - s1*pvtx->x(); 
	  
	  c1 = c1*1./tan(bestmatchedElTrack->theta());
	  s1 = s1*1./tan(bestmatchedElTrack->theta());
	  helix1[2] = bestmatchedElTrack->z0() - c1*pvtx->x() - s1*pvtx->y() + pvtx->z();
	  
	  
	  ///////////// TrackToHelix Other Electron Track
	  
	  helix2[0] = 1./tan(closestSiTrack->theta());
	  helix2[1] = PTTOCURVATURE*closestSiTrack->charge()/closestSiTrack->pt();
	  
	  if(closestSiTrack->phi0()>0.)
	    helix2[4] = closestSiTrack->phi0();
	  else
	    helix2[4] = 2*Pi + closestSiTrack->phi0();
	
	  double c2 = cos(closestSiTrack->phi0());
	  double s2 = sin(closestSiTrack->phi0());
	  helix2[3] = closestSiTrack->d0() + c2*pvtx->y() - s2*pvtx->x(); 
		    
	  c2 = c2*1./tan(closestSiTrack->theta());
	  s2 = s2*1./tan(closestSiTrack->theta());
	  helix2[2] = closestSiTrack->z0() - c2*pvtx->x() - s2*pvtx->y() + pvtx->z();
	  
	  double dct(helix1[0]-helix2[0]); 
		    
	  //////
		    
	  double separation=999;
	  double convX=999;
	  double convY=999;
	
	  double x1, y1, r1, x2, y2, r2;
	  double cpx1, cpx2;
	
	  double beta(0.);
	  if(helix1[4] < helix2[4])
	    {
	      beta = Pi/2-helix1[4];
	    }
	  else
	    {
	      beta = Pi/2-helix2[4];
	    }
	
	  double phi1(helix1[4] + beta);
	  if(phi1>2*Pi) phi1=phi1-2*Pi;
	  if(phi1<0.) phi1=phi1+2*Pi;
	
	  double phi2(helix2[4] + beta);
	  if(phi2>2*Pi) phi2 = phi2 - 2*Pi;
	  if(phi2<0) phi2 = phi2 + 2*Pi;
	
	  /// HelixToCircle Main Track Electron
	  r1 = 1/(2.*fabs(helix1[1]));
	
	  double charge1(1.);
	  if(helix1[1]<0.) charge1 = -1.;
	  double rcenter1(helix1[3]/charge1 + r1);
	  double phicenter1(phi1 + Pi/2*charge1);
	
	  x1 = rcenter1*cos(phicenter1);
	  y1 = rcenter1*sin(phicenter1);
	
	  /// HelixToCircle Other Electron Conv Track
	  r2 = 1/(2.*fabs(helix2[1]));
	
	  double charge2(1.);
	  if(helix2[1]<0.) charge2 = -1.;
	  double rcenter2(helix2[3]/charge2 + r2);
	  double phicenter2(phi2 + Pi/2*charge2);
	
	  x2 = rcenter2*cos(phicenter2);
	  y2 = rcenter2*sin(phicenter2);
	  //////
	
	  double dx(x1- x2);
	  if(dx <  1e-9 && dx > 0.) dx =  1e-9;
	  if(dx > -1e-9 && dx < 0.) dx = -1e-9;
	  double slope((y1-y2)/dx);
	  double b(y1 - slope*x1);
	  double alpha(atan(slope));
	  double d(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
	  //only keeping opposite sign option
	  separation = d-r1-r2;
	  if(x1>x2)
	    {
	      cpx1 = x1-r1*cos(alpha);
	      cpx2 = x2+r2*cos(alpha); 
	    }
	  else
	    {
	      cpx1 = x1+r1*cos(alpha);
	      cpx2 = x2 - r2*cos(alpha);
	    }
	
	
	  double temp1 = (cpx1+cpx2)/2;
	  double temp2 = slope*temp1+b;
	  convX = cos(beta)*temp1 + sin(beta)*temp2;
	  convY = -sin(beta)*temp1+ cos(beta)*temp2;
	    
	    
	  ///////
	  if(fabs(separation)<SEPCUT && fabs(dct)<DCTCUT){
	    separationMinDCT=separation;
	    radius_convX=convX;
	    radius_convY=convY;
	    radius_conv=sqrt(convX*convX + convY*convY);
	    if( convX*cos(bestmatchedElTrack->phi()) + convY*sin(bestmatchedElTrack->phi()) < 0)radius_conv = -radius_conv; 

	  }
	}
	
      }
    
    
    // std::cout << "Validation w Henri: track0 pT eta: " << bestmatchSiTrackPt*bestmatchSiTrackQ << " " << bestmatchSiTrackEta << std::endl; 
    // std::cout << "Validation w Henri: Mass at PV: " << mll_conv << std::endl;
    // std::cout << "Validation w Henri: Mass at conv. vertex : " << mll_conv_atConvV << std::endl; 
    // std::cout << "Validation w Henri: Radius: " << radius_conv << std::endl;
    // std::cout << "Validation w Henri: separationMinDCT: " << separationMinDCT << std::endl;
    // std::cout << "Validation w Henri: closestSiTrackPt: " << closestSiTrackPt << std::endl;
    
    elItr->auxdecor<float>("mll_conv") = mll_conv;
    elItr->auxdecor<float>("mll_conv_atConvV") = mll_conv_atConvV;
    elItr->auxdecor<float>("radius_conv") = radius_conv;
    elItr->auxdecor<float>("radius_convX") = radius_convX;
    elItr->auxdecor<float>("radius_convY") = radius_convY;

    elItr->auxdecor<float>("closestSiTracknIL") = closestSiTracknIL;
    elItr->auxdecor<float>("closestSiTrackeIL") = closestSiTrackeIL;
    elItr->auxdecor<float>("closestSiTracknNIL") = closestSiTracknNIL;
    elItr->auxdecor<float>("closestSiTrackeNIL") = closestSiTrackeNIL;

    elItr->auxdecor<float>("closestSiTrackPt") = closestSiTrackPt;
    elItr->auxdecor<float>("closestSiTrackEta") = closestSiTrackEta;
    elItr->auxdecor<float>("closestSiTrackPhi") = closestSiTrackPhi;
    elItr->auxdecor<float>("closestSiTrackD0") = closestSiTrackD0;
    elItr->auxdecor<float>("closestSiTrackZ0") = closestSiTrackZ0;
    elItr->auxdecor<float>("closestSiTrackQ") = closestSiTrackQ;

    elItr->auxdecor<float>("bestmatchSiTrackPt") = bestmatchSiTrackPt;
    elItr->auxdecor<float>("bestmatchSiTrackEta") = bestmatchSiTrackEta;
    elItr->auxdecor<float>("bestmatchSiTrackPhi") = bestmatchSiTrackPhi;
    elItr->auxdecor<float>("bestmatchSiTrackD0") = bestmatchSiTrackD0;
    elItr->auxdecor<float>("bestmatchSiTrackZ0") = bestmatchSiTrackZ0;
    elItr->auxdecor<float>("bestmatchSiTrackQ") = bestmatchSiTrackQ;
    
    
    elItr->auxdecor<float>("separationMinDCT") = separationMinDCT;

  }




 /* m_vertices = event.m_primaryVertices;
  m_pvNumber = 0;
  m_puNumber = 0;

  for (const xAOD::Vertex* vtx : *m_vertices){
    if(vtx->vertexType() == xAOD::VxType::PriVtx) {
      m_pvNumber++;
      m_pv = vtx;
    }
    else if( vtx->vertexType() == xAOD::VxType::PileUp ) m_puNumber++;
  }*/

 // double vtx_z = m_pv->z();

 /* for (auto elItr : event.m_electrons) {
    if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
  nelec++;
  }*/
 /* for (auto elItr : event.m_electrons) {
    //delta z0
    float delta_z0 = elItr->trackParticle()->z0()
                   + elItr->trackParticle()->vz()
                   - vtx_z;
    elItr->auxdecor<float>("delta_z0") = delta_z0;
    elItr->auxdecor<float>("delta_z0_sintheta") = delta_z0*std::sin( elItr->trackParticle()->theta() );
        if (fabs(elItr->auxdataConst<float>("delta_z0_sintheta")) > 2) {
    continue;
    }
  nelec++;
  }*/
//std::cout<<"nelecbefore= " <<nelec<<std::endl;
  return true;

}

std::string DecorateElectrons::name() const{
  return "DECORATEEL";
}



