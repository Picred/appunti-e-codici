#include <iostream>

using namespace std; 

/* allocazione dinamica di tipi primitivi */ 
int main(){

  /* Operatore new del C++ */

  int b; //stack 
  int *a = new int; //HEAP - allocazione dinamica di una cella di memoria per un int
  
  double *x = new double; //allocazione dinamica di una cella di memoria per un double

  *a = 10; 
  *x = 45.123456789; 

  cout << "a=" << *a << ", x=" << *x << endl;

}
