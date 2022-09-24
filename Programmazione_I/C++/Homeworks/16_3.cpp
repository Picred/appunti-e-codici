/*
16.3
Codificare in C++ un programma battaglia navale in cui l’utente
gioca contro il calcolatore.
Il programma chiede all’utente le seguenti informazioni:
• il nome del giocatore
• la dimensione del proprio campo di gara
• la dimensione della tabella di gara.
• la dimensione minima e massima delle navi, intesa come
numero di celle occupate da ogni nave.

Il programma dispone in modo casuale un certo numero di navi
nella tabella del giocatore e nella tabella dell’avversario (il
calcolatore).
Il programma visualizza sempre e solo le due tabelle del giocatore,
i) quella che contiene le navi del giocatore e ii) quella che contiene
le mosse contro l’avversario. In questa ultima tabella saranno
visibili solo i tiri a vuoto e i tiri a segno, mentre nella prima tabella
saranno visibili le navi e i tiri a segno.
Dopo l’inizio della battaglia, il programma chiede all’utente le
coordinate dell’obiettivo (cella) da colpire, di conseguenza aggiorna
le tabelle del giocatore.

La mossa del calcolatore avverr`a dopo ogni mossa del giocatore.
Anche in questo caso il giocatore vedr`a le sue tabelle aggiornate.
Il giocatore pu`o chiedere al programma di interrompere il gioco in
qualsiasi momento, in questo caso il programma offre al giocatore
la possibilit`a di salvare lo stato del gioco su un file, e di scegliere
un nome.
Inoltre, ad ogni avvio del programma, l’utente pu`o scegliere se
iniziare una nuova sessione di gioco oppure caricare una sessione di
gioco salvata precedentemente in un file.
*/

#include <iostream>

using namespace std;

int main (){

    string nome_giocatore;
    int Nc=0, Mc=0;
    int dim_campo;

    cout << "Inserisci il tuo nome: ";
    cin >> nome_giocatore;

 //campo proprio di gara
    cout << "Inserisci la dimensione quadrata del tuo campo: ";
    cin >> dim_campo;

//tabella di gara
 /*   int Nt, Mt;
    cout << "Inserisci le righe e le colonne della tabella di gara: ";
    cin >> Nt >> Mt;

    char campo_giocatore[Nc][Nc];
    char tabella_gara[Nt][Mt];
*/
    int dim_minima_nave;

//dimensioni minime nave
    cout << "Inserisci la dimensione minima di ogni nave: ";
    cin >> dim_minima_nave;
    
//dimensioni massime nave
    int dim_massima_nave;
    
    cout << "Inserisci la dimensione massima di ogni nave: ";
    cin >> dim_massima_nave;
    
    // costruzione campo giocatore vuoto
    char vuoto='O';

    cout << "-----TUO CAMPO DI GIOCO-----" << endl;
    for (int i=0; i<dim_campo; i++){
        for (int j=0; j<dim_campo; j++){
            campo_giocatore[i][j]= vuoto;
            cout << campo_giocatore[i][j] << " ";
        }
        cout << endl;
    }
    cout << campo_giocatore;
}