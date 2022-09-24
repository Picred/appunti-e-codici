srand(111222333);
A *vett[DIM];

string S = "supercalifragilistichespiralidoso";

for (int i = 0; i < DIM; i++) {
  short n = 3 + rand() % 10;
  if (rand() % 2 == 0)
    vett[i] = new B(n, S);
  else
    vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
}
