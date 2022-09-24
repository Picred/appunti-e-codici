/*
12.3
Codificare un programma in linguaggio C++ che chieda
all’utente di inserire da tastiera il proprio nome e cognome.
Successivamente il programma dovr`a stampare le seguenti
informazioni:
1. il primo e l’ultimo carattere del nome, il secondo ed il
terzo carattere del cognome.
2. una stringa formata da tutti i caratteri che sono presenti
sia nel nome che nel cognome. ES: se nome=”Mario”,
cognome= ”Rossi” lo output sar`a ”io”.

3. le segg. ulteriori informazioni:
a un messaggio che comunica all’utente se la prima
lettera del nome `e uguale all’ultima lettera del cognome.
b un messaggio che comunica all’utente se il numero di
caratteri del nome `e uguale al numero di lettere del
cognome.
c il numero di consonanti del nome e del cognome.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	string nome, cognome;
	int n, c, i=0, j;
	char caratteri, caratteriN, caratteriC;
	int consonanti=0;
	
	cout << "Inserisci il tuo nome: ";
	cin >> nome;
	
	cout << "Inserisci il tuo cognome: ";
	cin >>cognome;
	
	n=nome.length();
	c=cognome.length();
	
	cout << "Il primo carattere del tuo nome e': " <<nome.substr(0,1) << endl;
	cout << "Invece l'ultimo carattere del nome e': " << nome.substr(n-1,1) << endl;
	
	cout << "Il secondo carattere del cognome e': " << cognome.substr(1,1) << endl;
	cout << "Il terzo carattere del cognome e': " << cognome.substr(2,1) << endl;
	
	while (i<nome.length()){
		j=0;
			while (j<cognome.length()){
			
				if (nome[i]==cognome[j]){
					caratteri=nome[i];
					cout << "Carattere in comune:\t "<< caratteri << endl;
					}
			j++;
			}
		i++;
	}
	
	i=0;
	j=0;
	
	consonanti=0;
	while (i<n){
		caratteriN=nome[i];
					switch (caratteriN){
					
						case 'a': 
							break;
						case 'e':
							break;
						case 'i':
							break;
						case 'o':
							break;
						case 'u':
							break;
						default:
							consonanti=consonanti+1;
					}
		i++;
	}	
	
	while (j<c){
		
				caratteriC=cognome[j];
				switch (caratteriC){
					
						case 'a':
							break;
						case 'e':
							break;
						case 'i':
							break;
						case 'o':
							break;
						case 'u':
							break;
						default:
							consonanti=consonanti+1;
				}
		j++;
	}
			
		if (nome.substr(0,1)==cognome.substr(c-1)){
			cout << "La prima lettera del nome e' uguale all'ultima lettera del cognome." << endl;
		}
		else{
			cout << "La prima lettera del nome e' diversa dall'ultima lettera del cognome." << endl;
		}
		if (n==c){
			cout << "Il numeri di lettere del nome coincide con quelle del cognome." << endl;
		}
		else {
			cout << "Il numero di lettere del nome non coincide con quelle del cognome." << endl;
		}
		cout << "Il numero di consonanti del nome e del cognome e' pari a: " << consonanti;
		
	
}