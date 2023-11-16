/*
19_9
Definire una funzione che prende in input un array
monodimensionale di interi senza segno e inverte l’ordine degli
elementi all’interno dello array. ES: input: [0 1 2 3 4 5], risultato
della elaborazione: [5 4 3 2 1]
*/
#include <iostream>

using namespace std;

void inverti(unsigned int A[], int dim);

int main (){
    int dim=4;
    unsigned int A[dim]={1,2,3,4};
        
    inverti(A, 4);

    for (int i=0; i<dim; i++){
        cout << A[i]; }
}

void inverti(unsigned int *A, int dim){
        int temp;
        int j=dim-1;
        int i=0;
            
        while(i!=j){
    
            temp = A[i];
            A[i]= A[j];
            A[j]= temp;

            i++; 
            j--;          
        }
        
        // return *A;
}
