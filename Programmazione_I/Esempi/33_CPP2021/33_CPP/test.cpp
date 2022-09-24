#include <iostream>
#include "binary_string.h"

using namespace std; 

int main(){
  
  cout << sizeof(char) << endl;   

  //NB: a e' dispari. Con lo shift a destra (a >> b) si ottiene la PARTE INTERA
  //di (a / 2^b ) 
  unsigned short a = 31; 
  cout << "a: " << a << " (dec), " <<  binaryString(a) << " (bin)" << endl;        
  cout << "a >> 2: " << (a>>2) << " (dec), " << binaryString(a>>2) << " (bin)" << endl; 

  short b = -31; 
  cout << binaryString(b) << endl;   

}
