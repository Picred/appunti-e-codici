#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++)
      v[i][j] = INT_MAX;

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

void min_coins(int *v, int n, int r, ofstream &out) {
  std::sort(v, v + n);

  int **table = create_matrix(n + 1, r + 1);

  for (int i = 0; i < n; i++) {
    int index =
        i + 1; // Index righe tabella (Si parte dalla prima riga della matrice)

    for (int j = 1; j < r + 1; j++) {
      table[index][j] = table[index - 1][j];

      if (j >= v[i]) {
        int sub = table[index][j - v[i]];

        if (sub != INT_MAX)
          table[index][j] = min(sub + 1, table[index][j]);
      }
    }
  }

  // SOLUZIONE: numero di monete
  out << table[n][r] << " ";

  // STAMPA DELLE MONETE
  string print;
  int i = n;
  int j = r;

  while (i > 0 && j > 0) {
    int sub = j - v[i - 1]; // Sottosoluzione

    if (table[i][j] == table[i][sub] + 1 && sub >= 0) {
      j = sub;
      stringstream ss;
      ss << v[i - 1];
      string s = ss.str();
      print = s + " " + print;
    } else {
      i--;
    }
  }

  out << print << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int r, n;
    in >> r >> n;

    int *v = new int[n];

    for (int j = 0; j < n; j++)
      in >> v[j];

    min_coins(v, n, r, out);
  }
}