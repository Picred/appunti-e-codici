# Titolo: Thread (C/C++ o Java) [Prova in Itinere 18/12/2019]

### Tempo a disposizione: 45 minuti

#### File da consegnare: Tutti i file sorgente prodotti (C/C++ o Java)

Scrivere in C/C++ o in Java un programma con due thread **T1** e **T2**. I thread hanno una **variabile condivisa x** inizializzata con un intero compreso tra 0 e 10 (*estremi inclusi*).

Il thread **T1** ha una **variabile privata m** ed esegue un ciclo infinito, comportandosi in ciascun ciclo come segue:
- Attende 100ms
- Genera un valore casuale intero compreso tra 0 e 10 (estremi inclusi) e lo memorizza in **m**
- Se **x** è uguale a `-1` termina l'esecuzione
- Altrimenti, confronta m con la variabile condivisa **x**:
- Se **m** e **x** coincidono stampa un messaggio "RISPOSTA CORRETTA", setta **x** a `-1` e termina l'esecuzione
- Se la differenza in valore assoluto tra **m** ed **x** è **maggiore di 5** stampa il messaggio "risposta MOLTO sbagliata" e si mette in attesa
- Altrimenti, stampa il messaggio "risposta sbagliata"

Il Thread **T2** invece:
- Attende 300ms
- Sveglia **T1**
- Se **x** è uguale a `-1`, termina l'esecuzione
- Altrimenti, ricomincia dal primo punto