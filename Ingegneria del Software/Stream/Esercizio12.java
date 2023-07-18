package Stream;
import java.util.List;

/*
 * Restituire il perimetro minore tra tutte le figure
*/

public class Esercizio12 {
    private static List<Figura> l = List.of(new Figura(12, 12, 12, 12, 45, 45, 135, 135),
                         new Figura(2, 2, 2, 2, 90, 90, 90, 90),
                         new Figura(1, 2, 1, 2, 90, 90, 90, 90));

    public static int getPerimetroMinore(){
        return l.stream()
                .mapToInt(f -> f.l1() + f.l2() + f.l3() + f.l4())
                .min()
                .orElse(0);
    }

    public static void main(String[] args) {
        System.out.println(getPerimetroMinore());
    }
}
