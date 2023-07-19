package Observer;

import java.util.*;

public class Subject {
    private List<Observer> observers = new ArrayList<>();

    public void attach(Observer obs){
        observers.add(obs);
    }

    public void detach(Observer obs){
        observers.remove(obs);
    }

    public void notify(Object state){
        observers.forEach(o -> o.update(state, this));
    }
}
