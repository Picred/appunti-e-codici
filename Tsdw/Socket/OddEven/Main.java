public class Main{
    public static void main(String[] args) throws InterruptedException{
        Shared shared = new Shared();
        Thread tO = new MyThread("tO", shared);
        Thread tE = new MyThread("tE", shared);
        
        tO.start();
        tE.start();

        tO.join();
        tE.join();
    }
}