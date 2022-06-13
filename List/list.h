#ifndef LIST_H
#define LIST_H
#include "lnode.h"

template<typename T>
class List {
    private:
        Node<T> *head;
    public:
        List() {
            head=nullptr;
        }

    //verifico lista vuota, quando head ==nullptr
    bool isEmpty(){
        return head==nullptr;
    }
#pragma region "Inserimento"
    //inserimento di un valore val
    void insert(T val){
        //se la lista è vuota inserisco in testa
            if(this->isEmpty()){
                head=new Node<T>(val);
            }
        return;
    }

    //inserimento in testa
    void insertHead(T val){
        if(this->isEmpty()){
            head=new Node<T>(val);
            return;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next=head;
        this->head=temp;
    }

    //inserimento in coda
    void insertTail(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }
        Node<T>* ptr = head;
        while(ptr->next){
            ptr=ptr->getNext();
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next=temp;
    }

    //inserimento in modo ordinato crescente
    void insertCrescente(T val){
        if((this->isEmpty()) || (val<=head->val)){
            this->insertHead(val);
            return;
        }

        //se la lista non è vuota scorro finchè non trovo la posizione esatta
        Node<T>* ptr=head;

        while( (ptr->next) && (ptr->val <= val)){
            if(ptr->next->val > val){
                break;
            }
            ptr=ptr->getNext();
        }

        //verifico se sono arrivato alla coda
        if(!ptr->next){
            this->insertTail(val);
            return;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next=ptr->next;
        ptr->next=temp;
    }

    //inserimento in modo decrescente
    void insertDecrescente(T val){
        if((this->isEmpty()) || (val>=head->val)){
            this->insertHead(val);
            return;
        }

        //scorro la lista
        Node<T>* ptr=head;
        while((ptr->next) && (ptr->val>=val)){
            if(ptr->next->val < val){
                break;
            }
            ptr=ptr->getNext();
        }

        Node<T>* temp = new Node<T>(val);
        temp->next=ptr->next;
        ptr->next=temp;
    }
#pragma endregion

#pragma region "Eliminazioni"
    //eliminazione nodo di testa
    void removeHead(){
        if(this->isEmpty()){
            cout << "Lista vuota, nulla da rimuovere :-( " << endl;
            return;
        }

        Node<T>* temp=head; //serve per non perdere il riferimento, quindi poter deletare
        head=head->next;
        delete temp;
    }

    //eliminazione nodo di coda
    void removeTail(){
        if(this->isEmpty()){
            cout << "Lista vuota, nulla da rimuovere :-( " << endl;
            return;
        }

        //scorro per arrivare alla coda
        Node<T>* cur=head;
        Node<T>* prev=nullptr;

        while(cur->next){
            prev=cur;
            cur=cur->getNext();
        }

        prev->next=nullptr;
        delete cur;
    }

    //eliminazione di un nodo specifico
    void remove(T val){
        if(this->isEmpty()){
            cout << "Lista vuota, nulla da rimuovere :-( " << endl;
            return;
        }

        //head è il valore da rimuovere?
        if(head->val == val){
            removeHead();
            return;
        }

        Node<T>* cur = head;
        Node<T>* prev=nullptr;

        while(cur->next){
            if(cur->val==val){
                break;
            }
            prev=cur;
            cur=cur->next;
        }

        if(!(cur->next) && (cur->val != val)){
            cout << "Elemento non trovato in lista" << endl;
            return;
        }

        prev->next=cur->next;
        delete cur;
    }
#pragma endregion
    //stampa di una lista
    friend ostream& operator<<(ostream& os, List<T>& list){
        if(list.isEmpty()){
            os << "EMPTY LIST D:";
            return os;
        }
        os << "List Head: " << list.head << endl;

        Node<T>* ptr=list.head;

            while(ptr != nullptr){
                os << *ptr << endl; 
                ptr=ptr->getNext();
            } 
        return os;
    }

};

#endif