#include<iostream>

using namespace std;


void insertionSort(int array[], int n){
    int temp, j;

    for(int i=1; i<n; i++){ //considero il primo elemento già ordinato
        temp=array[i];
        for(j=i; j>0; j--){
            if(temp<array[j-1]){
                array[j] = array[j-1];
            }
            else{
                break;
            }
        }
        array[j]=temp;
    }
}


int main(){
    int vett[]={10,9,8,7,6,5,4,3,2,1};

    int dim= sizeof(vett)/ sizeof(int);

    for(int i=0; i<dim; i++){
        cout << vett[i] << " ";
    }
    cout << endl << endl;

    insertionSort(vett,dim);
    for(int i=0; i<dim; i++){
        cout << vett[i] << " ";
    }
}