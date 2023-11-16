//ricerca dicotomica

#include <iostream>

using namespace std;

//binary Search
//è sottinteso che l'array è ordinato già
bool ricercaBinaria(int array[] ,int n, int key){
	bool found = false;
	//verificare ad ogni iterazione se key>=array[n/2]
	// int midpoint = n/2; //floor(n/2)
	int start = 0;
	int end = n;
    

    while( !found && (start!=end) ){
        int midpoint = start+ ((end-start)/2); // è uguale (start+end)/2 

        
        cout << "start=" << start << ", end=" << end << " midpoint=" << midpoint << endl;

        if(array[midpoint]==key) 
            found=true;
        else if (key < array[midpoint]){
            //considerare la metà inferiore
            //aggiornare end, midpoint
            end=midpoint;
            // midpoint=(end-start)/2;
        }
        else {
            //considerare la metà superiore
            //aggiornare start e midpoint
            start=midpoint+1;
            // midpoint=(end-start)/2;
        }
    }

    return found;

}

int main(){
    int array[]={1,2,3,4,5,6,7,8,9,10};

    cout << ricercaBinaria(array,10,7);
}