#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void getDim(ifstream &, ofstream &);

int main() {

    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++){
        getDim(in,out);
    }
    in.close();
    out.close();

    return 0;
}

void getDim(ifstream &in, ofstream &out){
    string line;
    while(getline(in, line)){ //prende l'input e lo mette nella stringa line finche non trova il carattere finale
        vector<double> v;     //vettore tramite library vector
        stringstream ss(line);//buffer
        double a;             //variabile appoggio
        while(ss >> a)        //metto ss >> a; conversione
        {
            v.push_back(a);   //metto ogni singolo double nel vettore
        }
        out << v.size() << endl; //prendi la dimensione del vettore
    }
}
