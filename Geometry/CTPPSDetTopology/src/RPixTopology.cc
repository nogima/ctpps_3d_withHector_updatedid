#include "Geometry/CTPPSDetTopology/interface/RPixTopology.h"
#include <iostream>

unsigned short RPixTopology::no_of_pixels_simX_ = 160;  
unsigned short RPixTopology::no_of_pixels_simY_ = 156;  
unsigned short RPixTopology::no_of_pixels_ = 160*156;  

// all in mm
double RPixTopology::pitch_simX_ = 100E-3;
double RPixTopology::pitch_simY_ = 150E-3;
double RPixTopology::thickness_ = 0.23;
double RPixTopology::simX_width_ = 16.6;
double RPixTopology::simY_width_ = 24.4;

double RPixTopology::dead_edge_width_ = 200E-3;


RPixTopology::RPixTopology()

{
  indici_ = new CTPPSPixelIndices(156,160);
}
RPixTopology::~RPixTopology()

{
  delete indici_;
}


/*
bool RPixTopology::IsHit(double u, double v, double insensitiveMargin)
{
  // assumes square shape

  if (fabs(u) > last_strip_to_center_dist_)
    return false;

  if (fabs(v) > last_strip_to_center_dist_)
    return false;

  double sqrt_2 = sqrt(2.);
  double y = (u + v) / sqrt_2;
  double edge_to_ceter_dist = (x_width_ - phys_edge_lenght_ / sqrt_2) / sqrt_2 - insensitiveMargin;
  if (y < -edge_to_ceter_dist)
    return false;

  return true;
}
*/
