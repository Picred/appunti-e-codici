#include <iostream>
#include <cstdio>

using namespace std; 

int main(){
  
  char *p = "test"; // Per il C++11 il compilatore dara' un warning
  //p[2] = 'c'; //questa istruzione rappresenta un accesso non autorizzato a locazione di memoria 

  const char *p1 = "test";
  //p1[2] = 'c'; //Questa istruzione dara' errore di compilazione, corretto.

  char ptr[] = "test\0"; //carattere null alla fine e' inutile, lo avrebbe aggiunto il compilatore! 

  //con la lista di inizializzatori e' invece necessario inserire il carattere null!
  const char ptr1[] = {'a', 'b', 'c', '\0'};  
 
  //Attenzione alla mancanza del carattere null (vedi istruzione che stampa ptr2..)
  const char ptr2[] = {'a', 'b', 'c'};    

  //osservare il risultato..
  cout << "p:" << p << ", ptr: " << ptr << ", ptr1: " <<  ptr1 << ", ptr2:" << ptr2 << endl; 

}
