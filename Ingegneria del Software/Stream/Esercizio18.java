package Stream;
/*
 * Calcolare le aree dei triangoli rettangoli
 * Usare come base e altezza i lati opposti dell'angolo retto
 * es: se a1 = 90° allora l'area e' data da (l2*l3)/2
*/

import java.util.List;

public class Esercizio18 {
    private static List<Triangolo> t = List.of( new Triangolo(1, 2, 3, 90, 6, 7),
                                                new Triangolo(2, 3, 4, 6, 90, 8),
                                                new Triangolo(3, 4, 5, 7, 8, 9));

    public static int getLatiPerAreaMolt(Triangolo t){
        if (t.a1() == 90) 
            return t.l2()*t.l3();  

        if (t.a2() == 90) 
            return t.l1()*t.l3();   

        if (t.a3() == 90)
            return t.l1()*t.l2();
        
        return 0;
    }

    public static List<Integer> aree(){
        return t.stream()
                .filter(t -> t.a1() == 90 || t.a2() == 90 || t.a3() == 90)
                .map(t -> getLatiPerAreaMolt(t))
                .map(el -> el/2)
                .toList();
    }

    public static void main(String[] args) {
        System.out.println(aree());
    }

}
