#include "SimCTPPS/CTPPSTrackerDigiProducer/interface/RPixLinearInduceCharge.h"
#include <iostream>

RPixLinearInduceCharge::RPixLinearInduceCharge(const edm::ParameterSet &params, uint32_t det_id)
 : det_id_(det_id), theRPixDetTopology_(params), sqrt_2(sqrt(2.0))
{
  verbosity_ = params.getParameter<int>("RPixVerbosity");
  signalCoupling_.clear();

// di default =1
  double coupling_constant_ = params.getParameter<double>("RPixCoupling");
  signalCoupling_.push_back(coupling_constant_);
  signalCoupling_.push_back( (1.0-coupling_constant_)/2 );
  
  no_of_pixels_ = theRPixDetTopology_.DetPixelNo();
}

std::map<unsigned short, double, std::less<unsigned short> >  RPixLinearInduceCharge::Induce(
    const std::vector<RPixSignalPoint> &charge_map)
{
  thePixelChargeMap.clear();
  if(verbosity_)
    std::cout<<"RPixLinearInduceCharge "<<det_id_<<" : Clouds to be induced= "<<charge_map.size()<<std::endl;
  for(std::vector<RPixSignalPoint>::const_iterator i=charge_map.begin(); 
      i!=charge_map.end(); ++i)
  {
    double hit_pos_x,hit_pos_y;
    std::vector<pixel_info> relevant_pixels = theRPixDetTopology_.GetPixelsInvolved(
										    (*i).X(), (*i).Y(), (*i).Sigma(), hit_pos_x, hit_pos_y);
    if(verbosity_)
    {
      std::cout<<"RPixLinearInduceCharge "<<det_id_<<" : relevant_pixels = "
        <<relevant_pixels.size()<<std::endl;
    }
    for(std::vector<pixel_info>::const_iterator j = relevant_pixels.begin(); 
        j!=relevant_pixels.end(); ++j)
    {
/* UNUSED VARIABLES
      double pixel_begin_x = (*j).LowerSimXBorder();
      double pixel_end_x = (*j).HigherSimXBorder();
      double pixel_begin_y = (*j).LowerSimYBorder();
      double pixel_end_y = (*j).HigherSimYBorder();
      double sigma = (*i).Sigma();
*/
      double effic = (*j).EffFactor();
 
      unsigned short pixel_no = (*j).PixelIndex();
      
//      double charge_on_strip = (TMath::Erfc( (strip_begin-hit_pos)/sqrt_2/sigma )/2.0 -   TMath::Erfc( (strip_end-hit_pos)/sqrt_2/sigma )/2.0)* (*i).Charge()*effic;
      double charge_in_pixel =  (*i).Charge()*effic;

      if(verbosity_)
        std::cout<<"Efficiency in detector "<<det_id_<< " and pixel no " << pixel_no << "  : " <<effic<<std::endl;

//        QUI SI POTREBBE INTRODURRE IL CHARGE SHARING TRA I PIXELS ..................................       
/*      for(int k=-signalCoupling_.size()+1; k<(int)signalCoupling_.size(); ++k)
      {
        if( (str_no+k)>=0 && (str_no+k)<no_of_strips_)
          theStripChargeMap[str_no + k] += charge_on_strip*signalCoupling_[abs(k)];
      }
*/
 
          thePixelChargeMap[pixel_no] += charge_in_pixel;

    }
  }
      
  return thePixelChargeMap;
}
