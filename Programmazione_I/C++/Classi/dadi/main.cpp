#include "coppiaDadi.h"
#include "dado.h"
#include<iostream>

using namespace std;


int main(){

    CoppiaDadi dadi1;
    CoppiaDadi dadi2;
    char c='y';

    cout << "Lancio i dadi..." <<endl;
    while(c=='y'){
        //lancio i la coppia di dadi
        dadi1.lanciali();
        dadi2.lanciali();

        //vedo i nuovi dadi lanciati
        dadi1.vediDadi();
        dadi2.vediDadi();
        
         // cout << "Coppie 6-6:" << endl; //???????????????????????
        cout << "Lanciare i dadi?(y):" << endl;
        cin >> c;
    }
}