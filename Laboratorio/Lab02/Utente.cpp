#include <iostream>
#include <string>
#include <fstream>
#define N 2000

using namespace std;

class Utente {
    private:
        unsigned int id;
        string cognome;
        string nome;
        double popolarita;
    public:
        Utente(int i, string c, string n, double p){
            id=i;
            cognome=c;
            nome=n;
            popolarita=p;
        }

        Utente() : Utente(0, "", "", 0.0 ){}

        friend istream &operator>> (istream &input, Utente &user){
            string id_string, pop_string;
            getline(input, id_string, ';');
            getline(input,user.cognome, ';');
            getline(input,user.nome, ';');
            getline(input,pop_string); // mi fermo al carattere di fine riga (default di getline)
            user.id = atoi(id_string.c_str());
            user.popolarita=stod(pop_string);
            // cout << user.id << 
            return input;
        }


        double getPop(){
            return popolarita;
        }
};

void quicksort(Utente A[N], int p, int r){
    if(p<r){
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

int main(){
    // Utente pippo(4,Pippo,Baudo, 4865132);
    Utente* utenti = new Utente[N];
    unsigned int count =0;
    //apro il file

    ifstream file("utenti.txt", ifstream::in);
    file.open("utenti.txt");

    double temp[N];

        
        while (file.good()){
            Utente u;
            file >> u;
            utenti[count] = u ;
        
        }
    file.close();

    // p=0; r=N-1;

}
