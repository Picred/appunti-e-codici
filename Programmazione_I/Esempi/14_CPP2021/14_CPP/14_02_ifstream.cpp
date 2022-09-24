#include <iostream>
#include <fstream>
#include <string>

#define FILENAME_READ "A14_02_DATA.txt"

using namespace std; 

/* Legge una stringa da un file mediante 
*  la classe ifstream. 
* Uso dello operatore !  per controllare 
* l'occorrenza di eventuali errori in fase 
* di lettura. 
*/ 
int main(){

  string s; 
  
  //Nome del file passato al costruttore
  ifstream testfileR1(FILENAME_READ);

  //controllo presenza di eventuali errori in fase di apertura
  //ad esempio il file non esiste, 
  //oppure non si hanno i permessi per leggere i dati 
  //presenti nel file!
  if(!testfileR1.is_open()){
    cerr << "Error opening file " << FILENAME_READ << endl;  
  }
  
  //leggiamo la prima stringa presente nel file due volte, 
  //con due file descriptor differenti, testfileR1 e testfileR2
  //contestualmente usiamo l'operatore '!' per verificare 
  //la prezenza di eventuali errori in fase di lettura
  if(!(testfileR1 >> s))
    cerr << "Error reading from file " << FILENAME_READ << endl;
  else
    cout << "read from file "  << FILENAME_READ << ": " << s << endl;

  //chiusura file
  testfileR1.close();
}
