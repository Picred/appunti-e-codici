#include <cstring>
#include <iostream>

using namespace std;


class Messaggio
  {
    private :

       char * testo; // allocazione dinamica
       char * mittente; // idem 
       int    priorita;

       void Set (const char *, const char *, int);

    public:

       Messaggio (const Messaggio &);   // Costruttore di copia
       Messaggio (const char *, const char * = "", int = 0);

       void Virus (void);
       void Visualizza (void) const;

  }; //End class Messaggio


//alloca memoria dinamicamente
//usato anche dal costruttore di copia 
void Messaggio::Set (const char * t, const char * m, int p)
  {
    testo = new char [strlen(t)+1]; 
    mittente = new char [strlen(m)+1];
    strcpy (testo, t);
    strcpy (mittente, m);
    priorita = p;
  }


/* Costruttore di copia. Importante 
* per la gestione della memoria nel free store. 
* costruttore di copia di default opererebbe 
* ``memberwise'', quindi i due oggetti 
* userebbero le stesse aree di memoria
*/
Messaggio::Messaggio (const Messaggio & mess)
  {
    Set (mess.testo, mess.mittente, mess.priorita);
    cout << "Costruttore di copia\n";
  }

Messaggio::Messaggio (const char * t, const char * m, int p)
  {
    Set (t,m,p);
    cout << "Costruttore\n";
  }


//mescola un po il testo 
void Messaggio::Virus (void)
  {
    for (int i=0; i<strlen(testo); i++)   testo[i]++;
  }


void Messaggio::Visualizza (void) const
  {
    cout << "Mitt.: " << mittente << "  Mess.: " << testo
	 << "  Liv. priorita' : " << priorita << ", (memory address [testo]): " << (void *) testo << endl;
  }



int main (void)
  {
    Messaggio a("Buongiorno !!!", "Pippo",3);
    Messaggio b = a; // costruttore di copia..

    cout << "Prima ...\n";
    a.Visualizza ();
    b.Visualizza ();

    cout << "Dopo ...\n";
    a.Virus ();
    a.Visualizza ();
    b.Visualizza ();

    cout << "Infine ...\n";
    b = a; // avviene una copia membro a membro 
    // Non viene chiamato il costruttore di copia, questo viene usato solo per le inizializzazioni.
    a.Visualizza ();
    b.Visualizza ();

    // Domanda : Dove viene liberata la memoria allocata precedentemente ?
  
   return 0;
  }
