/*Aggiungere alla classe List un contatore che tenga conto del numero
 di elementi (nodi) inseriti e quindi della dimensione della lista 
Il contatore va aggiunto alla classe “List”*/

/*Aggiungere un puntatore alla coda e modificare 
tutti i metodi che accedono alla coda*/


/*Implementare l’operatore di accesso ( [] ) sfruttando la conoscenza 
del numero di elementi inseriti (potrebbe richiedere modifiche al nodo)*/

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
        os << "node val:" << node.val << " " << &node <<  "\tnext=" << node.next;
        return os;
    }
};


template<typename T>
class List {
    private:
        Node<T> *head;
        Node<T>* tail;
        int size;
    public:
        List() {
            this->head=nullptr;
            this->tail=nullptr;
            this->size=0;
        }

    //verifico lista vuota, quando head ==nullptr
    bool isEmpty(){
        return ((head==nullptr) && (tail==nullptr));
    }

    Node<T>* getHead(){
        return this->head;
    }
#pragma region "Inserimento"
    //inserimento di un valore val
    void insert(T val){
        //se la lista è vuota inserisco in testa
            if(this->isEmpty()){
                head=new Node<T>(val);
                this->size++;
            }
        return;
    }

    //inserimento in testa
    void insertHead(T val){
        if(this->isEmpty()){
            head=new Node<T>(val);
            this->size++;
            return;
        }

        if(tail==nullptr){
            tail=head;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next=head;
        this->head=temp;
        this->size++;
    }

    //inserimento in coda
    void insertTail(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }
        // Node<T>* ptr = head;
        // while(ptr->next){
        //     ptr=ptr->getNext();
        // }

        Node<T>* temp = new Node<T>(val);
        tail->next=temp;
        tail=tail->next;
        this->size++;
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
        this->size++;
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
        this->size++;
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
        this->size--;
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
        tail=prev;
        delete cur;
        this->size--;
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

        if(tail->val == val){
            removeTail();
            return;
        }

        Node<T>* cur = head;
        Node<T>* prev= nullptr;

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
        this->size--;
    }
#pragma endregion
    //stampa di una lista
    friend ostream& operator<<(ostream& os, List<T>& list){
        if(list.isEmpty()){
            os << "EMPTY LIST D:";
            return os;
        }
        os << "List Head: " << list.head << " List size=" << list.size;
        os << " List Tail: " << list.tail << endl;

        Node<T>* ptr=list.head;

            while(ptr != nullptr){
                os << *ptr << endl; 
                ptr=ptr->getNext();
            } 
        return os;
    }

    
    T operator[](int i){
        if(this->isEmpty()){
            cout << "Lista vuota, elemento non trovato!" << endl;
            return -1;
        }

        if(i>=this->size){
            cout << "La lista non ha piu' di " << this->size << " elementi!" << endl;
            return -1;
        }

        Node<T>* ptr=this->head;

        int count=0;

        while(ptr && count!=i){
            if(i==count){
                break;
            }
            ptr=ptr->getNext();
            count++;
        }

        return ptr->val;
    }

};

int main() {
    List<int> list;

    cout << "----------Inserisco in testa 50 40 30 20 10 0 e stampo----------" << endl;

    list.insertHead(50);
    list.insertHead(40);
    list.insertHead(30);
    list.insertHead(20);
    list.insertHead(10);
    list.insertHead(0);

    cout << list << endl;

    system("pause");

    cout << "----------Inserisco in coda 60 70 e stampo----------" << endl;

    list.insertTail(60);
    list.insertTail(70);

    cout << list << endl;
    system("pause");
    system("cls");
    cout << "----------Inserisco in modo crescente 37 e 8 in modo decrescente e stampo----------" << endl;

    list.insertCrescente(37);
    list.insertDecrescente(8);

        cout << list << endl;
    system("pause");
    cout << "----------Elimino due teste,una coda e il nodo 40 e stampo----------" << endl;

    list.removeHead();
    list.removeHead();
    list.removeTail();
    list.remove(40);

    cout << list;

    system("pause");

    cout << "----------Provo ad accedere all'elemento list[3]----------" << endl;

    cout << "L'elemento list[3] e' " << list[3] << endl;

}