#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixHitChargeConverter.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearChargeDivider.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearChargeCollectionDrifter.h"
#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearInduceCharge.h"


RPixHitChargeConverter::RPixHitChargeConverter(const edm::ParameterSet &params, CLHEP::HepRandomEngine& eng, uint32_t det_id)
  : params_(params), det_id_(det_id)
{
  verbosity_ = params.getParameter<int>("RPixVerbosity");
  theRPixChargeDivider = new RPixLinearChargeDivider(params, eng, det_id);
  theRPixChargeCollectionDrifter = new RPixLinearChargeCollectionDrifter(params, det_id);
  theRPixInduceCharge = new RPixLinearInduceCharge(params, det_id);
}

RPixHitChargeConverter::~RPixHitChargeConverter()
{
  delete theRPixChargeDivider;
  delete theRPixChargeCollectionDrifter;
  delete theRPixInduceCharge;
}


std::map<unsigned short, double, std::less<unsigned short> > RPixHitChargeConverter::processHit(const PSimHit &hit)
{  
  std::vector<RPixEnergyDepositUnit> ions_along_path = theRPixChargeDivider->divide(hit);
  if(verbosity_)
    std::cout<<"HitChargeConverter "<<det_id_<<" clouds no generated on the path="<<ions_along_path.size()<<std::endl;
  return theRPixInduceCharge->Induce(theRPixChargeCollectionDrifter->Drift(ions_along_path));
}

