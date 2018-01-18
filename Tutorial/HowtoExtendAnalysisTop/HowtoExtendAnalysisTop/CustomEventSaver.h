/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef HOWTOEXTENDANALYSISTOP_CUSTOMEVENTSAVER_H
#define HOWTOEXTENDANALYSISTOP_CUSTOMEVENTSAVER_H

#include "TopAnalysis/EventSaverFlatNtuple.h"
#include "HowtoExtendAnalysisTop/Event.h"

/**
 * This class shows you how to extend the flat ntuple to include your own variables
 * 
 * It inherits from top::EventSaverFlatNtuple, which will be doing all the hard work 
 * 
 */
namespace top{
  class CustomEventSaver : public top::EventSaverFlatNtuple {
    public:
      ///-- Default constrcutor with no arguments - needed for ROOT --///
      CustomEventSaver();
      ///-- Destructor does nothing --///
      virtual ~CustomEventSaver(){}
      
      ///-- initialize function for top::EventSaverFlatNtuple --///
      ///-- We will be setting up out custom variables here --///
      virtual void initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches) override;
      
      ///-- Keep the asg::AsgTool happy --///
      virtual StatusCode initialize() override {return StatusCode::SUCCESS;}      
      
      ///-- saveEvent function for top::EventSaverFlatNtuple --///
      ///-- We will be setting our custom variables on a per-event basis --///
      virtual void saveEvent(const top::Event& event) override;
      
    private:
      ///-- Some additional custom variables for the output --///
      float m_randomNumber;
      float m_someOtherVariable;

	  ttHML::Event* m_ttHEvent;


