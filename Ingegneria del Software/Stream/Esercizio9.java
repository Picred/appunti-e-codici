package Stream;

/*
* Restituire il prodotto più economico
*/

import java.util.Comparator;
import java.util.List;

public class Esercizio9{
    private static List<Prodotto> l = List.of(new Prodotto("p1", 80), new Prodotto("p2", 50),
                           new Prodotto("p3", 10), new Prodotto("p4", 20));
    
    public static String getProdottoEconomico(){
        return l.stream()
                .min(Comparator.comparing( p -> p.prezzo()))
                .map( p -> p.nome())
                .get();
    }

    public static void main(String[] args) {
        System.out.println(getProdottoEconomico());
    }
}