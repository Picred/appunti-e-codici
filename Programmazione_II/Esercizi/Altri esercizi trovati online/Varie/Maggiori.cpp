#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");

	for(int task=0 ; task<100 ; task++){
		int N;
		int X;
		in >> N; //Legge lo stream input da file
		in >> X;
		int S[N];
		for(int i=0; i<N ; i++) in >> S[i];

		int M = 0;
		for(int i=0; i<N ; i++){
			if(S[i]>X) M++;
		}
		out << M << " ";
		for(int i=0; i<N ; i++){
			if(S[i]>X)
				out << S[i] << " ";
		}
		out << endl;
	}

	in.close();
	out.close();

	return 0;
}
