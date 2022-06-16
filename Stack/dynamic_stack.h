#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H
#include "stack_list.h"

template<class T>
class Stack : protected List<T>{
    private:
        int size=0;
    public:
        Stack() : List<T>() {}

        bool isEmpty(){
            return size==0;
        }

        Node<T>* top(){
            return this->head;
        }

        void push(T val){
            List<T>::insertHead(val);
            size++;
        }

        Node<T>* pop(){
            if(this->isEmpty()){
                cout << "Pila vuota, nulla da rimuovere!";
                return nullptr;
            }

            Node<T>* temp = top();
            List<T>::removeHead();
            size--;
            return temp;

        }

        friend ostream& operator<<(ostream& os, Stack<T>& pila){
            os  << "size= " << pila.size << endl << "----------------------" << endl;
            os << "Top= " << *(pila.top()) << endl;


            Node<T>* ptr=(pila.top())->getNext();

            while (ptr){
                os << *ptr << endl;
                ptr=ptr->getNext();
            }
            delete ptr;
            return os;
        }

};


#endif