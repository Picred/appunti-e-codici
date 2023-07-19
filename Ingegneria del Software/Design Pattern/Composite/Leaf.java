package Composite;

public class Leaf implements Component{
    @Override
    public void operation(){
        System.out.println("Leaf: operation");
    }

    @Override
    public void add(Component c){

    }

    @Override
    public void remove(Component c){

    }
}
