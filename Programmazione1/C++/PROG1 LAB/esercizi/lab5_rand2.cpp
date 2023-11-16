/*
Scrivere un programma che simula una partita a carte tra l’utente e il calcolatore. Le regole del gioco sono molto semplici: 
il giocatore pesca una carta da un mazzo di 10 carte numerate da 1 a 10. Il calcolatore pesca una carta dalle restanti 9. 
Chi ottiene il numero più alto vince. Per simulare il fatto che il giocatore “pesca” dal mazzo, sarà permesso al giocatore 
di inserire un numero intero che, sommato al tempo corrente, verrà usato come seed per la simulazione.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    int x;
    cout << "Inserire x da sommare al tempo corrente per creare srand:" << endl;
    cin >> x;

    if(cin.fail()){
        cerr << "hai inserito un valore non valido.";
        return 0;
    }

    srand(time(0)+x);

    bool parita=true;

    while(parita){
        int p1=rand()%10+1;
        int p2=rand()%9+1;
        if(p2==p1){
            continue;
        }
        if(p1>p2){
            parita=false;
            cout << p1 << " " << p2 <<  " Vince Player 1.";
        } else{
            parita=false;
            cout << p1 << " " << p2 << "Vince Player 2.";
        }
    }    
}