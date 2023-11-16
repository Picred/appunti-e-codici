/*
A2 Descrivere un algoritmo in notazione NLS che prende in input
un array A di N elementi.
L’algoritmo calcola e stampa il massimo ed il minimo valore
tra tutti gli elementi di A
*/

Leggi A
Leggi N
i=0
max=A[i]
min=A[i]
while (i<N) do
    i=i+1
    if (A[i] < min) then
       min=A[i]
    end if
    if (A[i] > max) then
       max=A[i]
    end if
end while