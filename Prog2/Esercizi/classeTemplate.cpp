/*Scrivere una classe template che prenda due tipi di dato generici e li utilizzi
come tipi di dato per due attributi della classe stessa.
scrivere metodi set e get e un metodo di stampa, oltre al costruttore.*/

#include <iostream>

using std::cout

template<class T, class U>
class A{
    private:
        T val1;
        U val2;

    public:
        A(){};

        void setVal1(T val){ val1=val;}
        
        void setVal2(U val){val2=val;}

        T getVal1(){return val1;}

        U getVal2(){return val2;}

        void print(){
            cout << "val1=" << val1 << " val2=" << val2 << endl;
        }
};