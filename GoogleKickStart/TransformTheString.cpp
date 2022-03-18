
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void fillDP(int* dp, string F ){
    //mark F set in Dp array
    for(int i = 0; i < F.length(); i++){
        dp[F[i]-'a'] = 0;
    }

    //find min dist to each letter
    int minDist = 26;
    for(int i = 0; i < 51; i++){
        if(dp[i%26] == 0){
            minDist = 0;
        }
        else{
            minDist = min(minDist,dp[i%26]);
            dp[i%26] = min(minDist,dp[i%26]);
        }  
        minDist++;
    }
    
    minDist = 26;
    for(int i = 50; i >= 0 ; i--){
        if(dp[i%26] == 0){
            minDist = 0;
        }
        else{ 
            minDist = min(minDist,dp[i%26]);
            dp[i%26] = min(minDist,dp[i%26]);
        }  
        minDist++;
    }
    
}

int TransformTheString(string S, string F){
    int ans = 0;
    int dp[26];
    for(int i = 0; i < 26; i++){
        dp[i] = 26;
    }

    fillDP(dp, F);

    for(int j= 0; j < S.length(); j++){
        ans += dp[S[j] - 'a'];
    }
    return ans;
}

void run_case(int caseNum){
	//cout << "test case!" << endl;
    string S, F;

    cin >> S;
    cin >> F;
    cout << "Case #"  << caseNum << ": " << TransformTheString(S, F) << endl;
}

int main(int argc, char const *argv[])
{

/*#ifndef ONLINE_JUDGE
	freopen( "inputs/a.txt", "r", stdin);
	freopen( "outputs/a.txt", "w", stdout);
#endif*/

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests;
	cin >> tests;

	for (int i = 1; i <= tests; i++) run_case(i);
	return 0;
}