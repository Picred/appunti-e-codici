#ifndef DL_NODE_H
#define DL_NODE_H

#include<iostream>

using namespace std;

template <typename T>
class DLNode{
    private:
    DLNode<T> *next;
    DLNode<T> *prev;
    T val;

    template <typename U>
    friend class DLList;

    public:
    DLNode(T val):val(val),next(nullptr),prev(nullptr){}

    DLNode<T>* getNext() const { //metodo utile per la stampa per l'accesso a next
            return this->next;
        }
    DLNode<T>* getPrev() const { //metodo utile per la stampa per l'accesso a next
        return this->prev;
            }

        friend ostream& operator << (ostream& out, const DLNode<T>  &node){
            out << "dlnode val " << node.val << "- next= " << node.next; //node.next indirizzo del next
            out << " prev= " << node.prev<< endl;
            return out;
        }
};

#endif