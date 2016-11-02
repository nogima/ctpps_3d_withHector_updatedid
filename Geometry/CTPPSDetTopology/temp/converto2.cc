#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main(){

  ifstream file("data2.dat");
  double x,y;

  const double W = 16.6;
  const double L = 24.4;
  const double pitch_simX_ = 0.1;
  const double pitch_simY_ = 0.15;
  const double dead_edge_width_ = 0.2;
  
  unsigned int row,col;
  double lower_x, higher_x, lower_y, higher_y;
  while (file.good()){

      file >> row >> col ;
    
      assert(row>=0 && row<=159 && col>=0 && col <=155);
 
// rows (x segmentation)

      if(row == 0) {
	lower_x = 0;
	higher_x = 0.3;
      }
      if( row > 0 && row <= 78 ){
	lower_x = 0.3 + (row-1)*pitch_simX_;
	higher_x = 0.3 + row*pitch_simX_;
      } 
      if(row == 79) {
	lower_x = 0.3 + (row-1)*pitch_simX_;
	higher_x = 0.3 + (row+1)*pitch_simX_;
      }
      if(row == 80) {
	lower_x = 0.3 + (row)*pitch_simX_;
	higher_x = 0.3 + (row+2)*pitch_simX_;
      }
      if( row > 80 && row <= 158 ){
	lower_x = 0.3 + (row+1)*pitch_simX_;
	higher_x = 0.3 + (row+2)*pitch_simX_;
      } 
      if( row == 159){
	lower_x = 0.3 + (row+1)*pitch_simX_;
	higher_x = 0.3 + (row+4)*pitch_simX_;
      } 

// columns (y segmentation)



     if(col == 0) {
	lower_y = 0;
	higher_y = 0.35;
      }
      if( col > 0 && col <= 50 ){
	lower_y = 0.35 + (col-1)*pitch_simY_;
	higher_y = 0.35 + col*pitch_simY_;
      } 
      if(col == 51) {
	lower_y = 0.35 + (col-1)*pitch_simY_;
	higher_y = 0.35 + (col+1)*pitch_simY_;
      }
      if(col == 52) {
	lower_y = 0.35 + (col)*pitch_simY_;
	higher_y = 0.35 + (col+2)*pitch_simY_;
      }
      if( col > 52 && col <= 102 ){
	lower_y = 0.35 + (col+1)*pitch_simY_;
	higher_y = 0.35 + (col+2)*pitch_simY_;
      } 

      if(col == 103) {
	lower_y = 0.35 + (col+1)*pitch_simY_;
	higher_y = 0.35 + (col+3)*pitch_simY_;
      }
      if(col == 104) {
	lower_y = 0.35 + (col+2)*pitch_simY_;
	higher_y = 0.35 + (col+4)*pitch_simY_;
      }
         if( col > 104 && col <= 154 ){
	lower_y = 0.35 + (col+3)*pitch_simY_;
	higher_y = 0.35 + (col+4)*pitch_simY_;
      } 
       if(col == 155) {
	lower_y = 0.35 + (col+3)*pitch_simY_;
	higher_y = 0.35 + (col+4)*pitch_simY_ + 0.2;
      }
 








       cout << row << " " << col << " " << lower_x << " " <<higher_x << " " <<lower_y << " " <<higher_y << " " <<endl;

  }

  return 0;
}
