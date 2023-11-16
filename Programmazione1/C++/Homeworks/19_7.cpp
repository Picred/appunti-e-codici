/*
19.7 (R)
Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce il puntatore alla cella
che contiene la prima vocale dello array.
*/
#include <iostream>
#include <string>

using namespace std;

int puntatore(char array[], int dim);

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


   int a=puntatore(A, dim);
   int *ptr=&a;
   cout << (void*)ptr;
    
}

int puntatore(char array[], int dim){
    char *ptr=array;
        for (int i=0; i<dim; i++){
            switch (array[i]){
                case 'a':
                    *ptr=array[i];
                    break;
                case 'e':
                    *ptr=array[i];
                    break;
                case 'i':
                    *ptr=array[i];
                    break;
                case 'o':
                    *ptr=array[i];
                    break;
                case 'u':
                    *ptr=array[i];
                    break;
            }
        }
        return *ptr;
}