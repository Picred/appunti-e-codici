package Stream;

import java.util.List;
import java.util.stream.IntStream;
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
                .map(f -> IntStream.of(f.l1(), f.l2(), f.l3(), f.l4()))
                .map(s -> s.min)
                .boxed();
                // .forEach(System.out::println);
    }
}
