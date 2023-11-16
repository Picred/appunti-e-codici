#include<iostream>
using namespace std;

int* fun() {
    int *x = new int[500000];
    return x;
}

int main() {
    int *x;
    for (int i=0; i<100000; i++) {
        x = fun();
        delete[] x;
    }
}