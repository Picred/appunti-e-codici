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

  // Si ordina per i tempi di fine
  static void sort(Activity **v, int n) {
    for (int i = 1; i < n; i++) {
      int index = i;

      while (index > 0 && v[index]->end() < v[index - 1]->end()) {
        swap(v[index], v[index - 1]);
        index--;
      }
    }
  }

  static int select(Activity **v, int n) {
    int max = 1;
    int last = 0;

    for (int i = 1; i < n; i++) {
      if (v[i]->start() >= v[last]->end()) {
        max++;
        last = i;
      }
    }

    return max;
  }

  static void print(Activity **v, int n) {
    cout << "TOTAL: " << n << " -> ";
    for (int i = 0; i < n; i++)
      cout << "(s: " << v[i]->start() << " e: " << v[i]->end() << ") ";
    cout << endl;
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
  // Activity::print(v, n);
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