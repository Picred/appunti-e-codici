srand(111222333);

for (int i = 0; i < DIM; i++) {
	short n = 5 + rand() % 5;
	switch (rand() % 3) {
	case 0:
		vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
		break;
	case 1:
		vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
		break;
	case 2:
		vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
	}
}
