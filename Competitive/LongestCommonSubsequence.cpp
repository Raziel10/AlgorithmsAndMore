#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int RecursiveLCS( vector<int>& S1, vector<int>& S2, int i, int j){
    //Exponential aproach
    if(i >= S1.size() || j >= S2.size()){
        return 0;
    }

    if(S1[i] == S2[j]){
        return 1 + RecursiveLCS( S1 , S2 , i+1 , j+1 );
    }
    return max( RecursiveLCS( S1 , S2 , i+1 , j ), RecursiveLCS( S1 , S2 , i , j+1 ));
}

int DPLCS( vector< vector <int> > &dp, vector<int>& S1, vector<int>& S2, int i, int j){
    //implementing same recursive aproach with some memorization
    if( (i >= S1.size()) || (j >= S2.size()) ){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    else{
        if(S1[i] == S2[j]){
            dp[i][j] =  1 + DPLCS( dp , S1 , S2 , i+1 , j+1 );
        }
        else{
            dp[i][j] =  max( DPLCS( dp , S1 , S2 , i+1 , j ), DPLCS( dp , S1 , S2 , i , j+1 ));
        }
    }
    return dp[i][j];
}

int DP2LCS( vector< vector <int> > &dp, vector<int>& S1, vector<int>& S2){
    //implementing same recursive aproach with some memorization
   //iterate over each raw starting from position 1
   for(int x = 1; x <= S1.size() ; x++ ){
       for(int y = 1; y <= S2.size() ; y++ ){
           
           dp[x][y] = max(dp[x-1][y], dp[x][y-1]);

           if(S1[x-1] == S2[y-1]){
               dp[x][y] = max( dp[x-1][y-1] + 1 , dp[x][y]);
           }
       }
   }
    return dp[S1.size()][S2.size()];
}

void printLCSDP( vector < vector <int> >& dp ){
    //not finished yet.
    queue<int> s1;
    queue<int> s2;
    int row = 0;
    int column = 0;

    for(int i = 0; i < dp.size(); i++){
        for( int j = 0; j < dp.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    while(((row < dp.size()) && (column < dp.size())) && dp[row][column] != 0 ){
 
        if( (row + 1 < dp.size() ) && (column + 1 < dp.size()) && (dp[row][column] == (dp[row + 1][column + 1 ] + 1) )){
            //move diagonal
            
            s1.push(row);
            s2.push(column);
            row++;
            column++;
        }
        else if( (row + 1 < dp.size() ) && (dp[row][column] == dp[row + 1][column] )){
            //move down
            row++;
        }
        else if((column + 1 < dp.size() ) && (dp[row][column] == dp[row][column + 1 ] )){
            //move right
            column++;
        }
        else
        {
            break;
        }
    }
    cout << endl;
    while(!s1.empty()){
        cout << s1.front() << " ";
        s1.pop();
    }
    cout << endl;
    while(!s2.empty()){
        cout << s2.front() << " ";
        s2.pop();
    }
    
}

void printLCSDP2( vector < vector <int> >& dp ){
    stack<int> s1;
    stack<int> s2;
    int row = dp.size() - 1;
    int column = dp[0].size() - 1;

    while(dp[row][column] != 0){
 
        if(dp[row][column] == dp[row - 1][column] ){
            //move left
            row--;
        }
        else if(dp[row][column] == dp[row][column - 1 ] ){
            //move up
            column--;
        }
        else if(dp[row][column] == (dp[row - 1][column - 1 ] + 1) ){
            //move diagonal
            s1.push(row - 1);
            s2.push(column - 1);
            row--;
            column--;
        }
    }
    while(!s1.empty()){

        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    while(!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();
    }
    
}

int readSequence( vector<int>& S, int n){
    int aux;
    for(int i = 0; i < n; i++){
        cin >> aux;
        S.push_back(aux);
    }
    return 0;
}


int main (void){
    vector<int> s1;
    vector<int> s2;
    int n;

    cin >> n; 

    readSequence( s1 , n );
    readSequence( s2 , n );

    vector< vector <int> > dp ( n , vector<int>(n, -1));
    vector< vector <int> > dp2 ( n + 1 , vector<int>(n + 1, 0));
    
    //cout << RecursiveLCS(s1,s2,0,0) << endl;
    //cout << DPLCS(dp, s1, s2, 0, 0) << endl;
    //printLCSDP(dp);
    cout << DP2LCS(dp2, s1, s2) << endl;
    printLCSDP2(dp2);


    return 0;

}

