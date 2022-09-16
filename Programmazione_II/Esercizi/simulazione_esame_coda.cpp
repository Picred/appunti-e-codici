/*1. Definire classe studente che ha le seguenti proprietà:
- nome cognome eta media. definire il costruttore;
- simulare un appello con una coda. ovvero creare 4 studenti e inserirli in una coda simulando un esame e dandone la media
*/

#include <iostream>
using namespace std;

template<typename T>
class DLNode{
    private:
        T val;
        DLNode<T>* next;
        DLNode<T>* prev;

        template<typename U>
        friend class DLList;

    public:
        DLNode(T val) : val(val){
            next=nullptr;
            prev=nullptr;
        }

        DLNode<T>* getNext(){
            return this->next;
        }

        DLNode<T>* getPrev(){
            return this->prev;
        }

        T getVal(){
            return this->val;
        }

        friend ostream& operator<<(ostream& os, DLNode<T>& node){
            os << (node.val);
            return os;
        }
};


template <typename T>
class DLList {
    protected:
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
        // os << "List Head: " << list.head;
        // os << "\tList Tail: " << list.tail << endl;

        DLNode<T>* ptr=list.head;
            while(ptr != nullptr){
                os << *ptr << "\tMedia esame: "<<  ptr->getVal().getMedia()<< endl; 
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


template<typename T>
class Queue : protected DLList<T>{
    private:
        int size=0;
    public:
        Queue() : DLList<T>() {}

    bool isEmpty(){
        return size==0;
    }

    void enqueue(T val){
        DLList<T>::insertTail(val);
        size++;
    }

    T dequeue(){
        if(isEmpty()){
            return 0;
        }

        T temp = (DLList<T>::head)->getVal();

        DLList<T>::removeHead();
        size--;
        return temp;
    }

    friend ostream& operator<< (ostream& os, Queue<T>& coda){
        // os << "Head: " <<  coda.head << "\t Tail: " << coda.tail << endl;

        DLNode<T>* ptr = coda.head;

        while (ptr){
            cout << *ptr << endl;
            ptr=ptr->getNext();
        }
        return os;
    }
};

class Studente{
    private:
        string nome;
        string cognome;
        double media=0.0;
    public:
        Studente(string n="", string c="", double m=0.0) : nome(n), cognome(c){}

        
        void setMedia(double m){
            this->media=m;
        }   

        double getMedia(){
            return this->media;
        }

        friend ostream& operator<<(ostream& os, Studente& s){
            os << s.nome << " " << s.cognome;
            return os; 
        }
};

int main(){
    int n_studenti;

    cout << "Quanti studenti si presentano all'esame (max 10)?: ";
    cin >> n_studenti;
    
    if(n_studenti>10){
        cerr << "Numero di studenti troppo elevato!" << endl;
        return -1;
    }
    Queue<Studente*> coda_studenti;

    string nomi[10];
    string cognomi[10];

    for(int i=0; i<10; i++){
        switch (i){
            case 0: nomi[i] = "Mattia"; cognomi[i] = "FIORE"; break;
            case 1: nomi[i] = "Francesco"; cognomi[i] = "GRASSI"; break;
            case 2: nomi[i] = "Lorenzo"; cognomi[i] = "FONTANA"; break;
            case 3: nomi[i] = "Sara"; cognomi[i] = "VIOLA"; break;
            case 4: nomi[i] = "Matteo"; cognomi[i] = "MILANI"; break;
            case 5: nomi[i] = "Andrea"; cognomi[i] = "SANTORO"; break;
            case 6: nomi[i] = "Riccardo"; cognomi[i] = "VILLA"; break;
            case 7: nomi[i] = "Giorgia"; cognomi[i] = "MARTINI"; break;
            case 8: nomi[i] = "Chiara"; cognomi[i] = "FERRARA"; break;
            case 9: nomi[i] = "Davide"; cognomi[i] = "ORLANDO"; break;
        }
    }

    Studente* temp;
    int i=0;
    DLList<Studente> esaminati;

    cout << "Gli studenti in coda per l'esame sono " << n_studenti<< endl;

    while(n_studenti>0){
        temp=new Studente(nomi[i], cognomi[i++]);
        n_studenti--;
        coda_studenti.enqueue(temp);
    }

    int dim=0;
    while(!coda_studenti.isEmpty()){

        Studente* attuale = (coda_studenti.dequeue());
        cout << "Stiamo esaminando " <<  *attuale  << " ......\n";
        // system("pause");

        cout << "\nDecidere la media dello studente appena esaminato: ";
        double media;
        cin>>media;

        attuale->setMedia(media);
        esaminati.insertHead(*attuale);
    }

    
    cout << "\nSono stati esaminati tutti gli studenti in coda. Vediamo le loro medie:\n" << esaminati << endl;
    
    return 0;
}