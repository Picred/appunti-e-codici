/*
Eseguire la somma dei numeri contenuti in un file 'file.txt' e stamparne il totale.
*/

#include <iostream>
#include <fstream>

#define MY_FILE "file.txt"

using namespace std;

int main(){

        fstream file(MY_FILE);
        int num1, somma=0;
        bool eof;

        if(!file.is_open()){
            cerr << "Errore apertura del file." << endl;
        }

        

        while(!(file.eof())){
            file >> num1;
            somma+=num1;
        }
        cout << "La somma dei numeri scritti nel file '" << MY_FILE << "' e': " << somma;
    
    file.close();

}

