#include <iostream>
#include "automobile.h"

using namespace std;

  

int main()
{ 
   Persona leo("Leo", "Russo", 1988); 
   Automobile bolide(
     "BJ78jk9", "Fiat Punto",
     false, 105, &leo); //puntatore alla persona  Leo 
                      
   cout << endl << bolide << endl;

   cout << "La persona nel main prima dell'avviamento: \n   "
        << leo << endl;
   bolide.avviamento();
   cout << "La persona nel main dopo l'avviamento: \n   "
        << leo << endl;
     
   bolide.percorri(15);
   cout << endl << bolide << endl;
   
   cout << "Rifornimento: 0.25 litri\n";
   bolide.rifornimentoCarburante(0.25F);      
   cout << endl << bolide << endl;
   
   bolide.percorri(24);
   cout << endl << bolide << endl;
     
   bolide.spegnimento();
   cout << "Leo nel main dopo lo spegnimento: \n   "
        << leo << endl;
   cout << bolide << endl;
   
   return 0;

} // End main()

