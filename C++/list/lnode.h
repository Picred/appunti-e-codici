#ifndef LNODE_H
#define LNODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node{
    private:
        T val;
        Node<T>* next;

        template <typename U>
            friend class List;
        
    public:
        Node<T>(T valore) : val(valore){
            next=nullptr;
        }

        friend ostream& operator<< (ostream& os, Node<T>& node){
            os << "Node Val: " << node.val;
            os << " Node Next: " << node.next;

            os << endl;
            return os;
        }

        Node<T>* getNext() const{
            return this->next;
        }
};


#endif