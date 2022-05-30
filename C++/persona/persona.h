#ifndef PERSONA_H
#define PERSONA_H 

#include <iostream>

using namespace std;


class Persona {
    private:
        string nome;
        string cognome;
        int eta=0; //valore di default che posso specificare in caso di chiamata del costruttore di default
        string email;
        int *temperatura;
    public:
        Persona(){
            temperatura=new int[100];
        }

        Persona(string n, string c, int e, string mail){
            nome=n;
            cognome=c;
            eta=e;
            email=mail;
            temperatura=new int[100];
        }

        Persona(const Persona &p){
            nome=p.nome;
            cognome=p.cognome;
            eta=p.eta;
            email=p.email;
            temperatura=new int[100];          
        }

        void print(){ //funzione inline. piu veloce a tempo di esecuzione
            cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email << endl;
        }

        void print2(); // funziona implementata esternamente, quindi non inline. si effettua una call e una return

        ~Persona(){ //distruttore
            delete[] temperatura; //la delete si fa perchè si tratta di allocazione dinamica. In caso di statica non era necessario visto che il compilatore
                                    //dealloca automaticamente la memoria statica
        }
};

void Persona::print2(){
            cout << "Mi chiamo " << nome << " " << cognome << ", ho " << eta << " anni e la mia email e' " << email << endl;
        }

#endif