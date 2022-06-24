#include <iostream>
#include <cmath>
#include "./BST/bst.h"
#include "./StaticQueue/static_queue.h"
#include <cstdlib>
#include <typeinfo>

using namespace std;

#define PI 3.14159265

#pragma region "Classi"

class Shape{
    protected:
        double area;
    public:
        Shape(){}

        virtual double getArea()=0;

        virtual ostream& put(ostream& os){
            os << " " << typeid(*this).name();
            return os;
        }

        bool operator<(Shape& s){
            return this->area<s.getArea();
        }

        bool operator<=(Shape& s){
            return this->area<=s.getArea();
        }

        bool operator==(Shape& s){
            return this->area==s.getArea();
        }

        bool operator>(Shape& s){
            return this->area>s.getArea();
        }

        bool operator!=(Shape& s){
            return this->area!=s.getArea();
        }
};

class Rectangle : public Shape{
    private:
        double base;
        double altezza;

        template<typename T>
        friend class BST;
    public:
        Rectangle(double base=0, double altezza=0) : Shape() {
            this->base=base;
            this->altezza=altezza;
        }

        double getArea(){
            area=base*altezza;
            return area;
        }

        void setBase(double x){
            this->base=x;
        }

        void setAltezza(double x){
            this->altezza=x;
        }

        ostream& put(ostream& os){
            Shape::put(os);
            os << "\tArea=" << getArea() << endl; 
            return os;
        }

};

class Circle : public Shape{
    private:
        double raggio;

        template<typename T>
        friend class BST;
    public:
        Circle(double raggio=0) : Shape() {
            this->raggio=raggio;
        }

        double getArea(){
            area=(raggio*raggio)*PI;
            return area;
        }

        void setRaggio(double x){
            this->raggio=x;
        }

        ostream& put(ostream& os){
            Shape::put(os);
            os << "\tArea=" << getArea() << endl; 
            return os;
        }

};

class Triangle : public Shape{
    private:
        double base;
        double altezza;

        template<typename T>
        friend class BST;
    public:
        Triangle(double base=0, double altezza=0) : Shape() {
            this->base=base;
            this->altezza=altezza;
        }

        double getArea(){
            area=(base*altezza)/2;
            return area;
        }

        void setBase(double x){
            this->base=x;
        }

        void setAltezza(double x){
            this->altezza=x;
        }

        ostream& put(ostream& os){
            Shape::put(os);
            os << "\tArea=" << getArea() << endl; 
            return os;
        }

};
#pragma endregion
ostream& operator<< (ostream& os, Shape& s){
    return s.put(os);
}
int main(){

    srand(112233);
    int N;
    cout << "Inserire il numero di Shape da creare: ";
    cin >> N;
    
    // Shape* figure[N];

    StaticQueue<Shape*> cerchi(N);
    StaticQueue<Shape*> triangoli(N);
    StaticQueue<Shape*> rettangoli(N);

    int temp;
    
    cout << "Inserire i tipi di Shape da creare: 0:Rettangolo -> 1:Cerchio -> 2:Triangolo:";
    
    for(int i=0; i<N; i++){
            double r1=(double) ((rand()) /( (double)((RAND_MAX/(100)))));
            double r2=(double) ((rand()) /( (double)((RAND_MAX/(100)))));

            cin >> temp;

            while(!(temp>=0 && temp<3)){
                cout << "Inserire un valore corretto!";
                cin >> temp;
            } 

            Shape* obj;

            switch(temp){
                case 0: 
                    obj=new Rectangle(r1,r2); 
                    rettangoli.enqueue(obj);
                    break;
                case 1: 
                    obj=new Circle(r1);
                    cerchi.enqueue(obj); 
                    break;
                case 2: 
                    obj=new Triangle(r1,r2);
                    triangoli.enqueue(obj);
                    break;
            }
            cout << "Figura " << i+1 << " creata!" << endl;
    }

    cout << "\n";

    //Stampo le code;

    cout << "----------CODE----------" << endl;
    
    cout << "Triangoli \n" << triangoli << endl << endl;
    cout << "Rettangoli \n" << rettangoli << endl << endl;
    cout << "Cerchi \n" << cerchi << endl << endl;


    BST<Shape*> albero;

    // //estraggo gli oggetti dalle 3 code e li metto in un bst

    for(int i=0; i<N; i++){
		if(rettangoli.getSize()!=0)
	    	albero.insert(rettangoli.dequeue());

	    if(cerchi.getSize()!=0)
       		albero.insert(cerchi.dequeue());

    	if(triangoli.getSize()!=0)
			albero.insert(triangoli.dequeue());

        if(rettangoli.getSize()==0 && cerchi.getSize()==0 && triangoli.getSize()==0){
            break;
        }
	}

    cout << "----------ALBERO----------" << endl;

    albero.inOrder();

    double a;
    cout << "\nInserire un double area sotto la quale gli elementi dell'albero dovranno essere eliminati:";
    cin>>a;

    albero.remove_area(a);

    cout << "\nAlbero con area maggiore di " << a << ":\n";
    albero.inOrder();
    
    return 0;

}