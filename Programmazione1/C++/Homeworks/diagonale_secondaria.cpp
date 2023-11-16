#include <iostream>

using namespace std;

int main(){
    int n=3;
 //   int m=2;

    int A[n][n]={1,2,3,4,1,2,3,4,5};

    int sum=0;
    int j=n-1;
    for (int i=0; i<n; i++){
        while (j>=0){
            sum+=A[i][j];
            break;
        }
        j--;
        i++;
    }
    cout << sum;
}