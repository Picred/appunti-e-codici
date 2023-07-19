public class Multiton {
    private static int n_instances = 0;

    private Multiton(){}

    public static Multiton getInstance(){
        if(n_instances < 2){
            n_instances++;
            return new Multiton();
        }
        return null;
    }    
}
