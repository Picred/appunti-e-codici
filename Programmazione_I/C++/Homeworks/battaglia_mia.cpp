#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_CAMPO 10
#define MAX_NAVI 5

int main (){

    string nome_giocatore;
    int dim_minima_nave;
    int dim_massima_nave;
    int dim_campo;
    
    char campo_giocatore[MAX_CAMPO][MAX_CAMPO];
    char campo_avversario[MAX_CAMPO][MAX_CAMPO];

    cout << "Inserisci le dimensioni del campo: ";
    cin >> dim_campo;


   // cout << "Questo e' il tuo campo di gioco" << endl;

    int i=0; 
    int j;
    
    while (i<dim_campo){
        j=0;
            while (j<dim_campo){
                campo_giocatore[i][j]='O';
                cout << campo_giocatore[i][j] << " ";
                j++;
            }
            cout << endl;
            i++;
    } 

    cout << "Scegli la dimensione minima e massima delle navi (rispettivamente):";
    cin >> dim_minima_nave >> dim_massima_nave;


    srand (time(0));

    int r=rand()%(dim_campo+1)+0;
    int r1=rand()%(dim_campo+1)+0;

    //posizione random delle navi nell'intervallo [0,dim_campo]
    for (int k=0; k<MAX_NAVI; k++){
        for (int k1=0; k<dim_campo; k1++){
                campo_giocatore[r][r1]='X';
                cout << campo_giocatore[i][j];
                cout << campo_giocatore[r][r1];
        }
        cout << endl;
    }    
    
    
}