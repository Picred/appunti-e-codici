### <font color="cyan">Ordinamento e ricerca</font>
- Implementare la ricerca binaria (dicotomica) in maniera ricorsiva.
- Implementare l’ordinamento per scambio in maniera ricorsiva.
- Implementare il quicksort.

### <font color="lightblue">Classi</font>
- Definire una classe **Persona** con gli attributi *nome*, *cognome*, *eta*, *email*. 
    Definire inoltre il costruttore di default, 
    un costruttore "completo", e un costruttore di copia.
- Scrivere una classe template che prenda due tipi di dato generici e li
    utilizzi come tipi di dato per due attributi della classe stessa.
    Scrivere metodi set e get e un metodo di stampa, oltre al costruttore.
- Definire classe Studente che ha le seguenti proprietà:
	- nome, cognome, età, media;
	- quindi aggiungere gli oggetti Studente ad una coda. Generare N istanze di tipo Studente e simulare un'appello d'esame dove la media per ogni studente verrà assegnata.
	- Di conseguenza stampare a schermo gli studenti che hanno terminato l'appello con le relative medie aggiornate.
### <font color="orange">ADT's</font>
- Modificare il codice dell’inserimento ordinato `insertInOrder(T val)`
    (inserimento in modo ordinato di un nodo in una Lista semplicemente linkata)
    in modo che sia possibile inserire sia in ordine **ascendente** 
    che in ordine **discendente**. 
    Suggerimento: scrivere **due nuovi metodi** e selezionare l’inserimento.
- Aggiungere alla classe List un **contatore** che tenga conto del **numero di 
    elementi** (nodi) inseriti e quindi della dimensione della lista.
-  Aggiungere un **puntatore alla coda** e modificare tutti i metodi che accedono alla coda.
- Implementare l’operatore di accesso ( `operator[]` ) sfruttando la conoscenza del
    numero di elementi inseriti (potrebbe richiedere modifiche al nodo).
    *Hint*: Il contatore va aggiunto alla classe “List”
- <details>
  <summary> Valutare la complessità computazionale di inserimento e cancellazione sia
    della lista implementata a lezione che della lista con le modifiche apportate.</summary>
    1. Liste semplici. Se inserisco inserHead() mi costa 1 perchè ho il puntatore alla testa O(1)
    2. Se inserisco in coda `insertTail()` perchè per inserire un nodo a fine lista devo scorrere tutta la lista O(n) dove n è il numero di elemento 
    3. se faccio insert tail con puntatore alla coda, la complessità è sempre O(1) perchè non scorro la lista di n elementi; 
    4. removetail O(n) 
    5. removeTail() con ptr alla coda O(n) perchè comunque devo scorrere la lista visto che non ho Node  prev;*
    6. removeHead → O(1) 
    7. remove(elemento in mezzo alla lista) O(n)

</details>
- Definire l'overload dell’operatore `<<` specifica per una Stack in modo da 
    avere una corretta rappresentazione di essa.



