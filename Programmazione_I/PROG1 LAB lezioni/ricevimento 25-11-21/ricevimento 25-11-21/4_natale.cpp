/*
4.
Scrivere un metodo che prenda in input una matrice 
di puntatori a stringhe P di dimensioni n x m, due short a 
e b, ed una stringa s. Il metodo restituisca il valore 
booleano true se esiste almeno una colonna in P tale 
che la stringa s sia sottostringa di un numero 
compreso tra a e b (inclusi) di stringhe della colonna 
stessa. PS: Si assuma 0 < a  b < n
*/

#include <iostream>
#include <string>

#define N 2
#define M 3

using namespace std;

bool func(string *P[N][M], short a, short b, string s)
{
    int counter = 0;

    for (int j = 0; j < M; j++) //scorro colonne
    {
        for (int i = 0; i < N; i++) //scorro righe
        {
            if((*P[i][j]).find(s))
                counter++;
        }
        if ((counter >= a )&& (counter <= b))
            return true;
        counter=0;
    }
    return false;
}

int main()
{

    string *P[N][M];
    string m;

    int x, y;

    //cout << "La stringa Q ha " << N << " righe e " << M << " colonne" << endl;

    //cout << "Riempi la matrice con stringhe:" << endl;

    string s;

    // for (int i = 0; i < N; i++)
    // {
    //      for (int j = 0; j < M; j++) {
    //         cout << "P["<<i<<"]["<<j<<"]:";
    //          cin >> s;
    //          P[i][j] = new string(s);
    //      }
    // }

    P[0][0]=new string("abc");
    P[0][1]=new string("def");
    P[0][2]=new string("hhff");
    P[1][0]=new string("abcabc");
    P[1][1]=new string("abc");
    P[1][2]=new string("def");

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cout << "P["<<i<<"]["<<j<<"]="<<*(P[i][j])<<endl;

    // cout << "Inserisci una stringa: ";
    // cin >> m;

    m = "abc";

    // cout << "Inserisci i valori di x e y: ";
    // cin >> x;
    // cout << "\t";
    // cin >> y;

    x = 1;
    y = 2;

    cout << func(P, x, y, m);
}


