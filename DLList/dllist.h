#ifndef DLLIST_H
#define DLLIST_H

#include "dlnode.h"

template <typename T>
class DLList {
    private:
        DLNode<T>* head;
        DLNode<T>* tail;

    public:
        DLList(){
            head=nullptr;
            tail=nullptr;
        }

    bool isEmpty(){
        return (head==nullptr) && (tail==nullptr);
    }

    friend ostream& operator<<(ostream& os, DLList<T>& list){
        if(list.isEmpty()){
            os << "EMPTY LIST D:";
            return os;
        }
        os << "List Head: " << list.head;
        os << "\tList Tail: " << list.tail << endl;

        DLNode<T>* ptr=list.head;

            while(ptr != nullptr){
                os << *ptr << endl; 
                ptr=ptr->getNext();
            } 
        return os;
    }

    //inserimento in testa
    void insertHead(T val){
        if(this->isEmpty()){
            head=new DLNode<T>(val);
            tail=head;
            return;
        }

        DLNode<T>* temp = new DLNode<T>(val);
            head->prev=temp;
            temp->next=head;
            head=temp;
    }

    //inseriento in coda
    void insertTail(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }

        //prendo il puntatore alla coda
        DLNode<T>* temp = new DLNode<T>(val);
        temp->prev=tail;
        tail->next=temp;
        tail=temp; //la nuova coda
    }

    void insertCrescente(T val){
        if(this->isEmpty() || val<=head->val){
            insertHead(val);
            return;
        }

        if(tail->val <= val){
            insertTail(val);
            return;
        }

        //scorro la lista e trovo la posizione
        DLNode<T>* ptr=head;

        while((ptr->next)&& (val>=ptr->val)){
            if(val<=ptr->next->val){
                break;
            }
            ptr=ptr->getNext();
        }

        

        DLNode<T>* temp = new DLNode<T>(val);
        temp->next=ptr->next;
        temp->prev=ptr;
        ptr->next->prev=temp;
        ptr->next=temp;
    }

    void insertDecrescente(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }

        if(val>=head->val){
            this->insertHead(val);
            return;
        }

        if(val<=tail->val){
            this->insertTail(val);
            return;
        }

        //scorro la lista
        DLNode<T>* ptr=head;

        while((ptr->next) && (val <= ptr->val)){
            if(val>ptr->next->val){
                break;
            }
            ptr=ptr->getNext();
        }

        DLNode<T>* temp=new DLNode<T>(val);

        temp->next=ptr->next;
        temp->prev=ptr;
        ptr->next->prev = temp;
        ptr->next = temp;
    }


    void removeHead(){
        if(this->isEmpty()){
            cout << "lista vuota, nulla da rimuovere";
            return;
        }

        //verifico se ho SOLO la testa

        if(head==tail){
            DLNode<T>* temp = head;
            tail=nullptr;
            head=nullptr;
            delete temp;
            return;
        }

        DLNode<T>* temp=head;
        temp->next->prev=nullptr;
        head=head->next;
        delete temp;
    }

    void removeTail(){
        if(this->isEmpty()){
            cout << "lista vuota, nulla da rimuovere";
            return;
        }

        if(head==tail){
            this->removeHead();
            return;
        }

        DLNode<T>* temp=tail;
        temp->prev->next=nullptr;
        tail=tail->prev;
        delete temp;
    }

    void remove(T val){
        if(this->isEmpty()){
            cout << "lista vuota, nulla da rimuovere";
            return;
        }

        if(val==head->val){
            this->removeHead();
            return;
        } else if(val==tail->val){
            this->removeTail();
            return;
        }

        DLNode<T>* ptr = head;

        while(ptr->next && ptr->val!=val){
            ptr=ptr->getNext();
        }

        if(ptr->val != val && ptr->next){
            cout << "Elemento non trovato in lista";
        }

        ptr->next->prev=ptr->prev;
        ptr->prev->next=ptr->next;
        delete ptr;

    }

};


#endif