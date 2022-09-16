#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");

    for(int task=0; task<100; task++){
        string str[1000];
        int S[1000];
        int x;
        int minimo;

        for(int i=0;i<1000;i++)	{ //creo un'array di stringe numeriche
            x=i;
            in>>str[i];
            if(str[i]=="STOP")
                break;
        }

        minimo= atoi(str[0].c_str());

        for(int i=1;i<x;i++){ //trasformo l'array stringhe numeriche in array di int (tralasciando l'ultima stringa ovvero "STOP")
			S[i]=atoi(str[i].c_str());
			if(S[i]<minimo)
				minimo=S[i];
		}
		out << minimo << endl;
    }
    in.close();
	out.close();

	return 0;
}
