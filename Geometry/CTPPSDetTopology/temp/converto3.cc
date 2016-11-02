#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

int main(){

  ifstream file("data3.dat");
  
  unsigned int row,col;

  while (file.good()){

      file >> row >> col ;
      
      unsigned int index = col*160+row;
      
      cout << row << " "<< col  << " " << index << " "<<index%160 << " " <<index/160 << endl;
  }

  return 0;
}
