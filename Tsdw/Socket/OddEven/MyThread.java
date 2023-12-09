import java.util.Random;

public class MyThread extends Thread{
    private Random rand = new Random();
    private String threadName;
    private Shared shared;

    public MyThread(String name, Shared sh){
        this.threadName = name;
        this.shared = sh;
    }

    @Override
    public void run(){
        if(threadName.equals("tE")){ // tE
            int iters = 0;
            while(iters < 1000){
                iters++;
                try{
                    shared.sleepSh(200);
                } catch(InterruptedException e){
                    e.printStackTrace();
                }

                int r = (rand.nextInt()*2) % Integer.MAX_VALUE; // pari
                int n = shared.getN();

                shared.setN(n+r);
                if((shared.getN() % 2 == 0) && iters>=9){
                    System.out.println("[" + this.threadName + "] n = " + shared.getN());
                    break;
                }
            }
        }
        else{ // tO
            int iters = 0;
            while(iters < 1000){
                iters++;
                try{
                    shared.sleepSh(200);
                } catch(InterruptedException e){
                    e.printStackTrace();
                }
                int r = ((rand.nextInt() * 2) + 1) % Integer.MAX_VALUE;
                int n = shared.getN();

                shared.setN(n+r);

                if(iters >9 && shared.getN() % 2 == 1){
                    System.out.println("[" + this.threadName + "] n = " + shared.getN());
                    break;
                }
            }
        }
        System.out.println("[" + this.threadName + "] " + "termino...");
    }
}