<?php 
    $conn = new mysqli('localhost', 'newuser', 'password', 'University');

    if($conn->connect_error)
        die('Errore durante la connessione');
    
    function showStudents($conn){
        $sql = 'SELECT * FROM students;';

        $res = $conn->query($sql);
        if($res->num_rows>0){
            while($row = $res->fetch_assoc()){
                print $row["matricola"] ." " . $row["nome"] .  " " . $row["cognome"] . " " . "<a href=showcdl.php?cdl=" . $row["corso_di_laurea"] . ">" . $row["corso_di_laurea"]. "</a>" . "<br>";
                print "<form action=index.php?matricola=" . $row['matricola'] . " method='POST'>";
                print "<input type='text' name='newcdl' placeholder='Nuovo cdl'>";
                print "<input type='submit' name='changecdl' value='Cambia'></form>";
            }
        }
        else{
            print "<h3>Tabella studenti vuota </h3>";
            print "<a href=index.php>Homepage</a>";
        }
    }

    function insertStudent($conn, $nome, $cognome, $cdl){
        $sql = "INSERT INTO students (nome, cognome, corso_di_laurea) VALUES ('$nome', '$cognome', '$cdl')";
        
        if($conn->query($sql))
            print "Inserimento avvenuto con successo.";
        else
            print "Inserimento fallito.";

        print "<br><a href=index.php>Homepage</a>";
    }
?>