/*
Scrivere un programma in C++ che permetta di simulare una sequenza di N lanci di una coppia di dadi, 
dove N è un numero scelto dall’utente. Il programma dovrà stampare le sequenze dei due numeri 
(output primo dado e output secondo dado) in due colonne separate. ES: 
1 6
3 4
1 2
6 3
*/

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    int x=4; // x= numero lanci da effettuare
    srand(time(0));

    for(int i=0;i<x;i++){
        int num1=rand()%6+1;
        int num2=rand()%6+1;
        cout << num1 << "\t" << num2 << endl;
    }

    return 0;
}