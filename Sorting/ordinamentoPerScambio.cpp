#include <iostream>
#include<cstdlib>

using namespace std;

void ordinamentoPerScambio(int vett[], int size){
    for(int i=0; i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(vett[j]<vett[i]){
                swap(vett[i],vett[j]);
            }
        }
    }
}

void swap(int& x, int& y){
    int temp=x;
    x=y;
    y=temp;
}

int main(){
    int dim=10;

    int vett[10];

    cout << "Vettore[ " ;
    for(int i=0; i<dim; i++){
        vett[i] = dim-i;
        cout  << vett[i] << " ";
    } 
    cout << "]" << endl << endl;

    cout << "Ordiniamolo.."<< endl;
    ordinamentoPerScambio(vett,dim);

    cout << "Vettore ordinato[ " ;
    for(int i=0; i<dim; i++){
        cout  << vett[i] << " ";
    } 
    cout << "]";

}