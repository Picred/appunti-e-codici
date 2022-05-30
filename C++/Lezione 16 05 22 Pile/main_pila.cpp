#include "stack.h"
#include "static_stack.h"
#include <iostream>

using namespace std;


int main(){
    Stack<int> s;

    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);

    cout << s << endl;

    s.pop();
    s.pop();

    cout << s << endl;

    Node<int> *top=s.top();

    cout << *top << endl;

    StaticStack<int> st_s(10);

    st_s.push(10);
    st_s.push(11);
    st_s.push(12);
    st_s.push(13);
    st_s.push(14);

    cout << st_s << endl;

    int ret = -1;
}