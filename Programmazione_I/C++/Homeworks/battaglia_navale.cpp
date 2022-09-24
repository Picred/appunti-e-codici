
#include<iostream>
#include<time.h>
#include<stdlib.h>
const int n = 10;
using namespace std;
bool lancioPC(int H[n][n], int HPC[n][n]);//tira il PC
void p(int H[n][n]);//funzione di stampa ausiliaria
void print(char T[n][n], int M[n][n], int H[n][n]);//stampa
//reset di T ed M H ed HPC
void iniz(char T[n][n], int M[n][n], int H[n][n], int HPC[n][n]);
void set(int M[n][n]);//matrice del computer
void carica(int H[n][n]);//matrice del giocatore

main() {
   bool exit = false, colpito = false;
   int i, j;
   char T[n][n], ch;
   int M[n][n], H[n][n], HPC[n][n], conta = 0, contaPC = 0;
   //inizializz. e caricamento navi lato giocatore
   iniz(T, M, H, HPC);
   set(M);
   carica(H);
   //inizio gioco
   do {
      system("CLS");
      print(T, M, H);
      cout << "riga:";cin >> i;
      cout << "colonna:";cin >> j;
      if (i >= 0 && j >= 0 && i < n && j < n)
         if (M[i][j] == 1) { T[i][j] = 'X';M[i][j] = 0;conta++; }
         else T[i][j] = '0';
      else exit = true;
      colpito = lancioPC(H, HPC);
      if (colpito) { contaPC++; cout << "\a" << flush; }
      if (conta == 15) { cout << "HAI VINTO!!!";print(T, M, H);break; }
      if (contaPC == 15) { cout << "ha vinto il PC";print(T, M, H);break; }
   } while (exit != true);
} //fine main
void p(int H[n][n]) {
   int i, j;
   for (i = 0;i < n;i++) {//stampa T
      for (j = 0;j < n;j++)cout << H[i][j];
      cout << endl;
   }
}//fine p

void print(char T[n][n], int M[n][n], int H[n][n]) {
   int i, j;
   for (i = 0;i < n;i++) {//stampa T
      for (j = 0;j < n;j++) cout << T[i][j];
      cout << endl;
   }
   cout << "----------" << endl;
   for (i = 0;i < n;i++) {//stampa H
      for (j = 0;j < n;j++) cout << H[i][j];
      cout << endl;
   }
}//fine print

void iniz(
   char T[n][n], int M[n][n], int H[n][n], int HPC[n][n]) {
   int i, j;
   for (i = 0;i < n;i++)//iniz.T
      for (j = 0;j < n;j++) T[i][j] = '=';

   for (i = 0;i < n;i++)//iniz.M
      for (j = 0;j < n;j++) M[i][j] = 0;

   for (i = 0;i < n;i++)//iniz.H
      for (j = 0;j < n;j++) H[i][j] = 0;

   for (i = 0;i < n;i++)//iniz.HPC
      for (j = 0;j < n;j++) HPC[i][j] = 0;
}//fine iniz

void set(int M[n][n]) {
   bool occupato = false;
   int row, col, i, j, s;
   srand(time(0));
   //caricamento nave da 4
   s = rand() % 2;
   row = rand() % 7;
   col = rand() % 7;
   if (s == 0)for (j = col;j < col + 4;j++)M[row][j] = 1;
   else for (i = row; i < row + 4;i++)M[i][col] = 1;
   //caricamento 2 navi da 3
   for (i = 0;i < 2;i++) {
      do {
         occupato = false;
         s = rand() % 2;
         row = rand() % 8;
         col = rand() % 8;
         if (M[row][col] != 0)occupato = true;
         else {
            if (s == 0) {
               if (M[row][col + 1] != 0 || M[row][col + 2] != 0)occupato = true;
               else { M[row][col] = 1;M[row][col + 1] = 1;M[row][col + 2] = 1; }
            }
            else {
               if (M[row + 1][col] != 0 || M[row + 2][col] != 0)occupato = true;
               else { M[row][col] = 1;M[row + 1][col] = 1;M[row + 2][col] = 1; }
            }
         }
      } while (occupato == true);
   }//fine for
//caricamento 2 navi da 2
   for (i = 0;i < 2;i++) {
      do {
         occupato = false;
         s = rand() % 2;
         row = rand() % 8;
         col = rand() % 8;
         if (M[row][col] != 0)occupato = true;
         else {
            if (s == 0) {
               if (M[row][col + 1] != 0)occupato = true; else { M[row][col] = 1;M[row][col + 1] = 1; }
            }
            else {
               if (M[row + 1][col] != 0)occupato = true;
               else { M[row][col] = 1;M[row + 1][col] = 1; }
            }
         }
      } while (occupato == true);
   }//fine for

//caricamento una nave da 1
   do {
      occupato = false;
      row = rand() % 10;
      col = rand() % 10;
      if (M[row][col] != 0)occupato = true;
      else M[row][col] = 1;
   } while (occupato == true); //fine caricamento una nave da 1
}//fine set(M)

