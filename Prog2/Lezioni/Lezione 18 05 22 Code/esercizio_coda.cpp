/*Definire classe studente che ha le seguenti proprietà:
2 nome cognome eta media. costruttore;
3 simulare un appello con una coda. ovvero creare 4 studenti e inserirli in una coda simulando un esame*/
#include"queue.h"

#ifndef STIDENTE_H
#define STUDENTE_H

class Studente {
    private:
        string nome;
        string cognome;
        int eta;
        double media=0;

    public:
        Studente(string n,string c, int e) : nome(n),cognome(c),eta(e){}

        void setMedia(double d){media=d;}

        friend ostream& operator<<(ostream& out, Studente &s){
            out << "nome= " << s.nome << " cognome= " << s.cognome << " eta= " << s.eta << endl;
            return out;
        }
};

#endif

int main(){
    Queue<Studente> q;

    q.enqueue(Studente("n","c",20));
    q.enqueue(Studente("no","co",18));
    q.enqueue(Studente("nom","cog",19));
    q.enqueue(Studente("nome","cognome",21));

    //dequeue simula che uno studente fa l'esame
    cout << q << endl;

    //da rivedere
}