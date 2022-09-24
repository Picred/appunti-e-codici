/*2.Due stringhe si dicono sorelle se hanno lo stesso
numero di vocali. Scrivere un metodo che prenda in
input una matrice A di puntatori a stringhe, e
restituisca un boolean che indichi se esiste una
colonna di A in cui sono puntate almeno due stringhe
sorelle.*/

#include <iostream>
#include <cstring>
using namespace std;

void stampa_mat(string* **mat,int n, int m){
    for(int i=0;i<n; i++){
        for(int j=0;j<m;j++){
            cout<<*mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool mat2(string ***mat, int n, int m) {
    for(int j=0; j<m; j++) { //scorri le colonne
        for (int i=0; i<n; i++) { //scorri le righe
            string s1 = *mat[i][j]; //salvo una copia di *mat[i][j]
            int vocali_s1 = 0; //conta le vocali in s1
            for (int h=0; h<s1.length(); h++) { //scorre i caratteri di s1
                if(s1[h]=='a' || s1[h]=='e' || s1[h]=='i' || s1[h]=='o' || s1[h]=='u' || s1[h]=='A' || s1[h]=='E' || s1[h]=='I' || s1[h]=='O' || s1[h]=='U') {
                    vocali_s1++; //conta le vocali
                }
            }
            for (int k=i+1; k<n; k++) { //confronto con le stringhe successive nella stessa colonna
                string s2 = *mat[k][j]; //salvo una copia
                int vocali_s2 = 0; //conto le vocali in s2 come prima
                for (int h=0; h<s1.length(); h++) { 
                    if(s2[h]=='a' || s2[h]=='e' || s2[h]=='i' || s2[h]=='o' || s2[h]=='u' || s2[h]=='A' || s2[h]=='E' || s2[h]=='I' || s2[h]=='O' || s2[h]=='U') {
                            vocali_s2++;
                    }
                }
                if(vocali_s1==vocali_s2) //ho trovato una coppia
                    return true; //restituisco true
            }
        }
    }
    return false;
}

bool mat(string* **mat,int n, int m){
    int j=0,i=0,k=0,z=0;
    int conta=0;
    int vet[m];
    while(j<m){
        while(i<n){
            while(k<((*mat[i][j]).length())){
                if((mat[i][j][0][k] == 'a')||(mat[i][j][0][k] == 'e')||(mat[i][j][0][k] =='i')||(mat[i][j][0][k] =='o')||(mat[i][j][0][k] == 'u'))
                    conta++;
                k++;
            }
            k=0;
            vet[z]= conta;
            conta=0;
            z++;
            i++;
            if(i==n){
                for(int l=0; l<z; l++){
                    for(int p=l+1 ; p<z ; p++){
                        if(vet[l]==vet[p]) return true;
                    }
                }
            }
        }
        z=0;
        j++;
        i=0;
    }
    return false;
}


int main(void){
    int n,m;
    cout<<"inserisci n righe ";
    cin>>n;
    cout<<"inserisci m righe";
    cin>>m;
    // int*vet= new int[10]; vet->[primo elemento,secondo elemtno]
    string ***s=new string**[n];
    for(int i=0; i<n; i++){
        s[i]= new string*[m];
        for(int j=0; j<m;j++){
            s[i][j]= new string[1];
            for(int k=0; k<1; k++){
                cin>>s[i][j][k];
            }
        }
    }
    stampa_mat(s,n,m);
    cout<<endl;
    cout<<mat(s,n,m);
}