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

int main(){
    int vett[dim];

    for(int i=0; i<dim; i++){
        vett[i] = i;
    }

    //0 1 2 3 4 5 6 7 8 9

    cout << dicotomicaRicorsiva(vett,7,0,dim-1); //true se lo trova, false se non lo trova

}