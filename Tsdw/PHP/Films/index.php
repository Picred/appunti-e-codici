<!doctype html>
<html>
<body>
    <?php 
    function homepage(){
        echo "<br><h4><a href=index.php>Homepage</a></h4>";
    }

    function createFilm($conn, $titolo, $anno, $paese, $regista){
        $sql = "INSERT INTO films (titolo, anno, paese, regista) VALUES ('$titolo', '$anno', '$paese', '$regista');";
        if($conn->query($sql))
            echo "Film creato con successo";
        else
            echo "Errore nella creazione del film";
        homepage();
    }

    function readall($conn){
        $sql = "SELECT * FROM films;";
        $result = $conn->query($sql);
        if($result->num_rows>0){
            while($row = $result->fetch_assoc())
                echo $row['id'] . "  " . $row['titolo'] . "  " . $row['anno'] . "  " . $row['paese'] . "  " . $row['regista'] . "<br>"; 
        }
        else
            echo "<h1>Tabella vuota</h1>";
        homepage();
    }

    function updateFilm($conn, $old_title, $new_title){
        $sql = "UPDATE films SET titolo='$new_title' WHERE titolo='$old_title'";
        if($conn->query($sql))
            echo "Film aggiornato";
        else
            echo "Aggiornamento del film fallito";
        homepage();
    }

    function deleteFilm($conn, $titolo){
        $sql = "DELETE FROM films WHERE titolo='$titolo'";
        if($conn->query($sql))
            echo "Film eliminato";
        else
            echo "Eliminazione del film fallita";
        homepage();
    }
    
    if($_SERVER["REQUEST_METHOD"] === "GET"){ 
    ?>

    <h1>Benvenuto</h1>
    <h2>Database dei film</h2>

    <p>Crea un nuovo film:</p>
    <form action="index.php" method="POST">
        <!-- create film -->
        <input type="text" name="titolo" placeholder="Titolo" required>
        <input type="text" name="anno" placeholder="Anno" required>
        <br>
        <input type="text" name="paese" placeholder="Paese" required>
        <input type="text" name="regista" placeholder="Regista" required>
        <input type="submit" name="create" value="Crea">
    </form>

    <br>
        <!-- Read all table films -->
    <h3>Vedi tutti i film</h3>
    <form action="index.php" method="POST">
        <input type="submit" name="readall" value="Visualizza tutto">
    </form>
    <br>
        <!-- Update a film -->
    <h3>Aggiorna film</h3>
    <br>
    <form action="index.php" method="POST">
        <input type="text" name="titolo" placeholder="Titolo del film">
        <input type="text" name="newtitolo" placeholder="Nuovo titolo">
        <input type="submit" name="edit" value="Vai">
    </form>

        <!-- Delete a film -->
        <h3>Elimina un film</h3>
    <br>
    <form action="index.php" method="POST">
        <input type="text" name="titolo" placeholder="Titolo del film">
        <input type="submit" name="delete" value="Vai">
    </form>

<?php } //END GET
    $conn = new mysqli("localhost", "newuser", "password", "cinema");

    if($conn->connect_error)
        die("Errore durante la connessione con il database");

    if($_SERVER["REQUEST_METHOD"] === "POST"){
        if(isset($_POST['create']))
            createFilm($conn, $_POST['titolo'],$_POST['anno'], $_POST['paese'], $_POST['regista']);

        if(isset($_POST['readall']))
            readall($conn);

        if(isset($_POST['edit']))
            updateFilm($conn, $_POST['titolo'], $_POST['newtitolo']);

        if(isset($_POST['delete']))
            deleteFilm($conn, $_POST['titolo']);
    }
?>
</body>
</html>