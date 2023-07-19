package Mediator;

public class ConcreteColleagueB implements Colleague{
    private Mediator m;

    public ConcreteColleagueB(Mediator m){
        this.m = m;
    }

    @Override
    public void update(){
        System.out.println("ConcreteColleaguB: updated");
    }

    @Override
    public void operation(){
        System.out.println("ConcreteColleagueB: some operations");
        m.mynotify();
    }
}
