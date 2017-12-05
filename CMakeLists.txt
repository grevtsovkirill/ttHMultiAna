
cmake_minimum_required( VERSION 3.2 FATAL_ERROR )

atlas_subdir( ttHMultilepton )

atlas_depends_on_subdirs( PUBLIC
                          TopObjectSelectionTools
                          TopEventSelectionTools
			  Trigger
                          TopEvent
                          TopConfiguration
                          TopAnalysis
                          AsgTools
			  TriggerAnalysisInterfaces
			  TrigGlobalEfficiencyCorrection
			  MuonID
                          xAODCaloEvent
                          xAODBase
                          xAODTruth   
			  Event/xAOD/xAODCore
			  Event/xAOD/xAODEgamma
		 	  Event/xAOD/xAODEventInfo
    			  Event/xAOD/xAODJet
			  Event/xAOD/xAODMissingET
			  Event/xAOD/xAODTrigMissingE
			  Event/xAOD/xAODMuon
			  Event/xAOD/xAODTau
			  Event/xAOD/xAODTracking
		  	  Event/xAOD/xAODTruth
			  Event/xAOD/xAODPFlow
                          TopDataPreparation )

find_package( ROOT REQUIRED COMPONENTS Core Gpad Tree Hist RIO MathCore Graf Physics )

atlas_add_root_dictionary( ttHMultilepton _cintDictSource
                           ROOT_HEADERS Root/LinkDef.h
                           EXTERNAL_PACKAGES ROOT )

atlas_add_library( ttHMultilepton Root/*.cxx Root/*.h Root/*.icc
                   ttHMultilepton/*.h ttHMultilepton/*.icc ttHMultilepton/*/*.h
                   ttHMultileqton/*/*.icc ${_cintDictSource} 
                   PUBLIC_HEADERS ttHMultilepton
                   LINK_LIBRARIES TopObjectSelectionTools
                                  TopEventSelectionTools
				  TrigGlobalEfficiencyCorrectionLib
                                  TopEvent
                                  TopConfiguration
                                  TopAnalysis
                                  AsgTools
                                  xAODCaloEvent
                                  xAODBase
                                  xAODTruth
                                  TopDataPreparation
                                  ${ROOT_LIBRARIES}
                   INCLUDE_DIRS ${ROOT_INCLUDE_DIRS} )


atlas_install_data(DIRECTORY data/* )
