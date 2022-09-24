#include <iostream>
#include <iomanip>
#include "conto_corrente.h"

using namespace std;


int main()
{
   ContoCorrente conto1("Andrea Bianchi", 
                         72354, 102.56);

   ContoCorrente conto2("Maria Sforza", 
                         69713, 40.00);

   cout << fixed << setprecision(2) 
        << conto1 << endl << conto2;
      
   conto1.preleva(-78.00); 
   conto1.preleva(25.00);
   conto1.maturaInteressi();

   conto2.deposita(34.00);
   conto2.preleva(5000);
   conto2.setNominativo("Maria Verdi");
      
   cout << conto1 << endl << conto2 << endl; 
      
   cout << "Il Sig. " << conto1.getNominativo()
        << " possiede " 
        << conto1.getSaldo() 
        << " euro.\n\n";
    
    return 0;
} // end main()
