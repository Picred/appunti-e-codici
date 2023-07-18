[**I**] = operazione <font color = "orange"> INTERMEDIA </font>, NON consuma lo Stream
[**T**] = operazione <font color = "red"> TERMINALE </font>, CONSUMA lo Stream



- [**I**] .<font color = "red">stream()</font> : Stream\<T> 
    - Trasforma List\<T> in Stream\<T>


- [**I**] .<font color = "red">parallelStream()</font>:Stream\<T>
    - Restiruisce uno Stream\<T> in parallelo (MultiThread)
    - Usato **solo se** l'HW lo supporta
    - Potrebbe **NON TORNARE** uno Stream\<T> (*se non supportato*)
    - Usato se Stream\<T> è molto popolato


# STATEFULL
- [**T**] .<font color = "red">max</font>(Comparator.comparing(Persona::getEta)) : Optional\<T>
    
    - [**T**] .<font color = "red">min</font>(Comparator.comparing(Persona::getEta)) : Optional\<T>
    - Ricerca il max/min valore nello Stream
    - usa ```isPresent():boolean``` oppure ```isEmpty():boolean``` con ```Optional<T>```
    ```java
        Optional<Persona> pmax = amici.stream()
                                    .filter(x -> x.getEta() < 20)
                                    .max(Comparator.comparing(Persona::getEta));
        if (pmax.isPresent())
            System.out.println("persona: " + pmax.get().getNome());
        //OPPURE
        .max((p1, p2) -> p1.getEta() - p2.getEta());
    ```



-    [**I**] .<font color = "red">sorted</font>(Comparator.comparing(Persona::getName)) : Stream\<T>
    - Ordina lo Stream secondo quello che è specificato in ```comparing()```


- [**I**] .<font color = "red">distinct</font>() : Stream\<T>
    - **Trasforma** lo Stream ed elimina i duplicati





# STATELESS

- [**I**] <font color = "red"> .filter</font>(Predicate\<T>) : Stream\<T> 
    - Inserisce nello Stream\<T> gli elementi che soddisfano il predicato
    - **Concatenare** filter equivale ad AND LOGICO
        ```java 
        //Esempi
        Predicate<String> p = p -> p.equals("a");
        Stream<String> l2 = l.stream().filter(p);
        Stream<String> l3 = l.stream()
                            .filter(s -> s.length() == 2 || s.equals("b"));
        ```


- [**T**] <font color = "red"> .count</font> (): long
    - Conta gli elementi in uno stream


- [**I**] <font color = "red"> .reduce</font>(T identity, BinaryOperator\<T> accumulator): T
    - Applica l'operazione all'intero Stream e ritorna un solo valore
    ```java
    long l3 = l.stream()
                .reduce(0, (v,accum) -> v+accum);
    ```

- [**I**] <font color = "red"> .reduce</font>(Integer::sum): Optional\<T>
    - **Trasforma** Stream di elementi e lo converte in un *UNICO ELEMENTO*
    ```java
        Optional<Persona> pmax = amici.stream()
                                    .filter(x -> x.getEta() < 20)
                                    .reduce(Persona::getMax);
        if (pmax.isPresent())
            System.out.println("persona: " + pmax.get().getNome());
    ```


- [**I**] <font color = "red">.map </font> (Function\<T,R> mapper) : Stream\<R>
    - **Trasforma** lo Stream\<T> in Stream\<R> per ogni elemento
    ```java
    Function<String,Integer> stringLength = x -> x.length();
    
    int result = Stream.of("truth", "flows", "to", "them", "sweetly", "by","nature") // -> Stream<String>
    .map(stringLength) // -> Stream<Integer>
    .reduce(0, Integer::sum); // 31
    ```


- [**T**] .<font color = "red">collect</font>(Collector.toList()) : List\<T>
    - Trasforma lo Stream\<T> in List\<T>
    - E' più flessibile di ```toList()```


- [**T**] .<font color = "red">toList()</font> : List\<T>
    - Trasforma lo Stream\<T> in List\<T>


- [**T**] .<font color = "red">forEach</font>(p -> System.out.println(p))
    - Fa un'ultima operazione con lo Stream



- [**T**] .<font color = "red">findAny</font>() : Optional\<T>
    - [**T**] .<font color = "red">findFirst</font>() : Optional\<T>
        - Verifica se c'è un elemento nello Stream\<T>
        - usa ```isPresent():boolean``` o ```isEmpty():boolean```


- [**I**] .<font color = "red">iterate</font>((2, n) -> n*2) : Stream\<T>
    - Genera uno Stream<\T> infinito
    - Il successivo elemento dipende dal precedente


- [**I**] .<font color = "red">generate</font>(Math.round(Math.random)) : Stream\<T>
    - Genera uno Stream\<T> infinito
    - Gli elementi sono indipendenti



- [**I**] .<font color = "red">limit</font>(int n) : Stream\<T>
    - Blocca la ```iterate()``` oppure ```generate()``` a ```n``` elementi



# IntStream
Ha dei metodi static di classe IntStream

- .<font color = "red">rangeClosed</font>(1, 5) : IntStream
    - Genera un IntStream di numeri che vanno da 1 a 5 (estremi inclusi)

- .<font color = "red">boxed</font>() : Stream\<Integer>
    - Trasforma un IntStream in un Stream\<Integer>

- .<font color = "red">mapToObj</font>(i -> lista.get(i)) : Stream\<T>
    - Trasforma un IntStream in uno Stream di oggetti specificati in ```mapToObj()```

- .<font color = "red">mapToInt</font>(x -> x.length()).sum() : IntStream
    - Esegue la funzione passata e torna un IntStream

```java
    // IntStream NON E' Stream<Integer>
    // 
    IntStream.rangeClosed(1, 6)
            .map(x -> x*6)
            .forEach(System.out::println);

    int v = IntStream.rangeClosed(1, 5).sum(); // 15
```


# Supplier
- Può contenere vari tipi di oggetti e usa il metod get() per ricavarne il contenuto
```java
    Map<String, Supplier<Prodotto>> map = Map.of("primo", ProdottoA::new, "secondo", ProdottoB::new, "terzo", ProdottoC::new);

    public static Prodotto getProdotto(String name) {
        Supplier<Prodotto> s = map.get(name);
        if (s != null)
            return s.get();
        return new ProdottoA();
    } 

// --------------------------
    public static Prodotto getProdotto(String name) {
        return map.getOrDefault(name, ProdottoA::new).get();
    }
```

# Debug
- [**I**] .<font color = "red">peek</font>() : Stream\<T>
    - Utilizza gli elementi dello Stream\<T> e fa qualcosa con essi
    - *Controllo che tutto stia andando bene*

    ```java
    long c = team.stream()
                    .filter(p -> p.getRuolo().equals(ruolo))
                    .peek(p -> System.out.print(p.getNome() + ", "))
                    .count();
    System.out.println("\nCi sono " + c + " " + ruolo);
    ```


# Tipi
```java
Comparator<Persona> myComp = (p1, p2) -> p1.getEta() - p2.getEta();
// Torna:
// 0   se p1 == p2
// < 0 se p1 < p2
// > 0 se p1 > p2
Optional<Persona> pmax = amici.stream()
                                .filter(x -> x.getEta() < 20)
                                .max(myComp)
                                .orElse(0); // Se Optional è null, torna 0 (specificato fra parentesi)
// Ovvero
.max((p1, p2) -> p1.getEta() - p2.getEta());

//-------------------------------------------------------------------------------
Function<String,Integer> stringLength = x -> x.length();
.map(stringLength);
```
