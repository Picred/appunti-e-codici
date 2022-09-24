//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsC2_17.cpp
//***   Data creazione : 06/01/2014
//***   Progetto       : OOP in "C++"
//***   Lezione        : Le classi
//***   Argomento      : Classi friend (II)
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>


using namespace std;


class Euro;

class Lira
  {
    private :

       int valore;

    public :

       Lira (int v)   { valore = v; }
       void Convertitore (float, Euro &);

       friend class Euro; // euro friend di Lira

  }; //End class Lira


class Euro
  {
    private :

       int valore;

    public :

       Euro (int v)   { valore = v; }
       void Convertitore (float, Lira &);

       friend class Lira; // Lira friend di euro

  }; //End class Euro


void Euro::Convertitore (float coeff, Lira & l)
  {
    cout << "(Primo convertitore)\t"  // Convertitore metodo di Euro (friend di Lira!)
	 << valore * coeff << " lire  e  "
	 << l.valore / coeff << " euro\n";
  }


void Lira::Convertitore (float coeff, Euro & e)
  {
    cout << "(Secondo convertitore)\t" // Convertitore metodo di Lira (friend di Euro!)
	 << e.valore * coeff << " lire  e  "
	 << valore / coeff << " euro\n";
  }


int main ()
  {
    Lira diecimila(10000);
    Euro dieci(10);

    cout << "10 euro  e  10.000 lire  equivalgono rispettivamente a\n";

    dieci.Convertitore (1936.27, diecimila);
    diecimila.Convertitore (1936.27, dieci);

  // system("PAUSE");    // ns. comodo!
//   return EXIT_SUCCESS;
   return 0;
} // End main()

//*****************************************************************
//*****************************************************************
