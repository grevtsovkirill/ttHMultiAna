#ifndef ttHMLAsgHelper_H_
#define ttHMLAsgHelper_H_

#include "AsgTools/AsgTool.h"
#include "xAODJet/JetContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODMuon/MuonContainer.h"
#include <string>


class ttHMLAsgHelper: public asg::AsgTool{

 public:

  ttHMLAsgHelper(std::string name);
  ~ttHMLAsgHelper();

  const xAOD::MuonContainer* RetrieveMuons(std::string retname) const;
  const xAOD::TauJetContainer* RetrieveTaus(std::string retname) const;

  const xAOD::JetContainer* RetrieveJets(std::string retname) const;
  void getJetContainer(std::string name);
  const xAOD::ElectronContainer* RetrieveElectrons(std::string retname) const;
  void getElectronContainer(std::string name);
  struct pt_sort
  {

    inline bool operator() (const TLorentzVector& lhs, const TLorentzVector& rhs)
    {
      return (lhs.Pt() > rhs.Pt());
    }

    inline bool operator() (const TLorentzVector* lhs, const TLorentzVector* rhs)
    {
      return (lhs->Pt() > rhs->Pt());
    }

    inline bool operator() (const xAOD::IParticle& lhs, const xAOD::IParticle& rhs)
    {
      return (lhs.pt() > rhs.pt());
    }

    inline bool operator() (const xAOD::IParticle* lhs, const xAOD::IParticle* rhs)
    {
      return (lhs->pt() > rhs->pt());
    }
  };


 private:


};

#endif
