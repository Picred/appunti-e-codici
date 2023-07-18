package Stream;
import java.util.List;
/*
 * Calcolare la somma delle età di tutte le persone nella lista
*/
public class Esercizio17 {
    public static List<Persona> l = List.of(new Persona("p1", 10, "n1"),
                          new Persona("p2", 20, "n1"),
                          new Persona("p3", 30, "n2"),
                          new Persona("p4", 40, "n3"),
                          new Persona("p5", 50, "n3"));

    public static int sommaEta = l.stream()
                                    .mapToInt(p -> p.eta())
                                    .sum();

    public static void main(String[] args) {
        System.out.println(sommaEta);
    }
}
