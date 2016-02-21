#include <vector>
#include <map>
#include <string>
#include "TLorentzVector.h"
#include "TopEvent/Event.h"
#include "xAODTruth/TruthParticle.h" 
#include "xAODTruth/TruthVertex.h" 
#include "AsgTools/AsgTool.h"

#ifndef ttHMultilepton_ClassifyHF_H_
#define ttHMultilepton_ClassifyHF_H_

class ttHMultileptonLooseEventSaver;

namespace ttHMultilepton {
class ClassifyHF: public asg::AsgTool{

 public:
  
  ClassifyHF(std::string jetcollName);
  ~ClassifyHF();
  
  int ClassifyEvent(const top::Event& event);
  

 private:


  //event
  const top::Event* m_event;
  
  
  std::string m_jetcollName;
  int m_ext_code;

  std::vector<int> m_jet_trueflav; //jet flavor coming from association to hadrons
  std::vector<int> m_jet_count; //number of matched hadrons
  std::vector<int> m_jet_id; // origin of hadron matched to the jet
  std::vector<float> m_jet_pt; //internal use
  std::vector<float> m_jet_eta; //internal use
  std::vector<float> m_jet_phi; //internal use
  std::vector<float> m_jet_m; //internal use
  ///MAPS JUST FOR HF DEDICATED STUDIES///
  std::map<int, int> m_FinalHadrons; //map hadron, origin
  std::map<int, int> m_HadronJets; //map hadron, jet
  std::map<std::string,float> m_VariablesForReweighting; // map for Variables needed for Reweighting

  /////////////////

  void initEvent();
  void flagJets();
  int countJets();
  int hadronType(int pdgid);
  //functions



};
}

#endif

//-------------------------------------//
