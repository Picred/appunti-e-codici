/*Fare overload dell’operatore << specifica per 
una pila quindi una stampa più “bella”*/

#include <iostream>

using namespace std;

#pragma region "INCLUDES"
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
        os << "node val:" << node.val << " " << &node <<  "\tnext=" << node.next;
        return os;
    }
};

template<typename T>
class List {
    protected: //private->protected per permettere l'accesso dalla classe Stack
        Node<T> *head;
    public:
        List() {
            head=nullptr;
        }

    //verifico lista vuota, quando head ==nullptr

    bool isEmpty(){
        return head==nullptr;
    }

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

    

};

#pragma endregion


template<class T>
class Stack : protected List<T>{
    private:
        int size=0;
    public:
        Stack() : List<T>() {}

        bool isEmpty(){
            return size==0;
        }

        Node<T>* top(){
            return this->head;
        }

        void push(T val){
            List<T>::insertHead(val);
            size++;
        }

        Node<T>* pop(){
            if(this->isEmpty()){
                cout << "Pila vuota, nulla da rimuovere!";
                return nullptr;
            }

            Node<T>* temp = top();
            List<T>::removeHead();
            size--;
            return temp;

        }

        friend ostream& operator<<(ostream& os, Stack<T>& pila){
            os  << "Stack Size = " << pila.size << endl << "----------------------" << endl;
            os << "Top = " << pila.top()->getVal() << endl;


            Node<T>* ptr=(pila.top());

            while (ptr){
                os  << "" << ptr->getVal() << endl;
                ptr=ptr->getNext();
            }
            delete ptr;
            return os;
        }

};

int main(){
    Stack<int> pila;

    pila.push(4);
    pila.push(814);
    pila.push(99);

    cout << pila;

    pila.pop();

    cout << "\n-----Faccio un pop()-----\n"  << pila;
}