#include <fstream>
#include <iostream>

using namespace std;

class Coppia {
private:
  int x, y;

public:
  Coppia(double x, double y) {
    this->x = x * 10;
    this->y = y * 10;
  }

  int getx() { return x; }

  int gety() { return y; }

  friend ostream &operator<<(ostream &out, Coppia &c) {
    out << "(" << (double)c.getx() / 10 << " " << (double)c.gety() / 10 << ")";
  }
};

Coppia **countingSort(ostream &out, Coppia **v, int n) {
  int min = v[0]->getx();
  int max = v[0]->getx();

  // Trovo il massimo e il minimo
  for (int i = 0; i < n; i++) {
    if (v[i]->getx() < min)
      min = v[i]->getx();

    else if (v[i]->getx() > max)
      max = v[i]->getx();
  }

  // Operazioni counting
  int range = (max - min) + 1;
  int *c = new int[range]{0};

  for (int i = 0; i < n; i++)
    c[v[i]->getx() - min]++;

  for (int i = 1; i < range; i++)
    c[i] += c[i - 1];

  // Sorting
  Coppia **s = new Coppia *[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i]->getx() - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  return s;
}

void solve(ifstream &in, ofstream &out, int n) {
  Coppia **array = new Coppia *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    double x, y;

    in >> tmp >> x >> y >> tmp;
    array[i] = new Coppia(x, y);
  }

  Coppia **s = countingSort(out, array, n);

  for (int i = 0; i < n; i++) {
    out << *s[i];
    out << " ";
  }

  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    solve(in, out, n);
  }
}