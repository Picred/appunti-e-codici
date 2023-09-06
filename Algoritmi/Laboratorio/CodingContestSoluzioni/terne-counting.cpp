#include <fstream>
#include <iostream>

using namespace std;

class Terna {
private:
  int x, y, z;

public:
  Terna(double x, double y, double z) {
    this->x = x * 10;
    this->y = y * 10;
    this->z = z * 10;
  }

  int getx() { return x; }

  int gety() { return y; }

  int getz() { return z; }

  friend ostream &operator<<(ostream &out, Terna &c) {
    out << "(" << (double)c.getx() / 10 << " " << (double)c.gety() / 10 << " "
        << (double)c.getz() / 10 << ")";
  }
};

Terna **countingSort(ostream &out, Terna **v, int n) {
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
  Terna **s = new Terna *[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i]->getx() - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  return s;
}

void solve(ifstream &in, ofstream &out, int n) {
  Terna **array = new Terna *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    double x, y, z;

    in >> tmp >> x >> y >> z >> tmp;
    array[i] = new Terna(x, y, z);
  }

  Terna **s = countingSort(out, array, n);

  for (int i = 0; i < n; i++)
    out << *s[i] << " ";

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