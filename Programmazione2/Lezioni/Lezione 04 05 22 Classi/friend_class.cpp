#include <iostream>

using namespace std;

class Y{};

class A{
    int data;
    class B{}; //scope di B è limitato all'interno della classe A. Un oggetto B fuori da A non può essere creato
    enum {a = 100}; //array blabla-abile
    friend class X;
    friend Y;
};

class X : A::B { //X eredita da B in maniera pubblica, lo posso fare solo perchè è friend
    A::B mx;
        class Y{
            A::B my;
        };
    int v[A::a];
}