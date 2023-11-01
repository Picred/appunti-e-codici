import java.io.*;
import java.net.*;

public class Server{
    public static final int PORT = 1050;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;

        try{
            serverSocket = new ServerSocket(PORT);
        } catch (IOException e){
            e.printStackTrace();
        }

        System.out.println("Server Started...");
        System.out.println("Server INFO: " + serverSocket);


        // Client
        Socket clientSocket = null;
        BufferedReader recv = null; // in
        PrintWriter send = null; // out

        try{
            clientSocket = serverSocket.accept();
            System.out.println("Connection accepted from: " + clientSocket);

            recv = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            send = new PrintWriter(clientSocket.getOutputStream(), true);

            String inputLine;

            while((inputLine = recv.readLine()) != null){
                if(inputLine.equals("FINE"))
                    break;
                System.out.println("Ricevuto: " + inputLine);
                send.println(inputLine);
            }
        } catch(IOException e){
            System.out.println("Accept failed");
            System.exit(1);
        }

        try {
            send.close();
            recv.close();
            clientSocket.close();
            serverSocket.close();
        } catch (IOException e) {
            System.out.println("Errorclosing...");
            e.printStackTrace();
        }
    }
}
