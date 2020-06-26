#include <iostream>
#include <iomanip>

using namespace std;

int main (void){
    long double res = 0;
    long double aux;
    int n;

    cin >> n;
    for(int j = 0; j < n; j++){
        cin >> aux;
        res = res + ((aux * aux + 1) / aux);
    }
    
    cout<<fixed<<setprecision(11)<<res;
    return 0;
}