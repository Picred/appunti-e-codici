#ifndef QUEUE_H
#define QUEUE_H

#include "dllist.h"
template<typename T>
class Queue : protected DLList<T>{
    private:
        int size=0;
    public:
        Queue() : DLList<T>() {}

    bool isEmpty(){
        return size==0;
    }

    void enqueue(T val){
        DLList<T>::insertTail(val);
        size++;
    }

    DLNode<T> dequeue(){
        if(isEmpty()){
            return 0;
        }

        DLNode<T> temp = *(DLList<T>::head);

        DLList<T>::removeHead();
        size--;
        return temp;
    }

    friend ostream& operator<< (ostream& os, Queue<T>& coda){
        os << "Head: " <<  coda.head << "\t Tail: " << coda.tail << endl;

        DLNode<T>* ptr = coda.head;

        while (ptr){
            cout << *ptr << endl;
            ptr=ptr->getNext();
        }
        return os;
    }
};

#endif