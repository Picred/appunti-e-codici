package Decorator;

public class ConcreteDecoratorA extends Decorator{
    public ConcreteDecoratorA(Component w){
        super(w);
    }

    public void operation(){
        System.out.println("ConcreteDecoratorA: Decorator recall");
        super.operation();
        System.out.println("ConcreteDecoratorA: added operation");
    }
}
