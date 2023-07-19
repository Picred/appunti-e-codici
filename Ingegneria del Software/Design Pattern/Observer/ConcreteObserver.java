package Observer;

public class ConcreteObserver implements Observer {
    public void update(Object state, Subject s){
        int st = (int)state;
        System.out.println("ConcreteObserver: stato = " + st);
    }
}
