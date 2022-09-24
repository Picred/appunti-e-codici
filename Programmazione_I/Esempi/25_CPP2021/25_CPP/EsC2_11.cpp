#include <iostream>
#include <cstdlib>
using namespace std;

class Classe
  {
    private :

       float peso;

       static int peso_totale;

    public:

       static int contatore_oggetti;

       void Inizializza (int p)
	  {
	    peso = p;
	    contatore_oggetti++; // static, unica copia condivisa tra gli oggetti
	    peso_totale += p; // 
	  }

       void Visualizza (void) const
	  {
	    cout << "Peso totale : " << peso_totale
		 << "    Oggetti :" << contatore_oggetti << '\n';
	  }

  }; //End class Classe


// Le variabili statiche DEVONO essere
// inizializzate all'esterno

int Classe::peso_totale = 0; // Costituisce un'eccezione al data-hiding
int Classe::contatore_oggetti = 0;


int main ()
  {
    Classe x,y,z;

    x.Inizializza (10); // mdifichera' la variabile condivisa "peso_totale", che e' "private"
    y.Inizializza (20);
    z.Inizializza (30);

    x.Visualizza ();

    x.contatore_oggetti = 10; // e' public! 
    cout << "contatore : " << Classe::contatore_oggetti << '\n';

    //Classe::peso_totale = 0; //       Errore di compilazione

   //system("PAUSE");    // ns. comodo!
   return 0; 
} // End main()

//*****************************************************************
//*****************************************************************
