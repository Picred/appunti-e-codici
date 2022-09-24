#include<iostream>
#include<string>

using namespace std;

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
