package Stream;
import java.util.List;

/*
 * Ottenere la somma del valore dell'area di tutte le figure
*/

public class Esercizio13 {
    private static List<Figura> l = List.of(new Figura(12, 12, 12, 12, 45, 45, 135, 135),
                         new Figura(2, 2, 2, 2, 90, 90, 90, 90),
                         new Figura(1, 2, 1, 2, 90, 90, 90, 90));

    public static void getAreaTot(){
        int areaTot = l.stream()
            .mapToInt(f -> f.l1() * f.l2())
            .sum();
        
        System.out.println(areaTot);
    }

    public static void main(String[] args) {
        getAreaTot();
    }
}
