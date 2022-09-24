/*
Definire una funzione che prende in input un array
monodimensionale di caratteri e restituisce il numero di vocali
presenti nello array.
*/

#include <iostream>

using namespace std;

int vocali_array(char a[], int dim);


int main (){
    int dim=4;
    char array[dim]={'a','g','u','x', '\0'};

    int vocali;
    vocali=vocali_array(array, dim);
    cout << "Vocali in array: " << vocali;
}



int vocali_array(char a[], int dim){
    int vocali=0;

        for (int i=0; i<dim; i++){
            switch(a[i]){
                case 'a':
                    vocali++;
                    break;
                case 'e':
                    vocali++;
                    break;
                case 'i':
                    vocali++;
                    break;
                case 'o':
                    vocali++;
                    break;
                case 'u':
                    vocali++;
                    break;
                default:
                    break;
            }
        }
        return vocali;
}