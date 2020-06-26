#include <iostream>
#include <numeric>
#include <vector>
#include <cmath> 

using namespace std;


string CompareSum( vector<long long int> &A, vector<long long int> &B){

    string message;
    long long int  resA = accumulate(A.begin(), A.end(), 0.0);
    long long int resB = accumulate(B.begin(), B.end(), 0.0);

    if(resA == resB){
        message = "SUM(A)=SUM(B)";
    }
    else if(resA > resB){
        message = "SUM(A)>SUM(B)";
    }
    else if(resA <resB){
        message = "SUM(A)<SUM(B)";
    }
    return message ;

}

int main (void){
    int n;
    vector<long long int> A;
    vector<long long int> B;
    double aux;

    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> aux;
        A.push_back(std::round(aux*1000));
    }

    for(int i = 0; i < n; i++){
        cin >> aux;
        B.push_back(std::round(aux*1000));
    }

    cout << CompareSum(A,B);

    return 0;
}