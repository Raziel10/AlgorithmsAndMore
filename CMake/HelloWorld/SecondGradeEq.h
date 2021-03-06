#include <iostream>
#include <cmath>

class SecondGradeEquation{
    int a, b, c;
    public:
    double x1,x2;
    
    SecondGradeEquation(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void resolve(){
        x1 = 0;
        x2 = 0;

        x1 = (-b + sqrt(pow(b,2) - (4*a*c))) / (2*a); 
        x2 = (-b - sqrt(pow(b,2) - (4*a*c))) / (2*a); 
        std::cout << "x1: " << x1 << " ,x2: " << x2;
    }
};