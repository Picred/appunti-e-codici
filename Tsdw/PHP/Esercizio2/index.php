<!DOCTYPE HTML>
<html>
<body>
<?php
    $servername = "localhost";
    $username = "newuser";
    $password = "password";
    $dbname = "exam";

    $conn = new mysqli($servername, $username, $password, $dbname);

    if($conn->connect_error)
        die("Error connecting to myDB");
?>

<?php if($_SERVER['REQUEST_METHOD'] == 'GET'){ 
    if($_GET['edit_isbn'] != 'true'){?>
    <form action="index.php" method="POST">
    <input type="submit" name="show" value="Show books">
    <br><br>
    
    <input type="text" name="isbn" placeholder="isbn">
    <input type="text" name="title" placeholder="title">
    <input type="text" name="author" placeholder="author">
    <input type="text" name="publisher" placeholder="publisher">
    <br>
    
    <input type="number" name="ranking" placeholder="ranking">
    <input type="number" name="year" placeholder="year">
    <input type="number" name="price" placeholder="price">
    <br>
    
    <input type="submit" name="insert" value="Insert into books">
</form>

<?php } if($_GET['edit_isbn'] == 'true'){ ?>
    <form action="index.php" method="POST">
    <input type="text" name="new_isbn" placeholder="new isbn">
    <input type="hidden" name="old_isbn" value="<?= $_GET['old_isbn']; ?>">
    <input type="submit" name="edit" value="edit isbn">
    <input type="submit" name="remove" value="Remove record">
    </form>
<?php }
}// end get section

if($_SERVER['REQUEST_METHOD'] == 'POST'){
    
    if(isset($_POST['show'])){
        $sql = 'SELECT * FROM books;';
        $result = $conn->query($sql);

        if($result->num_rows>0){
            while($row = $result->fetch_assoc()){
                print $row['id'] . "  " . $row['isbn'] . "  " . $row['title'] . "  " . $row['author'] . "  " . $row['publisher'] . "  " . $row['ranking'] . "  " . $row['year'] . "  " . $row['price'] . "  " . '<a href=index.php?edit_isbn=true&old_isbn=' . $row['isbn'] . '>Edit this isbn</a>' . '<br>' ;
            }
        }
        print '<h3><a href="index.php">Homepage</a></h3>';
    }

    if(isset($_POST['insert'])){
        if($_POST['isbn'] == "" && $_POST['title'] == ""){
            print "isbn / title non possono essere nulli.<br>";
            print '<h3><a href="index.php">Ritenta</a></h3>';
        }
        else{
            $sql = "INSERT INTO books (isbn, title, author, publisher, ranking, year, price) VALUES (";
            $isbn = $_POST['isbn'];
            $title = $_POST['title'];
            $author = $_POST['author'];
            $publisher = $_POST['publisher'];
            $ranking = $_POST['ranking'];
            $year = $_POST['year'];
            $price = $_POST['price'];

            $sql .= "'$isbn', '$title',";
            
            if($author == "") $sql .= " 'NULL',";
            else $sql .= "'$author',";

            if($publisher == "") $sql .= " 'NULL',";
            else $sql .= "'$publisher',";

            if($ranking == "") $sql .= (intval(0)) . ',';
            else $sql .= "'$ranking',";

            if($year == "") $sql .= (intval(0))  . ',';
            else $sql .= "'$year',";
        
            if($price == "") $sql .= (intval(0)) . ');';
            else $sql .= "'$price');";

            if($conn->query($sql) === TRUE)
                print "Inserimento avvenuto";
            else
                print "Errore nell'inserimento<br>";
            print '<h3><a href="index.php">Homepage</a></h3>';

        }
    }
    if(isset($_POST['edit'])){
        $old_isbn = $_POST['old_isbn'];
        $new_isbn = $_POST['new_isbn'];

        if($new_isbn != ""){
            print $new_isbn . "<br>";
            $sql = "UPDATE books SET isbn='$new_isbn' WHERE isbn='$old_isbn';";
            $conn->query($sql);
            header("location: index.php");
        } else {
            print "Nuovo isbn non settato";
            print '<h3><a href="index.php">Ricomincia</a></h3>';
        }
    }

    if(isset($_POST['remove'])){
        $old_isbn = $_POST['old_isbn'];
        $sql ="DELETE FROM books WHERE isbn='$old_isbn';";
        $conn->query($sql);
        header("location: index.php");
    }
} ?>
</body>
</html>