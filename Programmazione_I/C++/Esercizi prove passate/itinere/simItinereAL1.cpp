/*Esercizio 1 (punti 15) (scrivere la soluzione di seguito)
Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata S di dimensioni n × n di puntatori a interi
senza segno, un double w ed uno short k (si assuma k < n). Il metodo restituisca il valore booleano true se esistono almeno k
colonne in S che soddisfano il seguente requisito: la media aritmetica degli elementi della colonna stessa sia minore o uguale a
w. NB: si presti attenzione ai numeri mancanti..
*/
#include <iostream>
#include <string>
#define n 3

using namespace std;

bool foo(unsigned int* S[n][n], double w, short k){
	int cont_colonne=0, counter=0; double rap=0.0; unsigned int elementi=0;
	
	for (int j=0; j<n; j++){
		elementi=0;
	    	for (int i=0; i<n; i++){ 
				// if (S[i][j]!=nullptr){
				elementi+=*S[i][j];
				// cout << "somma elementi: " << elementi << endl << endl;
				// }
			} rap = static_cast<double>(elementi)/n;
			if (rap<=w){
				cont_colonne++;
			}
	}
		if (cont_colonne >= k){
			return true;
		} else {
			return false;
		}
}	

int main(){
    unsigned int *S[n][n];

    S[0][0]= new unsigned int(7); //colonna1
    S[0][1]= new unsigned int(4);
    S[0][2]= new unsigned int(0);

    S[1][0]= new unsigned int(2); //colonna1
    S[1][1]= new unsigned int(3);
    S[1][2]= new unsigned int(1);

    S[2][0]= new unsigned int(1); //colonna1
    S[2][1]= new unsigned int(2);
    S[2][2]= new unsigned int(2);

    double w = 0.3;
    short k = 1; //true se ci sono almeno k colonne che hanno la media aritmetica della colonna stessa <= w

    cout << foo(S,w,k);

	return 0;
}