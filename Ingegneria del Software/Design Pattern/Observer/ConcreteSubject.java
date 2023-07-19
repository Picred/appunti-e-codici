package Observer;

public class ConcreteSubject extends Subject{
    int state = 0;

    public int getState(){
        return state;
    }

    public void setState(int s){
        state = s;
    }

    public void add(int n){
        state = state + n;
        notify(state);
    }
}
