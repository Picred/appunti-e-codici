/*
A3 Descrivere un algoritmo in notazione NLS che prende in input
un numero N > 0 ed un numero M > 0. Lalgoritmo opera
nel seguente modo:
• stampa i primi N numeri pari, a partire da 0.
• stampa i successivi M numeri dispari.
Ad esempio, per N=5, M=4 lo output sarà:
0 2 4 6 8 9 11 13 15
*/

Leggi N, M //N>0 e M>0
i=0
Stampa i
while (i<2N-2) do
    i=i+2
    Stampa i
end while
j=0
i=i+1
while (j<M) do 
     Stampa i
     i=i+2
     j=j+1
end while