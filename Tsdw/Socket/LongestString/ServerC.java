import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerC{
    private static final int PORT = 3333;

    public static void main(String[] args) {
        ServerSocket serverSocket = null;

        try{
            serverSocket = new ServerSocket(PORT);

            Socket clientSocket = null;
            BufferedReader in = null;
            PrintWriter out = null;
            String longestReceived = "";

            while(true){
                clientSocket = serverSocket.accept();
                in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                out = new PrintWriter(clientSocket.getOutputStream(), true);

                String input = in.readLine();
                if(input.length() > longestReceived.length())
                    longestReceived = input;

                System.out.println("[ServerC] ricevo: " + input);
                out.println(longestReceived);
                
                clientSocket.close();
                in.close();
                out.close();
            }

        }catch (IOException e){
            e.printStackTrace();
        }
    }
}