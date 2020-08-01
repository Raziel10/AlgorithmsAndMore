#include <iostream>
#include <map>
#include <utility>

using namespace std;
map< pair<int,long long int> ,long long int> dp;
long long int SumOfTwoDigits(int S, int L, int Accum){
    long long int count = 0;
    long long int aux;
    if(L == 0){
        if(Accum == S){
            return 1;
        }
        else{
            return 0;
        }
    }
    int i;
    if(Accum == 0 && L > 1) 
        i = 1;
    else 
        i = 0;
    for(; i < 10; i++){
        pair<int,int> p(L,Accum + i );
        if(dp.count(p) > 0 ){
            count += dp[p];
        }else{
            aux = SumOfTwoDigits(S, L-1,Accum + i);
            dp[p] = aux;
            count += dp[p];
        }
        
    }
    return count;
}


int main(void){
    //read values
    int S,L;

    //read s - target
    cin >> S;
    //read L - decimals
    cin >> L;

    //Go recursively to generate all the permutations
    cout << SumOfTwoDigits(S, L, 0);
    return 0;
}

