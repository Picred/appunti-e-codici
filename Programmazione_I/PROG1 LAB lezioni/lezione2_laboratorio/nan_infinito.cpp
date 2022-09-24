#include<iostream>
#include<cmath>

int main() {
    //NAN sta per "not a number" e indica valori numerici non validi
    //std::cout << NAN << std::endl;
    //indica +infinito
    //std::cout << +INFINITY << std::endl;
    //indica -infinito
    //std::cout << -INFINITY << std::endl;

    //std::cout << 0.0/0 << std::endl; //nan
    //std::cout << 1.0/0 << std::endl; //infinity
    //std::cout << -1.0/0 << std::endl; //-infinity
    //std::cout << 1/INFINITY << std::endl; //0

    float x = 0.0/0;
    float y = x + 1;

    std::cout << y << std::endl;

    std::cout << "Hello";
}