
#include <bits/stdc++.h>
#define endl "\n"
#define lli long long int
using namespace std;


int CuttingIntervals(int N, int C){
    int sieve[10e13 + 100] = {0};
    
    pair<int,int> inter;
    vector< pair<int,int> > intervals;
    int L, R;

    while(N){
        cin >> L >> R;
        cout << "L:" <<L<< ",R:" << R << endl; 
        intervals.push_back(make_pair(L,R));
        N--;
    }
    
    sort(intervals.begin(), intervals.end());

    
    //iterate over all the intervals 
    for( auto i : intervals){
        cout << i.first << "," << i.second << endl;
        for(int a = i.first +1; a < i.second -1 ; a++){
            sieve[a]++;
        }
    }

    // sort by freq
    multimap <lli,lli> mmap;
    for(int  j= 0; j < 10e13 + 100; j++){
        mmap[sieve[j]] = j;
    }
    
    //take greatest value from mmap
    multimap <lli,lli>::reverse_iterator rit;
    for(rit = mmap.rbegin() ; rit != mmap.rend(); rit++){
        
    }
    
    

    return 0;
}

void run_case(int caseNum){
	int N, C;
    cin >> N >> C;
    cout << "Case #"  << caseNum << ": " << CuttingIntervals(N,C)<< endl;
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