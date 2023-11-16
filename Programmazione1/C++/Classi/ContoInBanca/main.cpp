#include <string>
#include <iostream>
#include "conto.h"

using namespace std;

int main(){

    cout << "porco dio" << endl;
    Conto c1("Ubaldo Sterchi",268,100.0);
    Conto c2("Pietro Smusi",246);

    cout << c1.getGiacenza() << " " << c2.getGiacenza() << endl;


    c2.versa(34.21);

    c2.paga_imposta();

    cout<< c2.getGiacenza()<<endl;

    c1.paga_mese();

    cout << c1.getGiacenza()<<endl;

    cout <<c1.getProprietario()<<endl;
    cout<<c1.getGiacenza()<<endl;


}