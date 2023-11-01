# Socket (C o Java)

- Realizzare un server (in C o in Java) chiamato _Server A_ che si metta in ascolto sul port `7777` per ricevere una stringa `str` composta da una **sequenza di lunghezza arbitraria di caratteri numerici** da (_0 a 9_) e terminata dal carattere `\n`. Il server dovrà quindi stampare il messaggio ricevuto sullo standard output. Testare il server usando `telnet`

- Estendere le funzionalità dal server definito al punto precedente realizzando un secondo server chiamato _Server B_ che oltre a stampare il messaggio ricevuto sullo standard output, lo **invia come risposta al client** (_senza modificarlo_). Testare il server usando `telnet`.

- Estendere le funzionalità dal server definito al punto precedente realizzando un terzo server chiamato _Server C_ che oltre a stampare il messaggio ricevuto sullo standard output, lo passa ad un metodo `int MUL(String str)` che per ora **restituisce sempre 0** per qualunque parametro di input str. Il risultato del metodo deve quindi essere inviato come messaggio di risposta al client. Testare il server usando `telnet`.

- Estendere le funzionalità dal server definito al punto precedente realizzando un quarto server chiamato _Server D_ modificando il comportamento del metodo `int MUL(String str)` che dovrà restituire **il prodotto delle singole cifre numeriche** presenti nella stringa in input, ad esempio per la stringa `1234` restituirà l’intero `24`. Il risultato del metodo deve quindi essere inviato come messaggio di risposta al client. Testare il server usando `telnet`.

- _(Opzionale)_ Realizzare un semplice client per testare i server creati ai punti precedenti