#include <string>
#include <sstream>

using namespace std; 

string binaryString(unsigned short n){
    stringstream ss;
    unsigned short op; 
    
    int l = sizeof(n)*8; 
    /* 
      l e' il numero di bit;
      posizioni i=0 ... l-1
      Il bit in posizione l-1 e' quello piu' a sinistra
    */
    for(int i=l-1; i>=0; i--){
      /* 
	1. Il bit in i-esima posizione viene spostato in posizione l-1, 
	quindi e' il bit piu' a sinistra (piu' significativo). 
	NB: Alla sua destra ci sara' un numero i di bit non 
	necessariamente zero. Sono i bit in posizione 0 ... i-1 
      */ 
      op = n << (l-i-1); //shift a sinistra
      /* 
	Adesso shift di sizeof(n)-1 = l-1 posizioni a destra. 
	Il bit piu' a sinistra viene spostato alla posizione 0. 
	NB: A seguito della operazione di shift a destra, tutti i bit 
	a sinistra del meno significativo saranno a zero. 
      */
      op = op >> l-1; // shift a destra. 

      /* 
	Adesso basta inserire il numero nello stringstream
      */ 
      ss << op; 
    }

    return ss.str(); 
       
}
