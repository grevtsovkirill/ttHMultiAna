#include "TopEvent/EventTools.h"
#include "ttHMultilepton/TruthMatchAlgo.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace ttHMultilepton;

TruthMatchAlgo :: TruthMatchAlgo() :
  asg::AsgTool( "TruthMatchAlgo" ),
  m_debug(true),
  m_MCTClassifier(nullptr)
{

  ATH_MSG_INFO("Initialising ttHMultilepton::TruthMatchAlgo() ...");

  m_isTruthMatchedDecor          = new SG::AuxElement::Decorator< char >("isTruthMatched");
  m_truthTypeDecor               = new SG::AuxElement::Decorator< int >("truthType");
  m_truthOriginDecor             = new SG::AuxElement::Decorator< int >("truthOrigin");
  m_truthPdgIdDecor              = new SG::AuxElement::Decorator< int >("truthPdgId");
  m_truthStatusDecor             = new SG::AuxElement::Decorator< int >("truthStatus");
  m_truthPtDecor                 = new SG::AuxElement::Decorator< float >("truthPt");
  m_truthEtaDecor                = new SG::AuxElement::Decorator< float >("truthEta");
  m_truthPhiDecor                = new SG::AuxElement::Decorator< float >("truthPhi");
  m_truthMDecor                  = new SG::AuxElement::Decorator< float >("truthM");
  m_truthEDecor                  = new SG::AuxElement::Decorator< float >("truthE");
  m_truthRapidityDecor           = new SG::AuxElement::Decorator< float >("truthRapidity");
  m_isQMisIDDecor                = new SG::AuxElement::Decorator< char >("isQMisID");
  m_isConvPhDecor                = new SG::AuxElement::Decorator< char >("isConvPh");
  m_isExtConvPhDecor             = new SG::AuxElement::Decorator< char >("isExtConvPh");
  m_isIntConvPhDecor             = new SG::AuxElement::Decorator< char >("isIntConvPh");
  m_isISR_FSR_PhDecor            = new SG::AuxElement::Decorator< char >("isISR_FSR_Ph");
  m_isBremsDecor                 = new SG::AuxElement::Decorator< char >("isBrems");
  m_ancestorTruthTypeDecor       = new SG::AuxElement::Decorator< int >("ancestorTruthType");
  m_ancestorTruthPdgIdDecor      = new SG::AuxElement::Decorator< int >("ancestorTruthPdgId");
  m_ancestorTruthOriginDecor     = new SG::AuxElement::Decorator< int >("ancestorTruthOrigin");
  m_ancestorTruthStatusDecor     = new SG::AuxElement::Decorator< int >("ancestorTruthStatus");

  m_isTruthMatchedAcc        = new SG::AuxElement::Accessor< char >("isTruthMatched");
  m_isQMisIDAcc              = new SG::AuxElement::Accessor< char >("isQMisID");
  m_isConvPhAcc              = new SG::AuxElement::Accessor< char >("isConvPh");
  m_isISR_FSR_PhAcc          = new SG::AuxElement::Accessor< char >("isISR_FSR_Ph");
  m_isBremsAcc               = new SG::AuxElement::Accessor< char >("isBrems");
  m_truthPLAcc               = new SG::AuxElement::Accessor< TruthLink_t >("truthParticleLink");
  m_truthTypeAcc             = new SG::AuxElement::ConstAccessor< int >("truthType");
  m_truthOriginAcc           = new SG::AuxElement::ConstAccessor< int >("truthOrigin");
  m_truthMatchProbabilityAcc = new SG::AuxElement::Accessor<float>("truthMatchProbability");
  m_ancestorTruthTypeAcc     = new SG::AuxElement::Accessor< int >("ancestorTruthType");
  m_ancestorTruthOriginAcc   = new SG::AuxElement::Accessor< int >("ancestorTruthOrigin");

  // Initialise MCTruthClassifier
  //
  m_MCTClassifier = new MCTruthClassifier("MCTruthClassifier");
  top::check( m_MCTClassifier->initialize(), "TruthMatchAlgo() :: Failed to properly initialize MCTruthClassifier." );

}

TruthMatchAlgo :: ~TruthMatchAlgo(){}

