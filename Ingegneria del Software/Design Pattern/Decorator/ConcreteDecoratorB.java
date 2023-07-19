package Decorator;

public class ConcreteDecoratorB extends Decorator{
    public ConcreteDecoratorB(Component w){
        super(w);
    }

    public void operation(){
        System.out.println("ConcreteDecoratorB: Decorator recall");
        super.operation();
        System.out.println("ConcreteDecoratorB: added operation");
    }
}
