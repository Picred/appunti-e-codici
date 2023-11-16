#include "dynamic_stack.h"

int main(){
    Stack<int> pila;

    pila.push(4);
    pila.push(814);
    pila.push(99);

    cout << pila;

    pila.pop();

    cout << endl << pila;
}