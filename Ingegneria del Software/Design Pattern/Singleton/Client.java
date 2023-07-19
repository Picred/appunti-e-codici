public class Client {
    //Client
    public static void main(String[] args) {
        // Singleton test
        Singleton sing = Singleton.getInstance();
        // Singleton test = new Singleton(); // Errore
    
        // Multiton test (max 2 instances)
        Multiton mult = Multiton.getInstance();
        Multiton mult2 = Multiton.getInstance();
        Multiton mult3 = Multiton.getInstance();
        
        System.out.println(mult3);
    }
}
