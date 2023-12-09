#### Scrivere un programma in Java in cui tre thread aggiornano la stessa variabile globale condivisa `sample`, inizialmente posta a `50`.

- Ogni thread ciclicamente genera un numero casuale compreso tra `10 e 90` e prova a sovrascrivere il valore corrente di `sample`.

- Il thread mostra in output un messaggio che segue il modello “_Sono il thread X: sample valeva Y, adesso vale Z_”, con opportuni valori al posto di X, Y e Z.

- Se il valore casuale generato **è uguale** al valore attuale di sample il thread **termina** il suo ciclo, comunicando in output la propria terminazione.

- Quando tutti i thread sono terminati, il programma principale termina e mostra in output il **valore finale** di `sample`.