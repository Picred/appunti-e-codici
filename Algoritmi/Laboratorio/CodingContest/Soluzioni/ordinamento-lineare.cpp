#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;

int *countingSort(ofstream &out, int *v, int n) {
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

  return s;
}

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  int *array = new int[n];

  for (int i = 0; i < n; i++) {
    H value;
    in >> value;
    typeid(H) == typeid(double) ? array[i] = value * 10 : array[i] = value;
  }

  int *s = countingSort(out, array, n);

  for (int i = 0; i < n; i++) {
    if (typeid(H) == typeid(double))
      out << (double)s[i] / 10;

    else if (typeid(H) == typeid(char))
      out << (char)s[i];

    else
      out << s[i];

    out << " ";
  }

  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type;
    int n;
    in >> type;
    in >> n;

    if (type == "int" || type == "bool")
      solve<int>(in, out, n);

    else if (type == "char")
      solve<char>(in, out, n);

    else if (type == "double")
      solve<double>(in, out, n);
  }
}