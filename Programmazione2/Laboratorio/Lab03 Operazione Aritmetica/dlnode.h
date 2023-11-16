#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>
using namespace std;

template<typename T>
class DLNode{
    protected:
        T val;
        DLNode<T>* next;
        DLNode<T>* prev;

        template<typename U>
        friend class DLList;

        template<typename S>
        friend class Queue;

    public:
        DLNode(T val) : val(val){
            next=nullptr;
            prev=nullptr;
        }

        DLNode<T>* getNext(){
            return this->next;
        }

        DLNode<T>* getPrev(){
            return this->prev;
        }

        friend ostream& operator<<(ostream& os, DLNode<T>& node){
            os << "val:" << node.val;
            return os;
        }
};

#endif