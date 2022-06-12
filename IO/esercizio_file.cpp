//Aprire il file "output.txt" e stampare quello che c'è scritto fino al carattere ','

#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream file("output.txt");

    //verifico se il file è aperto
    if(file.is_open()){
        cout << "File aperto con successo" << endl;
    }

    char virgola = ',';
    string x;
    while (!(x.find(virgola) != string::npos)){
        file >> x; //x si aggiorna ad ogni iterazione
    }

    cout << x;
}