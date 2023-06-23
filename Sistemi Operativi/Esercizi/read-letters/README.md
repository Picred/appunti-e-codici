# Consegna

Implementa un programma che utilizzi i thread per leggere un file di testo e analizzare il suo contenuto lettera per lettera. Il programma dovrà trasformare ogni lettera in minuscolo e attivare il thread corrispondente, denominato AL (A-L) o MZ (M-Z), in base al valore della lettera.

I thread AL e MZ dovranno accedere a una struttura dati condivisa di tipo `shared_stats_t`, che conterrà i seguenti campi:

- `STATS_al`: un intero che rappresenta il numero di lettere presenti nella porzione di testo compresa tra le lettere A e L.
- `STATS_mz`: un intero che rappresenta il numero di lettere presenti nella porzione di testo compresa tra le lettere M e Z.
- `done`: un flag che indica se l'elaborazione del file è terminata.

I thread dovranno aggiornare i campi `STATS_al` e `STATS_mz` in base alle lettere che elaborano. Inoltre, dovrai utilizzare dei semafori per garantire la corretta sincronizzazione tra i thread e l'accesso condiviso alla struttura dati.

Il thread MAIN dovrà eseguire la seguente funzione:

```c
void main_function(void* arg)
```
Questa funzione leggerà il file di testo carattere per carattere utilizzando la chiamata di sistema read(). Ogni carattere letto verrà trasformato in minuscolo utilizzando la funzione ```tolower()``` della libreria ```<ctype.h>```. Successivamente, il carattere verrà inviato al thread corrispondente (AL o MZ) in base al suo valore. Nel caso in cui il carattere letto sia una lettera compresa tra A e L, verrà inviato al thread AL; se il carattere è una lettera compresa tra M e Z, verrà inviato al thread MZ.

Se viene raggiunta la fine del file, il thread MAIN imposterà il flag done della struttura ```shared_stats``` su DONE. Successivamente, verranno inviati dei segnali ```(sem_post())``` ai thread AL e MZ per notificare loro la fine dell'elaborazione.

Il thread AL eseguirà la seguente funzione:

```c
void al_function(void* arg)
```

Questa funzione utilizzerà un loop infinito per ricevere i caratteri inviati dal thread MAIN tramite un semaforo ```sem_al```. Ogni volta che riceve un carattere, incrementerà il campo ```STATS_al``` della struttura ```shared_stats```

Successivamente, invierà un segnale al thread MAIN per indicare la fine dell'elaborazione del carattere (sem_post()). Se viene ricevuto un segnale di fine elaborazione (done), il thread AL terminerà l'esecuzione.

Il thread MZ eseguirà la seguente funzione:

```c
void mz_function(void* arg)
```

Questa funzione avrà un comportamento simile a al_function, ma lavorerà sui caratteri compresi tra le lettere M e Z e incrementerà il campo `STATS_mz` della struttura shared_stats.

Alla fine dell'elaborazione, il thread `MAIN` dovrà stampare il numero di lettere presenti nella porzione di testo compresa tra le lettere A e L `STATS_al` e il numero di lettere presenti nella porzione di testo compresa tra le lettere M e Z `STATS_mz`.

Assicurati di gestire correttamente la creazione e la terminazione dei thread utilizzando le funzioni `pthread_create()` e `pthread_join()`. Inoltre, utilizza la chiamata di sistema `open()` per aprire il file di testo specificato come argomento sulla linea di comando.

Nella realizzazione del programma, presta attenzione alla corretta sincronizzazione tra i thread e all'accesso condiviso alla struttura dati shared_stats. Utilizza i semafori `sem_al`, `sem_mz` e `sem_main` per garantire la sincronizzazione e proteggere l'accesso condiviso.

Infine, sii attento alle best practices di programmazione ad oggetti utilizzando strutture dati appropriate e definendo le funzioni come metodi dei thread.

Sarai valutato sulla corretta implementazione del programma, sulla correttezza logica e funzionale, sull'efficienza delle soluzioni proposte e sulla capacità di gestire gli aspetti di concorrenza e sincronizzazione tra i thread.