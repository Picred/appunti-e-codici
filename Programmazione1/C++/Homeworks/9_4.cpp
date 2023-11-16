/*
Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensioni N × M,
un array A di dimensione k, ed un numero w < M.
L’algoritmo stampa il valore di verit`a true se esiste almeno
una riga della matrice V che contiene almeno w elementi
maggiori di ogni elemento in A.
*/

Leggi V // N x M
Leggi A // DIM=k
Leggi w<M

int i=0,j;
int elementiR;

		while (i<N){
			j=0;
			elementiR=0;
				while (j<M){
				elementiR++
				if (V[i][j]>A[i] && elementiR<w)
				Stampa true;	
				}
		}