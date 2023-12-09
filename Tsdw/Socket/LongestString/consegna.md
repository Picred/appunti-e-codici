# 10/11/2023. I Prova in itinere di TSDW
## Esercizio 1: Socket (C o Java) -- Tempo a disposizione: 30 minuti.
Realizzare un server (*in C o in Java*) che si metta in ascolto sul port `3333`, sul quale accetta richieste di connessione da un client. 
Sulla connessione stabilita, il **server attende una stringa**, terminata dal carattere `\n`.

*N.B. Questo riquadro grigio vi riguarda solo se sviluppate il server in C:* 
- potete supporre che al server basti una sola operazione di lettura per ricevere la stringa inviata dal client;
- potete, inoltre, se volete, omettere di verificare che la stringa ricevuta termini con `\n`.

- Il server, quindi, **stampa la stringa** ricevuta sullo **standard output** e, chiusa la connessione in corso, si **rimette in attesa** di eventuali nuove richieste di connessione. 
	- Chiamate il file sorgente `server_A.c` o `ServerA.java`, secondo i casi. Testate questo `server_A` usando telnet. 
- Conservando la versione (A) del server, realizzatene un’ulteriore versione (B), tale che **per ciascuna stringa ricevuta**, il server, oltre a stamparla sulla propria standard output, **la invii nuovamente** (senza alcuna modifica) al client come risposta. Quindi, `server_B` chiude la connessione e si **rimette in attesa** di eventuali nuove richieste di connessione.
	- Testate il server server_B usando telnet.
- Conservando la versione (B) del server, realizzatene un’ulteriore versione, `server_C`, identica a B, salvo che per la **risposta inviata al client**, che sarà **la stringa più lunga tra quelle** ricevute fino a quel momento (NB: il server C non invia al cliente anche la stringa appena ricevuta).
	- Testate il server server_C usando telnet.
- *(Opzionale, dà bonus)* Realizzate un semplice client per testare i server creati ai punti precedenti.
- Un ulteriore *bonus* è previsto se il client viene sviluppato nel linguaggio, tra C e Java, non adoperato in precedenza per i quesiti A-C.