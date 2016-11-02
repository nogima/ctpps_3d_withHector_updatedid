#ifndef SimCTPPS_CTPPSTrackerDigiProducer_RPix_HIT_CHARGE_CONVERTER_H
#define SimCTPPS_CTPPSTrackerDigiProducer_RPix_HIT_CHARGE_CONVERTER_H

#include "SimDataFormats/TrackingHit/interface/PSimHit.h"
#include <map>
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearChargeCollectionDrifter.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearChargeDivider.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearInduceCharge.h"
//#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPSimTypes.h"

class RPixHitChargeConverter
{
  public:
    RPixHitChargeConverter(const edm::ParameterSet &params_, CLHEP::HepRandomEngine& eng, uint32_t det_id);
    ~RPixHitChargeConverter();
    
    std::map<unsigned short, double, std::less<unsigned short> > processHit(const PSimHit &hit);
  private:
    const edm::ParameterSet &params_;
    const uint32_t det_id_;
    
    RPixLinearChargeDivider* theRPixChargeDivider;
    RPixLinearChargeCollectionDrifter* theRPixChargeCollectionDrifter;
    RPixLinearInduceCharge* theRPixInduceCharge;
    int verbosity_;
};

#endif  //SimCTPPS_CTPPSTrackerDigiProducer_RPix_HIT_CHARGE_CONVERTER_H
