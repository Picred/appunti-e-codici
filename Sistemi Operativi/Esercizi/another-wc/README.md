Creare un programma another-wc.c in linguaggio C che accetti invocazioni sulla riga di
comando del tipo:
```bash
$ another-wc [file di testo]
```


- Questo programma al suo avvio creerà un processo figlio. Tale processo comunicherà con il padre tramite un **segmento di memoria condivisa** grande al più **2 byte**. Per una corretta comunicazione sarà necessario l'utilizzo di semafori: utilizzarne il numero ritenuto strettamente necessario e nel modo ritenuto più appropriato.

- Il processo figlio leggerà il contenuto del `file` di testo indicato come *unico parametro* (*o dallo standard input in sua assenza*) e dovrà passare il suo contenuto al processo padre `byte-per-byte`.

- Il padre dovrà elaborare il contenuto ricevuto facendo un'analisi simile a quella effettuata dal comando UNIX `wc`: conteggiando il numero di caratteri, parole e righe.

>Considerare come delimitatori di parole gli spazi/tabulazioni e i principali segni di interpunzione (.,;:!).

- Alla fine i processi dovranno terminare spontaneamente, rilasciando qualunque struttura dati persistente.

***Suggerimento***: utilizzare un secondo byte all'interno della memoria condivisa per segnalare al padre la fine del flusso proveniente dal figlio.

*Un esempio ipotetico di invocazione potrebbe essere il seguente:*
```bash
$ another-wc /etc/passwd
    # 31 49 1534 /etc/passwd
```