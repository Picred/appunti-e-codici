### CREAZIONE REPOSITORY	
`git init` //inizializza i vari file ".git"
`git add static_fun.cpp` //aggiungo il file che mi interessa
`git status` //mostra situazione del registro
`git commit -m "first commit"`
`git status` // dice che non c'è nessun nuovo file perchè ho "freezato" la situazione e non ho il disallineamento
`git branch -M main` //varie rammificazioni nelle quali posso dividere il mio repository
`git remote add origin "link"` //la parte remota si trova a questo indirizzo
`git push -u origin main`

### GENERARE NUMERI RANDOM DOUBLE
```cpp

double min=0;
double max=50;

double r = min + (double) ((rand()) /( (double)((RAND_MAX/(max-min)))));
```

### Complessità degli algoritmi
- Ricerca Dicotomica -> θ(log2n)
- Ordinamento per scambio-> O(n²)
- Insertion Sort->O(n²)
- Selection Sort-> O(n²)
- Merge Sort -> θ(n logn) per ogni tipo di input ---> dove Merge->θ(n)
- Quick Sort-> **MIGLIORE** Partition divide esattamente a metà l'array, quindi ci saranno meno chiamate ricorsive θ(n logn) **PEGGIORE** θ(n²)->L'array è totalmente sbilanciato come divisione e una parte è formata da un solo elemento e l'altra parte da n-1 elementi  

- ### Operazioni su Liste:
	- Inserimento in testa, in coda -> $O(1)$
	- Inserimento in modo ordinato -> $O(n)$
	- Ricerca di un elemento -> $O(n)$
	- Eliminazione testa, eliminazione coda -> $O(n)$
	- Eliminazione nodo specifico $O(n)$
- ### Operazioni su Stack
	- `push()` -> $O(1)$ Si inserisce sempre in testa;
	- `pop()` -> $O(1)$ Si estrae sempre dalla testa
	- `getTop()` -> $O(1)$  
- ### Operazioni su StaticStack
	- `push()` -> $O(1)$ Si inserisce sempre in testa;
	- `pop()` -> $O(1)$ Si estrae sempre dalla testa
	- `getTop()` -> $O(1)$  
- ### Operazioni sui BST
	- $O(log n)$ perchè l'input si dimezza ad ogni chiamata.

- ### Operazioni sui grafi
	- Accesso a vertice mediante lista di adiacenza -> O(|V|)
	- Accesso a vertice mediante matrice di adiacenza -> O(1)
	- #### BFS
		- Inizializzazione -> $\Theta (V)$
		- Visita $O(|E|)$
		- Totale $O(∣V ∣) + O(∣E∣)$
	* #### DFS
		* Inizializzazione -> $O (V)$
		- Visita $O(|E|)$
		- Totale $O(∣V ∣) + O(∣E∣)$ 