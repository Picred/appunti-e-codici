#ifndef STACK_H
#define STACK_H

#include "list.h"
#include <iostream>

using namespace std;

template<typename T>
class Stack : protected List<T> {
    
    int size=0;

    public:
        Stack() : List<T>(){}


        bool isEmpty(){
            return size ==0;
        }


        Node<T>* top(){
            if(isEmpty()){
                return nullptr;
            }
            return List<T>::getHead();
        }

        void push(T val){
            List<T>::insertHead(val);
            size++;
        }

        Node<T>* pop(){
            if(isEmpty()){
                return nullptr;
            }
            Node<T> *ptr =top(); //prendo un riferimento al nodo in testa
            List<T>::removeHead(); //posso cancellare
            size--;
            return ptr;
        }

        friend ostream& operator<< (ostream& out, Stack<T>& s){
            // return out << (List<T>)s; //cast da Stack a List così l'operatore << sia quello della superclasse
            if(s.isEmpty()){
                out << "empty stack" << endl;
                return out;
            }

            Node<T>* ptr = s.top();
            out << "Top= " << ptr->getVal() << endl;
            while(ptr) {
                out << ptr->getVal() << endl;
                ptr=ptr->getNext();
            }
            return out;
        }

        
};



#endif
