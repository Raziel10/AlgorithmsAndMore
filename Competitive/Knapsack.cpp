//10 Knapsack problem

#include <iostream>
#include <vector>

using namespace std;
vector< vector<int> > dp;
//Recursive solution 
int RecursiveKnapsack(vector<int>& W, vector<int>& n, int Wt, int I){
    if(I == 0){
        dp[I][Wt] = 0;
    }
    else{
        //initial value using previos value
        if(dp[I][Wt] == 0){
            dp[I][Wt] = RecursiveKnapsack(W,n,Wt, I - 1);
            if (Wt >= W[I-1]){
                //use max value including current index value
                dp[I][Wt] = max(dp[I][Wt], RecursiveKnapsack(W,n,Wt - W[I-1], I - 1) + n[I-1]);
            }
        }
        
        
    }
    //cout << "WT : " << Wt << "I: " << I << "val: " << dp[Wt][I] << endl;
    return dp[I][Wt];
}

//IterativeSolution
int IterativeKnapsack(vector<int>& W, vector<int>& n, int Wt){
    
    for(int j = 0; j <= Wt; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n.size(); i++){
        for(int j = 1; j <= Wt; j++){
            dp[i][j] = dp[i-1][j];
            if( j >= W[i - 1] ){
                dp[i][j] = max(dp[i][j], dp[i-1][j - W[i - 1]] + n[i - 1]);
            }
        }
    }

    //Start from last value
    return dp[n.size()][Wt];
}
void PrintDPTable(){
    for(int j  = 0; j < dp.size(); j++){
        for(int i = 0; i < dp[0].size(); i ++){
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    return;
}
void PrintValues(vector<int>& W, vector<int>& n){
    vector <int> results;
    int Ii = dp.size() - 1;
    int Wj = dp[0].size() - 1;
    while (Wj > 0 && dp[Ii][Wj] > 0){
        if(dp[Ii][Wj] == dp[Ii - 1][Wj]){ 
            Ii--;
        }else{
            results.push_back(Ii);
            Ii--;
            Wj-= W[Ii];
        }    
    }

    cout << results.size() << endl;
    for( int c = 0 ; c < results.size() ; c++ ){
        cout << results[c] << " ";
    }
    cout << endl;
    
     
    return;
}




int main (void){
    //read data

    int n;
    int WTarget;
    vector<int> W;
    vector<int> nums;
    cin >> n;
    cin >> WTarget;

    //read values;

    for(int i = 0; i < n ; i ++){
        int WAux, NAux;
        cin >> WAux >> NAux;
        W.push_back(WAux);
        nums.push_back(NAux);
    }

    //Fill dp table 
    for(int k = 0; k <= n; k++){
        vector<int> aux (WTarget+1,0);
        dp.push_back(aux);
    }
    RecursiveKnapsack(W,nums,WTarget,n);

    //PrintDPTable();

    PrintValues(W,nums);

    return 0;
}
