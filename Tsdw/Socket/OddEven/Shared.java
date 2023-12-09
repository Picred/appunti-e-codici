public class Shared{
    private int n;

    public Shared(){
        this.n = 0;
    }

    public void sleepSh(int dur) throws InterruptedException{
        Thread.sleep(dur);
    }

    public int getN(){
        return this.n;
    }

    public synchronized void setN(int k){
        this.n = k;
    }
}