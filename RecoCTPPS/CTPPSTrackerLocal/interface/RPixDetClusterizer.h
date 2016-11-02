/**********************************************************************
 *
 * Author: F.Ferro - INFN Genova
 * September 2016
 *
 **********************************************************************/
#ifndef RecoCTPPS_RPixCluster_DET_CLUSTERIZER_H
#define RecoCTPPS_RPixCluster_DET_CLUSTERIZER_H

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/DetSetVector.h"

#include "DataFormats/CTPPSDigi/interface/CTPPSTrackerDigi.h"
#include "DataFormats/CTPPSDigi/interface/CTPPSTrackerDigiCollection.h"
#include "DataFormats/CTPPSReco/interface/RPixCluster.h"

#include <vector>
#include <set>

class RPixDetClusterizer{

public:

  RPixDetClusterizer(edm::ParameterSet const& conf);

  void buildClusters(unsigned int detId, const std::vector<RPixDigi> &digi, std::vector<RPixCluster> &clusters);
  void make_cluster(RPixDigi aSeed,  std::vector<RPixCluster> &clusters );
  ~RPixDetClusterizer();


private:

  std::set<RPixDigi> rpix_digi_set_;
  const edm::ParameterSet &params_;
  int verbosity_;
  unsigned short SeedADCThreshold_;
  unsigned short ADCThreshold_;

  std::vector<RPixDigi> SeedVector_;

};



class tempCluster{

public:

  tempCluster()
{
  isize=0; 
  curr=0; 
  rowmin=16000; 
  colmin=16000;
}
  ~tempCluster(){}

    static constexpr unsigned short MAXSIZE = 256;
    unsigned short adc[256];
    unsigned short row[256];
    unsigned short col[256];
    unsigned short rowmin;
    unsigned short colmin;
    unsigned int isize;
    unsigned int curr;

    // stack interface (unsafe ok for use below)
    unsigned short top() const { return curr;}
    void pop() { ++curr;}   
    bool empty() { return curr==isize;}

    bool addPixel(unsigned short myrow, unsigned short mycol, unsigned short const iadc) {
      if (isize==MAXSIZE) return false;
      rowmin=std::min(rowmin,myrow);
      colmin=std::min(colmin,mycol);
      adc[isize]=iadc;
      row[isize]=myrow;
      col[isize++]=mycol;
      return true;
    }
    void printCluster(){
      std::cout << "Printing tempCluster " << std::endl;
      if(isize==0){std::cout << "Warning: empty tempCluster " << std::endl;}
      else{
	std::cout << "tempCluster size: " << isize << std::endl;
	std::cout << "row, col, adc " <<  std::endl;
	for(unsigned int i = 0; i < isize; i++){
	  std::cout << row[i]<<", " << col[i] << ", "<< adc[i] << std::endl;
	}
      }
    }

};


#endif
