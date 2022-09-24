#include<iostream>

using namespace std;

int main() {
    //int x = 6;

    //if(x % 2 == 0) {
    //    cout << "Il numero e' pari" << endl;
    //} else {
    //    cout << "Il numero e' dispari" << endl;
    //}

    //cout << "Alla prossima!";

    //int n = 1;

    //while(n<=10) {
    //    cout << n << endl;
    //    n++;
    //}

    int x;

    //do {
    //    cout << "Indovina il numero: ";
    //    cin >> x;
    //} while(x!=5);

    cout << "Indovina il numero segreto: ";
    cin >> x;

    while(x!=5) {
        cout << "Indovina il numero segreto: ";
        cin >> x;
    }
}