#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<int> cards (1e4 + 1 ,0);

void MakeCards(){
    cards[0] = 0;
    for(int i = 1; i <= 1e4; i++){
        if(i % 2 == 0){
            cards[i] = 2 * cards[i/2];
        }else{
            cards[i] = 1;
        }
    }
}

string CardsForFriends(int w, int h, int n){
    if(cards[w] * cards[h] >= n){
        return "YES";
    }
    else{
        return "NO";
    }
}

string CardsForFriends2(int w, int h, int n){
    int sheets = 1;

    while( w % 2 == 0){
        w /= 2; 
        sheets *= 2;
    }

    while( h % 2 == 0){
        h /= 2; 
        sheets *= 2;
    }

    if(sheets >= n){
        return "YES";
    }
    else{
        return "NO";
    }
}

void run_case(){
    int n;
    int w, h;
    cin >> w >> h >> n;
    MakeCards();
    string respuesta = CardsForFriends(w,h,n);
    cout << respuesta << endl;
}

int main(int argc, char const *argv[])
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests;
	cin >> tests;

	while (tests-- > 0) run_case();

	return 0;
}

