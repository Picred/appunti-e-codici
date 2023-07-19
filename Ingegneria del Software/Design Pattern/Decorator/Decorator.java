package Decorator;

public class Decorator implements Component {
    private final Component wrap;

    public Decorator(Component w){
        this.wrap = w;
    }

    @Override
    public void operation(){
        System.out.println("Decorator: operation");
        wrap.operation();
    }

    @Override
    public Component getWrapped(){
        return wrap;
    }
}
