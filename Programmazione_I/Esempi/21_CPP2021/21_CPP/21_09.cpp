#include <iostream>
#include "frazione.h"

using namespace std;

  

int main()
{
 
   Frazione f1(3, 4);
   Frazione f2(10, 12);
      
   cout << "La prima frazione è " << f1 << endl;
   cout << "La seconda frazione è " << f2 << endl << endl;
      
   if (f1.equals(f2))
       cout << "Le due frazioni sono uguali\n";
   else
       cout << "Le due frazioni sono diverse\n";
      
   if (f1.eMaggiore(f2))
         cout << f1 << " e' maggiore di " << f2 << endl;
   else
         cout << f1 << " non e' maggiore di " << f2 << endl;
     
   if (f1.eMinore(f2))
         cout << f1 << " e' minore  di " << f2;
   else
         cout << f1 << " non e' minore  di " << f2;

   cout << endl << endl;   
   Frazione f3 = f1.piu(f2);
   cout << f1 << " + " << f2 << " = " << f3 << endl;
      
   f3 = f1.per(f2);
   cout << f1 << " * " << f2 << " = " << f3 << endl;

   f3 = f1.meno(f2);
   cout << f1 << " - " << f2 << " = " << f3 << endl;
 
   f3 = f1.diviso(f2);
   cout << f1 << " / " << f2 << " = " << f3 << endl;
 
   return 0;

} // End main()

