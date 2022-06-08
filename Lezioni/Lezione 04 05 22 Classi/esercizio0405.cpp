/*scrivere una classe template che prenda due tipi di dato generici e li utilizzi come tipi di dato per due attributi della classe stessa.
scrivere metodi set e get e un metodo di stampa, oltre al costruttore.
nel main creo alcuni oggetti e li stampo*/

#include <iostream>

using namespace std;

template<typename T1, typename T2>

class A{
    private:
        T1 dato1;
        T2 dato2;
    public:
        A(T1 n, T2 m) : dato1(n),dato2(m){ 
            // cout << "A constructor" << endl;
        }

        void stampa(){
            cout << "Dato1 = " << dato1 << " Dato2 = " << dato2 << endl;
        }

        T1 getDato1(){return dato1;}
        T2 getDato2(){return dato2;}

        void setDato1(T1 n){dato1=n;}
        void setDato2(T2 n){dato2=n;}
};

int main(){
    A<int,double> a(5,10.2);
    A<string,double> b("ciao",54.4);

    // cout << a.getDato1() << " " << a.getDato2() << endl;
    cout << "Dati primo oggetto: ";
    a.stampa();
    cout << "Dati secondo oggetto: ";
    b.stampa();

    cout << endl <<"Uso i setter su primo oggetto" << endl;
    a.setDato1(10); a.setDato2(5.5);
    a.stampa();
    
    cout << endl << "Uso i setter su secondo oggetto" << endl;
    b.setDato1("pippo"); b.setDato2(79.12);
    b.stampa();
    // cout << a.getDato1() << " " << a.getDato2()<< endl;
    

}