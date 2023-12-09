// Inspired by www.dmi.unict.it/tramonta/lessons/sd/jthread.tar

public class myThread extends Thread {
    myThread() {
        System.out.println("myThread constructor");
    }

    public void run() {
        // Starting
        System.out.println("In run di myThread");
        Thread t = Thread.currentThread();
        System.out.println("myThread running pid " + t.toString());
        System.out.println(t.getName());
        for (int i = 0; i < 1000; i++) {
            System.out.println("\t\t>");
        }
    }
}