package TsdwLab.Esercizi.ValoreAssoluto;

import java.util.Random;

public class MyThread extends Thread {
    Random rand = new Random();
    private int m;
    private int tid;
    Shared shared;

    public MyThread(Shared shared, int tid){
        this.shared = shared;
        this.tid = tid;
    }

    @Override
    public void run(){
        //T1
        if(tid == 1){
            while(true){
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e){
                    System.out.println("sleep()");
                    e.printStackTrace();
                }
                m = rand.nextInt(11);

                if(shared.getX() == -1){
                    break;                
                }

                if (m == shared.getX()){
                    System.out.println("RISPOSTA CORRETTA");
                    shared.setX(-1);
                    break;
                }

                if(Math.abs(this.m - shared.getX()) > 5){
                    System.out.println("risposta MOLTO sbagliata");
                    try{
                        shared.sharedWait();
                    } catch(InterruptedException e){
                        System.out.println("sharedWait()");
                        e.printStackTrace();
                    }
                    continue;
                }
                else{
                    System.out.println("risposta sbagliata");
                }
            }
        }
        // T2
        else if (tid == 2){
            while(true){
                try {
                    Thread.sleep(300);
                } catch (InterruptedException e){
                    System.out.println("sleep()");
                    e.printStackTrace();
                }
                shared.sharedNotify();
                if(shared.getX() == -1){
                    break;
                }
            }
        }
    }
}
