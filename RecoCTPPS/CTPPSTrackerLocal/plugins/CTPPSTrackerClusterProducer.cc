
#include "RecoCTPPS/CTPPSTrackerLocal/interface/CTPPSTrackerClusterProducer.h"

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"


//needed for the geometry:
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/Common/interface/DetSetVector.h"

#include <vector>
#include <memory>
#include <string>
#include <iostream>
//#include <cstdlib> // I need it for random numbers

CTPPSTrackerClusterProducer::CTPPSTrackerClusterProducer(const edm::ParameterSet& conf) :
  param_(conf) ,
  clusterizer_(conf){
  
  src_ = conf.getUntrackedParameter<std::string>("label");
  verbosity_ = conf.getParameter<int> ("RPixVerbosity");
	 
  tokenRPixDigi_ = consumes<edm::DetSetVector<RPixDigi> >(edm::InputTag(src_));
 
  produces<edm::DetSetVector<RPixCluster> > ();
}

CTPPSTrackerClusterProducer::~CTPPSTrackerClusterProducer() {

}


// ------------ method called to produce the data  ------------
void CTPPSTrackerClusterProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
   
 
// Step A: get inputs

	edm::Handle<edm::DetSetVector<RPixDigi> > rpd;
	iEvent.getByToken(tokenRPixDigi_, rpd);


      //     theClusterVector.reserve(400);
      //    theClusterVector.clear();

	edm::DetSetVector<RPixCluster>  output;

// run clusterisation
	if (rpd->size())
	  run(*rpd, output);

/*
	int numberOfDetUnits = 0;
	int numberOfClusters = 0;
  
      // Iterate on detector units
	edm::DetSetVector<RPixDigi>::const_iterator DSViter = rpd->begin();
	for( ; DSViter != rpd->end(); DSViter++) {
	  ++numberOfDetUnits;
 
	  std::vector<short> badChannels; 
	  DetId detIdObject(DSViter->detId());
       


	    edmNew::DetSetVector<RPixCluster>::FastFiller spc(output, DSViter->detId());

	 
	    clusterizer_->clusterizeDetUnit(*DSViter, spc);  //CHECK HOW TO DEAL WITH DEADCHANNELS AND GEOMETRY

	} // end of DetUnit loop
     
*/
        // Step D: write output to file
       
	iEvent.put(std::make_unique<edm::DetSetVector<RPixCluster> >(output));

}

void CTPPSTrackerClusterProducer::run(const edm::DetSetVector<RPixDigi> &input, edm::DetSetVector<RPixCluster> &output){

  for (const auto &ds_digi : input)
    {
      edm::DetSet<RPixCluster> &ds_cluster = output.find_or_insert(ds_digi.id);
 
      clusterizer_.buildClusters(ds_digi.id, ds_digi.data, ds_cluster.data);
    }
}

DEFINE_FWK_MODULE( CTPPSTrackerClusterProducer);
