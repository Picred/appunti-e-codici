#include <iostream>
#include <sstream> // stringstream 

using namespace std; 

//Prima vedi main 
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
      op = op >> (l-1); // shift a destra. 

      /* 
	Adesso basta inserire il numero nello stringstream
      */ 
      ss << op; 
    }

    return ss.str(); 
       
}


//Operatori logici bit a bit (bitwise) 

int main(){

  string sep = string(16, '-'); 

  /* 1 
    shift logico << e >>     
  */ 

  unsigned short a = 0x000f; // a=15 / 0 ... 01111
  unsigned short x = 0b1111000011110000; 

  cout << binaryString(x) << endl; 

  int shift=1; 

  cout << "a=" << a << " (dec), " << binaryString(a) << " (bin) \n\n";

  //Shift bit a bit a sinistra 
  // a << i equivale a moltiplicare per 2^i
  cout << "1. Shift a SINISTRA (bit a bit) : << " << "\n\n";  

  cout << "( " << binaryString(a) << " << " << shift << " ) = " << binaryString(a<<shift) << ", " << (a<<shift) << " (dec) \n\n";

  //Shift bi a bit  a destra
  // a >> i equivale a moltiplicare per 2^(-i), il risultato sara' 
  //la parte intera della divisione! 

  cout << "2. Shift a DESTRA (bit a bit): >> " << "\n\n"; 
  cout << "( " << binaryString(a) << " >> " << shift << " ) = " << binaryString(a>>shift) << ", " << (a>>shift) << " (dec) \n\n";

  /* NB: 
    L'effetto della moltiplicazione per 2^(i) (risp. 2^-i) 
    e' quello di lasciare i bit a destra (risp. sinistra) 
    a zero, qualunque fosse lo il loro valore. 

    (11110000 << 1) = 11100000
    (11110010 << 1) = 11100100

    (11110000 >> 1) = 01111000
    (11110010 >> 1) = 01111001
  */ 

  /* 
    2 
    Operatore OR bitwise: | 
    x | y = 0 quando x=0 e y=0, altrimenti varra' 1

    x	y   (x | y)
    ---------------
    0	1     1	
    1	0     1	
    1	1     1
    0	0     0

  */ 
   unsigned short b = 0xf000; //

   cout << "3. Bitwise OR (binary) : |" << "\n\n";
   cout << binaryString(b) <<  " | " << endl <<  binaryString(0x000f) << endl << sep << endl << binaryString(b | 0x000f) << "\n\n";

  /*  
    3 
    Operatore AND bitwise: & 
    x | y = 1 quando x=1 e y=1, altrimenti varra' 0

    x	y   (x & y)
    ---------------
    0	1     0	
    1	0     0	
    1	1     1
    0	0     0

  */ 

   cout << "4. Bitwise AND (binary): &" << endl << endl; 
   cout << binaryString(b) << " & " << endl << binaryString(0x000f) << endl << sep << endl << binaryString(b & 0x000f) << "\n\n";

   /* 
    4. 
   Operatore di complemento a 1: ~
   x - ~x
   ------
   1   0
   0   1
   */ 

   cout << "5. Bitwise complement (unary) : ~" << endl << endl; 
   cout << "( ~" << binaryString(b) << " ) = " << binaryString(~b) << "\n\n"; 

  /*  
    5 
    Operatore OR esclusivo (XOR) bitwise: ^

    x	y   (x ^ y)
    ---------------
    0	1     1
    1	0     1	
    1	1     0
    0	0     0

  */ 

   cout << "6. Bitwise XOR (binary) : ^" << "\n\n"; 
   cout << binaryString(b) << " ^ " << endl <<  binaryString(0x000f) << endl << sep << endl << binaryString(b ^ 0x000f) << "\n\n";

}
