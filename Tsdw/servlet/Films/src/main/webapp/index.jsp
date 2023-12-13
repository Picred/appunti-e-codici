<html>
<body>
    <h3>Visualizza la tabella</h3>
    <form action="/films" method="GET">
        <input type="hidden" name="action" value="read">
        <input type="submit" value="Visualizza tabella">
    </form>


    <h3>Inserisci in tabella</h3>
    <form action="/films" method="POST">
        <input type="hidden" name="action" value="insert">
        <input type="text" name="titolo" placeholder="Titolo" required>
        <input type="text" name="anno" placeholder="anno" required>
        <br>
        <input type="text" name="paese" placeholder="paese" required>
        <input type="text" name="regista" placeholder="regista" required>
        <br>
        <input type="submit" value="Inserisci record">
    </form>
    

    <h3>Aggiorna un record</h3>
    <form action="/films" method="POST">
        <input type="hidden" name="action" value="update">
        <input type="text" name="oldtitolo" placeholder="Titolo da aggiornare" required>
        <input type="text" name="newtitolo" placeholder="Nuovo titolo" required>
        <input type="text" name="anno" placeholder="anno" required>
        <input type="text" name="paese" placeholder="paese" required>
        <input type="text" name="regista" placeholder="regista" required>
        <br>
        <input type="submit" value="Aggiorna record">
    </form>


    <h3>Elimina un record</h3>
    <form action="/films" method="POST">
        <input type="hidden" name="action" value="delete">
        <input type="text" name="titolo" placeholder="Titolo da eliminare" required>
        <br>
        <input type="submit" value="Elimina record">
    </form>
    

</body>
</html>
