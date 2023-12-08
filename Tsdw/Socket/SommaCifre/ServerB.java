import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerB {
    private static final int PORT = 3333;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;

        try{
            serverSocket = new ServerSocket(PORT);
        } catch(IOException e){
            System.out.println("serverSocket");
            System.exit(1);
        }

        System.out.println(serverSocket + " started.");

        BufferedReader in = null;
        PrintWriter out = null;
        Socket clientSocket = null;

        while(true){
            try{
                clientSocket = serverSocket.accept();

                System.out.println("New client connected");

                in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                out = new PrintWriter(clientSocket.getOutputStream(), true);

                String buffer = in.readLine();
                System.out.println(buffer);
                out.println(buffer);
                
                clientSocket.close();
                System.out.println("Client disconnected");
            } catch(IOException e){
                System.out.println("accept");
                System.exit(1);
            }
        }
    }
}
