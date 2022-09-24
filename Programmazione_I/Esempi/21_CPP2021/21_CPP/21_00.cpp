#include <iostream>
#include <cstdlib>
#include <ctime>

#include "dado.h"

#define MAX_LANCI 10000000
#define LANCIO_BUONO 3
#define SEQ 10

using namespace std;

int main()
{
    Dado d;//creo istanza di Dado
    int c=0;
    int i = 0; 

    srand(time(0));

    while (i++<MAX_LANCI && c<SEQ)
       {       
	  //uno o due lanci
	  //si vince quando 
         d.effettuaLancio(); 
          
        if (d.getUltimoLancio() == LANCIO_BUONO)
	    	c++;
		else{
	  	//cout << d.getUltimoLancio() << endl; 
	  	c=0;}
       }

      cout << "Tot Lanci="  << (c==SEQ ? i : i-1) << ", c=" << c << endl; 
      cout << (c==SEQ ? "Hai vinto" : "Non hai vinto") << endl;       
}
