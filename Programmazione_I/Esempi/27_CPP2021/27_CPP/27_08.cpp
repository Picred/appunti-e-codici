#include <cstring>
#include <iostream>

using namespace std;

class Complex
  {
    private :

       float Re;
       float Im;

    public:

       Complex (float, float);

       void Visualizza (void) const;

  }; //End class Complex


//Lista di inizializzazione 
Complex::Complex (float a, float b) :
	 Re{a}, Im{b}
  {
    cout << "Costruttore Complex\n";
  }


void Complex::Visualizza (void) const
  {
    cout << Re << "+" << Im << "i\n";
  }


class Coppia
  {
    private :

// non esiste costruttore di default (o argomenti standard) per Complex! 
       Complex primo; 

// dunque il costruttore della classe Coppia deve occuparsi della inizializzazione di primo e secondo
       Complex secondo; 

    public :

       Coppia (float, float);
       void Visualizza (void) const;

  };  //End class Coppia

Coppia::Coppia (float a, float b) :primo{a,b}, secondo{a+1, b+1}
  {
    cout << "Costruttore Coppia\n";
  }


void Coppia::Visualizza (void) const
  {
    primo.Visualizza ();
    secondo.Visualizza ();
    cout << '\n';
  }


// DOMANDE :
//   2) Cosa accade se si elimina un'occorrenza nella lista
//      di inizializzazione del costruttore "Coppia" ?
//   3) All'interno di una funzione, e' possibile richiamare
//      un costruttore relativamente ad un oggetto ?


int main ()
  {
    Coppia c(2.4, 3.7);

    c.Visualizza ();

//    system("PAUSE");
    return 0;
} // end main()



//*****************************************************************
//*****************************************************************
