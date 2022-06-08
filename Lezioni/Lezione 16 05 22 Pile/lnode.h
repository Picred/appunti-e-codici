#ifndef LNODE_H
#define LNODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T val;
        Node<T>* next;

        template<typename U> // U parametro non usato, serve solo per distinguere i template di lista e questa riga
        friend class List; 

    public:
        Node(T val) : val(val){
            next=nullptr;
        }

        Node<T>* getNext() const { //metodo utile per la stampa per l'accesso a next
            return this->next;
        }

        T getVal(){
            return val;
        }
        
        friend ostream& operator << (ostream& out, const Node<T>  &node){
            out << "node val " << node.val << "- next= " << node.next; //node.next indirizzo del next
            return out;
        }
};

#endif