package Stream;

import java.util.List;
/*
 * Creare un metodo che prende in ingresso due parametri, min e max,
 *  e restituisce una lista di istanze di persona costituita da elementi di gente che hanno età compresa fra min e max.
*/
public class Esercizio16{
    public static List<Persona> l = List.of(new Persona("p1", 10, "n1"),
                            new Persona("p2", 20, "n1"),
                            new Persona("p3", 30, "n2"),
                            new Persona("p4", 40, "n3"),
                            new Persona("p5", 50, "n3"));
    

    public static List<Persona> solution(int max, int min){
        return l.stream()
                .filter(p -> p.eta() >= min)
                .filter(p -> p.eta() <= max)
                .toList();
    }

    public static void main(String[] args) {
        int min = 20, max = 40;
        System.out.println(solution(max, min));
    }
}