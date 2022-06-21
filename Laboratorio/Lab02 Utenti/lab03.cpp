#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
#define N 2000
//creare delle classi utente per poterli ordinare

class Utente {
private:
    int id;
    string nome;
    string cognome;
    double popolarita;
public:
    Utente(int i, string c, string n, double p){
            id=i;
            cognome=c;
            nome=n;
            popolarita=p;
        }

        Utente() : Utente(0, "", "", 0.0 ){}

    friend ostream& operator<<(ostream& os, Utente& u) {
        os << "Id= " << u.id;
        os << " Nome=" << u.nome;
        os << " Cognome=" << u.cognome;
        os << " Popolarita=" << u.popolarita;
        return os;
    }

    friend istream& operator>> (istream& input, Utente& user) {
        string id_string, popolarita_string;
        getline(input, id_string, ';');
        getline(input, user.cognome, ';');
        getline(input, user.nome, ';');
        getline(input, popolarita_string); // mi fermo al carattere di fine riga (default di getline)
        user.id = atoi(id_string.c_str());
        user.popolarita = stod(popolarita_string);
        // cout << user.id << 
        return input;
    }

        friend bool operator<(Utente& u1, Utente& u2){
            if(u1.popolarita<u2.popolarita)
                return true;
            
            return false;
        }

        //ordinamento per popolarita
        friend bool operator>(Utente& u1, Utente& u2){
            if(u1.popolarita>u2.popolarita)
                return true;
            
            return false;
        }

        friend bool operator==(Utente& u1, Utente& u2){
            if(u1.popolarita==u2.popolarita)
                return true;
            
            return false;
        }
        //ordinamento per cognome
        
        bool compareTo(Utente& other){
            string s1=this->cognome;
            string s2=other.cognome;

            int i;
            for(i=0; i<s1.length() && i<s2.length();i++){
                if(s1[i]<s2[i])
                    return true;
            }
            if(i==s1.length()){
                return true;
            }

            if(i==s2.length()){
                return false;
            }
            return false;
        }



};

void swap (Utente& x,Utente& y){
    Utente temp=x;
    x=y;
    y=temp;
}

void selection_sort(Utente* vett,int dim){
    int indexMin;
    
    for(int i=0;i<dim;i++){
        indexMin=i;
        for(int j=i+1;j<dim;j++){
            if(vett[j]<vett[indexMin]){
                indexMin=j;
            }
        }
        swap(vett[i],vett[indexMin]);
    }
}

void merge(Utente* vett, int p, int q, int r) {
    int n1 = (q - p) + 1;
    int n2 = r - q;

    Utente* L = new Utente[n1+1];
    Utente* R = new Utente[n2+1];

    for (int i = 0;i < n1;i++) {
        L[i] = vett[p + i]; //riempiemento array L
    }

    for (int j = 1;j <= n2;j++) {
        R[j-1] = vett[q + j]; //riempimento array R
    }

    L[n1] = Utente(0,"zzzzzzzzzzzzzz","",0.0); //Utente con il cognome "Piu grande"
    R[n2] = Utente(0,"zzzzzzzzzzzzzz","",0.0); //Utente con il cognome "Piu grande"

    //devo scorrere l'array R,L e il vett
    int i = 0, j = 0, k = p;

    for (k = p;k <= r;k++) {
        if ((L[i].compareTo(R[j]))) {
            vett[k] = L[i];
            i++;
        }
        else {
            vett[k] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;
}

void mergesort(Utente* vett, int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2.0);

        mergesort(vett, p, q);
        mergesort(vett, q + 1, r);
        merge(vett, p, q, r);
    }
}

int main(){
    ifstream myfile("utenti.txt");

    if (!myfile.is_open()) {
        cerr << "Errore apertura del file!" << endl;
        return -1;
    }

    Utente* utenti = new Utente[N];

    int count = 0;
    while (myfile.good() && count < N) {
        Utente u;
        myfile >> u;
        utenti[count] = u;
        count++;
    }

    
    //ordinamento per popolarita selection sort 
    // selection_sort(utenti,N);
    // for (int i = 0; i < N; i++) {
    //     cout << i << ")" << utenti[i] << endl;
    // }

    //ordinamento per cognome

    mergesort(utenti,0,N-1);

    for (int i = 0; i < N; i++) {
        cout << i << ")" << utenti[i] << endl;
    }
    myfile.close();

}