#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>
using namespace std;


template<typename T>
class StaticStack{
    T* array;
    int top = -1; //indice dell'elemento top
    int size = 0; //dimensione massima
    int maxSize=-1; //valgono -1 perchè rappresentano la lista vuota perchè gli indici nell'array -1 non esistono

    public:
        StaticStack(int _maxSize) : maxSize(_maxSize){
            array = new T[maxSize];
        }

        T getTop(){
            if(isEmpty())
                return -1;

            return array[top];
        }

        void push (T val){
            if(top == maxSize-1){
                cout << "Stack Overflow" << endl;
                    return;
                }
            array[++top]=val;
        }

        T pop(){
            if(isEmpty())
                return -1;

            return array[top--];
        }

        bool isEmpty(){
            return top == -1;
        }

        friend ostream& operator<<(ostream& out, StaticStack<T>& s){
            out << "Static Stack: maxSize=" << s.maxSize << endl;
            out << "------" << endl;
            for(int i=s.top; i>=0; i--){
                out << s.array[i] << " - ";

            }
        return out;
        }
};

#endif