#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> nums;
    

    int aux;
    //read values
    for(int i = 0; i < n; i++){
        cin >> aux;
        nums.push_back(aux);
    }

    vector<int> dp(n,0);
    dp[0] = 1;
    int maxAns = 1; //1 for n == 1

    for(int i = 1; i < n; i++){
        int maxval = 0;
        for(int j = 0; j < i ; j++){
            if(nums[i] > nums[j]){
                //Just if i is bigger that j considert that dp value
                maxval = max(dp[j], maxval);
            }
        }
        dp[i] = maxval + 1;
        maxAns = max(maxAns, dp[i]);
    }
    cout << maxAns;
    
    return 0;
}