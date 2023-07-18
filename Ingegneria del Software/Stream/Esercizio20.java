package Stream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * Restituire una mappa contenente le coppie (nome persone - nazione). 
*/

public class Esercizio20 {
    public static List<Persona> l = List.of(new Persona("p1", 10, "n1"),
                          new Persona("p2", 20, "n1"),
                          new Persona("p3", 30, "n2"),
                          new Persona("p4", 40, "n3"),
                          new Persona("p5", 50, "n3"));

    public static Map<String,String> getCoppie(){
        Map<String,String> mapRet = new HashMap<>();

        l.stream().forEach(p -> mapRet.put(p.nome(), p.nazione()));
        return mapRet;
    }

    public static void main(String[] args) {
        System.out.println(getCoppie());
    }
}
