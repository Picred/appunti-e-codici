/* 11.1 
Sulla base degli esempi precedenti, codificare un
ciclo while in linguaggio C++ nel quale:
• il loop si ferma quando il capitale o montante
raggiunge o supera la cifra target definita in una
costante T;
• tuttavia il periodo di accumulo di interessi sul
montante non deve in ogni caso superare il
numero di anni definito in una costante N.
*/

#include <iostream>

using namespace std;

#define TASSO_INTERESSE 0.1 

int main () {
    const double TARGET=1500.0;
    double capitale=1000.0;
    int anno=0;
    int N=5;

        while (capitale<TARGET) {
            capitale+=capitale*TASSO_INTERESSE;
            anno++;
            if (anno>N){
                cout << "Anni superati" << endl;
                break;
            }
        }
    cout << "Capitale: " << capitale << endl;
}