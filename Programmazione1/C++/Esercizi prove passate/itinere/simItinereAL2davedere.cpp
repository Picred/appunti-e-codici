/*
Scrivere un metodo che prenda in input una matrice A di stringhe di dimensioni n × m ed una matrice B di puntatori a
stringhe di dimensioni m × l. Il metodo restituisca un vettore di booleani C di dimensione l in cui cj = true se e solo se `e
possibile trovare almeno una stringa, nella colonna j −esima di B (sia bkj ), la quale sia sottostringa della corrispondente stringa
presente nella riga j − esima di A (sia ajk). Si assuma n ≥ l. NB: si presti attenzione alle stringhe mancanti in B
*/

using namespace std;
#include <iostream>
#include <string>
#define n 3
#define m 4
#define l 4

bool* foo(string A[n][m], string* B[m][l]){
	bool* C=new bool[l];
	for(int c=0; c<l; c++){
		for(int k=0; k<l; k++){
			for(int i=0; i<m && i<n; i++){
				string s=*B[i][k];
				auto found = s.find(A[i][k]); 
				if (found!=string::npos){
					C[c]=true; c++;
				} else {
					C[c]=false; }
			}
		}
	}
	return C;
}

int main(){ //main da controllare

    string A[n][m];
    string *B[m][l];

    A[0][0] = "pippo";
    A[0][1] = "lucia";
    A[0][2] = "come";

    A[1][0] = "filippo";
    A[1][1] = "teo";
    A[1][2] = "gabriele";



    B[0][0] = new string ("ipp");
    B[0][1] = new string ("ia");
    B[0][2] = new string ("boo");
    B[0][3] = new string ("wljfn");

    B[1][0] = new string ("welkjdn");
    B[1][1] = new string ("jwnd");
    B[1][2] = new string ("ele");
    B[1][3] = new string ("wekbf");

    B[2][0] = new string ("jojnef");
    B[2][1] = new string ("weoihf");
    B[2][2] = new string ("ioef");
    B[2][3] = new string ("laelnf");

    bool *V = foo(A,B);

    for(int i=0;i<l;i++){
        cout << V[i];
    }
}