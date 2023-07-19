package Mediator;

public class ConcreteColleagueA implements Colleague {
    private Mediator m;

    public ConcreteColleagueA(Mediator m){
        this.m = m;
    }

    @Override
    public void update(){
        System.out.println("ConcreteColleagueA: updated");
    }

    @Override
    public void operation(){
        System.out.println("ConcreteColleagueA: operation from user");
        m.mynotify();
    }
}
