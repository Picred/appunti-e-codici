#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Stringa
  {
    private :

       char str[80];

    public:

    void Inizializza (const char * s)
	  {
	   strcpy (str, s);
	  }

    void Leggi (char * buf)
	  {
	   strcpy (buf, str);
	  }

  }; //End class Stringa


int main()
  {
    char buffer[80];
    Stringa s1;
    s1.Inizializza ("Prima stringa\n");

    Stringa s2 = s1; // copia i valori in s1 su s2, membro a membro

    s2.Leggi (buffer);
    cout << buffer; // infatti..

    const Stringa s3 = s1; // Ok ma oggetto e' const, solo inizializzazione
//       s3.Inizializza (buffer); //Errore di compilazione

    return 0;
} 
