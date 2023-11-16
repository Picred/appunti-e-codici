#ifndef SORTING_H
#define SORTING_H
#include <climits>
#include <cmath>

namespace sorting {

    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    bool dicotomicaRicorsiva(int vett[], int key, int start, int end) {
        if (start > end) {
            return false;
        }

        int m = (end + start) / 2;

        if (vett[m] == key) {
            return true;
        }

        if (key < vett[m]) {
            return dicotomicaRicorsiva(vett, key, start, m - 1);
        }

        if (key > vett[m]) {
            return dicotomicaRicorsiva(vett, key, m + 1, end);
        }

        return false;
    }

    bool dicotomicaIterativa(int vett[], int size, int key) {
        int start = 0;
        int end = size - 1;
        int midpoint;
        bool found = false;

        while (!found && start <= end) {
            midpoint = (start + end) / 2;

            if (vett[midpoint] == key)
                found = true;

            if (key < vett[midpoint])
                end = midpoint - 1;

            if (key > vett[midpoint])
                start = midpoint + 1;
        }

        return found;
    }

    void ordinamentoPerScambio(int vett[], int size) {
        for (int i = 0; i < size - 1;i++) {
            for (int j = i + 1;j < size;j++) {
                if (vett[j] < vett[i])
                    swap(vett[i], vett[j]);
            }
        }
    }

    void selectionSort(int vett[], int dim) {
        int indexMin;
        for (int i = 0; i < dim; i++) {
            indexMin = i;
            for (int j = i + 1;j < dim; j++) {
                if (vett[j] < vett[indexMin])
                    indexMin = j;
            }
            swap(vett[i], vett[indexMin]);
        }
    }

    void insertionSort(int vett[], int dim) {
        int temp, j;

        for (int i = 1; i < dim; i++) {
            temp = vett[i];
            for (j = i; j > 0; j--) {
                if (temp < vett[j - 1])
                    vett[j] = vett[j - 1];
                else break;
            }
            vett[j] = temp;
        }
    }

    void merge(int A[], int p, int q, int r) {

        //Array sinistro L[n1], Array destro R[n2];
        int n1 = q - p + 1;
        int n2 = r - q;

        int* L = new int[n1 + 1];
        int* R = new int[n2 + 1];

        for (int i = 0; i <= n1;i++) {
            L[i] = A[p + i];
        }

        for (int j = 0; j <= n2;j++) {
            R[j - 1] = A[q + j];
        }

        L[n1] = INT_MAX;
        R[n2] = INT_MAX;

        //confronto L ed R e copio su A

        // L[i] R[j] A[k]
        int i = 0, j = 0, k = 0;

        for (k = p;k <= r;k++) {
            if (L[i] < R[j]) {
                A[k] = L[i++];
            }

            else {
                A[k] = R[j++];
            }
        }
    }

    void mergeSort(int A[], int p, int r) {
        if (p < r) {
            int q = floor((p + r) / 2);

            mergeSort(A, p, q);
            mergeSort(A, q + 1, r);
            merge(A, p, q, r);
        }
    }
}

void bubblesort(int vett[], int dim) {

    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (vett[i] > vett[j]) {
                int temp = vett[i];
                vett[i] = vett[j];
                vett[j] = temp;
            }
        }
    }
}
#endif