/*
 * Data una lista di numeri interi positivi, verificare se la lista è ordinata.
*/
import java.util.List;

public class Esercizio6 {
    private static List<Integer> l = List.of(1,2,3, 4, -2);


    public static void main(String[] args) {
        boolean isOrdinata = l.stream()
                              .sorted()
                              .toList()
                              .equals(l);
        if(isOrdinata)
            System.out.println("Ordinata");
        else
            System.out.println("NON Ordinata");
    }
}