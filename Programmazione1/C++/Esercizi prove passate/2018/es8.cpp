/*
Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n x m, uno
short k ed uno short w, e restituisca true se la matrice contiene almeno w colonne che contengono almeno
una sequenza di interi monotona crescente di lunghezza maggiore o uguale a k.
*/

bool foo(int** A,int n, int m, short k, short w){
    int nColonne;
    int sequenza;
    //scorro le colonne
    for (int j=0; j<m; j++){
        nColonne=0;
        sequenza=1;
        for (int i=1; i<n; i++){
            if (A[i-1][j] == (A[i][j]-1)){ //controllo che il precedente é uguale all'attuale - 1(quindi una sequenza)
                sequenza++;
            if(sequenza>=k)
                nColonne++;
            }
        if(nColonne>=w)
            return true;
        }
    }
    return false;
}