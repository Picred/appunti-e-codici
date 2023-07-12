package Stream;
/*
 * Data una lista di stringhe, produrre una stringa contenente le iniziali di ciascuna stringa della lista
*/

import java.util.List;

public class Esercizio4{
    private static List<String> l = List.of("to", "speak", "the", "truth",
                          "and", "pay", "your", "debts");

    public static void  solution(){
        l.stream()
        .map(o -> o.charAt(0))
        .forEach(o -> System.out.print(o));
    }

    public static void main(String[] args) {
        solution();
    }
}