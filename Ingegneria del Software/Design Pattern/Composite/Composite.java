package Composite;

import java.util.*;

public class Composite implements Component {
    private List<Component> l = new ArrayList<>();

    @Override
    public void add(Component c){
        l.add(c);
    }

    @Override
    public void remove(Component c){
        l.remove(c);
    }

    @Override
    public void operation(){
        System.out.println("Composite: operation");
        l.forEach(c -> c.operation());
    }

}
