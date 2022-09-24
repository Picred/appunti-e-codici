#include<iostream>
#include<string>
using namespace std;

int somma(int, int); //esiste una funzione somma che prende due interi e restituisce un intero, verrà implementata più in là

int pow(int base, int esponente = 2);

void print(string);

int main() {
    int x = somma(2,3);
    {
        int y = x+2;
        cout << y << endl;
    }
    cout << x << endl;
    //cout << y << endl; //ERRORE

    int z = 8;
    int y = somma(x, z);
    cout << y << endl;

    print("Hello World");

    cout << pow(2,3) << endl;
    cout << pow(2) << endl;
    cout << pow(2, 4) << endl;
}


int somma(int x, int y) {
    return x + y;
}

int pow(int base, int esponente) {
    int prod = 1;
    for(int i=0; i<esponente; i++)
        prod *= base;
    return prod;
}

void print(string s) {
    cout << s << endl;
}
