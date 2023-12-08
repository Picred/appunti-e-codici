import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerD {
    private static final int PORT = 3333;
    private static int id = 0;

    private static int sommacifre(String str){
        id++;
        int res = 0;
        for(int i=0; i<str.length(); i++){
            int c = Character.getNumericValue(str.charAt(i));
            if (c >= 0 && c <= 9)
                res +=c;
        }
        return res;
    }
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
                out.println(id + "," + sommacifre(buffer));
                
                clientSocket.close();
                System.out.println("Client disconnected");
            } catch(IOException e){
                System.out.println("accept");
                System.exit(1);
            }
        }

        try{
            in.close();
            out.close();
            clientSocket.close();
            serverSocket.close();
        } catch(IOException e ){
            System.out.println("close");
            System.exit(1);
        }
    }
}