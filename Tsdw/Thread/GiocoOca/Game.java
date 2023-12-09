package GiocoOca;

public class Game {
    int round = 0; // variabile condivisa
    
    // metodi con sincronizzazione

    int getRound() {
        return round;
    }

    public synchronized void setRound(int k){ // sync: metodo chiamato da un thread. Solo uno alla volta può accedere. Fa da semaforo
        round = k;
    }

    public synchronized void gameWait() throws InterruptedException{
        wait();
    }

    public synchronized void gameNotify(){
        notifyAll();
    }

    public synchronized void gameSleep() throws InterruptedException{
        Thread.sleep(500);
    }
}
