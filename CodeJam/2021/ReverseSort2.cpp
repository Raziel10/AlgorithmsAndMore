#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int Cost(pair<bool,bool>& LC, char c, int X, int Y ){
    int cost1 = 0;
    int cost2 = 0;
    int minCost = 0;

    if(LC.first){
        if(c == 'C'){
            cost1 = 0;
        }
        if(c == 'J'){   
            cost1 = X;
        }
    }
    if(LC.second){
         if(c == 'C'){
            cost2 = Y;
        }
        if(c == 'J'){   
            cost2 = 0;
        } 
    }

    if(LC.first && LC.second){
        minCost = min(cost1,cost2);
    }
    else if(LC.first){
        minCost = cost1;
    }
    else if(LC.second){
        minCost = cost2;
    }

    return minCost;
}

int MoonsAndUmbrellas(int X, int Y, string s){
    pair<bool,bool> LastCharacter = {false, false};
    int minCost = 0;
    int cost1, cost2;

    for(int i = 0; i < s.length(); i++){
        if( s[i] == '?' ){
            cost1 = Cost(LastCharacter, 'C', X, Y);
            cost2 = Cost(LastCharacter, 'J', X, Y);
            if(cost1 == cost2){
                LastCharacter.first = true;
                LastCharacter.second = true;
                minCost += cost1;
            }
            else if(cost1 < cost2){
                LastCharacter.first = true;
                LastCharacter.second = false;
                minCost += cost1;
            }
            else{
                LastCharacter.first = false;
                LastCharacter.second = true;
                minCost +=cost2;
            }
        }
        else{
            minCost += Cost(LastCharacter, s[i], X, Y);
            if( s[i] == 'C'){
               LastCharacter.first = true; 
               LastCharacter.second = false; 
            }
            else if( s[i] == 'J'){
               LastCharacter.first = false;
               LastCharacter.second = true; 
            }
        }
    }
    return minCost;
}

void run_case(int caseNum){
	//cout << "test case!" << endl;
    int X,Y;
    string input;
    cin >> X >> Y >> input;
    
    int ans = MoonsAndUmbrellas(X,Y,input);
    //cout << input << endl;
    cout << "Case #"  << caseNum << ": " << ans<< endl;
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