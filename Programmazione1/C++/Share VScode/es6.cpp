/*
6.Scrivere un metodo che prenda come parametro 
formale un cubo (array tridimensionale) C di stringhe, 
e restituisca in output una stringa contenente tutte le 
desinenze di due caratteri delle stringhe sulla faccia 
superiore del cubo C.
*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string pippos(string ***C, int n, int m, int z){

    string desinenze="";
    z=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            desinenze += C[z][i][j].substr( C[z][i][j].length()-2,2 );
            }
        }
    return desinenze;
}