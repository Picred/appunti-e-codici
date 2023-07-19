package Decorator;

public class ConcreteComponent implements Component{
    @Override
    public void operation(){
        System.out.println("ConcreteComponent: operation");
    }

    @Override
    public Component getWrapped(){
        return this;
    }
}
