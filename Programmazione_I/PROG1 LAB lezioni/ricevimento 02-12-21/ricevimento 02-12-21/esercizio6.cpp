/* 
   Scrivere una funzione che prenda in input un parametro formale array 
   di caratteri A di dimensioni n × m × k ed un parametro formale short w 
   e restituisca il valore true se esiste, all’interno della matrice, 
   almeno una riga o una colonna di una qualunque matrice bidimensionale 
   contenuta nello array A che contenga una sequenza di caratteri palindroma 
   di lunghezza maggiore o uguale a w.
*/

// zzabbal

// abba
// 0 1 2
// 3 2 1

// abcba

// a b c 
// 0 1 2 3
// 4 3 2 1

//z

#define n 2
#define m 2
#define k 3

//A[0] -> 2 x 3 // n=0
//A[1] -> 2 x 3 // n=1

//m=0 A[i][0][j]

//k=0 A[i][k][0]



bool fun(char A[n][m][k], short w) {
    for(int i=0; i<n; i++) { //scorre le matrici bidimensionali fissato i
        for(int j=0; j<m; j++) { //scorro le righe
            for(int h=0; h<k; h++) {
                int low=h;
                int high=k-1;
                int half_len = 0;
                while(low<high){
                    if(A[i][j][low]!=A[i][j][high]) {
                        high--;
                    } else {
                        low++;
                        high--;
                        half_len++;
                    }
                }
                if((half_len-1)*2>=w)
                    return true;
            }
        }
        for(int h=0; h<k; h++) { //scorro le colonne
            for(int j=0; j<m; j++) {
                int low=j;
                int high=m-1;
                int half_len = 0;
                while(low<high){
                    if(A[i][low][h]!=A[i][high][h]) {
                        high--;
                    } else {
                        low++;
                        high--;
                        half_len++;
                    }
                }
                if((half_len-1)*2>=w)
                    return true;
            }
        }
    }

    for(int j=0; j<m; j++) { //scorre le matrici bidimensionali fissato j

    }

    for(int h=0; h<k; h++) { //scorre le matrici bidimensionali fissato h

    }
    return false;
}