package Stream;

import java.util.List;

/*
 * Restituire la lista di nazioni senza ripetizioni presenti in una lista di gente.
*/
public class Esercizio19 {
    public static List<Persona> l = List.of(new Persona("p1", 10, "n1"),
                        new Persona("p2", 20, "n1"),
                        new Persona("p3", 30, "n2"),
                        new Persona("p4", 40, "n3"),
                        new Persona("p5", 50, "n3"));

    public static List<String> nazioniDist(){
        return l.stream()
                .map(p -> p.nazione())
                .distinct()
                .toList();
    }

    public static void main(String[] args) {
        System.out.println(nazioniDist());
    }
}
