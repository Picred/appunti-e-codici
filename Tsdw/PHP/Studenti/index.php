<!DOCTYPE HTML>
<html>
<body>
<?php
    require 'functions.php';

    if($_SERVER['REQUEST_METHOD'] === 'GET'){
        showStudents($conn);
?>
        <h2>Inserisci un nuovo studente:</h2>

        <form action="index.php" method="POST">
            <input type="text" name="nome" placeholder="nome">
            <input type="text" name="cognome" placeholder="cognome">
            <input type="text" name="cdl" placeholder="Corso di Laurea">
            <input type="submit" name="insert" value="Inserisci">
        </form>

        <h2>Elimina studente:</h2>
        <form action="index.php" method="POST">
        <input type="number" name="matricola" placeholder="Matricola">
        <input type="submit" name="delete" value="Elimina studente">
        <?php
    }

    if($_SERVER['REQUEST_METHOD'] === 'POST'){
        if(isset($_POST['insert']))
            insertStudent($conn, $_POST['nome'],$_POST['cognome'],$_POST['cdl']);
        
        if(isset($_POST['changecdl'])){
            $new_cdl = $_POST['newcdl'];
            $matricola = $_GET['matricola'];

            $sql = "UPDATE students SET corso_di_laurea='$new_cdl' WHERE matricola='$matricola'";
            if($conn->query($sql))
                print "Aggiornamento effettuato con successo.";
            else
                print "Aggiornamento fallito.";
            print "<a href=index.php>Homepage</a>";
        }

        if(isset($_POST['delete'])){
            $matricola = $_POST['matricola'];
            ?> 
            <form action="index.php?matricola=<?= $matricola?>" method='POST'>
            <input type="submit" name="si" value="Sono sicuro">
            <input type="submit" name="no" value="Ho sbagliato">
            <?php
        }

        if(isset($_POST['si'])){
            $matricola = $_GET['matricola'];
            $sql = "DELETE FROM students WHERE matricola=$matricola";
            if($conn->query($sql)){
                print "Query andata a buon fine";
                print "<br><i>La matricola indicata potrebbe anche non esistere</i>";
            }
            else
                print "Errore durante la cancellazione dello studente avente matricola $matricola";

            print "<br><a href=index.php>Homepage</a>";
        }

        if(isset($_POST['no']))
            header("location: index.php");
    }
?>
</body>
</html>