#include <iostream>
#include <iomanip>

#include <cmath>

using namespace std;

int main()
{
    
   int k=2000000000;
   int j=2000000000;
   int z=k+j;
        
   const short a = 32000;
   const short b = 32000;
   short c;
   c = a+b;  
          
   cout << z << "    " << c << endl; 
          
   const int COSTANTE_SFORTUNATA = 17; 
   cout << "Un numero davvero sfortunato : "
        << COSTANTE_SFORTUNATA << endl << endl; 
   //COSTANTE_SFORTUNATA=7;    Errore di compilazione !!!
		
		
   double x = 4.0;
   double y = sqrt(x);
   cout << "La radice quadrata di " << x 
        << " è " << y << "\n\n";
		
		
   const double PI_GRECA_MEZZI = M_PI / 2.0;
   cout << "Il coseno di " << PI_GRECA_MEZZI 
        << " e' " << cos(PI_GRECA_MEZZI) 
        << endl << endl;
                                                 
   double risultato = pow(sin(x),2) + pow(cos(x),2);				 
   cout << "\nVerifichiamo la relazione fondamentale " 
		<< "della trigonometria :\n" 
        << "\t\t sin(4)^2+cos(4)^2 = " 
        << risultato << endl;

   cout << "SQRT(9)=" << sqrt(9.0) << ", CBRT(28)=" << cbrt(28.0) << ", pow(28, 1/3)=" << pow(28.0, 1.0/3) << endl;

    return 1;
} // End main()
