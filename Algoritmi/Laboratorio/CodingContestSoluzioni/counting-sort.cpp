#include <fstream>
#include <iostream>

using namespace std;

void countingSort(ostream &out, int *v, int n) {
  int min = v[0];
  int max = v[0];

  // Trovo il massimo e il minimo
  for (int i = 0; i < n; i++) {
    if (v[i] < min)
      min = v[i];

    else if (v[i] > max)
      max = v[i];
  }

  // Operazioni counting
  int range = (max - min) + 1;
  int *c = new int[range]{0};

  for (int i = 0; i < n; i++)
    c[v[i] - min]++;

  for (int i = 1; i < range; i++)
    c[i] += c[i - 1];

  // Sorting
  int *s = new int[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i] - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  for (int i = 0; i < n; i++)
    out << s[i] << " ";

  out << endl;
}

void fprint(ostream &out) {}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    int *array = new int[n];

    for (int i = 0; i < n; i++)
      in >> array[i];

    countingSort(out, array, n);
  }
}