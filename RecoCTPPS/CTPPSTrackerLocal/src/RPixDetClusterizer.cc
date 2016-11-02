#include <iostream>


#include "RecoCTPPS/CTPPSTrackerLocal/interface/RPixDetClusterizer.h"
#include "Geometry/CTPPSDetTopology/interface/RPixTopology.h"


RPixDetClusterizer::RPixDetClusterizer(edm::ParameterSet const& conf):
  params_(conf), SeedVector_(0)
{
verbosity_ = conf.getParameter<int>("RPixVerbosity");
SeedADCThreshold_ = conf.getParameter<int>("SeedADCThreshold");
ADCThreshold_ = conf.getParameter<int>("ADCThreshold");
}

RPixDetClusterizer::~RPixDetClusterizer(){}

void RPixDetClusterizer::buildClusters(unsigned int detId, const std::vector<RPixDigi> &digi, std::vector<RPixCluster> &clusters)
{

 if(verbosity_) std::cout<<" RPixDetClusterizer "<<detId<<" received digi.size()="<<digi.size()<<std::endl;
if(verbosity_)  for(unsigned int i=0; i<digi.size();i++)std::cout<< digi[i].adc() << std::endl;


// creating a set of RPixDigi's and fill it

 rpix_digi_set_.clear();
 rpix_digi_set_.insert(digi.begin(),digi.end());

 if(verbosity_) std::cout<<" RPix set size = "<<rpix_digi_set_.size()<<std::endl;

// storing the seeds
 SeedVector_.clear();
 std::set<RPixDigi>::iterator RPDit;
 for(RPDit = rpix_digi_set_.begin(); RPDit!=rpix_digi_set_.end();++RPDit){
    //   if(verbosity_) std::cout<<"    " << (*RPDit).adc()<< std::endl;

   if((*RPDit).adc() > SeedADCThreshold_){
     
   // storing the seed if above threshold
     SeedVector_.push_back(*RPDit);

   } 
 }
 if(verbosity_) std::cout<<" SeedVector size = "<<SeedVector_.size()<<std::endl;



//----
// Looping on the seeds to make a cluster around the seed

 for(std::vector<RPixDigi>::iterator SeedIt = SeedVector_.begin(); SeedIt!=SeedVector_.end();++SeedIt){
   
// testing find method ... to be removed
   std::set<RPixDigi>::iterator RPDit3 = rpix_digi_set_.find( *SeedIt );
   if(verbosity_) std::cout<<"    " <<  (*RPDit3).adc()<< std::endl;

// make cluster around the seed

   make_cluster( *SeedIt, clusters);

// to be finished ........


 }

}

void RPixDetClusterizer::make_cluster(RPixDigi aSeed,  std::vector<RPixCluster> &clusters ){

// THIS DEPENDS ON SENSOR TOPOLOGY!!!

// CHECK ALSO FOR CALIBRATION

  int max_rows_in_sensor=160;
  int max_cols_in_sensor=156;


// creating a temporary cluster

  tempCluster atempCluster;

// filling the cluster with the seed
 atempCluster.addPixel(aSeed.row(),aSeed.column(),aSeed.adc());
rpix_digi_set_.erase( aSeed );


 while ( ! atempCluster.empty()) {
   //This is the standard algorithm to find and add a pixel
     auto curInd = atempCluster.top(); atempCluster.pop();
     for ( auto c = std::max(0,int(atempCluster.col[curInd])-1); c < std::min(int(atempCluster.col[curInd])+2,max_cols_in_sensor) ; ++c) {
	 for ( auto r = std::max(0,int(atempCluster.row[curInd])-1); r < std::min(int(atempCluster.row[curInd])+2,max_rows_in_sensor); ++r)  {

//
	   for(std::set<RPixDigi>::iterator RPDit4 = rpix_digi_set_.begin(); RPDit4 != rpix_digi_set_.end(); ){
	     if( (*RPDit4).column() == c && (*RPDit4).row() == r && (*RPDit4).adc() > ADCThreshold_ ){
	     
	       if(!atempCluster.addPixel( r,c,(*RPDit4).adc() )) {goto endClus;}
	       RPDit4 =  rpix_digi_set_.erase(RPDit4);

	     }else{
	       ++RPDit4;
	     }

	   }

	 }
       }
	     
 }  // while accretion


  endClus:
     //  SiPixelCluster cluster(atempCluster.isize,atempCluster.adc, atempCluster.x,atempCluster.y, atempCluster.xmin,atempCluster.ymin);


  if(verbosity_) atempCluster.printCluster();
  RPixCluster cluster(atempCluster.isize,atempCluster.adc, atempCluster.row,atempCluster.col, atempCluster.rowmin,atempCluster.colmin);
  clusters.push_back(cluster);

// SPLINTING LARGE CLUSTERS TO BE DONE

}
