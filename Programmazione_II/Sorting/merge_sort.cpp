#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void merge(int* vett, int p, int q, int r) {
    int n1 = (q - p) + 1;
    int n2 = r - q;

    int* L = new int[n1+1];
    int* R = new int[n2+1];

    for (int i = 0;i < n1;i++) {
        L[i] = vett[p + i]; //riempiemento array L
    }

    for (int j = 1;j <= n2;j++) {
        R[j-1] = vett[q + j]; //riempimento array R
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    //devo scorrere l'array R,L e il vett
    int i = 0, j = 0, k = p;

    for (k = p;k <= r;k++) {
        if (L[i] < R[j]) {
            vett[k] = L[i];
            i++;
        }
        else {
            vett[k] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;
}

void mergesort(int* vett, int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2.0);

        mergesort(vett, p, q);
        mergesort(vett, q + 1, r);
        merge(vett, p, q, r);
    }
}



int main() {
    int dim = 10;
    int vett[dim];

    for (int i = 0; i < 10;i++) {
        vett[i] = rand() % 100;
    }

    cout << "Vettore non ordinato:" << endl;
    for (int i = 0; i < dim;i++) {
        cout << vett[i] << " ";
    }
    cout << endl;

    mergesort(vett, 0, dim - 1);

    cout << "Vettore ordinato:" << endl;
    for (int i = 0; i < dim;i++) {
        cout << vett[i] << " ";
    }

}