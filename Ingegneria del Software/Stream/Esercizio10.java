package Stream;
/*
* Restituire tutte le figure che siano rettangoli o quadrati (tutti gli angoli uguali)
*/
import java.util.List;

public class Esercizio10 {
    private static List<Figura> l = List.of(new Figura(12, 12, 12, 12, 45, 45, 135, 135),
                         new Figura(2, 2, 2, 2, 90, 90, 90, 90),
                         new Figura(1, 2, 1, 2, 90, 90, 90, 90));
    
    public static List<Figura> getQuadRet(){
        return l.stream()
                .filter(f -> f.a1() == f.a2())
                .filter(f-> f.a3() == f.a4())
                .filter(f ->  f.a1() == f.a4())
                .toList();
    }
    
    public static void main(String[] args) {
        
        System.out.println(getQuadRet());        
    }
}