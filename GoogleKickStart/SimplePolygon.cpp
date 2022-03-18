
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string SimplePolygon(int N, int A, vector<pair<int,int>>* coord){
    bool isPossible = false;
    int b, B;
    coord = new vector<pair<int,int>>();
    switch(N){
        case 3:
            isPossible = true;
            coord->push_back({0,0});
            coord->push_back({1,0});
            coord->push_back({1,A});
            break; 
        case 4:
            if(A > 1){
                isPossible = true;
                b = B = A / 2;
                B += (A % 2);  
                coord->push_back({0,0});
                coord->push_back({1,0});
                coord->push_back({1,B});
                coord->push_back({0,b});
            }
            break;
        case 5:
            if(A > 3){
                isPossible = true;
                b = B = (A - 2) /2;
                B += ((A - 2) % 2);  
                coord->push_back({0,0});
                coord->push_back({0,1});
                coord->push_back({1,1 + b});
                coord->push_back({1,1});
                coord->push_back({1 + B,1});
            }
            break;
    }

    return isPossible? "POSSIBLE": "IMPOSSIBLE";
}


void run_case(int caseNum){
	//cout << "test case!" << endl;
    int N, A;
    string cad;
    vector<pair<int,int>>* coords;
    cin>> N >> A;
    cout << "Case #"  << caseNum << ": " << SimplePolygon(N,A, coords)<< endl;
    for(auto coord : (*coords)){
        cout << coord.first  << " " << coord.second<< endl;
    }
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