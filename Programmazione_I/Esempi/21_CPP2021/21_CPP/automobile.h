#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>
#include "serbatoio.h"

using namespace std;



//************
class Motore {
//************

public:  

   Motore (int _potenza, int _kmAlLitro=12);
   
   void accensione();  
   void spegnimento();  
   bool spento() const;
   float consumoCarburantePerKm (int km) const;
  
   friend ostream &operator<< (ostream &stream, Motore m);
   

private: 
         
   int  potenza;
   int  kmAlLitro;
   bool avviato;      
 
}; // End class Motore




//*************
class Persona {
//*************

public:  

   Persona (string, string, short int, bool=false);
   
   string getNominativo() const;  
   short int getEta() const;
   void setAllaGuida (bool);
   bool getAllaGuida() const;  
   
   friend ostream &operator<< (ostream &stream, Persona p);
   

private: 
         
   string nome;
   string cognome;
   short int annoNascita;
   bool allaGuida;
 
}; // End class Persona




//****************
class Automobile {
//****************

public:  

   Automobile (string _targa,
               string _modello,
               bool _servosterzo,
               int potenzaMotore,
               Persona *_guidatore);
   ~Automobile();

   void avviamento ();
   void spegnimento ();
   bool percorri (int km);
   void rifornimentoCarburante (float carburante);
   
   friend ostream &operator<< (ostream &stream, Automobile &a);
        // Il secondo parametro "Automobile &a" è passato 
        // per indirizzo perché non è stato definito il 
        // costruttore di copie 

private: 
         
   string targa;
   string modello;
   int contaKm;
   bool servoSterzo;
   Motore motoreABenzina;
   Serbatoio *serbatoioCarburante;   
   Persona *guidatore;
    
}; // End class Automobile


#endif
