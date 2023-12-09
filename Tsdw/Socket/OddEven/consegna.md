#### Una variabile intera n, inizializzata a 0, è condivisa tra 2 thread `tO`, `tE`.

Il thread `tE`, ciclicamente:
- attende `200ms` (N.B.: la chiamata `Thread.sleep(t)` attende per `t` millisecondi)
- genera un **intero casuale pari** e **lo somma** alla variabile condivisa `n`
- se ha eseguito **almeno 10 cicli** e `n` **è pari** termina
- altrimenti ricomincia dal **passo (1)**, a meno che abbia già compiuto **1000 iterazioni**, nel qual caso termina.

Il thread `tO`, ciclicamente:
- attende `200ms` (N.B.: la chiamata Thread.sleep(n) attende per `n` millisecondi)
- genera un **intero casuale dispari** e **lo somma** alla variabile condivisa `n`
- se ha eseguito **almeno 10 cicli** e `n` **è dispari** termina
- altrimenti ricomincia dal **passo (1)**, a meno che abbia già compiuto **1000 iterazioni**, nel qual caso termina.


Il programma termina quando **tutti i thread** hanno terminato la propria esecuzione. I thread scriveranno di essere terminati. Possono anche visualizzare, a ogni ciclo, il valore trovato in n.

>Non ricorrere a un array di 2 thread per l’implementazione!

>Nel codice, **proteggere** opportunamente la variabile `n` dagli **accessi concorrenti**