void carica(int H[n][n]) {
   //'valido' controlla che la nave sia nei limiti della matrice
   //e che non vada a collidere con altre navi
   bool occupato = false,
      valido = false;
   int row, col, i, j, s;
   do {//caricamento nave da 4
      valido = false;
      cout << "riga iniz.nave da 4:";cin >> row;
      cout << "colonna iniz.nave da 4:";cin >> col;
      cout << "orientamento (0/1):";cin >> s;
      if (row >= 0 && col >= 0 && row < n && col < n) {
         if (s == 0 && col + 4 < n) {
            for (j = col;j < col + 4;j++)H[row][j] = 1;
            valido = true;system("CLS");p(H);
         }
         if (s == 1 && row + 4 < n) {
            for (i = row;i < row + 4;i++)H[i][col] = 1;
            system("CLS");
            valido = true;p(H);
         }
      }
      else valido = false;
   } while (valido != true);
   //fine caricamento nave da 4
   for (i = 0;i < 2;i++) {//caricamento 2 navi da 3
      do {
         valido = false;
         cout << "riga iniz.nave da 3:";cin >> row;
         cout << "colonna iniz.nave da 3:";cin >> col;
         cout << "orientamento (0/1):";cin >> s;
         if (row >= 0 && col >= 0 && row < n && col < n) {
            if (H[row][col] == 0) {
               if (s == 0 && col + 2 < n && H[row][col + 1] == 0 && H[row][col + 2] == 0) {
                  for (j = col;j < col + 3;j++)H[row][j] = 1;
                  system("CLS");
                  valido = true;p(H);
               }
               if (s == 1 && row + 2 < n && H[row + 1][col] == 0 && H[row + 2][col] == 0) {
                  for (j = row;j < row + 3;j++)H[j][col] = 1;
                  system("CLS");
                  valido = true;p(H);
               }
            }
            else valido = false;
         }
         else valido = false;
      } while (valido == false);
   }//fine caricamento 2 navi da 3

   for (i = 0;i < 2;i++) {//caricamento 2 navi da 2
      do {
         valido = false;
         cout << "riga iniz.nave da 2:";cin >> row;
         cout << "colonna iniz.nave da 2:";cin >> col;
         cout << "orientamento (0/1):";cin >> s;
         if (row >= 0 && col >= 0 && row < n && col < n) {
            if (H[row][col] == 0) {
               if (s == 0 && col + 1 < n && H[row][col + 1] == 0) {
                  for (j = col;j < col + 2;j++)H[row][j] = 1;
                  system("CLS");
                  valido = true;p(H);
               }
               if (s == 1 && row + 1 < n && H[row + 1][col] == 0) {
                  for (j = row;j < row + 2;j++)H[j][col] = 1;
                  system("CLS");
                  valido = true;p(H);
               }
            }
            else valido = false;
         }
         else valido = false;
      } while (valido == false);
   }//fine caricamento 2 navi da 2

   do {//caricamento una nave da 1
      valido = false;
      cout << "riga nave da 1:"; cin >> row;
      cout << "colonna nave da 1:";cin >> col;
      if (H[row][col] != 0)valido = false;
      else { H[row][col] = 1;valido = true; }
   } while (valido == false); //fine caricamento una nave da 1
}//fine carica(H)

bool lancioPC(int H[n][n], int HPC[n][n]) {
   bool valido = false;
   int row, col;
   bool trovato = false;
   srand(time(0));
   do {
      valido = false;
      row = rand() % 10;
      col = rand() % 10;
      if (HPC[row][col] == 1)valido = false;
      else { valido = true;HPC[row][col] = 1; }
      if (valido)
         if (H[row][col] == 1) { H[row][col] = 0;trovato = true; }
   } while (valido == false);
   return trovato;
}//fine lancioPC