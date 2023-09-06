#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>

using namespace std;

int min_coins_v2(int *v, int n, int r) {
  int *t = new int[r + 1]{0};

  for (int i = 1; i < r + 1; i++)
    t[i] = INT_MAX;

  for (int i = 1; i < r + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (v[j] <= i) {
        // Selezione del sottoproblema
        int sub = t[i - v[j]];

        // Se la soluzione del sottoproblema esiste
        if (sub != INT_MAX)
          t[i] = min(sub + 1, t[i]);
      }
    }
  }

  return t[r];
}

// Con ordinamento
int min_coins(int *v, int n, int r) {
  int *t = new int[r + 1]{0};
  for (int i = 1; i < r + 1; i++)
    t[i] = INT_MAX;

  std::sort(v, v + n);
  int min = INT_MAX;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= r; j++) {
      int sub = t[j - v[i]];
      if (v[i] <= j && sub != INT_MAX)
        t[j] = std::min(sub + 1, t[j]);
    }

    if (t[r] < min)
      min = t[r];
  }

  return min;
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

    out << min_coins_v2(v, n, r) << endl;
  }
}