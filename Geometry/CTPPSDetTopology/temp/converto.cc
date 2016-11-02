#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main(){

  ifstream file("data.dat");
  double x,y;

  const double W = 16.6;
  const double L = 24.4;
  const double pitchX = 0.1;
  const double pitchY = 0.15;
  const double dead_edge = 0.2;
  
  unsigned int row,col;

  while (file.good()){

      file >> x >> y ;
    
      assert(x>=0 && x<=16.6 && y>=0 && y <=24.4);
 
// rows (x segmentation)

      if(x <= (dead_edge+pitchX) ) row = 0;

      if(x > (dead_edge+pitchX) && x <= (dead_edge+79*pitchX)   ){
	row = int((x - dead_edge-pitchX)/pitchX)+1 ;
      }      

     if(x >  (dead_edge+79*pitchX) &&  x<= (dead_edge+81*pitchX)) row = 79;

     if(x >  (dead_edge+81*pitchX) &&  x<= (dead_edge+83*pitchX)) row = 80;

     if(x > (dead_edge+83*pitchX) && x <= (dead_edge+162*pitchX)   ){
	row = int((x - dead_edge-pitchX)/pitchX)-1;
      }      
     if(x > (dead_edge+162*pitchX) ) row = 159;

// columns (y segmentation)

      if(y <= (dead_edge+pitchY) ) col = 0;

      if(y > (dead_edge+pitchY) && y <= (dead_edge+51*pitchY)   ){
	col = int((y - dead_edge-pitchY)/pitchY)+1 ;
      }      

     if(y >  (dead_edge+51*pitchY) &&  y<= (dead_edge+53*pitchY)) col = 51;

     if(y >  (dead_edge+53*pitchY) &&  y<= (dead_edge+55 *pitchY)) col = 52;

     if(y >  (dead_edge+55*pitchY) &&  y<= (dead_edge+105 *pitchY)) {
	col = int((y - dead_edge-pitchY)/pitchY)-1 ;
     }



     if(y >  (dead_edge+105*pitchY) &&  y<= (dead_edge+107*pitchY)) col = 103;

     if(y >  (dead_edge+107*pitchY) &&  y<= (dead_edge+109 *pitchY)) col = 104;

     if(y >  (dead_edge+109*pitchY) &&  y<= (dead_edge+159 *pitchY)) {
	col = int((y - dead_edge-pitchY)/pitchY)-3 ;
     }

     if(y >  (dead_edge+159*pitchY) ) col = 155;

 



      cout << x << " " << y<< " " << row << " " << col <<endl;
  }


  return 0;
}
