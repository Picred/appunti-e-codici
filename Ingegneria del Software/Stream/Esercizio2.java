/*
* Data una lista di istanze di Persona trovare i diversi ruoli.
*/

import java.util.List;

public class Esercizio2 {
    public record Persona(String name, int age, String role) {}

    private static List<Persona> l = List.of(new Persona("Kent", 29, "CTO"),
                            new Persona("Luigi", 25, "Programmer"),
                            new Persona("Andrea", 26, "GrLeader"),
                            new Persona("Sofia", 26, "Programmer"));

    public static void solution(){
        l.stream()
            .map(p -> p.role)
            .distinct()
            .forEach(p -> System.out.println(p));
    }

    public static void main(String[] args) {
        solution();
    }
}
