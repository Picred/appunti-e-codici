/*
19_8
Definire una funzione che prende in input un array
monodimensionale di interi senza segno e inverte il valore massimo
con il valore minimo. ES: [ 1 2 6 4 5 ] −− > [ 6 2 1 4 5 ].
*/
#include <iostream>

using namespace std;

void inverti(unsigned int A[], int dim);

int main(){
    int dim;

    cout << "Dimensione array: ";
    cin >> dim;

    unsigned int array[dim]={};

    for (int i=0; i<dim; i++){
        cout << "Valore A[" << i << "]: ";
        cin >> array[i];

    }
    //for (int k=0; k<dim; k++)
     //cout << array[k] << " - ";

    inverti(array, dim);

}

void inverti(unsigned int A[], int dim){
    unsigned int max=A[0];
    unsigned int min=A[0];
    int amax=0;
    int amin=0;
    
        for (int i=0; i<dim; i++){
            cout << A[i] << " - ";
        }
        cout << endl;

    for(int i=0; i<dim; i++){
        if(A[i]>max){
            max=A[i];
            amax=i;
        } 
        if (A[i]<min){
            min=A[i];
            amin=i;
        }

        }

    unsigned int temp=0;

    
  //  cout << "amax: " << amax << " amin: "<< amin << endl; 
    
    //inversione valori max e min

    temp=A[amax];
    A[amax]=A[amin];
    A[amin]=temp; 

        for (int i=0; i<dim; i++){
            cout << A[i] << " - ";
        }
}