StatusCode TruthMatchAlgo :: executeTruthMatching( const top::Event& event ) {

  m_event = &event;

  if ( m_event->m_electrons.size() > 0 ) {
    for ( const auto el : m_event->m_electrons ) {
      top::check( this->doTruthMatching(el), "Failed truth matching for this electron. Aborting.");
    }
  }
  if ( m_event->m_muons.size() > 0 ) {
    for ( const auto mu : m_event->m_muons ) {
      top::check( this->doTruthMatching(mu), "Failed truth matching for this muon. Aborting.");
    }
  }

  return StatusCode::SUCCESS;

}

//-----------------------------------------------------------------------------//

StatusCode TruthMatchAlgo :: doTruthMatching( const xAOD::IParticle* lep ) {

  // Return immediately if input particle is not an electron/muon
  //
  if ( !( lep->type() == xAOD::Type::Electron || lep->type() == xAOD::Type::Muon ) ) {
    ATH_MSG_WARNING("doTruthMatching() :: Not passing an electron/muon! Won't try anything. Returning.");
    return StatusCode::SUCCESS;
  }

  // Truth particle types are defined in https://svnweb.cern.ch/trac/atlasoff/browser/PhysicsAnalysis/MCTruthClassifier/trunk/MCTruthClassifier/MCTruthClassifierDefs.h:
  //
  // Further explaination can be found in: https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/MCTruthClassifier
  //

  // Try to do the matching
  //
  if ( lep->type() == xAOD::Type::Electron ) {

    ATH_MSG_DEBUG( "doTruthMatching() :: finding truth match for reco ELECTRON - pT = " <<  lep->pt()/1e3 << " [GeV], eta = " << lep->eta() );

    // For electrons, the link to truth matching particle as well as useful info (type, origin...) is already a property of xAOD::Electron
    // We need only to get the pointer to the truth particle from the link

    if ( ! (*m_truthPLAcc).isAvailable( *lep ) ) {
      ATH_MSG_WARNING("doTruthMatching() :: No link available to truth match for this reco electron. This shouldn't happen. Returning");
      return StatusCode::SUCCESS;
    }
    if ( ! (*m_truthPLAcc)( *lep ).isValid() ) {
      ATH_MSG_VERBOSE("doTruthMatching() :: Link to truth match for this reco electron is invalid. This shouldn't happen. Returning");
      return StatusCode::SUCCESS;
    }
    const xAOD::TruthParticle* truthMatch = *( (*m_truthPLAcc)(*lep) );

    // If there's no matching truth electron, return and spit out a warning.
    //
    if ( !truthMatch ) {
      ATH_MSG_WARNING( "doTruthMatching() :: This reco electron is not matched to a generic truth particle. This shouldn't happen. Returning");
      return StatusCode::SUCCESS;
    }

    // Store info of truth matching particle
    //
    top::check( this->saveTruthMatchInfo( lep, truthMatch ) , "doTruthMatching() :: Problem with saveTruthMatchInfo(). Aborting.");

    // Check if electron is charge flip. Do it only if the truth match is an electron.
    //
    if ( truthMatch->isElectron() ) {
      top::check( this->checkTruthQMisID( lep, truthMatch ), "doTruthMatching() :: Problem with checkChargeFlip(). Aborting.");
    }

  } else if ( lep->type() == xAOD::Type::Muon ) {

    ATH_MSG_DEBUG( "doTruthMatching() :: finding truth match for reco MUON - pT = " <<  lep->pt()/1e3 << " [GeV], eta = " << lep->eta() );

    // For muons, only the truth matching particle is accessible from the xAOD::Muon object
    // (or, when available, from its xAOD::TrackParticle, which is recommended to use) track particle.
    // All the information such as type, origin ... must be accessed from the truth match itself, and subsequently
    // saved as a decoration for the reco muon.

    if ( fabs( lep->eta() ) < 2.5 ) {
      top::check(  this->muonTrackMatching( lep ), "doTruthMatching() :: Problem with muonTrackMatching() for this muon ( | eta | < 2.5 ). Aborting.");
    }
    /* else { // looks like HIGG8D1 slims out truth info for forward muons
      top::check( this->muonTruthPartMatching( lep ) , "doTruthMatching() :: Problem with muonTruthPartMatching() for this forward muon ( | eta| > 2.5 ). Aborting.");
    }*/

  }

  return StatusCode::SUCCESS;

}

