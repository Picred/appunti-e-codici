/* Data una stringa A di dimensioni n ed m confrontare i singoli caratteri 
   es(pippo - poppo )--- in che posizione la lettera non è uguale 
*/

#include <iostream>

using namespace std;

int main(){


    int n=3;
    int m=3;
    string A[n][m]={{"caio", "caio", "caio"},
                    {"prtz","prtz", "prtz"},
                    {"gmf","gmf","gmyf"} };


    for (int i=0; i<n; i++){
        for (int j=1; j<m; j++){
            string s1=A[i][j-1];
            string s2=A[i][j];
            if(s1!=s2){
                for(int k=0; k<s1.length() && k<s2.length(); k++){
                    if(s1[k]!=s2[k]){
                        cout << "caratteri diversi nella posizione k=" << k;
                        return 0; //fermo il programma
                    }
                }
            }

        }
    }
}