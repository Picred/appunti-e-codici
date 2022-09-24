srand(111222333);
string S;

short fa = 3;

for (int i = 0; i < DIM; i++) {
	short n = 10 + rand() % 10;
	S = "";
	for (int k = 0; k < 20; k++)
		S += rand() % ('z' - 'a' + 1) + 'a';
	if (rand() % 2 == 0)
		vett[i] = new B(n, S);
	else
		vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
}
