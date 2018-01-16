
#ifndef _EVENT_H_
#define _EVENT_H_


#include "AsgTools/AsgTool.h"
#include "xAODJet/JetContainer.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODMuon/MuonContainer.h"
#include "xAODTau/TauJetContainer.h"
#include "xAODEventInfo/EventInfo.h"
#include "xAODTracking/VertexContainer.h"
#include "xAODTruth/xAODTruthHelpers.h"


#include "TopEventSelectionTools/TreeManager.h"
#include "HowtoExtendAnalysisTop/EventData.h"
#include <vector>
#include <memory>


namespace ttHML {
  struct Event : public asg::AsgTool {
//    struct Event {
    public:

      Event();
      virtual ~Event();
    
   /* void GetJetContainer(std::string name);
    void GetElectronContainer(std::string name);
    void GetMuonContainer(std::string name); 
    void GetTauContainer(std::string name); */

    ConstDataVector<xAOD::JetContainer> * selected_jets   =  new ConstDataVector<xAOD::JetContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::ElectronContainer> * selected_electrons = new ConstDataVector<xAOD::ElectronContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::MuonContainer> * selected_muons = new ConstDataVector<xAOD::MuonContainer>(SG::VIEW_ELEMENTS);
    ConstDataVector<xAOD::TauJetContainer> * selected_taus = new ConstDataVector<xAOD::TauJetContainer>(SG::VIEW_ELEMENTS);
    int onelep_type;
    void BootstrapTree(std::shared_ptr<top::TreeManager> tree, bool doSFSystematics);
    std::shared_ptr<ttHML::EventData> m_info;


    private:

};

}

#endif

