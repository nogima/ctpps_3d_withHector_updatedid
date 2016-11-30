#ifndef CTPPS_TRACKERDIGI_CLASSES_H
#define CTPPS_TRACKERDIGI_CLASSES_H

#include "DataFormats/CTPPSDigi/interface/CTPPSPixelDigi.h"
#include "DataFormats/CTPPSDigi/interface/CTPPSPixelDigiCollection.h"
//#include "DataFormats/CTPPSPixelDigi/interface/SiPixelCalibDigi.h"
//#include "DataFormats/CTPPSPixelDigi/interface/SiPixelCalibDigiError.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSetVectorNew.h"
#include "boost/cstdint.hpp"
#include <vector>

namespace DataFormats_RPixDigi {
  struct dictionary {
/*
    SiPixelCalibDigi::datacontainer calibdatacontainer;
    SiPixelCalibDigi calibdigiitself;
    edm::Wrapper<SiPixelCalibDigi::datacontainer> calibdatacontainer0;
    edm::Wrapper<std::vector<SiPixelCalibDigi::datacontainer> > calibdatacontainervec0;
    edm::Wrapper<SiPixelCalibDigi> calibdigi;
    edm::Wrapper<std::vector<SiPixelCalibDigi> > calibdigivec;
    edm::Wrapper<edm::DetSet<SiPixelCalibDigi> > calibdigidetvec;
    edm::Wrapper<std::vector<edm::DetSet<SiPixelCalibDigi> > > calibdigidetset;
    edm::Wrapper<edm::DetSetVector<SiPixelCalibDigi> > calibdigidetsetvec;

    
    SiPixelCalibDigiError calibdigierr;
    edm::Wrapper<SiPixelCalibDigiError> calibdigierrw;
    edm::Wrapper<std::vector<SiPixelCalibDigiError> > calibdigierrvec;
    edm::Wrapper<edm::DetSet<SiPixelCalibDigiError> > calibdigierrdetvec;
    edm::Wrapper<std::vector<edm::DetSet<SiPixelCalibDigiError> > > calibdigierrdetset;
    edm::Wrapper<edm::DetSetVector<SiPixelCalibDigiError> > calibdigierrdetsetvec;
*/
    edm::Wrapper<RPixDigi> ff0;
    edm::Wrapper<RPixDigiCollection> ffc0;
    edm::Wrapper< std::vector<RPixDigi>  > ff1;
    edm::Wrapper< edm::DetSet<RPixDigi> > ff2;
    edm::Wrapper< std::vector<edm::DetSet<RPixDigi> > > ff3;
    edm::Wrapper< edm::DetSetVector<RPixDigi> > ff4;

    edm::Wrapper<edmNew::DetSetVector<RPixDigi> > ff4_bis;
    //   edm::Wrapper<edmNew::DetSetVector<SiPixelCalibDigi> > calibdigidetsetvec_bis;
//    edm::Wrapper<edmNew::DetSetVector<SiPixelCalibDigiError> > calibdigierrdetsetvec_bis;
    
  };
}

#endif
