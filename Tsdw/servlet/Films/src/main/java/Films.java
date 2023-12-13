import java.sql.*;
import java.io.*;
import jakarta.servlet.http.*;

public class Films extends HttpServlet{
    Connection conn;
    final String connString = "jdbc:mysql://localhost:3306/cinema?user=newuser&password=password";

    public void init(){
        try{
            conn = DriverManager.getConnection(connString);
        } catch(Exception e){
            e.printStackTrace();
        }
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response){
        response.setContentType("text/html");
        PrintWriter out;

        try{
            out = response.getWriter();
            //Leggi tutto
            if(request.getParameter("action").equals("read")){
                String sql = "SELECT * FROM films";

                ResultSet result = conn.createStatement().executeQuery(sql);

                while(result.next()){
                    out.print(result.getString("id"));
                    out.print(" | ");
                    out.print(result.getString("titolo"));
                    out.print(" | ");
                    out.print(result.getString("anno"));
                    out.print(" | ");
                    out.print(result.getString("paese"));
                    out.print(" | ");
                    out.print(result.getString("regista"));
                    out.print("<br>");
                }
                homepage(out);
            }
        } catch(Exception e){
            e.printStackTrace();
        }
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response){
        response.setContentType("text/html");
        PrintWriter out;

        try{
            out = response.getWriter();

            //inserimento
            if(request.getParameter("action").equals("insert")){
                String titolo = request.getParameter("titolo");
                String anno = request.getParameter("anno");
                String paese = request.getParameter("paese");
                String regista = request.getParameter("regista");

                String sql = "INSERT INTO films (titolo, anno, paese, regista) VALUES ('";
                sql += titolo + "', '"; 
                sql += anno + "', '"; 
                sql += paese + "', '"; 
                sql += regista + "')"; 

                conn.createStatement().execute(sql);
                out.print("Inserimento riuscito.");
            }

            //aggiornamento
            else if(request.getParameter("action").equals("update")){
                String oldtitolo = request.getParameter("oldtitolo");
                String newtitolo = request.getParameter("newtitolo");
                String anno = request.getParameter("anno");
                String paese = request.getParameter("paese");
                String regista = request.getParameter("regista");

                String sql = "UPDATE films SET ";
                sql += "titolo='" + newtitolo + "',";
                sql += "anno='" + anno + "',";
                sql += "paese='" + paese + "',";
                sql += "regista='" + regista + "' WHERE titolo='" + oldtitolo + "'";

                conn.createStatement().execute(sql);
                out.print("Aggiornamento riuscito.");
            }
            
            
            //cancellazione
            else if(request.getParameter("action").equals("delete")){
                String titolo = request.getParameter("titolo");
                String sql = "DELETE FROM films WHERE titolo='" + titolo + "'";
                conn.createStatement().execute(sql);
                out.print("Eliminazione avvenuta con successo");
            }
            homepage(out);
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    void homepage(PrintWriter out){
        out.print("<br><a href='index.jsp'>Torna alla homeapge</a>");
    }
}