
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


long long int TrashBins(int N, string trashes){
    long long int ans = 0;
    bool trashFound = false;
    int last_trash_indx = 0;
    vector<int> min_distance (trashes.length(),INT_MAX);

    for(int i = 0; i < trashes.length(); i++){
        if(trashes[i] == '1'){
            last_trash_indx = i;
            trashFound = true;
        }
        if(trashFound){
            min_distance[i] = i - last_trash_indx;
            
        }
    }
    trashFound = false;
    for(int i = trashes.length() - 1; i >= 0; i--){
        if(trashes[i] == '1'){
            last_trash_indx = i;
            trashFound = true;
        }
        if(trashFound){
            min_distance[i] = min(min_distance[i], last_trash_indx - i);
        }
        ans += min_distance[i];
    }

    return ans;
}

void run_case(int caseNum){
	int N;
    string trash_map;
    cin >> N;
    cin >> trash_map;

    cout << "Case #"  << caseNum << ": " << TrashBins(N, trash_map)<< endl;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests;
	cin >> tests;

	for (int i = 1; i <= tests; i++) run_case(i);
	return 0;
}