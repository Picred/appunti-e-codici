package Adapter;

public class Adapter implements Target {
    private Adaptee adapt = new Adaptee();

    public void request(){
        System.out.println("Adapter: Request");
        adapt.specificRequest();
    }
}
