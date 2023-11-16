/*
Scrivere un metodo che prenda in input un parametro formale array di caratteri A di dimensioni n× m ×k ed
un parametro formale short w e restituisca il valore true se esiste,
 all’interno della matrice, almeno una riga o una colonna di
una qualunque matrice bidimensionale contenuta nello array A che 
contenga una sequenza di caratteri palindroma di lunghezza maggiore o uguale a w
*/

bool foo(char ***A, int n, int m,int k, short w){
    int counter=0;

    // scorro le varie dimensioni della matrice A[k][n][m]

    for (int l=0; l<k; l++){
        //scorro la matrice bidimensionale
        for (int i=0; i<n; i++){
            counter=0;
            for(int j=0; j<m && j<m-1-j; j++){
                //vedo se la riga e' palindroma
                if (A[l][i][j] != A[l][n-1-i][m-1-j]){
                    break;
                } else {
                    counter++;
                }
                if (counter >=w){
                    return true;
                }
            }
        }
    }
    return false;
}