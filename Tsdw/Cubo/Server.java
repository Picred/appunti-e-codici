package Cubo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    private static final int PORT = 3333;

    public static int cubo(int n){
        return n*n*n;
    }

    public static void main(String[] args) {
        ServerSocket socket = null;

        try{
            socket = new ServerSocket(PORT);
        } catch (IOException e){
            System.out.println("New socket!");
            e.printStackTrace();
        }
        
        System.out.println("Server started \n" + socket);

        Socket clientSocket = null;
        BufferedReader in = null;
        PrintWriter out = null;

        try{
            clientSocket = socket.accept();
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            out = new PrintWriter(clientSocket.getOutputStream(), true);

            String text = in.readLine();
            System.out.println("Received: "+ text);

            int number = Integer.parseInt(text);

            out.println(cubo(number));
        } catch(IOException e){
            System.out.println("accept()");
            e.printStackTrace();
        }

        System.out.println("Closing connection..");

        try{
            in.close();
            out.close();
            socket.close();
            clientSocket.close();
        } catch(IOException e){
            System.out.println("close()");
            e.printStackTrace();
        }
    }
}
