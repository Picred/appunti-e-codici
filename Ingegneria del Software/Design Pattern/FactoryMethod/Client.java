public class Client {
    public static void main(String[] args) {
        ConcreteCreator creat = new ConcreteCreator();

        Product prodB = creat.operation("B");
        
        System.out.println(prodB);
    }
}
