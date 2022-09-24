/*Scrivere un metodo che prenda in input tre parametri formali: una matrice 
di puntatori a stringhe A di dimensioni n × m, uno short k ed una stringa s. 
Il metodo restituisca un array di bool di dimensione n in cui il singolo 
elemento di indice i assume valore true se la stringa s è sottostringa 
di almeno k stringhe della riga i-esima della matrice A.
*/
#include<iostream>
#include<cstring>

using namespace std;

#define n 2
#define m 3


//string A[n][m] -> matrice di stringhe
//string *A[n][m] -> matrice di indirizzi a locazioni di memoria che contengono stringhe

bool* funzione(string* A[n][m], short k, string s){
	bool* arr = new bool[n];
	
	for(int i = 0; i < n; i++){
		int conta = 0;
		for(int j = 0; j < m; j++){			
			if((strstr((*A[i][j]).c_str(), s.c_str()) != NULL)){
				conta++;
			}
		}
		if(conta>=k)
			arr[i] = true;
		else
			arr[i] = false;
	}
	// for(int i = 0; i < n; i++){
	// 	arr[i] = true;
	// 	cout << arr[i] << " " ;
	// }
	return arr;
}

int main(){
	string* matrice[n][m];
	
	matrice[0][0] = new string("pippo");
	matrice[0][1] = new string("paperinos");
	matrice[0][2] = new string("francos");
	matrice[1][0] = new string("antonio");
	matrice[1][1] = new string("pippo");
	matrice[1][2] = new string("pippofranco");
	
	short k = 2;
	string s = "os";
	//int n_arr = sizeof(funzione(matrice, k, s)) / sizeof(int); 
	//bool arr[n_arr] = {funzione(matrice, k , s)};
	bool *arr = funzione(matrice, k , s);
	//cout << endl << n_arr << endl;
	for(int i = 0; i < n; i++){
		cout << i << ": " << arr[i] << endl;
	}
	delete[] arr;
	arr = nullptr;
}
