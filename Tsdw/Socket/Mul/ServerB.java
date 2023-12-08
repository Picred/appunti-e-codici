import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerB {
    private static final int PORT = 7777;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;

        try{
            serverSocket = new ServerSocket(PORT);
        } catch(IOException e){
            System.out.println("serverSocket");
            System.exit(1);
        }

        System.out.println(serverSocket + "started...");

        Socket clientSocket = null;
        BufferedReader in = null;
        PrintWriter out = null;

        try{
            clientSocket = serverSocket.accept();
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            
            String buffer = in.readLine();
            System.out.println("ServerB received: " + buffer);
            out.println("ServerB answer: " + buffer);

        } catch(IOException e){
            System.out.println("accept");
            System.exit(1);
        }


        try{
            in.close();
            out.close();
            clientSocket.close();
            serverSocket.close();
        } catch(IOException e){
            System.out.println("close");
            System.exit(1);
        }
    }
}
