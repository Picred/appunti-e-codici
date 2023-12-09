package TsdwLab.Esercizi.ValoreAssoluto;
import java.util.Random;

public class Shared {
    Random rand = new Random();
    private int x;

    public Shared(){
        this.x = rand.nextInt(11);
    }

    public int getX(){
        return this.x;
    }

    public synchronized void setX(int t){
        this.x = t;
    }

    public synchronized void sharedWait() throws InterruptedException{
        wait();
    }

    public synchronized void sharedNotify(){
        notifyAll();
    }
}
