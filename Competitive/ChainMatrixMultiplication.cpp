#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main (void){
    //read values 
    int n;
    cin >> n;
    vector<long long int> mDims;
    //Create dp matrix
    vector< vector<long long int> > dp(n, vector<long long int>(n,LONG_MAX)); 

    for(int i = 0; i < n+1; i++){
        int aux;
        cin >> aux;
        mDims.push_back(aux);
    }
    
    



    //start filling matrix
    int row; 
    for(int d = 0; d < n; d++){
        row = 0;
        for(int column = d; column < n; column++){
            if(row == column){
                dp[row][column] = 0;
            }
            else{
                //follow formula
                //C[i,j] = min { C[i,k] + C[k+1,j] + di-1 * dk *  dj} where i<=k<j
                //iterate over Ks
                int i = row + 1;
                int j = column +1;
                for(int k = row; k < column; k ++){
                    //cout << "Row: " << row << " Column: " << column << " K:" << k;
                    //cout << " d: " << mDims[row] * mDims[k+1] * mDims[column+1]; 
                    long long int kCost = dp[row][k] + dp[k+1][column] + (mDims[row] * mDims[k+1] * mDims[column+1]);
                    //cout << " kCost: " << kCost << endl ; 
                    dp[row][column] = min (dp[row][column], kCost);

                }
            }
            
            row++;
        }
    }
    cout << dp[0][n-1];

    return 0;
}