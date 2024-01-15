import jakarta.servlet.http.*;
import java.io.*;

import java.sql.*;

public class Scheletro extends HttpServlet{
    Connection conn;
    String connString = "jdbc:mysql://localhost:3306/books?user=newuser&password=password";

    public void init(){
        try{
            conn = DriverManager.getConnection(connString);
            System.out.println("Connesso");
        } catch(Exception e){
            e.printStackTrace();
            System.out.println("\n\nNON Connesso");
        }
    }
    
    public void doGet(HttpServletRequest request, HttpServletResponse response){
		response.setContentType("text/html");
        PrintWriter out;
        try{
            out = response.getWriter();
            out.print("Heiiiiiii");
        } catch(Exception e){
            
        }
    }
}
