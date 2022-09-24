//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsE1_06.cpp
//***   Data creazione : 12/01/2014
//***   Progetto       : OPP in "C++"
//***   Lezione        : Ereditarieta'
//***   Argomento      : Costruttori e Distruttori (I)
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>
#include <cstdlib>

using namespace std;


class Base
  {
    public:

       Base()  { cout << "Costruttore 'Base'\n"; }
       ~Base ()  { cout << "Distruttore 'Base'\n"; }

  }; //End class Base


class Derivata : public Base
  {
    public:

      //costruttore deve sempre chiamare costruttore della 
      //classe base. Qui e' automatica chiamata a 
      //costruttore di default! (Base())
       Derivata ()   { cout << "Costruttore 'Derivata'\n"; }
       ~Derivata ()  { cout << "Distruttore 'Derivata'\n"; }


  }; //End class Derivata



int main ()
  {
//    Derivata d;
    Derivata *p = new Derivata();
    delete p;
    //system("PAUSE");    // ns. comodo!
    return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
