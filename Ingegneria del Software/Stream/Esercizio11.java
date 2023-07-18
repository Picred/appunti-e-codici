package Stream;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Stream;

/*
 * Restituire uno stream che contenga il lato minore per ogni figura
*/
public class Esercizio11 {
    private static List<Figura> l = List.of(new Figura(12, 12, 12, 12, 45, 45, 135, 135),
                         new Figura(2, 2, 2, 2, 90, 90, 90, 90),
                         new Figura(1, 2, 1, 2, 90, 90, 90, 90));

    public static Stream<Integer> getLatoMinore(){
        return l.stream()
                .map(f -> List.of(f.l1(), f.l2(), f.l3(), f.l4())
                                .stream()
                                .min(Comparator.naturalOrder())
                                .orElse(0));
    }

    public static void main(String[] args) {
            Stream<Integer> latoMinoreStream = getLatoMinore();
            List<Integer> latoMinoreList = latoMinoreStream.toList();
    
            System.out.println(latoMinoreList);
    }
}
