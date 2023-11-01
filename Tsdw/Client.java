import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client{
    public static void main(String[] args) throws UnknownHostException {
        InetAddress addr;

        if(args.length == 0)
            addr = InetAddress.getByName(null);
        else
            addr = InetAddress.getByName(args[0]);

        Socket socket = null;
        BufferedReader recv = null, stdIn = null;
        PrintWriter send = null;

        try{
            socket = new Socket(addr, Server.PORT);
            recv = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            send = new PrintWriter(socket.getOutputStream(), true);

            // Input da tastiera
            stdIn = new BufferedReader(new InputStreamReader(System.in));
            String userInput;

            while(true){
                userInput = stdIn.readLine();
                send.println(userInput); // invio al server

                if(userInput.equals("FINE"))
                    break;

                System.out.println("Risposta Server: " + recv.readLine());
            }
        } catch (UnknownHostException e) {
            System.err.println("Don't know about host " + addr);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Couldn't get I/O for the connection to: " + addr);
            System.exit(1);
        }
    }
}