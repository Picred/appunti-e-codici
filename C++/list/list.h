#ifndef LIST_H
#define LIST_H

#include "lnode.h"

using namespace std;

template<typename T>
class List{
    private:
        Node<T> *head;

    public:
        List() {
            head=nullptr;
        }

    //controllo lista vuota
    bool isEmpty(){
        return head==nullptr;
    }

    //inserimento in testa
    void insertHead(T val){
        if(this->isEmpty()){
            head=new Node<T>(val);
            return;
        }
        //lista non vuota?
        Node<T>* temp= new Node<T>(val);
        temp->next=head;
        this->head=temp;
    }

    //eliminazione nodo testa
    void removeHead(T val){
        if(this->isEmpty()){
            cout << "Lista vuota, nulla da rimuovere" << endl;
            return;
        }
        Node<T>* temp = head;
        head=head->next;
        delete temp;
        }



    friend ostream& operator<<(ostream& os, List<T>& list){
        os << "List Head: " << list.head << endl;

        Node<T> *ptr = list.head;
        while (ptr != nullptr){
            os << *ptr << " - ";  
            ptr=ptr->getNext();
        }
        os << endl;
        return os;
    }
};


#endif
