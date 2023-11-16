/*
11.9
Codificare in C++ un programma che chiede all’utente di
inserire due numeri decimali maggiori di zero e diversi tra
loro (ES: 10.2 e 24.7), ed un numero intero N.
• il programma calcola lo arrotondamento per eccesso o
per difetto di entrambi i numeri, a seconda che la parte
decimale sia maggiore o uguale a 0.5 oppure minore di
0.5 rispettivamente. Siano a e b i due numeri ottenuti,
con a < b.
• per ogni numero a ≤ p ≤ b, calcola e stampa la
somma degli N-1 numeri minori di p e la somma dei
2N numeri maggiori di p;
*/

#include <iostream>

using namespace std;

int main () {

    float N1, N2;
    int N;
    int numero, p, somma=0, prodotto=1;
    

    cout << "Inserisci due numeri decimali maggiori di zero e diversi fra loro: ";
    cin >> N1 >> N2;

    cout << "Inserisci un numero intero:";
    cin >> N;

    int a=N1+0.5;
    int b=N2+0.5;
         //   cout << a << " " << b;
       
        p=(a+b)/2;

        for (int i=a; i<p-1; i++){ //somma di n-1 numeri compresi fra a e p
            somma+=i;
        }

          cout << "La somma degli " << N-1 << "numeri, di cui a<p, e': " << somma << endl;

        somma=0;

        for (int i=p; i<b; i++){ //somma di 2N numeri compresi fra p e b
            somma+=i*2;    
        }
            cout << "La somma degli " << 2*N << " numeri, di cui p>b, e': " << somma;

    }