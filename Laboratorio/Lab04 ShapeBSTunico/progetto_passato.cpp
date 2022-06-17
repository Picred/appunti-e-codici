#include <iostream>
#include "bst.h"
#include "queue.h"
#include <cstdlib>
#include <ctime>
#include <string>

#define PI 3.14

using namespace std;

class Shape{
    public:
        Shape(){}

        virtual double getArea()=0;
};

class Rectangle : public Shape{
    private:
        double base,altezza;
    public:
        Rectangle(double _base, double _altezza):Shape(){
            base=_base;
            altezza=_altezza;
        }

        double getArea(){
            return base*altezza;
        }
};

class Circle : public Shape{
    private:
        double raggio;
    public:
        Circle(double _raggio):Shape(){
            raggio=_raggio;
        }

        double getArea(){
            return (raggio*raggio)*PI;
        }
};

class Triangle : public Shape{
    private:
        double base,altezza;
    public:
        Triangle(double _base, double _altezza):Shape(){
            base=_base;
            altezza=_altezza;
        }

        double getArea(){
            return (base*altezza)/2;
        }
};

int main(){
    Queue<Rectangle> r;
    Queue<Circle> c;
    Queue<Triangle> t;
    
    int N = 10;
    //n inserito da utente

    Shape* shapes[10];

    //shape scelta da utente
    string scelta="triangolo";
    int i=0;
    if(scelta == "triangolo"){
        shapes[i]=new Triangle(1.56,3.58);
        t.enqueue(shapes[i]);
        i++;
    }


    
}