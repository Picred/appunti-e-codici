#include <iostream>
#include <sstream>


using namespace std;


int main()
{    
   const int PRIMO   = 1;
   const int SECONDO = 1<<1;
   const int TERZO   = 1<<2;
   const int QUARTO  = 1<<3;
   const int QUINTO  = 1<<4;
   const int SESTO   = 1<<5;
   const int SETTIMO = 1<<6;
   const int OTTAVO  = 1<<7;

   int unNumero = 127;    // Questo valore è l'input

   int bit1,
       bit2,
   	   bit3,
   	   bit4,
   	   bit5,
   	   bit6,
   	   bit7,
   	   bit8;  // variabili int che conterranno 1 o 0

   // "estraggo" i bit da "unNumero"
   bit1 = (unNumero & PRIMO); 
   bit2 = (unNumero & SECONDO)/2;
   bit3 = (unNumero & TERZO)/4;
   bit4 = (unNumero & QUARTO)/8;
   bit5 = (unNumero & QUINTO)/16;
   bit6 = (unNumero & SESTO)/32;
   bit7 = (unNumero & SETTIMO)/64;
   bit8 = (unNumero & OTTAVO)/128;

        //con le successive istruzioni stampo i bit estratti

    cout << "Gli 8 bit meno significativi del numero " 
         << unNumero << " sono : ";

    cout << bit8 << bit7 << bit6 << bit5 
         << bit4 << bit3 << bit2 << bit1 << endl;
     
        return 0;
} // End main()
