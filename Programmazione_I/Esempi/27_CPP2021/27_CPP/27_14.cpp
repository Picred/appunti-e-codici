#include  <cstring>
#include <iostream>

using namespace std;

//DISTRUTTORE
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
       ~Messaggio ();

       void Virus (void);
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


Messaggio::~Messaggio ()
  {
    cout << "Distruttore : " << testo << '\n';
    delete [] testo;
    delete [] mittente;
  }


void Messaggio::Virus (void)
  {
    for (int i=0; i<strlen(testo); i++)   testo[i]++;
  }


void Messaggio::Visualizza (void) const
  {
    cout << "Mitt.: " << mittente << "  Mess.: " << testo
	 << "  Liv. priorita' : " << priorita << '\n';
  }


Messaggio  Identita (const Messaggio mess)
  {
   //  Messaggio aux("aux", "aaa",4);
   // return aux;       

    return mess;
  }


int main ()
  {
    Messaggio a("Buongiorno !!!", "Pippo",3);
    Messaggio b = a;

    cout << "Prima ...\n";
    a.Visualizza ();
    b.Visualizza ();

    cout << "Dopo ...\n";
    a.Virus ();
    a.Visualizza ();
    b.Visualizza ();

    cout << "INIZIO CHIAMATA metodo\n";
    Identita(a);
    cout << "FINE CHIAMATA metodo\n";

    a.Visualizza ();
    b.Visualizza ();

    return 0;
  }


//*****************************************************************
//*****************************************************************
