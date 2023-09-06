#include <fstream>
#include <iostream>
#include <limits.h>

using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

int matrix_chain(int *v, int n) {
  int **table = create_matrix(n, n);

  for (int l = 2; l < n; l++) {
    for (int i = 0; i < n - l; i++) {
      int j = i + l;

      table[i][j] = INT_MAX;

      for (int k = i + 1; k < j; k++) {
        int q = table[i][k] + table[k][j] + v[i] * v[k] * v[j];

        if (q < table[i][j])
          table[i][j] = q;
      }
    }
  }

  return table[0][n - 1];
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    int *vett = new int[n + 1];
    int r, c;

    for (int j = 0; j < n; j++) {
      char tmp;
      in >> tmp;
      in >> r;
      in >> tmp;
      in >> c;
      in >> tmp;
      vett[j] = r;
    }

    vett[n] = c;
    out << matrix_chain(vett, n + 1) << endl;
  }
}