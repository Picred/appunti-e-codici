#ifndef LIST_H
#define LIST_H
#include "lnode.h"
#include <iostream>

using namespace std;

template<typename T>
class List{
    protected:
        Node<T>* head;

    public:
        List(){
            head = nullptr;
        }

        bool isEmpty(){ //controllo se la lista è vuota oppure no
            return head == nullptr;
        }
        void insert(T val){
            if(this->isEmpty()){
                head = new Node<T>(val);
            }
            return; //termino l'operazione
        }

        void insertHead(T val){
            if(this->isEmpty()){
                this->insert(val);
                return;
            }
            Node<T>* temp = new Node<T>(val);
            temp->next = head;
            this->head=temp;
        }

        void insertTail(T val){
            if(this->isEmpty()){
                this->insertHead(val);
                return;
            }

            Node<T>* ptr = head;
            while(ptr->getNext() != nullptr){
                ptr = ptr->getNext();
            }

            Node<T> *temp = new Node<T> (val);
            ptr->next=temp;
        }

        Node<T>* getHead() const {
            return head;
        }

        void insertInOrder(T val){//inserimento ordinato
            // if(isEmpty() || head->val >= val)
            if(this->isEmpty()){
                this->insertHead(val);
                return;
            }
            if(val <= head->val){ //valore da inserire val <= del valore di testa? allora inserisco in testa
                this->insertHead(val);
                return;
            }

            Node<T>* ptr = head; //per scorrere
            while(ptr->getNext() && (val >= ptr->val && val )) { //scorro la lista finchè il successivo non è nullptr e finchè 
                if(val <= ptr->next->val) //val <= del successivo di ptr
                    break;
                //altrimenti incremento il ptr e vedo il prossimo nodo
                ptr = ptr->getNext(); //avanzo il puntatore
            }
            if(! (ptr->next) ){
                this->insertTail(val);
                return;
            }

            Node<T>* toInsert= new Node<T>(val); //nuovo nodo da inserire
            toInsert->next = ptr->next; //
            ptr->next = toInsert;

        }

        void removeHead(){
            if(this->isEmpty()){
                cout << "empty list" << endl;
                return;
            } //altlrimenti
            Node<T>* temp=head; 
            head=head->next; //faccio scorrere la testa avanti

            delete temp; 
        }

        void removeTail(){
            if(this->isEmpty()){
                cout << "empty list" << endl;
                return;
            }
            
            Node<T>* cur = head; //current pointer
            Node<T>* prev = nullptr; //previous pointer
            while(cur->next->next){ 
                cur->next; //scorro la lista finchè arrivo alla fine
                prev=cur;
                cur=cur->next;
            }
            prev->next = nullptr;

        }

        void remove(T val){
            if(this->isEmpty()){
                cout << "empty list" << endl;
                return;
            }

            if(head->val == val){
                this->removeHead();
                return;
            }

            Node<T>* cur = head; //current pointer
            Node<T>* prev = nullptr; //previous pointer

            while((cur->next) && (cur->val!=val)){ 
                prev=cur;
                cur=cur->next;
            }

            if(cur->val != val){
                cout << "Element with value " << val << " not found!" << endl;
                return;
            }

            prev->next=cur->next;
            delete cur;
        }



        friend ostream& operator<< (ostream& out, const List<T> &list){
            out << "List head=" << list.head << endl;
            Node<T> *ptr = list.head;
            while (ptr != nullptr){
                out << "\t" << *ptr << endl;
                ptr=ptr->getNext(); //avanzamento di ptr
            }
            return out;
        }
};

#endif