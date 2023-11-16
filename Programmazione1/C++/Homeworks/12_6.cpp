/*
12.6
Scrivere un programma in C++ finalizzato al calcolo dei valori di
dosaggio per la ricetta di un dolce.

Il programma chiede all’utente di inserire un numero compreso tra 2 e 16
che rappresenta il numero di persone che mangeranno il dolce.

Il programma chiede all’utente di inserire un valore che indica se tra i
commensali ci sono diabetici.

Il programma calcola il dosaggio nel seguente modo:
A dosaggio “base”, per un numero di persone compreso tra 2 e 4
(estremi inclusi): 0.3kg di farina, 4 uova, 0.1kg di zucchero.

B dosaggio “medio”, per un numero di persone compreso tra 5 e 8
(estremi inclusi). 2 volte e mezzo il dosaggio base per la farina e le
uova, 1 volta e mezzo il dosaggio base di zucchero.

C dosaggio “esteso”, per un numero di persone compreso tra 9 e 16
(estremi inclusi): in questo caso il dosaggio andrà calcolato come la
somma dei dosaggi dei due casi precedenti (medio e base).

Inoltre:
• se ci sono diabetici tra i commensali, usare il fruttosio al posto dello
zucchero, e la dose sar`a la seguente:
dosaggio Fruttosio = 2/3 × dosaggio Zucchero.
• il numero di uova vanno arrotondati sempre per eccesso (es:
2.1 → 3, 2.9 → 3, 9.45 → 10).
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main () {
		
	int persone;
	bool diabetici;
	char risposta; //diabetici si/no
	double farinaB, uovaB, zuccheroB; //ingredienti Base
	double farinaM, uovaM, zuccheroM; //dosaggi Medi
	double farinaE, uovaE, zuccheroE; //dosaggi Estesi
	double fruttosioB, fruttosioM, fruttosioE; 
	int iuovaB, iuovaM, iuovaE; //uova intere

	cout << "Inserisci il numero di persone che mangeranno il dolce(2-16): " << endl;
	cin >> persone;

	if (persone >=2 && persone <=16) { //numero di persone nel range 2-16?
	
	cout << "Ci sono diabetici? (y/n)" << endl;
	cin >> risposta;

			if (risposta=='y') {diabetici=true;}

			if (risposta=='n') {diabetici=false;}

			//calcolo la dose BASE
			farinaB=0.3; uovaB=4.0; zuccheroB=0.1;
			iuovaB=uovaB+0.5;

	if (persone>=2 && persone <=4) {	//dosaggio base?
		
		cout << "Il dosaggio base per 2-4 persone e' il seguente: " << endl;
		cout << "Uova: " << iuovaB << endl;
		cout << "Farina: " << farinaB << " kg" << endl;
				
				if (diabetici==false) {
					cout << "Zucchero: " << zuccheroB << " kg" << endl;}
				else {
					fruttosioB=zuccheroB*2;
					fruttosioB=fruttosioB/3;
					cout << "Visto che ci sono diabetici, usa il fruttosio al posto dello zucchero nella seguente quantita': " \
						<< fixed << setprecision(2) << fruttosioB << " kg" << endl; } }

			//calcolo dosaggio medio
			farinaM=farinaB*2.5; uovaM=uovaB*2.5; zuccheroM=zuccheroB*1.5;
			iuovaM=uovaM+0.5;


							if (persone>=5 && persone <=8) {	//dosaggio medio?
			
							cout << "Il dosaggio medio per 5-8 persone e' il seguente: " << endl;
							cout << "Uova: " << iuovaM << endl;
							cout << "Farina: " << farinaM << " kg" << endl;
								if (diabetici==false) {
								cout << "Zucchero: " << zuccheroB << " kg" << endl;}
								else {
								fruttosioM=zuccheroM*2;
								fruttosioM=fruttosioM/3;
								cout << "Visto che ci sono diabetici, usa il fruttosio al posto dello zucchero nella seguente quantita': "\
								<< fixed << setprecision(2) << fruttosioM << " kg" << endl; } }
		
			//calcolo dosaggio esteso, somma dei precendti dosaggi
			farinaE=farinaB+farinaM;
			uovaE=uovaB+uovaM;
			zuccheroE=zuccheroB+zuccheroM;
			iuovaE=uovaE+0.5;


		if (persone>=9 && persone <=16) {	//dosaggio esteso?
			cout << "Il dosaggio esteso per 9-16 persone e' il seguente: " << endl;
			cout << "Uova: " << iuovaE << endl;
			cout << "Farina: " << farinaE << " kg" << endl;
				if (diabetici==false) {
					cout << "Zucchero: " << zuccheroE << " kg" << endl;}
				else {
					fruttosioE=zuccheroE*2;
					fruttosioE=fruttosioE/3;
					cout << "Visto che ci sono diabetici, usa il fruttosio al posto dello zucchero nella seguente quantita': " \
						<< fixed << setprecision(2) << fruttosioE << " kg" << endl; } }
									
							
									
	} 	
	

	else //range di persone 2-16 superato

	{

	cout << "Hai inserito un valore fuori dal range, riavvia il programma e ritenta."; // Input errato range di persone 2-16
	
	}
	
	return 0;
}