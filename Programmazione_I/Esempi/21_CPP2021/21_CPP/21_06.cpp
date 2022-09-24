#include <iostream>
#include "serbatoio.h"

using namespace std;


int main()
{
    Serbatoio a(100,100, "A");
    Serbatoio b(100,0, "B");
    Serbatoio c(80, 0, "C");
    Serbatoio d(40, 0, "D");

    int tempoTrascorso = 0;

    while (!d.pieno())
      {
        cout << "INIZIO TRANSAZIONI" << endl;
         
        float uno = a.preleva(a.getQuantita()/5);
        b.deposita(uno); 

        float due = a.preleva(a.getQuantita()/10);
        c.deposita(due); 
         
        float tre = b.preleva(b.getQuantita()/2);
        c.deposita(tre); 

        float quattro = b.preleva(b.getQuantita()/5);
        d.deposita(quattro);        

	float cinque = c.preleva(c.getQuantita()/2);
	d.deposita(cinque);

         
        cout << a << endl << b << endl << c << d << endl;
         
        tempoTrascorso += 2;
      } 
 
        cout << "Tempo trascorso : " << tempoTrascorso  
             << " ore.\n\n";
    
    return 0;
} // end main()
