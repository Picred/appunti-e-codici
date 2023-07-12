package Stream;
/*
 * Data una lista di prodotti, restituire il costo totale dei prodotti che hanno un prezzo maggiore di 10.
*/

import java.util.List;

public class Esercizio7 {
    public record Prodotto(String nome, double prezzo) {}

    private static List<Prodotto> l = List.of(new Prodotto("p1", 5.0), new Prodotto("p2", 10.0),
                                new Prodotto("p3", 15.0), new Prodotto("p4", 20.0));

    public static double getCostoTot(){
        return l.stream()
                .map( p -> p.prezzo)
                .filter(p -> p > 10)
                .reduce(0.0, Double::sum);
    }

    public static void main(String[] args) {
        double tot = getCostoTot();
        System.out.println(tot);
    }
}
