#ifndef TTHMULTILEPTONEVENTSAVER_H_
#define TTHMULTILEPTONEVENTSAVER_H_

#include "TopAnalysis/EventSaverFlatNtuple.h"

class ttHMultileptonEventSaver : public top::EventSaverFlatNtuple {
 public:
  //Default - so root can load based on a name
  ttHMultileptonEventSaver();
  
  //Default - so we can clean up
  ~ttHMultileptonEventSaver();
  
  //Run once at the start of the job
  void initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches);

  //Keep the asg::AsgTool happy
  virtual StatusCode initialize(){return StatusCode::SUCCESS;}
  
  //Run for every event (in every systematic) that needs saving
  void saveEvent(const top::Event& event);
  
 private:
  //Extra variable to write out
  float m_HT;
  float m_HThad;
  float m_cent;
  
  ClassDef(ttHMultileptonEventSaver, 0);
};

#endif
