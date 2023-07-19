package Composite;

public class Client {
    public static void main(String[] args) {
        Component leaf = new Leaf();

        leaf.operation();

        Component composite = new Composite();

        composite.add(leaf);
        composite.operation();
    }
}
