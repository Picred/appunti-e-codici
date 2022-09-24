/*
Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × n ed
un double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice A per cui il
rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale principale
di A sia maggiore di w.
*/

#define n 4

bool foo(int A[n][n], double w){
    double rapporto;
    int somma_colonna;
    int somma_principale=0;

    //sommo elementi diag principale prima
    for (int i=0; i<n; i++)
        somma_principale+=A[i][i];

    //scorro per colonna
    for(int j=0; j<n;j++){
        somma_colonna=0;
            for(int i=0;i<n;i++){
                somma_colonna+=A[i][j];
            }
            rapporto=(double)somma_colonna/(double)somma_principale;
            if(rapporto>w)
                return true;
    }
    return false;
}



