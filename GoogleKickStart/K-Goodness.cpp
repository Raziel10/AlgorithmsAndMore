
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int K_Goodness_String(int K, string cad){
    int count = 0;
    int cadSize = cad.length();
    for(int i = 0 ; i < cadSize/2 ; i ++){
        if( cad[i] != cad[cadSize - i - 1]){
            count++;
        }
    }
    return abs(K - count);
}

void run_case(int caseNum){
	//cout << "test case!" << endl;
    int N, K;
    string cad;

    cin>> N >> K;
    cin>> cad;
    cout << "Case #"  << caseNum << ": " << K_Goodness_String(K, cad)<< endl;
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