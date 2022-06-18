#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <iostream>

using namespace std;

template<class T>
class StaticStack{
    private:
        T* array;
        int size=0;
        int maxSize=-1;
        int top=-1;
    public:
        StaticStack(int dim) : maxSize(dim){
            array=new T[maxSize];
        }

        bool isEmpty(){
            return top==-1;
        }

        bool isFull(){
            return size==maxSize;
        }

        T getTop(){
            if(this->isEmpty()){
                cout << "Empty static stack!";
                return NULL;
            }
            return array[top];
        }

        void push(T val){
            if(top==(maxSize-1)){
                cout << "Stack Overflow" << endl;
                return;
            }

            array[++top]=val;
            size++;
        }

        T pop(){
            if(this->isEmpty()){
                cout << "Empty Static Stack!";
                return NULL;
            }
            size--;
            return array[top--];
        }
        
        friend ostream& operator<< (ostream& os, StaticStack<T>& pila){
            if(pila.isEmpty()){
                os << "Empty static stack!";
                return os;
            }
            // os << "maxSize=" << pila.maxSize << endl;
            // os << "top=" << pila.getTop() << endl << "--------" << endl;;   
            for(int i=pila.top; i>=0;i--){
                os << *(pila.array[i]) << endl;
            }
            // os << endl;
            return os;
        }
        
};
#endif