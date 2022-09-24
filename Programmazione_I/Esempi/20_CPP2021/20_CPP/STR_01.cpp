#include <iostream>
//#include <cstring> // equivalente a #include <string.h> in 

using namespace std;

int main(){
  
  //p "punta" all'area di memoria (read-only) in cui viene memorizzato 
  //un array di caratteri di lunghezza 5 ('test' + '\0') 
  const char *p = "test"; //OK. String literal

  //un letterale e' un rray di caratteri
  //infatti sizeof() ne stampa la dimenzione in bytes 7 + 1 
  //ultimo carattere e' carattere 'null' ('\0')
  cout << "sizeof(\"Hi all!\"):" << sizeof("Hi all!") <<  endl;

  // stampa la dimensione, in bytes, del puntatore
  cout << "sizeof(p): " << sizeof(p) << endl; 

  // stampa la dimensione, in byte, occupata da un char, ovvero p[0].  
  cout << "sizeof(*p): " << sizeof(*p) << endl;  
  cout << "p[3]:" << p[3] << endl; // OK

  //Deprecated. Not safe. Indeed, memory of literal "test1" is read-only. 
  //p1[2] = 'c' will result in ``undefined behaviour''. 
  char *p1 = "test1"; 
  
  //OK. array di caratteri per una stringa di 19 caratteri
  char p2[20]; 
  p2[4] = 'k';// OK ma...
  cout << "p2: " << p2 << endl; //Manca il carattere '\0'...
  
  //allocazione (dichiarazione array) + inizializzazione
  char p3[20] = "Hello all!"; //OK, verra' inizializzato con un '\0' alla fine
  cout << "p3: " << p3 << endl; // OK   
  //oppure..
  char p33[] = "Hello all!"; // avra' lunghezza appropriata (11)

  //questo non va molto bene
  char name[] = {'p', 'i', 'p', 'p', 'o'}; //manca lo 0, alcune funzioni potrebbero non funz. corr. 
  cout << "name:" << name << "strlen(name):" << endl;

  //questo e' OK
  char name1[] = {'p', 'i', 'p', 'p', 'o', '\0'}; //manca lo 0
  cout << "name1:" << name1 << endl;
  
}
