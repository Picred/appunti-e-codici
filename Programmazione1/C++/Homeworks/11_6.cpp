/*
11.6
Codificare in linguaggio C++ un algoritmo che stampi a ritroso la sequenza di caratteri da ’a’ a ’z’, ma non le vocali. Codificare due versioni differenti nelle quali si fa uso del
costrutto for e del costrutto while rispettivamente.
*/
#include <iostream>

using namespace std;

int main (){
    int i=20;
    char alfabeto[]={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};

    cout << "Stampa lettere dell'alfabeto a ritroso, escluse vocali, mediante for\n";
    for (alfabeto[i]; i>=0; i--){
        switch (alfabeto[i]){
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
            cout << "Lettera: " << alfabeto[i] << endl;
        }
   // cout << alfabeto[i] << endl;
    }
        cout << "Stampa lettere dell'alfabeto a ritroso, escluse vocali, mediante while\n";
        i=20;
        while (i>=0){
        
         switch (alfabeto[i]){
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
            cout << "Lettera: " << alfabeto[i] << endl;
        }
        i--;
        }
}