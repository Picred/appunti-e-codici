Il database mySql myDB contiene le tabelle `flist` (lista dei film) e `wlist` (lista dei film desiderati).
Le tabelle sono uguali e hanno i seguenti campi: titolo `VARCHAR(30) NOT NULL` e regista `VARCHAR(30)`.

Implementare mediante PHP una o più pagine web che presentino:
- una sezione con un titolo a caso cercato in flist scritto sotto:`<h1>film consigliato:</h1><br>`
- una sezione con un **form** con due campi input: `film` e `regista` e un pulsante `submit` che aprirà la stessa o un’altra pagina inviandole i dati del form col metodo **`POST`**.

Una volta ricevuti i dati, viene eseguita una query che cerca record di `flist` con titolo o regista corrispondenti a quelli inseriti.

---

**Se esiste** almeno un risultato:
- viene **stampato** sotto la scritta:`<h1>film richiesto/i:</h1><br>` 
- viene fornito **un link per tornare indietro**

**Altrimenti**:
- se il **titolo non esiste** nella `wlist` allora viene chiesto se si vuole aggiungere il film richiesto nella `wish list`, mediante un **form** con due pulsanti submit: `si` e `no`.

La pressione del bottone `si` determina l’inserimento di `titolo` e `regista` nella tabella `wlist`, la pressione del bottone `no` **reindirizza alla pagina iniziale**

--- 

**Bonus**:
- **inserire un link** o un pulsante in un form che mostra nella stessa o in una nuova pagina:
-  la **wish list**
- un **pulsante per svuotarla**
- un **link per tornare indietro**

Dati per connettersi al database:
- `$servername` = "localhost";
- `$username` = "username";
- `$password` = "password";
- `$dbname` = "myDB";

>Funzione per numero causale: `rand(int $min, int $max): int`

***Suggerimento**: il form con i due pulsanti `si` e no dovrebbe anche ritrasmettere il `titolo` e il `regista`*

Query per creare il database

```sql
CREATE TABLE flist (titolo VARCHAR(30) NOT NULL, regista VARCHAR(30));

INSERT INTO `flist` VALUES ('Blade Runner','Ridley Scott'),('I predatori dell\'arca perduta','Steven Spielberg'),('Star Wars','George Lucas'),('Ritorno al futuro','Robert Zemeckis'),('Frankenstein Junior','Mel Brooks'),('Alien','Ridley Scott'),('The Goonies','Richard Donner'),('Il senso della vita','Terry Jones - Terry Gilliam');

CREATE TABLE wlist (titolo VARCHAR(30), regista VARCHAR(30));
```