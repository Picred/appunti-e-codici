#include<iostream>

using namespace std;

int main() {
    int N, M;
    cout << "Inserire il numero di righe: ";
    cin >> N;

    cout << "Inserire il numero di colonne: ";
    cin >> M;

    int x[N][M];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            cout << "Inserisci il valore di x["<<i<<"]["<<j<<"]: ";
            cin >> x[i][j];
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cout << "x["<<i<<"]["<<j<<"]:"<<x[i][j]<<endl;
}