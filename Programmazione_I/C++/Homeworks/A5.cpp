/*
A5 Descrivere un algoritmo in notazione NLS che prende in input
un array A di N elementi e due numeri a e b. Si assuma a < b.
L’algoritmo dovr`a stampare il numero di elementi dello array (sia A[i] il generico elemento di A) tali che
a ≤ A[i] ≤ b.
*/

Leggi N
Leggi a,b // a<b
i=0

while (i<N) do
	if (A[i]<=b && A[i]>=a) then
		Stampa A[i]
	end if
	i++
end while