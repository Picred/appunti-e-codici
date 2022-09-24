#include <cstring>
#include <iostream>

using namespace std;

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
    cout << "Costruttore : " << testo << '\n';
  }


Messaggio::~Messaggio ()
  {
    cout << "Distruttore : " << testo << '\n';
    delete [] testo;
    delete [] mittente;
  }


void Messaggio::Visualizza (void) const
  {
    cout << "Mitt.: " << mittente << "  Mess.: " << testo
	 << "  Liv. priorita' : " << priorita << '\n';
  }



Messaggio a("Esterno", "ext",1);
static Messaggio b("Statico esterno", "st_ext",2);


int main ()
  {
    cout << "Inizio del main\n";

    Messaggio c("Interno", "int",3);
    static Messaggio d("Statico interno", "st_int",4);

    Messaggio *ptr;
    ptr = new Messaggio ("Dinamico", "din",5);
    delete ptr; // distruttore!

    cout << "Fine del main\n";

    return 0;
  }


