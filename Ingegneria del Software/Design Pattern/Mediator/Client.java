package Mediator;

public class Client {
    public static void main(String[] args) {
        Mediator m = new ConcreteMediator();
        Colleague c1 = new ConcreteColleagueA(m);
        Colleague c2 = new ConcreteColleagueB(m);

        c1.operation();
    }
}
