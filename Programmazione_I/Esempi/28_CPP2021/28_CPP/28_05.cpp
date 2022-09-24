//OPERATORE ``=''

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//OPERATORE = 
class Messaggio
  {
    private :

       char * testo;
       char * mittente;
       int    priorita;

       void Set (const char *, const char *, int);

    public:

       Messaggio (const char *, const char * = "", int = 0);
       Messaggio (const Messaggio &);   // Costruttore di copia
       ~Messaggio (); // distruttore, necessario!

       Messaggio &  operator = (const Messaggio &);
  
       void Visualizza (void) const;

  }; //End class Messaggio


void Messaggio::Set (const char * t, const char * m, int p)
  {
    testo = new char [strlen(t)+1];
    mittente = new char [strlen(m)+1];
    strcpy (testo, t);
    strcpy (mittente, m);
    priorita = p;
  }


//COSTRUTTORE DI COPIA
Messaggio::Messaggio (const Messaggio & mess)
  {
    Set (mess.testo, mess.mittente, mess.priorita);
    cout << "Costruttore di copia\n";
  }


//COSTRUTTORE
Messaggio::Messaggio (const char * t, const char * m, int p)
  {
    Set (t,m,p);
  }


//DISTRUTTORE
Messaggio::~Messaggio ()
  {
    cout << "DIS" << endl;                  
    delete [] testo; //deallocazione memoria
    delete [] mittente;
  }


// - LA & È PRESENTE SOLO PER RAGIONI DI EFFICIENZA
// - il primo const è presente per evitare modifiche 
//   all'operando di sinistra nel main, il motivo si evince nel main
// - il secondo const è presente per evitare modifiche 
//   all'operando di destra da parte del metodo sottostante

//Operatore binario, membro. this e' argomento "implicito"
// a = b e' come a.operator=(b)
 Messaggio & Messaggio::operator = (const Messaggio & mess) 
  {
    cout << "Overload = \n";
    if (this != & mess) // a = a
       {
	     this->~Messaggio ();   // Perché qui è necessaria la "delete" delle variabili? 
				//altrimenti memory leak! 
	     Set (mess.testo, mess.mittente, mess.priorita);
       }   
    return *this;
  }


void Messaggio::Visualizza (void) const
  {
    cout << "Mitt.: " << mittente << "  Mess.: " << testo
	 << "  Liv. priorita' : " << priorita << '\n';
  }


int main ()
  {
    Messaggio a("Primo", "abc", 3);
    Messaggio b = a; // costruttore di copia
    Messaggio c("Secondo", "def", 1);

    cout << "\n";

   //come scrivere a = (b=c), prima b=c, poi a = b
    a = b = c; // operator '=': prima b=c, poi a=b
    
   // (b=a) = c; 
   // Errore : l'uso di "const" impedisce la compilazione;
   // l'oggetto (b=a) è "const" in quanto alias "const &" e pertanto 
   // può richiamare soltanto metodi "const", è lo stesso di 
   // const Messaggio &y = a;
   // y.metodo();   compila solo se metodo() è pubblico e "const".
 
   // SE TOGLIESSI IL "CONST" AVREI A="PRIMO" E B=C="SECONDO"
    
    a.Visualizza();
    b.Visualizza();
    c.Visualizza();
    cout << "\n\n";
    
//    system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
