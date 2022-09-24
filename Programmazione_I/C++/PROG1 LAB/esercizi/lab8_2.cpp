/*
Definire una classe base Persona che contenga un’anagrafica generale comune a tutte le persone (nome, indirizzo, data di nascita, sesso, ecc.).
 Progettare una gerarchia di classi che contempli le seguenti classi: studente, impiegato, studente_impiegato. Scrivere un programma che legga 
 da file informazioni per un vettore di persone: a) generale; b) studenti; c) impiegati; d) studenti impiegati
*/

class Persona{
    private:
        string nome;
        string cognome;
        string indirizzo;
        short eta;
        char sesso;
    public:

};

class Generale: public Persona{
    
};

class Studente: public Persona{
    
};

class Impiegato: public Persona{
    
};

class Studente_Impiegato: public Persona{
    
};

int a=2.m; 