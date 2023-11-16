/*
Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N × N.
L’algoritmo dovr`a calcolare e stampare la media aritmetica
dei valori differenza calcolati tra ogni valore della diagonale principale e il corrispondente valore della diagonale
secondaria.
*/

Leggi V // N x N

int media, i=0;
int differenze;
int c=1;

while (i<N){
	differenze=A[N-c][N-c]-A[i][i];
	c++;
	i++;
	media=differenza/2;
	Stampa media;
}