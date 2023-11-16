#include "random.h"
#include<iostream>



using namespace std;

int main(){

    Random n1;
    Random n2(1122433);

    for(int i=0; i<2;i++){
        n1.generateDouble(10,20);
        n2.generateInt(100,200);

        n1.stampaValore();
        n2.stampaValore();

        cout << i << endl << endl;
    }
}