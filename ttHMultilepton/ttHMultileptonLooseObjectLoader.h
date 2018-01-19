/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#ifndef HOWTOEXTENDANALYSISTOP_ttHMultileptonLooseObjectLoader_H
#define HOWTOEXTENDANALYSISTOP_ttHMultileptonLooseObjectLoader_H

#include "TopAnalysis/ObjectLoaderBase.h"


  class ttHMultileptonLooseObjectLoader : public top::ObjectLoaderBase {
    public:

      /**
      * @brief Setup the cuts.  Probably easiest if you look at the code, no?
      *
      * @param topConfig The config that has been loaded.
      * @return A fully configured object that can be used to control which
      * objects (physics ones, not computer ones) are selected by the program.
      */
      top::TopObjectSelection* init(std::shared_ptr<top::TopConfig> topConfig);

      ClassDef(ttHMultileptonLooseObjectLoader, 0);
  };


#endif
