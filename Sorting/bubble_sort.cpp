#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubblesort(int vett[], int dim){

    for(int i=0; i<dim-1; i++){
        for(int j=i+1; j<dim; j++){
            if(vett[i] > vett[j]){
                int temp=vett[i];
                vett[i]=vett[j];
                vett[j]=temp;
            }
        }
    }
}

int main(){
    srand(time(0));

    int vett[10];
    cout << "Vettore generato" << endl;
    
        for(int i=0; i<10; i++){
            vett[i]=rand()%500;
            cout << vett[i] << " ";
        }

    cout << endl << "Vettore ordinato" << endl;

    bubblesort(vett,10);

    for(int i=0; i<10; i++){
            cout << vett[i] << " ";
        }
    
    return 0;
}