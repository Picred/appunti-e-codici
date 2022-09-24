/* Scrivere un metodo che prenda come parametri
formali una matrice A di stringhe ed un intero k, e
restituisca in output una copia di A in cui tutte le
stringhe della colonna k-esima siano state epurate
dalle lettere non italiane.*/

#include<string>
using namespace std;

#define N 2
#define M 3

string ** fun(string A[N][M], int k) {
    string **out = new string*[N];
    string whitelist = "abcdefghilmnopqrstuvz";
    for(int i=0; i<N; i++) {
        out[i] = new string[M];
        for(int j=0; j<M; j++) {
            if(j!=k) {
                out[i][j] = A[i][j];
            } else {
                out[i][j] = "";
                for(h=0; h<A[i][j].length();h++) {
                    char c = A[i][j][h];
                    for(l=0; l<whitelist.length(); l++)
                        if(c==whitelist[l]) {
                            out[i][j]+=c;
                            break;
                        }
                    //if(whitelist.find(c)!=string::npos)
                    //    out[i][j]+=c;
                }
            }
        }
    }
}