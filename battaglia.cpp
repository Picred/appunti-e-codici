/*
Codificare in C++ un programma battaglia navale in cui l’utente
gioca contro il calcolatore.
Il programma chiede all’utente le seguenti informazioni:
• il nome del giocatore
• la dimensione del campo di gara
• la dimensione della tabella di gara. FORSE NON SI CONSIDERA QUESTA.
• la dimensione minima e massima delle navi, intesa come
numero di celle occupate da ogni nave.  { quindi navi della stessa lunghezza (?) }

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

// class Giocatore{
//     private:
//         string nome;
//     public:
//         virtual void attacca();
// };

void vediCampo(string **c, short n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << //continuare qua, stampavo il campo
        }
    }
}

int main(){
    short n;
    cout << "Dimensione campo: " << endl;
    cin >> n;

    string campo[n][n];


}