//Per compilare l'intero programma: "g++ PTR_13.cpp array_ptr.cpp" 
//oppure aprire un progetto su dev-C++ e includere il file header, il file 
//sorgente PTR_13.cpp ed il file sorgente array_ptr.cpp 

#include <iostream>

using namespace std;

int main(){

    int maxsize=5;

    int *iptr;  //pointer to the dynamic array
    int  *iptrold; // auxiliary pointer

    int num;  //get input by the user

    iptr = new int[maxsize]; // allocazione array

    int count=0;

    cout<<"\nEnter a number: "; // chiede il primo numero all'utente
    cin>>num;

 while(!cin.eof()) // per finire basta premere CTRL-d
    {
        if (count < maxsize)
        {
            iptr[count] = num; // OK, conserva il valore nel primo posto disponibile 
            count++; // e incrementa il contatore
        }
	else
        {
            cout<<"\nReached maxsize"<<endl;
            iptrold=iptr; // conserviamo il puntatore all'area di memoria attuale
            iptr = new int[maxsize*2]; // nuova area di memoria
            for (int i=0; i<maxsize; i++) // copia i valori nella nuova area di memoria 
	      *(iptr+i) = *(iptrold+i);

	    delete[] iptrold; //libera area puntata da iptrold
            iptrold=NULL; // adesso iptrold e' NULL
  
            iptr[count] = num; //conserva il valore
            count++; // incrementa il contatore
            maxsize=maxsize*2; // aggiorna maxsize

        }
        cout<<"\nEnter a number: ";
        cin>>num;
  }
}


