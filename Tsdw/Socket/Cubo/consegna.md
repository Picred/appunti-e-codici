# Tecniche di Programmazione Concorrente e Distribuita  24/05/2016
### Socket (C o Java)

Scrivere un server che si metta in ascolto sul port `3333` in grado di rispondere ad un messaggio composto da una sola stringa 
`str` composta da cifre numeriche (da 0 a 9) terminata dal carattere `\n`.

Il server:
- Converte la stringa ricevuta _str_ in un numero intero _n_.
- Il numero viene usato come input per il metodo `int cubo(int n)` che restituisce il cubo dell’intero _n_.
- Invia al client il valore restituito dal metodo `cubo()`. 

- Testare il server con un semplice client o con telnet.

- Tempo a disposizione: 35 minuti.
