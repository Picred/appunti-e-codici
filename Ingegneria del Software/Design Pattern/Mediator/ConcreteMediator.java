package Mediator;

public class ConcreteMediator implements Mediator{
    Colleague c1 = new ConcreteColleagueA(this);
    Colleague c2 = new ConcreteColleagueB(this);

    @Override
    public void mynotify(){
        c2.update();
    }
}
