// -*- C++ -*-
//
// Package:     CTPPS
// Class  :     CTPPSTrackerNumberingScheme
//
// Implementation:
//     <Notes on implementation>
//
// Original Author: 
//         Created:  Tue May 16 10:14:34 CEST 2006
//

// system include files

// user include files
#include "SimG4CMS/CTPPS/interface/CTPPSTrackerNumberingScheme.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

//
// constructors and destructor
//
CTPPSTrackerNumberingScheme::CTPPSTrackerNumberingScheme() {

  edm::LogInfo("CTPPSSim") << " Creating CTPPSTrackerNumberingScheme";
//  SetCurrentDetectorPosition();
}

CTPPSTrackerNumberingScheme::~CTPPSTrackerNumberingScheme() {
  edm::LogInfo("CTPPSSim") << " Deleting CTPPSTrackerNumberingScheme";
}


