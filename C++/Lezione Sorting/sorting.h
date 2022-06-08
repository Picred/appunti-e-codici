#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void selectionSort (int array[], int n){
    int indexMin;

    for(int i=0; i<n; i++){
        indexMin=i;
            for(int j=i+1; j<n; j++){
                if( array[j] < array[indexMin] ){
                    indexMin=j;
                }
            }
        swap(array[i],array[indexMin]);
    }
}


void printArray(int array[], int n){
    for (int i=0; i<n; i++){
        cout << array[i] << "\t";
    }
    cout << endl;
}


void ordinamento (int array[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if( array[j] < array[i] ){
                swap(array[i],array[j]);
            }
        }
    }
}

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