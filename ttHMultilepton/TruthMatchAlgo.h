#ifndef ttHMultilepton_TruthMatchAlgo_H_
#define ttHMultilepton_TruthMatchAlgo_H_

#include "TopEvent/Event.h"

#include "xAODBase/IParticle.h"
#include "xAODTruth/TruthParticle.h"

#include "AsgTools/AsgTool.h"
#include "MCTruthClassifier/MCTruthClassifier.h"
#include "MCTruthClassifier/MCTruthClassifierDefs.h"

class ttHMultileptonLooseEventSaver;

namespace ttHMultilepton {

  class TruthMatchAlgo: public asg::AsgTool {

 public:

  TruthMatchAlgo();
  ~TruthMatchAlgo();

  StatusCode executeTruthMatching( const top::Event& event );

 private:

  const top::Event* m_event;

  bool m_debug;

  SG::AuxElement::Decorator< char >*    m_isTruthMatchedDecor;    //! /* truth match is an electron/muon */
  SG::AuxElement::Decorator< int >*     m_truthTypeDecor;         //! /* type of the parent particle (according to MCTruthClassifier) - might be needed if this info is not stored in reco particle yet*/
  SG::AuxElement::Decorator< int >*     m_truthOriginDecor;       //! /* origin of the parent particle (according to MCTruthClassifier) - might be needed if this info is not stored in reco particle yet*/
  SG::AuxElement::Decorator< int >*     m_truthPdgIdDecor;        //! /* pdgId of the match particle */
  SG::AuxElement::Decorator< int >*     m_truthStatusDecor;       //! /* status of the match particle */
  SG::AuxElement::Decorator< float >*   m_truthPtDecor;           //! /* pt of the match particle */
  SG::AuxElement::Decorator< float >*   m_truthEtaDecor;          //! /* eta of the match particle */
  SG::AuxElement::Decorator< float >*   m_truthPhiDecor;          //! /* phi of the match particle */
  SG::AuxElement::Decorator< float >*   m_truthMDecor;            //! /* m of the match particle */
  SG::AuxElement::Decorator< float >*   m_truthEDecor;            //! /* E of the match particle */
  SG::AuxElement::Decorator< float >*   m_truthRapidityDecor;     //! /* rapidity of the match particle */
  SG::AuxElement::Decorator< char >*    m_isQMisIDDecor;          //! /* reco has opposite charge wrt to primitive truth ancestor */
  SG::AuxElement::Decorator< char >*    m_isBremsDecor;           //! /* reco is matched to a bremmstrahlung lepton (i.e, ancestor emitted a photon by brem) */
  SG::AuxElement::Decorator< int >*     m_ancestorTruthTypeDecor;    //! /* type of the primitive ancestor (according to MCTruthClassifier) - need it for brem leptons*/
  SG::AuxElement::Decorator< int >*     m_ancestorTruthPdgIdDecor;   //! /* pdgId of the primitive ancestor (according to MCTruthClassifier) - need it for brem leptons*/
  SG::AuxElement::Decorator< int >*     m_ancestorTruthOriginDecor;  //! /* origin of the primitive ancestor (according to MCTruthClassifier) - need it for brem leptons*/
  SG::AuxElement::Decorator< int >*     m_ancestorTruthStatusDecor;  //! /* status of the primitive ancestor (according to MCTruthClassifier) - need it for brem leptons*/

  SG::AuxElement::Accessor< char >*        m_isTruthMatchedAcc;   //!
  SG::AuxElement::Accessor< char >*        m_isQMisIDAcc;         //!
  SG::AuxElement::Accessor< char >*        m_isBremsAcc;          //!
  typedef ElementLink< xAOD::TruthParticleContainer > TruthLink_t;
  SG::AuxElement::Accessor< TruthLink_t >* m_truthPLAcc;          //!
  SG::AuxElement::ConstAccessor< int >*    m_truthTypeAcc;        //!
  SG::AuxElement::ConstAccessor< int >*    m_truthOriginAcc;      //!
  SG::AuxElement::Accessor< float >*       m_truthMatchProbabilityAcc;     //!
  SG::AuxElement::Accessor< int >*         m_ancestorTruthTypeAcc;         //!
  SG::AuxElement::Accessor< int >*         m_ancestorTruthOriginAcc;       //!

  MCTruthClassifier *m_MCTClassifier; //!

  StatusCode doTruthMatching ( const xAOD::IParticle* lep );
  StatusCode muonTruthPartMatching ( const xAOD::IParticle* lep );
  StatusCode muonTrackMatching ( const xAOD::IParticle* lep );

  StatusCode saveTruthMatchInfo ( const xAOD::IParticle* lep, const xAOD::TruthParticle* truthMatch, const xAOD::TrackParticle* trk = nullptr );
  StatusCode checkTruthQMisID ( const xAOD::IParticle* lep, const xAOD::TruthParticle* truthMatch );

  };

}

#endif
