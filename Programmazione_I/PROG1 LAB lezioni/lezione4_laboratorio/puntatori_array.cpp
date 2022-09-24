#include<iostream>
using namespace std;

int main() {
    int x[5] = {1,2,3,4,5}; //puntatore costante

    cout << x << endl;
    cout << *x << endl; //x[0] = *(x+0)

    cout << (x+1) << endl;
    cout << (x+1) << endl;

    int *ptr = 0;
    cout << ptr << endl;
    cout << (ptr+1) << endl;

    cout << *(x+1) << endl; // x[i] -> *(x+i)
}