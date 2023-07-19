package Decorator;

public class Client {
    public static void main(String[] args) {
        Component comp = new ConcreteComponent();
        comp.operation();
        
        Component comp2 = new ConcreteDecoratorA(new ConcreteDecoratorB(comp));

        comp2.operation();

        System.out.println("\nRemoving Decorators...\n");

        Component comp3 = comp2.getWrapped();

        comp3.operation();
    }

}
