/*

    Scrivere un metodo che prenda in input una matrice A di float, e restituisca il valore di somma(min(A,j)), 
    dove min(A, j) è la funzione che restituisce 
    il minimo elemento presente nella j-esima colonna di A. N.B.: 
    Non è possibile utilizzare array ausiliari.

*/

#include <iostream>


using namespace std;

float minimo;
float somma=0;

float foo(float **A, int n, int m){
    for (int j=0;j<m;j++){
        minimo=A[0][j];

        for (int i=0;i<n;i++){

            if (minimo>A[i][j])
                minimo=A[i][j];
        }
        somma+=minimo;
    }
return somma;
}

int main(){
    int n=3, m=4;
    float **A=new float *[n];
    for(int i=0; i<n;i++){
        A[i]=new float [m];
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
            cout<<A[i][j]<< "  ";
			
		}
        cout<<endl;
	}

    float som = foo(A,n,m);

    cout << "somma=" << som << endl;

    return 0;
}

/*          {{1.7,1,5,7},
			 {4,7,8,2},
			 {5,5,2.2,2}}; 
                                */