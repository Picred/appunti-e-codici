#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream file("esempio.txt"); //apertura in lettura

    //verifico se il file è stato aperto
    if (!file.is_open()) {
        cerr << "Errore apertura del file" << endl;
    }

    cout << "Leggo da 'file' " << endl;

    string x;
    while(getline(file,x)){ //leggo una riga intera
        cout << x << endl;
    }
    
    file.close();

    //scrivo su un file insesistente, quindi, allo stesso tempo, lo creo
    ofstream out("output.txt");

    //verifico se il file è stato aperto
    if (out.is_open()) {
        cout << "Secondo file aperto con successo!" << endl;
    }

    out << "Prova output, parola due"; //scrivo sul secondo file

    out.close();

}