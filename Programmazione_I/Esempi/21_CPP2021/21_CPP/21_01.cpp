#include <iostream>
#include <cstdlib>
#include <ctime>

#include "dado.h"

using namespace std;

/* 
  Simula il lancio di
  una coppia di dadi. 

  Si vince quando escono 
  due numeri uguali. 
*/
int main()
{
    srand(time(0));
    
    Dado primo, secondo;

    primo.effettuaLancio();
    secondo.effettuaLancio();

    int numeroDiLanci = 1;
     
    //numeri estratti identici
    while (primo.getUltimoLancio() != 
           secondo.getUltimoLancio() )   
      {
        primo.effettuaLancio();
        secondo.effettuaLancio();
        numeroDiLanci++; 
      } 
      
    cout << "Sono stati effettuati " <<
      numeroDiLanci <<
      " lanci.\n" << endl;
    cout << "Primo dado   : " << primo   << endl;     
    cout << "Secondo dado : " << secondo << endl;     

    primo.commentaLancio(); 

    return 0;
} // end main()
