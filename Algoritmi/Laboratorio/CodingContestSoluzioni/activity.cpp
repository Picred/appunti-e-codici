#include <fstream>
#include <iostream>
using namespace std;

class Activity {

private:
  int s;
  int e;

public:
  Activity(int start, int end) {
    s = start;
    e = end;
  }

  int start() { return s; }

  int end() { return e; }

  int profit() { return e - s; }

  // Si ordina per i tempi di fine
  static void sort(Activity **v, int n) {
    for (int i = 1; i < n; i++) {
      int index = i;

      // (1) Ordina per tempi di fine
      // (2) se i tempi di fine sono uguali confronta i tempi di inizio
      while ((index > 0 && v[index]->end() < v[index - 1]->end()) ||
             (index > 0 && v[index]->end() == v[index - 1]->end() &&
              v[index]->start() < v[index - 1]->start())) {
        swap(v[index], v[index - 1]);
        index--;
      }
    }
  }

  static int select(Activity **v, int n) {
    int *t = new int[n]{0};

    for (int i = 0; i < n; i++)
      t[i] = v[i]->profit();

    for (int i = 1; i < n; i++) {

      // j = i trova la prima activity compatibile partendo da i fino a j>=0
      for (int j = i; j >= 0; j--) {
        if (v[j]->end() <= v[i]->start()) {
          t[i] = max(t[i], t[j] + v[i]->profit());
        }
      }
    }

    int max = t[0];

    for (int i = 0; i < n; i++)
      if (t[i] > max)
        max = t[i];

    return max;
  }
};

void solve(ifstream &in, ofstream &out, int n) {
  Activity **v = new Activity *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    int start, end;
    in >> tmp >> start >> end >> tmp;
    v[i] = new Activity(start, end);
  }

  Activity::sort(v, n);
  out << Activity::select(v, n) << endl;
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