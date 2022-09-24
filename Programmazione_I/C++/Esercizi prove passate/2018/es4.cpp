/*
Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione 
n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il
 prodotto degli
elementi della colonna i-esima di B
*/

#define n 4
#define m 5
#define k 3
double* foo(int A[n][m], int B[k][n]){
    double *C=new double[n];
    int somma=0;
    double prodotto=1;

    double rapporto;

    for (int i=0; i<n; i++){
            //scorro le righe di A e sommo gli elementi
            somma=0;
        for (int j=0; j<m; j++){
            somma += A[i][j];
        }
        // scorro le colonne di B e moltiplico i fattori
        prodotto=1;
        for (int j=0; j<k; j++){
            prodotto *= B[i][j]; 
        }
        rapporto=somma/prodotto;
        C[i]=rapporto;
    }
    return C;
}