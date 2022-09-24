//esercizio 2 Itinere 9/12/2021
#include <string>

using namespace std;

string *** foo(string ***A, int n, int m, char *B, int c){
	//A è già allocata dinamicamente nel main
	//cerco le vocali in B e le metto in una stringa
	string vocaliB="";
	for (int i=0; i<c; i++){
		char carattere=B[i]; //errore, era A[i];

		if(carattere=='a' || carattere=='A' || carattere=='e' || carattere=='E' || carattere=='i'||carattere=='I' || carattere=='o' || carattere=='O' || carattere=='u' || carattere=='U'){
		vocaliB+=carattere;}}
	for (int j=1;j<m;j++){
		for(int i=0;i<n;i++){ string s=*A[i][j];
		//scorro la stringa vocaliB
		for (int k=0;k<vocaliB.length();k++){
			int indice=s.find(vocaliB);
		if (indice!=string::npos){
			(*A[i][j]).erase(indice,1);
		}
		}
	} j++;
	} return A;
}
			