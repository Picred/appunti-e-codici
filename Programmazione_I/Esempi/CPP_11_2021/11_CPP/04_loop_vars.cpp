#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  
  const int N=10;
  const int M=20;

  const int A = 34;
  const int B = 46;  

  const int K = 12345; 

  int evenNumber, oddNumber;
  
  //A - Stampare i numeri nell'intervallo [1,N] in ordine crescente
  //Verificare che il ciclo e' codificato correttamente
  cout << "Print Numbers from 1 to " << N << endl; 
  for(int b=0; b<=N; b++)
    cout << b << endl;

  //B - stampa i numeri nell'intervallo [1,M] in ordine decrescente 
  //Verificare che il ciclo e' codificato correttamente
  cout << "Print Numbers from "<< M << " to " << 1 << endl; 
  for(int c=M; c>=0; c--)
    cout << c << endl;

  //C - stampa i numeri nell'intervallo [A,B] in ordine crescente
  //Verificare che il ciclo e' codificato correttamente
  cout << "Print numbers from " << A << " to " << B << endl; 
  for(int j=A; j<B; j++)
    cout << j << endl;

  //D Stampa una griglia di NxM caratteri '&'
  //ovvero N righe di testo fatte di M caratteri '&', una dopo l'altra
  //Verificare che il ciclo e' codificato correttamente
  cout << "Print a grid " << N << 'x' << M << " of '&' "<< endl; 
  for(int j=1; j<N; j++)
    for(int j=1; j<M; j++)
      cout << "&"; 
    cout << endl;  

  //E Somma i numeri dispari finche' la somma non assume 
  //un valore maggiore o uguale del numero K
  cout << "Sum odd numbers until " << K << " is reached " << endl;
  int sum=1;
  oddNumber=1;
  while(sum<K){
    sum+=oddNumber;  
    oddNumber+=2;
  } 
  
  cout << "Sum: " << sum << endl;

  /* F
    stampa una griglia NxM di numeri nel seguente modo:
    - le righe ad indice pari sono fatte di M numeri dispari
    - le righe ad indice dispari sono fatte di M numeri pari 
    - il primo numero di ogni riga deve essere il successivo rispetto alla 
    sequenza della riga precendente avente indice con la stessa parita'. 

    Es: N=4, M=4 
      1 3 5 7 
      0 2 4 6 
      9 11 13 15
      8 10 12 14
  */

  cout << "[F]: Print a matrix NxM with odd numbers and even numbers " << endl;
  evenNumber = 0;
  oddNumber = 1;
  for(int j=0; j<N; j++){
    if(j%2==0) //indice di riga e' pari
      for(int k=0; k<M; k++){
	cout << oddNumber << " ";
	oddNumber+=2; 
      }
    else  
      for(int k=0; k<M; k++){
	cout << evenNumber << " ";
	evenNumber+=2;
      }  
    cout << endl;
  }
  
  //F1 Per incolonnare i numeri? 
  cout << "[F1]; Print a (beautiful) matrix NxM with odd numbers and even numbers " << endl;
  evenNumber = 0;
  oddNumber = 1;
  for(int j=0; j<N; j++){
    if(j%2==0) //indice di riga e' pari
      for(int k=0; k<M; k++){
	cout << setw(4) << oddNumber << " ";
	oddNumber+=2; 
      }
    else  
      for(int k=0; k<M; k++){
	cout << setw(4) << evenNumber << " ";
	evenNumber+=2;
      }  
    cout << endl;
  }

  //F2 scrivere il ciclo in modo differente (if vs for)?   
  cout << "[F2] Print a (beautiful) matrix NxM with odd numbers and even numbers (if vs for)" << endl;
  evenNumber = 0;
  oddNumber = 1;
  for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
	if(j%2==0){ //indice di riga e' pari
	  cout << setw(4) << oddNumber << " ";
	  oddNumber+=2; 
	}else{  
	    cout << setw(4) << evenNumber << " ";
	    evenNumber+=2;
	  }
      }
      cout << endl;
  }  
}
