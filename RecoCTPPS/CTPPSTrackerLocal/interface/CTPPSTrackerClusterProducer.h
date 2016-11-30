/**********************************************************************
 *
 * Author: F.Ferro - INFN Genova
 * September 2016
 *
 **********************************************************************/
#ifndef RecoCTPPS_CTPPSTrackerLocal_CTPPSTrackerClusterProducer
#define RecoCTPPS_CTPPSTrackerLocal_CTPPSTrackerClusterProducer

#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/Common/interface/DetSetVector.h"
#include "DataFormats/Common/interface/DetSet.h"
//#include "DataFormats/Common/interface/DetSetVectorNew.h"
//#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
 
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "DataFormats/CTPPSDigi/interface/CTPPSTrackerDigi.h"
#include "DataFormats/CTPPSReco/interface/RPixCluster.h"
#include "DataFormats/DetId/interface/DetId.h"

#include "RecoCTPPS/CTPPSTrackerLocal/interface/RPixDetClusterizer.h" 
#include "DataFormats/Common/interface/DetSetVector.h"

#include "DataFormats/CTPPSDetId/interface/CTPPSTrackerDetId.h"

#include "FWCore/Framework/interface/ESWatcher.h"
#include "Geometry/VeryForwardGeometryBuilder/interface/TotemRPGeometry.h"
#include "Geometry/VeryForwardRPTopology/interface/RPTopology.h"
#include "Geometry/Records/interface/VeryForwardRealGeometryRecord.h"


#include <vector>
#include <set>




class CTPPSTrackerClusterProducer : public edm::stream::EDProducer<>
{
public:
  explicit CTPPSTrackerClusterProducer(const edm::ParameterSet& param);
 
  ~CTPPSTrackerClusterProducer();

 virtual void produce(edm::Event&, const edm::EventSetup&) override;

private:
 edm::ParameterSet param_;
 int verbosity_;
 
 edm::InputTag src_;
 edm::EDGetTokenT<edm::DetSetVector<RPixDigi>> tokenRPixDigi_;
  
 edm::ESWatcher<VeryForwardRealGeometryRecord> geometryWatcher;

 RPixDetClusterizer clusterizer_;
  
 void run(const edm::DetSetVector<RPixDigi> &input, edm::DetSetVector<RPixCluster> &output);
 
};



#endif
