package Stream;
/*
 *Data una lista di persone, trovare i nomi dei programmatori con età minore di 30 anni.  
*/
import java.util.List;

public class Esercizio1{
    public record Persona(String name, int age, String role) {}

    private static List<Persona> l = List.of(new Persona("Kent", 29, "CTO"),
                          new Persona("Luigi", 25, "Programmer"),
                          new Persona("Andrea", 26, "GrLeader"),
                          new Persona("Sofia", 26, "Programmer"),
                          new Persona("Alfio", 63, "Programmer"));

    public static void solution(){
        l.stream()
            .filter(p -> p.role == "Programmer")
            .filter(p -> p.age < 30)
            .forEach(p -> System.out.println(p.name));
    }

    public static void main(String[] args) {
        solution();
    }

}