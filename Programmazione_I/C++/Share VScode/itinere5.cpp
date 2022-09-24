/*
Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B.
*/

#include <iostream>
#define N 2 //righe di A e colonne di B
#define M 3 //colonne di A                         A[n][m] 
#define K 4 //righe di B                           B[k][n]

using namespace std;

double *array(unsigned int A[N][M], unsigned int B[K][N]){

    double *C=new double[N];


    double rapporto, somma=0.0, prodotto=1;
    
    
    for(int i=0; i<N; i++){      //riga matrice A o colonne B
    
        for(int j=0; (j<M && j<K) ;j++){   //righe di B e colonne di A
             
            prodotto*=B[j][i];     
            somma+=A[i][j];
        }
       rapporto=somma/prodotto;
       C[i]=rapporto;
    }
    return C;
}  

  int main(){
    unsigned int A[N][M] = { {1,2,3}, //2x3 somma riga =15
                             {4,5,6} };

    unsigned int B[K][N]={{2,3},  //4x2 prodotto colonne = 945
                          {4,5},        //rapporto =somma/prodotto 
                          {6,7},
                          {8,9} };      
    
    double *C=array(A, B);

    for (int i=0; i<N; i++){
        cout << C[i] << " - ";

    }
}






























double * arrayC(int A[n][m],int B[k][n]){
	
	double * C = new double [n];
	double rapporto, somma=0.0 , prodotto = 1.0;
	
	
	for (int i=0;i<n;i++){
          //scorre le righe di A e fa la somma
        for (int z=0;z<m;z++){
            somma+=A[m][z];
        }
		//scorre le colonne di B e fa il prodotto
	    for (int j=0;j<k;j++){
		prodotto*=B[j][k];
	}
	
	rapporto= somma/prodotto;
	C[i]= rapporto;
	cout<<C[i];
	
}
