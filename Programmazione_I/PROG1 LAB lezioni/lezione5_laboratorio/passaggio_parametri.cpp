#include<iostream>
using namespace std;

void fun(int &x) {
    x = 7;
}

void fun3(int x) {
    x = 7;
}

void fun2(int *x) {
    *x = 7;
}

void fun4(int* &x) {
    x = new int(9);
}

void fun5(int* x) {
    x = new int(9);
}

void minmax(int x, int y, int &min, int &max) {
    min = (x<y) ? x : y;
    max = (x>y) ? x : y;
}

int main() {
    //int z = 2;

    //fun(z);
    //fun2(&z);

    //cout << z;

    // int *x = new int(2);
    // int *y = x;

    // fun5(x);

    // cout << *x << endl;

    // cout << *y;

    int x = 3;
    int y = 2;

    int min, max;

    minmax(x,y,min,max);

    cout << min << " - " << max << endl;

}