#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

#include<string>

class Persona {
    private:
        string nome;
        string cognome;
        int eta;
    public:
        Persona(string, string, int);
        void saluta();
        void dici_nome();
        void dici_eta();
        void invecchia();
        void saluta_persona(Persona p2);

        void setNome(string);
        void setCognome(string);
        void setEta(int);

        string getNome();
        string getCognome();
        int getEta();
};

#endif