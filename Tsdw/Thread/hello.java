// Inspired by www.dmi.unict.it/tramonta/lessons/sd/jthread.tar

public class hello {
    public static void main(String[] args) throws InterruptedException {
        // Main is a deamon thread
        Thread tMain = Thread.currentThread();
        System.out.println("Main Thread "+tMain.toString());
        // Let's create a new thread with method 1
        myThread t = new myThread();
        // Start thread
        t.start();
        // In "parallel" here
        for (int i = 0; i < 10; i++) {
            System.out.println("<");
        }
        System.out.println("");
        System.out.println("This is the end");
    }
}