//-----------------------------------------------------------------------------//

StatusCode TruthMatchAlgo :: muonTrackMatching( const xAOD::IParticle* lep )
{

  // Get the reco muon ID track particle
  //
  const xAOD::TrackParticle* trk(nullptr);
  ElementLink< xAOD::TrackParticleContainer > trkLink = dynamic_cast<const xAOD::Muon*>(lep)->inDetTrackParticleLink();

  if ( !trkLink.isValid() ) {
    ATH_MSG_WARNING("muonTrackMatching() :: Link to ID track particle for this reco muon is invalid. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }
  trk = *trkLink;

  // Get the truth particle matching the ID track
  //
  if ( ! (*m_truthPLAcc).isAvailable( *trk ) ) {
    ATH_MSG_WARNING("muonTrackMatching() :: No link available to truth match for this reco muon's ID track. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }
  if ( ! (*m_truthPLAcc)( *trk ).isValid() ) {
    ATH_MSG_VERBOSE("muonTrackMatching() :: Link to truth match for this reco muon's ID track is invalid. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }
  const xAOD::TruthParticle* truthMatch = *( (*m_truthPLAcc)(*trk) );

  // If there is no matching truth particle for the ID track, return and spit out a warning.
  //
  if ( !truthMatch ) {
    ATH_MSG_WARNING("muonTrackMatching() :: No truth match for this reco muon's ID track. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }

  // Store info of truth matching particle.
  //
  top::check( this->saveTruthMatchInfo( lep, truthMatch, trk ) , "muonTrackMatching() :: Problem with saveTruthMatchInfo(). Aborting.");

  // Check if muon is charge flip. Do it only if the truth match is a muon.
  //
  if ( truthMatch->isMuon() ) {
    top::check( this->checkTruthQMisID( lep, truthMatch ), "muonTrackMatching() :: Problem with checkChargeFlip(). Aborting.");
  }

  return StatusCode::SUCCESS;

}

//-----------------------------------------------------------------------------//

StatusCode TruthMatchAlgo :: muonTruthPartMatching ( const xAOD::IParticle* lep )
{

  // Get the truth particle matching the reco muon
  //
  const xAOD::TruthParticle* truthMatch(nullptr);

  if ( ! (*m_truthPLAcc).isAvailable( *lep ) ) {
    ATH_MSG_WARNING("muonTruthPartMatching() :: No link available to truth match for this reco muon. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }
  if ( ! (*m_truthPLAcc)( *lep ).isValid() ) {
    ATH_MSG_WARNING("muonTruthPartMatching() :: Link to truth match for this reco muon is invalid. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }
  truthMatch = *( (*m_truthPLAcc)(*lep) );

  // If there is no matching truth particle, return and spit out a warning.
  //
  if ( !truthMatch ) {
    ATH_MSG_WARNING("muonTruthPartMatching() :: No truth matching for this reco muon. This shouldn't happen. Returning");
    return StatusCode::SUCCESS;
  }

  // Store info of truth matching particle.
  //
  top::check( this->saveTruthMatchInfo( lep, truthMatch ) , "muonTruthPartMatching() :: Problem with saveTruthMatchInfo(). Aborting.");

  // Check if muon is charge flip. Do it only if the truth match is a muon.
  //
  if ( truthMatch->isMuon() ) {
    top::check( this->checkTruthQMisID( lep, truthMatch ), "muonTruthPartMatching() :: Problem with checkChargeFlip(). Aborting.");
  }

  return StatusCode::SUCCESS;

}

//-----------------------------------------------------------------------------//

StatusCode TruthMatchAlgo :: saveTruthMatchInfo( const xAOD::IParticle* lep, const xAOD::TruthParticle* truthMatch, const xAOD::TrackParticle* trk ) {

  ATH_MSG_DEBUG( "saveTruthMatchInfo() :: storing truth match info for reco lepton: \n" <<
		 "pT = " <<  lep->pt()/1e3 << " [GeV] \n" <<
		 "electron? --> " << ( lep->type() == xAOD::Type::Electron ) << "\n" <<
		 "muon? --> " << ( lep->type() == xAOD::Type::Muon ) << "\n" <<
		 "truth match pT = " << truthMatch->pt()/1e3 << " [GeV]" );

  // Decorate reconstructed particle with default values
  //
  (*m_isTruthMatchedDecor)( *lep )  = -1;
  // If type/origin not available yet for reco xAOD::IParticle, need to set the decorator
  if ( ! (*m_truthTypeAcc).isAvailable( *lep ) ) {
    (*m_truthTypeDecor)( *lep )       = 0;
    (*m_truthOriginDecor)( *lep )     = 0;
  }
  (*m_truthPdgIdDecor)( *lep )  = 0;
  (*m_truthStatusDecor)( *lep ) = -1;
  (*m_truthPtDecor)( *lep )     = -1.0;
  (*m_truthEtaDecor)( *lep )    = -999.0;
  (*m_truthPhiDecor)( *lep )    = -999.0;
  (*m_truthMDecor)( *lep )      = -1.0;
  (*m_truthEDecor)( *lep )      = -1.0;
  (*m_truthRapidityDecor)( *lep ) = -999.0;

  if ( !trk ) {

    if ( lep->type() == xAOD::Type::Electron ) {

      (*m_isTruthMatchedDecor)( *lep ) = ( truthMatch->isElectron() );

    } else if ( lep->type() == xAOD::Type::Muon ) {

      (*m_isTruthMatchedDecor)( *lep ) = ( truthMatch->isMuon() );

      // Store the type of the match: pass the truth muon type info to the reco muon
      //
      if ( ! (*m_truthTypeAcc).isAvailable( *lep ) ) {
        if ( ! (*m_truthTypeAcc).isAvailable( *truthMatch ) ) {
	  ATH_MSG_WARNING("saveTruthMatchInfo() :: No truth type info available for this muon's matching truth particle. This shouldn't happen. Returning");
	  return StatusCode::SUCCESS;
	}
	int truthMatchType = (*m_truthTypeAcc)(*truthMatch);
	(*m_truthTypeDecor)( *lep ) = truthMatchType;
      }
      // Store the origin of the match: pass the truth muon origin info to the reco muon
      //
      if ( ! (*m_truthOriginAcc).isAvailable( *lep ) ) {
        if ( ! (*m_truthOriginAcc).isAvailable( *truthMatch ) ) {
	  ATH_MSG_WARNING("saveTruthMatchInfo() :: No truth origin info available for this muon's matching truth particle. This shouldn't happen. Returning");
	  return StatusCode::SUCCESS;
	}
	int truthMatchOrigin = (*m_truthOriginAcc)(*truthMatch);
	(*m_truthOriginDecor)( *lep ) = truthMatchOrigin;
      }
    }

  } else if ( trk && lep->type() == xAOD::Type::Muon ) {

    // Retrieve track truth MC probability (should be always available for ID tracks!)
    //
    float trk_prob(-1.0);
    if ( m_truthMatchProbabilityAcc->isAvailable( *trk ) ) {
      trk_prob = (*m_truthMatchProbabilityAcc)( *trk );
    }

    // Decorate with true if the truth match is a muon (NB: since we are looking at the track, this might not always be the case!!),
    // and the track mc probability (when available) is high enough
    //
    (*m_isTruthMatchedDecor)( *lep ) = ( truthMatch->isMuon() && ( trk_prob < 0.0 || trk_prob > 0.8 ) );

    // Store the type of the match: pass the track type info to the reco muon
    //
    if ( ! (*m_truthTypeAcc).isAvailable( *lep ) ) {
      if ( ! (*m_truthTypeAcc).isAvailable( *trk ) ) {
	ATH_MSG_WARNING("saveTruthMatchInfo() :: No truth type info available for this muon's ID track matching truth particle. This shouldn't happen. Returning");
	return StatusCode::SUCCESS;
      }
      int truthTrkMatchType = (*m_truthTypeAcc)(*trk);
      (*m_truthTypeDecor)( *lep ) = truthTrkMatchType;
    }
    // Store the origin of the match: pass the track origin info to the reco muon
    //
    if ( ! (*m_truthOriginAcc).isAvailable( *lep ) ) {
      if ( ! (*m_truthOriginAcc).isAvailable( *trk ) ) {
        ATH_MSG_WARNING("saveTruthMatchInfo() :: No truth origin info available for this muon's ID track matching truth particle. This shouldn't happen. Returning");
	return StatusCode::SUCCESS;
      }
      int truthTrkMatchOrigin = (*m_truthOriginAcc)(*trk);
      (*m_truthOriginDecor)( *lep ) = truthTrkMatchOrigin;
    }
  }

  // Store the pdgId and status of the match
  //
  /*
  static SG::AuxElement::Accessor< int > pdgIdAcc("pdgId");
  if ( pdgIdAcc.isAvailable( *truthMatch ) ) {
    ATH_MSG_DEBUG( "saveTruthMatchInfo() :: decorating reco lepton w/ truth match PdgId: " << truthMatch->pdgId() );
    (*m_truthPdgIdDecor)( *lep ) = truthMatch->pdgId();
  }
  // Store the status of the match
  //
  static SG::AuxElement::Accessor< int > statusAcc("status");
  if ( statusAcc.isAvailable( *truthMatch ) ) {
    ATH_MSG_DEBUG( "saveTruthMatchInfo() :: decorating reco lepton w/ truth match Status: " << truthMatch->status() );
    (*m_truthStatusDecor)( *lep ) = truthMatch->status();
  }
  */
  (*m_truthPdgIdDecor)( *lep )  = truthMatch->pdgId();
  (*m_truthStatusDecor)( *lep ) = truthMatch->status();

  // Store the kinematics of the truth matching particle
  //
  (*m_truthPtDecor)( *lep )  = sqrt( truthMatch->px() * truthMatch->px() + truthMatch->py() * truthMatch->py() );
  (*m_truthEtaDecor)( *lep ) = truthMatch->eta();
  (*m_truthPhiDecor)( *lep ) = truthMatch->phi();
  (*m_truthMDecor)( *lep )   = truthMatch->m();
  (*m_truthEDecor)( *lep )   = truthMatch->e();
  (*m_truthRapidityDecor)( *lep ) = truthMatch->rapidity();

  return StatusCode::SUCCESS;

}

//-----------------------------------------------------------------------------//

StatusCode TruthMatchAlgo :: checkTruthQMisID ( const xAOD::IParticle* lep, const xAOD::TruthParticle* truthMatch ) {

  // default decorations
  //
  (*m_isQMisIDDecor)( *lep )             = -1;
  (*m_isISR_FSR_PhDecor)( *lep )         = -1;
  (*m_isConvPhDecor)( *lep )             = -1;
  (*m_isBremsDecor)( *lep )              = -1;
  (*m_ancestorTruthTypeDecor)( *lep )    = 0;
  (*m_ancestorTruthPdgIdDecor)( *lep )   = 0;
  (*m_ancestorTruthOriginDecor)( *lep )  = 0;
  (*m_ancestorTruthStatusDecor)( *lep )  = -1;

  int pdgId(-999);
  static SG::AuxElement::Accessor< int > pdgIdAcc("pdgId");

  if ( pdgIdAcc.isAvailable( *truthMatch ) ) { pdgId = truthMatch->pdgId(); }

  // A safety check: immediately return if input truth particle
  // is NOT an electron/muon
  //
  if ( !( truthMatch->isElectron() || truthMatch->isMuon() ) ) {
    ATH_MSG_WARNING("checkTruthQMisID() :: Input truth particle is NOT an electron/muon (pdgId: " << pdgId << "). Will not check whether it's charge flip. Returning.");
    return StatusCode::SUCCESS;
  }

  float reco_charge(0.0);
  if ( lep->type() == xAOD::Type::Electron ) {
     ATH_MSG_DEBUG("checkTruthQMisID() :: This reco lepton is an electron" );
    reco_charge = dynamic_cast<const xAOD::Electron*>(lep)->charge();
  } else if ( lep->type() == xAOD::Type::Muon ) {
     ATH_MSG_DEBUG("checkTruthQMisID() :: This reco lepton is a muon" );
    reco_charge = dynamic_cast<const xAOD::Muon*>(lep)->charge();
  }
  if ( !reco_charge ) {
    ATH_MSG_ERROR("checkTruthQMisID() :: Reco particle has zero charge. This shouldn't happen. Aborting");
    return StatusCode::FAILURE;
  }

  xAOD::TruthParticle* primitiveTruth(nullptr);

  if ( ! (*m_truthTypeAcc).isAvailable( *lep ) ) {
    ATH_MSG_ERROR("checkTruthQMisID() :: No accessor to truthType available for this reco lepton. This shouldn't happen. Aborting");
    return StatusCode::FAILURE;
  }

  // case 1:
  //
  // Lepton (in most cases, an electron) is matched to a truth lepton which is part of a bremmmstrahlung shower.
  // In this case, we need to go back until we find the original lepton that radiated the photon.
  // The charge of this primitive lepton is the one to look at!
  //
  // look at 'Background'-type el/mu (see MCTruthClassifier.h)
  //

  bool isBkgLep(false);

  int pdgId_primitive(-999);

  if ( (*m_truthTypeAcc)( *lep ) == 4 || (*m_truthTypeAcc)( *lep ) == 8 ) {

    isBkgLep = true;

    ATH_MSG_DEBUG("checkTruthQMisID() :: This reco lepton (charge: " << reco_charge << " ) is matched to a secondary truth lepton. Let's go back until we find the primitive");

    bool foundPrimitive(false);

    // Use this just to break the while loop in ill-fated cases
    //
    unsigned int iGeneration(0);

    // Check that the match has a parent
    //
    if ( !truthMatch->nParents() ) {
      ATH_MSG_WARNING("checkTruthQMisID() :: This reco lepton's match has no parents. Will not check whether it's charge flip. Returning");
      return StatusCode::SUCCESS;
    }

    primitiveTruth = const_cast<xAOD::TruthParticle*>( truthMatch->parent(0) );

    while ( !( foundPrimitive || iGeneration > 20 ) ) {

      if ( pdgIdAcc.isAvailable( *primitiveTruth ) ) { pdgId_primitive = primitiveTruth->pdgId(); }

      // Protection for truth particles w/o a prodVertex
      //
      if ( !primitiveTruth->hasProdVtx() ) {
      	  ATH_MSG_WARNING("checkTruthQMisID() :: \t Found a truth particle w/o production vertex. Will not check whether this reco lepton is charge flip. Returning");
      	  return StatusCode::SUCCESS;
      }

      // Check if prod vtx is compatible to a secondary interaction. If that's the case, go back in the chain!
      //
      if ( primitiveTruth->prodVtx()->barcode() < -200000 ) {

	ATH_MSG_DEBUG("checkTruthQMisID() :: \t Parent has pdgId: " << pdgId_primitive << ", prodVtx barcode: " << primitiveTruth->prodVtx()->barcode() << " - Need to go backwards in the decay chain");

	if ( !primitiveTruth->nParents() ) {
          ATH_MSG_WARNING("checkTruthQMisID() :: \t This truth ancestor has no parents. Will not check whether reco lepton it's charge flip. Returning");
	  return StatusCode::SUCCESS;
	}

	primitiveTruth = const_cast<xAOD::TruthParticle*>( primitiveTruth->parent(0) );

      } else {

	// Ok, we found the primitive!
	foundPrimitive = true;

	ATH_MSG_DEBUG("checkTruthQMisID() :: \t We found the primitive! pdgId: " << pdgId_primitive << ", prodVtx barcode: " << primitiveTruth->prodVtx()->barcode() );

      }

      ++iGeneration;
    }

  } else {
  // case 2:
  //
  // Lepton is matched to a truth lepton which is not produced in a secondary interaction.
  // Will check the charge directly on the truth match.
  //
    primitiveTruth = const_cast<xAOD::TruthParticle*>( truthMatch );
    if ( pdgIdAcc.isAvailable( *primitiveTruth ) ) { pdgId_primitive = primitiveTruth->pdgId(); }
  }

  // Use the MCTruthClassifier to get the type and origin of the primitive truth ancestor,
  // and save it as a decoration
  //
  std::pair<MCTruthPartClassifier::ParticleType,MCTruthPartClassifier::ParticleOrigin>  ancestor_info;
  ancestor_info = m_MCTClassifier->particleTruthClassifier( primitiveTruth );
  (*m_ancestorTruthTypeDecor)( *lep )   = ancestor_info.first;
  (*m_ancestorTruthPdgIdDecor)( *lep )  = primitiveTruth->pdgId();
  (*m_ancestorTruthOriginDecor)( *lep ) = ancestor_info.second;
  (*m_ancestorTruthStatusDecor)( *lep ) = primitiveTruth->status();

  // Now check the charge!
  //
  float truth_charge    = primitiveTruth->charge();
  int truth_norm_charge = ( truth_charge ) ? static_cast<int>( truth_charge / fabs(truth_charge) ) : 0;
  int reco_norm_charge  = ( reco_charge )  ? static_cast<int>( reco_charge  / fabs(reco_charge)  ) : 0;

  // Flag a lepton as 'isBrems' only if:
  //
  // -) the primitive ancestor is NOT a photon
  //   AND
  // -) it is a "background" (aka, secondary) lepton
  //
  // Flag a lepton as 'isQMisID' only if:
  //
  // -) the primitive ancestor is NOT a photon
  //   AND
  // -) the primitve ancestor origin is not ISR/FSR...
  //   AND
  // -) the charge has actually flipped in reco ;-)
  //
  // Flag a lepton as 'isISR_FSR' only if:
  //
  // -) the primitive ancestor is NOT a photon
  //   AND
  // -) the primitive ancestor origin is ISR/FSR
  //
  // Flag a lepton as 'isConvPh' only if:
  //
  // -) the primitive ancestor is a photon itself

  // NB in this scheme: primitive ancestor --> first non-GEANT-originated particle

  (*m_isBremsDecor)( *lep )      = 0;
  (*m_isQMisIDDecor)( *lep )     = 0;
  (*m_isISR_FSR_PhDecor)( *lep ) = 0;
  (*m_isConvPhDecor)( *lep )     = 0;
  (*m_isExtConvPhDecor)( *lep)   = 0;
  (*m_isIntConvPhDecor)( *lep)   = 0;

  if ( primitiveTruth->isLepton() && !primitiveTruth->isPhoton() ) {

    if ( isBkgLep && !(ancestor_info.second == 39 || ancestor_info.second == 40) ) { (*m_isBremsDecor)( *lep ) = 1; }
    if ( !(ancestor_info.second == 39 || ancestor_info.second == 40) && ( reco_norm_charge * truth_norm_charge ) < 0 ) { (*m_isQMisIDDecor)( *lep ) = 1; }
    if ( ancestor_info.second == 39 || ancestor_info.second == 40 ) { (*m_isISR_FSR_PhDecor)( *lep ) = 1; }

  } else if ( primitiveTruth->isPhoton() ) {
    (*m_isConvPhDecor)( *lep ) = 1;
    
    if (truthMatch->barcode()<200000){
      (*m_isIntConvPhDecor)( *lep ) = 1;
    }
    else{
      (*m_isExtConvPhDecor)( *lep ) = 1;
    }
  }

  ATH_MSG_DEBUG( "checkTruthQMisID() :: \n\nPrimitive TRUTH: \n" <<
		 "norm charge: " << truth_norm_charge << "\n" <<
		 "pdgId: " << pdgId_primitive << "\n" <<
		 "prodVtxBarcode: " << primitiveTruth->prodVtx()->barcode() << "\n" <<
		 "status: " << primitiveTruth->status() << "\n" <<
		 "type: " << ancestor_info.first << "\n" <<
		 "origin: " << ancestor_info.second << "\n" <<
		 "-----------\n" <<
		 "isBkgLep? " << isBkgLep << "\n" <<
		 "isBrems? " << (*m_isBremsAcc)( *lep ) << "\n" <<
		 "isConvPh? " << (*m_isConvPhAcc)( *lep ) << "\n" <<
		 "is from ISR/FSR? " << (*m_isISR_FSR_PhDecor)( *lep ) << "\n" <<
		 "-----------\nRECO: \n" <<
		 "norm charge: " << reco_norm_charge << " \n" <<
		 "-----------\n" <<
		 "isQMisID? " << (*m_isQMisIDAcc)( *lep ) << "\n\n");

  return StatusCode::SUCCESS;

}
