#include <iostream>
#include <math.h>
#include <iomanip> 

using namespace std;

int main(void){
    long long int x;
    long long int y;

    double z;

    cin >> x;
    cin >> y;

    double res = (double) x / double (y);
    z = ceil(res);
    if( z == (-0) ){
        cout << "0";
    }
    else{
        cout <<fixed<< std::setprecision(0) << z;
    }
    return 0;
}