//esercizio 1 Itinere 9/12/2021

#define n 4
#define m 3

using namespace std;

int foo(int* M[n][m], double z, short k){
	int n_colonne=0;
	double media=0.0;
	int elementi;
	for(int j=0; j<m; j++){
		elementi=0;
			for(int i=1;i<n;i++){
				if(A[i][j]!=nullptr){
					int el1=*A[i-1][j];
					int el2=*A[i][j];
					media=(static_cast<double>(el1)/el2)/2;
					if(media<z){
						elementi++;
					}
				}
			} if(elementi>=k){
				n_colonne++;
			   }
		} return n_colonne;
} //ho usato matrice A al posto di matrice M, 1 errore. Secondo il prof manca un ciclo for perchè secondo lui dovevano essere 3