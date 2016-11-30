
#include "RecoCTPPS/CTPPSPixelLocal/interface/CTPPSPixelClusterProducer.h"

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


#include <vector>
#include <memory>
#include <string>
#include <iostream>
//#include <cstdlib> // I need it for random numbers

CTPPSPixelClusterProducer::CTPPSPixelClusterProducer(const edm::ParameterSet& conf) :
  param_(conf) ,
  clusterizer_(conf){
  
  src_ = conf.getUntrackedParameter<std::string>("label");
  verbosity_ = conf.getParameter<int> ("RPixVerbosity");
	 
  tokenRPixDigi_ = consumes<edm::DetSetVector<RPixDigi> >(edm::InputTag(src_));
 
  produces<edm::DetSetVector<RPixCluster> > ();
}

CTPPSPixelClusterProducer::~CTPPSPixelClusterProducer() {

}


// ------------ method called to produce the data  ------------
void CTPPSPixelClusterProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
   
 
// Step A: get inputs

	edm::Handle<edm::DetSetVector<RPixDigi> > rpd;
	iEvent.getByToken(tokenRPixDigi_, rpd);

 // get geometry
 //----------------------------------

	edm::ESHandle<TotemRPGeometry> geometry;
	iSetup.get<VeryForwardMeasuredGeometryRecord>().get(geometry);

	geometryWatcher.check(iSetup);


// dry checks to be removed
	unsigned int rpId = 2031091712;//  1997537280;
//	double z0 = geometry->GetRPDevice(rpId)->translation().z();
	CLHEP::Hep3Vector localV(-4.43825,2.05224,0.115);
	CLHEP::Hep3Vector globalV = geometry->LocalToGlobal(rpId,localV);

//	std::cout << " z0 = " << z0 <<std::endl;
	std::cout << "id: "<< rpId <<"   local " << localV <<"   to global "<<globalV<< std::endl;

//---------------------------------------------


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

void CTPPSPixelClusterProducer::run(const edm::DetSetVector<RPixDigi> &input, edm::DetSetVector<RPixCluster> &output){

  for (const auto &ds_digi : input)
    {
      edm::DetSet<RPixCluster> &ds_cluster = output.find_or_insert(ds_digi.id);
 
      clusterizer_.buildClusters(ds_digi.id, ds_digi.data, ds_cluster.data);

//-----------------------------------
      unsigned int cluN=0;
      for(std::vector<RPixCluster>::iterator iit = ds_cluster.data.begin(); iit != ds_cluster.data.end(); iit++){
	
	if(verbosity_)	std::cout << "Cluster " << ++cluN <<" avg row " << (*iit).avg_row()<< " avg col " << (*iit).avg_col()<<std::endl;





      }

//-----------------------------------
    }
}

DEFINE_FWK_MODULE( CTPPSPixelClusterProducer);
