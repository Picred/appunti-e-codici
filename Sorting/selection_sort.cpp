#include <iostream>
#include<cstdlib>

using namespace std;

void swap (int& x,int& y){
    int temp=x;
    x=y;
    y=temp;
}

void selection_sort(int* vett,int dim){
    int indexMin;
    
    for(int i=0;i<dim;i++){
        indexMin=i;
        for(int j=i+1;j<dim;j++){
            if(vett[j]<vett[indexMin]){
                indexMin=j;
            }
        }
        swap(vett[i],vett[indexMin]);
    }
}


int main(){
    int dim=10;
    int vett[dim];

    for(int i=0; i<10;i++){
        vett[i]=rand()%100;
    }

    cout << "Vettore non ordinato:" << endl;
    for(int i=0; i<10;i++){
        cout << vett[i] << " ";
    }
    cout << endl;
    selection_sort(vett,dim);

    cout << "Vettore ordinato:" << endl;
        for(int i=0; i<10;i++){
                cout << vett[i] << " ";
            }   
}

