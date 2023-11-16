// ++ postfisso in classe figlia
//nel main quello che c'è sotto, no virtual, solo a membro
        B operator++(int a){
            B aux = *this;
            p++; //p è private di B
            return aux;
        }

    B* aux=nullptr;
    for(int i=0; i<DIM && aux==nullptr;i++){
        if(typeid(*vett[i]) == typeid(B)){
            cout << i << ")" << *vett[i] << endl;
            aux= ((B*)vett[i]);
            (*aux)++;
            cout << i << ")" << *vett[i] << endl;
            // cout << i << ")" <<*aux;
        }
    }

// ++ prefisso classe figlia
// nel main quello che c'è sopra, no virtual,solo a membro
        C operator++() {
            ++y;
            return *this;
        }

// [] o membro o non a membro, lo stesso
char& A::operator[](int i) {
    return str[i % A::getLen()];
}

cout << "vett[5]=" << (*vett[0])[5] << endl;
(*vett[0])[5]= 1;
cout << "vett[5]=" << (*vett[0])[5] << endl;

//
string A::operator () (int i1, int i2) {
    string s = "";
    for(int i = i1; i < i2; i++) {
        s += A::get(i);
    }
    return s;
}
cout << "*vett[5]=" << *vett[5];
cout << "vett[5](1, 3)=" << (*vett[5])(1, 3) << endl << endl;

// +
short operator+(A& a1, A& a2) {
    return a1.getLen() + a2.getLen();
}
cout << (*vett[5]) + (*vett[6]) << endl;

cout <<(*vett[0])[5] << endl;
(*vett[0])[5]= 1;
cout << (*vett[0])[5];

