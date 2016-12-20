/*
 *
* This is a part of CTPPS offline software.
* Author:
*   Fabrizio Ferro (ferro@ge.infn.it)
*
*/

#ifndef DataFormats_CTPPSReco_CTPPSPixelRecHit
#define DataFormats_CTPPSReco_CTPPSPixelRecHit


#include "DataFormats/GeometrySurface/interface/LocalError.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"

// Reconstructed hits in CTPPS Pixel detector

class CTPPSPixelRecHit{

public:

  CTPPSPixelRecHit(){}
CTPPSPixelRecHit(LocalPoint lp, LocalError le) : thePoint(lp), theError(le), isOnEdge_(false),hasBadPixels_(false), spanTwoRocs_(false){;}
CTPPSPixelRecHit(LocalPoint lp, LocalError le, bool edge, bool bad, bool rocs) : thePoint(lp), theError(le), isOnEdge_(edge),hasBadPixels_(bad), spanTwoRocs_(rocs){;}

  
  inline LocalPoint getPoint(){ return thePoint;}
  inline LocalError getError(){ return theError;}
  
  inline bool isOnEdge(){return isOnEdge_;}
  inline bool hasBadPixels(){return hasBadPixels_;}
  inline bool spanTwoRocs(){return spanTwoRocs_;}


private:

  LocalPoint thePoint;
  LocalError theError;

  bool isOnEdge_;
  bool hasBadPixels_;
  bool spanTwoRocs_;

};

inline bool operator< (CTPPSPixelRecHit& a, CTPPSPixelRecHit& b)
{

  return (a.getPoint().mag() < b.getPoint().mag());

};





#endif
