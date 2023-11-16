/*
19.6
Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce l’indice dell’ultima
consonante che si trova nello array in input.
*/
#include <iostream>

using namespace std;

int indice(char array[], int dim);

int main(){
    //array da tastiera
    int dim;
    cout << "Dimensione array: ";
    cin >> dim;
    char A[dim]={};

    for (int i=0; i<dim; i++){
        cout << "Inserisci il carattere di A[" << i << "]: ";
        cin >> A[i];
    }

    int indice_ultima_consonante=0;
    indice_ultima_consonante=indice(A, dim);
    cout << "L'indice dell'ultima consonante e': " << indice_ultima_consonante;
}

int indice(char array[], int dim){
    int j;
    for (int i=0; i<dim; i++){
        switch (array[i]){
            case 'a':
            break;
            case 'e':
            break;
            case 'i':
            break;
            case 'o':
            break;
            case 'u':
            break;
            default:
            j=i;
        }
    }
    return j;
}