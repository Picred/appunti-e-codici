/*
 * Data una lista di stringhe, produrre una lista che contiene solo le stringhe che cominciano con un certo prefisso noto
*/

import java.util.List;

public class Esercizio3 {
    private static List<String> l = List.of("author", "auto",
                          "autocorrect", "begin",
                          "big", "bigger", "biggish");

    public static void solution(String start){
        l.stream()
        .filter(o->o.startsWith(start))
        .forEach(o->System.out.println(o));
    }

    public static void main(String[] args) {
        solution("b");
    }
}
