#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    string path_to_file = "abc/testo.txt";
    ifstream file(path_to_file);

    if(!file.is_open()){
        cerr << "Attenzione il file "<< path_to_file << " non esiste.";
        return 1;
    }

    string x;
    while(file >> x) {
        cout << x << endl;
    }

    file.close();
    ifstream file2(path_to_file);

    cout << endl;
    string y;
    while(getline(file2, y)) {
        cout << y << endl;
    }

    ofstream file3("output.txt");

    file3 << "RIGA UNO"<<endl;
    file3 << "RIGA DUE"<<endl;

    fstream file4("output2.txt", fstream::out);
    file4 << "RIGA UNO"<<endl;
    file4 << "RIGA DUE"<<endl;

    fstream file5("output2.txt", fstream::in);
    string xx;
    file5 >> xx;
    cout << xx;
}