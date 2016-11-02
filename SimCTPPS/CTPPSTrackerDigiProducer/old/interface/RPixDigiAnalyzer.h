#ifndef SimCTPPS_RPIXDigiAnalyzer_h
#define SimCTPPS_RPIXDigiAnalyzer_h


#include "FWCore/Framework/interface/ConsumesCollector.h"

#include <FWCore/Framework/interface/EDAnalyzer.h>
#include <DataFormats/CTPPSDetId/interface/CTPPSTrackerDetId.h>
#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"
#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigi.h"
#include "DataFormats/SiPixelDigi/interface/PixelDigiCollection.h"

#include "SimDataFormats/CrossingFrame/interface/CrossingFrame.h"
#include "SimDataFormats/CrossingFrame/interface/MixCollection.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Common/interface/DetSetVector.h"

#include "Geometry/CTPPSDetTopology/interface/RPixSimTopology.h"
#include "TH2D.h"

class TH1F;
class TFile;
class PSimHit;


namespace edm {
  class ParameterSet; class Event; class EventSetup;}

class RPixDigiAnalyzer : public edm::EDAnalyzer{
  
 public:
  explicit RPixDigiAnalyzer(const edm::ParameterSet& pset);
  virtual ~RPixDigiAnalyzer();
  void endJob();
  void beginJob();
  void analyze(const edm::Event & event, const edm::EventSetup& eventSetup);
  // hDigis* WheelHistos(int wheel);
  
 private:
//  typedef std::map<DTWireId, std::vector<const PSimHit*> > DTWireIdMap; 

 TH2D *hAllHits;
 TH2D *hOneHitperEvent;
 TH2D *hOneHitperEvent2;
 TH2D *hOneHitperEventCenter;
 TH2D *hOneHitperEvent2Center;
  TFile *file;
  std::string label;

  int verbosity_;
  edm::EDGetTokenT< edm::PSimHitContainer > psim_token;
//   edm::EDGetTokenT<CrossingFrame<PSimHit>> psim_token;
  edm::EDGetTokenT<edm::DetSetVector<PixelDigi> > pixel_token;
  

  RPixSimTopology theRPixDetTopology_;
  unsigned int found_corresponding_digi_count;
  unsigned int cumulative_cluster_size[3];
};

#endif    
