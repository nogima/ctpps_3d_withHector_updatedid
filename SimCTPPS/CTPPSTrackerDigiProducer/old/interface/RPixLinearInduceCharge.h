#ifndef SimCTPPS_RPixDigiProducer_RPix_LINEAR_INDUCE_CHARGE_H
#define SimCTPPS_RPixDigiProducer_RPix_LINEAR_INDUCE_CHARGE_H

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <vector>
//#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixSimTypes.h"
#include "Geometry/CTPPSDetTopology/interface/RPixSimTopology.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixSignalPoint.h"

class RPixLinearInduceCharge
{
  public:
    RPixLinearInduceCharge(const edm::ParameterSet &params, uint32_t det_id);
//    SimRP::strip_charge_map 
std::map<unsigned short, double, std::less<unsigned short> > Induce(const std::vector<RPixSignalPoint> &charge_map);
  private:
    uint32_t det_id_;
    std::vector<double> signalCoupling_;
    std::map<unsigned short, double, std::less<unsigned short> > thePixelChargeMap;
    RPixSimTopology theRPixDetTopology_;
    double sqrt_2;
    int no_of_pixels_;
    int verbosity_;

    //double sigmas_no_;
    //double active_edge_smearing_;
    //double bottom_edge_smearing_;
    //double top_edge_smearing_;
};

#endif
