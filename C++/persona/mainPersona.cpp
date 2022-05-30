#include "studente.h"


void fun(){
    Studente s1;
    Studente s2("Aa","Bd",19,"a@unict,it","1000097441");
    Studente s3=s2;

    //decommentare per vedere l'errore
    // s1.Persona::print(); //print() di Persona è accessibile dall'interno della classe Studente ma non dall'esterno
    s1.print();
    s2.print();
    s3.print();

}
int main(){
    // while(true) //decommentare per vedere l'utilizzo della memoria e verificare memory leak
        fun();
    cout << "finito";    
}