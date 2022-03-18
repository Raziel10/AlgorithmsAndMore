#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int Reverse(vector<int> &in, int i , int j ){
    int cost = (j - i) + 1;
    while(i < j){
        swap(in[i], in[j]);
        i++;
        j--;
    }
    return cost;
}

int Reversesort(vector<int> &in){
    int min = INT_MAX;
    int minIndx = 0;
    int cost = 0;
    for(int i = 0 ; i < in.size() - 1; i ++){
        min = in[i];
        minIndx = i;
        for(int j = i ; j < in.size(); j++){
            if(in[j] < min){
                min = in[j];
                minIndx = j;
            }
        }
        cost += Reverse(in,i,minIndx);
    }
    /*for(int i = 0; i < in.size(); i++){
        cout << in[i] << ", " ;
    }*/
    return cost;
}

void run_case(int caseNum){
	//cout << "test case!" << endl;
    int N;
    vector<int> input; 
    cin>> N;
    for(int j = 0; j < N; j++){
        int v; 
        cin >> v; 
        input.push_back(v);
    }
    cout << "Case #"  << caseNum << ": " << Reversesort(input)<< endl;
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