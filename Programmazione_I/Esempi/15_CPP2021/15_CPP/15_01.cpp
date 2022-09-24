#include <iostream>

#define DIM 10

using namespace std; 

int main(){ 

  int A[DIM] = {}; //tutti a zero!
  int B[DIM]= {0}; // tutti a zero! 
  float C[DIM] = {0.2, 0.3, 0.4}; //i restanti saranno inizializzati a zero!

  //array di caratteri 
  char c[] = "pippo"; 
  char d[10] = {'a', 'b'}; // i restanti saranno caratteri '\0', ASCII = 0

  cout << "c=" << c << ", d=" << d << endl;

  for(int i=0; i<10; i++)
    cout << "d[" << i << "]= " << d[i] << ", (int=" << (int) d[i] << ")" << endl;

  int V[DIM] = {1,2,3,4,5}; //V[5], V[6], ...? 

  cout << "V[5]=" << V[5] << "\n\n"; 

  int W[DIM] = {};
  int Z[DIM]; //nessuna inizializzazione!!

  for(int i=0; i<DIM; i++){
    cout << "W[" << i << "]" << "=" << W[i] << endl; 
    cout << "Z[" << i << "]" << "=" << Z[i] << endl;
  }
}
