import java.util.Random;

public class MyThread extends Thread{
    Random rand = new Random();
    private int val;
    private int tid;
    private Shared shared;

    public MyThread(int tid, Shared sh){
        shared = sh;
        this.tid = tid;
    }

    @Override
    public void run(){
        while(true){
            this.val = rand.nextInt(81) + 10;

            System.out.println("Sono il thread " + this.tid + " : sample valeva " + shared.getSample() + ", adesso vale " + val);
            if(val == shared.getSample()) 
                break;
                
            shared.setSample(val);

        }

        System.out.println("T" + tid + " termino...");
    }
}