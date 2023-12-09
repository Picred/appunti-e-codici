package TsdwLab.Esercizi.ValoreAssoluto;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Shared shared = new Shared();
        Thread t1 = new MyThread(shared, 1);
        Thread t2 = new MyThread(shared, 2);
        
        t1.start();
        t2.start();

        t1.join();
        t2.join();
    }
}
