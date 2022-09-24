/*Scrivere un metodo che prenda come parametro
formale un array A di stringhe (tutte di lunghezza
dispari), e restituisca in output la massima lunghezza
delle stringhe palindrome contenute al centro delle
stringhe di A*/

#define N 3

// zhabcbalm

int fun(string A[N]) {
    int max = 0;
    for(int i=0; i<N; i++) {
        int len;
        if(A[i].length()==0)
            len=0;
        else if(A[i].length()==1)
            len=1;
        else {   
            int middle = A[i].length()/2;
            int low = middle-1;
            int high = middle+1;
            int hlen = 0;
            while((A[low]==A[high]) && (low>=0) && (high<A[i].length())) {
                low--;
                high++;
                hlen++;
            }
            len = hlen*2+1;
        }
    }
}
// zhabcbalm
// l = 9
// middle = 4
// low = 3
// high = 5

// hlen: 0 -> 1 -> 2
// len = 2*2+1 = 5

// abcba
// l=5
// middle = 2
// low=1
// high=3
// hlen: 0->1 -> 2
// len = 5

