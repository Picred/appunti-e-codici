/* 12.7
Tre vasche A, B e C raccolgono acqua da 15 tubi differenti.
• La vasca A riceve l’acqua convogliata nei tubi 1,5,6,10.
• La vasca B riceve l’acqua convogliata nei tubi da 2 a 4 e da 7
a 9.
• La vasca C riceve l’acqua convogliata nei rimanenti tubi.
Inoltre, i tubi con numero dispari hanno una portata di 60 litri al
minuto, mentre quelli con numero pari hanno una portata di 120
litri al minuto.

Codificare un programma in linguaggio C++ che esegua le seguenti
operazioni:
• il programma chiede in input all’utente 5 numeri distinti, compresi
tra 1 e 15. Tali numeri rappresentano 5 differenti tubi. NB: il
programma deve operare un controllo sulla validit`a dell’input (ad
esempio che i numeri siano tutti differenti tra loro);
• il programma chiede all’utente il numero totale di minuti (M)
durante i quali i tubi specificati forniranno acqua alla rispettiva
vasca. NB: il programma deve operare un controllo sulla validit`a
dello input, ad esempio che il numero immesso sia positivo.
• il programma calcola e stampa la quantit d’acqua raccolta in ogni
vasca dopo gli M minuti speficicati dall’utente.
*/

#include <iostream>


#define PORTATA_PARI 60 // litri al minuto
#define PORTATA_DISPARI 120 // litri al minuto

using namespace std;

int main (){
	
	int vascaA=0, vascaB=0, vascaC=0;
	int tubo1, tubo2, tubo3, tubo4, tubo5;
	bool verifica=true;
	bool range=true;
	bool minutiPositivi=true;
	int i, j, k=0;
	int minuti=0;
	i=0; j=0; 
	
	// RICHIESTA INPUT
		cout << "Inserisci 5 numeri distinti da 1 a 15:";
		cin >> tubo1 >> tubo2 >> tubo3 >> tubo4 >> tubo5;
		int A[5] = {tubo1,tubo2,tubo3,tubo4,tubo5};
		

		cout << "Inserisci i minuti totali di riempimento delle vasche: ";
		cin >> minuti;
		
			// VALIDITA' INPUT
		
				if (minuti<1){
					minutiPositivi=false;
				}

	if (tubo1<1 || tubo1>15){ // range e numeri positivi?
		cout << "Errore, hai inserito valori fuori dal range.(valore 1)" << endl;
		range=false;
	}
	if (tubo2<1 || tubo2>15){
		cout << "Errore, hai inserito valori fuori dal range.(valore 2)"<< endl;
		range=false;
	}
	if (tubo3<1 || tubo3>15){
		cout << "Errore, hai inserito valori fuori dal range.(valore 3)"<< endl;
		range=false;
	}
	if (tubo4<1 || tubo4>15){
		cout << "Errore, hai inserito valori fuori dal range.(valore 4)"<< endl;
		range=false;
	}
	if (tubo5<1 || tubo5>15){
		cout << "Errore, hai inserito valori fuori dal range.(valore 5)"<< endl;
		range=false;
	} 
	
		while (i<5 && verifica){ //numeri diversi fra loro?
			j=i+1;
				while (j<5 && verifica) {
					if (A[i] != A[j]){
						verifica=true;
					}
					else { 
						verifica=false;
						cout << "Hai inserito due numeri uguali, riavvia il programma." << endl;
					}
					j++; 
				}
				i++;
		}
	//	cout << "range1-15: " << range << " " << "Numeri diversi fra loro?: "<< verifica << " " << "Minuti positivi: " << minutiPositivi; // DEBUG VALIDITA' INPUT	
		
		// CALCOLI RIEMPIMENTO VASCHE
		i=0;
		
		if (range && verifica && minutiPositivi) {
		
		while (i<5) {
		
		
// VASCA A
		if (A[i]==1 || A[i]==5 || A[i]==6 || A[i]==10){
			if (A[i]%2==0){
			
				vascaA=PORTATA_PARI*minuti; }
			else {
				vascaA=PORTATA_DISPARI*minuti;}
		}
			
				
				
//VASCA B	
		if ((A[i]>=2 && A[i]<=4) || (A[i]>=7 && A[i]<=9)){
				if (A[i]%2==0){
					vascaB=PORTATA_PARI*minuti;
				}
				else {
					vascaB=PORTATA_DISPARI*minuti;
				}
		}
	
	
// VASCA C	
		if (A[i]>=10 && A[i]<=15){
			if (A[i]%2==0){
				vascaC=PORTATA_PARI*minuti;
			} else {
				vascaC=PORTATA_DISPARI*minuti;
			}
		}
		i++;
		}
		
		// STAMPA DELLE CAPACITA' DELLE VASCHE
		
cout << "Con i dati da te inseriti si ha che:\n";
cout << "La vasca A, con i tubi " << tubo1 << "," << tubo2 << "," << tubo3 << "," << tubo4 << "," << tubo5 << " ha " << vascaA << " litri d'acqua dopo " << minuti << " minuti."<< endl;
cout << "La vasca B, con i tubi " << tubo1 << "," << tubo2 << "," << tubo3 << "," << tubo4 << "," << tubo5 << " ha " << vascaB << " litri d'acqua dopo " << minuti << " minuti."<<endl;	
cout << "La vasca C, con i tubi " << tubo1 << "," << tubo2 << "," << tubo3 << "," << tubo4 << "," << tubo5 << " ha " << vascaC << " litri d'acqua dopo " << minuti << " minuti."<< endl;
		
		}else 
		{
			cout << "Si e' verificato un errore, riavvia il programma e ritenta.";
		}
		
	return 0;
}