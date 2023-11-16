#include "persona.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
//costruttore
Persona::Persona(string n, string c, int e) : nome(n), cognome(c), eta(e){}

void Persona::saluta(){ //stampo a caso un saluto
            srand(time(NULL));
            int rnd=rand()%3 + 1;
            if(rnd==1) 
                cout << "Buongiorno!"<<endl;
            if(rnd==2) 
                cout << "Buonasera!"<<endl;
            if(rnd==3)
                cout << "Ciao!"<<endl;
        }
//setter
void Persona::setNome(string x){
    nome=x;
}

void Persona::setCognome(string y){
    cognome=y;
}

void Persona::setEta(int z){
    eta=z;
}
//getter
string Persona::getNome(){return nome;}

string Persona::getCognome(){return cognome;}

int Persona::getEta(){
    return eta;
}


 void Persona::dici_nome(){
        cout << "Mi chiamo " << nome << " " << cognome << "." << endl;
    }

void Persona::dici_eta(){
    cout << "La mia eta' e':" << eta << endl;
}

void Persona::invecchia(){
    eta++;
}

void Persona::saluta_persona(Persona p2){
    string saluto;
    if (p2.getEta()>eta)
        saluto="Buongiorno ";
    else 
        saluto="Ciao ";
    
    cout << saluto << p2.getNome() << " " << p2.getCognome() << ", piacere di conoscerti." <<endl;
}
