#include <iostream>
#include <fstream>
#include <string>

#define FILENAME_WRITE "A14_06_DATA.txt"

/* Uso della classe fstream per scrittura di file 
* uso operatore '!' per controllo errori in fase di 
* scrittura
*/ 
using namespace std; 

int main(){

  string s; 
  
  fstream myfile;

  //metodo open
  myfile.open(FILENAME_WRITE, std::fstream::out);
  //FM provare anche append ed eseguire il programma diverse volte
  //myfile.open(FILENAME_READ_WRITE, std::fstream::out | std::fstream::app);

  //controllo presenza di eventuali errori
  if(!myfile.is_open()){ //uso operatore '!'
    cerr << "Error opening file " << FILENAME_WRITE << endl;
    return -1;
  }

  if(!(myfile << "A14_06 pippo test pippo2" << endl)) 
    cerr << "Error writing on file " << FILENAME_WRITE << endl;
  else
    cout << "Written data on file " << FILENAME_WRITE << endl;

  myfile.close();
}
