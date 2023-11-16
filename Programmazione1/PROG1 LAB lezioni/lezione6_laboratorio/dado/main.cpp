#include "dado.h"
#include<iostream>

using namespace std;

int main() {
    cout << "Ho costruito il dado." << endl;
    Dado d;
    cout << "Ho lanciato il dado." << endl;
    d.lancia();
    cout << "Il valore ottenuto e': ";
    cout << d.getValore();
}