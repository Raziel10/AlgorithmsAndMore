
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
/*
int main (void){
    int n;
    int value;
    int smallest, largest;
    vector<int> nums;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> value;
        nums.push_back(value);
        smallest = *min_element(nums.begin(), nums.end());
        largest = *max_element(nums.begin(), nums.end());
    }

    vector< vector <int> > dp (n, vector<int>(largest + 1, 0));

    for(int i = smallest; i <= largest; i ++){
        dp[0][i] = abs(i - smallest);
    }

    for(int i = 1; i < n ; i ++){
        int minimum = INT_MAX;
        for(int j = smallest; j <= largest ; j++){
            minimum = min(minimum, dp[i-1][j]);
            dp[i][j] = minimum + abs( j - nums[i]);
        }
    }

    int ans = INT_MAX;
    for(int j = smallest; j <= largest ; j++){
        ans = min(ans, dp[n - 1][j]);
    }
    cout << ans;
    return 0;
}
*/

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m = *max_element(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int bestBelow = 1e9;
        for (int j = 0; j <= m; ++j) {
            bestBelow = min(bestBelow, dp[i][j]);
            dp[i + 1][j] = bestBelow + abs(a[i] - j);
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';

    return 0;
}

//read values
//read n 
//read n values and store it in vector

//Find max value (n)
// Find min value (n)

//Create matrix row n+1, small - max
//Each row (i) represents the current index in array we what to find minimum steps
//Each column (j) depicts minimun steps to make current index equal to j value


// fill first row  (0) with difference between small and matrix (n)
// create fill the rest of the values, we need to consider min value from previos i index

//fin min value from the last index filled
