#include <iostream>

//no name clash! 
//nomi uguali protetti da 
//namespace! 
#include "alpha.h"
#include "beta.h"

using namespace std; 

int main(){

  using namespace alpha; 
  using beta::ClasseY; 

  ClasseX x(10); 
  ClasseY y("abcd");

  cout << x.getK() << endl; 
  cout << y.getS() << endl; 

}
