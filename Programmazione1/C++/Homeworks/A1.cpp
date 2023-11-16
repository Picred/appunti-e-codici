/*
A1 Descrivere un algoritmo in notazione NLS che prende in input
tre numeri X, Y, Z.
L’algoritmo deve calcolare e stampare il minore dei tre
numeri.
*/

Leggi X, Y, Z
min=0
if (X<Y) then
    min=X
else
    min=Y
end if
if (min>Z) then
    min=Z
end if
Stampa min