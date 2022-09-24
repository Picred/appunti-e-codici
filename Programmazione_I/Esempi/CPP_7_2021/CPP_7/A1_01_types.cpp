#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <limits>

using namespace std;

int main()
{

    //INTERI 
   int unNumeroTipoInt = 234918743;
      //questo è un intero a 4 byte?		

   long int unNumeroGrande = 1000000000000; 
   //it doesn't fit in an integer, it needs a long

//  int unInt = 1000000000000;
 // cout << unInt << endl; 
	 
  //SHORT 
   short int unNumeroCorto= 30000;
   //questo richiede solo 2 byte ?
   
   signed char charSigned = 200; // ammette valori da -127 a +127
   cout << "a signed char (200): " << (int) charSigned << endl ; // non stampera' 200, ma un valore di overflow

  //CARATTERI 

   unsigned char unsignedChar = 200; // 0 to 254
       // questo richiede solo un byte!
   cout << "an unsigned char (200): " << (int) unsignedChar << endl; // ok, it will print 200
    //se stampiamo il valore..
   cout << "an unsigned char (200): " << unsignedChar << endl; // ok, it will print 200

   char aChar = 130; //a char is signed or unsigned? It depends on the implementation..
   cout << "aChar(130) (Signed or unsigned?): " << (int) aChar << endl ; // it will print 130? 

   char aRealChar = 'c'; 
   cout << "a char printed as int:" << (int) aRealChar << endl;
   cout << "the same character printed as char:" <<  aRealChar << endl;

    //Booleani
   bool b = true; //as 1 
   bool bb = false; //as 0
   bool aBool = 1;

   cout << "b=" << b << ", bb=" << bb << ", aBool=" << aBool<< ", aBool==true?? " << (aBool==true) << ", aBool==false??" << (aBool==false) << endl ;

   //How many bytes? It (partially) depends on the implementation. 
   cout << "bool       -> " << sizeof (bool) << endl << endl;
   cout << "signed char  -> " << sizeof (signed char) << endl;
   cout << "unsigned char  -> " << sizeof (unsigned char) << endl;
   cout << "short int  -> " << sizeof (short int) << endl;
   cout << "int        -> " << sizeof (int) << endl;  
   cout << "unsigned int -> " << sizeof (unsigned int) << endl;
   cout << "long int   -> " << sizeof (long int) << endl;
   cout << "long long  -> " << sizeof (long long) << endl;
   cout << "float      -> " << sizeof (float) << endl;
   cout << "double     -> " << sizeof (double) << endl;
   cout << "long double-> " << sizeof (long double) << endl; 
   cout << "void *: " << sizeof(void *) << endl;
   //cout << "void: " << sizeof(void) << endl;

   cout << "unNumeroTipoInt = " << unNumeroTipoInt << endl;
   cout << "unNumeroGrande  = " << unNumeroGrande << endl;
   cout << "unNumeroCorto   = " << unNumeroCorto << endl << endl;

   //OVERFLOW!
   int unNumeroGrandeInt = static_cast<int> (unNumeroGrande);
   cout << "UnNumeroGrande (da long a int, risultato dello overflow..)" << unNumeroGrandeInt  << endl;

  //Division by zero! Qui il compilatore emette un warning..
  //cout << "Division 1/0 as int: " << (1/0) << endl;

  //Another division by zero. In questo caso nessun warning, perche'? 
  //int i = 10, j=0;
  //cout << i/j << endl;

 
   // Costanti intere  
   int x = 75;     // decimale
   cout << " x = " << x << endl; 
   x = 0113;       // ottale -- prefisso 0
   cout << " x = " << x << endl; 
   x = 0x4b;       // esadecimale -- prefisso 0x
   cout << " x = " << x << endl << endl; 

    return 0;
} // end main()
