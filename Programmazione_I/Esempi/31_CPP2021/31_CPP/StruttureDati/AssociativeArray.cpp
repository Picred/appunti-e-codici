//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : "Associative array.cpp"
//***   Data creazione : 21/01/2014
//***   Progetto       : OOP in "C++"
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>

#include <cstring>

using namespace std;

class ArrayAssociativo
  {
    private :

      char ** stringhe;

    public :

      ArrayAssociativo (char ** str) : stringhe(str) { }

      int operator [ ] (char *);

      char * operator [ ] (int indice)    { return *(stringhe+indice); }

  }; // End class ArrayAssociativo


int ArrayAssociativo::operator [ ] (char * str)
  {
    char **ptr = stringhe;

    while (* ptr != NULL)
       if (strcmp(*ptr++, str) == 0)   
	return (ptr-stringhe-1);
    

    return -1;
  }


int main ()
  {
    char * nomi [ ] = { "Primo", "Secondo", "Terzo", NULL};

    ArrayAssociativo A (nomi);

    cout << "Il numero indice di Terzo e' : " << A["Terzo"] << endl;
    cout << "La parola nella locazione di indice uno e' : " << A[1] << endl;
    cout << "Si puo' anche fare : " << A[A["Primo"]] << endl;

   // system("PAUSE");    // ns. comodo!
    return 0;
  }


//*****************************************************************
//*****************************************************************

