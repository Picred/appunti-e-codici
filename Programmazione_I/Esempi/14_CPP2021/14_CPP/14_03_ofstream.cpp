#include <iostream>
#include <fstream>
#include <string>

#define FILENAME_WRITE "A14_03_DATA.txt"

using namespace std; 

/* Uso della classe ofstream per scrittura di file
* uso operatore '!' per verifica eventuali errori 
*/ 
int main(){

//  string s; 
  
  
  ofstream myfile;

  //metodo open
  myfile.open(FILENAME_WRITE); //NB: nessun flag per specificare apertura in scrittura!
  //FM provare anche append ed eseguire il programma diverse volte

  //controllo presenza di eventuali errori
  if(!myfile.is_open()){
    cerr << "Error opening file " << FILENAME_WRITE << endl;
    return -1;
  }

  if(!(myfile << "A14_03 pippo test pippo2" << endl)) // uso operatore '!'
    cerr << "Error writing on file " << FILENAME_WRITE << endl;
  else
    cout << "Written data on file " << FILENAME_WRITE << endl;        

  myfile.close();
}
