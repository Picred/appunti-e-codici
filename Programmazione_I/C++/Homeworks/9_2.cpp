Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N × M
ed un numero p.

L’algoritmo dovr`a calcolare e stampare le medie aritmetiche
di tutti i valori minori o uguali a p per le sole righe di
V che hanno indice dispari.

INIZIO

	Leggi V; // NxM
	Leggi p;
	int i=1;
	int j=0;
	int media, box; // box è il contenitore del valore letto in V

	
	while (i<N){
		j=0;
		while (j<M) {
			
			if (V[i][j]<=p) {

			box=V[i][j];
			media=box+V[i][j];
			media=media/2;
			cout << media << endl;
			}
		j++;
		}
	i=i+2;
	
}