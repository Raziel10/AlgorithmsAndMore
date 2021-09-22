
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


long long int Festival(int D, int N, int K, vector<vector<int>>& attractions){
    long long int ans = 0;
    
    vector<pair<int, int>> start_value;
    vector<pair<int, int>> end_value;
    
    //fill vectors
    for(const auto element : attractions){
        start_value.push_back({element[1], element[0]});
        end_value.push_back({element[2], element[0]});
    }
    
    // sort by start date
    sort(start_value.begin(), start_value.end());
    
    // sort by end date
    sort(end_value.begin(), end_value.end());
    
    int processed_task_start = 0;
    int processed_task_end = 0;
    long long int sum = 0;
    list<long long int> happiness_list;
    list<long long int>::reverse_iterator it;
    // go through each day.
    for(int day = 1 ; day <= D; day++){
        while((processed_task_start < start_value.size()) && (start_value[processed_task_start].first == day)){
            happiness_list.push_back(start_value[processed_task_start].second);
            processed_task_start++;
        }
        happiness_list.sort();
        it = happiness_list.rbegin(); 
        sum = 0;
        for(int i = 0; (it != happiness_list.rend()) && (i < K) ; i++){
            sum += *it;
            it++;
        }
        ans = max(ans,sum);

        while((processed_task_end < end_value.size()) && (end_value[processed_task_end].first == day)){
            happiness_list.remove(end_value[processed_task_end].second);
            processed_task_end++;
        }
        
    }

    return ans;
}

void run_case(int caseNum){
	int D, N, K;
    
    int hi, si, ei;
    cin >> D >> N >> K;

    vector<vector<int>> attractions;
    for( int i = 0; i < N; i++){
        cin >> hi >> si >> ei;
        attractions.push_back({hi, si, ei});
    }

    cout << "Case #"  << caseNum << ": " << Festival(D,N,K,attractions)<< endl;
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