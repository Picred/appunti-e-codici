#include<iostream>
#include<string>
#include "libreria.h"

using namespace std;

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