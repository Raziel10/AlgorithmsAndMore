#include <iostream>
#include <vector>

using namespace std;


long long int MaximalSumSquare( vector < vector <int> > &m, vector < vector <int> > &dp,int n, int k, int i, int j){
    //not efficient solution 
    //worst case could even benn n4
    long long int sum = 0;
    if ( (i + k > n) || (j + k > n)){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //Check current posistion 
    for(int a = 0; a < k; a ++){
        for(int b = 0; b < k; b++){
            sum += m[i+a][j+b];
        }
    }
    sum = max(sum, MaximalSumSquare(m,dp,n,k,i+1,j));
    sum = max(sum, MaximalSumSquare(m,dp,n,k,i,j+1));
    dp[i][j] = sum;

    return sum; 
}


long long int IterativeMaximalSumSquare( vector < vector <int> > &m,int n, int k){
    long long int GreatestSum = 0;

    //Create prefix sum array
    vector < vector <long long int> > ps( n + 1, vector <long long int> (n + 1 , 0 ));
      for(int i = 1; i < n + 1 ; i++){
        for(int j = 1; j < n + 1 ; j++){
            //prefix sum formula
            ps[i][j] = ps[i - 1][j]  + ps[i][j-1] - ps[i - 1][ j- 1] + m[i-1][j-1];
            if(i >= k && j >= k){
                //using another formula
                GreatestSum = max(GreatestSum, ps[i][j] - ps[i][j - k] - ps[i - k][j] + ps[i - k][j - k]);
            }
        }
    }
    /*
    for(int i = k; i < n + 1 ; i++){
        for(int j = k; j < n +1 ; j++){
            //Check current posistion 
            GreatestSum = max(GreatestSum, ps[i][j] - ps[i][j - k] - ps[i - k][j] + ps[i - k][j - k]);
        }
    }*/

    return GreatestSum; 
}



int main (void){
    int n;
    int k;
    int aux;

    cin >> n; 
    cin >> k; 


    vector< vector <int> > matrix (n, vector<int>(n,0));
    vector< vector <int> > dp ( n - k  +1 , vector<int>(n - k + 1, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> aux;
            matrix[i][j]=aux;
        }
    }

    //cout << MaximalSumSquare(matrix, dp, n, k, 0, 0);
    cout << IterativeMaximalSumSquare(matrix,n,k);
    return 0;
}