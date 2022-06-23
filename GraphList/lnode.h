#ifndef LNODE_H
#define LNODE_H

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

        T getVal(){
            return this->val;
        }

    friend ostream& operator<< (ostream& os, Node<T>& node){
        // os << "node val:" <<
        os <<  node.val; 
        // os << " " << &node <<  "\tnext=" << node.next;
        return os;
    }
};

#endif