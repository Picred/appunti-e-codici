## Comandi Shell

- echo ciao > output Redireziona l'output sul file indicato dopo la ">" e sovvrascrive tutto il file (se esiste guà)
- >> vuol dire che scrive sul file iniziando dalla sua fine
- 2> è l'operatore che prende il canale 2(errore).
    - man comandchenonesiste 2> output //scrive l'errore sul file
    - man comandochenonessite >output 2>1: prende l'output del comando e lo mette sul file "output" e il canale standard error lo mette sul descrittore di file "1"
    - Piu semplicemente man comandochenonesiste > output.txt 2> error.txt -> L'output lo mette su output.txt e gli eventuali errori su error.txt
    - Gli errori si potrebbero mettere sul "dispositivo" /dev/null che risulta essere un buco nero e serve per nascondere dei dati che non si vogliono vedere. Per esempio: man comandochenonesiste >output.txt 2> /dev/null e gli errori non si vedranno mai, appunto
- grep: è un FILTRO che è usato per ricercare all'interno di un file, o di output, di un certo testo

- Espressioni regolari: Una cerca riga inizia con una specifica parola o carattere -> si usa "^". 
    - grep "parola" file.txt -> cerca tutte le stringhe che contengono "parola" nel file specificati
    - grep "user" /etc/passwd cerca "user" all'interno del file che contiene tutti gli user del sistema

Per cercare all'interno del "man" si usa "/". quindi se cerco "-G" in una pagina di manuale uso /-G

Pipeline
Vengono fatte n fork e il comando viene eseguito per intero. Si usa "|"
- l'input del primo comando viene passato al secondo e cosi via
- comando | comando | ... | comando

WC
- conta i caratteri, parole e righe in un file, usando -c, -w, -l.

SORT
- ordina un cerco input. 

HEAD & TAIL
- head prende n righe iniziali da un file. 
- cat file.txt | head -n 10 mostra le prime 10 righe del file
- cat file.txt | tail -n 10 mostra le ultime 10 righe del file

TAR
- applicativo che permette di raggruppare i file senza compressione
- tar -c -t test.tar * crea l'archivio tar chiamato test.tar di tutti i file in quella directory. 
    - -c crea
    - -x estrae archivio nella directory attuale
    - -t elenca il contenuto dell'archivio

ALIAS
- alias test="echo ciao". quando scrivo test stampa "ciao"

## Modalità di esecuzione
- Quando si esegue un comando si riceve in output un exitcore (0-255). 0=tutto ok. >0=problema nell'esecuzione
- Ad ogni comando si fa una fork e il processo shell va in wait. Si sblocca quando finisce la fork.
- In caso di pipeline con n comandi, vengono eseguite n fork. Quindi n processi paralleli che comunicano fra loro tramite la Pipe, appunto. Ci saranno per la shell n wait in attesa di tutti i processi creati

- Per raggruppare i comandi si usa ";" 
- echo -n "ciao"; echo -n "mondo" -> -n indica, in echo, di non andare a capo

Operatori logici per combinare comandi c1, c2, c3...
- "&&" e "||"
- c1 && c2 -> se c1 restituisce l'exit status 0, allora viene eseguito c2. E' un'implicazione
- c1 || c2 -> se c1 fallisce, allora viene eseguito c2


Esecuzione asincrona
- "comando &" esegue un processo in background

Jobs (slide)

# Bash
Usa shell e include i costrutti della programmazione (if,for,while,..)

Uno script è un file che contiene una serie di operazioni fra quelle viste finora. Il file viene interpretato ed eseguito.
- "#!/bin/bash" specifica l'interprete per il file in questione e si mette in testa al file. Si usa per evitare di scrivere "bash file.sh" e usare ./file.sh direttamente

## Sintassi
- var=value dichiara una variabile. Non si usano spazi fra "=". Di default hanno scope globale
- $var si riferisce alla variabile dichiarata
- $# indica il numero di argomenti passati da command-line (argv)
- $i iesimo argomenti da command-line (argc)
- $* prende tutti gli argomenti da command-line ($IFS separa ogni argomento)
- $@ tutti gli argomneti racchiusi da doppi apici
- $? prende l'exit status dell'ultimo comando eseguito
- $! prende l'id dell'ultimo processo eseguito in bg
- var=$(comando) assegna a var l'output del comando eseguito
- echo "il numero di parole è: $parole" oppure echo "Il numero di parole é; $(ls * | wc -w)

Quoting
- \ elimina il significato del metacarattere che segue