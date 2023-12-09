<?php 
    require 'functions.php';

    if($_SERVER['REQUEST_METHOD'] === 'GET'){
        $cdl = $_GET['cdl'];
        $sql = "SELECT * FROM courses WHERE codice_corso=$cdl";
        $res = $conn->query($sql);
        if($res->num_rows>0){
            while($row = $res->fetch_assoc())
                print $row['codice_corso'] . " | " . $row['nome_corso'] . " | " . $row['descrizione'] . " | " . $row['crediti'] . "<br>";
        }
        else
            print "Nessun dato disponibile nella tabella <code>courses</code>.";
        print "<a href=index.php>Homepage</a>";
    }
?>
