package Stream;
/*
 * Produrre una lista contenente i primi n multipli di 7.
*/
import java.util.stream.Stream;
import java.util.List;

public class Esercizio8 {
    private static int n = 10;

    private static List<Integer> solution =Stream.iterate(7, x -> x+7)
                     .limit(n)
                     .toList();

    public static void main(String[] args) {
        System.out.println(solution);
    }
}
