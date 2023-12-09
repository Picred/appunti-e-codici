import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerB{
    private static final int PORT = 3333;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;

        try{
            serverSocket = new ServerSocket(PORT);

            Socket clientSocket = null;
            BufferedReader in = null;
            PrintWriter out = null;

            while(true){
                clientSocket = serverSocket.accept();
                in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                out = new PrintWriter(clientSocket.getOutputStream(), true);

                String input = in.readLine();

                System.out.println("[ServerB] ricevo: " + input);
                out.println(input);
                
                clientSocket.close();
                in.close();
                out.close();
            }

        }catch (IOException e){
            e.printStackTrace();
        }
    }
}