#include <iostream>
#include <cstdlib>

using namespace std;


const char Ch = 'X';

//prototipo  (dichiarazione di f)
//double f (float x, int j=1, char c='A');

// Il seguente errore di compilazione e' dovuto al fatto
// che gli argomenti standard devono specificare tutti
// i parametri piu' a destra
//
   //  double f (float x=3.14, int j, char c='A'); // ... ERRORE
//

//implementazione (definizione di f)
double f (float x, int j, char c)
  {
    cout << "f : " << x << "   " << j << "   " << c << '\n';
    return x;
  }


//solo definizione 
int g (int k=0)
  {
    cout << "g : " << k << '\n';
    return k;
  }


//prototipo indica default per terzo parametro 
float h (int k, int m, char c=Ch); 

//definizione indica default anche per secondo parametro 
float h (int k, int m=g(100), char c) 
  {
    cout << "h : " << k << "   " << m << "   " << c << '\n';
    return (float) (k+m);
  }


int main()
  {
   f(2.3, 8, 'Z');
   f(2.3, 8); // terzo argomento prende valore di default
   f(2.3, 'Z');   // Errato, anche se ... viene compilato (un carattere e' un intero...)
   f(2.3); //secondo e terzo argomento assumeranno valori di default

   g(5);
   g();

   h(2);
   // h();  ... Errore di compilazione,necessita di almeno un parametro, quello piu a sinistra
   
   return EXIT_SUCCESS;
  }

//*****************************************************************
//*****************************************************************
