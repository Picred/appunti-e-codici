#include <iostream>
#include<cstdlib>
#include "sorting.h"

#define dim 10

using namespace std;
using namespace sorting;

int main(){
    int vett[dim];
    
    cout << "----------RICERCA DICOTOMICA----------\n";

    cout << "Vettore[" ;
    for(int i=0; i<dim; i++){
        vett[i] = i;
        cout  << " " << vett[i] << " ";
    }
    cout << "]" << endl;

    
    cout << "Cerchiamo il 7 nel vettore(ricorsione)..." << endl; 
    cout << (dicotomicaRicorsiva(vett,7,0,dim-1) ? "Trovato" : "Non trovato") << endl; //true se lo trova, false se non lo trova
    
    cout << "Cerchiamo l'8 nel vettore (iterazione)..."<< endl;
    cout << (dicotomicaIterativa(vett,dim,8) ? "Trovato" : "Non trovato");


/////////////////////////////////////////////////////////////////////////
    cout << "\n\n----------ORDINAMENTO PER SCAMBIO----------\n";
    
    cout << "Vettore non ordinato[ " ;
    for(int i=0; i<dim; i++){
        vett[i] = dim-i;
        cout  << vett[i] << " ";
    } 
    cout << "]" << endl << endl;

    cout << "Ordiniamolo.."<< endl;
    ordinamentoPerScambio(vett,dim);

    cout << "Vettore ordinato[ " ;
    for(int i=0; i<dim; i++){
        cout  << vett[i] << " ";
    } 
    cout << "]";

    /////////////////////////////////////////////////////////////////////////
    cout << "\n\n----------SELECTION SORT----------\n";

    cout << "Vettore non ordinato[ " ;
    for(int i=0; i<dim; i++){
        vett[i] = dim-i;
        cout  << vett[i] << " ";
    }
    cout << "]" << endl << endl;

    cout << "Ordiniamolo..." << endl;
    selectionSort(vett,dim);

    cout << "Vettore ordinato[ " ;
    for(int i=0; i<dim; i++){
        cout  << vett[i] << " ";
    } 
    cout << "]";

}