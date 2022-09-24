#include<iostream>

using namespace std;

int main() {
    int x = 5;

    cout << x << endl;
    cout << &x << endl;

    int *x_ptr = &x;

    cout << x_ptr << endl;

    //int *ptr = NULL;
    int *null_ptr = nullptr;
    //int *ptr = 0;

    cout << null_ptr << endl;

    cout << *x_ptr << endl;

    // x_ptr: int* (puntatore a intero)
    // *x_ptr: int (intero)
    // x: int (intero)
    // &x: int* (puntatore a intero)

    *x_ptr = 8;

    cout << x << endl;

    //cout << *null_ptr << endl; // ERRORE: null_ptr è nullo

    int a = 2;
    int b = 3;

    int *a_ptr = &a;
    int *b_ptr = &b;

    cout << (a==b) << endl; //0
    cout << (a_ptr==b_ptr) << endl; //0

    b_ptr=&a;
    cout << (a_ptr==b_ptr) << endl; //1
    cout << (*a_ptr==*b_ptr) << endl; //1

    int aa = 2;
    int bb = 2;
    int *aa_ptr = &aa;
    int *bb_ptr = &bb;

    cout << (aa==bb) << endl; //1
    cout << (aa_ptr==bb_ptr) << endl; //0

    int var = 8;
    const int* var_ptr = &var; // (const int)*

    cout << var_ptr << endl;
    cout << *var_ptr << endl;

    //*var_ptr = 0; // ERRORE: puntatore di sola lettura

    int var2 = 7;
    int* const var2_ptr = &var2; // (int)* const

    cout << *var2_ptr << endl;
    *var2_ptr = -2;
    cout << var2 << endl;

    //var2_ptr = &x; // ERRORE: il puntatore è costante

    int var3 = -9;
    const int* const var3_ptr = &var3;

    cout << *var3_ptr << endl;
    //*var3_ptr = 8; //ERRORE
    //var3_ptr = NULL; //ERRORE
}