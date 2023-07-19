package Observer;

public class Client {
    public static void main(String[] args) {
        ConcreteSubject subj = new ConcreteSubject();
        Observer obs = new ConcreteObserver();

        subj.attach(obs);

        subj.add(4);
        subj.add(26);
    }
}
