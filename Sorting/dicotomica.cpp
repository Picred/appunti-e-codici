#include <iostream>

using namespace std;

#define dim 10

bool dicotomicaRicorsiva(int vett[dim], int key, int start, int end){
    if(start>end){
        return false;
    }

    int m = (end+start)/2;

    if(vett[m]==key){
        return true;
    }

    if(key<vett[m]){
        return dicotomicaRicorsiva(vett,key,start,m-1);
    }

    if(key>vett[m]){
        return dicotomicaRicorsiva(vett,key,m+1,end);
    }

    return false;
}


bool dicotomicaIterativa(int vett[], int size, int key){
    int start=0;
    int end=size-1;
    int midpoint;
    bool found=false;

    while(!found && start<=end){
        midpoint= (start+end)/2;

        if(vett[midpoint]==key)
            found=true;

        if(key<vett[midpoint])
            end=midpoint-1;
        
        if(key>vett[midpoint])
            start=midpoint+1;
    }

    return found;
}

int main(){
    int vett[dim];

    cout << "Vettore[" ;
    for(int i=0; i<dim; i++){
        vett[i] = i;
        cout  << vett[i] << "- ";
    }
    cout << "]" << endl;

    //0 1 2 3 4 5 6 7 8 9

    cout << dicotomicaRicorsiva(vett,7,0,dim-1) << endl; //true se lo trova, false se non lo trova

    cout << (dicotomicaIterativa(vett,dim,8) ? "trovato" : "non trovato");
}