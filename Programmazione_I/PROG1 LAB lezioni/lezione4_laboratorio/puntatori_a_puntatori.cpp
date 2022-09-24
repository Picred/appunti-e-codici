#include<iostream>

using namespace std;

int main() {
    int x = 5;
    int *x_ptr = &x;
    int **x_ptr_ptr = &x_ptr;

    cout << x << endl;
    cout << x_ptr << endl;
    cout << x_ptr_ptr << endl;
    cout << *x_ptr_ptr << endl;
    cout << **x_ptr_ptr << endl;
}