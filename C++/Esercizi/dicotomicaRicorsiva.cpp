// Implementare la ricerca binaria (dicotomica) in maniera ricorsiva

#define DIM 10
#include<iostream>

using namespace std;


bool dicotomicaRicorsiva(int vett[DIM], int key, int start, int end){
    
    int midpoint;

    if(start>end){
        return false;
    }
    else{
        midpoint=((end+start)/2);


        if(vett[midpoint]==key){
            return true;
        } 
        else if(key<vett[midpoint]){
            end=midpoint-1;
            return dicotomicaRicorsiva(vett,key,start,end);
        }   
        else{
            start=midpoint+1;
            return dicotomicaRicorsiva(vett,key,start,end);
        }
    }
    return false;
}

int main(){
    int vett[DIM]={1,2,3,4,5,6,7,8,9,10};
    
    cout << (dicotomicaRicorsiva(vett,1,0,DIM-1)) << endl;
}

