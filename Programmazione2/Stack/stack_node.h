#ifndef STACK_NODE_H
#define STACK_NODE_H

#include <iostream>
using namespace std;

template<typename T>
class Node{
    private:
        T val;
        Node<T>* next;

        template <typename U>
        friend class List;
    public:
        Node(T val) : val(val){
            next=nullptr;
        }

        Node<T>* getNext(){
            return this->next;
        }

    friend ostream& operator<< (ostream& os, Node<T>& node){
        os << "node val:" << node.val << " " << &node <<  "\tnext=" << node.next;
        return os;
    }
};

#endif