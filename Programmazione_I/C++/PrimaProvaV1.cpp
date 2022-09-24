#include<cstdlib>
#include<ctime>
#define n 2
#define m 4

using namespace std;
// int* foo() sbagliato -> int***foo() è la correzione all'errore
int*** foo(int A*[n][m],unsigned int a, unsigned int b, short s){
    int*** ret = new int**[n];
    
        for(int i=0; i<n; i++){ //creo e copio la matrice
            ret[i]=new int*[m];
                for(int j=0; j<m; j++){
                    ret[i][j]=A[i][j]; //copio anche i nullptr
                }
        }

        for(int j=0;j<m;j++){
            int n_volte=1;
            int el1;
                for(int i=0; i<n;i++){
                    if(A[i][j]!=nullptr){
                        el1=*A[i][j];
                        n_volte=1;
                            for(int k=i+1;k<n;k++){
                                if(el1==*(A[k][j]) && A[k][j])
                                    n_volte++;
                            }
                            if(n_volte>=s){
                                for(int k=i+1;k<n;k++){
                                    if(el1==*(A[k][j]) && A[k][j]){
                                        *ret[i][j]=static_cast<int>(rand()%(b-a+1)+a)*(-1);
                                    }
                                }
                            }
                    }
                }
        }
        return ret;
}