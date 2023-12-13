import jakarta.servlet.http.*;
import java.io.*;

public class Scheletro extends HttpServlet{
    
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
