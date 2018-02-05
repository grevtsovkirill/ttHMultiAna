/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef _EVENTDATA_H_
#define _EVENTDATA_H_



namespace ttHML{

  class EventData {
    /**
     * @brief EventData class for holding meta data.
     */

  public:
    EventData(){};
    virtual ~EventData(){};
    
    /// Metadata variables
    ULong64_t eventNumber;
    UInt_t mcChannelNumber;
    UInt_t runNumber;

    bool isData;

    /// Current systematic variation
    std::string currentSyst;  
  };
}

#endif
