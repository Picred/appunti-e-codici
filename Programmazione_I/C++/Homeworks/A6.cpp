/*
A6 Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N x N.
L’algoritmo costruisce un nuovo array W di dimensione N che
contiene gli elementi della diagonale principale di V.
*/

//soluzione più efficiente
i=0
while (i<N) do 
    W[i]=V[i][i]
    i=i+1
end while

//soluzione meno efficiente
Leggi V
i=0
while (i<N) do 
    j=0
        while (j<N) do 
          if (i==j) then
             W[i]=V[i][j]
           end if 
         j=j+1
        end while
     i=i+1
end while