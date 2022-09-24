/*
Definire una funzione che prende in input un array
monodimensionale di interi senza segno e restituisce la media degli
elementi di tale array.
*/
#include <iostream>

using namespace std;

double media(unsigned int A[], unsigned int DIM);

//prova della funzione media

int main(){
    unsigned int array[]={};
    int dim;
    cout << "inserisci la dimensione dell'array: ";
    cin >> dim;

        for (int i=0; i<dim; i++){
            cout << "Inserisci A[" << i << "]: ";
            cin >> array[i];
        }

    

    double Media;
    Media=media(array, dim);
    cout << "La media e':" << Media;

}


double media(unsigned int A[], unsigned int DIM){
    double media=0;
        int i=0;
        while (i<DIM){
            media+=A[i];
            i++;
        }
        media/=i;
        return media;
}