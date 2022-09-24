#include <iostream>
#include <cstdlib>

#define N1 5
#define M1 10

#define N2 7
#define M2 5

using namespace std;

/* Va bene solo con parametro attuale 
  matrice bidimensionale allocata dinamicamente 
*/ 
void f1(double *x[], int n, int m){

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cout << x[i][j] <<  " ";
    cout << endl;
  }

  cout << endl; 

}

/* Va bene solo con parametro attuale 
  matrice bidimensionale allocata dinamicamente 
*/
//double **v / double *v[]   
void f2(double **x, int n, int m){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cout << *(*(x+i)+j) <<  " ";
    cout << endl; 
  }
  cout << endl; 
}

/* 
 * Bisogna passare una matrice allocata 
 * staticamente o sullo stack. 
*/ 
void f3(double z[][M2], int n){    
  for(int i=0; i<n; i++){
    for(int j=0; j<M2; j++)
      cout << z[i][j] <<  " ";
    cout << endl;
  }  
  cout << endl;
}

/* Allocazione dinamica vs automatica/statica
* di matrici e passaggio come argomenti di funzioni. 
*/
int main(){

  srand(111222333);

  /* Operatore new del C++ -- Array */

  //allocazione dinamica di uno array di punt. a int
  double **x = new double*[N1]; //HEAP 

  //oppure allocazione statica/automatica di un array di punt. a int
  double *y[N2]; // 

  //una matrice z, allocazione automatica/statica 
  double z[N1][M2];

  //dynamic allocation of x
  for(int j=0; j<N1; j++)
    x[j] = new double[M1];
  
  //dynamic allocation of y
  for(int j=0; j<N2; j++)
    y[j] = new double[M2];
  
  //initialization of x
  for(int i=0; i<N1; i++)
    for(int j=0; j<M1; j++)
      x[i][j] = rand()/(double) RAND_MAX;

  //initialization of y
  for(int i=0; i<N2; i++)
    for(int j=0; j<M2; j++)
      y[i][j] = rand()/(double) RAND_MAX;

  //initialization of z
  for(int i=0; i<N1; i++)
    for(int j=0; j<M2; j++)
      z[i][j] = rand()/(double) RAND_MAX;

  cout << "f1(x)" << endl; 
  f1(x, N1, M1); //ok

  cout << "f2(x)" << endl;
  f2(x, N1, M1); //ok

  //f3(x, N2); // Errore di compilazione!

  cout << "f1(y)" << endl; 
  f1(y, N2, M2); 

  cout << "f2(y)" << endl;
  f2(y, N2, M2);
  //f3(y, N2);//  Errore di compilazione!

  cout << "f3(y):" << endl;
  //f3(y, N2); // Errore di compilazione!

  cout << "f3(z)" << endl;
  f3(z, N1);

  f2(z, N1, M2); 

  cout << "Inoltre: sizeof(z)=" << sizeof(z) << endl;
  cout << "\t..infatti: N1=" << N1 << ", M2=" << M2 << ", N1xM2xsizeof(double)=" << N1*M2*sizeof(double) << endl;

  cout << "Invece: sizeof(x)=" << sizeof(x) << ", sizeof(y)=" << sizeof(y) << endl;
  cout << "\t..infatti: N2=" << N2 << ", sizeof(double)xN2=" << N2*sizeof(double) << endl;   
}
