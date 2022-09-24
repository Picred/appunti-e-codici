#include <cstring>
#include <iostream>

using namespace std;


class Classe
  {
    private :

       const int c; // va inizializzata! 
       int i;
       float * f;
       double & d; // va inizializzata! 

    public:

       Classe (int, int, float *, double &);

       void Visualizza () const;

  }; //End class Classe



// Le costanti e gli indirizzi devono essere inizializzati
// Gli array costituiscono un'eccezione
//Si provi a commentare l'inizializzazione del 
//campo d (reference) oppure del campo  c (const)
Classe::Classe (int cc, int ii, float * ff, double & dd) :
	  f(ff), d(dd)
  {
    // E' preferibile inizializzare le variabili membro
    // nella lista di inizializzazione
  }


void Classe::Visualizza () const

  {
   cout << "Costante : " << c << '\n';
  }



int main ()
  {
    float  x = 2.3;
    double y = 0.344;

    Classe c1(10, 8, &x, y);
    Classe c2(20, 8, &x, y);

    c1.Visualizza ();
    c2.Visualizza ();

//    system("PAUSE");
    return 0;
} // end main()



//*****************************************************************
//*****************************************************************
