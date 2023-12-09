import java.util.List;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args) throws InterruptedException{
        Shared shared = new Shared();
        List<Thread> threads = new ArrayList<>(3);

        for(int i=1; i<=3; i++)
            threads.add(new MyThread(i,shared));

        for(Thread t : threads)
            t.start();

        for(Thread t : threads)
            t.join();
        System.out.println("[MAIN]: valore finale di sample: " + shared.getSample());
    }
}