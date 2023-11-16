#include "persona.h"
using namespace std;
#ifndef STUDENTE_H
#define STUDENTE_H

class Studente : protected Persona{ //da public Persona, ho modificato in protected Persona
    std::string matricola;

    public:
        Studente() : Persona(){}
        Studente(string n, string c, int e, string email, string m) : Persona(n,c,e,email), matricola(m) {}
        Studente(const Studente &s): Persona(s){
            matricola = s.matricola;
            // temperatura = new int [100];
        } 

        void print(){
            Persona::print();
            cout << " la mia matricola e' " << matricola << endl;
        }
};

#endif