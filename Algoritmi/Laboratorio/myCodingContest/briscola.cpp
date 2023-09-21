#include <iostream>
#include <fstream>
using namespace std;

// da ricontrollare
class Partita{
    private:
        int giorno, inizio, fine, tassa, vincita;
    public:
        Partita(int g, int i, int f, int t, int v) : giorno(g), inizio(i), fine(f), tassa(t), vincita(v){}
        friend bool verificaOrari(Partita, Partita);
        bool verificaFondi(int saldo){
            if (tassa > saldo)
                return false;
            return true;
        }

        int getGuadagno(){
            return vincita - tassa;
        }

        friend ostream& operator<<(ostream &os, Partita &p){
            os << p.giorno << " " << p.inizio << " " << p.fine << " " << p.tassa << " " << p.vincita << endl;
            return os;
        }
};

bool verificaOrari(Partita p1, Partita p2){
    if (p1.giorno != p2.giorno) 
        return true;
    if (p1.fine < p2.inizio)
        return true;
    return false;
}

int getPianificazioneMigliore(int cifra, Partita** partita, int dim){
    int guadagno = 0;
    int saldo = cifra;
    int max = cifra;

    for (int i = 0; i < dim; i++){
        saldo = cifra;
        if (partita[i]->verificaFondi(saldo)){
            guadagno = partita[i]->getGuadagno();
            Partita lastPartita = *partita[i];

            for (int j = 0; j < dim; j++){
                if (i != j && verificaOrari(lastPartita, *partita[j])){
                    guadagno += partita[j]->getGuadagno(); 
                    lastPartita = *partita[j];
                }
            }
        }
        saldo += guadagno;
        if (saldo > max)
            max = saldo;
    }
    return max;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int numero_partite, cifra_a_disposizione;
    for (int x = 0; x < 100; x++){
        in >> numero_partite >> cifra_a_disposizione;
        Partita **partite = new Partita *[numero_partite];
        int giorno, inizio, fine, tassa, vincita;
        for (int i = 0; i < numero_partite; i++){
            in >> giorno >> inizio >> fine >> tassa >> vincita;
            partite[i] = new Partita(giorno, inizio, fine, tassa, vincita);
        }
        out << getPianificazioneMigliore(cifra_a_disposizione, partite, numero_partite) << endl;
    }
}