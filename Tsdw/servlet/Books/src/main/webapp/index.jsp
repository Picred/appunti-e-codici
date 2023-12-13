<html>
<body>
<h2>Books Database</h2>
    <h4>Visualizza dati</h4>
    <form action="/books" method="GET">
        <input type="submit" name="action" value="Vedi tutto">
    </form> 
    
    <br>
    
    <h4>Inserisci dati</h4>
    <form action="/books" method="POST">
        <input type="text" name="isbn" placeholder="isbn">
        <input type="text" name="title" placeholder="title">
        <input type="text" name="author" placeholder="author">
        <input type="text" name="publisher" placeholder="publisher">
        <input type="number" name="ranking" placeholder="ranking">
        <input type="number" name="year" placeholder="year">
        <input type="number" name="price" placeholder="price">
        <input type="submit" name="action" value="Inserisci">
    </form>
</body>
</html>
