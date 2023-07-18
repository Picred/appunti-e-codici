package Stream;
/*
 *Restituire la lista di lati maggiori dei triangoli.
*/

import java.util.Comparator;
import java.util.List;

public class Esercizio15 {
    public static List<Triangolo> l = List.of(new Triangolo(3, 4, 5, 30, 60, 90),
                            new Triangolo(4, 5, 4, 30, 30, 120),
                            new Triangolo(13, 5, 12, 30, 60, 90),
                            new Triangolo(17, 15, 8, 30, 60, 90));

    public static List<Integer> latiMaggiori = l.stream()
                                                .map(t -> List.of(t.l1(), t.l2(), t.l3())
                                                            .stream()
                                                            .sorted(Comparator.reverseOrder())
                                                            .findFirst()
                                                            .orElse(0)
                                                    )
                                                .toList();
    public static void main(String[] args) {
        System.out.println(latiMaggiori);
    }
}
