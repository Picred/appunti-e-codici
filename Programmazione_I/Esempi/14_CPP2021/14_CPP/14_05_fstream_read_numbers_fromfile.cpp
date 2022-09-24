#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;

/* Il programma legge dei numeri 
* da un file. 
* Il ciclo termina a seguito di 
* un i) errore di lettura 
* oppure ii) EOF. 
* Dopo il ciclo di lettura 
* il programma stampa la media dei 
* numeri acquisiti dal file. 
*/ 
int main(){

  //al massimo 50 numeri..
  const int MAX_ITEMS=50;
  //End of File
  bool eof=false;
  //array per i numeri
  double x[MAX_ITEMS];
  //contatore
  int c=0;
  //summa per media
  double sum=0;

  //nome del file di input
  const string FILENAME="in_test.txt";
  
  //Apertura file in modalita' lettura
  fstream infile(FILENAME, ios_base::in);
  //oppure (lettura/scrittura): 
  //fstream inoutfile(FILENAME, ios_base::in | ios_base::out);
  //oppure (solo scrittura): 
  //fstream outfile(FILENAME, ios_base::out); 

  if(!infile.is_open()){
    cerr << "Cannot open file " + FILENAME + "!" << endl; 
    return -1;
  }

  //leggo al massimo MAX_ITEMS numeri oppure finche' l'utente non digita un EOF
  while(!eof && c<MAX_ITEMS){
    infile >> x[c];

    if((eof=infile.eof())){
      cerr<<"EOF! eof()=" << infile.eof() << endl;
    }

    else if(infile.fail()){ // IO error!
      cerr << "IO error: fail()=" << infile.fail() << endl;
      cerr << "Found invalid number!" << endl;

      cerr << "Now clearing the error flags.." << endl;
      infile.clear(); // clear all the error flags
      cerr << "infile.fail()=" << infile.fail() << endl;

      cerr << "Discarding invalid input.." << endl;
      infile.ignore(std::numeric_limits<std::streamsize>::max(), ' '); //ignore the remaining characters
    }

    else{
      cout << "Read number " << x[c] << endl;
      c++;
    }
  }//end while

  cout << "Read " << c << " numbers!" << endl;

  for(int i=0; i<c; i++){
    sum+=x[i];
    cout << "sum= " << sum << endl;
  }

  cout << "AVG(x[])=" << (c>0 ? sum/c : 0.0) << endl;

  infile.close(); // chiude il file
}
