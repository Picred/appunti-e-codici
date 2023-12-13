Implementare uno script in PHP che consenta di gestire un database di film. 
Il database di film dovrebbe avere i seguenti campi:

`Titolo | Anno | Paese | Regista`

Le funzioni richieste sono:

- `CreateFilm()`: Permette di **inserire un nuovo** record nel database con le informazioni specificate.

- `ReadAllFilms()`: Restituisce **tutti i film** presenti nel database.

- `UpdateFilm()`: **Aggiorna** le informazioni di un film nel database in base al vecchio titolo.

- `DeleteFilm()`: **Elimina** un film dal database in base al titolo.

```sql
CREATE DATABASE cinema;
```

```sql
CREATE TABLE films (
  id INT PRIMARY KEY AUTO_INCREMENT,
  titolo VARCHAR(255) NOT NULL,
  anno VARCHAR(255) NOT NULL,
  paese VARCHAR(255) NOT NULL,
  regista VARCHAR(255) NOT NULL
);
```