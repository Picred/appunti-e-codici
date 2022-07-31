#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>


using namespace std;

void printArray(int array[], int n);


void merge(int A[], int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;

    cout << "INDICI: " << p << " " << q << " " << r << endl;

    int* L=new int[n1+1];
    int* R=new int[n2+1];

    //adesso devo procedere alla copia negli array L ed R
    for(int i=0; i<n1; i++){
        L[i]=A[p+i];
    }

    for(int j=1; j<=n2; j++){
        R[j-1]=A[q+j];
    }

    /* 
    for(int j=0; i<n2; j++)
        R[j]=A[q+j+1];
    */

    L[n1]=INT_MAX; //inserisco il valore sentinella, ovvero "infinito"
    R[n2]=INT_MAX; //inserisco il valore sentinella, ovvero "infinito"

    // cout << "L= " << endl;
    printArray(L,n1+1);
    // cout << "R= " << endl;
    printArray(R,n2+1);

    int i=0, j=0, k=p;


    for(k=p; k<=r; k++){
        if(L[i] < R[j]) {
            A[k]=L[i];
            i++;
        }
        else {
            A[k]=R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;
    // delete L; // elimina solo il primo elemento dell'array.
    // delete L[]; //non compila
}

void mergesort(int A[],int p, int r){
    if(p<r){
        int q = floor((p+r)/2.0);
        mergesort(A,p,q); //metà sinistra dell'array
        mergesort(A,q+1,r); //metà destra dell'array
        merge(A,p,q,r);
    }
}

void printArray(int array[], int n){
    for (int i=0; i<n; i++){
        cout << array[i] << "\t";
    }
    cout << endl;
}

int main(){
    int n=50;

    int array[n];

    //inizializzo array con numeri casuali

    for(int i=0; i<n; i++){
        array[i]=rand()%101;
    }
    // cout << "Non ordinato:" << endl;   
    printArray(array,n);

    cout << endl << endl;

    mergesort(array,0,n-1);
    // cout << "Risultato " << endl << endl;

    printArray(array,n);

    return 0;
}