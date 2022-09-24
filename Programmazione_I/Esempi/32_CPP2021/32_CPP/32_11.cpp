#include <iostream>

using namespace std;

/* 
   Questo programma implementa una funzione
   ricorsiva per il calcolo del fattoriale.
*/



long  fattoriale  ( int  n )
    {
      cout << "fatt(" << n << ")" << endl;
       
      if  ( n == 0 )     return  1;
      
      return   n * fattoriale ( n-1 );
   }


int main(int argc, char *argv[])
{
  if(argc<2){
    cerr << "No argument! " << endl;
    return -1;
  }
     
   cout << "risultato: " << endl << fattoriale(atoi(argv[1])) << endl;     
    return 0; 
} // End main()