      // for names of lepton trigger SFs for multi-trigger tool
      //std::map<CP::SystematicSet, std::string> m_lep_trigger_sf_names{ 
/*      std::vector< std::pair<CP::SystematicSet, std::string> >  m_lep_trigger_sf_names{
    	{ dummy_nom, "nominal" },
    	{ dummy_elup, "EL_SF_Trigger_UP" },
   		{ dummy_eldo, "EL_SF_Trigger_DOWN" },
	    { dummy_muup, "MU_SF_Trigger_STAT_UP" },
	    { dummy_mudo, "MU_SF_Trigger_STAT_DOWN" },
	    { dummy_eleffup, "EL_EFF_Trigger_UP" },
	    { dummy_eleffdo, "EL_EFF_Trigger_DOWN" }
	  }; */
  // for names of lepton SFs
  std::map<top::topSFSyst, std::string> m_lep_sf_names{
    { top::topSFSyst::nominal, "nominal" },
    { top::topSFSyst::EL_SF_Trigger_UP, "EL_SF_Trigger_UP" },
    { top::topSFSyst::EL_SF_Trigger_DOWN, "EL_SF_Trigger_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_STAT_UP, "MU_SF_Trigger_STAT_UP" },
    { top::topSFSyst::MU_SF_Trigger_STAT_DOWN, "MU_SF_Trigger_STAT_DOWN" }, // do not change the order up to this point to match m_lep_trigger_sf_names
    { top::topSFSyst::MU_SF_Trigger_SYST_UP, "MU_SF_Trigger_SYST_UP" },
    { top::topSFSyst::MU_SF_Trigger_SYST_DOWN, "MU_SF_Trigger_SYST_DOWN" },
    { top::topSFSyst::EL_SF_Reco_UP, "EL_SF_Reco_UP" },
    { top::topSFSyst::EL_SF_Reco_DOWN, "EL_SF_Reco_DOWN" },
    { top::topSFSyst::EL_SF_ID_UP, "EL_SF_ID_UP" },
    { top::topSFSyst::EL_SF_ID_DOWN, "EL_SF_ID_DOWN" },
    { top::topSFSyst::EL_SF_Isol_UP, "EL_SF_Isol_UP" },
    { top::topSFSyst::EL_SF_Isol_DOWN, "EL_SF_Isol_DOWN" },
    { top::topSFSyst::MU_SF_Trigger_UP, "MU_SF_Trigger_UP" },
    { top::topSFSyst::MU_SF_Trigger_DOWN, "MU_SF_Trigger_DOWN" },
    { top::topSFSyst::MU_SF_ID_STAT_UP, "MU_SF_ID_STAT_UP" },
    { top::topSFSyst::MU_SF_ID_STAT_DOWN, "MU_SF_ID_STAT_DOWN" },
    { top::topSFSyst::MU_SF_ID_SYST_UP, "MU_SF_ID_SYST_UP" },
    { top::topSFSyst::MU_SF_ID_SYST_DOWN, "MU_SF_ID_SYST_DOWN" },
    { top::topSFSyst::MU_SF_Isol_STAT_UP, "MU_SF_Isol_STAT_UP" },
    { top::topSFSyst::MU_SF_Isol_STAT_DOWN, "MU_SF_Isol_STAT_DOWN" },
    { top::topSFSyst::MU_SF_Isol_SYST_UP, "MU_SF_Isol_SYST_UP" },
    { top::topSFSyst::MU_SF_Isol_SYST_DOWN, "MU_SF_Isol_SYST_DOWN" },
    { top::topSFSyst::MU_SF_TTVA_STAT_UP, "MU_SF_TTVA_STAT_UP" },
    { top::topSFSyst::MU_SF_TTVA_STAT_DOWN, "MU_SF_TTVA_STAT_DOWN" },
    { top::topSFSyst::MU_SF_TTVA_SYST_UP, "MU_SF_TTVA_SYST_UP" },
    { top::topSFSyst::MU_SF_TTVA_SYST_DOWN, "MU_SF_TTVA_SYST_DOWN" },
    { top::topSFSyst::MU_SF_ID_STAT_LOWPT_UP, "MU_SF_ID_STAT_LOWPT_UP" },
    { top::topSFSyst::MU_SF_ID_STAT_LOWPT_DOWN, "MU_SF_ID_STAT_LOWPT_DOWN" },
    { top::topSFSyst::MU_SF_ID_SYST_LOWPT_UP, "MU_SF_ID_SYST_LOWPT_UP" },
    { top::topSFSyst::MU_SF_ID_SYST_LOWPT_DOWN, "MU_SF_ID_SYST_LOWPT_DOWN" },
  };
  // names tau SFs
    std::map<top::topSFSyst, std::string> m_tau_sf_names{
      { top::topSFSyst::nominal, "nominal" },
      { top::topSFSyst::TAU_SF_ELEOLR_TOTAL_UP,   "TAU_SF_ELEOLR_TOTAL_UP"  },
      { top::topSFSyst::TAU_SF_ELEOLR_TOTAL_DOWN, "TAU_SF_ELEOLR_TOTAL_DOWN"},
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP,   "TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_UP"  },
      { top::topSFSyst::TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN, "TAU_SF_TRUEELECTRON_ELEOLR_TOTAL_DOWN"},
      { top::topSFSyst::TAU_SF_JETID_TOTAL_UP,    "TAU_SF_JETID_TOTAL_UP"   },
      { top::topSFSyst::TAU_SF_JETID_TOTAL_DOWN,  "TAU_SF_JETID_TOTAL_DOWN" },
      { top::topSFSyst::TAU_SF_JETID_HIGHPT_UP,   "TAU_SF_JETID_HIGHPT_UP"  },
      { top::topSFSyst::TAU_SF_JETID_HIGHPT_DOWN, "TAU_SF_JETID_HIGHPT_DOWN"},
      { top::topSFSyst::TAU_SF_RECO_TOTAL_UP,     "TAU_SF_RECO_TOTAL_UP"    },
      { top::topSFSyst::TAU_SF_RECO_TOTAL_DOWN,   "TAU_SF_RECO_TOTAL_DOWN"  },
      { top::topSFSyst::TAU_SF_RECO_HIGHPT_UP,    "TAU_SF_RECO_HIGHPT_UP"   },
      { top::topSFSyst::TAU_SF_RECO_HIGHPT_DOWN,  "TAU_SF_RECO_HIGHPT_DOWN" },
        };


      
      ///-- Tell RootCore to build a dictionary (we need this) --///
      ClassDef(CustomEventSaver, 0);
  };
}

#endif

