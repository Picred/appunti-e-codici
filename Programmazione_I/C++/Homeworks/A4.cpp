/*
A4 Descrivere un algoritmo in notazione NLS che prende in input
un’array A di dimensione N ed un numero p. Si assuma
0 < p < N.
L’algoritmo esegue le seguenti operazioni:
• calcola il massimo valore degli elementi dello array A
che hanno indice minore o uguale a p.
• calcola il minimo valore degli elemento dello array A
con indice maggiore di p.
• calcola e stampa la media aritmetica tra i due valori
calcolati in precedenza.
*/

Leggi A
Leggi p
max <- a[0]
min<-a[p+1]
while (index<n) do
    if index <= p then
       if a[index]>max then
          max<-a[index]
            end if
       else
          if a[index]<min then
            a[index]<-min
           end if
       end if
      index=index+1
end while
media (max+min)/2
Stampa media