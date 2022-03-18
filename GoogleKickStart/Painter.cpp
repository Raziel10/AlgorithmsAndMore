
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int Painter(int N, string P){
    int count = 0;
    bool oldTraces[3] = {};
    bool Traces[3] = {};
    
    for(int i = 0; i < 3; i++){
        oldTraces[i] = false;
        Traces[i] = false;
    }
    
    unordered_map<char,int> Colors;
    Colors['U'] = 0;
    Colors['R'] = 1;
    Colors['Y'] = 2;
    Colors['B'] = 4;
    Colors['O'] = 3;
    Colors['P'] = 5;
    Colors['G'] = 6;
    Colors['A'] = 7;

    for(int j = 0; j < N; j++){
        int color = Colors[P[j]];
        int component = 1;
        for(int i = 0; i < 3; i++){
            Traces[i] = color & (component);
            component = component << 1;
        }
        for(int i = 0; i < 3; i++){
            if((Traces[i] == false) && (oldTraces[i] == true)){
                count++;
            }
            oldTraces[i] = Traces[i];
        }
        
    }
    for(int i = 0; i < 3; i++){
        if(Traces[i] == true){
            count++;
        }
    }
    return count;
}

void run_case(int caseNum){
	//cout << "test case!" << endl;
    string P;
    int N;

    cin >> N;
    cin >> P;
    cout << "Case #"  << caseNum << ": " << Painter(N, P) << endl;
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