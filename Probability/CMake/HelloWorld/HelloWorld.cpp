#include <iostream>
#include "SecondGradeEq.h"
//Hello world for c++ using cmake

int main(int argc, char* argv[]){
    int a, b, c;
    
    std::cout << "Hello World";
    std::cout << "Inserta coeficientes de ecuacion de segundo grado:";
    std::cin >> a >> b >> c;
    SecondGradeEquation eq (a,b,c);
    eq.resolve();


    return 0;
}