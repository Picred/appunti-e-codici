#include "static_stack.h"

int main(){
    StaticStack<int> pila(3);

    pila.push(9);
    pila.push(32);
    pila.push(34);
    pila.push(24);

    cout << pila;

    pila.pop();
    pila.pop();
    cout << endl << pila;
}
