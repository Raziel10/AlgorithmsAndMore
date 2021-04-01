
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef struct Node{
    int R;
    int L;
    int U;
    int D;
}Node_t;


int solution(vector<vector<int>>& A, int R, int C)
{

    vector<vector<Node_t>> Inter (R, vector<Node_t>(C) );

    //recorrido Left 2 Right
    int Continous = 0;
    for(int i = 0; i < R; i++){
        Continous = 0;
        for(int j = 0; j < C; j++){
            if( A[i][j] != 0){
                Continous++;
                Inter[i][j].L = Continous;
            }
            else{
                Continous = 0;
            }
        }
    }
    //recorrido Right 2 Left
    
    for(int i = 0; i < R; i++){
        Continous = 0;
        for(int j = C - 1; j >= 0; j--){
            if( A[i][j] != 0){
                Continous++;
                Inter[i][j].R = Continous;
            }
            else{
                Continous = 0;
            }
        }
    }
    //recorrido Up 2 Down
    for(int j = 0; j < C; j++){
        Continous = 0;
        for(int i = 0; i < R; i++){
            if( A[i][j] != 0){
                Continous++;
                Inter[i][j].U = Continous;
            }
            else{
                Continous = 0;
            }
        }
    }
    //recorrido Down 2 Up
    
    for(int j = 0; j < C; j++){
        Continous = 0;
        for(int i = R - 1; i >= 0; i--){
            if( A[i][j] != 0){
                Continous++;
                Inter[i][j].D = Continous;
            }
            else{
                Continous = 0;
            }
        }
    }

    //recorrido 
    int Total = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if( A[i][j] != 0){
                Node_t* N = &(Inter[i][j]);
                //cout << "i: "<< i<<" j: " << j << endl;
                //cout << "Up: "<<N->U <<" ,Left: "<< N->L <<" ,Down: " << N->D <<" ,Right: " << N->R << endl;
                int MaxL = max(N->U, N->R);
                int MinL = min(N->U, N->R);
                //cout << "Max: "<< MaxL<<" Min: " << MinL << endl;
                if(MaxL >= 4){
                    if( MaxL == MinL )
                        Total +=  2 * (MaxL / 2 - 1);
                    else if( MaxL / 2 <= MinL )
                        Total += MaxL / 2 - 1;
                }
                //cout << "Total: " << Total << endl; 
                MaxL = max(N->U, N->L);
                MinL = min(N->U, N->L);
                //cout << "Max: "<< MaxL<<" Min: " << MinL << endl;
                if(MaxL >= 4){
                    if( MaxL == MinL )
                        Total +=  2 * (MaxL / 2 - 1);
                    else if( MaxL / 2 <= MinL )
                        Total += MaxL / 2 - 1;
                }
                //cout << "Total: " << Total << endl;  
                MaxL = max(N->D, N->L);
                MinL = min(N->D, N->L);
                //cout << "Max: "<< MaxL<<" Min: " << MinL << endl;
                if(MaxL >= 4){
                    if( MaxL == MinL )
                        Total +=  2 * (MaxL / 2 - 1);
                    else if( MaxL / 2 <= MinL )
                        Total += MaxL / 2 - 1;
                }
                //cout << "Total: " << Total << endl; 
                MaxL = max(N->D, N->R);
                MinL = min(N->D, N->R);
                //cout << "Max: "<< MaxL<<" Min: " << MinL << endl;
                if(MaxL >= 4){
                    if( MaxL == MinL )
                        Total +=  2 * (MaxL / 2 - 1);
                    else if( MaxL / 2 <= MinL )
                        Total += MaxL / 2 - 1;
                }
                //cout << "Total: " << Total << endl; 
            }
        }
    }
    return Total;
}

void run_case(int id){
    int R, C;
    cin >> R >> C;
    vector< vector<int> > input (R, vector<int>(C,0) );
    for ( int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> input[i][j];

    int ans = solution(input,R,C);
    printf("Case #%d: %d\n", id, ans);
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