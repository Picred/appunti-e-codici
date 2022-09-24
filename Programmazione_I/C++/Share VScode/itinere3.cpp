/*
Scrivere un metodo che prenda in input una matrice V di stringhe contenente verbi italiani
all’infinito, e restituisca la percentuale dei verbi della prima coniugazione.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

double prima_coniugazione(string **V, int n, int m){
    double tot_verbi=0;
    string fine_parola;
    double verbi_are;
    double percentuale_are;
    //scorro la matrice
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //verifico le 3 lettere finali della parola considerata
            fine_parola = V[i][j].substr(V[i][j].length()-3,3);
            
            if (fine_parola == "are"){
                verbi_are++;
            }
            tot_verbi++;
        }
    }
    percentuale_are = (verbi_are/tot_verbi)* 100;
    return percentuale_are;
} 

int main(){
    int n=3;
    int m=4;
    int random;
    cout << endl;
    srand(time(0));
    //inizializzo dinamicamente la matrice
    string **V = new string*[n];
    for (int i=0; i<n; i++){
        V[i]=new string[m];
        for (int j=0; j<m; j++){
            random=rand()%3;
            V[i][j]="T";         //assegno una base di stringhe 
            switch (random){        //assegno delle coniugazioni random
                case 0:
                V[i][j]+="are";
                break;
                case 1:
                V[i][j]+="ere";
                break;
                case 2:
                V[i][j]+="ire";
                break;
            } 
            cout << V[i][j] << "\t";
             
        }
        cout << endl;
    }

    //utilizzo la funzione per vedere la percentuale di parole con la prima coniugazione
    double percentuale_are;
    percentuale_are=prima_coniugazione(V,3,4);
    cout << endl <<"La percentuale di ARE nella matrice e' del " << setprecision(4) << percentuale_are << "%.";
    
    return 0;
}