#include"persona.h"
#include<iostream>

using namespace std;

int main(){
    Persona p1("Mario","Rossi",20);
    Persona p2("Marco","Ferra",24);
    Persona p3("Cleopatra","Nineone",30);

    p1.saluta();
    p2.saluta();
    p3.saluta();

    p1.saluta_persona(p2);

    p3.dici_nome();
    p2.setCognome("Scarso");

    p2.dici_nome();
}