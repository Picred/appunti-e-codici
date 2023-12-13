<!DOCTYPE html>
<html>
    <body>
        <%
        String id = request.getParameter("id");
        %>
        <h3>Aggiorna libro selezionato</h3>
        <form action="/books" method="POST">
            <input type="text" name="isbn" placeholder="isbn">
            <input type="text" name="title" placeholder="title">
            <input type="text" name="author" placeholder="author">
            <input type="text" name="publisher" placeholder="publisher">
            <input type="number" name="ranking" placeholder="ranking">
            <input type="number" name="year" placeholder="year">
            <input type="number" name="price" placeholder="price">
            <input type="hidden" name="id" value="<%=id%>">
            <input type="submit" name="action" value="Aggiorna">
        </form>

        <h3>Elimina libro selezionato</h3>
        <form action="/books" method="POST">
            <input type="hidden" name="id" value="<%=id%>">
            <input type="submit" name="action" value="Elimina">
        </form>
    </body>
</html>