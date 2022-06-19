#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//creare delle classi utente per poterli ordinare

class Utente{
    private:
        int id;
        string nome;
        string cognome;
        double popolarita;
    public:
        Utente(int i, string c, string n, double p) : id(i), nome(n),cognome(c),popolarita(p){}

        friend ostream& operator<<(ostream& os, Utente& u){
            os << "Id= " << u.id;
            os << " Nome=" << u.nome;
            os << " Cognome=" << u.cognome;
            os << " Popolarita=" << u.popolarita;
            os << endl;
            return os;
        }
};


int main(){
    ifstream myfile("utenti.txt");

    if(!myfile.is_open()){
        cerr << "Errore apertura del file!" << endl;
        return -1;
    }

    Utente* utenti;
    string temp;

    // while(!myfile.eof()){
        string riga;
        myfile >> riga;
        //scorro la stringa estratta
        int i=0;
        temp="";
        while(i < riga.length() && (temp.find(';') != string::npos) ){
            temp+=riga[i];
            i++;
        }
    // }

    cout << temp;
    myfile.close();
    
}