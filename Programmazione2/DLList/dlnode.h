#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>
using namespace std;

template<typename T>
class DLNode{
    private:
        T val;
        DLNode<T>* next;
        DLNode<T>* prev;

        template<typename U>
        friend class DLList;

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
            os << "node val:" << node.val << " " << &node <<  "\tnext=" << node.next << "\tprev=" << node.prev;
            return os;
        }
};

#endif