#include <iostream>

#define DIM 10
#define N 3
#define M 4

using namespace std; 

int main(){ 

  int A[DIM][DIM]; //matrice quadrata DIM x DIM elementi

  for(int i=0; i<DIM; i++)
    for(int j=0; j<DIM; j++)
      cout << "A[" << i << "][" << j << "]=" << A[i][j] << endl; 

  cout << "\n\n" ; 

  int B[DIM][DIM] = {0}; //tutti gli elementi a zero!

  for(int i=0; i<DIM; i++)
    for(int j=0; j<DIM; j++)
      cout << "B[" << i << "][" << j << "]=" << B[i][j] << endl; 

  cout << "\n\n" ; 

  int C[N][M] = {1,2,3,4,5,6,7,8,9,10,11,12};

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cout << "C[" << i << "][" << j << "]=" << C[i][j] << endl; 

  cout << "\n\n" ; 

  int D[N][M] = {1,2,3,4,5}; //inizializzazione parziale

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cout << "D[" << i << "][" << j << "]=" << D[i][j] << endl; 

  cout << "\n\n" ; 



  //NO! Il compilatore non riesce a calcolare le dimensioni 
  //int E[][] = {1,2,3,4,5,6,7,8,9,10,11,12}; 

  //OK
  int F[][M] =   {1,2,3,4,5,6,7,8,9,10,11,12}; 

  int G[][M] = {1,2,3,4,5,6,7,8,9,10};  //quante righe? 

  for(int i=0; i<N; i++)
    for(int j=0; j<M; j++)
      cout << "G[" << i << "][" << j << "]=" << G[i][j] << endl; 

}
