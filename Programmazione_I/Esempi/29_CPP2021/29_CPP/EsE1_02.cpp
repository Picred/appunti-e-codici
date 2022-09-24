//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsE1_02.cpp
//***   Data creazione : 12/01/2014
//***   Progetto       : OOP in "C++"
//***   Lezione        : Ereditarieta'
//***   Argomento      : Derivazioni (II)
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int Dimensione = 20;


class Vettore3D
  {
    private :

       char  nome[Dimensione+1];

    protected :

       float    x, y, z;

    public:

       void Set (float l, float m, float n)
	   { x = l;  y = m;  z = n; }

       void Set_Nome (char *str)  { strcpy (nome, str); }

       float Prima   () const     { return x; }
       float Seconda () const     { return y; }
       float Terza   () const     { return z; }

       void Visualizza () const   { cout << nome; }

  }; //End class Vettore3D


//Derivazione con modificatore accesso PROTECTED
class Vettore4D : protected Vettore3D
//+ metodi e campi public vengono ereditati con specificatore accesso protected
// metodi e campi protected vengono ereditato con specificatore protected
//metodi e campi private vengono eredidati ma non sono accessibili 
//all'interno della classe ne all'esterno 
  {      
    protected :

       float    w;

    public:

       void Set (float l, float m, float n, float o)
	   { x = l;  y = m;  z = n;  w = o; }

       float Quarta () const     { return w; }

       void Visualizza () const
	   {
	     // cout << nome;   // Errore di compilazione ...
	     Vettore3D::Visualizza();
	     cout << " = ( " << x << ", "
		  << y << ", " << z << ", " << w << " )\n";
	   }
  }; //End class Vettore4D

int main ()
  {
    Vettore4D a;

    a.Set (1,2,3,4);
    // Errore di compilazione ...
    //a.Set_Nome ("V1"); //derivazione protected, Set_Nome: public -> protected oper Vettore4D
    a.Visualizza (); //OK

  //   cout << a.Prima() << a.Seconda() << a.Terza();
    // Triplo errore di compilazione ... derivazione protected, public-> protected per Vettore4D

    cout << a.Quarta()  << "\n\n";

//     a.Vettore3D::Set (-1,-2,-3);   // Errore di compilazione ...

    // a.w = a.x   //  Doppio errore di compilazione ...

//   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
  }


//*****************************************************************
//*****************************************************************
