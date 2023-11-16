#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    double p;

    cout << "Inserisci un numero qualsiasi: ";
    cin >> p;

    if (p<1){
        cerr << "Errore: numero minore di 1";
    }
    if (p>=1){
        int p2=p+0.5;
        int array[p2]={};

        srand(time(0));
        int i=rand()%(1000-50+1)+50; //valori a piacere [50,1000]

            //inizializzazione array con ciclo for

            for (int j=0; j<p2; j++){
                array[j]=i;
            }

            //inizializzazione array con ciclo while

                int j=0;
            while (j<p2){
                array[j]=i;
                j++;
            }
            j=0;
            //inizializzazione array con ciclo do while
            do {
                array[j]=i;
                j++;
            } while (j<=p2);

            //stampa array con ciclo for
            for (int k=0; k<p2; k++){
                cout << array[k]=i=rand()%(1000-50+1)+50 << " ";
            }
        }
}
