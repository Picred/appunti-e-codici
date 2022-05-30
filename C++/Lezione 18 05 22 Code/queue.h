#ifndef QUEUE_H
#define QUEUE_H
#include "dllist.h"
#include<iostream>

using namespace std;

template <typename T>
class Queue : protected DLList<T>{
    protected:
        int size=0;
    public:
        Queue() : DLList<T>(){}

        void enqueue(T val){
            DLList<T>::insertTail(val);
            size++;
        }
    
        DLNode<T> dequeue(){

            if(isEmpty()){
                return 0;
            }

            DLNode<T> ptr= *(DLList<T>::head); //prendo un riferimento prima di rimuovere cosi lo restituisco
            DLList<T>::removeHead();
            size--;
            return ptr;
        }

        bool isEmpty(){
            return size==0;
        }

        friend ostream& operator<<(ostream& out, Queue<T>& queue){
            out << "Queue starting at " << &(queue.head) << "\n\n";
            DLNode<T> *ptr= queue.head;
            while(ptr){
                out << *ptr << endl;
                ptr=ptr->getNext();
            }
            return out;
        }
};

#endif