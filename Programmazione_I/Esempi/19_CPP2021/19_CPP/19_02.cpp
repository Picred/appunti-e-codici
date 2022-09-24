#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std; 

/* Allocazione dinamica di array monodimensionali */
int main(){

  srand(111222333); 

  /* Operatore new del C++ -- Array */
  int *a = new int[SIZE]; //allocazione dinamica di uno array di int
  
  //allocazione dinamica di un array di double 
  double *x;
  x= new double[SIZE]; 

  for(int j=0; j<SIZE; j++){
    x[j] = rand()/(double) RAND_MAX;
    a[j] = rand()%1000; 
  }
    
  for(int j=0; j<SIZE; j++){
    cout << "a[" << j << "]:" << a[j] << ", x[" << j << "]:" << x[j] << endl;  
  }

  cout << endl; 

  //anche (aritmetica dei puntatori): 
  for(int j=0; j<SIZE; j++){
    cout << "a[" << j << "]:" << *(a+j) << ", x[" << j << "]:" << *(x+j) << endl;  
  }
}
