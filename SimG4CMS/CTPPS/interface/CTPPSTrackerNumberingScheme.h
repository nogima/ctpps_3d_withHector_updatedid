#ifndef _CTPPS_TrackerNumberingScheme_h
#define _CTPPS_TrackerNumberingScheme_h 1
// -*- C++ -*-
//
// Package:     CTPPS
// Class  :     CTPPSTrackerNumberingScheme
//
/**\class CTPPSTrackerNumberingScheme CTPPSTrackerNumberingScheme.h SimG4CMS/CTPPS/interface/CTPPSTrackerNumberingScheme.h
 
 Description: This class manages the UnitID that labels CTPPS sensitive
              volumes
 
 Usage:
    Used in CTPPSSD to get unique ID of sensitive detector element
 
*/
//
// Original Author: 
//         Created:  Tue May 16 10:14:34 CEST 2006
//
 
// system include files

// user include files

#include "SimG4CMS/CTPPS/interface/CTPPSTrackerOrganization.h"

class CTPPSTrackerNumberingScheme : public CTPPSTrackerOrganization {

public:

  // ---------- Constructor and destructor -----------------
  CTPPSTrackerNumberingScheme();
  ~CTPPSTrackerNumberingScheme();
	 
  //  virtual uint32_t GetUnitID(const G4Step* aStep) const ;

};

#endif


