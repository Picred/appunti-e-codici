#include <fstream>
#include <iostream>
using namespace std;

namespace sort {

void swap(int *v, int x, int y) {
  int tmp = v[x];
  v[x] = v[y];
  v[y] = tmp;
}

void insertionSort(int *v, int n) {
  for (int i = 1; i < n; i++) {
    int index = i;

    while (index >= 1 && v[index] > v[index - 1]) { // Desc order
      swap(v, index, index - 1);
      index--;
    }
  }
}
} // namespace sort

void knapsack(ofstream &out, int *v, int n, int p) {
  sort::insertionSort(v, n);
  int max = 0;

  for (int i = 0; i < p; i++)
    max += v[i];

  out << max << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n, p;
    in >> n >> p;

    int *v = new int[n];

    for (int j = 0; j < n; j++)
      in >> v[j];

    knapsack(out, v, n, p);
    delete[] v;
  }
}