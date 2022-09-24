//*****************************************************************
//*****************************************************************
//***
//***   Nome file      : EsE1_05.cpp
//***   Data creazione : 12/01/2014
//***   Progetto       : OOP in "C++"
//***   Lezione        : Ereditarieta'
//***   Argomento      : Dichiarazioni di accesso
//***   -----------------------------------------------------------
//***   Autore         : G. Cincotti
//***   Organizzazione : Dipartimento di Matematica e Informatica
//***   E-mail         : cincotti@dmi.unict.it
//***
//*****************************************************************
//*****************************************************************


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int Dimensione = 20;


class Vettore3D
  {
    private:

       char  nome[Dimensione+1];

    protected :

       float    x, y, z;

    public:

       void Set (float l, float m, float n)
	   { x = l;  y = m;  z = n; }

       void Set_Nome (const char *str)  { strcpy (nome, str); }

       float Prima   () const     { return x; }
       float Seconda () const     { return y; }
       float Terza   () const     { return z; }

       void Visualizza () const   { cout << nome; }

  }; //End class Vettore3D


class Vettore4D : protected Vettore3D
  {
    protected :

       float w;

    public:

       void Set (float l, float m, float n, float o)
	   { x = l;  y = m;  z = n;  w = o; }

       float Quarta () const { return w; }

	//Vettore3D::Set_Nome; //DEPRECATED!
        using Vettore3D::Set_Nome; //Ancora public
       //using Vettore3D::nome;       // Errore di compilazione ...
       //using  Vettore3D::x;          // ???         
       //using  Vettore3D::Set;        // ???  
       using Vettore3D::Prima;

       void Visualizza () const
	   {
	     // cout << nome;   // Errore di compilazione ...
	     Vettore3D::Visualizza();
	     cout << " = ( " << x << ", " << y << ", " << z << ", " << w << " )\n";
	   }
  }; //End class Vettore4D



int main ()
  {
    Vettore4D a;

    a.Set (1,2,3,4);
    a.Set_Nome ("V1");   // Adesso funziona ...
    a.Visualizza ();

    cout << "Prima : " << a.Prima() <<          // Adesso funziona ...
	    "  Quarta : " << a.Quarta() << "\n\n";

    // cout << a.Seconda() << a.Terza(); // Doppio errore di compilazione ...

    // a.Vettore3D::Set (-1,-2,-3);   // Errore di compilazione ...

    // a.w = a.x   //  Doppio errore di compilazione ...

//   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
  }

//*****************************************************************
//*****************************************************************
