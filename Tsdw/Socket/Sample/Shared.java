public class Shared{
    private int sample;

    public Shared(){
        this.sample = 50;
    }

    public int getSample(){
        return sample;
    }

    public synchronized void setSample(int k){
        sample = k;
    }
}