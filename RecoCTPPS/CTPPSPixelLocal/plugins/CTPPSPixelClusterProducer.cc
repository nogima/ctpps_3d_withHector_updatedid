
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
	 
  tokenCTPPSPixelDigi_ = consumes<edm::DetSetVector<CTPPSPixelDigi> >(edm::InputTag(src_));
 
  produces<edm::DetSetVector<CTPPSPixelCluster> > ();
}

CTPPSPixelClusterProducer::~CTPPSPixelClusterProducer() {

}


// ------------ method called to produce the data  ------------
void CTPPSPixelClusterProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
   
 
// Step A: get inputs

	edm::Handle<edm::DetSetVector<CTPPSPixelDigi> > rpd;
	iEvent.getByToken(tokenCTPPSPixelDigi_, rpd);

 // get geometry
 //----------------------------------
/*
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
*/
//---------------------------------------------


      //     theClusterVector.reserve(400);
      //    theClusterVector.clear();

	edm::DetSetVector<CTPPSPixelCluster>  output;

// run clusterisation
	if (rpd->size())
	  run(*rpd, output);


        // Step D: write output to file
       
	iEvent.put(std::make_unique<edm::DetSetVector<CTPPSPixelCluster> >(output));

}

void CTPPSPixelClusterProducer::run(const edm::DetSetVector<CTPPSPixelDigi> &input, edm::DetSetVector<CTPPSPixelCluster> &output){

  for (const auto &ds_digi : input)
    {
      edm::DetSet<CTPPSPixelCluster> &ds_cluster = output.find_or_insert(ds_digi.id);
 
      clusterizer_.buildClusters(ds_digi.id, ds_digi.data, ds_cluster.data);

//-----------------------------------
      unsigned int cluN=0;
      for(std::vector<CTPPSPixelCluster>::iterator iit = ds_cluster.data.begin(); iit != ds_cluster.data.end(); iit++){
	
	if(verbosity_)	std::cout << "Cluster " << ++cluN <<" avg row " << (*iit).avg_row()<< " avg col " << (*iit).avg_col()<<std::endl;





      }

//-----------------------------------
    }
}

DEFINE_FWK_MODULE( CTPPSPixelClusterProducer);
