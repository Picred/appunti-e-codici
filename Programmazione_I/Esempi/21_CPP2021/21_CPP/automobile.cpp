#include <iostream>
#include <ctime>

#include "automobile.h"



Motore::Motore (int _potenza, int _kmAlLitro)
   {
      cout << "Costruttore Motore.." << endl;  
      potenza   = _potenza;
      kmAlLitro = _kmAlLitro;
      avviato   = false; 
   }

  
void Motore::accensione ()
   {
      if (avviato) 
         cout << "MOTORE : Il motore" 
              << " era già acceso!";
      else
         avviato = true;
   }
   
   
void Motore::spegnimento ()
   {
      if (!avviato) 
         cout << "MOTORE : Il motore"
              << " era già spento!";
      else
         avviato = false;
   }
 
   
bool Motore::spento() const
   {
      return !avviato;
   }
   
   
float Motore::consumoCarburantePerKm (int km) const
   {
      return (float)km / kmAlLitro;
   }
    
      
ostream &operator<< (ostream &stream, Motore m)
   {
         stream << "Il motore ha una potenza di " 
         << m.potenza << "KWh, e percorre " 
         << m.kmAlLitro 
         << "km con un litro di carburante."
         << "\nIl motore e' attualmente " 
         << (m.avviato ? "acceso":"spento") 
         << ".\n";

      return stream;     
   }


   
//*************************************************



Persona::Persona (string n, 
		  string c, 
                  short int anno,
                  bool guida)
   {
      nome = n;
      cognome = c;
      annoNascita = anno;
      allaGuida = guida;
   }
   
   
string Persona::getNominativo() const
   {
      return nome + " " + cognome;   
   }     
   
   
short int Persona::getEta() const
   {  

    time_t t = time(NULL);    struct tm *time;

    time = localtime(&t);
    int annoCorrente = 1900 + time->tm_year; 
    
    return  (annoCorrente - annoNascita);      
   }
      
      
void Persona::setAllaGuida (bool guida)
   {
      allaGuida = guida;                            
   }
   
   
bool Persona::getAllaGuida() const
   {
      return allaGuida;                              
   }
  
   
ostream &operator<< (ostream &stream, Persona p)
   {
       stream << p.getNominativo() 
              << ", di " << p.getEta() 
              << " anni, in posizione: "
              << (p.getAllaGuida() ? "dentro il veicolo!":
                                   "fuori dal veicolo!") 
              << endl;
              
       return stream;       
   }
   

   
//*************************************************



Automobile::Automobile (
                 string _targa,
                 string _modello,
                 bool _servosterzo,
                 int _potenzaMotore,
                 Persona *_guidatore)

   : motoreABenzina(_potenzaMotore)

   {                                                        
     cout << " Costruttore Automobile...\n";
   
     targa   = _targa;
     modello = _modello;
     contaKm = 0;
     servoSterzo = _servosterzo;
     serbatoioCarburante = new Serbatoio(70, 70, targa + modello);
     guidatore = _guidatore;    
   }


Automobile::~Automobile()
   {
     delete serbatoioCarburante;
     cout << "  ***** DISTRUTTO il serbatoio! *****\n\n";
   }

  
void Automobile::avviamento ()
   {    
      guidatore->setAllaGuida(true);
      motoreABenzina.accensione();
   }
   
   
void Automobile::spegnimento ()
   {
      motoreABenzina.spegnimento();
      guidatore->setAllaGuida(false);
   }
 
   
bool Automobile::percorri (int km)
   {
      if (motoreABenzina.spento())
        {
          cout << "Il motore è spento!\n";
          return false;         
        }
        
      float carburante = 
         motoreABenzina.consumoCarburantePerKm(km);  

      if (carburante >
          serbatoioCarburante->getQuantita())
        {
          cout << "Non c'è sufficiente " 
               << "carburante nel serbatoio!\n";
          return false;         
        }
        
      serbatoioCarburante->preleva(carburante);
      contaKm += km;  
      cout << "Percorsi km " << km << endl;

      return  true;
   }
 
   
void Automobile::rifornimentoCarburante (float carburante)
   {
      (*serbatoioCarburante).deposita(carburante);
   }
 
      
ostream &operator<< (ostream &stream, Automobile &a)
   {
       stream << "La " << a.modello 
              << " ha targa " << a.targa 
              << " con " << a.contaKm 
              << "km.\n"
              << *(a.serbatoioCarburante)
              << a.motoreABenzina
              << "Guidatore: " << *(a.guidatore)
              << endl;

      return stream;     
   }


   
//*************************************************




