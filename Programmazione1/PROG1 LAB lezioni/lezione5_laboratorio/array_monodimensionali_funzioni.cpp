#include<iostream>
using namespace std;

#define N 3

void fun1(int x[N]) {
    for(int i=0; i<N; i++)
        cout << x[i] << "\t";
    cout << endl;
}

void fun2(int x[]) {
    for(int i=0; i<N; i++)
        cout << x[i] << "\t";
    cout << endl;
}

void fun3(int *x) {
    for(int i=0; i<N; i++)
        cout << x[i] << "\t"; //*(x+i)
    cout << endl;
}

int main() {
    int x[N] = {1,2,3};
    fun1(x);
    fun2(x);
    fun3(x);

    cout << endl;

    int *y = new int[N]{1,2,3};
    fun1(y);
    fun2(y);
    fun3(y);
}