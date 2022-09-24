#include<iostream>
#include<cstdlib>

using namespace std;

//copia oggetti

class A{
    private:
        int a;
        int b;
    public:
        A(int a, int b){
            this->a=a;
            this->b=b;
        }


        int getA(){return this->a;}

        int getB(){return this->b;}

        void print(){
            cout << "a=" << a << " b=" << b << endl;
        }

        friend A operator++(A&,int);
        friend A operator++(A&);
        
};

class Array{
    private:    
        int* vec;
        int dim;
    public:
        Array(int d, int a, int b){
            vec=new int[d];
            for(int i=0; i<d; i++){
                vec[i]=rand()%(b-a+1)+a;
            }
            this -> dim = d;
        }

        void print(){
             for(int i=0; i<dim; i++){
                 cout << vec[i] << " ";
             }
             cout << endl;
        }

        int get(int i){
            return vec[i%dim];
        }

        int& operator[](int);
        
        string operator()(int i1,int i2);
};

A operator+(A o1, A o2){
    return A(o1.getA()+o2.getB() , o1.getB()+o2.getB());
}

A operator++(A& o1, int){
    A aux = o1;
    o1.a+=1;
    o1.b+=1;
    return aux;
}

A operator++(A& o1){
    o1.a++;
    o1.b++;
    return o1;
}

int& Array::operator[](int i){
    return vec[i%dim];
}

//prendo gli elementi che sono compresi fra i1 e i2 e li metto in una stringa

string Array::operator()(int i1,int i2){
    string ret="";
        for(int i=i1; i<i2; i++){
            ret+=Array::get(i);
        }
    return ret;
}



int main(){
    A o1(1,2);
    A o2(10,20);
    A o3=o1+o2;

    // cout << "o1+o2" << endl;
    // o3.print();

    cout << "o1 -> ";
    o1.print();
    cout << "o1++" << endl;
    o1++;
    o1.print();


    cout << "++o1" << endl;
    ++o1;
    o1.print();

/////////////////////////////////////////////////////////////

    Array a1(10,90,65);

    a1.print();

    cout << "prendo l'elemento indice 0" << endl;
    cout << "a1[0] = " << a1[0];

    cout << "\nprovo ()" << endl;

    cout << a1(2,9);


}

