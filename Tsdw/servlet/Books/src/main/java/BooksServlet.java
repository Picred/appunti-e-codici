import jakarta.servlet.http.*;
import java.sql.*;

import java.io.IOException;
import java.io.PrintWriter;

public class BooksServlet extends HttpServlet {
    Connection conn;
	final String connectionString = "jdbc:mysql://localhost:3306/books?user=newuser&password=password";

	public void init(){
		try{
            conn = DriverManager.getConnection(connectionString);
		}catch (Exception e){
            e.printStackTrace();
		}

		System.out.println("Connessione effettuata");
	}

	public void doGet(HttpServletRequest request, HttpServletResponse response){
		response.setContentType("text/html");
		PrintWriter out;
		try{
            out = response.getWriter();
            if(request.getParameter("action").equals("Vedi tutto"))
            	readAll(out);
		} catch (IOException e){
            e.printStackTrace();
		}
		

    }

	public void readAll(PrintWriter out){
		try{
            String sql = "SELECT * FROM books;";
            Statement st = conn.createStatement();
            ResultSet result = st.executeQuery(sql);

            out.print("<h2>Record in tabella <code>books</code>:</h2>");
            while(result.next()){
            	String id = result.getString("id");
            	String isbn = result.getString("isbn");
            	String title = result.getString("title");
            	String author = result.getString("author");
            	String publisher = result.getString("publisher");
            	String ranking = result.getString("ranking");
            	String year = result.getString("year");
            	String price = result.getString("price");

            	out.print(id + " | <a href=libro.jsp?id=" + id + ">" + isbn + "</a> | " + title + " | " + author + " | "  + publisher + " | " + ranking + " | " + year + " | " + price + "<br>");
            }
            out.print("<br><a href=index.jsp>Homepage</a>");
		} catch (SQLException e){
            e.printStackTrace();
		}
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response){
		response.setContentType("text/html");
		PrintWriter out = null;

		try{
            out = response.getWriter();
            if(request.getParameter("action").equals("Inserisci")){
            	String isbn = request.getParameter("isbn");
            	String title = request.getParameter("title");
            	String author = request.getParameter("author");
            	String publisher = request.getParameter("publisher");
            	int ranking = Integer.parseInt(request.getParameter("ranking"));
            	int year = Integer.parseInt(request.getParameter("year"));
            	int price = Integer.parseInt(request.getParameter("price"));
            
            	String sql = "INSERT INTO books (isbn, title, author, publisher, ranking, year, price) VALUES ('";
            	sql += isbn + "','" + title + "',' " + author + "',' " + publisher+ "',' " + ranking+ "',' " + year+ "',' " + price + "')";
            
            	Statement st = conn.createStatement();
            	st.executeUpdate(sql);

            	out.print("Inserimento avvenuto con successo");
            	out.print("<br><a href=index.jsp>Homepage</a>");
            }

            else if(request.getParameter("action").equals("Aggiorna")){
            	String isbn = request.getParameter("isbn");
            	String title = request.getParameter("title");
            	String author = request.getParameter("author");
            	String publisher = request.getParameter("publisher");
            	Integer ranking = Integer.parseInt(request.getParameter("ranking"));
            	Integer year = Integer.parseInt(request.getParameter("year"));
            	Integer price = Integer.parseInt(request.getParameter("price"));
            	String id = request.getParameter("id");

            	String sql = "UPDATE books SET ";
            	sql += "isbn='" + isbn + "',";
            	sql += "title='" + title + "',";
            	sql += "author='" + author + "',";
            	sql += "publisher='" + publisher + "',";
            	sql += "ranking=" + ranking + ",";
            	sql += "year=" + year + ",";
            	sql += "price=" + price;
            	sql += " WHERE id='" + id + "'";

            	conn.createStatement().executeUpdate(sql);
            	out.print("Aggiornamento avvenuto con successo");
            	out.print("<br><a href=index.jsp>Homepage</a>");
            }

            else if(request.getParameter("action").equals("Elimina")){
            	String id = request.getParameter("id");
            	String sql = "DELETE FROM books WHERE id='" + id + "'";

            	conn.createStatement().execute(sql);
            	out.print("Eliminazione avvenuta con successo");
            	out.print("<br><a href=index.jsp>Homepage</a>");
            }
		} catch (Exception e){
            e.printStackTrace();
		} 
	}
}
