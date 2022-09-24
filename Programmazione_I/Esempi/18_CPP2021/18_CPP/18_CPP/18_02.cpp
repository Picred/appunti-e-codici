#include <iostream>
#include <iomanip>

#define COLUMNS 4
#define ROWS 3

using namespace std; 

/* Per un array bidimensionale valgono 
  le stesse considerazioni. 
  Le celle dello array costituiscono un unico 
  blocco di memoria grande ROWSxCOLUMNSxsizeof(int). 
*/ 
void showAddr2(int  v[][COLUMNS], int n){
//void showAddr2(int (*v)[COLUMNS], int n ) 
//voi showAddr2(int *v[COLUMNS], int n) // NO!!

  cout << "showAddr2(v)" << " ovvero verificare che le celle sono contigue.." << endl;
  int *prev = nullptr; 
   for(int i=0; i<n; i++) //righe
    for(int j=0; j<COLUMNS; j++){ //colonne
      //indirizzo del singolo elemento 
      cout << "Address-of(v[" << i << "][" << j << "])=" << &(v[i][j]);
      //aritmetica dei puntatori 
      if(&v[i][j] == prev+1)
	cout << " == Address-of(v[" << (j-1 < 0 ? i-1 : i) << "][" << (j-1 < 0 ? COLUMNS -1 : j-1) << "])+1" << endl; 
      else 
	cout << endl; 
      prev = (int *) &(v[i][j]);
    }
}

void g(int v[][COLUMNS], int n){
  cout << endl; 
  //v e' un puntatore ad un vettore di COLUMNS elementi
  cout << "v  :" << v << ", *v: " << *v << endl;
  cout << " ovvero: " << endl; 
  cout << "&v[0][0]  :" << &v[0][0] << endl << endl;

  int *ptr = &v[0][0];
  cout << "Adesso ptr = &v[0][0], infatti ptr=" << ptr << endl; 

  /* L'espressione (v+i) rappresenta il puntatore 
  * allo elemento di indice (i*COLUMNS, 0), in altre parole v[i][0]
  */
  cout << "(ptr+2*COLUMNS) == (v+2) ? "; 
  cout << (((ptr + 2*COLUMNS) == (int*) (v+2)) ? "true" : "false") << endl; 

  /* L'espressione (*(v+i) + j) rappresenta il puntatore 
  * allo elemento di indice (i,k), in altre parole v[i][k]
  */
  int i=1, j=2;  
  cout << "(*(v+" << i << ") +" << j << "):" << (*(v+i)+j) << endl;
  cout << "   oppure:" << endl; 
  cout << "(v[" << i << "] +" << j << "):" << (v[i]+j) << endl;    
  cout << "   ovvero: " << endl; 
  cout << "&v[" << i << "][" << j << "]:" << &v[i][j] << endl <<  endl;


  cout << "Ricordando che ptr = &v[0][0].." << endl; 
  cout << "(ptr+2*COLUMNS + 1) == (*(v+2) + 1) ? "; 
  cout << ( ( (ptr + 2*COLUMNS + 1) == (int*) (*(v+2) + 1)) ? "true" : "false") << endl << endl;

  //dereferenziando il puntatore si ha accesso al valore 
  cout << "Dereferenziando: " << endl; 
  cout << "*(*(v+" << i << ") +" << j << "):" << *(*(v+i)+j) << endl;
  cout << " oppure:" << endl; 
  cout << "*(v[" << i << "] +" << j << "):" << *(v[i]+j) << endl;    
  cout << " ovvero: " << endl; 
  cout << "v[" << i << "][" << j << "]:" << v[i][j] << endl;

}

int main(){

  int v[ROWS][COLUMNS] = {/* 1st row */ 1,2,3,4, /*2nd row*/ 5,6,7,8, /*3th row*/9,10,11,12};  // 3 x 4

  showAddr2(v, ROWS); 

  g(v, ROWS);
}
