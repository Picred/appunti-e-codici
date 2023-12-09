<!doctype html>

<html>
<body>

<?php
$servername = "localhost";
$username = "newuser";
$password = "password";
$dbname = "myDB";

$conn = new mysqli($servername, $username, $password, $dbname);

if($conn->connect_error)
    die("Error connecting to myDB");
?>

<?php if($_SERVER["REQUEST_METHOD"] == "GET"){
    print "<h1>Film consigliato: </h1>";
    $sql = "SELECT * FROM flist;";
    $result = $conn->query($sql);

    if($result->num_rows > 0){
        $result->data_seek(rand(0, $result->num_rows));
        $row = $result->fetch_assoc();
        $titolo_random = $row["titolo"];
        $regista_random = $row["regista"];

        print $titolo_random;
        if($regista_random != "")
            print "($regista_random)";
        
    $result->free();
}
?>

<br><br>
<form method="POST" action="<?php echo $_SERVER['PHP_SELF']?>" >
    <input type="text" name="titolo" placeholder="Inserisci titolo">
    <input type="text" name="regista" placeholder="Inserisci regista">
    <input type="submit" name="trova">
    <input type="submit" name="wlist" value="Visualizza wlist">
</form>

<?php }//endif get ?>

<?php if($_SERVER['REQUEST_METHOD'] == 'POST'){
    
    if (isset($_POST['trova'])){
        $sql = 'SELECT * FROM flist WHERE ';
        $add_end = false;
        $titolo = $_POST['titolo'];
        $regista = $_POST['regista'];
        
        if($titolo == "" && $regista == ""){
            print "Inserisci almeno il titolo";
            print '<br><a href="index.php">Home page</a>';
        }
        else {
            if($titolo!= ""){
                $sql .= "titolo = '$titolo' ";
                $add_end = true;
            }

            if($regista!= ""){
                if($add_end)
                    $sql .= "AND ";
                $sql .= "regista= '$regista'";
            }
            $sql .= ";";

            $result = $conn->query($sql);

            if($result->num_rows > 0){
                print '<h1>Film richiesto: </h1>';
                while($row = $result->fetch_assoc()){
                    print $row['titolo'];
                    if($row['regista'] != "")
                        print ': ' . $row['regista'];
                    print '<br>';
                }
                print '<a href=index.php>Home page</a>';
            }
            else {
                print "Nessun risultato trovato in <code>flist</code>. <br>Cerco in wlist...<br>";
                
                $sql = 'SELECT * FROM wlist WHERE ';
                $add_end = false;
                $titolo = $_POST['titolo'];
                $regista = $_POST['regista'];
                
                if($titolo!= ""){
                    $sql .= "titolo = '$titolo' ";
                    $add_end = true;
                }

                if($regista!= ""){
                    if($add_end)
                        $sql .= "AND ";
                    $sql .= "regista= '$regista'";
                }
                $sql .= ";";

                $result = $conn->query($sql);

                if($result->num_rows > 0){
                    print "Film presente in <code>wlist</code><br>";
                    print '<a href="index.php">Home page</a>';
                }
                
                else{
                    print "Nessun risultato trovato nemmeno in <code>wlist</code>. <br>Aggiungerlo alla <code>wlist</code>?";
                    ?>
                    <form action="index.php" method="POST">
                        <input type="hidden" name="titolo" value="<?php print $titolo;?>">
                        <input type="hidden" name="regista" value="<?php print $regista;?>">
                        <br>
                        <input type="submit" value="si" name="si">
                        <input type="submit" value="no" name="no">
                    </form>

                    <?php
                }
            }
        }
        
    }

    if(isset($_POST['si'])){
        $titolo = $_POST['titolo'];
        $regista = $_POST['regista'];
        $sql = "INSERT INTO wlist (titolo, regista) VALUES (";

        if($titolo == ""){
            print "Errore. Inserisci almeno il titolo.";
            print '<br><a href="index.php">Home page</a>';
        }
        else{
            $sql .= "'$titolo'";
            if($regista != ""){
                $sql .= ", '$regista'";
            }
            else{
                $sql .= ", ''";
            }
        }
        $sql .= ");";
        $conn->query($sql);
        $conn->close();
        header("location: index.php");
    }
    
    if(isset($_POST['no'])){
        $conn->close();
        header("location: index.php");
    }

    if(isset($_POST['wlist'])){
        $sql = 'SELECT * FROM wlist;';

        $result = $conn->query($sql);
        if($result->num_rows > 0){
            print '<h1>Wish list <code><i>wlist</i></code>: </h1>';
            while($row = $result->fetch_assoc()){
                print $row['titolo'];
                    if($row['regista'] != "")
                        print ': ' . $row['regista'];
                    print '<br>';

            }
            ?>
            <form action="index.php" method="POST">
                <input type="submit" name="svuota" value="Svuota wlist">
            </form>
            <?php
        } else{
            print "Wish list vuota.<br>";
        }
        print '<a href=index.php>Home page</a>';
    }

    if(isset($_POST['svuota'])){
        $sql = 'TRUNCATE TABLE wlist;';

        $result = $conn->query($sql);
        $conn->close();
        header("location: index.php");
    }

    ?>
<?php } //endif post?>
</body>
</html>