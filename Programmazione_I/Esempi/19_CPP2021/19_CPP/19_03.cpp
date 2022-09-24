#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

int main(){

  srand(111222333);

  /* Operatore new del C++ -- Array */
  unsigned int *a = new unsigned int[SIZE]; //allocazione dinamica di uno array di int
  
  //allocazione dinamica di un array di double 
  double *x; 
  x= new double[SIZE]; 

  for(int j=0; j<SIZE; j++){
    x[j] = rand()/(double) RAND_MAX;
    a[j] = rand()%1000; 
  }

  //accesso agli elementi mediante operatore [] e indice     
  for(int j=0; j<SIZE; j++){
    cout << "a[" << j << "]:" << a[j] << ", x[" << j << "]:" << x[j] << endl;  
  }

  cout << endl; 

  //accesso agli elementi mediante aritmetica dei puntatori 
  for(int j=0; j<SIZE; j++){
    cout << "a[" << j << "]:" << *(a+j) << ", x[" << j << "]:" << *(x+j) << endl;  
  }

  //valore del puntatore x
  cout << "x prima della delete: " << x << endl; 

  //deallocazione del blocco di mem. puntato da x
  delete [] x; 

  //valore del punt. dopo la deallocazione 
  cout << "x dopo la delete: " << x << endl;

  //buona norma, dopo deallocazione, 
  //scrivere nullptr nel puntatore.
  //Inoltre, prima del tentativo di 
  //deallocazione controllare, il valore del puntatore. 

  if(a){ // MEGLIO
    delete [] a;
    a = nullptr; //C++11
  }

  //senza il controllo su a, una seconda 
  //delete avrebbe risultato indefinito (e.g. memoria corrotta)

}
