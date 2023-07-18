package Stream;
import java.util.List;
import java.util.Comparator;
import java.util.stream.Collectors;

/*
 * Restituire la somma totale dei costi dei 2 prodotti meno cari
*/

public class Esercizio14 {
    public static List<Prodotto> l = List.of(new Prodotto("p1", 80),
                           new Prodotto("p2", 40),
                           new Prodotto("p3", 10),
                           new Prodotto("p4", 90));

    public static List<Prodotto> lOrdinata = l.stream()
                                .sorted(Comparator.comparing(Prodotto::prezzo))
                                .collect(Collectors.toList());
    
    public static double sommaTotMenoCari = lOrdinata.stream()
                                                    .limit(2)
                                                    .mapToDouble(p -> p.prezzo())
                                                    .sum();
    public static void main(String[] args) {
        System.out.println(sommaTotMenoCari);
    }
}
