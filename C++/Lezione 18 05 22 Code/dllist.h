#ifndef DL_LIST_H
#define DL_LIST_H
#include "dlnode.h"

template <typename T>

class DLList{
    protected:
        DLNode<T> *head;
        DLNode<T> *tail;

    public:
        DLList(){
            head=nullptr;
            tail=nullptr;
        }

        friend ostream& operator<< (ostream& out, DLList<T>& list){
            out << "List head: " << list.head << " List tail: " << list.tail << endl;
            DLNode<T>* ptr = list.head;

            while (ptr){
                out << "\t" << *ptr << endl;
                ptr=ptr->getNext();
            }
            return out;
        } 
    
    bool isEmpty(){
        return (head == tail) && (tail== nullptr);
    }

    void insertHead(T val){
        if(this->isEmpty()){
            head = new DLNode<T>(val);
            tail = head;
            return;
        }

        DLNode<T> *toInsert = new DLNode<T>(val);
        toInsert->next = head;
        head->prev = toInsert;
        head=toInsert;
    }

    void insertTail(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }

        DLNode<T> *toInsert = new DLNode<T>(val);
        toInsert->prev = tail;
        tail->next = toInsert;
        tail = toInsert;
    }

    void removeHead(){
        if(this->isEmpty()){
            cout << "empty list" << endl;
            return;
        }
        //lista ha un solo nodo?
        if(head==tail){
            DLNode<T> *ptr=head;
            head=nullptr;
            tail=nullptr;
            delete ptr;
            return;
        }

        DLNode<T> *ptr=head;
        ptr->next->prev = nullptr; 
        head = ptr->next; //head->next

        // delete ptr;
    }

    void removeTail(){
        if(this->isEmpty()){
            cout << "empty list" << endl;
            return;
        }
        //lista ha un solo nodo?
        if(head==tail){
            DLNode<T> *ptr=head; // DLNode<T> *ptr=tail è uguale
            head=nullptr;
            tail=nullptr;
            delete ptr;
        }

        DLNode<T> *ptr = tail;
        ptr->prev->next=nullptr;
        tail = ptr->prev; //tail->prev

        delete ptr;
    }

    void remove(T val){
        if(this->isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        if(head->val==val){
            removeHead();
            return;
        }

        if(tail->val==val){
            removeTail();
            return;
        }
        // la lista ha più nodi? scorro la lista 

        DLNode<T>* ptr = head;

        while ((ptr->next) && (ptr->val!=val)){
            // ptr->prev = ptr; //non posso assegnare il predecessore al nodo stesso
            ptr=ptr->next;
        }

        if(ptr->val!=val){
            cout << "Element with value " << val << " not found!" << endl;
            return;
        }

        ptr->prev->next = ptr->next;
        ptr->next->prev=ptr->prev;


        delete ptr;
    }
    
    //implementazione personale di insertInOrder(T val)
    void insertInOrder(T val){
        if(this->isEmpty()){ //lista vuota? insertHead(val)
            this->insertHead(val);
            return;
        }

        if(head->val >= val){ //ordinamento crescente
            this->insertHead(val);
            return;
        }

        if(tail->val <= val){
            insertTail();
            return;
        }

        //altrimenti scorro la lista
        DLNode<T> *ptr=head;

        while ((val>=ptr->val) && (ptr->next)){
            if(val<= ptr->next->val)
                break;
            ptr=ptr->next;
        }
        

        DLNode<T> *toInsert = new DLNode<T>(val);
        toInsert->next = ptr->next;
        toInsert->prev=ptr;
        
        ptr->next->prev = toInsert; //aggiorno questo sennò perdo i successivi nodi
        ptr->next=toInsert;
        // ptr->prev=toInsert; errato

    }

    //implementazione modificatore d'accesso []

};

#endif