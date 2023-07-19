public class ConcreteCreator extends Creator {
    @Override
    public Product factoryMethod(String param){
        if (param == "A")
            return new ConcreteProductA();
    
        if(param=="B")
            return new ConcreteProductB();
        
        return null;
    }
}
