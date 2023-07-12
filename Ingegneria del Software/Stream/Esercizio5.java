package Stream;
/*
 * Data una lista di terne di numeri interi, per ciascuna terna verificare se essa costituisce un triangolo. Restituire la lista dei perimetri per le
 * terne che rappresentano triangoli.
 * In un triangolo, ciascun lato è minore della somma degli altri due.
 * Si può rappresentare la terna come un array di tre elementi interi
*/

import java.util.*;
import java.util.function.Predicate;

public class Esercizio5{
    private static List<List<Integer>> l = List.of(List.of(3, 4, 5), List.of(3, 4, 6),
                                List.of(3, 4, 7), List.of(3, 4, 8));


    public static List<Integer> solution(){
        Predicate<List<Integer>> isTriangle = o -> (o.get(0) <= o.get(1) + o.get(2)) && 
                                                    (o.get(1) <= o.get(2) + o.get(0)) && 
                                                    (o.get(2) <= o.get(0) + o.get(1));

        return l.stream()
                .filter(isTriangle)
                .map(o -> o.get(0) + o.get(1) + o.get(2))
                .toList();
    }

    public static void main(String[] args) {
        List<Integer> sol = solution();

        for(Integer i : sol){
            System.out.println(i);
        }
    }

}