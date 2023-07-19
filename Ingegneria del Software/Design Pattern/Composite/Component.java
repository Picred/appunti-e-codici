package Composite;

public interface Component {
    public void operation();
    public void add(Component c);
    public void remove(Component c);
}
