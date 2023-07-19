public abstract class Creator {
    public Product operation(String param){
        return factoryMethod(param);
    }

    public abstract Product factoryMethod(String param);
}
