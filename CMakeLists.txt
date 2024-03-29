# Auto-generated on: 2017-11-24 15:14:15.262411
cmake_minimum_required( VERSION 3.2 FATAL_ERROR )
# Declare the name of this package:
atlas_subdir( ttHMultilepton None )

# This package depends on other packages:
atlas_depends_on_subdirs( PUBLIC
                          TriggerAnalysisInterfaces
                          TrigGlobalEfficiencyCorrection
                          TopObjectSelectionTools
                          TopEventSelectionTools
                          TopEvent
                          TopConfiguration
                          TopAnalysis
                          JetJvtEfficiency
                          TopDataPreparation
                          xAODCaloEvent
                          xAODBase
                          xAODTruth 
                          xAOD/xAODCore
                          Event/xAOD/xAODEgamma
                          Event/xAOD/xAODEventInfo
                          Event/xAOD/xAODJet
                          Event/xAOD/xAODMissingET
                          Event/xAOD/xAODTrigMissingE
                          Event/xAOD/xAODMuon
                          Event/xAOD/xAODTau
                          Event/xAOD/xAODTracking
                          Event/xAOD/xAODTruth
                          IsolationSelection
                          AsgTools )

# This package uses ROOT:
find_package( ROOT REQUIRED COMPONENTS Core Gpad Tree Hist RIO MathCore Graf Physics )

# Generate a CINT dictionary source file:
atlas_add_root_dictionary( ttHMultilepton _cintDictSource
                           ROOT_HEADERS Root/LinkDef.h
                           EXTERNAL_PACKAGES ROOT )

# Build a library that other components can link against:
atlas_add_library( ttHMultilepton Root/*.cxx Root/*.h Root/*.icc
                   ttHMultilepton/*.h ttHMultilepton/*.icc ttHMultilepton/*/*.h
                   ttHMultilepton/*/*.icc ${_cintDictSource} 
                   PUBLIC_HEADERS ttHMultilepton
                   LINK_LIBRARIES TopObjectSelectionTools
                                  TopEventSelectionTools
                                  TrigGlobalEfficiencyCorrectionLib
                                  TopEvent
                                  TopConfiguration
                                  TopAnalysis
                                  TopDataPreparation
                                  JetJvtEfficiencyLib
                                  AsgTools
                                  xAODCaloEvent
                                  xAODBase
                                  xAODTruth
                                  xAODCore
			  xAODEgamma
		 	  xAODEventInfo
    		xAODJet
			  xAODMuon
			  xAODTau
			  xAODTracking
		  	xAODTruth
			  xAODPFlow
        FTagAnalysisInterfacesLib
                                  ${ROOT_LIBRARIES}
                   INCLUDE_DIRS ${ROOT_INCLUDE_DIRS} )

# Install data files from the package:
atlas_install_data( DIRECTORY share )
atlas_install_data(DIRECTORY data )

