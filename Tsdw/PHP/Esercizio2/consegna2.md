
**Servizio** 
Il servizio *mysql* è già attivo (in ascolto sulla porta `3306` e l’interfaccia di `loopback`); mysql è già dotato di un database **exam** e un utente **user** con password **password** e privilegi su **exam**.

**Operazioni necessarie all’avvio**
Sono raccolte nel file `init.sh`. All'inizio della prova vanno eseguite dal terminale, nella home directory dell’utente, in modalità batch con: `sh ./init.sh`

*Tra le azioni così eseguite, è rilevante il **setup del DB**, che si può anche ottenere, a mano, eseguendo nella home directory dell’utente:* `mysql -uuser -ppassword exam < books.sql`

**Tabella books**: a questo punto, grazie al setup appena eseguito, sarà presente, nel database exam, la tabella books(, già popolata, avente schema SQL:
```sql
books (
    id        int auto_increment primary key,
    isbn      varchar(15) unique not null,
    title     varchar(128) not null,
    author    varchar(64),
    publisher varchar(64),
    ranking   int,
    year      int,
    price     float
);
```

Consegne -> *Implementare*:
- il **codice per la business logic** lato server e l’**invio al browser del codice HTML** che consenta l’interazione necessaria da parte dell’utente che assicurino le **funzionalità “CRUD”** descritte di seguito.

***Funzionalità Richieste (NB: sono R e C in CRUD)***
1. Visualizzare sul browser un **form HTML con un bottone** che, **cliccato**, riceva dal server e **visualizzi la lista dei record** presenti nella tabella books.
2. Visualizzare sul browser un **form HTML che permetta l’inserimento di un nuovo record** nella tabella **books**; **dopo l’inserimento**, il browser **mostrerà la lista dei record presenti**, per consentire la verifica del precedente inserimento.
***Funzionalità Facoltative (NB: sono U e D in CRUD)***
3. Nella lista di record ricevuta dal server come in (1), come codice HTML, si renda, per ciascun record, l’attributo *isbn* un **link**, che, cliccato, porta a un **form di aggiornamento del record di provenienza**
4. Aggiungere, in quest’ultimo form di aggiornamento di un record, un **bottone per l’eliminazione del record stesso dalla tabella books.**

***Ambiente**: il codice dinamico descritto sopra deve essere realizzato sia (interamente) in PHP che (interamente) mediante Java servlet.*

***Struttura**. Il codice lato server necessario può essere distribuito in un numero arbitrario di componenti dinamici (cioè script PHP o servlet Java) e/o statici (cioè file HTML).* 

*A titolo di esempio, si potrebbe realizzare un unico file PHP che implementi tutta la business logic e invii l’HTML per visualizzare il bottone (1) e il form (2), oppure, in alternativa,  un file PHP per ciascuna funzionalità, un file HTML per il bottone (1) e un altro per il form (2).*

>*Lo stesso può dirsi per le servlet: si possono avere servlet multiple o una sola servlet (che comunque sarebbe strutturata nei metodi doGet(), doPost(), …)*

## Eventuali query (per esercitarsi)
```sql
create table books (
    id        int auto_increment primary key,
    isbn      varchar(15) unique not null,
    title     varchar(128) not null,
    author    varchar(64),
    publisher varchar(64),
    ranking   int,
    year      int,
    price     float
);
```


```sql
INSERT INTO books
(isbn, title, author, publisher, ranking, year, price)
VALUES
('978-1501180254', 'The Lord of the Rings', 'J.R.R. Tolkien', 'HarperCollins', 1, 1954, 25.99),
('978-0451531374', 'To Kill a Mockingbird', 'Harper Lee', 'Hachette Book Group', 2, 1960, 14.99),
('978-0544160888', 'The Catcher in the Rye', 'J.D. Salinger', 'Little, Brown and Company', 3, 1951, 10.99),
('978-0446672206', '1984', 'George Orwell', 'Penguin Random House', 4, 1949, 12.99),
('978-0395725734', 'The Great Gatsby', 'F. Scott Fitzgerald', 'Scribner', 5, 1925, 18.99),
('978-0446529601', 'Pride and Prejudice', 'Jane Austen', 'Penguin Classics', 6, 1813, 17.99),
('978-0451526146', 'The Adventures of Sherlock Holmes', 'Arthur Conan Doyle', 'Random House', 7, 1892, 15.99),
('978-0394754950', 'The Grapes of Wrath', 'John Steinbeck', 'Penguin Books', 8, 1939, 12.99),
('978-0316014718', 'To Kill a Mockingbird', 'Harper Lee', 'Hachette Book Group', 9, 2012, 14.99),
('978-0547875380', 'Harry Potter and the Sorcerer\'s Stone', 'J.K. Rowling', 'Scholastic Press', 10, 1997, 13.99);
```