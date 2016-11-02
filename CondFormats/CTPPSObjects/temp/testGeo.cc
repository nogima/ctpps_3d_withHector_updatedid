#include <iostream>
#include <cassert>

using namespace std;

double getXcenter(int);
double getYcenter(int);
double getXdimension(int);
double getYdimension(int);

int main(){

  bool printRows = true;
  bool printColumns = true;


  if(printRows){
  cout << "row"<< "     xCenterCorner" << "    xCenter" << "     size"<<endl; 
  for(int row=0; row<160; row++){ 
  double xx=getXcenter(row);
  double xxCornerSystem = -xx + 8.3;
  cout << row << "          " << xxCornerSystem <<"          " << xx <<  "      " << getXdimension(row)<<endl;
  }
  cout << endl;
  }



  if(printColumns){
  cout << "col"<< "     yCenterCorner" << "     yCenter" << "     size"<<endl; 
  for(int col=0; col<156; col++){ 
  double yy=getYcenter(col);
  double yyCornerSystem = yy + 12.2;
  cout << col << "          " << yyCornerSystem <<"          " << yy <<  "      " << getYdimension(col)<<endl;
  }

  }



  return 0;
}


double getXcenter(int row){

  double x=0;
  const double pitch = 0.1;
  const double edge = 0.2;

  assert(row>=0 && row <=159);

  if(row >=0 && row <= 78){

    x = row*pitch + edge + pitch/2.;

  }

  if(row == 79){

    x = (row+1)*pitch + edge;

  }

   if(row == 80){

    x = (row+2)*pitch + edge;

  }

   if(row >=81 && row <= 158){

     x = (row+2)*pitch + edge + pitch/2.;

  }
 
   if(row == 159){

     x = 16.35;

  }


  return -x+8.3;
}

double getXdimension(int row){

  assert(row>=0 && row <=159);

  double size = 0.1;

  if(row == 79 || row ==80) size = 0.2;

  return size;
}





double getYcenter(int col){

  double y=0;
  const double pitch = 0.15;
  const double edge = 0.2;

  if(col >= 0 && col <= 50){
    
    y = edge + col*pitch + pitch/2.;

  }

  if(col == 51){
    y = edge + (col+1)*pitch;
  }

  if(col == 52){
    y = edge + (col+2)*pitch;
  }

  if (col >= 53 && col <=102){
    y = edge + (col+2)*pitch + pitch/2.;
  }

  if(col == 103){
    y = edge + (col+3)*pitch;
  }

  if(col == 104){
    y = edge + (col+4)*pitch;
  }



  if(col >= 105 && col <=155){
    y = edge + (col+4)*pitch + pitch/2.; 
  }


  return y-12.2;

}

double getYdimension(int col){

  assert(col>=0 && col <=155);

  double size = 0.15;

  if(col == 51 || col ==52 || col == 103 || col ==104) size = 0.3;

  return size;
}

