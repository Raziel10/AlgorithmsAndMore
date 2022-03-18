
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string DogsAndCats(int N, int D,int C, int M, string cad){
    long long int TotalCatFood = C;
    int Dogs = 0;
    string res = "NO";

    for (const char& animal : cad){
        if( animal == 'D'){
            Dogs++;
        }
    }


    for (const char& animal : cad){
        if(Dogs){
            if( animal == 'C'){
            //check cats food 
                if(TotalCatFood == 0){
                    return "NO"; 
                }
                TotalCatFood--;
            }
            else{
                // check dog food
                if(D == 0){
                    return "NO"; 
                }
                D--;
                Dogs--;
                // increase Cats food M portions
                TotalCatFood+=M;
                
            }
        }
        else{
            break;
        }
    }
    return "YES";
}

void run_case(int caseNum){
	//cout << "test case!" << endl;
    int N, D, C, M;
    string cad;

    cin>> N >> D >> C >> M;
    cin>> cad;
    cout << "Case #"  << caseNum << ": " << DogsAndCats(N,D,C,M,cad)<< endl;
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